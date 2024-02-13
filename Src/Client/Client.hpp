class Client
{
private:
    int Port;

public:
    int Sock;

    Client(int port);
    ~Client();

    bool Start();
    void Send(char *message);
};