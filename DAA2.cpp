#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq){
        this->data = data;
        this->freq = freq;
        this->left = NULL;
        this->right = NULL;
    }
};

class Compare{
    public:
    bool operator()(Node *node1, Node *node2){
        return node1->freq >= node2->freq;
    }
};

Node* buildHuffman(map<char, int> freq){

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for(auto it: freq){
        Node *newN = new Node(it.first, it.second);
        pq.push(newN);
    }

    while(!pq.empty()){

        // First minimum to the left
        Node *left = pq.top();
        pq.pop();

        // Second minimum to the right
        Node *right = pq.top();
        pq.pop();

        Node *temp = new Node('#', left->freq + right->freq);
        temp->left = left;
        temp->right = right;

        pq.push(temp);

    }

    return pq.top();

}

void traverseHuffman(Node *root, string code, map<char, string> &charCodes){

    if(!root){
        return;
    }

    if(!root->left && !root->right){
        charCodes[root->data] = code;
        return;
    }

    traverseHuffman(root->left, code+"0", charCodes);
    traverseHuffman(root->right, code+"1", charCodes);

}

string getEncoded(string input, map<char, string> charCodes){
    string output = "";
    for(auto ch: input){
        output += charCodes[ch];
    }
    return output;
}

int main(){

    string input;
    cin >> input;

    cout << "\nInput String : " << input << endl;
    int n = input.size();

    map<char, int> charFreq;
    for (int i = 0; i < n; i++){
        charFreq[input[i]]++;
    }

    Node *root = buildHuffman(charFreq);

    map<char, string> charCode;
    traverseHuffman(root, "", charCode);

    cout<<"\nHuffman Codes for each character : "<<endl;
    for (auto it : charCode){
        cout<<it.first<<" -> "<<it.second<<endl;
    }

    string output = getEncoded(input, charCode);

    cout<<"\nOutput String : "<<output<<endl;
    cout<<endl;

    return 0;
}