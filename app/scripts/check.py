#!/usr/bin/env python3
# -*- coding:utf-8 -*-
###
# Copyright (c) 2020 NXP
# ******************************************************************************
# File: xloader.py
# Created Date: Tuesday, March 31st 2020, 2:17:50 pm
# Author: Major Lin
# -----
# Last Modified: Wed Apr 01 2020
# Modified By: Major Lin
# -----
# 
# -----
# HISTORY:
# Date      	By           	Comments
# ----------	-------------	----------------------------------------------------------
# ******************************************************************************
###
import serial
ser = serial.Serial("/dev/tty.usbserial-14110", 115200, timeout=5)

def send_cmd(cmdid:int, addr:int, data:bytes=b''):
    #with open("data.bin", "wb") as ser:
    ser.write(b'CMD')
    ser.write(cmdid.to_bytes(1, byteorder='little'))
    ser.write(addr.to_bytes(4, byteorder='little'))
    ser.write(data)
    for i in range(4096 - len(data)):
        ser.write(b'\xff')
    ser.write(b'\0')
    ser.write(b'DMC')
    ser.flush()
    print(ser.read(4))

def update_code():
    with open("chip.bin", "rb") as f:
        data = f.read(4096)
        base = 0x80000
        while(data):
            # erase
            print("Erase: {:0>8X}".format(base))
            send_cmd(4, base, data)
            print(ser.read(1000))
            print("Program: {:0>8X}".format(base))
            send_cmd(5, base, data)
            print(ser.read(1000))
            data = f.read(4096)
            base = base + 4096
    send_cmd(6, 0x80000)
    print(ser.read(1000))
    ser.close()

def update_boot():
    with open("boot.bin", "rb") as f:
        data = f.read(4096)
        base = 0x00000
        while(data):
            # erase
            print("Erase: {:0>8X}".format(base))
            send_cmd(4, base, data)
            print(ser.read(1000))
            print("Program: {:0>8X}".format(base))
            send_cmd(5, base, data)
            print(ser.read(1000))
            data = f.read(4096)
            base = base + 4096
    send_cmd(6, 0x00000)
    print(ser.read(1000))
    ser.close()

# update_code()
for i in range(100):
    send_cmd(1, 0)
