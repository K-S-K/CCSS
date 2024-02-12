FROM ubuntu:latest AS build

RUN apt-get update && apt-get install -y \
    g++ \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . /app

RUN g++ -o ./client ./Client.cpp

FROM ubuntu:latest
COPY --from=build /app/client /app/client

EXPOSE 8080

CMD ["/app/client"]

