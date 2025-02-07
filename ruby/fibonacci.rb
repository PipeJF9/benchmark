def fibonacci(n, memo = {})
    return memo[n] if memo.key?(n)
    return n if n <= 1
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo)
    memo[n]
end

fib_numbers = (0...500).map { |i| fibonacci(i) }

puts fib_numbers.join("\n")
File.write("salida_ruby.txt", fib_numbers.join("\n"))