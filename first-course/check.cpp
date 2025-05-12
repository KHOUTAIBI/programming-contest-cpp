#include <cstdio>

int main(){

    long double total = 0.00;
    long double money;

    while(scanf("%f", &money) == 1){   
        total += money;
    }

    printf("%.2Lf", total);
}