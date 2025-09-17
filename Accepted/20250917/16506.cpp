// BOJ - 16506 CPU

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> m;
string b8[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
string b16[16] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };

void tc() {
    string s; int rd, ra, x, c;
	cin >> s >> rd >> ra >> x;
	if(s[s.size() - 1] == 'C') c = 1, s.pop_back();
	else c = 0;

	cout << m[s] << c << '0' << b8[rd] << b8[ra];
    cout << (c ? b16[x] : b8[x]);
    if(!c) cout << "0"; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	m.insert({"ADD", "0000"}); m.insert({"SUB", "0001"}); m.insert({"MOV", "0010"});
	m.insert({"AND", "0011"}); m.insert({"OR", "0100"}); m.insert({"NOT", "0101"});
	m.insert({"MULT", "0110"}); m.insert({"LSFTL", "0111"}); m.insert({"LSFTR", "1000"});
	m.insert({"ASFTR", "1001"}); m.insert({"RL", "1010"}); m.insert({"RR", "1011"});

	int t; cin >> t;
	while (t--) tc();
}