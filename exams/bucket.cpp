#include <cstdio>
#include <algorithm>

using namespace std;

const int NMAX = 100 + 1;
int times[NMAX];
int df[NMAX];
int N, s, t, b;


int main(){
    
    scanf("%d\n", &N);
    fill(df, df + NMAX, 0);
    int total = 0;

    for (int i = 0; i < N; ++i){
        scanf("%d %d %d\n", &s, &t, &b);
        times[t] -= b;
        times[s] += b;
    }
 
    for (int i = 1; i < NMAX; ++i){
        df[i] = df[i - 1] + times[i];
        total = max(total, df[i]);
    }

    printf("%d\n", total);
}