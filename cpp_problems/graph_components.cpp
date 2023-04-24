#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

void dfs(std::unordered_map<int, std::unordered_set<int>>& graph, int vertex, int component, std::vector<int>& components) {
    components[vertex] = component;
    for (int neighbor : graph[vertex]) {
        if (components[neighbor] == 0) {
            dfs(graph, neighbor, component, components);
        }
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::unordered_map<int, std::unordered_set<int>> graph;
    int first_end, second_end;
    for (int i = 0; i < M; i++) {
        std::cin >> first_end >> second_end;
        graph[first_end - 1].insert(second_end - 1);
        graph[second_end - 1].insert(first_end - 1);
    }

    // for checking both visited and component for each vertex
    std::vector<int> components(N, 0);
    int component = 0;
    for (int i = 0; i < N; i++) {
        if (components[i] == 0) {
            component += 1;
            // i stays for vertex
            dfs(graph, i, component, components);
        }
    }

    std::cout << component << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << components[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
