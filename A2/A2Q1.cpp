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

void merge(int s[],int f[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int Ls[n1],Lf[n1],Rs[n2],Rf[n2];
    for(int i=0;i<n1;i++){
        Ls[i]=s[l+i];
        Lf[i]=f[l+i];
    }
    for(int j=0;j<n2;j++){
        Rs[j]=s[m+1+j];
        Rf[j]=f[m+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(Lf[i]<=Rf[j]){
            s[k]=Ls[i];
            f[k]=Lf[i];
            i++;
        }
        else{
            s[k]=Rs[j];
            f[k]=Rf[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        s[k]=Ls[i];
        f[k]=Lf[i];
        i++;
        k++;
    }
    while(j<n2){
        s[k]=Rs[j];
        f[k]=Rf[j];
        j++;
        k++;
    }
}

void mergesort(int s[],int f[],int l,int r){
    if(l>=r)return;
    int m=(l+r)/2;
    mergesort(s,f,l,m);
    mergesort(s,f,m+1,r);
    merge(s,f,l,m,r);
}

int main(){
    int s[]={1,3,0,5,8,5};
    int f[]={2,4,6,7,9,9};
    int n=6;

    mergesort(s,f,0,n-1);

    int cnt=0,last=-1;
    cout<<"activities: ";
    for(int i=0;i<n;i++){
        if(s[i]>=last){
            cnt++;
            last=f[i];
            cout<<"("<<s[i]<<","<<f[i]<<") ";
        }
    }
    cout<<"\nMax. activities = "<<cnt;
    return 0;
}