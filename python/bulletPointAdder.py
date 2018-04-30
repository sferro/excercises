#!/usr/bin/python
# -*- coding: utf-8 -*-
# bulletPointAdder.py - Adds Wikipedia bullet points to the start
# of each line of text on the clipboard.

import sys
import pyperclip
text = pyperclip.paste()

# Separate lines and add stars.
lines = text.split('\n')
print(lines)
for i in range(len(lines)):    # loop through all indexes in the "lines" list
    lines[i] = '* ' + lines[i] # add star to each string in "lines" list

text = '\n'.join(lines)
pyperclip.copy(text)