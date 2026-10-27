class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<string>ans;
        for(int i=0;i<m-1;i++){
            string s=".";
            for(int j=1;j<n;j++){
                s+="#";
            }
            cout<<s<<endl;
            ans.push_back(s);

        }
        string s="";
        s.resize(n,'.');
        ans.push_back(s);
        return ans;


        
    }
};