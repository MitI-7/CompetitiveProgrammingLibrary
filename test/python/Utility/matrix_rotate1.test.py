# verification-helper: PROBLEM https://atcoder.jp/contests/abc298/tasks/abc298_b

from library.python.Utility.matrix_rotate import matrix_rotate


def main():
    N = int(input())
    A, B = [], []
    for _ in range(N):
        A.append(list(map(int, input().split())))
    for _ in range(N):
        B.append(list(map(int, input().split())))

    for i in range(4):
        ok = True
        for y in range(N):
            for x in range(N):
                if A[y][x] == 1:
                    ok &= B[y][x] == 1
        if ok:
            print("Yes")
            return
        A = matrix_rotate(A)

    print("No")


if __name__ == '__main__':
    main()
