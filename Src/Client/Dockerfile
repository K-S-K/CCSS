FROM builder-2024-05:ver_1 AS built

FROM ubuntu:latest
COPY --from=built /app/Client/Bin/client /app/client

EXPOSE 8080

CMD ["/app/client"]

