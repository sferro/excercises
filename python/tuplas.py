#!/usr/bin/python
# -*- coding: utf-8 -*-

# Las tuplas son lo mismo que las listas pero sus valores son inmutables, los valores no se pueden modificar
# Son muchas mas ligeras que las listas

t = (22, True, "una cadena", 23.345, [3, "otra lista"])

print t

dato_0 = t[0]
dato_4 = t[4]
dato_41 = t[4][1]

print dato_0
print dato_4
print dato_41


# con valores negativos de subindice accedemos desde el final hacia el principio
print t[-2]

# Tambien podemos indicar un desde hasta en las listas

print t[1:4] # Me imprime desde la posicion 1 a la 4 

# Y si no ponemos el desde y/o hasta me cuenta desde esa posicion o hasta esa posicion
print t[:3]
print t[1:]

print type(t)