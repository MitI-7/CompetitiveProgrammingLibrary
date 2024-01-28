# verification-helper: PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_c

from library.python.Utility.matrix_strip import matrix_strip


def main():
    HA, WA = map(int, input().split())
    A = [input() for _ in range(HA)]

    HB, WB = map(int, input().split())
    B = [input() for _ in range(HB)]

    HX, WX = map(int, input().split())
    X = [input() for _ in range(HX)]

    A, B, X = matrix_strip(A, '#'), matrix_strip(B, '#'), matrix_strip(X, '#')

    HA, WA = len(A), len(A[0])
    HB, WB = len(B), len(B[0])
    HX, WX = len(X), len(X[0])
    for sy_a in range(HX - HA + 1):
        for sx_a in range(WX - WA + 1):
            for sy_b in range(HX - HB + 1):
                for sx_b in range(WX - WB + 1):

                    ans = [["."] * WX for _ in range(HX)]
                    for y in range(HA):
                        for x in range(WA):
                            if A[y][x] == '#':
                                ans[sy_a + y][sx_a + x] = A[y][x]
                    for y in range(HB):
                        for x in range(WB):
                            if B[y][x] == '#':
                                ans[sy_b + y][sx_b + x] = B[y][x]

                    if ans == X:
                        print("Yes")
                        return
    print("No")


if __name__ == '__main__':
    main()
