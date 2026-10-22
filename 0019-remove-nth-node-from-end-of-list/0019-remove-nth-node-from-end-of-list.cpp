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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL)return NULL;//BASICALLY...

        ListNode*temp = head;
        int size = 0;
        while(temp){
            temp = temp ->next;
            size++;
        }
        
        if(size == n){//MATLAB PEHLA ELEMENT...
            ListNode* abhi = head;
            head = head->next;
            delete abhi;
            return head;
        }
        //size-n;//iske aage wale ko nikalna hai
        ListNode*temp2 = head;
        int total = 1;
        while(temp2 && total!=(size-n)){
            total++;
            temp2 = temp2->next;
        }

        //ISKE AAGE WALE KO DELETE KARNA HAI ISLIYE...

        temp2->next = temp2->next->next;
       // delete temp2->next;
        return head;
    }
};