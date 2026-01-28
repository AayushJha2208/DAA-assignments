#include <iostream>
using namespace std;
int partition(int *a,int l,int r){
    int p=a[r];
    int i=l-1;
    for (int j=l; j<r;j++)
    {
        if (a[j]<p)
        {
            i++;
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    int t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;
    return i+1;
}

void quickSort(int *a,int l,int r)
{
    if (l<r)
    {
        int pi =partition(a,l,r);
        quickSort(a,l,pi -1);
        quickSort(a,pi+1,r);
    }
}

int func(int *arr,int n,int k){
	quickSort(arr,0,n-1);
	int s=0;
	for(int i=0;i<n-k;i++){
		s+=arr[i];
	}
	return s;	
}
int main() {
    int n, k;
    cin >> n;          
	cin >> k;              
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];  
    }

    

    int result = func(arr, n, k);
    cout << result << endl;

    return 0;
}
