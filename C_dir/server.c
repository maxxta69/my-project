#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BACKLOG 5
#define BUFFER 1024
#define PORT 6003

int main(void)
{
    int server_socket;
    int client_socket;
    int opt = 1;
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof server_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0)
    {
        perror("Unable to create server socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        perror("Unable to reuse socket");
        close(server_socket);
        return 1;
    }



    if((bind(server_socket, (struct sockaddr *)&server_addr, sizeof server_addr)) < 0)
    {
        perror("Unable to bind server with server_addr");
        close(server_socket);
        return 1;
    }

    if((listen(server_socket, BACKLOG)) < 0)
    {
        perror("Unable to listen on the bound server socket");
        close(server_socket);
        return 1;
    }

    printf("Listening on port %d...\n", PORT);

    if((client_socket = accept(server_socket, NULL, NULL)) < 0)
    {
        perror("Unable to accept connection on the bound server socket");
        close(server_socket);
        return 1;
    }

    printf("Client connected...\n");

    char* greeting = "Server: hello from server!\n";
    send(client_socket, greeting, strlen(greeting), 0);

    char recv_buffer[BUFFER];
    ssize_t received_bytes;

    while((received_bytes = recv(client_socket, recv_buffer, sizeof(recv_buffer) - 1, 0)) > 0)
    {
        recv_buffer[received_bytes] = '\0';

        if((send(client_socket, recv_buffer, received_bytes, 0)) < 0)
        {
            perror("Unable to echo messages.");
            break;
        }
    }
    if(received_bytes < 0)
    {
        perror("Error with received messages");
    }

    close(client_socket);
    close(server_socket);

    return 0;
}