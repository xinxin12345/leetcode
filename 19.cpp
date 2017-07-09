#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
   int val;
   ListNode* next;
   ListNode(int v):val(v){}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;
    if (head == NULL)
    {
    	return head;
    }
    for (int i = 0; i < n; ++i)
    {
    	fast = fast->next;
    }
    //判断是否是头结点
    if (fast == NULL)
    {
    	head = head->next;
    	return head;
    }
    while(fast->next!=NULL){
    	fast = fast->next;
    	slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
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
	n7->next = NULL;
	int n = 7;

	head = removeNthFromEnd(head,n);
	
	while(head!=NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
	return 0;
}
