#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

    int N, M, capacity, request;
    set<pair<int , int>> s;
    scanf("%d %d\n", &N, &M);

    for (int i = 0; i< N; ++i){
        scanf("%d\n", &capacity);
        s.insert({capacity, i});
    }

    for (int j = 0; j < M; ++j){
        scanf("%d\n", &request);

        auto it = s.lower_bound({request, 0});

        if (it != s.end()){
            printf("%d\n", it->second);
            s.erase(it);
        }

        else printf("-1\n");

    }

}