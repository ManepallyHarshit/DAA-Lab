#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(char c, int f, Node* l, Node* r) : ch(c), freq(f), left(l), right(r) {}
};

struct CompareNodes {
    bool operator()(const Node* a, const Node* b) const {
        return a->freq > b->freq;
    }
};

Node* buildHuffman(const vector<char>& chars, const vector<int>& freq) {
    if (chars.empty()) return nullptr;

    priority_queue<Node*, vector<Node*>, CompareNodes> minHeap;

    for (size_t i = 0; i < chars.size(); ++i) {
        minHeap.push(new Node(chars[i], freq[i]));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top();
        minHeap.pop();

        Node* right = minHeap.top();
        minHeap.pop();

        int combinedFreq = left->freq + right->freq;
        Node* parent = new Node('$', combinedFreq, left, right);

        minHeap.push(parent);
    }

    Node* root = minHeap.top();
    minHeap.pop();
    return root;
}

void printCodes(const Node* root, const string& code = "") {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->ch << ": " << (code.empty() ? "0" : code) << "\n";
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int numCharacters;
    cout << "Enter total number of characters: ";
    if (!(cin >> numCharacters) || numCharacters <= 0) {
        cerr << "Invalid number of characters.\n";
        return 1;
    }

    vector<char> chars(numCharacters);
    vector<int> freq(numCharacters);

    cout << "\nEnter each character followed by its frequency (e.g., 'a 15'):\n";
    for (int i = 0; i < numCharacters; ++i) {
        cout << "Character " << (i + 1) << ": ";
        if (!(cin >> chars[i] >> freq[i])) {
            cerr << "Invalid input format.\n";
            return 1;
        }
    }

    Node* root = buildHuffman(chars, freq);
    cout << "\nHuffman Codes:\n";
    printCodes(root);
    deleteTree(root);

    return 0;
}