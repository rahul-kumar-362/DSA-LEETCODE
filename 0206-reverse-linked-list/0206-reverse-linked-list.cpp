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
    //BRUTE FORCE IS  USING STACK AND REVERSE
    ListNode* reverseList(ListNode* head) {
        ListNode * temp = head;
        ListNode * prev = NULL;

        while(temp){
            ListNode*currn = temp->next;
            temp->next = prev;//prev lelenge...
            prev = temp;//ye prev banjayega kisi aur ka...

            temp = currn;
        }
        head = prev;
        return head;//wahi head;
    }
};