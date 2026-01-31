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
int crossum(int *arr, int l, int h, int m) {
    int sum = 0;
    int lsum = INT_MIN, rsum = INT_MIN;

    for (int i = m; i >= l; i--) {
        sum += arr[i];
        lsum = max(lsum, sum);
    }

    sum = 0;
    for (int i = m + 1; i <= h; i++) {
        sum += arr[i];
        rsum = max(rsum, sum);
    }

    return lsum + rsum;
}
int subsum(int *arr,int l,int h){
    if(l==h) return arr[l];
    int m=(l+h)/2;
    int lt=subsum(arr,l,m);
    int rt=subsum(arr,m+1,h);
    int cr=crossum(arr,l,h,m);
    // if (lt>rt && lt>cr)return lt;
    // else if(rt>lt && rt>cr) return rt;
    // else return cr;
    return max(max(lt,rt),cr);
}
int main(){
    int arr[] = {-2, -1};
    cout<<"Maximum subarray sum : "<<subsum(arr,0,1);
    return 0;
}
