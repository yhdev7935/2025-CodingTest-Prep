// BOJ - 16462 나교수 교수님의 악필

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        string ss; cin >> ss;
        for(int j = 0; j < ss.size(); j++)
            if(ss[j] == '0' || ss[j] == '6') ss[j] = '9';
        int t = stoi(ss);
        sum += (t > 100 ? 100 : t);
    }
    cout << ((sum + n / 2) / n) << '\n';
}