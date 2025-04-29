#include <cstdio>

int main(){
    
    int A{0}, B{0}, C{0};
    int tempA{0}, tempB{0}, tempC{0};
    int temp;

    scanf("%d ", &tempA);
    scanf("%d ", &tempB);
    
    if (tempB < tempA) {
        int tempvar;
        tempvar = tempA;
        tempA = tempB;
        tempB = tempvar;
    }
    
    scanf("%d ", &tempC);
    if (tempC < tempA) {
        int tempvar;
        tempvar = tempC;
        tempC = tempA;
        tempA = tempvar;
    }

    if (tempC < tempB) {
        int tempvar;
        tempvar = tempB;
        tempB = tempC;
        tempC = tempvar;
    }

    while(scanf("%d ", &temp) > 0){
        if (temp > tempC){
            tempA = tempB;
            tempB = tempC;
            tempC = temp;
        }
        if (temp >= tempB && temp < tempC){
            tempA = tempB;
            tempB = temp;
        }
        if (temp >= tempA && temp < tempB){
            tempA = temp;
        }
    }
    
    
    A = tempC - tempB;
    B = tempC - tempA;
    C = tempB - B;
    
    printf("%d %d %d\n", A, B, C);
}