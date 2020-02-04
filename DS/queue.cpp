#include <iostream>
using namespace std;

template<class T>
struct Node{
    T val;
    Node<T> *next;
    Node(T _val): val(_val), next(NULL){};
};

template<class T>
class queue{
    private:
        Node<T> *head, *tail;
        int sz = 0;
    public:
        void push(T val){
            Node<T> *temp = new Node<T>(val);
            if(sz == 0) head = temp;
            else tail->next = temp;
            tail = temp;
            sz++;
        }
        bool pop(){
            if(sz == 0) return false;
            head = head->next;
            if(head == NULL) tail = NULL;
            sz--;
            return true;
        }
        T front(){
            return head->val;
        }
        int size(){
            return sz;
        }
};

int main(){
    queue<int> q;
    cout << q.size() << endl;
    q.push(45);
    cout << q.front() << ' ' << q.size() << endl;
    q.push(100);
    cout << q.front() << ' ' << q.size() << endl;
    q.pop();
    cout << q.front() << ' ' << q.size() << endl;
    q.pop();
    cout << q.front() << ' ' << q.size() << endl;
    q.pop();
    cout << q.front() << ' ' << q.size() << endl;
}