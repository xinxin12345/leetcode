#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode* deleteDuplicates(ListNode* head){
	if (!head || !head->next)
	{
		return head;
	}
	ListNode* temp = head;
	ListNode* current = head->next;
	ListNode* pre = NULL;
    while(temp){
    	if (current == NULL)
    	{
    		return head;
    	}
    	else if (temp->val != current->val)
    	{
    		pre = temp;
    		temp = temp->next;
    		current = current->next;
    	}
    	else{
    		while (current && temp->val == current->val)
    		{
    			current = current->next;
    		}
    		if (current == NULL)
    		{
    			if (temp == head)
    			{
    				return NULL;
    			}
    			else{
    				pre->next = NULL;
    			} 			
    		}
    		else{
    			if (temp == head)
    			{
    				head = current;
    				temp = current;
    				current = current->next;
    			}
    			else{
    				pre->next = current;
    				temp = current;
    				current = current->next;
    			}
    		}
    	
    	}

    }
}

int main(){
	ListNode* head = NULL;

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(1);
//    ListNode* n3 = new ListNode(1);
//    ListNode* n4 = new ListNode(2);
//    ListNode* n5 = new ListNode(3);
//    ListNode* n6 = new ListNode(4);
//    ListNode* n7 = new ListNode(5);

    head = n1;
    n1->next = n2;
    n2->next = NULL;
//    n3->next = n4;
//    n4->next = n5;
//    n5->next = NULL;
//    n6->next = n7;
//    n7->next = NULL;

    head = deleteDuplicates(head);

    if (head == NULL)
    {
    	cout<<"NULL"<<endl;
    }
    else{
    	while(head){
    		cout<<head->val<<" ";
    		head = head->next;
    	}
    	cout<<endl;
    }

    
	return 0;
}


