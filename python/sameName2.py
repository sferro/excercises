#!/usr/bin/python
# -*- coding: utf-8 -*-

def spam():
    global eggs
    eggs = 'spam global'
    print(eggs)

def bacon():
    eggs = 'bacon local'
    print(eggs)

    spam()
    print(eggs)

eggs = 'global'
bacon()
print(eggs)

