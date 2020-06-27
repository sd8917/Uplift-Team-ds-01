class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* curr = head;
        //Run while we not the reacht the end of the linked list

        while(curr && curr->next!=NULL){
            if(curr->val == curr->next->val){
                //It store the duplicate element for deletion
                ListNode* pDuplicate = curr->next;
                curr->next= curr->next->next;
                delete pDuplicate;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};
