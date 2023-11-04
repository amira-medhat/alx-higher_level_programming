#!/usr/bin/python3
def islower(c):
    if ord('a') <= ord(c) <= ord('z'):
        return True
    return False

def uppercase(str):
    for c in (str):
        print("{:c}".format(ord(c) - 32 if islower(c) else ord(c)), end="")
    print("")
