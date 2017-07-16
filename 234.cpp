#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

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

bool isPalindrome(ListNode* head){
	if (!head || !head->next)
	{
		return true;
	}
	ListNode* slow = head,*fast = head;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast)
	{
		slow->next = reverseList(slow->next);
		slow = slow->next;
	}
	else{
        slow = reverseList(slow);
	}
	while(slow){
		if (head->val != slow->val)
		{
			return false;
		}
		else{
			head = head->next;
			slow = slow->next;
		}
	}
	return true;
}

int main(){
	ListNode* head = NULL;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(2);
	ListNode* n5 = new ListNode(1);

	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	cout<<isPalindrome(head)<<endl;
	return 0;
}

