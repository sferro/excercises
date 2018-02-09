#!/usr/bin/python
# -*- coding: utf-8 -*-

# Los diccionarios: es clave = valor
# Como clave podemos poner cualquier valor inmutable: numeros, cadenas, tuplas... pero no Listas ni Diccionarios ya que son mutables
# el indice del diccionario es la clave

d = {"Nombre" : "Sebastian Ferro", 
	"edad": 38,
	"sueldo": 16500.38,
	"hijos":("Francisco","Santiago")}

print d
print d["Nombre"]
print d["hijos"]
print d["sueldo"]
