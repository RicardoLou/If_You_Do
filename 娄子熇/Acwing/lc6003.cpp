#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d,e,ans=0;
		cin>>a>>b>>c>>d>>e;
		while(b>1&&e>0){
			ans+=6;
			b-=2;
			e-=1;
		}while(a>0&&c>0&&e>0){
			ans+=6;
			c--;
			a--;
			e--;
		}while(a>2&&e>0){
			ans+=6;
			a-=3;
			e-=1;
		}while(a>0&&b>0&&e>0){
			ans+=5;
			a--;
			b--;
			e--;
		}while(c>0&&e>0){
			ans+=4;
			c--;
			e--;
		}while(a>1&&e>0){
			ans+=4;
			a-=2;
			e--;
		}while(b!=0&&e>0){
			ans+=3;
			b--;
			e--;
		}
		while(a != 0 && b != 0 && e > 0) {
		    ans += 5;
		    a --;
		    b --;
		    e --;
		}
		while(a!=0&&e>0){
			ans+=2;
			a--;
			e--;
		}
		while(c>0&&d>0){
			ans+=4;
			c--;
			d--;
		}
		while(a>1&&d>0){
			ans+=4;
			a-=2;
			d--;
		}
		while(b>0&&d>0){
			ans+=3;
			b--;
			d--;
		}
		while(a>0&&d>0){
			ans+=2;
			a--;
			e--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}