#!/usr/bin/python3
"""  Lockboxes """


def canUnlockAll(boxes):
    """Method to check unlocked boxes"""
    dict_boxes = {0: "open"}
    for i in range(1, len(boxes)):
        dict_boxes[i] = "locked"

    for x in boxes:
        for index, box in enumerate(boxes):
            if dict_boxes[index] == "open":
                for key in box:
                    dict_boxes[key] = "open"

    cont = 0
    for value in dict_boxes.values():
        if value == "open":
            cont += 1

    if cont == len(dict_boxes):
        return True
    else:
        return False
