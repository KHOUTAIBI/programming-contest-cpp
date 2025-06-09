#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N_MAX = 500 + 3;
unsigned long long dp[N_MAX][N_MAX];
int N;

long long solve(vector<unsigned long long> dist){

    unsigned long long energy = 0;

    for (int i = 0; i < N; ++i) dp[i][i] = 0;

    for (int len = 2; len <= N; ++len){
        
        for (int i = 0; i + len <= N ; ++i){
            
            int j = len + i - 1;

            dp[i][j] = 1e19;

            for (int k = i; k <= j ; ++k){
                energy += dist[k];
            }


            for (int k = i; k < j; ++k){
                dp[i][j] = min(dp[i][k] + dp[k+1][j] + energy, dp[i][j]);
            }

            energy = 0;
        }
    }

    return dp[0][N-1];
}


int main(){
    
    scanf("%d\n", &N);
    vector<unsigned long long> values;
    unsigned  long x;
    
    while(scanf("%lld ", &x) > 0){
        values.push_back(x);
    }

    unsigned long long sol = solve(values);

    printf("%lld\n", sol);
}