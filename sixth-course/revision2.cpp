#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> music;
vector<int> chods;

bool checkEqual(vector<int> a, vector<int> b){

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int changed = true;
    int diff = a[0] - b[0];

    for (int i = 1; i < C; ++i){
        if (diff != a[i] - b[i]) changed = false;
    }

    return changed;
}


int main(){

    scanf("%d\n", &N);
    
    int x;
    for (int i = 0; i < N; ++i){
        scanf("%d\n", &x);
        music.push_back(x);
    }

    scanf("%d\n", &C);
    for (int i = 0; i < C; ++i){
        scanf("%d\n", &x);
        chods.push_back(x);
    }

    vector<int> window;
    vector<int> indexes;
    
    for (int i = 0; i < C; ++i) window.push_back(music[i]);


    bool equal = checkEqual(window, chods); 
    if (equal) indexes.push_back(1);

    for (int i = C; i < N; ++i){

        window.erase(window.begin());
        window.push_back(music[i]);

        equal = checkEqual(window, chods);
        if (equal) indexes.push_back(i + 2 - C);
    }

    printf("%d\n", indexes.size());

    for (int u : indexes) printf("%d\n", u);
}