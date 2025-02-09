const fs = require('fs');
const path = require('path');

// Crear el directorio si no existe
const outputDir = "/app/salida_js/";
if (!fs.existsSync(outputDir)) {
    fs.mkdirSync(outputDir, { recursive: true });
}

function fibonacci(n, memo = {}) {
    if (n in memo) return memo[n];
    if (n <= 1) return n;
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

const startTime = performance.now();
for (let i = 0; i < 10000; i++) {
    fibonacci(i);
}
const endTime = performance.now() - startTime;

// Imprimir correctamente la ejecución
console.log(`JavaScript execution time in ms:${endTime}`);

// Guardar en el archivo dentro del contenedor
const outputFile = path.join(outputDir, "salida_js.txt");

fs.writeFileSync(outputFile, `JavaScript execution time in ms:${endTime}`);

