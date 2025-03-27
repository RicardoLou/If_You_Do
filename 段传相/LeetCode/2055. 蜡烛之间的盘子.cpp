class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int sLen = s.length(), l=-1, r-1, qLen = queries.size();
        vector<int> left(sLen, -1), right(sLen, -1);
        vector<int> sums(sLen, 0), aa(qLen, 0);
        int sum = 0;
        for (int i = 0; i < sLen; i++) {
            if (s[i] == '*') {
                sum++;
            }
            else {
                l = i;
                sums[i] = sum;
            }
            left[i] = l;
        }
        for (int i = sLen - 1; i >= 0; i--) {
            if (s[i] == '|') {
                r = i;
            }
            right[i] = r;
        }
        for (long long i = 0; i < qLen; i++) {
            if (left[queries[i][1]] != -1 && right[queries[i][0]] != -1 && left[queries[i][1]] >= right[queries[i][0]]) {
                aa[i] = sums[left[queries[i][1]]] - sums[right[queries[i][0]]];
            }
        }

        //超时
        // for(long long i=0;i<qLen;i++){
        //     l=s.find("|",queries[i][0]);
        //     r=s.rfind("|",queries[i][1]);
        //     if(l>r||l==-1||l==r-1){
        //         sums.push_back(0);
        //     }else{
        //         int sum=0;
        //         // auto a=s.begin(),b=s.begin();
        //         // advance(a,l);//移动迭代器
        //         // advance(b,r);
        //         // sum=count(a,b,'*');
        //         // sums.push_back(sum);
        //         while(l<r){
        //             if(s[++l]=='*'){
        //                 sum++;
        //             }
        //         }
        //         sums.push_back(sum);
        //     }
        // }
        return aa;
    }
};