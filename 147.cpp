#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode* insertionSortList(ListNode* head){
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* index = head->next;
	ListNode* temp = NULL;
	ListNode* pre = NULL;
	ListNode* indexpre = head;
	int inx = 0;
	while(index){
		temp = head;
		pre = NULL;
		inx = 0;
		while(temp != index){
			if (temp == head && index->val < temp->val)
			{
				ListNode* Node = new ListNode(index->val);
				Node->next = head;
				head = Node;
				indexpre->next = index->next;
				index = index->next;
				inx = 1;
				break;
			}
			else if(index->val < temp->val){
				pre->next = index;
				index = index->next;
				pre->next->next = temp;
				indexpre->next = index;
				inx = 1;
				break;
			}
			else{
				inx = 0;
				pre = temp;
				temp = temp->next;
			}             
		}
		if (inx == 0)
		{
			indexpre = index;
			index = index->next;
		}
	}
	return head;
}

int main(){
	ListNode* head = NULL;

	ListNode* n1 = new ListNode(3);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(4);
	ListNode* n4 = new ListNode(7);
	ListNode* n5 = new ListNode(1);

	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	head = insertionSortList(head);
	if (head == NULL)
	{
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
