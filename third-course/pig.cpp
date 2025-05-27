#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 40005;
vector<int> graph[MAXN];
int distB[MAXN], distE[MAXN], distN[MAXN];

void bfs(int start, int dist[], int n) {
    
    fill(dist, dist + n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int B, E, P, N, M;
    scanf("%d %d %d %d %d", &B, &E, &P, &N, &M);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1, distB, N);  
    bfs(2, distE, N);  
    bfs(N, distN, N);  

    int minEnergy = 1e9;
    for (int i = 1; i <= N; ++i) {
        if (distB[i] != -1 && distE[i] != -1 && distN[i] != -1) {
            int energy = distB[i] * B + distE[i] * E + distN[i] * P;
            minEnergy = min(minEnergy, energy);
        }
    }

    printf("%d\n", minEnergy);
    return 0;
}
