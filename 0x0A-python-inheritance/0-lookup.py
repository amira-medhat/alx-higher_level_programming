#!/usr/bin/python3
""" Defines an object attribute lookup function """


def lookup(obj):
    """ returns a list of object's available attributes and functions """
    return (dir(obj))
