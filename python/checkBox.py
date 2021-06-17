#!/usr/bin/python
# -*- coding: utf-8 -*-

# This program test pywebio library.

from pywebio.input import *
from pywebio.output import *
from pywebio.session import *

# Checkbox
agree = checkbox("User Term", options=['I agree to terms and conditions'])
put_text('agree = %r' % agree)  

