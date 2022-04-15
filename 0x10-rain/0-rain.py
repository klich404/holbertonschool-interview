#!/usr/bin/python3
"""0_rain"""


def rain(walls):
    """rain function"""
    if type(walls) is not list:
        return 0
    if len(walls) is 0:
        return 0
    water = 0
    for idx, mid in enumerate(walls):
        if idx is not 0 and idx is not (len(walls) - 1):
            left = max(walls[0:idx])
            right = max(walls[idx + 1:len(walls)])
            if mid < left and mid < right:
                water += min([left, right]) - mid
    return water
