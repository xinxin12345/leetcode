#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode* reverseBetween(ListNode* head, int m, int n){
   if (m == n)
   {
   	return head;
   }
   int index = 0;
   ListNode* temp = head;
   ListNode* current = NULL;
   ListNode* end = NULL;
   ListNode* start = NULL;
   ListNode* pre = NULL;
   while(temp && index < n){
   	index++;
   	if (index == m-1)
   	{
   	    pre = temp;	
   	}
   	if (index == m)
   	{
   		end = new ListNode(temp->val);
   		end->next = NULL;
   		start = end;
   	}
   	else if (m < index && index <= n)
   	{
   		current = new ListNode(temp->val);
   		current->next = start;
   		start = current;
   	}
   	temp = temp->next;
   }

   end->next = temp;
   if (pre == NULL)
   {
   	head = start;
   }
   else{
   	   pre->next = start;
   }


   return head;
}

int main(){
	ListNode* head = NULL;
	int m = 1;
	int n = 2;

	ListNode* n1 = new ListNode(3);
	ListNode* n2 = new ListNode(5);
//	ListNode* n3 = new ListNode(3);
//	ListNode* n4 = new ListNode(4);
//	ListNode* n5 = new ListNode(5);

	head = n1;
	n1->next = n2;
	n2->next = NULL;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = NULL;

	head = reverseBetween(head,m,n);

    while(head){
       cout<<head->val<<" ";
       head = head->next;
    }
    cout<<endl;

	return 0;
}


