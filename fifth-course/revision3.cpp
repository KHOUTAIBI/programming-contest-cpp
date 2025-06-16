#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX{1005}, M_MAX{2005}, T_MAX{1005};
long long values[N_MAX];
long long dp[N_MAX][T_MAX];
vector<int> nxt[M_MAX];
int N, M, C;

const long long INF = 1e18;

long long max_val(long long t, int node){
    
    if (t >= T_MAX) return -INF;
    long long res = dp[t][node];

    if (res == -INF){
        ++res;
        if (node == 1) res = - C * t * t;
        for (auto v : nxt[node]){
            res = max(res, max_val(t + 1, v));
        }
        res += values[node];
    }

    return res;
}



int main(){

    fill(dp[0], dp[T_MAX], -INF);
    scanf("%d %d %d\n", &N, &M, &C);
    
    for (int i = 1; i <= N; ++i){
        scanf("%d ", &values[i]);
    }
    
    int a,b;
    for (int i = 0; i < M; ++i){
        scanf("%d %d\n",  &a, &b);
        nxt[a].push_back(b);
    }

    long long result = max_val(0, 1);

    printf("%d\n", result);
}