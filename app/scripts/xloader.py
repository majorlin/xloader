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
#with open("data.bin", "wb") as ser
ser = serial.Serial("/dev/tty.usbserial-14310", 115200, timeout=3)

def send_cmd(cmdid:int, addr:int, data:bytes=b'', nocheck:bool=False):
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
    echo = ser.read(4)
    if echo == b'DONE' or nocheck:
        if nocheck:
            print(echo.decode('utf-8'), end='')
        return True
    else:
        print(echo.decode('utf-8'), end='')
        print("CMD failed, retrying....")
        send_cmd(cmdid, addr, data)

def update_code():
    with open("chip.bin", "rb") as f:
        data = f.read(4096)
        base = 0x80000
        while(data):
            # erase
            print("Erase: {:0>8X}".format(base))
            send_cmd(4, base, data)
            # print(ser.read(1000))
            print("Program: {:0>8X}".format(base))
            send_cmd(5, base, data)
            # print(ser.read(1000))
            data = f.read(4096)
            base = base + 4096
    send_cmd(6, 0x80000)
    # print(ser.read(1000))
    ser.close()

def update_boot():
    with open("chip.bin", "rb") as f:
        data = f.read(4096)
        base = 0x00000
        while(data):
            # erase
            print("Erase: {:0>8X}".format(base))
            send_cmd(4, base, data)
            # print(ser.read(1000))
            print("Program: {:0>8X}".format(base))
            send_cmd(5, base, data)
            # print(ser.read(1000))
            data = f.read(4096)
            base = base + 4096
    send_cmd(6, 0x00000)
    # print(ser.read(1000))
    ser.close()

def update_fw():
    with open("./build/firmware.bin", "rb") as f:
        data = f.read(4096)
        base = 0x01000
        while(data):
            print("Program: {:0>8X}".format(base))
            send_cmd(2, base, data)
            data = f.read(4096)
            base = base + 4096
    send_cmd(3, 0x01000, nocheck=True)
    # send_cmd(0, 0x01000)
    print(ser.read(1000).decode('utf-8'))
    ser.write('gpio toggle=1\n'.encode())
    print(ser.read(1000).decode('utf-8'))
    ser.close()

# update_code()
# update_boot()
update_fw()
