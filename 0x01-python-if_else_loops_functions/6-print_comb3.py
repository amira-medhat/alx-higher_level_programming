#!/usr/bin/python3
for i in range(9):
    for j in range(i + 1,10):
        if (i != 8) or (j != 9):
            print(f"{i:d}{j:d}, ",end="")
        else:
            print(f"{i:d}{j:d}")
