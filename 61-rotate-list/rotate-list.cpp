class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int n = 1;
        ListNode* temp = head;
        while(temp->next){
            n++;
            temp = temp->next;
        }
        temp->next = head;
        k = k%n;
        int x =  n-k-1;
        ListNode* temp2 = head;
        while(x>0){
            temp2 = temp2->next;
            x--;
        }
        head = temp2->next;
        temp2->next = NULL;
        return head;
    }
};