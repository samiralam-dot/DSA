class Solution {
public:
    int par[26];

    int find(int x) {
        if(par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b)
            return;

        if(a < b)
            par[b] = a;
        else
            par[a] = b;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        for(int i = 0; i < 26; i++)
            par[i] = i;

        for(int i = 0; i < s1.size(); i++) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        string ans = "";

        for(char c : baseStr) {
            ans += char(find(c - 'a') + 'a');
        }

        return ans;
    }
};