#include <iostream>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, H, W;
        cin >> N >> H >> W;
        int l = max(H,W);
        int h = max(H,W)*N;
        int ans = h;
        while(l <= h) {
            int mid =(l+h)/2;
            int ch = mid / H;
            int cw = mid / W;
            if(ch * cw >= N){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
