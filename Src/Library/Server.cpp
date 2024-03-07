#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#include "Server.hpp"

Server::Server(int port, int buffSize)
{
    Port = port;
    BuffSize = buffSize;

    memset(&address, 0, sizeof(address));
}

Server::~Server()
{
}

bool Server::Start(void)
{

    // Creating socket file descriptor
    if ((SocketId = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cerr << "Socket creation error" << std::endl;
        return false;
    }

    address.sin_family = AF_INET; // versus AF_LOCAL
    // address.sin_addr.s_addr = INADDR_ANY;
    address.sin_addr.s_addr = htonl(INADDR_ANY); // host-to-network endian
    address.sin_port = htons(Port);              // for listening

    // Bind socket to host:port
    if (bind(SocketId, (struct sockaddr *)&(address), sizeof(address)) < 0)
    {
        perror("bind failed");
        return false;
    }

    // Listen for incoming connections
    if (listen(SocketId, 3) < 0)
    {
        perror("listen failed");
        return false;
    }

    return true;
}

/// @brief Close the connection
bool Server::Stop()
{
    return CloseSocket(SocketId);
}

bool Server::CloseSocket(int socketId)
{
    // https://www.gnu.org/software/libc/manual/html_node/Closing-a-Socket.html

    int result = close(socketId);

    switch (result)
    {
    case 0:
        std::cerr << "socket " << socketId << " was successfully closed" << std::endl;
        return true;
        break;

    case EBADF:
        std::cerr << "socket " << socketId << " is not a valid file descriptor" << std::endl;
        break;

    case ENOTSOCK:
        std::cerr << "socket " << socketId << " is not a socket." << std::endl;
        break;

    case ENOTCONN:
        std::cerr << "socket " << socketId << " is not connected." << std::endl;
        break;

    default:
        std::cerr << "Connection Failed" << std::endl;
        break;
    }

    return false;
}

int Server::AcceptIncomingConnection()
{
    int socketId;
    int addrlen = sizeof(address);

    // Accept incoming connection
    if ((socketId = accept(SocketId, (struct sockaddr *)&(address), (socklen_t *)&addrlen)) < 0)
    {
        perror("accept failed");
        return -1;
    }

    return socketId;
}
