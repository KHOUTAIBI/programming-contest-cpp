#include <cstdio>

int main(){

    int W, shatter_number, area{0}, l, w;

    scanf("%d\n", &W);
    scanf("%d\n", &shatter_number);

    while (scanf("%d %d\n", &w, &l) > 0){
        area += w * l;
    }

    printf("%d\n", area/W);
}