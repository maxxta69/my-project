#include <iostream>
#include "Port_decoder.h"

int main(int argc, char* argv[]){
    char Raw_packet[] = {0x00, 0x50};
    uint16_t port_number = PortDecoder(Raw_packet);
    std::cout << "Port Number: " << port_number << std::endl;

    return 0;
}
