#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#include "Server.hpp"

int main()
{
    Server server = *(new Server(8080));

    if (server.Start())
    {
        std::cout << "Server is started." << std::endl;
    }
    else
    {
        return 1;
    }

    int socketNumber;
    char buffer[1024] = {0};

    if ((socketNumber = server.AcceptIncomingConnection()) < 0)
    {
        perror("accept failed");
        return 1;
    }

    // Read message from client
    read(socketNumber, buffer, 1024);
    std::cout << "C ---> " << buffer << " ---> S" << std::endl;

    // Echo message back to client
    send(socketNumber, buffer, strlen(buffer), 0);
    std::cout << "C <--- " << buffer << " <--- S" << std::endl;

    std::cout << "Server is comleted." << std::endl;

    return 0;
}
