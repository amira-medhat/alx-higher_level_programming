#!/usr/bin/python3
def islower(c):
    if ord('a') <= ord(c) <= ord('z'):
        return True
    return False

def uppercase(str):
    for c in (str):
        if (islower(c)):
            print("{:c}".format(ord(c) - 32), end="")
        else:
            print("{:c}.format(ord(c))", end="")
    print("")
