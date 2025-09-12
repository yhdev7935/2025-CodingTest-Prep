// BOJ - 6566 애너그램 그룹

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
    map<string, vector<string> > m;
    map<string, int> c;
    while(1) {
        string ss; cin >> ss; if(cin.eof()) break;
        string ss2 = ss; sort(ss2.begin(), ss2.end());
        m[ss2].push_back(ss);
        c[ss2] += 1;
    }

    vector<pair<string, int> > v(c.begin(), c.end());
    for(int i = 0; i < v.size(); i++)
        sort(m[v[i].first].begin(), m[v[i].first].end());
    
    sort(v.begin(), v.end(), [&](const pair<string,int>& a, const pair<string,int>& b){
        if(a.second == b.second) return m[a.first][0] < m[b.first][0];
        return a.second > b.second;
    });

    for(int i = 0; i < min((int) v.size(), 5); i++) {
        auto& p = v[i];
        cout << "Group of size " << p.second << ": ";
        string pv = "";
        for(string sss : m[p.first]) {
            if(pv == sss) continue;
            cout << sss << ' ';
            pv = sss;
        }
        cout << ".\n";
    }
}