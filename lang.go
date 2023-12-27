package main

import (
	"fmt"
	"os"
	"strconv"
)

func add(x, y float64) float64 {
	return x + y
}

func subtract(x, y float64) float64 {
	return x - y
}

func multiply(x, y float64) float64 {
	return x * y
}

func divide(x, y float64) float64 {
	if y != 0 {
		return x / y
	}
	fmt.Println("Cannot divide by zero.")
	os.Exit(1)
	return 0
}

func main() {
	if len(os.Args) != 4 {
		fmt.Println("Usage: calculator <number> <operator> <number>")
		os.Exit(1)
	}

	num1, err1 := strconv.ParseFloat(os.Args[1], 64)
	operator := os.Args[2]
	num2, err2 := strconv.ParseFloat(os.Args[3], 64)

	if err1 != nil || err2 != nil {
		fmt.Println("Invalid input. Please provide valid numbers.")
		os.Exit(1)
	}

	var result float64

	switch operator {
	case "+":
		result = add(num1, num2)
	case "-":
		result = subtract(num1, num2)
	case "*":
		result = multiply(num1, num2)
	case "/":
		result = divide(num1, num2)
	default:
		fmt.Println("Invalid operator. Use +, -, *, or /.")
		os.Exit(1)
	}

	fmt.Printf("%v %s %v = %v\n", num1, operator, num2, result)
}
