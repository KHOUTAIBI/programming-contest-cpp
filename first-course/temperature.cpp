#include <cstdio>

int main(){

    int t1, t2, t3, temperature;
    int min = 50;
    int max = -50;
    char sepe;

    while(scanf("%d-%d-%d", &t1, &t2, &t3) == 3){
        
        while(scanf("%d%c", &temperature, &sepe) > 0){
            
            
            if (temperature <= min){
                min = temperature;
            }    
            
            if (temperature >= max){
                max = temperature;
            }

            if (sepe == '\n') break;
        }
    }

    printf("%d %d\n", min, max);
}
