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
int crossum(int *arr,int l,int h,int m){
    int sum=0;
    int lsum=INT_MIN,rsum=INT_MIN;
    int i;
    for(i=m;i>=l;i--){
        sum+=arr[i];
        if(sum>lsum)lsum=sum;
    }
    sum=0;
    for(i=m+1;i<=h;i++){
        sum+=arr[i];
        if(sum>rsum)rsum=sum;
    }
    return max(rsum,0)+max(lsum,0);
}
int subsum(int *arr,int l,int h){
    if(l>h) return 0;
    if(l==h) return arr[l];
    int m=(l+h)/2;
    int lt=subsum(arr,l,m-1);
    int rt=subsum(arr,m+1,h);
    int cr=crossum(arr,l,h,m);
    if (lt>rt && lt>cr)return lt;
    else if(rt>lt && rt>cr) return rt;
    else return cr;
}
int main(){
    int arr[]={2, 3, 4, 5, 7};
    cout<<"Maximum subarray sum : "<<subsum(arr,0,4);
    return 0;
}