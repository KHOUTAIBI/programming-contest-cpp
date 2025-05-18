#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

void solve(int arra[], int arrb[], int k){
    int n = sizeof(arra) / arra[0]
    pair<int, int> arr[n];
    
    for (int i = 0; i < n; ++i){
        arr[i] = {arra[i], arrb[i]};
    }

    sort(arr, arr + n);
    int max_len = arr[n - 1].first - arr[0].second;

    int sum = 0;
    bool impossible = false;

}

int main(){

    int N, n, k;
    int a,b;

    set<int, int> a_b_s;

    while (scanf("%d\n", &N) > 0){
        
        int index = 0;
        scanf("%d %d\n", &n, &k);
        int arr_a[n];
        int arr_b[n]
        char c;
        
        while (scanf("%d%c", &arr_a[index], &c) > 0){
            if (c == '\n') break;
        }
        
        while (scanf("%d%c", &arr_b[index], &c) > 0){
            if (c == '\n') break;
        } 

    }
}