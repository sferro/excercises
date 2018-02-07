//
//  main.swift
//  interestingNumber
//
//  Created by Sebastian Ferro on 2017/02/08.
//  Copyright © 2017 Sebastian Ferro. All rights reserved.
//

import Foundation

print("while")
var n = 2
while n < 100 {
    n = n * 2
    print(n)
}
print("final")
print(n)

print("repeat")
var m = 2
repeat {
    m = m * 2
    print(m)
} while m < 100

print("final")
print(m)

print("for")
var total = 0
for i in 0..<4 {
    total += i
    print(total)
}

print("final")
print(total)

