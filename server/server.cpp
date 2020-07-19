#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include <vector>
#include <thread>
#include "DataFileLogger.h"
#include "communication/endpoint.h"

#define PORT 62555

#define SOCKET_OK 0
#define BIND_ERR 1
#define LISTEN_ERR 2

// Prototypes.
static inline struct sockaddr_in server_setup(int sock_fd, unsigned short port, unsigned short* msg);
void handle_client(const ruslan::communicatable* client);

int main()
{
    int server_fd, error;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "Socket setup failure." << std::endl;
        return 1;
    }

    struct sockaddr_in server_addr = server_setup(server_fd, PORT, (unsigned short*) &error);
    socklen_t len = sizeof(server_addr);

    if (error == BIND_ERR)
    {
        std::cerr << "Binding failure." << std::endl;
        return 1;
    }

    else if (error == LISTEN_ERR)
    {
        std::cerr << "Listening failure." << std::endl;
        return 1;
    }

    std::vector<std::thread> endpoint_handlers;

    while (true)
    {
        int client_fd = accept(server_fd, (struct sockaddr*) &server_addr, &len);

        if (client_fd < 0)
        {
            std::cerr << "Client connection failure.\n\n";
            continue;
        }

        else
            std::cout << "\nClient connected.\n\n";

        endpoint_handlers.push_back(std::thread(handle_client, new ruslan::endpoint(client_fd)));
    }

    return 0;
}

// Setup, bind, and listen.
static inline struct sockaddr_in server_setup(int sock_fd, unsigned short port, unsigned short* msg)
{
    struct sockaddr_in addr = {.sin_family = AF_INET, .sin_port = htons(port)};
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock_fd, (struct sockaddr*) &addr, sizeof(addr)) != 0)
    {
        *msg = BIND_ERR;
        return addr;
    }

    else if (listen(sock_fd, 5) != 0)
    {
        *msg = LISTEN_ERR;
        return addr;
    }

    *msg = SOCKET_OK;
    return addr;
}

// Handles single client.
void handle_client(const ruslan::communicatable* client)
{
    char* buffer = new char[100];
    int read_val = client->readfrom(buffer, 100);

    std::cout << "Reading value: " << read_val << std::endl << "Message: " << buffer << std::endl;
    delete[] buffer;
}
