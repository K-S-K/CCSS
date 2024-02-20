FROM ubuntu:latest AS build

RUN apt-get update && apt-get install -y \
    g++ make \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . /app

RUN make

FROM ubuntu:latest
COPY --from=build /app/Bin/server /app/server

EXPOSE 8080

CMD ["/app/server"]

