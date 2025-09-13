// BOJ - 9506 약수들의 합

#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100001

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    
    while(1) {
        int t; cin >> t;
        if(t == -1) break;

        vector<int> v;
        for(int i = 1; i * i < t; i++)
            if(t % i == 0) {
                v.push_back(i);
                if(i != t / i) v.push_back(t / i);
            }

        sort(v.begin(), v.end());

        int sum = 0; for(int k : v) sum += k;
        if(t != sum - t) cout << t << " is NOT perfect.\n";
        else {
            cout << t << " = " << v[0];
            for(int i = 1; i < v.size() - 1; i++)
                cout << " + " << v[i];
            cout << '\n';
        }
    }

    return 0;
}