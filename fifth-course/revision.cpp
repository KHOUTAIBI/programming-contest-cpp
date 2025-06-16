#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 500 + 3;
unsigned long long dp[N_MAX][N_MAX];
int N;

int solve(vector<unsigned long long> values){

    unsigned long long energy;

    for (int i = 0; i < N; ++i){
        dp[i][i] = 0;
    }

    for (int len = 2; len <= N; ++len){
        for (int i = 0; i <= N; ++i){

            int  j = i + len - 1;
            dp[i][j] = 1e18;

            for (int k = i; k <= j ; ++k){
                energy += values[k];
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
    unsigned long long x;

    while (scanf("%lld ", &x) > 0){
        values.push_back(x);
    }

    unsigned long long sol = solve(values);
    printf("%lld\n", sol);
}