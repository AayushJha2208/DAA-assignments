#include <iostream>
using namespace std;

int can(int *a, int n, int m, int lim){
    int seg = 1;
    int cur = 0;
    for(int i = 0; i < n; i++){
        if( (cur | a[i]) <= lim ){
            cur = cur | a[i];
        }
        else{
            seg++;
            cur = a[i];
        }
    }
    if(seg <= m) return 1;
    else return 0;
}

int func(int *a, int m, int n){
    int ll = a[0];
    int ul = 0;

    for(int i = 0; i < n; i++){
        ul = ul | a[i];
        if(a[i] > ll) ll = a[i];
    }

    while(ll < ul){
        int mid = (ll + ul) / 2;

        if(can(a, n, m, mid))
            ul = mid;
        else
            ll = mid + 1;
    }

    return ll;
}

int main(){
    int a[] = {1,4,2};
    int m = 2;

    cout << func(a, m, 3);
    return 0;
}
