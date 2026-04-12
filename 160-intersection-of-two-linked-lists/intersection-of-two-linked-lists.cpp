
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        ListNode* ans = NULL;
        while(h1){
            h1->val = h1->val*(-1);
            h1 = h1->next;
        }
        while(h2){
            if(h2->val<0){
                ans = h2;
                break;
            }
            h2 = h2->next;
        }
        h1 = headA;
        while(h1){
            h1->val = h1->val*(-1);
            h1 = h1->next;
        }
        
        return ans;
    }
};