#!/usr/bin/env python3
# -*- coding=utf8 -*-
"""
# Author: Major Lin
# Created Time : 06/11/19 14:31:03
# File Name: bin2hex.py
# Description:
"""

import sys
import struct

with open(sys.argv[1], "rb") as f:
    byte = f.read(4)
    while byte:
        print("{:0>8X}".format(struct.unpack('I', byte)[0]))
        byte = f.read(4)
for _ in range(2000):
    print("{:0>8X}".format(0))