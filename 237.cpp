#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v){}
};

void deleteNode(ListNode* node) {
	if (!node || !node->next)
	{
		return;
	}
	node->val = node->next->val;
	node->next = node->next->next;
}

int main(){
	ListNode* l1 = NULL;

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);

    l1 = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    ListNode* node = n3;

    deleteNode(node);

    while(l1!=NULL){
    	cout<<l1->val<<" ";
    	l1 = l1->next;
    }
    cout<<endl;

	return 0;
}
