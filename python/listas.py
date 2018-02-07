#!/usr/bin/python

# Las listas vendrian a ser arrays
# Pueden contener cualquier tipo de dato: enteros, Booleanos, flotantes, cadenas, otras listas
# El primer elemento de la lista es 0

l = [22, True, "una cadena", 23.345, [3, "otra lista"]]

print l

dato_0 = l[0]
dato_4 = l[4]
dato_41 = l[4][1]

print dato_0
print dato_4
print dato_41

l[2] = "otra cadena"

print l

# con valores negativos de subindice accedemos desde el final hacia el principio
print l[-2]

# Tambien podemos indicar un desde hasta en las listas

print l[1:4] # Me imprime desde la posicion 1 a la 4 

# Y si no ponemos el desde y/o hasta me cuenta desde esa posicion o hasta esa posicion
print l[:3]
print l[1:]

print type(l)