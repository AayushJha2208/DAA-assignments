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

int main() {
    int arr[] = {3, -2, 5, -1, 6, -3, 2};
    int s = 7;

    int maxsum = INT_MIN;

    for(int i = 0; i < s; i++){
        int currsum = 0;
        for(int j = i; j < s; j++){
            currsum += arr[j];
            if(currsum > maxsum)
                maxsum = currsum;
        }
    }

    cout << maxsum;
    return 0;
}
