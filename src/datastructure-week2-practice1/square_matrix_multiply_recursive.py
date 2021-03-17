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


def square_matrix_multiply_recursive(A, B):
    if len(A) == 1:
        return A * B
    a11, a12, a21, a22 = split(A)
    b11, b12, b21, b22 = split(B)
    c11 = square_matrix_multiply_recursive(a11, b11) + square_matrix_multiply_recursive(a12, b21)
    c12 = square_matrix_multiply_recursive(a11, b12) + square_matrix_multiply_recursive(a12, b22)
    c21 = square_matrix_multiply_recursive(a21, b11) + square_matrix_multiply_recursive(a22, b12)
    c22 = square_matrix_multiply_recursive(a21, b12) + square_matrix_multiply_recursive(a22, b22)
    return np.vstack((np.hstack((c11, c12)), np.hstack((c21, c22))))


A = [[1, 2], [1, 2]]
B = [[2, 5], [5, 7]]
# Expected C = [[12 19], [12 19]]
print(square_matrix_multiply_recursive(np.matrix(A), np.matrix(B)))
