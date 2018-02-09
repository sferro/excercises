#!/usr/bin/python
# -*- coding: utf-8 -*-

print("Escribe 0 para salir")

while True:
    numero = input("> ")
    print("numero ingresado = " + str(numero)) 
    if int(numero) < 0:
        print("Numero negativo")
    elif int(numero) > 0:
        print("Numero positivo")
    else:
        print("cero")
    var = "par" if (int(numero) % 2 == 0) else "impar"
    print(var)
    if int(numero) == 0:
        break

name = ''
while name != 'your name':
    print('Please enter your name.')
    name = input()
print('Thank you')
