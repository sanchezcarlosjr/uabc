# Version 3.6
import numpy as np


def split(matrix):
    """
    Splits a given matrix into quarters.
    Input: nxn matrix
    Output: tuple containing 4 n/2 x n/2 matrices corresponding to a, b, c, d
    """
    row, col = matrix.shape
    row2, col2 = row // 2, col // 2
    return matrix[:row2, :col2], matrix[:row2, col2:], matrix[row2:, :col2], matrix[row2:, col2:]


def strassen(A, B):
    if len(A) == 1:
        return A * B
    a11, a12, a21, a22 = split(A)
    b11, b12, b21, b22 = split(B)
    p1 = strassen(a11, b12 - b22)
    p2 = strassen(a11 + a12, b22)
    p3 = strassen(a21 + a22, b11)
    p4 = strassen(a22, b21 - b11)
    p5 = strassen(a11 + a22, b11 + b22)
    p6 = strassen(a12 - a22, b21 + b22)
    p7 = strassen(a11 - a21, b11 + b12)
    c11 = p5 + p4 - p2 + p6
    c12 = p1 + p2
    c21 = p3 + p4
    c22 = p5 + p1 - p3 - p7
    return compress(c11, c12, c21, c22)


def compress(c11, c12, c21, c22):
    return np.vstack((np.hstack((c11, c12)), np.hstack((c21, c22))))


A = [[1, 2], [1, 2]]
B = [[2, 5], [5, 7]]
# Expected C = [[12 19], [12 19]]
print(strassen(np.matrix(A), np.matrix(B)))
