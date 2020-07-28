#!/usr/bin/python3

import sys

def calc():
    divided = ''
    result = 0
    modulo = 0
    if len(sys.argv) != 4:
        return "Error"
    if (sys.argv[2] == '+'):
        return int(sys.argv[1]) + int(sys.argv[3])
    elif (sys.argv[2] == '-'):
        return int(sys.argv[1]) - int(sys.argv[3])
    elif (sys.argv[2] == '*'):
        return int(sys.argv[1]) * int(sys.argv[3])
    elif (sys.argv[2] == '/'):
        result = int(sys.argv[1]) / int(sys.argv[3])
        modulo = int(sys.argv[1]) % int(sys.argv[3])
        divided = str(result) + "(il reste " + str(modulo) + ")"
        return divided
    else:
        return "Error"

if __name__=="__main__":
    print(calc())
