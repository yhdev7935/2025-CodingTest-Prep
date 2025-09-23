// BOJ - 9946 단어 퍼즐

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int x = 1; 
    while(1) {
        string a, b; cin >> a >> b;
        if(a == "END") break;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if(a == b) cout << "Case " << x << ": same\n";
        else cout << "Case " << x << ": different\n";
        x++;
    }
    return 0;
}