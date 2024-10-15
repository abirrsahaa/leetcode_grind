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
    int findLength(ListNode* head){
        if(!head)return 0;
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // the algo is simple point the pointers at same distance and then go traverse
        int length1=findLength(headA);
        int length2=findLength(headB);
        if(length1>=length2){
            // pehla bada hai

            // pehle ko shi position pe lao 
            int diff=length1-length2;
            int count=0;
            ListNode* pehla=headA;
            while(count<diff){
                pehla=pehla->next;
                count++;
            }

            ListNode* dusra=headB;
            while(pehla&&dusra){
                if(pehla==dusra)return pehla;
                pehla=pehla->next;
                dusra=dusra->next;
            }
            return NULL;



        }else{
            // dusra bada hai 
            int diff=length2-length1;
            int count=0;
            ListNode* pehla=headB;
            while(count<diff){
                pehla=pehla->next;
                count++;
            }

            ListNode* dusra=headA;
            while(pehla&&dusra){
                if(pehla==dusra)return pehla;
                pehla=pehla->next;
                dusra=dusra->next;
            }
            return NULL;



        }
    }
};