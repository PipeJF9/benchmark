FROM openjdk:17-slim

WORKDIR /app

RUN mkdir -p /app/salida_java

COPY fibonacci.java .

RUN javac fibonacci.java

CMD ["java", "/app/fibonacci.java"]
