# target が含まれる最小の長方形になるように matrix の周囲を削除する
def matrix_strip(matrix, target="#"):
    h, w = len(matrix), len(matrix[0])
    min_y, max_y = h, -1
    min_x, max_x = w, -1
    for y in range(h):
        for x in range(w):
            if matrix[y][x] == target:
                min_x = min(min_x, x)
                max_x = max(max_x, x)
                min_y = min(min_y, y)
                max_y = max(max_y, y)

    ans = []
    for y in range(h):
        b = []
        for x in range(w):
            if min_y <= y <= max_y and min_x <= x <= max_x:
                b.append(matrix[y][x])
        if b:
            ans.append(b)
    return ans
