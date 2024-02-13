#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#include "Server.hpp"

Server::Server(int port)
{
    Port = port;
}

Server::~Server()
{
}

bool Server::Start(void)
{
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        return false;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(Port);

    // Bind socket to localhost:8080
    if (bind(server_fd, (struct sockaddr *)&(address), sizeof(address)) < 0)
    {
        perror("bind failed");
        return false;
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("listen failed");
        return false;
    }

    return true;
}

int Server::AcceptIncomingConnection()
{
    int socketNumber;
    int addrlen = sizeof(address);

    // Accept incoming connection
    if ((socketNumber = accept(server_fd, (struct sockaddr *)&(address), (socklen_t *)&addrlen)) < 0)
    {
        perror("accept failed");
        return -1;
    }

    return socketNumber;
}
