#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode* rotateRight(ListNode* head, int k){
	int num = 0;
	if (k == 0 || !head || !head->next)
	{
		return head;
	}
	ListNode* slow = head,* fast = head;
	ListNode* temp;
	while(k--){
		num++;
		fast = fast->next;
		if (!fast)
		{
			fast = head;
			k = k % num;
		}
	}
	if (!fast)
	{
		return head;
	}


	while(fast->next){
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = head;
	head = slow->next;
	slow->next = NULL;

	return head;

}

int main(){
	int k = 2000000;
	ListNode* head = NULL;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//	ListNode* n4 = new ListNode(4);
//	ListNode* n5 = new ListNode(5);

	head = n1;
	n1->next = n2;
	n2->next = NULL;
//    n3->next = n4;
//    n4->next = n5;
//    n5->next = NULL;

    head = rotateRight(head,k);

    if (!head)
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







