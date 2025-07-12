#include<iostream>
#include<algorithm>
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
        
        // Sắp xếp tăng dần
        sort(a, a + n);
        
        int visible = n;
        int i = 0, j = (n + 1) / 2;
        
        while(i < (n + 1) / 2 && j < n){
            if(a[j] >= 2 * a[i]){
                visible--;
                i++;
            }
            j++;
        }
        
        cout << visible << endl;
    }
    return 0;
} 