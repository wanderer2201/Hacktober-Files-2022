class Solution {
public ListNode swapNodes(ListNode head, int k) {

   //use two pointers and intailize with list head 
   ListNode fast=head;
   ListNode slow=head;
    
    //iterate k times to reach the first node
    for(int i=0;i<k-1;i++)
        fast=fast.next;
    //store this node in pointer and call it first
    ListNode first=fast;
    
    //continue the loop using the same fast pointer but on the same time move slow
    //and once the fast reach the end of the list on the same time slow 
    //will be on second node
    while(fast.next!=null)
    {
        slow=slow.next;
        fast=fast.next;
    }
    //store this node in pointer and call it second 
    ListNode second=slow;
    
    //swap values of first and second
    int temp=second.val;
    second.val=first.val;
    first.val=temp;
    
    return head;
}
}
