#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode* swapPairs(ListNode* head){
	if (!head || !head->next)
	{
		return head;
	}
   ListNode* temp = head;
   int tmp;
   while(temp && temp->next){
       tmp = temp->val;
       temp->val = temp->next->val;
       temp->next->val = tmp;
       temp = temp->next->next;
   }
   return head;
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
	n4->next = NULL;

	head = swapPairs(head);

	while(head){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;

	return 0;
}
