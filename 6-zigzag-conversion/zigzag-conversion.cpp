
class Solution {
public:
    string convert(string s, int n) {
        if(n == 1) return s;

        vector<string> ans(n, "");
        int i=0, j=0;
        bool flg=true;

        while(i<s.size()) {
            ans[j] += s[i];

            if(flg) {
                j++;
            }
            else {
                j--;
            }

            if(j == n-1) {
                flg = false;
            }
            else if(j == 0) {
                flg = true;
            }

            i++;
        }

        string fans="";
        for(auto x:ans) fans+=x;

        return fans;
    }
};
