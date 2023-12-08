#!/usr/bin/python3

class LockedClass:
    """
    A class that restricts dynamic creation of instance attributes, allowing only 'first_name'.

    Attributes:
        None
    """

    def __setattr__(self, attr, value):
        """
        Overrides the default attribute setting behavior to restrict attribute creation.

        Args:
            attr (str): The attribute name to be set.
            value: The value to be assigned to the attribute.

        Raises:
            AttributeError: If attempting to set an attribute other than 'first_name'.
        """
        if attr != 'first_name':
            raise AttributeError(
                "'LockedClass' object has no attribute '{}'".format(attr)
            )
        self.__dict__[attr] = value
        
