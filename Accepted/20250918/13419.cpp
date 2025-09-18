// BOJ - 13419 탕수육

#include <iostream>
#include <string>

using namespace std;

void tc() {
    string ss; cin >> ss; int n = ss.size();
    string t1 = "", t2 = "";
    if(ss.size() == 1) {
        cout << ss << '\n' << ss << '\n';
        return;
    }
    t1 += ss[0]; t2 += ss[1];
    for(int i = 2 % n; i != 0; i = (i + 2) % n) t1 += ss[i];
    for(int i = 3 % n; i != 1; i = (i + 2) % n) t2 += ss[i];
    cout << t1 << '\n' << t2 << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) tc();
}