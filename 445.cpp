#include <iostream>
#include <stack>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	stack<int> st1,st2;
	ListNode* head = NULL;
	ListNode* temp = NULL;
	int carry = 0;
	int len1 = 0;
	int len2 = 0;
	while(l1 != NULL){
		st1.push(l1->val);
		l1 = l1->next;
		len1++;
	}
	while(l2 != NULL){
		st2.push(l2->val);
		l2 = l2->next;
		len2++;
	}
	if (len1 < len2)
	{
		while(!st1.empty()){
			temp = new ListNode((st1.top() + st2.top() + carry)%10);
			carry = (st1.top() + st2.top() + carry)/10;
			temp->next = head;
			head = temp;
			st1.pop();
			st2.pop();
		}
		while(!st2.empty()){
			temp = new ListNode((st2.top() + carry)%10);
			carry = (st2.top() + carry)/10;
			temp->next = head;
			head = temp;
			st2.pop();
		}
	}
	else{
		while(!st2.empty()){
			temp = new ListNode((st1.top() + st2.top() + carry)%10);
			carry = (st1.top() + st2.top() + carry)/10;
			temp->next = head;
			head = temp;
			st1.pop();
			st2.pop();
		}
		while(!st1.empty()){
			temp = new ListNode((st1.top() + carry)%10);
			carry = (st1.top() + carry)/10;
			temp->next = head;
			head = temp;
			st1.pop();
		}
	}
	if (carry != 0)
	{
		temp = new ListNode(carry);
		temp->next = head;
		head = temp;
	}
		return head;
}

	int main(){
		ListNode* l1 = NULL;
		ListNode* l2 = NULL;
		ListNode* result = NULL;

		ListNode* n1 = new ListNode(7);
		ListNode* n2 = new ListNode(2);
		ListNode* n3 = new ListNode(4);
		ListNode* n4 = new ListNode(3);

		l1 = n1;
		n1->next = n2;
		n2->next = n3;
		n3->next = n4;
		n4->next = NULL;

		ListNode* n5 = new ListNode(5);
		ListNode* n6 = new ListNode(6);
		ListNode* n7 = new ListNode(4);

		l2 = n5;
		n5->next = n6;
		n6->next = n7;
		n7->next = NULL;

		result = addTwoNumbers(l1,l2);
		if (result == NULL)
		{
			cout<<"NULL"<<endl;
		}
		else{
			while(result){
				cout<<result->val<<" ";
				result = result->next;
			}
			cout<<endl;
		}

		return 0;
	}

