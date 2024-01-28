# verification-helper: PROBLEM https://atcoder.jp/contests/abc202/tasks/abc202_d

from library.python.String.find_kth_string_permutation import find_kth_string_permutation


def main():
    A, B, K = map(int, input().split())

    s = "a" * A + "b" * B
    ans = find_kth_string_permutation(K - 1, s)
    print(*ans, sep="")


if __name__ == '__main__':
    main()
