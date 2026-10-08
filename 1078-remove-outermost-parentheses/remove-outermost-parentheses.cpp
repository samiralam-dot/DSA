class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans="";
        
        for(auto x:s){
if (x == '(') {
    st.push('(');

    if (st.size() > 1)
        ans += '(';
}
else {
    if (st.size() == 1) {
        st.pop();
        continue;
    }

    if (st.size() > 1) {
        ans += ')';
        st.pop();
    }
}
                                
        }
        return ans;
    }
};