FROM gcc:latest

WORKDIR /app

RUN mkdir -p /app/salida_cpp

COPY fibonacci.cpp .

RUN g++ -o fibonacci fibonacci.cpp -O3

CMD ["/app/fibonacci"]
