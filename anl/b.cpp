#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode {

    char data;
    unsigned freq;

    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq) {
        this->data = data;
        this->freq = freq;
    }

};

struct comp {

    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }

};

void print(MinHeapNode* node, string s) {

    if(node == NULL) return;

    if(node->data != '$') {
        cout<<node->data<<" "<<s<<endl;
    }

    print(node->left, s + "0");
    print(node->right, s + "1");
}

void Code(char data[], int freq[], int siz) {

    struct MinHeapNode *l, *r, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, comp> minHeap;

    for(int i=0;i<siz;i++) {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    while(minHeap.size() != 1) {

        l = minHeap.top();
        minHeap.pop();

        r = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', l->freq + r->freq);

        top->left = l;
        top->right = r;

        minHeap.push(top);

    }

    print(minHeap.top(),"");

}

int main() {

    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    Code(arr, freq, size);

}

// Time complexity: O(nlogn) where n is the number of unique characters. If there are n nodes, extractMin() is called 2*(n – 1) times. extractMin() takes O(logn) time as it calls minHeapify(). So, overall complexity is O(nlogn).
// If the input array is sorted, there exists a linear time algorithm. We will soon be discussing in our next post.

// Applications of Huffman Coding:
// They are used for transmitting fax and text.
// They are used by conventional compression formats like PKZIP, GZIP, etc.
// Multimedia codecs like JPEG, PNG, and MP3 use Huffman encoding(to be more precise the prefix codes).

// There are mainly two major parts in Huffman Coding

// Build a Huffman Tree from input characters.
// Traverse the Huffman Tree and assign codes to characters.

