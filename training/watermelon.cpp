#include <cstdio>

int main(){
    int w;

    scanf("%d\n", &w);

    if (w % 2 == 1 || w == 2){
        printf("NO\n");
        return 0;
    }

    else{
        printf("YES\n");
    }
}