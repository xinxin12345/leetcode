#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode* removeElements(ListNode* head, int val){
	if (!head)
	{
		return head;
	}
	else if(!head->next && head->val == val){
      return NULL;
	}
	ListNode* temp = head;
	ListNode* pre = NULL;
    while(temp){
    	if (head->val == val)
    	{
    		head = head->next;
    		temp = head;
    	}
        else if(temp->val == val){
            pre->next = temp->next;
            temp = pre->next;
        }
        else{
        	pre = temp;
        	temp = temp->next;
        }
    }
    return head;
}

int main(){
	ListNode* head = NULL;
	int val = 6;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(6);
	ListNode* n4 = new ListNode(3);
	ListNode* n5 = new ListNode(4);
	ListNode* n6 = new ListNode(5);
	ListNode* n7 = new ListNode(6);

	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;

	head = removeElements(head,val);
	while(head){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
	return 0;
}
