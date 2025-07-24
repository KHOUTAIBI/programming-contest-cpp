#include <cstdio>
#include <algorithm>

const iint NMAX = 300 + 1;
int input[NMAX];
int N, x;


solve(int begin, int end){
    if (input[begin] == input[end]){
        return 1 + ;
    }


}


int main(){
    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i){
        scanf("%d ", &input[i]);
    }

    int result = 0;
    result = solve(0, N - 1);

    printf("%d\n", result);
}