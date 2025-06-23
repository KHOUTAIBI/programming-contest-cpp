#include <cstdio>


using namespace std;

const int N_MAX{1001};
int df[N_MAX][N_MAX];


int main(){
    
    int N, K;
    
    scanf("%d %d\n", &N, &K);

    for (int i = 0; i < N; ++i){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
        df[x1][y1] += 1;
        df[x2][y2] +=1;
        df[x1][y2] -=1;
        df[x2][y1] -=1;
    }
    
    for (int x = 0; x < N_MAX; ++x){
        for (int y = 1; y < N_MAX; ++y){
            df[x][y] += df[x][y-1];
        }
    }

    for (int y = 0; y < N_MAX; ++y){
        for (int x = 1; x < N_MAX; ++x){
            df[x][y] += df[x-1][y];
        }
    }

    int res = 0;
    for (int y = 0; y < N_MAX; ++y){
        for (int x = 0; x < N_MAX; ++x){
            if (df[x][y] == K) res++;
        }
    }

    printf("%d\n", res);
}

