#pragma once 

#include <iostream>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
// #include <cerrr>

int open_raw_socket();
void process_packet(char *buffer, int size);
