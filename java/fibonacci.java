import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

public class FibonacciJava {
    static HashMap<Integer, Long> memo = new HashMap<>();

    public static long fibonacci(int n) {
        if (memo.containsKey(n)) return memo.get(n);
        if (n <= 1) return n;
        long result = fibonacci(n - 1) + fibonacci(n - 2);
        memo.put(n, result);
        return result;
    }

    public static void main(String[] args) throws IOException {
        StringBuilder output = new StringBuilder();

        for (int i = 0; i < 500; i++) {
            output.append(fibonacci(i)).append("\n");
        }

        System.out.print(output);

        FileWriter writer = new FileWriter("salida_java.txt");
        writer.write(output.toString());
        writer.close();
    }
}