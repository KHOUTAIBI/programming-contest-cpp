#include <cstdio>

int main(){

    float total = 0.0;
    float money;

    while(scanf("%f", &money) == 1){   
        total += money;
    }

    printf("%.2lf", total);
}