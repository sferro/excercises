#!/usr/bin/python
# -*- coding: utf-8 -*-

def collatz(number):
    if (number % 2) == 0:
        return number // 2
    else:
        return 3 * number + 1

print('Input a number')
inputNumber = int(input())
while True:
    if inputNumber == 1:
        break

    inputNumber = collatz(inputNumber)
    print(inputNumber)
