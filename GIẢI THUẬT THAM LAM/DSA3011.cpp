#include<iostream>
#include<queue>
using namespace std;

int main(){
    long long BASE = 1000000007;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            pq.push(x);
        }
        long long res = 0;
        while(pq.size() > 1){
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            long long cost = (a + b) % BASE;
            res = (res + cost) % BASE;
            pq.push(cost);
        }
        cout << res << endl;
    }
    return 0;
} 