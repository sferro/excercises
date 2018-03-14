#!/usr/bin/python
# -*- coding: utf-8 -*-

def spam():
    eggs = 'spam local'
    print(eggs)

def bacon():
    eggs = 'bacon local'
    print(eggs)

    spam()
    print(eggs)

eggs = 'global'
bacon()
print(eggs)

