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
        if(Lv[i]/Lw[i] >= Rv[j]/Rw[j]){
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
    int n=3; double W=50;
    double val[]={100,60,120};
    double wt[]={20,10,40};

    mergesrt(val,wt,0,n-1);

    double ans=0;
    for(int i=0;i<n;i++){
        if(W==0)break;
        if(wt[i]<=W)
        {
            ans+=val[i];
            W-=wt[i];
        }
        else
        {
            ans+=(val[i]/wt[i])*W;
            W=0;
        }
    }

    cout<<"Max value = "<<ans;
    return 0;
}
