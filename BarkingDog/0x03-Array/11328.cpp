// BOJ - 11328 Strfry

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string a, b; cin >> a >> b;
        int ch[27] = {0, }, no = 0;
        for(int i = 0; i < a.size(); i++) ch[a[i] - 'a']++;
        for(int i = 0; i < b.size(); i++) {
            if(ch[b[i] - 'a'] <= 0) no = 1;
            ch[b[i] - 'a']--;
        }
        if(a.size() != b.size() || no) cout << "Impossible\n";
        else cout << "Possible\n";
    }
}