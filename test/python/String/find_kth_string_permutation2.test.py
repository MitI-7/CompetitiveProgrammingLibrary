# verification-helper: PROBLEM https://atcoder.jp/contests/abc215/tasks/abc215_c

from library.python.String.find_kth_string_permutation import find_kth_string_permutation


def main():
    S, K = input().split()
    print(*find_kth_string_permutation(int(K) - 1, S), sep="")


if __name__ == '__main__':
    main()
