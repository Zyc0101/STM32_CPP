from machine import Pin        
from machine import UART

uart = UART(1, 9600)                         # init with given baudrate
uart.init(9600, bits=8, parity=None, stop=1) # init with given parameters

while True:
    uart.write('abc')   # write the 3 characters