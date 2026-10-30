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

    // void reverse(ListNode*&head){
    //     ListNode* temp = head;
    //     ListNode*prev = NULL;
    //     ListNode*curr = NULL;//AAGE ka store karega
    //     while(temp){
    //         curr = (temp->next)?temp->next:NULL;

    //         temp->next = prev;//piche JOIN...
    //         prev = temp;//temp ki Value prev mai aur Aage badho...
    //         temp = curr;//AAGE WaLa temp
    //     }
    //     head  =  prev;//shit
    // }

    ListNode* rotateRight(ListNode* head, int k) {

        if(k == 0) return head;
        if(!head || !head->next)return head;

        ListNode*temp = head;
        int n = 1;
        while(temp->next){
            n++;
            temp = temp->next;
        }

        
        k = k % n;//TAAKI rotations manage ho sake

        int d  = n - (k + 1);
        int curr = 0;
        
        ListNode*temp2 = head;

        while(temp2 && curr != d){
            curr++;
            temp2 = temp2 -> next;
        }

        temp->next = head;//LOOP banadiya
        head = temp2->next ;//update Head

        temp2->next = NULL;//FIR AGAIN LOOP BREAK

        return head;
    }
};