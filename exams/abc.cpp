#include <cstdio>
#include <algorithm>

using namespace std;

int inputs[7];

int main(){
    for (int i = 0; i < 7; ++i){
        scanf("%d ", &inputs[i]);
    }

    sort(inputs, inputs + 7);

    printf("%d %d %d\n", inputs[0], inputs[1], inputs[6] - inputs[0] - inputs[1]);
}
