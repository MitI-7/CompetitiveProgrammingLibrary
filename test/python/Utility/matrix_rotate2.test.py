# verification-helper: PROBLEM https://atcoder.jp/contests/abc218/tasks/abc218_c

from library.python.Utility.matrix_rotate import matrix_rotate
from library.python.Utility.matrix_strip import matrix_strip


def main():
    N = int(input())
    S, T = [], []
    for y in range(N):
        S.append(input())
    for y in range(N):
        T.append(input())

    S, T = matrix_strip(S, "#"), matrix_strip(T, "#")

    for i in range(4):
        if S == T:
            print("Yes")
            return
        S = matrix_rotate(S)

    print("No")


if __name__ == '__main__':
    main()
