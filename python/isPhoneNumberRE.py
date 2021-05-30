#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import re

def isPhoneNumber(text):
#    phoneNumRegex = re.compile(r'((\()?(0)?(2|3)(\d){2}(\))?(\s|-|\.)?(15)?([1-9]){3}(\s|-|\.)?(\d){4})|((\()?(0)?11(\))?(\s|-|\.)?(15)?(\d){4}(\s|-|\.)?(\d){4})')

    phoneNumRegex = re.compile(r'''(
    (\()?(0)?(2|3)(\d){2}(\))?                  # Prefix (opcion para No Amba: 351 532 7322)
    (\s|-|\.)?                                  # Separator        
    (15)?([1-9]){3}                             # Area Code
    (\s|-|\.)?                                  # Separator
    (\d){4})                                    # Last 4 digits
    |                                           # or (opcion para amba: 11 4657 1243)
    ((\()?(0)?11(\))?                           # Prefix
    (\s|-|\.)?                                  # Separator
    (15)?(\d){4}                                # Area Code
    (\s|-|\.)?                                  # Separator
    (\d){4}                                     # Last 4 digits
    )''', re.VERBOSE)

    mo = phoneNumRegex.search(text)
    if mo == None:
        return False

    return True


if len(sys.argv) < 2:
    print('Usage: python isPhoneNumber.py [number]')
    sys.exit()

number = sys.argv[1]      # first command line arg is the number

print(number + ' is a phone number:')
print(isPhoneNumber(number))