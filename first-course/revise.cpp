#include <cstdio>
#include <algorithm>
#include <array>

using namespace std;

int main(){
    
    array<int, 7> numbers;
    int i = -1;

    while(scanf("%d", &numbers[++i]) > 0);

    sort(numbers.begin(), numbers.end());
    printf("%d %d %d\n", numbers[0], numbers[1], numbers[6] - numbers[0] - numbers[1]);

}   