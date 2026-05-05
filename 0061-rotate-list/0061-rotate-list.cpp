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
    ListNode* rotateRight(ListNode* head, int k) {


        if(head == NULL || head->next == NULL || k == 0)
            return head;


        ListNode* temp1=head;
        int count=1;
        while(temp1->next!=NULL){
            temp1=temp1->next;
            count++;
        }

        ListNode*temp2=temp1;//tail se start karna hai
         k=k%count;


         
        temp1->next=head;
        for(int i=0;i<count-k;i++){

            temp2=temp2->next;
        }

        ListNode* ans = temp2->next;
        temp2->next=NULL;


        
        return ans;
    }
};