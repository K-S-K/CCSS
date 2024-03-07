#include <cstring>
#include <iostream>
#include <unistd.h>

#include "../Library/Client.hpp"

int main()
{
    int message_count = 5;
    const char *stop_word = "stop";

    sleep(1);

    Client client = *(new Client(8080));

    if (client.Start())
    {
        std::cout << "Emitter is started." << std::endl;
    }
    else
    {
        return 1;
    }

    for (int i = 0; i < message_count; i++)
    {
        char strBuf[80];
        memset(strBuf, '\0', sizeof(strBuf));
        sprintf(strBuf, "Ping %d", i);

        client.Send(strBuf);
    }

    client.Send(stop_word);

    if (client.Stop())
    {
        std::cout << "Emitter is completed its job." << std::endl;
    }

    return 0;
}
