//to check if a linkedlist is a palindrome or not

class Solution {
public:
    bool isPalindrome(ListNode* head) { 
        ListNode* slow= head;
        
        stack <int> s;
        while(slow != NULL){
                s.push(slow->val);
                slow = slow->next;
        }
 
        while(head != NULL ){
             int i=s.top();
             s.pop();
  
            if(head -> val != i){
                return false;
            }
  
            
           head=head->next;
        }
        return true;
    }
};