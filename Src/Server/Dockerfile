FROM builder-2024-05:ver_1 AS built

FROM ubuntu:latest
COPY --from=built /app/Server/Bin/server /app/server

EXPOSE 8080

CMD ["/app/server"]

