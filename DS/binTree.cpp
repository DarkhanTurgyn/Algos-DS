#include <iostream>
using namespace std;

template<class T>
struct Node{
    T val;
    Node<T> *left, *right;
    Node(T _val): val(_val), left(NULL), right(){};
};

template<class T>
void rec(Node<T> *root){
    if(root == NULL) return;
    cout << root->val << endl;
    rec(root->left);
    rec(root->right);
}

int main(){
    Node<string> *ptr = new Node<string>("456");
    Node<string> *ptr2 = new Node<string>("2");
    Node<string> *ptr3 = new Node<string>("three");
    Node<string> *ptr4 = new Node<string>("four");
    Node<string> *ptr5 = new Node<string>("five");
    ptr->left = ptr2;
    ptr->right = ptr3;
    ptr2->left = ptr4;
    ptr2->right = ptr5;
    rec(ptr);
}