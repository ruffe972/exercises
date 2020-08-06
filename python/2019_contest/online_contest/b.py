import math

def new_matrix(dimen):
    matrix = []
    for i in range(dimen):
        matrix.append([False] * dimen)
    return matrix

encrypted_msg = input()
mask = input()
dimen = round(math.sqrt(len(mask)))
matrix = new_matrix(dimen)

for row in range(dimen):
    for col in range(dimen):
        matrix[row][col] = True if mask[row * dimen + col] == '1' else False

for k in range(4):        
    for row in range(dimen):
        for col in range(dimen):
            if not matrix[row][col]:
                print(encrypted_msg[row * dimen + col], end='')
    rotated_mat = new_matrix(dimen)
    for row in range(dimen):
        for col in range(dimen):
            if matrix[row][col]:
                rotated_mat[col][dimen - row - 1] = True
    matrix = rotated_mat
