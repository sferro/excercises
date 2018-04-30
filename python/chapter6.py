#!/usr/bin/python
# -*- coding: utf-8 -*-

spam = "Hello World! '''''' "
print('String Double Quotes: ', spam)

spam = 'Hello World """"" '
print('String Single Quotes: ', spam)

spam = 'Say hi to Bob\'s mother.\n Bye'
print('Escape Characters: ', spam)

spam = r'That is Carol\'s cat.'
print('Raw Strings: ', spam)

spam = '''Dear Alice,
Eve's cat has been arrested for catnapping, cat burglary, and extortion.
Sincerely,
Bob''')
print('Multiline Strings with Triple Quotes: ', spam)


spam = 'Hello World!'
print('Indexing')
print('spam: ', spam)
print('spam[0]: ', spam[0])
print('spam[4]: ', spam[4])
print('spam[-1]: ', spam[-1])
print('spam[0:5]: ', spam[0:5])
print('spam[:5]: ', spam[:5])
print('spam[6:]: ', spam[6:])


spam = 'Hello World!'
print('spam: ', spam)
print('spam.upper(): ', spam.upper())
print('spam.lower(): ', spam.lower())

print('spam.islower(): ', spam.islower())
print('spam.isupper(): ', spam.isupper())

print('spam.lower().islower(): ', spam.lower().islower())
print('spam.upper().isupper(): ', spam.lower().islower())

spam = ['Hello', 'World']
