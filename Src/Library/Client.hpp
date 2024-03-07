class Client
{
private:
    int Port;
    int SocketId;
    std::string Host;
    
    int BuffSize;

public:

    Client(int port, std::string host = "127.0.0.1", int buffSize = 2048);
    ~Client();

    bool Start();
    bool Stop();
    bool Send(const char *message, bool echo = true);
};