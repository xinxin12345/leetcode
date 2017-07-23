#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode *detectCycle(ListNode *head){
	if (head == NULL || head->next == NULL || head->next->next == NULL)
	{
		return NULL;
	}
	int index = 1;
	ListNode* slow = head;
	ListNode* fast = head;
	while(fast){
       if (fast == slow && index == 0)
       {
       	
       	slow = head;
       	while(slow != fast){
       		slow = slow->next;
       		fast = fast->next;
       	}
       	return slow;
       }
       if(fast->next == NULL){
       	return NULL;
       }
       fast = fast->next->next;
       slow = slow->next;
       index = 0;
	}
	return NULL;
}

int main(){
	ListNode* head = NULL;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	ListNode* n7 = new ListNode(7);

	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n5;

	head = detectCycle(head);
	if (head == NULL)
	{
		cout<<"NULL"<<endl;
	}
	else{
		cout<<head->val<<endl;
	}

	return 0;
}



