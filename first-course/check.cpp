#include <cstdio>
#include <string>
using namespace std;

int main(){

    int total{0};
    int price, number;
    int TOTAL;
    char name[1000];

    
    while(1){
        
        scanf("%[^\n]", name);
        string name_string(name);
        
        if (name_string == "TOTAL"){
            break;
        }

        scanf("%d %d\n", &price, &number);
        total += (price * number);

    }

    scanf("%d\n", &TOTAL);

    if (total < TOTAL){
        printf("PROTEST");
    }

    else {
        printf("PAY");
    }
}   