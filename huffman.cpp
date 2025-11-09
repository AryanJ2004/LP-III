#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Node structure
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Compare function for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // smaller freq = higher priority
    }
};

// Print Huffman Codes (recursive)
void printCodes(Node* root, string code) {
    if (!root) return;
    if (!root->left && !root->right)
        cout << root->ch << " : " << code << endl;
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    cout << "Enter characters and frequencies:\n";
    for (int i = 0; i < n; i++) {
        char c; int f;
        cin >> c >> f;
        pq.push(new Node(c, f));
    }

    // Build Huffman Tree (Greedy)
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    cout << "\nHuffman Codes:\n";
    printCodes(pq.top(), "");

    return 0;
}

// I/P:
// 6
// a 5
// b 9
// c 12
// d 13
// e 16
// f 45