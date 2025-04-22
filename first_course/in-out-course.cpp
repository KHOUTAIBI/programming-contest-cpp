#include <cstdio>
#include <iostream>

int main(){
    printf("%i\n", 10);
    int a, b, c;
    char s1[101], s2[102];
    scanf("%d %d %d", &a, &b, &c);
    scanf("%[^\n]\n", s1);
    scanf("%[^\n]\n", s2);

    if (a + b == c){
        printf("%s\n", s1);
    }

    else {
        printf("%s", s2);
    }

}