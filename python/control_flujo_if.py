#!/usr/bin/python

print "Escribe 0 para salir"

while True:
    numero = raw_input("> ")
    print "numero ingresado = " + str(numero) 
    if int(numero) < 0:
        print "Numero negativo"
    elif int(numero) > 0:
        print "Numero positivo"
    else:
        print "cero"
    var = "par" if (int(numero) % 2 == 0) else "impar"
    print var
    if int(numero) == 0:
        break
