#include <cstdio>


int main(){
    
    int n, k;
    scanf("%d", &n);
    scanf("%d\n", &k);
    int arr[n];
    int i = 1;
    int index = 0;

    while (scanf("%d", &arr[index]) > 0){
        ++index;
    }

    int score = arr[k - 1];
    int total{0};

    if (arr[0] == 0){
        printf("0\n");
        return 0;
    }

    for (int j = 0; j < n; ++j){
        if (arr[j] >= score && arr[j] != 0){
            total += 1;
        }
    }

    printf("%d\n", total);
}