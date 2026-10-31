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
    ListNode* reverseList(ListNode* &temp1,ListNode*&temp2) {
        // ListNode * temp = head;
        ListNode* stop  = temp2->next;//REVERSING KE TIME CHANGE HOJAYEGA isliye STORE

        ListNode * prev = stop;//AAGE WALA STORE KARKE RAKH...KAAM AAYEGA 

        while(temp1 && temp1!=stop){//TEMP1 exist karna Chahiye
            ListNode*currn = temp1->next;
            temp1->next = prev;//prev lelenge...
            prev = temp1;//ye prev banjayega kisi aur ka...

            temp1 = currn;
        }
        //head = prev;
        return prev;//wahi head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp1 = head;
        ListNode*temp2 = head;
        int curr = 0;
        ListNode* ans = new ListNode(0);
        ans->next = head; // FIX: incomplete group bhi connected rahega if n<K
        ListNode* chut = ans;

        while(temp2){
            curr++;
            if(curr == k){
                curr = 0;
                ListNode* groupStart = temp1;//REVERSE KARNE SE PEHLE KA HEAD .. BAAD KA TAIL...

                ListNode* nextGroup = temp2->next; // Aage Ka store  Karlia reverse se Pehle

                ListNode* newHead = reverseList(temp1, temp2);
                ans->next = newHead;
                ans = groupStart;
                //temp1 --> temp2 BANGAYA HAI...
                temp2 = nextGroup;//BADALDIA BKL

                // continue;//TAAKI temp2  ke NICHE ki Value se FARK  NA PADE
            }
            else{
                temp2 = temp2 -> next;
            }
        }
        
        return chut->next;//KYUKI ANSWER TO BADHTA JAA RAHA HAI
    }
};