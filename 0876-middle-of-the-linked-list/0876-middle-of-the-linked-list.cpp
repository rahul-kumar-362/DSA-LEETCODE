/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {//Take 2 ptr JABTAK FAST = END... SLOW = MIDDLE
        if(head-> next == NULL)return head;
        ListNode*fast = head;
        ListNode*slow = head;
        while(fast &&  fast->next){//FOR EVEN AND ODD...
        //EK bhi condition false to loop khatam
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};