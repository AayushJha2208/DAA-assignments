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
void quicksrt(int* arr, int l,int h){
    stack<int> stk;
    stk.push(l);
    stk.push(h);
    int l1,h1,pi,i,j;
    while(!stk.empty()){
        h1=stk.top();stk.pop();
        l1=stk.top();stk.pop();
        if(l1>=h1) continue;
        pi=arr[l1];
        i=l1;
        j=l1+1;
        while(j<=h1){
            if(arr[j]<pi){
                swap(arr[j],arr[i+1]);
                j++;i++;
            }
            else j++; 
        }
        swap(arr[i],arr[l1]);
        pi=i;
        stk.push(l1);stk.push(pi-1);
        stk.push(pi+1);stk.push(h1);
    }
}
int main() {
    int arr[]={3,9,5,2,1,0,11,8};
    quicksrt(arr,0,7);
    for (int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}