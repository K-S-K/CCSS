FROM ubuntu:latest AS build

RUN apt-get update && apt-get install -y \
    g++ \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . /app

RUN g++ -o ./server ./Main.cpp ./Server.cpp

FROM ubuntu:latest
COPY --from=build /app/server /app/server

EXPOSE 8080

CMD ["/app/server"]

