#include <cstdio>
#include <algorithm>

using namespace std;

typdef pair<int, int> msg;

int NMAX = 2 * 10 * 100 + 1, XMAX = 1001, XMIN = -1000;
int N, x, y;
pair messages[NMAX];

int main(){
    scnaf("%d\n", &N);
    
    for (int i = 0; i < N; ++i){
        scanf("%d %d\n", &x, &y);
        msg message{x, y};
        messages[i] = message;
    }


    for (int i = 0; i < N; ++i){
        msg {x1, y1}  = messages[i];
        for (int j = i; j < N; ++j){
                     
        }
    }
}