#include "ws_server.h"
#include <App.h>
#include <iostream>
#include <unordered_set>
#include <mutex>

struct PerSocketData {};


using WebSocketClient = uWS::WebSocket<false, true, PerSocketData>;

uWS::Loop* global_ws_loop = nullptr;
std::unordered_set<WebSocketClient*> connected_clients;
std::mutex clients_mutex;

void start_ws_server(int port) {
    uWS::App().ws<PerSocketData>("/*", {
        .open = [](auto *ws) {
            std::lock_guard<std::mutex> lock(clients_mutex);
            connected_clients.insert(ws);
            std::cout << "[WebSocket] Client just Connected!" << std::endl;
        },
        .close = [](auto *ws, int /*code*/, std::string_view /*message*/) {
            std::lock_guard<std::mutex> lock(clients_mutex);
            connected_clients.erase(ws);
            std::cout << "[WebSocket] Client Disconnected." << std::endl;
        }
    }).listen(port, [port](auto *listen_socket) {
        if (listen_socket) {
            std::cout << "Websockect server run in port " << port << std::endl;
            global_ws_loop = uWS::Loop::get(); 
        } else {
            std::cerr << "Webcoket failed to Connect at port" << port << std::endl;
        }
    }).run();
}

void broadcast_ws_message(const std::string& message) {
    if (global_ws_loop) {
        global_ws_loop->defer([message]() {
            std::lock_guard<std::mutex> lock(clients_mutex);
            for (auto *ws : connected_clients) {
                ws->send(message, uWS::OpCode::TEXT);
            }
        });
    }
}