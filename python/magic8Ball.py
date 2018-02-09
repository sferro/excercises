#!/usr/bin/python
# -*- coding: utf-8 -*-

import random

def getAnswer(answerNumber):
    if answerNumber == 1:
        return 'retorna 1'
    elif answerNumber == 2:
        return 'retorna 2'
    elif answerNumber == 3:
        return 'retorna 3'
    elif answerNumber == 4:
        return 'retorna 4'
    elif answerNumber == 5:
        return 'retorna 5'
    elif answerNumber == 6:
        return 'retorna 6'
    elif answerNumber == 7:
        return 'retorna 7'
    elif answerNumber == 8:
        return 'retorna 8'
    elif answerNumber == 9:
        return 'retorna 9'


#llamada extendida
r = random.randint(1, 9)
fortune = getAnswer(r)
print(fortune)

#en un solo renglon
print(getAnswer(random.randint(1, 9)))