package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	fileName := os.Args[1]
	wordToCount := os.Args[2]

	file, err := os.Open(fileName)
	if err != nil {
		panic(err)
	}

	defer file.Close()

	scanner := bufio.NewScanner(file)
	count := 0
	for scanner.Scan() {
		count += countOcurrences(scanner.Text(), wordToCount)
	}

	fmt.Printf("Word was found %d time\n", count)

	if err := scanner.Err(); err != nil {
		fmt.Println("error reading the file")
	}
}

func countOcurrences(line, w string) int {
	words := strings.Split(line, " ")
	count := 0
	for _, word := range words {
		if word == w {
			count += 1
		}
	}

	return count
}
