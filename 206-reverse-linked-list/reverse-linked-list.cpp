class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // base case
        if (!head || !head->next) return head;

        // reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // fix the current node’s link
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
