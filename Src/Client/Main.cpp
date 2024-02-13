#include <iostream>
#include <unistd.h>

#include "Client.hpp"

int main()
{
    Client client = *(new Client(8080));

    int valread;
    char buffer[1024] = {0};
    char message[] = "Hello from client";

    client.Start();

    // Send message to server
    client.Send(message);
    std::cout << "Message sent to server." << std::endl;

    // Read response from server
    valread = read(client.Sock, buffer, 1024);
    std::cout << "Server: " << buffer << std::endl;

    return 0;
}
