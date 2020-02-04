#include <iostream>
using namespace std;

template<class T>
struct Node{
    T val;
    Node<T> *next;
    Node(T _val): val(_val), next(NULL){};
};

template<class T>
class stack{
    private:
        Node<T> *topNode;
        int sz = 0;
    public:
        void push(T val){
            Node<T> *temp = new Node<T>(val);
            if(topNode) temp->next = topNode;
            topNode = temp;
            sz++;
        }
        bool pop(){
            if(sz == 0) return false;
            topNode = topNode->next;
            sz--;
            return true;
        }
        T top(){
            return topNode->val;
        }
        int size(){
            return sz;
        }
};

int main(){
    stack<int> my_stack;
    cout << my_stack.size() << endl;
    my_stack.push(45);
    cout << my_stack.top() << ' ' << my_stack.size() << endl;
    my_stack.push(100);
    cout << my_stack.top() << ' ' << my_stack.size() << endl;
    my_stack.pop();
    cout << my_stack.top() << ' ' << my_stack.size() << endl;
    my_stack.pop();
    cout << my_stack.top() << ' ' << my_stack.size() << endl;
    my_stack.pop();
    cout << my_stack.top() << ' ' << my_stack.size() << endl;

}