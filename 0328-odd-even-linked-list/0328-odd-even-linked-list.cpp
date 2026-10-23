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
    ListNode* oddEvenList(ListNode* head) {//BRUTE FORCE IS STORING IN ARRAY
        ListNode*even = new ListNode(0);
        ListNode*evenhead = even;//starting mai store
        ListNode*odd = new ListNode(0);
        ListNode*oddhead = odd;

        ListNode * temp = head;
        int size = 1;
        while(temp!=NULL){
            if(size%2==1){//ODD
                odd->next = temp;
                odd = temp;//AAGE
            }
            else{
                even->next = temp;
                even = temp;//AAGE
            }
            size++;
            temp = temp->next;
        }
        even->next = NULL;//LAST MAI KUCH RAKHO MAT WARNA LOOP

        odd->next = evenhead->next;//0's KO SKIP
        return oddhead->next;
    }
};