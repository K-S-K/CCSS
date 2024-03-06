#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "Server.hpp"


int main()
{
    const char *stop_word = "stop";
    const char *stop_confirm = "stopped";
    bool stop_signal = false;

    Server server = *(new Server(8080));

    if (server.Start())
    {
        std::cout << "Server is started." << std::endl;
        std::cout << "Listening on port " << server.Port << std::endl;
        std::cout << "Obtained SocketId " << server.SocketId << std::endl;
    }
    else
    {
        return 1;
    }

    // Listen until the stop signal
    while (!stop_signal)
    {
        int socketId = server.AcceptIncomingConnection();

        std::cout << "Accepted incoming connection, socketId " << socketId << std::endl;

        while (!stop_signal)
        {
            char buffer[server.BuffSize + 1];
            memset(buffer, '\0', sizeof(buffer));
            int count = read(socketId, buffer, sizeof(buffer));
            if (count > 0)
            {
                puts(buffer);
                write(socketId, buffer, count); // echo as a confirmation

                if (strcmp(buffer, stop_word) == 0)
                {
                    write(socketId, stop_confirm, sizeof(stop_confirm)); // echo as confirmation
                    puts("set stop flag");
                    stop_signal = true;
                    break;
                }
            }
        }

        std::cout << "Close incoming connection, socketId " << socketId << std::endl;
        server.CloseSocket(socketId); // break connection
    }

    if (server.Stop())
    {
        std::cout << "Server is completed its job." << std::endl;
    }
}
