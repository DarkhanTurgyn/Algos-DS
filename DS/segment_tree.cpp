#include <iostream>;
using namespace std;

int n;
int t[];           //! update tree size -> 4*n

void built(int a[], int v, int tl, int tr){
    if(tl == tr) t[v] = tl;
    else{
        int tm = (tl + tr) / 2;
        built(a, v*2, tl, tm);
        built(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1]; 
    }
}

int sum(int v, int tl, int tr, int l, int r){
    if(l>r) return 0;
    if(tl==l && tr==r) return t[v];
    int tm = (tl + tr) / 2;
    sum(v*2, tl, tm, l, min(r, tm));
    sum(v*2+1, tm+1, tr, max(l, tm+1), r);

}

void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr) t[v] = new_val;
    else{
        int tm = (tl + tr) / 2;
        if(pos<=tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}


int main(){
    cin>>n;
    int tree[4*n];
}