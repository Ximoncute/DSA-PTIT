#include<iostream>
using namespace std;

long long merge(long long arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    long long L[n1], R[n2];
    
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    long long inv_count = 0;
    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inv_count += (n1 - i);
        }
    }
    
    while(i < n1)
        arr[k++] = L[i++];
    
    while(j < n2)
        arr[k++] = R[j++];
    
    return inv_count;
}

long long mergeSort(long long arr[], int left, int right) {
    long long inv_count = 0;
    if(left < right) {
        int mid = left + (right - left) / 2;
        
        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        long long a[1000005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        cout << mergeSort(a, 0, n - 1) << endl;
    }
    return 0;
} 