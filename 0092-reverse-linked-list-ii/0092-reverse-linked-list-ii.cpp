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

    ListNode* reverse(ListNode* head){
        if(!head||!head->next)return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* agla=curr->next;
            curr->next=prev;
            prev=curr;
            curr=agla;  
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head||!head->next)return head;

        if(left==right)return head;

        // so there can be 2 cases
        // when head is 1 
        // and when head is in the middle 
        if(left==1){
            // head ko store karo 
            // end wale node tak jao 
            // uska next store karo 
            // reverse karo 
            // head ko next jo store kiya tha uske sath link kar do 

            ListNode* temp=head;
            ListNode* age=temp;
            int count=1;

            while(count<right){
                age=age->next;
                count++;
            }

            ListNode* link=age->next;
            age->next=NULL;
            ListNode* reverse_head=reverse(temp);
            temp->next=link;

            return reverse_head;

        }
        else{
            // pehle start position mai jao same step bss ak extra link karna hoga 
            // reverse_head ke sath and return apna wala head hoga 

            ListNode* pehla=head;
            ListNode* agla=head->next;
            int count=2;

            while(count<left){
                pehla=pehla->next;
                agla=agla->next;
                count++;
            }
            // now pehla ko bacha ke rakh aur right nikal pehle mereko usko null banana hai
            

            // right wala kam kar rha 
            ListNode* temp=head;
            ListNode* age=temp;
            count=1;

            while(count<right){
                age=age->next;
                count++;
            }

            ListNode* link=age->next;
            age->next=NULL;
            ListNode* reverse_head=reverse(agla);
            agla->next=link;
            pehla->next=reverse_head;


            return head;
            

        }

        
    }
};