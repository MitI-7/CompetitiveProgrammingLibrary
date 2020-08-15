std::vector<std::pair<int, int>> make_tree(int n) {
    std::vector<std::pair<int, int>> edges;
    std::queue<int> nodes;
    nodes.push(0);

    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> rand(1, 5); // 最大の枝の数

    int last_node = 1;
    while (not nodes.empty()) {
        int node = nodes.front(); nodes.pop();

        for (int i = 0; i < rand(mt); ++i) {
            edges.emplace_back(std::make_pair(node, last_node));
            nodes.push(last_node);
            last_node++;

            if (last_node >= n) {
                break;
            }
        }

        if (last_node >= n) {
            break;
        }
    }

    return edges;
}