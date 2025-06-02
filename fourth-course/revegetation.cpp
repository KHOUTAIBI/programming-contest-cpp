#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int NB_NODE_MAX = 1000 * 1000;
vector<pair<int, char>> nxt[NB_NODE_MAX];
int type[NB_NODE_MAX];
int N, M, res{0};

void readGraph(){
    
    
    scanf("%d %d\n", &N, &M);
    for (int i = 0; i < M; ++i){
        char c;
        int x, y;
        scanf("%c %d %d\n", &c, &x, &y);
        nxt[x].push_back({y, c}); 
        nxt[y].push_back({x, c});
    }

}


void mark(int n, int color){
    if (type[n]){
        if (type[n] != color){
            res = - NB_NODE_MAX;
        }
    } else {
        type[n] = color;
        for (auto [v, t] : nxt[n]){
            if (t == 'S'){
                mark(v, color);
            }
            else mark(v, 3 - color);
        }
    }
}



int main(){

    readGraph();
    for (int i = 1; i <= N; ++i){
        if (type[i] == 0){
            ++res;
            mark(i, 1);
        }
    }

    if (res <= 0){
        printf("0\n");
     
    }

    else {
        printf("1");
        for (int i = 0; i < res; ++i){
            printf("0");
        }
        printf("\n");
    }
}