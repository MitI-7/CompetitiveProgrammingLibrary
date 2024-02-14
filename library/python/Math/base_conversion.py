# base 進数から10進数に変える
# v[0]が最上位の桁を表す
# 6 = 110 なら v = {0, 1, 1}
def to_base_10(v, base):
    ans = 0
    for x in v:
        assert x >= 0
        assert x < base
        ans = ans * base + x
    return ans


# 10 進数から base 進数に変える
def to_base_n(x, base):
    if x == 0:
        return [0]

    ans = []
    while x > 0:
        t = x % base
        ans.append(t)
        x //= base

    return ans[::-1]
