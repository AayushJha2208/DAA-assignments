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

void merge(double v[],double w[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    double Lv[n1],Lw[n1],Rv[n2],Rw[n2];

    for(int i=0;i<n1;i++){
        Lv[i]=v[l+i];
        Lw[i]=w[l+i];
    }
    for(int j=0;j<n2;j++){
        Rv[j]=v[m+1+j];
        Rw[j]=w[m+1+j];
    }

    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
    if(Lw[i] <= Rw[j]){
        v[k]=Lv[i];
        w[k]=Lw[i];
        i++;
    }
    else{
        v[k]=Rv[j];
        w[k]=Rw[j];
        j++;
    }
    k++;
}


    while(i<n1){
        v[k]=Lv[i];
        w[k]=Lw[i];
        i++;k++;
    }
    while(j<n2){
        v[k]=Rv[j];
        w[k]=Rw[j];
        j++;k++;
    }
}

void mergesrt(double v[],double w[],int l,int r){
    if(l>=r)return;
    int m=(l+r)/2;
    mergesrt(v,w,l,m);
    mergesrt(v,w,m+1,r);
    merge(v,w,l,m,r);
}

int main(){
    int n=5,ans=0,t=0;
    double mx=0;
    double d[]={100,19,27,25,15};
    double p[]={2,1,2,1,3};
    mergesrt(p,d,0,n-1);
    // for(int i=0;i<n;i++) cout<<d[i]<<"  ";
    // for(int i=0;i<n;i++) cout<<p[i]<<"  ";
    for(int i=n-1;i>=0;i--){
        if(p[i]>t){
            ans+=d[i];
            t++;
        }
    }
    cout<<"Max value = "<<ans;
    return 0;
}
