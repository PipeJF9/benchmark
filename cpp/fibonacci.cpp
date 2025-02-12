#include <iostream>
#include <unordered_map>
#include <chrono>
#include <fstream>
#include <filesystem>  // Para manejar directorios correctamente

// Memoización con unordered_map para mejorar rendimiento
std::unordered_map<int, uint64_t> memo;

uint64_t fibonacci(int n) {
    if (n <= 1) return n;
    if (memo.find(n) != memo.end()) return memo[n];

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    // Medir tiempo de ejecución
    auto start_time = std::chrono::high_resolution_clock::now();

    // Calcular Fibonacci hasta 10,000
    for (int i = 0; i < 10000; i++) {
        fibonacci(i);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    double execution_time_ms = std::chrono::duration<double, std::milli>(end_time - start_time).count();

    std::cout << execution_time_ms << " ms" << std::endl;

    // Crear directorio de salida usando filesystem (C++17+)
    std::string output_dir = "/app/salida_cpp";
    if (!std::filesystem::exists(output_dir)) {
        if (!std::filesystem::create_directories(output_dir)) {
            std::cerr << "Error: No se pudo crear el directorio de salida." << std::endl;
            return 1;
        }
    }

    // Guardar el tiempo en un archivo
    std::ofstream outfile(output_dir + "/salida_cpp.txt");
    if (outfile.is_open()) {
        outfile << execution_time_ms << " ms"  << std::endl;
        outfile.close();
    } else {
        std::cerr << "Error: No se pudo crear el archivo de salida." << std::endl;
        return 1;
    }

    return 0;
}
