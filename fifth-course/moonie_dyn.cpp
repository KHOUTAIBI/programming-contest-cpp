#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX{1001}, M_MAX{2001}, C_MAX{1001};

int dist[N_MAX][M_MAX];
int weights[N_MAX];
vector<int> adj[M_MAX];

const int INF = 1e8;
int N, M, C;

int BellmanFord(int root) {

    fill(dist[0], dist[N_MAX], -INF);

    int result = 0;
    dist[0][root] = 0;

    for(int t = 0; t < N_MAX; ++t){
        
        for (int city = 1; city <= N; ++city){
            
            if (dist[t][city] < 0) continue;

            for (auto v : adj[city]){
                int earned = weights[v] + dist[t][city];
                dist[t+1][v] = max(dist[t+1][v], earned);
            }

        }
        
        if (dist[t + 1][1] >= 0) {
            int profit = dist[t + 1][1] - C * (t + 1) * (t + 1);
            result = max(result, profit);
        }
   
    }

    return result;

}

int main(){
    
    scanf("%d %d %d\n", &N, &M, &C);
    for (int i = 1; i <= N; ++i){
        scanf("%d ", &weights[i]);
    }
    
    for (int i = 0; i < M; ++i){
        int a,b;
        scanf("%d %d\n", &a, &b);
        adj[a].push_back(b);
    }
    int result = BellmanFord(1);
    printf("%d\n", result);
}