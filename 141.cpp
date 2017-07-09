#include <iostream>
using namespace std;

#define INT_MAX 0x7fffffff

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v){}
};

bool hasCycle(ListNode *head){
if (head == NULL)
{
	return head;
}
while(head->next != NULL){
   if (head->val != INT_MAX)
   {
   	 head->val = INT_MAX;
   	 head = head->next;
   }
   else{
   	return true;
   }
}
return false;
}

int main(){
	ListNode* head = NULL;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);

	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;

	bool result = hasCycle(head);
	cout<<result<<endl;

	return 0;
}
