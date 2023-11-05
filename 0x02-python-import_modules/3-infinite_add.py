#!/usr/bin/python3
if __name__ == "__main__":
    import sys
    result = 0
    for i in sys.argv[1:]:  # Start from the second argument (sys.argv[0] is the script name)
        result += int(i)
    print("{}".format(result))
