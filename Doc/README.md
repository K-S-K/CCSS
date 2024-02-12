# CCSS - Cross Container Signal Exchange

The purpose of this project is to adjust the approach of creating several projects in different containers and let them communicate with each other via sockets.

The concepts implemented in the job are:
- There are two separate processes: the Client and the Server.
- The server listens to the input from the Client and answers in the same socket.
- The applications are the simplest programs in C / C++.
- The build process is performed in the Docker containers.
- After the build, the executables are copied to the new clean containers so the source code doesn't go to the production.
- The Docker-compose script creates the dockers.
