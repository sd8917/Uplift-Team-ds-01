class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> m;
        ListNode* pA = headA;
        while (pA) {
            m[pA]++;
            pA = pA->next;
        }
        ListNode* pB = headB;
        while (pB) {
            if (mA.find(pB) != mA.end())
                return pB;
            pB= pB->next;
        }
        return nullptr;
    }
};
