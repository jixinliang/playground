package main

import (
	"fmt"
	"runtime"
)

func main() {
	fmt.Println("Hi There")
	fmt.Printf("NumCPU: %d\n", runtime.NumCPU())
}
