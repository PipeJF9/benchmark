FROM golang:1.24rc3-bookworm

WORKDIR /app

RUN mkdir -p /app/salida_go

CMD go build -o fibonacci fibonacci.go && ./fibonacci