#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v){}
};

ListNode* deleteDuplicates(ListNode* head){
	if (head == NULL)
	{
		return head;
	}

	ListNode* temp;
	ListNode* current = head;
	while(current->next!=NULL){
       if(current->next->val == current->val){
          temp = current->next;
          current->next = temp->next;
       }
       else{
       	 current = current->next;
       }    
	}
	return head;
}

int main(){
	ListNode* head = NULL;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(1);
	ListNode* n3 = new ListNode(2);
	ListNode* n4 = new ListNode(3);
	ListNode* n5 = new ListNode(3);
	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	head = deleteDuplicates(head);

    while(head->next != NULL){
    	cout<<head->val<<" ";
    	head = head->next;
    }
    cout<<head->val<<endl;
	return 0;
}
