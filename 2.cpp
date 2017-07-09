#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
	ListNode* result = NULL;
	ListNode* head = NULL;
	ListNode* temp = NULL;
	int add = 0;
	int carry = 0;
	while(l1 != NULL && l2 != NULL){
		add = (l1->val + l2->val+carry)%10;
		if (result == NULL)
		{
			result = new ListNode(add);
			head = result;
			result->next = NULL;
		}
		else{
			temp = new ListNode(add);
			temp->next = NULL;
			result->next = temp;
			result = result->next;
		}

		carry = (l1->val + l2->val+carry)/10;
		l1 = l1->next;
		l2 = l2->next;
	}

	if (l1 == NULL && l2 != NULL)
	{
		while(l2 != NULL){
			add = (l2->val+carry)%10;
			temp = new ListNode(add);
            carry = (l2->val+carry)/10;
			temp->next = NULL;
			result->next = temp;
			result = result->next;
			l2 = l2->next;
		}
		if (carry != 0)
		{
			temp = new ListNode(carry);
			temp->next = NULL;
			result->next = temp;
		}
	}
	else if (l2 == NULL && l1 != NULL)
	{
		while(l1 != NULL){
			add = (l1->val+carry)%10;
			temp = new ListNode(add);
			carry = (l1->val+carry)/10;
			temp->next = NULL;
			result->next = temp;
			result = result->next;
			l1 = l1->next;
		}
		if (carry != 0)
		{
			temp = new ListNode(carry);
			temp->next = NULL;
			result->next = temp;
		}
	}
	else{
		if (carry != 0)
		{
			temp = new ListNode(carry);
			temp->next = NULL;
			result->next = temp;
		}

	}

	return head;
}
int main(){
	ListNode* l1 = NULL;
	ListNode* l2 = NULL;
	ListNode* result = NULL;

	ListNode* n1 = new ListNode(3);
	ListNode* n2 = new ListNode(7);

	l1 = n1;
	n1->next = n2;
	n2->next = NULL;

	ListNode* n4 = new ListNode(9);
	ListNode* n5 = new ListNode(2);

	l2 = n4;
	n4->next = n5;
	n5->next = NULL;

	result = addTwoNumbers(l1,l2);
	while(result != NULL){
		cout<<result->val<<" ";
		result = result->next;
	}
	cout<<endl;
	return 0;
}



