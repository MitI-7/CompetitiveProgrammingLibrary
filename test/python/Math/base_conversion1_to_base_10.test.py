# verification-helper: PROBLEM https://atcoder.jp/contests/abc220/tasks/abc220_b

from library.python.Math.base_conversion import to_base_10


def main():
    K = int(input())
    A, B = input().split()
    print(to_base_10([int(a) for a in A], K) * to_base_10([int(b) for b in B], K))


if __name__ == '__main__':
    main()
