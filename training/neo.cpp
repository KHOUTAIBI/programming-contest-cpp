#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
    Node(T value, Node* l) : data(value), left(l), right(nullptr) {}
    Node(T value, Node* l, Node* r) : data(value), left(l), right(r) {}
};

vector<Node<int>*> solution;


void solve(int points[], int n) {
    Node<int>* tree = nullptr;
    Node<int>* temp = nullptr;
    int bottom_leaf = INT_MIN;

    for (int i = 0; i < n; ++i) {
        int val = points[i];

        if (!tree) {
            tree = new Node<int>(val);
            temp = tree;
            bottom_leaf = val;
            continue;
        }

        if (val > bottom_leaf) {
            solution.push_back(tree);
            tree = new Node<int>(val);
            temp = tree;
            bottom_leaf = val;
            continue;
        }

        
        if (temp->left && val >= temp->left->data) {
            Node<int>* newNode = new Node<int>(val);
            temp->right = newNode;
            temp = newNode;
        } else {
            Node<int>* newNode = new Node<int>(val);
            newNode->left = temp->left;
            temp->left = newNode;
            temp = newNode;
        }

        bottom_leaf = val;
    }

    if (tree) {
        solution.push_back(tree);
    }
}




int main() {
    int t, N;
    scanf("%d\n", &t);

    while (t--) {
        
        scanf("%d", &N);
        int points[N];

        for (int i = 0; i < N; ++i) {
            scanf("%d", &points[i]);
        }

        solve(points, N);
        printf("%d\n", solution.size());
        solution.clear(); 
    }

    return 0;
}
