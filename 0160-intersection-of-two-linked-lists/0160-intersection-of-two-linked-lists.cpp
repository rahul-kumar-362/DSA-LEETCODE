
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

//         Complexity
// - Time: O(n + m)
// - Auxiliary Space: O(1)
        if(headA == NULL || headB == NULL) return NULL;

        ListNode* skipA = headA;
        ListNode* skipB = headB;

        while(skipA != skipB) {
            if(skipA == NULL) {
                skipA = headB;
            }
            else {
                skipA = skipA->next;
            }

            if(skipB == NULL) {
                skipB = headA;
            }
            else {
                skipB = skipB->next;
            }
        }

        return skipA;
    }
};
