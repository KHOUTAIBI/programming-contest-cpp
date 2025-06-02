#include <cstdio>
#include <cstring>

const int MAXN = 500;
const int MAXV = 2 * MAXN + 2;

int N, K;
int capa[MAXV][MAXV], flow[MAXV][MAXV];
bool visited[MAXV];


bool dfs(int u, int target) {
    if (visited[u]) return false;
    visited[u] = true;
    if (u == target) return true;

    for (int v = 0; v < MAXV; ++v) {
        if (flow[u][v] < capa[u][v]) {
            if (dfs(v, target)) {
                flow[u][v] += 1;
                flow[v][u] -= 1;
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &N, &K);
    int src  = 2 * N;
    int sink  = 2 * N + 1;

    for (int i = 0; i < K; ++i) {
        int r, c;
        scanf("%d %d", &r, &c);
        capa[r - 1][N + c -1] = 1;
    }

    for (int r = 0; r < N; ++r) {
        capa[src][r] = 1;
    }

    for (int c = 0; c < N; ++c) {
        capa[N + c][sink] = 1;
    }

    int result = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));
        if (!dfs(src, sink)) break;
        result++;
    }

    printf("%d\n", result);
    return 0;
}
