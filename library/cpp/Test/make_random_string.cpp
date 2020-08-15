// サイズnのランダムな文字列を作成
// uniqueをtrueにすると，返却する文字列に文字の重複がないようになる
std::string make_random_string(const int n, const bool unique=false) {
    std::random_device rnd;
    std::mt19937 mt(rnd());

    const std::string alpha = "abcdefghijklmnopqrstuvwxyz";
//    const std::string alpha = "ABCDEFGHIJKLMNOPQRSTUWXYZ";

    std::vector<int> idx_list(n);

    if (unique) {
        assert(n <= 26);
        std::iota(idx_list.begin(), idx_list.end(), 0);
        std::shuffle(idx_list.begin(), idx_list.end(), mt);
    }
    else {
        for (int i = 0; i < n; ++i) {
            idx_list[i] = mt() % alpha.size();
        }
    }

    std::string s;
    for (int i = 0; i < n; ++i) {
        s += alpha[idx_list[i]];
    }
    
    return s;
}