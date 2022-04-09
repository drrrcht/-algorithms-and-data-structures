#include <iostream>
#include <vector>

int n, diameter = -1, vertex = -1;

std::vector<std::vector<int>> graph;
std::vector<std::vector<std::vector<int>>> binary_lift;
std::vector<std::vector<int>> depth;
std::vector<int> parent;

void dfs1(int node, int dist, int p, bool take = false) {
    if (take) {
        parent[node] = p;
    }

    if (diameter <= dist) {
        diameter = dist;
        vertex = node;
    }

    for (int i: graph[node]) {
        if (i != p) {
            dfs1(i, dist + 1, node, take);
        }
    }
}

std::vector<int> get_diameter(int root) {
    std::vector<int> result;
    parent.resize(n + 5, -1);
    dfs1(root, 0, -1, false);
    result.emplace_back(vertex);
    dfs1(vertex, 0, -1, true);
    result.emplace_back(vertex);
    return result;
}

void dfs(int node, int p, int id, int lvl) {
    depth[id][node] = lvl;
    binary_lift[id][0][node] = p;

    for (int i = 1; i < 17; ++i) {
        if (binary_lift[id][i - 1][node] == -1) {
            break;
        }

        binary_lift[id][i][node] = binary_lift[id][i - 1][binary_lift[id][i - 1][node]];
    }

    for (int i: graph[node]) {
        if (i != p) {
            dfs(i, node, id, lvl + 1);
        }
    }
}

int computeNode(int id, int node, int distance) {
    int x = node;

    for (int i = 16; i >= 0; --i) {
        if (x == -1) {
            return x;
        }

        if (distance & (1LL << i)) {
            x = binary_lift[id][i][x];
        }
    }

    return x;
}

void solve() {
    int query, u, v, ver, dist;
    std::cin >> n >> query;

    graph.resize(n + 5);
    binary_lift.resize(2, std::vector<std::vector<int>>(17, std::vector<int>(n + 5, -1)));
    depth.resize(2, std::vector<int>(n + 5, 0));

    for (int i = 1; i < n; ++i) {
        std::cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    std::vector<int> endPoints = get_diameter(1);

    dfs(endPoints[0], -1, 0, 0);
    dfs(endPoints[1], -1, 1, 0);

    for (int i = 0; i < query; ++i) {
        std::cin >> ver >> dist;
        int node1 = computeNode(0, ver, dist);
        int node2 = computeNode(1, ver, dist);

        if (node1 != -1) {
            std::cout << node1 << '\n';
            continue;
        }

        if (node2 != -1) {
            std::cout << node2 << '\n';
            continue;
        }

        std::cout << 0 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}
