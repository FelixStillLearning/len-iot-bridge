#include <iostream>
#include <thread>
#include <chrono>
#include "grpc_server.h"
#include "ws_server.h"

int main() {
    std::cout << "starting IoT gateway bridge" << std::endl;

    std::thread ws_thread([](){
        start_ws_server(9002);
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    start_grpc_server(50051);

    if(ws_thread.joinable()) {
        ws_thread.join();
    }

    return 0;
} 