#!/usr/bin/python3
def islower(c):
    if ord('a') <= ord(c) <= ord('z'):
        return True
    return False

def uppercase(str):
    for c in (str):
        if (islower(c)):
            print(f"{ord(c) - 32:c}",end="")
        else:
            print(f"{ord(c):c}",end="")
    print("")
