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
void mergesrt(int* arr){
    int s=8;
    int temp[s];
    for(int c=2;c<=s*2;c*=2){
        int k=0,f=0;
        while(f<s){
            int a=min((f+(c/2)),s);
            int b=min(f+c,s);
            int i=f,j=a;
            while(i<a&&j<b){
                if(arr[i]<=arr[j])temp[k++]=arr[i++];
                else temp[k++]=arr[j++];
            }
            while(i<a)temp[k++]=arr[i++];
            while(j<b)temp[k++]=arr[j++];
            f+=c;
        }
        for(int a=0;a<s;a++) arr[a]=temp[a];
        
    }
}
int main() {
    int arr[]={3,9,5,2,1,0,11,8};
    mergesrt(arr);
    for (int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}