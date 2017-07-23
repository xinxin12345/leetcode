#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode* oddEvenList(ListNode* head) {
	
	if(head == NULL||head->next==NULL||head->next->next==NULL)
	{
		return head;
	}
	ListNode* slow = head;
	ListNode* fast = head->next->next;
	ListNode* temp = head->next;
	ListNode* pre = NULL;
	while(fast){
		pre = slow->next;
		slow->next = fast;
		temp->next = fast->next;
		if(!fast->next){
			slow = slow->next;
			slow->next = pre;
			return head;
		}
		fast = fast->next->next;
		slow = slow->next;
		slow->next = pre;
		temp = temp->next;

	}
	return head;
}

int main(){
	ListNode* head = NULL;

//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//	ListNode* n4 = new ListNode(4);
//	ListNode* n5 = new ListNode(5);
//
//	head = n1;
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = NULL;

	head = oddEvenList(head);
	if(!head){
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



