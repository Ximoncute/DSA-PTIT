#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        int a[100005];
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        for(int i = 0; i < n-1; i++){
            if(a[i] != 0 && a[i] == a[i+1]){
                a[i] = a[i] * 2;
                a[i+1] = 0;
            }
        }
        int ketqua[100005];
        int pos = 0;
        
        for(int i = 0; i < n; i++){
            if(a[i] != 0){
                ketqua[pos] = a[i];
                pos++;
            }
        }        
        while(pos < n){
            ketqua[pos] = 0;
            pos++;
        }       
        for(int i = 0; i < n; i++){
            cout << ketqua[i];
            if(i < n-1) cout << "  ";
        }
        cout << endl;
    }
    
    return 0;
} 