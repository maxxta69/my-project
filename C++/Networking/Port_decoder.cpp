#include "Port_decoder.h"
#include <arpa/inet.h>
#include <iostream>
#include <cstdint>

uint16_t PortDecoder(const char* Raw_packet){
    const uint16_t *int_pointer = reinterpret_cast<const uint16_t *>(Raw_packet);
    const uint16_t translated_port = ntohs(*int_pointer);
    return translated_port;
}