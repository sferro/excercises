//
//  main.swift
//  interestingNumber
//
//  Created by Sebastian Ferro on 2017/02/08.
//  Copyright © 2017 Sebastian Ferro. All rights reserved.
//

import Foundation

func greet(person: String, day: String) -> String {
    return "Hello \(person), today is \(day)."
}

func greet2(_ person: String, on day: String) -> String {
    return "Hello \(person), today is \(day)."
}

var saludo = greet(person: "Sebastian Ferro", day: "Lunes")

print(saludo)

saludo = greet2("Seba", on: "Martes")

print(saludo)

