FROM openjdk:17-slim

WORKDIR /app

RUN mkdir -p /app/salida_java

COPY Fibonacci.java .

RUN javac Fibonacci.java

CMD ["java", "/app/Fibonacci.java"]
