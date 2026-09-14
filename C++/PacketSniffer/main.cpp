#include "sniffer.h"

int main(int argc, char* argv[]){
    std::cout << "[*] Initializing packet sniffer..." << std::endl;

    int socket_fd = open_raw_socket();
    if (socket_fd == -1){
        return 1;
    }
    char buffer[65536];
    std::cout << "[*] Listening for live network packets... Press Ctrl+C to cancel" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    while(true) {
        int packet_size = recv(socket_fd, buffer, sizeof(buffer), 0);

        if(packet_size < 0){
            std::cerr << "[-] Failed to recieve packet data." << std::endl;
            break;
        }

        process_packet(buffer, packet_size);
    }

    close(socket_fd);
    return 0;
}
