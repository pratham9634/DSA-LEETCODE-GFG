class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        // Mark nodes in list A by negating their values
        while(tempA){
            tempA->val = tempA->val * (-1);
            tempA = tempA->next;
        }
        
        ListNode* ans = nullptr;
        
        // Check nodes in list B for intersection
        tempB = headB;
        while(tempB){
            if(tempB->val < 0){
                ans = tempB;
                break;
            }
            tempB = tempB->next;
        }
        
        // Restore list A values
        tempA = headA;
        while(tempA){
            tempA->val = abs(tempA->val);
            tempA = tempA->next;
        }
        
        return ans;
    }
};
