#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> music, chores;

bool checkEqual(vector<int> a, vector<int> b) {

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int diff = a[0] - b[0];
    bool equal = true;

    for (int i = 1; i < C; ++i)
        if (diff != a[i] - b[i]) equal = false;

    return equal;
}

int main() {
    scanf("%d\n", &N);
    int x;
    for (int i = 0; i < N; ++i) {
        scanf("%d\n", &x);
        music.push_back(x);
    }

    scanf("%d\n", &C);
    for (int i = 0; i < C; ++i) {
        scanf("%d\n", &x);
        chores.push_back(x);
    }

    vector<int> notes;
    vector<int> matches;

    for (int i = 0; i < C; ++i)
        notes.push_back(music[i]);

    int equal = checkEqual(notes, chores);
    if (equal) matches.push_back(1);

    for (int i = C; i < N; ++i) {
        notes.erase(notes.begin());
        notes.push_back(music[i]);

        equal = checkEqual(notes, chores);

        if (equal) matches.push_back(i + 2 - C);
    }

    printf("%d\n", matches.size());
    for (int u : matches) printf("%d\n", u);
}
