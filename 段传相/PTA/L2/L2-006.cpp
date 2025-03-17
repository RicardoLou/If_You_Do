#include<bits/stdc++.h>
using namespace std;

int a[31] = {}, b[31] = {};
map<int, int> mp;

void bl(int root, int s, int e, int index) {
    if (s > e) {
        return;
    }
    int i = s;
    while (i < e && b[i] != a[root]) {
        i++;
    }
    mp[index] = a[root];
    bl(root - 1 - e + i, s, i - 1, 2 * index + 1);
    bl(root - 1, i + 1, e, 2 * index + 2);
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    bl(n - 1, 0, n - 1, 0);
    auto it = mp.begin();
    cout << it->second;
    while (++it != mp.end()) {
        cout << ' ' << it->second;
    }

}



// class JD{
// public:
//     int data=-1;
//     int l=-1;
//     int r=-1;

//     JD(int data,int l,int r){
//         this->data=data;
//         this->l=l;
//         this->r=r;
//     }

//     JD(){}
// };


// void shu(unique_ptr<JD[]>& s,int* h,int* z,int l,int r,int n,int jds){
//     if(l>r||jds<0) return;
//     s[n].data=h[jds--];
//     s[n].l=2*n+1;
//     s[n].r=2*n+2;
//     int mid;
//     for(mid=l;mid<=r;mid++){
//         if(z[mid]==s[n].data){
//             break;
//         }
//     }
//     if(mid<=r){
//         shu(s,h,z,mid+1,r,2*n+2,jds);
//         shu(s,h,z,l,mid,2*n+1,jds);
//     }

//     return;

// }

// void BFS(unique_ptr<JD[]>& s){
//     int index=0;
//     queue<int> q;
//     q.push(0);
//     while(!q.empty()){
//         JD jd=s[q.front()];
//         q.pop();
//         if(index==0){
//             index++;
//             cout<<jd.data;
//         }else{
//             cout<<" "<<jd.data;
//         }
//         if(jd.l!=-1){
//             q.push(jd.l);
//         }
//         if(jd.r!=-1){
//             q.push(jd.r);
//         }

//     }
// }

// int main(){

//     int n;
//     cin>>n;
//     int h[n],z[n];
//     unique_ptr<JD[]> s(new JD[n+1]);
//     for(int& x:h){
//         cin>>x;
//     }
//     for(int& x:z){
//         cin>>x;
//     }

//     int jds=n-1;
//     //int root=h[jds];
//     shu(s,h,z,0,n,0,jds);
//     BFS(s);

// }