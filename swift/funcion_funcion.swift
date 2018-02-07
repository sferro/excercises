//
//  main.swift
//  interestingNumber
//
//  Created by Sebastian Ferro on 2017/02/08.
//  Copyright © 2017 Sebastian Ferro. All rights reserved.
//

import Foundation

func returnFifteen() -> Int {
    var y = 10

    func add() {
        y += 5
    }
    add()

    return y
}

func makeIncrementer() -> ((Int) -> Int) {
    func addOne(number: Int) -> Int {
        return 1 + number
    }
    return addOne
}

func hasAnyMatches(list: [Int], condition: (Int) -> Bool) -> Bool {
    
    for item in list {

        if condition(item) {

            return true
        }

    }

    return false
}

func lessThanTen(number: Int) -> Bool {

    return number < 10
}

var fifTeen = returnFifteen()

print("returnFifteen = \(fifTeen).")

var increment = makeIncrementer()
var numIncrementado = increment(7)
print ("numIncrementado = \(numIncrementado).")

numIncrementado = increment(9)
print ("numIncrementado 2= \(numIncrementado).")

var numbers = [20, 19, 7, 12]

var respuesta = hasAnyMatches(list: numbers, condition: lessThanTen)
print("la respuesta es: \(respuesta).")


