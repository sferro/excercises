#!/usr/bin/env python
def fib(n):  # devuelve la serie fibonacci hasta n
    """Devuelve la serie fibonacci hasta n"""
    result = []
    a, b = 0, 1
    while a < n:
        result.append(a)
        a, b = b, a+b
    return result
