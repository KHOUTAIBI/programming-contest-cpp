#include <cstdio>

int main(){

    int N, t,v,d, sure{0}, total{0};
    char c;
    
    scanf("%d\n", &N);

    while(scanf("%d %d %d\n", &t,&v,&d) > 0){

        sure = t + v + d;

        if (sure > 1){
            total += 1;
        }

        sure = 0;

    }

    printf("%d\n", total);

}