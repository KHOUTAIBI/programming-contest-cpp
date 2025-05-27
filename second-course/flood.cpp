#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_NODE = 100 * 100;

int N, E, T;
int altitudes[MAX_NODE];
int forecast_seine[MAX_NODE];

vector<int> levels;
vector<int> graph[MAX_NODE];

void readGraph() {
    for (int i = 0; i < E; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

int solve(int start_node, const vector<int>& initial_levels) {

    vector<int> dist = initial_levels;
    vector<int> next_dist(N);

    vector<int> active_nodes;

    for (int i = 0; i < N; ++i) {
        if (dist[i] > 0) active_nodes.push_back(i);
    }

    for (int t = 0; t < T; ++t) {

        if (dist[1] > 0) return t;

        next_dist = dist;
        vector<bool> visited(N, false);

        for (int node : active_nodes) {

            for (int neighbor : graph[node]) {
            
                int propagated = dist[node] + altitudes[node] - altitudes[neighbor];
                if (propagated > next_dist[neighbor]) {
                    next_dist[neighbor] = propagated;
                    visited[neighbor] = true;
                }
            }
        }

        next_dist[0] = forecast_seine[t];
        
        active_nodes.clear();
        for (int i = 0; i < N; ++i) {
            if (next_dist[i] > dist[i]) {
                active_nodes.push_back(i);
            }
        }

        dist = move(next_dist);
    }

    return -1;
}


int main() {
    scanf("%d %d %d", &N, &E, &T);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &altitudes[i]);
    }

    levels.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &levels[i]);
    }

    for (int i = 0; i < T; ++i) {
        char dummy;
        scanf("%d%c", &forecast_seine[i], &dummy);
        if (dummy == '\n') break;
    }

    readGraph();

    int result = solve(1, levels);
    printf("%d\n", result);
    return 0;
}
