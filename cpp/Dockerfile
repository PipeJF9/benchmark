FROM gcc:latest

WORKDIR /app

RUN mkdir -p /app/salida_cpp

CMD g++ -o fibonacci -std=c++17 fibonacci.cpp && ./fibonacci