# CCSS - Cross Container Signal Exchange

#### To start the Client and the Server
- Go to the Src directory
- Type the command ```docker-compose up --build```
- Or another command ```docker-compose up --force-recreate```


#### Other Useful Docker Commands:
- ```cd Src``` - this is the directory from which all commands must be called.
- ```docker-compose up --build``` - Update and start all containers.
- ```docker ps -a``` - List all the containers.
- ```docker rm -v -f $(docker ps -qa)``` - Clean out all containers on my development machine
- ```docker rm 42928f35f2f1 eecbbec31cb4``` - Remove these two containers.
- ```docker images -a``` - List all images
- ```docker rmi ccss-client ccss-server``` - Remove these two images.
- ```docker image prune -a --force --filter "until=24h"``` - Remove all old images.
- 
- ```docker exec -it [container-id] bash``` - Enter to the Docker Container session with command line


#### Further reads:
- [Develop on a remote Docker host](https://code.visualstudio.com/remote/advancedcontainers/develop-remote-host)
- []()
- [Deploying Docker Containers over SSH](https://brunoscheufler.com/blog/2022-06-05-deploying-docker-containers-over-ssh)
- [Running SSH Server in a Docker container](https://satvikakolisetty.medium.com/running-ssh-server-in-a-docker-container-55eb2a3add35)
- [Setting Up a Local Docker Registry](https://www.allisonthackston.com/articles/local-docker-registry.html)
- [Creating a local Docker registry](https://kubeops.net/blog/creating-a-local-docker-registry)
- [How to Use Your Own Registry](https://www.docker.com/blog/how-to-use-your-own-registry-2/)
- []()
- [C++ Development Tutorial 4: Static and Dynamic Libraries](https://domiyanyue.medium.com/c-development-tutorial-4-static-and-dynamic-libraries-7b537656163e)
- []()
