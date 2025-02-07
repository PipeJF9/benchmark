const fs = require('fs');

function fibonacci(n, memo = {}) {
    if (n in memo) return memo[n];
    if (n <= 1) return n;
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

let fibNumbers = [];
for (let i = 0; i < 500; i++) {
    fibNumbers.push(fibonacci(i));
}

console.log(fibNumbers.join('\n'));
fs.writeFileSync("salida_javascript.txt", fibNumbers.join('\n'));