import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Fibonacci {
    public static long fibonacci(int n, long[] memo) {
        if (n <= 1) return n;
        if (memo[n] != 0) return memo[n];
        memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
        return memo[n];
    }

    public static void main(String[] args) {
        long startTime = System.nanoTime();

        int limit = 10000;
        long[] memo = new long[limit];
        for (int i = 0; i < limit; i++) {
            fibonacci(i, memo);
        }

        long endTime = System.nanoTime() - startTime;
        double executionTimeMs = endTime / 1_000_000.0;

        System.out.println("Java execution time in ms:" + executionTimeMs);

        // Crear directorio si no existe
        File dir = new File("/app/salida_java");
        if (!dir.exists()) {
            dir.mkdirs();
        }

        // Guardar el tiempo en un archivo
        File outputFile = new File(dir, "salida_java.txt");
        try (FileWriter writer = new FileWriter(outputFile)) {
            writer.write("Java execution time in ms:" + executionTimeMs);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
