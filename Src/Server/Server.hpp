class Server
{
private:
    int Port;
    struct sockaddr_in address;
    int server_fd;

public:
    Server(int port);
    ~Server();

    bool Start(void);
    int AcceptIncomingConnection();
};
