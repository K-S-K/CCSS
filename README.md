# CCSS - Cross Container Signal Exchange

The purpose of this project is to adjust the approach of creating several projects in different containers and let them communicate with each other via sockets. The project can be used as a template for creating more complex projects.

The concepts implemented in the job are:
- There are two separate processes: the Client and the Server.
- The server listens to the input from the Client and answers in the same socket.
- The applications are the simplest programs in C / C++.
- The build process is performed in the Docker containers.
- After the build, the executables are copied to the new clean containers so the source code doesn't go to the production.
- The Docker-compose script creates the dockers.
- The executables are stored in the /app directory of each container.


#### To start the Client and the Server
- Go to the Src directory
- Type the command docker-compose up --build
