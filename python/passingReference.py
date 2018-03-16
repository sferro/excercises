#!/usr/bin/python
# -*- coding: utf-8 -*-

def eggs(someParameter):
    someParameter.append('Hello')

spam = [1, 2, 3]
eggs(spam)

print(spam)
