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
    ListNode *detectCycle(ListNode *head) {//FLOYD CYCLE KA LAFDA ALGORITHM...
        if(head ==NULL || head->next == NULL)return NULL;
        ListNode*fast = head;
        ListNode*slow = head;

        if(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        while(fast && fast->next){
            if(fast == slow){
                //yaha par baat par gaur kare MATHS se nikalenge 1st appearance...
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return NULL;
    }
};