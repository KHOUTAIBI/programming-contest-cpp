#include <cstdio>
#include <set>

using namespace std;

int N, K;
const int MAX_NODES  = 1000 * 1000;
int adjacency[MAX_NODES][MAX_NODES];
int capa[MAX_NODES][MAX_NODES], flow[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];


int dfs(int x, int target) {
    
    if(visited[x]) return 0;
    if(x==target) return 1;  
    visited[x] = true; 
    for(int i = 0; i < N; ++i) 
    if(flow[x][n] < capa[x][n]) { 
    
    const int sub_flow = dfs(n, target);
    if(sub_flow > 0) {
        flow[x][n]+= 1;
        flow[n][x]-= 1;
        return sub_flow;
    }
    return 0; 
}


int main(){
    
    scanf("%d %d\n", &N, &K);

    for (int i = 0; i < N; ++i){
        int x, y;
        scanf("%d %d\n", &x, &y);
    }

    for (int i = 0; i < N; ++i){
        adjacency[x][y] = 1;
    }

    for (int i = 0; i < N; ++i){
        adjacency[N][i] = 1;
    }

    for (int i = 0; i < N; ++i){
        adjacency[i][N] = 1;
    }

    int res = 0;
    int INF = 1000 * 1000;
    while(dfs(N, INF, N - 1)){
        res+= dfs(N, INF, N - 1);
    }
}