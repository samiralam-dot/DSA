class Solution {
public:
    bool check(string s){
        stack<char> st;

        for(auto x:s){
            if(x=='(')
                st.push(x);
            else{
                if(st.empty())
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }

    vector<string> ans;

    void solve(int i,string s,int n){

        if(i==2*n){   
            if(check(s))
                ans.push_back(s);

            return;
        }

        solve(i+1,s+'(',n);
        solve(i+1,s+')',n);
    }

    vector<string> generateParenthesis(int n) {

        solve(0,"",n);

        return ans;
    }
};