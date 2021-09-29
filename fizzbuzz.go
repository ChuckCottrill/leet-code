

// fizzbuzz
// A program that prints the numbers from 1 to n. But for multiples of three 
// print “Fizz” instead of the number and for the multiples of five print “Buzz”. 
// For numbers which are multiples of both three and five print “FizzBuzz”.

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

/*
 * Complete the 'fizzBuzz' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

func fizzBuzz(n int32) {
    // Write your code here
    fizz := "fizz"
    buzz := "buzz"
    
    if n % 3 == 0 && n % 5 == 0 {
        fmt.Println(fizz+buzz)
    } else if n % 3 == 0 {
        fmt.Println(fizz)
    } else if n % 5 == 0 {
        fmt.Println(buzz)
    } else {
        fmt.Println(n)
    }
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    nTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)
    n := int32(nTemp)

    fizzBuzz(n)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}

