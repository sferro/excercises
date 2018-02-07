#!/usr/bin/env python


def ventadequeso(tipo, *argumentos, **palabrasclaves):
    print "-- ¿Tiene", tipo, "?"
    print "-- Lo siento, nos quedamos sin", tipo
    for arg in argumentos:
        print arg
    print "-"*40
    claves = palabrasclaves.keys()
    claves.sort()
    for c in claves:
        print c, ":", palabrasclaves[c]
 