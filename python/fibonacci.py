import time
import os

# Crear el directorio si no existe
output_dir = "/app/salida_python/"
os.makedirs(output_dir, exist_ok=True)

def fibonacci(n, memo={}):
    if n in memo:
        return memo[n]
    if n <= 1:
        return n
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo)
    return memo[n]

start_time = time.time()
fib_numbers = [str(fibonacci(i)) for i in range(10000)]
end_time = time.time() - start_time	

# Imprimir correctamente la ejecución
print(f"Python execution time in ms: {end_time * 1000}")

# Guardar en el archivo dentro del contenedor
output_file = os.path.join(output_dir, "salida_python.txt")
with open(output_file, "w") as f:
    f.write(f"Python execution time in ms:{end_time * 1000}")
