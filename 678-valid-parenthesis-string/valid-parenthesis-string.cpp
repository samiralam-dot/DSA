class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;

        for(char c : s) {
            if(c == '(') {
                mn++;
                mx++;
            }
            else if(c == ')') {
                mn--;
                mx--;
            }
            else {
                mn--;   // '*' as ')'
                mx++;   // '*' as '('
            }

            if(mx < 0)
                return false;

            if(mn < 0)
                mn = 0;
        }

        return mn == 0;
    }
};