#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

TreeNode* sortedListToBST(ListNode* head){
	if (head == NULL)
	{
		return NULL;
	}
	ListNode* slow = head;
	ListNode* fast = head;
	ListNode* pre = NULL;
	while(fast->next && fast->next->next){
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	TreeNode* Tree = new TreeNode(slow->val);
	if (pre != NULL)
	{
		pre->next = NULL;
		Tree->left = sortedListToBST(head);
	}
	else{
		Tree->left = NULL;
	}
	Tree->right = sortedListToBST(slow->next);
	return Tree;
}

