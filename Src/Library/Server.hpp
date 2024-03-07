class Server
{
private:
    struct sockaddr_in address;

public:
    int Port;
    int SocketId;
    int BuffSize;

    Server(int port, int buffSize = 2048);
    ~Server();

    bool Start(void);
    bool Stop();
    bool CloseSocket(int socketId);
    int AcceptIncomingConnection();
};
