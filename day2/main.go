package main

import (
	"bufio"
	"log"
	"os"
	"strconv"
	"strings"
)

func main() {

	file, err := os.Open("input.txt")

	depth := 0
	horizontal := 0

	aim := 0

	if err != nil {
		log.Fatal(err)
	}

	defer file.Close()

	scanner := bufio.NewScanner(file)

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	for scanner.Scan() {

		if strings.HasPrefix(scanner.Text(), "forward") {
			result := strings.Split(scanner.Text(), " ")
			value, err := strconv.Atoi(result[1])

			if err != nil {
				log.Fatal(err)
			}

			horizontal += value
			depth += aim * value
		}
		if strings.HasPrefix(scanner.Text(), "up") {
			result := strings.Split(scanner.Text(), " ")
			value, err := strconv.Atoi(result[1])

			if err != nil {
				log.Fatal(err)
			}

			aim -= value

		}
		if strings.HasPrefix(scanner.Text(), "down") {
			result := strings.Split(scanner.Text(), " ")
			value, err := strconv.Atoi(result[1])

			if err != nil {
				log.Fatal(err)
			}

			aim += value

		}
	}

	ans := depth * horizontal

	println(ans)

}
