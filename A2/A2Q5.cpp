#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <climits>
using namespace std;

struct node{
    int f;
    node *l,*r;
};

node* newnode(int x){
    node* t=new node();
    t->f=x;
    t->l=t->r=NULL;
    return t;
}

void heapify(node* h[],int n,int i){
    int sm=i,l=2*i+1,r=2*i+2;
    if(l<n && h[l]->f<h[sm]->f)sm=l;
    if(r<n && h[r]->f<h[sm]->f)sm=r;
    if(sm!=i)
    {
        swap(h[i],h[sm]);
        heapify(h,n,sm);
    }
}

node* pop(node* h[],int &n){
    node* t=h[0];
    h[0]=h[n-1];
    n--;
    heapify(h,n,0);
    return t;
}

void push(node* h[],int &n,node* x){
    int i=n++;
    h[i]=x;
    while(i>0)
    {
        int p=(i-1)/2;
        if(h[p]->f<=h[i]->f)break;
        swap(h[p],h[i]);
        i=p;
    }
}

void preorder(node* r,string s){
    if(!r)return;
    if(!r->l && !r->r){
        cout<<s<<" ";
        return;
    }
    preorder(r->l,s+"0");
    preorder(r->r,s+"1");
}

int main(){
    char c[]={'a','b','c','d','e','f'};
    int f[]={5,9,12,13,16,45};
    int n=6;

    node* h[100];

    for(int i=0;i<n;i++){
        h[i]=newnode(f[i]);
    }

    for(int i=n/2-1;i>=0;i--){
        heapify(h,n,i);
    }

    while(n>1){
        node* a=pop(h,n);
        node* b=pop(h,n);

        node* t=newnode(a->f+b->f);
        t->l=a;
        t->r=b;

        push(h,n,t);
    }

    preorder(h[0],"");
    return 0;
}
