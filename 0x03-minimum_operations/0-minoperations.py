#!/usr/bin/python3
"""
Returns an integer
If n is impossible to achieve, return 0
"""


def minOperations(n):
    """Returns an integerIf n is impossible to achieve, return 0"""

    if type(n) is not int:
        return 0
    if n <= 1:
        return 0

    operations = 0
    character = 1
    copys = 1

    while character < n:
        if n % character == 0:
            copys = character
            operations += 1
        if character != n:
            character += copys
            operations += 1
        else:
            break
    return operations
