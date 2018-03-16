#!/usr/bin/python
# -*- coding: utf-8 -*-

def commaCode(lista):
    lenLista = len(lista)
    commaCodeStr = ''
    for i in range(lenLista):
        if i == (lenLista - 2):
            commaCodeStr += lista[i] + ', and '
        elif i == (lenLista - 1):
            commaCodeStr += lista[i]
        else:
            commaCodeStr += lista[i] + ', '

    return commaCodeStr

spam = ['apples', 'bananas', 'tofu', 'cats', 'apples2', 'bananas2', 'tofu2', 'cats2']
print(commaCode(spam))


