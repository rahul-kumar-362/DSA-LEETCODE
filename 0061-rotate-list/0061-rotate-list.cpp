class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        int n = 1;
        while (fast->next) {
            fast = fast->next;
            n++;
        }

        k %= n;
        if (k == 0) return head;

        fast = head;

        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return newHead;
    }
};