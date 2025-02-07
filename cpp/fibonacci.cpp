#include <iostream>
#include <fstream>
#include <unordered_map>

std::unordered_map<int, long long> memo;

long long fibonacci(int n) {
    if (memo.count(n)) return memo[n];
    if (n <= 1) return n;
    return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    std::ofstream file("salida_cpp.txt");

    for (int i = 0; i < 500; i++) {
        std::cout << fibonacci(i) << "\n";
        file << fibonacci(i) << "\n";
    }

    file.close();
    return 0;
}