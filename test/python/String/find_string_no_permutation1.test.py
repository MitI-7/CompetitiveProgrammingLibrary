# verification-helper: PROBLEM https://atcoder.jp/contests/abc276/tasks/abc276_c

from library.python.String.find_kth_string_permutation import find_kth_string_permutation
from library.python.String.find_string_no_permutation import find_string_no_permutation_no


def main():
    N = int(input())
    P = list(map(int, input().split()))

    k = find_string_no_permutation_no(P)
    print(*find_kth_string_permutation(k - 1, P))


if __name__ == '__main__':
    main()
