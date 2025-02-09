FROM golang:1.24rc3-bookworm

WORKDIR /app

RUN mkdir -p /app/salida_go

COPY fibonacci.go .

RUN go build -o fibonacci fibonacci.go

CMD ["/app/fibonacci"]
