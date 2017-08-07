#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

int getlength(ListNode* head){
	int count = 0;
	while(head){
		count++;
		head = head->next;
	}
	return count;
}

//odd 
ListNode* getmiddle1(ListNode* head){
	ListNode* slow = head;
	ListNode* fast = head;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
    return slow;
}

//even
ListNode* getmiddle2(ListNode* head){
   ListNode* slow = head;
   ListNode* fast = head->next;
   while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
   }
   return slow;
}

ListNode* getmidpre(ListNode* head){
	ListNode* midpre = NULL;
	int length = getlength(head);
	ListNode* slow = head;
	ListNode* fast = head;
	if (length%2 == 0)
	{
	   while(fast->next->next){
	   	fast = fast->next->next;
	   	if (!fast->next->next)
	   	{
	   		midpre = slow;
	   		return midpre;
	   	}
	   	slow = slow->next;
	   }
	}
	else{
		while(fast->next){
			fast = fast->next->next;
			if (!fast->next)
			{
				midpre = slow;
				return midpre;
			}
			slow = slow->next;
		}
	}
}

ListNode* reverseList(ListNode* head){
	ListNode* result = NULL;
	ListNode* temp = NULL;
	if (!head || !head->next)
	{
		return head;
	}
	while(head != NULL){
		if (result == NULL)
		{
			result = new ListNode(head->val);
			result->next = NULL;
		}
		else{
			temp = result;
			result = new ListNode(head->val);
			result->next = temp;
		}
		head = head->next;
	}
	return result;
}

void reorderList(ListNode* head){
    if (!head || !head->next || !head->next->next)
    {
    	return ;
    }
    ListNode* middle = NULL;
    ListNode* midpre = NULL;
    ListNode* midhost = NULL;
    ListNode* temp = NULL;
    //even
    if (getlength(head) %2 == 0)
    {
    	middle = getmiddle2(head);
    	midpre = getmidpre(head);
        midhost = reverseList(middle->next->next);
        midpre->next = midhost;
        temp = midhost;
        while(temp->next){
        	temp = temp->next;
        }
        temp->next = middle;
        middle->next->next = NULL;
    }
    //odd
    else{
       middle = getmiddle1(head);
       midpre = getmidpre(head);
       midhost = reverseList(middle->next);
       midpre->next = midhost;
       temp = midhost;
       while(temp->next){
       	temp = temp->next;
       }
       temp->next = middle;
       middle->next = NULL;
    }
    ListNode* slow = head;
    ListNode* fast = midhost;
    ListNode* tempnode = NULL;
    while(fast != middle){
       tempnode = new ListNode(fast->val);
       fast = fast->next;
       if (fast == middle)
       {
       	tempnode->next = slow->next;
       	slow->next = tempnode;
       	slow = slow->next;
       }
       else{
       	tempnode->next = slow->next;
       	slow->next = tempnode;
       	slow = slow->next->next;
       }

   }
    slow->next = middle;
}

int main(){
	ListNode* head = NULL;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);

	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	reorderList(head);
	while(head){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
	return 0;
}

