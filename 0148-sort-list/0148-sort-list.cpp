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
    ListNode* merge(ListNode* root1,ListNode* root2){
        if(!root1&&root2)return root2;
        if(root1&&!root2)return root1;
        
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* temp1=root1;
        ListNode* temp2=root2;
        
        while(temp1&&temp2){
            if(temp1->val<temp2->val){
                dummy->next=temp1;
                temp1=temp1->next;
                dummy=dummy->next;
                // dummy->next=NULL;
            }
            else{
                dummy->next=temp2;
                temp2=temp2->next;
                dummy=dummy->next;
                // dummy->next=NULL;
                
            }
        }
        
        
        while(temp1){
            
            dummy->next=temp1;
            temp1=temp1->next;
            dummy=dummy->next;
            // dummy->next=NULL;
        }
        
        while(temp2){
            
            dummy->next=temp2;
            temp2=temp2->next;
            dummy=dummy->next;
            // dummy->next=NULL;
            
        }
        
        return temp->next;
        
    }
    ListNode* findMiddle(ListNode* head){
        if(head==NULL)return head;
        ListNode* temp1=head;
        ListNode* temp2=head;
        while(temp1->next&&temp2->next){
            temp2=temp2->next;
            if(temp2->next){
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return temp1;
    }
    ListNode* sortList(ListNode* head) {

        if(head==NULL||head->next==NULL)return head;

        // sort a ll is more like sort a array
        // which comes down to the fact that what is the 
        // most optimized sorting known till now ?
        // merge sort 

        // what we do in merge sort 
        // we divide the 2 half (make sure you dry run to understand)
        // until it becomes one 
        // and then we will be performing the simple merge operation that we have done
        // that is merging two sorted list or array

        // find the middle recursively 
        ListNode* middle=findMiddle(head);
        ListNode* temp=middle->next;
        middle->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(temp);
        ListNode* ans=merge(left,right);

        return ans;
        
    }
};