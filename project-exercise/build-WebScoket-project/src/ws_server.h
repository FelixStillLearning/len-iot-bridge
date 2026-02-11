#pragma once 
#include <string>

void start_ws_server(int port);

void broadcast_ws_message(const std::string & message);
