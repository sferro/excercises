#!/usr/bin/python
# -*- coding: utf-8 -*-

birthdays = {'Alice': 'Apr 1', 'Bob': 'Dec 12', 'Carol': 'Mar 4'}

while True:
    print('Enter a name: (blank to quit)')
    name = input()

    if name == '':
        break

    if name in birthdays:
        print(birthdays[name] + ' is the birthday of ' + name)
    else:
        print('I don`t have birthday information for ' + name)
        print('What is threir birthday?')
        bday = input()
        birthdays[name] = bday
        print('birthday database updated.')

