#!/usr/bin/python3
"""
Rotate a 2d matrix
"""


def rotate_2d_matrix(matrix):
    """
    rotate function
    """
    dim = len(matrix)
    for idx in range(0, int(dim/2)):
        for idy in range(idx, dim-idx-1):
            temp = matrix[idx][idy]
            matrix[idx][idy] = matrix[dim-idy-1][idx]
            matrix[dim-idy-1][idx] = matrix[dim-idx-1][dim-idy-1]
            matrix[dim-idx-1][dim-idy-1] = matrix[idy][dim-idx-1]
            matrix[idy][dim-idx-1] = temp
