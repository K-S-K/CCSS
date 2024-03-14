# CCSS - Cross Container Signal Exchange

This project's purpose is to adjust the approach of creating several projects in **different docker containers** and letting them **communicate with each other** via sockets sensing strings. It can be used as a template for creating more complex projects.

#### The concepts implemented in the job are:
- There are two separate processes: the Emitter and the Collector.
- The Collector listens to the input from the Emitter and answers in the same socket.
- The applications are the simplest programs in C / C++.
- The build process is performed in the Docker containers.
- The executables are copied to the new clean containers after the build, so the source code doesn't go to production.
- The Docker-compose script creates the dockers.
- The executables are stored in the /app directory of each container.


#### To start the Emitter and the Collector
- Go to the Src directory
- Type the command:
```
docker-compose up --build
```
- Or this command:
```
docker-compose up --force-recreate
```


#### Other notes
- Developed with Visual Studio Code under Ubuntu.
