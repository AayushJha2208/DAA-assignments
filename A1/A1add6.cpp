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

double dist(pair<int,int> p1, pair<int,int> p2){
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return sqrt(dx*dx + dy*dy);
}

double crossdis(vector<pair<int,int>>& arr, int l, int h, int m, double d) {
    vector<pair<int,int>> strip;
    for(int i=l;i<=h;i++){
        if(abs(arr[i].first - arr[m].first) < d)
            strip.push_back(arr[i]);
    }
    sort(strip.begin(), strip.end(),
        [](auto &a, auto &b){ return a.second < b.second; });
    double mndis = d;
    for(int i=0;i<strip.size();i++){
        for(int j=i+1;j<strip.size() && 
            (strip[j].second - strip[i].second) < mndis; j++){
            mndis = min(mndis, dist(strip[i], strip[j]));
        }
    }
    return mndis;
}

double midis(vector<pair<int,int>>& arr,int l,int h){
    if(h - l == 1){
        return dist(arr[l],arr[h]);
    }
    int m = (l+h)/2;
    double d = min(midis(arr,l,m),midis(arr,m+1,h));
    return min(d, crossdis(arr,l,h,m,d));
}

int main(){
    vector<pair<int,int>> arr = {
        {9,3},{2,6},{15,3},{5,1},{1,2},{12,4},{7,2},{4,7},
        {16,5},{3,3},{10,5},{6,4},{14,6},{8,6},{11,1},{13,2}
    };
    sort(arr.begin(), arr.end());
    double ans = midis(arr,0,arr.size()-1);
    cout<<"Minimum distance between a pair is : "<<ans<<endl;
    return 0;
}
