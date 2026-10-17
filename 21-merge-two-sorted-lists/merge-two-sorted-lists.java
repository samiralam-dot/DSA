/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head=new ListNode(-1);
        ListNode temp=head;
        while(l1!=null||l2!=null){
            int val=1000;
            if(l1!=null&&l2!=null){
                if(l1.val<l2.val){
                    val=l1.val;
                    l1=l1.next;
                }
                else{
                    val=l2.val;
                    l2=l2.next;
                }
            }
            else{
                if(l1!=null){
                    val=l1.val;
                    l1=l1.next;
                }
                else {
                    val=l2.val;
                    l2=l2.next;
                }


            }
            ListNode x=new ListNode(val);
            temp.next=x;
            temp=temp.next;
           


        }
        return head.next;
        
    }
}