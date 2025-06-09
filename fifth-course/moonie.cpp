#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX{1001}, M_MAX{2001}, C_MAX{1000};
int N, M, C;
int days{0}, result{0};
vector<pair<int, int>> nxt[N_MAX];
int money[N_MAX];

void readGraph(){

    for (int i = 0; i < M; ++i){
        int a, b;
        scanf("%d %d\n", &a, &b);
        nxt[a].push_back({b, money[b]});
    }    
}

int state[N_MAX];
const int NOT_VISITED = 0, IN_VISITS = 1 , VISITED = 2 ;
int temp = 0;

void dfs(int node) {
    
    
    if(state[node] == NOT_VISITED) {    
        
        state[node] = IN_VISITS;

        ++days;
        
        for(auto& [v, mon] : nxt[node]){


            temp += mon;

            if (v == 1){
                fill(state, state + N_MAX, NOT_VISITED);
                if (result < temp - C * days * days){
                    result = temp - C * days * days;
                }

                else {
                    return;
                }

            }
            
            dfs(v);
        
        }
        
    }
    
}


int main(){
    
    scanf("%d %d %d\n", &N, &M, &C);
    fill(state, state + N_MAX, 0);
    
    for (int i = 1; i <= N; ++i){
        scanf("%d ", &money[i]);
    }

    readGraph();

    dfs(1);

    printf("%d\n", result);

}