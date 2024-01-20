# 2次元行列を右に90度回転
def matrix_rotate(A):
    H, W = len(A), len(A[0])
    ans = [[None] * H for _ in range(W)]

    for y in range(H):
        for x in range(W):
            ans[W - 1 - x][y] = A[y][x]

    return ans
