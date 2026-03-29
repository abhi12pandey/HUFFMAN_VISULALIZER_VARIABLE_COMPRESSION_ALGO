#include<bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) {
        this->ch = ch;
        this->freq = freq;
        left = right = NULL;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string str) {
    if (!root) return;

    if (root->ch != '$')
        cout << root->ch << ": " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void huffmanCoding(vector<char> chars, vector<int> freq) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < chars.size(); i++) {
        pq.push(new Node(chars[i], freq[i]));
    }

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    printCodes(pq.top(), "");
}

int main() {
    vector<char> chars = {'A','B','C','D','E','F'};
    vector<int> freq = {5,9,12,13,16,45};

    huffmanCoding(chars, freq);
}