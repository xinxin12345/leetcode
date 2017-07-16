#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v){}
};

ListNode* reverseList(ListNode* head){
	if (!head || !head->next)
	{
		return head;
	}
	ListNode* res = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return res;
}

int main(){
	ListNode* head = NULL;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);

	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next =NULL;

    head = reverseList(head);
    while(head!=NULL){
    	cout<<head->val<<" ";
    	head = head->next;
    }
    cout<<endl;

	return 0;
}

