#include "bits/stdc++.h"

using namespace std;

int main() {
    	int arr[10] = { 5,8,2,4,6,9,7,0,1,3 };
	int m1=arr[0];
	int m2 = arr[0];
	for (int i = 0; i < 10; ++i) {
		m1 = max(m1, arr[i]);
		m2 = min(m2, arr[i]);
	}
	cout << "最大值为: " << m1 
		 << "\n最小值为: " << m2 << endl;
}