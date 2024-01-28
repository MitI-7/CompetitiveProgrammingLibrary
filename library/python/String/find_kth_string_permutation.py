# s を並び替えてできる文字列のうち，辞書順で k 番目(0-indexed)の文字列を求める
# 存在しない場合は空文字列を返す
def find_kth_string_permutation(k, s):
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

    # k が作れるかチェック
    max_k = fact[n]
    for v in freq.values():
        max_k //= fact[v]

    if k >= max_k:
        return []

    ans = []
    for i in range(n):
        # i 文字目を c にできるか
        for c in chars:
            if freq[c] <= 0:
                continue

            freq[c] -= 1

            # i 文字目を c にしたとき，作成できる文字列の個数
            count = fact[n - i - 1]
            for v in freq.values():
                count //= fact[v]

            if k < count:
                ans.append(c)
                break

            freq[c] += 1
            k -= count

    return ans
