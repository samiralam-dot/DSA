/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*>v,ans;
        while(head!=NULL){
            v.push_back(head);
            head=head->next;
        }

        int n=v.size();
        int val=0;
        for(int i=n-1;i>=0;i--){
            if(v[i]->val<val){
                v[i]=NULL;
            }else{
                val=max(val,v[i]->val);
            }

        }

        for(auto x:v){
            if(x)ans.push_back(x);
        }
        ListNode* cur=NULL;

        if(ans.size()>0)cur=ans[0];
        ListNode*it=cur;
        ans.erase(ans.begin());
        for(auto x:ans){
            it->next=x;
            it=it->next;
        }
        return cur;



        





        
    }
};