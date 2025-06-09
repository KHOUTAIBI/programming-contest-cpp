#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int N_MAX = 1000 * 1000 + 1;
const int K_max = 20 + 1;
const int moves = 3;

int dyn[N_MAX][K_max][3];
int fj[N_MAX];

int N, K;

int win(int b, int f){
    
    if (b == 0 && f == 2){
        return 1;
    }

    if (b == 1 && f == 0){
        return 1;
    }
    
    if (b == 2 && f == 1){
        return 1;
    }

    return 0;
    
}

int solve(){

    for (int g = 0; g < moves; ++g){
        dyn[0][0][g] = win(g, fj[0]);
    }

    for (int i = 1; i < N; ++i){

        for (int k = 0; k <= K; ++k){

            for (int g = 0; g < 3; ++g){
     
                dyn[i][k][g] = dyn[i - 1][k][g] + win(g, fj[i]);

                if (k > 0){
     
                    for (int prev = 0; prev < 3; ++prev){
                        if (prev != g){
                            dyn[i][k][g] = max(dyn[i][k][g], dyn[i-1][k-1][prev] + win(g, fj[i]));
                        }
                    }
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < moves; ++i){
        result = max(result, dyn[N-1][K][i]);
    }

    return result;

}


int main(){

    scanf("%d %d\n", &N, &K);

    fill(dyn[0][0], dyn[N_MAX][0], 0);

    char c;
    int i = 0;

    while(i < N){
        scanf("%c\n", &c);
        if (c == 'H') fj[i] = 0;
        else if(c == 'P') fj[i] = 1;
        else if(c == 'S') fj[i] = 2;
        ++i;
    } 


    int sol = solve();
    printf("%d\n", sol);
}