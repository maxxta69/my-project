#include "sniffer.h"

int open_raw_socket(){
    int sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

    if(sock_fd == -1){
        std::cerr << "[-] Error opening raw socket: " << strerror(errno) << std::endl;
        std::cerr << "[!] Did you forget to run with 'sudo'?" << std::endl;
    } else{
        std::cout << "[+] Raw network socket opened successfully! ID: " << sock_fd << std::endl;
    }
    return sock_fd;
}

void process_packet(char* buffer, int size) {
    struct iphdr *ip_header = reinterpret_cast<struct iphdr *>(buffer);

    struct in_addr source_ip, dest_ip;
    source_ip.s_addr = ip_header->saddr;
    dest_ip.s_addr = ip_header->daddr;

    int ip_header_len = ip_header->ihl * 4;

    struct tcphdr *tcp_header = reinterpret_cast<struct tcphdr *>(buffer + ip_header_len);

    uint16_t source_port = ntohs(tcp_header->source);
    uint16_t dest_port = ntohs(tcp_header->dest);

    std::cout << "[PACKET] " << inet_ntoa(source_ip) << ":" << source_port << "--->" << inet_ntoa(dest_ip) << ":" << dest_port << " | size: " << size << " bytes" << std::endl;
}