#!/usr/bin/python
# -*- coding: utf-8 -*-

def imprimir_holamundo(texto, veces = 1):
    print veces * texto

def funcion_parametros_variables(param1, param2, *otros):
    for val in otros:
        print val
    print otros

def func_varios(param1, param2, **otros):
    for i in otros.items():
        print i

def f(x, y):
    x = x + 3
    y.append(23)
    print x, y

def suma(a, b):
    c = a + b
    return c

def otra_func(p1, p2):
    return p1 * 2, p2 * 2




imprimir_holamundo("Hola Mundo", 3)

print "funcion_parametros_variables"
print "param 1 y 2"
funcion_parametros_variables(1,2)
print "param 1, 2 y 3"
funcion_parametros_variables(1,2,3)
print "param 1, 2, 3 y 4"
funcion_parametros_variables(1,2,3,4)
print "param 1, 2, 3, 4 y 5"
funcion_parametros_variables(1,2,3,4,5)

print "func_varios"
func_varios(1, 2, tercero = 3, cuarto = 4)

print "funcion f"
x = 22
y = [22]
f(x, y)
print x, y

print "funcion suma"
c = 0
a = suma(4, 5)

print a, c

print "funcion otra func"
p1 = 1
p2 = 3
p1, p2 = otra_func(1, 2)
print p1
print p2
print otra_func(3,4)