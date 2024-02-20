#include <iostream>
#include <unistd.h>

#include "Client.hpp"

int main()
{
    Client client = *(new Client(8080));

    int valread;
    char buffer[1024] = {0};
    char message[] = "Hello";

    if (client.Start())
    {
        std::cout << "Client is started " << "." << std::endl;
    }
    else
    {
        return 1;
    }

    // Send message to server
    client.Send(message);
    std::cout << "C ---> " << message << " ---> S" << std::endl;

    // Read response from server
    valread = read(client.Sock, buffer, 1024);
    std::cout << "C <--- " << buffer << " <--- S" << std::endl;

    std::cout << "Client is comleted." << std::endl;

    return 0;
}
