#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> e(n);
	for (int& x : e) {
		cin >> x;
	}

	//分别找G和H第一个和最后一个元素
	int g_h = -1, g_e, h_h = -1, h_e;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'G') {
			g_e = i;
			if (g_h == -1) {
				g_h = i;
			}
		}
		if (s[i] == 'H') {
			h_e = i;
			if (h_h == -1) {
				h_h = i;
			}
		}
	}
	//cout<<g_h<<' '<<g_e<<' '<<h_h<<' '<<h_e;

	set<pair<int, int>> st;

	//两名领导者都覆盖其品种的所有奶牛（都满足条件1)
	if (e[g_h] - 1 >= g_e && e[h_h] - 1 >= h_e) st.insert({ g_h,h_h });
	// for(auto x:st){
	//     cout<<"1:"<<x.first<<' '<<x.second<<endl;
	// }

	//H的领导者满足条件1，G的领导者满足条件2
	for (int i = 0; i < h_h; i++) {
		if (s[i] == 'G' && e[i] - 1 >= h_h) {
			st.insert({ i,h_h });
		}
	}
	// for(auto x:st){
	//     cout<<"2:"<<x.first<<' '<<x.second<<endl;
	// }

	//H的领导者满足条件2，G的领导者满足条件1
	for (int i = 0; i < g_h; i++) {
		if (s[i] == 'H' && e[i] - 1 >= g_h) {
			st.insert({ g_h,i });
		}
	}
	// for(auto x:st){
	//     cout<<"3:"<<x.first<<' '<<x.second<<endl;
	// }
	cout << st.size();

}