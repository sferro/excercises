//
//  main.swift
//  interestingNumber
//
//  Created by Sebastian Ferro on 2017/02/08.
//  Copyright © 2017 Sebastian Ferro. All rights reserved.
//

import Foundation

func calculateStatistics(scores: [Int]) -> (min: Int, max: Int, sum: Int) {

    var min = scores[0]
    var max = scores[0]
    var sum = 0

    for score in scores {
        if score > max {
            max = score
        } else if score < min {
            min = score

        }
        sum += score 
    }
    return (min, max, sum)
}

func sumOf(numbers: Int...) -> Int {

    var sum = 0

    for number in numbers {
        sum += number
    }
    return sum
}

let statistics = calculateStatistics(scores: [5, 3, 100, 3, 9, 12, 34, 67, 23, 45, 76, 98, 12, 21, 23])

print("Valores .sum, .min, max")
print(statistics.min)
print(statistics.max)
print(statistics.sum)


print("Valores .sum 0, .min 1, max 2")
print(statistics.0)
print(statistics.1)
print(statistics.2)

var suma = sumOf()
print("sumOf sin datos = \(suma).")
suma = sumOf(numbers: 43, 12, 56, 67, 78, 89)
print("sumOf con datos 43, 12, 56, 67, 78 89 = \(suma).")