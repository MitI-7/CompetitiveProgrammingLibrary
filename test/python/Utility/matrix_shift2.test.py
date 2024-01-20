# verification-helper: PROBLEM https://atcoder.jp/contests/abc300/tasks/abc300_b

from library.python.Utility.matrix_shift import shift_left_y, shift_up_x


def main():
    H, W = map(int, input().split())
    A, B = [], []
    for _ in range(H):
        A.append(list(input()))
    for _ in range(H):
        B.append(list(input()))

    for i in range(H):
        for j in range(W):
            if A == B:
                print("Yes")
                return

            for y in range(H):
                shift_left_y(y, A)

        for x in range(W):
            shift_up_x(x, A)

    print("No")


if __name__ == '__main__':
    main()
