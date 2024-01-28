# s を並び替えてできる文字列のうち，s が辞書順で何番目か(0-indexed)を求める
def find_string_no_permutation_no(s):
    n = len(s)

    fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = fact[i - 1] * i

    freq = dict()
    for c in s:
        if c not in freq:
            freq[c] = 0
        freq[c] += 1
    chars = list(sorted(list(set(s))))

    ans = 0
    for i in range(n):
        for c in chars:
            if freq[c] == 0:
                continue

            if c >= s[i]:
                break

            freq[c] -= 1

            num = fact[n - i - 1]
            for v in freq.values():
                if v != 0:
                    num //= fact[v]

            ans += num
            freq[c] += 1

        freq[s[i]] -= 1

    return ans
