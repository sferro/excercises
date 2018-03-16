#!/usr/bin/python
# -*- coding: utf-8 -*-

import random

messages = ['Tenes que estudiar mas', 
    'Trabaja Duro', 
    'Vas a recibir un aumento',
    'Tu equipo favorito va a perder',
    'Tu equipo favorito va a ganar',
    'Este finde va a llover',
    'No salgas este fin de semana',
    'No juegues a la loteria, vas a perder',
    'La suerte no esta de tu lado este mes']

print(messages[random.randint(0, len(messages) - 1)])
