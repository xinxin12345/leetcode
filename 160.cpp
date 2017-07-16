#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v){}
};

ListNode* reverseList(ListNode* head){
    ListNode* result = NULL;
    ListNode* temp = NULL;
    if (!head || !head->next)
    {
        return head;
    }
    while(head != NULL){
        if (result == NULL)
        {
            result = new ListNode(head->val);
            result->next = NULL;
        }
        else{
            temp = result;
            result = new ListNode(head->val);
            result->next = temp;
        }
        head = head->next;
    }
    return result;
}


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)  {
	if (!headA || !headB)
	{
		return NULL;
	}
    ListNode* result = NULL;

    headA = reverseList(headA);
    headB = reverseList(headB);

    while(headA && headB){
       if (headA->val == headB->val)
       {
       	result = new ListNode(headA->val);
       	headA = headA->next;
       	headB = headB->next;
       	
       	if (!headA || !headB)
       	{
       		return result;
       	}
       }
       else{
          return result;
       }
    }
}

int main(){
	ListNode* headA = NULL;
	ListNode* headB = NULL;
	ListNode* result = NULL;

	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//	ListNode* n4 = new ListNode(4);
//	ListNode* n5 = new ListNode(5);

//	ListNode* n6 = new ListNode(6);
//	ListNode* n7 = new ListNode(7);
//	ListNode* n8 = new ListNode(8);

	headA = n1;
	n1->next = NULL;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = NULL;

	headB = n1;
//	n6->next = n7;
//	n7->next = n8;
//    n8->next = n3;

    result = getIntersectionNode(headA,headB);

    if (result == NULL)
     {
     	cout<<'NULL'<<endl;
     } 
     else{
     	cout<<result->val<<endl;
     }


	return 0;
}


