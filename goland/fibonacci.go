package main

import (
	"fmt"
	"os"
	"time"
)

// Fibonacci recursivo con memoización
func fibonacci(n int, memo map[int]uint64) uint64 {
	if n <= 1 {
		return uint64(n)
	}
	if val, exists := memo[n]; exists {
		return val
	}
	memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo)
	return memo[n]
}

func main() {
	startTime := time.Now()

	// Crear un mapa para la memoización
	memo := make(map[int]uint64)

	// Calcular Fibonacci hasta 20,000
	for i := 0; i < 10000; i++ {
		fibonacci(i, memo)
	}

	endTime := time.Since(startTime)
	executionTime := float64(endTime.Nanoseconds()) / 1e6 // Convertir a ms con decimales

	fmt.Printf("%.6f ms\n", executionTime)

	// Crear directorio si no existe
	outputDir := "/app/salida_go"
	if err := os.MkdirAll(outputDir, os.ModePerm); err != nil {
		fmt.Println("Error creando directorio:", err)
		return
	}

	// Guardar el tiempo en un archivo
	outputFile := outputDir + "/salida_go.txt"
	file, err := os.Create(outputFile)
	if err != nil {
		fmt.Println("Error creando archivo:", err)
		return
	}
	defer file.Close()
	
	_, err = file.WriteString(fmt.Sprintf("%.6f ms", executionTime))
	if err != nil {
		fmt.Println("Error escribiendo en archivo:", err)
	}
}
