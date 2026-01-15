#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a,int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    vector<int> L(n1),R(n2);
    for(int i=0;i<n1;i++)
	L[i]=a[l+i];
    for(int j=0;j<n2;j++)
	R[j]=a[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j])
		a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1)
	a[k++]=L[i++];
    while(j<n2)
	a[k++]=R[j++];
}

void mergeSort(vector<int>& a,int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    int n=6;
    vector<int> a={12,11,13,5,6,7};
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
