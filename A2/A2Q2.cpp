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

int main(){
    double at[]={9.00,9.10,9.20,11.00,11.20};
    double dt[]={9.50,12.00,9.40,11.30,11.40};
    int n=5;
    sort(at,at+n);
    sort(dt,dt+n);
    int cnt=0,cur=0,i=0,j=0;
    while(i<n&&j<n){
        
        if(at[i]<=dt[j]){
            cur++;
            i++;
        }
        else{
            cur--;
            j++;
        }
        cnt=max(cnt,cur);
    }
    cout<<"\nMinimum platforms = "<<cnt;
    return 0;
}