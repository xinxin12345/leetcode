#include <iostream>
using namespace std;
struct  ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode* partition(ListNode* head, int x){
	if (!head || !head->next)
	{
        return head;
	}
    ListNode* slow = head,*fast = head;

    int index = -1;
  
   if (slow->val >= x)
   {
   	fast = slow;
   	while(fast && fast->next){
    	if (fast->next->val < x)
    	{
    		ListNode* n = new ListNode(fast->next->val);

            if(index == -1){
    			n->next = slow;
    			head = n;
    			slow = n;
    			index = 1;
    		}	
    		else{
    			n->next = slow->next;
    			slow->next = n;
    			slow = slow->next;
    		}

             if (fast->next == NULL)
             {
             	fast = NULL;
             }
             else{
             	fast->next = fast->next->next;
             }
    		
    		
    	}
    	else{
    		fast = fast->next;
    	}
    }
   }
   else{

   	while(slow->next->val < x){
   		slow = slow->next;
   		if (slow->next == NULL)
   		{
   			return head;
   		}
   	}
   	
   	fast = slow->next;
    while(fast && fast->next){
    	if (fast->next->val < x)
    	{
    		ListNode* n = new ListNode(fast->next->val);
    		n->next = slow->next;
    		slow->next = n;
    		slow = slow->next;
    		
    		fast->next = fast->next->next;
    	}
    	else{
    		
    		fast = fast->next;
    	}
    }
   }

    
    return head;
}

int main(){
	int x = 3;
	ListNode* head = NULL;

	ListNode* n1 = new ListNode(4);
	ListNode* n2 = new ListNode(4);
	ListNode* n3 = new ListNode(1);
	ListNode* n4 = new ListNode(1);
	ListNode* n5 = new ListNode(0);
	ListNode* n6 = new ListNode(0);
	ListNode* n7 = new ListNode(3);
	ListNode* n8 = new ListNode(2);
	ListNode* n9 = new ListNode(1);
	ListNode* n10 = new ListNode(3);
	ListNode* n11 = new ListNode(1);
	ListNode* n12 = new ListNode(1);
	ListNode* n13 = new ListNode(2);

	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n9;
	n9->next = n10;
	n10->next = n11;
	n11->next = n12;
	n12->next = n13;
	n13->next = NULL;

    head = partition(head,x);

    while(head){
    	cout<<head->val<<" ";
    	head = head->next;
    }
    cout<<endl;

	return 0;
}



