class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode* >s;
        ListNode*temp = head;
        while(temp){
            s.push(temp);
            temp = temp->next;
        }

        ListNode*node = head;
        while(node){
            if( node->val != s.top()->val ){
                return false;
            }
            s.pop();
            node = node->next;
        }
        return true;
    }
};
