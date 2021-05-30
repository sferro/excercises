#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

def isPhoneNumber(text):
    if len(text) != 12:
        return False

    if not text[0:3].isdecimal():
        return False

    if text[3] != '-':
        return False

    if not text[4:7].isdecimal():
        return False

    if text[7] != '-':
        return False

    if not text[8:12].isdecimal():
        return False

    return True


if len(sys.argv) < 2:
    print('Usage: python isPhoneNumber.py [number]')
    sys.exit()

number = sys.argv[1]      # first command line arg is the number

print(number + ' is a phone number:')
print(isPhoneNumber(number))

message = 'Call me at 415-555-1011 tomorrow. 415-555-9999 is my office.'
for i in range(len(message)):
    chunk = message[i:i+12]
    if isPhoneNumber(chunk):
        print('Phone number found: ' + chunk)

print('Done')
