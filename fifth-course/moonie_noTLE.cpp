#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX{1005}, M_MAX{2001}, C_MAX{1001}, T_MAX = 1005;
long long dyn[N_MAX][T_MAX];
long long values[N_MAX];
vector<int> nxt[N_MAX];

const long long INF = 1e18;
int N, M, C;

long long max_value(long long t, int node) {

   if (t >= T_MAX) return -INF;
   long long& res = dyn[t][node];

    if (res == -INF){
        res++;
        if (node == 1) res = - C * (long long)t * (long long)t; 
        for (int v : nxt[node]){
            res = max(res, max_value(t + 1, v));
        }
        res += values[node];
    }
    return res;
}

int main(){

    fill(dyn[0],dyn[N_MAX],-INF);

    scanf("%d %d %d\n", &N, &M, &C);
    
    for (int i = 1; i <= N; ++i){
        scanf("%lld ", &values[i]);
    }
    
    long long a,b;
    for (int i = 0; i < M; ++i){
        scanf("%lld %lld\n", &a, &b);
        nxt[a].push_back(b);
    }

    long long result = max_value(0, 1);
    printf("%lld\n", result);
}