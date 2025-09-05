#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;   
    while(t--){
        int n;
        cin >> n;
        
        int a[1005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }        
        int min = a[0];
        int max = a[0];
        
        for(int i = 0; i < n; i++){
            if(a[i] < min) min = a[i];
            if(a[i] > max) max = a[i];
        }
        
        int dem = 0;
        for(int so = min; so <= max; so++){
            for(int i = 0; i < n; i++){
                if(a[i] == so){
                    dem++;
                    break;
                }
            }
        }
        
        cout << (max - min + 1) - dem << "\n";
    }
    
    return 0;
} 