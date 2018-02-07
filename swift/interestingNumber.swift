//
//  main.swift
//  interestingNumber
//
//  Created by Sebastian Ferro on 2017/02/08.
//  Copyright © 2017 Sebastian Ferro. All rights reserved.
//

import Foundation

let interestingNumber = [
    "Prime": [2, 3, 5, 7, 11, 13],
    "Fibonacci": [1, 1, 2, 3, 5, 8, 13, 21],
    "Squar": [1, 4, 9, 16],
]

var largest = 0

for (kind, numbers) in interestingNumber {
    for number in numbers {
        if number > largest {
            largest = number
        }
    }
}

print(largest)
