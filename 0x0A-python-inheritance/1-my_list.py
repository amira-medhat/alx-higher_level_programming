#!/usr/bin/python3
""" inherited list class MyList """


class MyList(list):
    """ Implements sorted printing for the built-in list class """

    def print_sorted(self):
        """ Print a list in sorted ascending order """
        temp = list(self)
        temp.sort(reverse = False)
        print(temp)
