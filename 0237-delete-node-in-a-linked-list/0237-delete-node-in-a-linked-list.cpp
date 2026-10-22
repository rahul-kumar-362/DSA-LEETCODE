/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //OK WO NODE DELETE KARNA HAI KYA JISKI VALUE WO HO

        node->val = node->next->val;//value lelo aage ki aur usko delete krdo...
        ListNode * temp = node->next;
        // temp->next = node;
        node->next = node->next->next;//bichwala delete
        delete temp;
    }
};