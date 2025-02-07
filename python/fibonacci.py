import time

def fibonacci(n, memo={}):
    if n in memo:
        return memo[n]
    if n <= 1:
        return n
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo)
    return memo[n]

fib_numbers = [str(fibonacci(i)) for i in range(500)]

print("\n".join(fib_numbers))

with open("salida_python.txt", "w") as f:
    f.write("\n".join(fib_numbers))