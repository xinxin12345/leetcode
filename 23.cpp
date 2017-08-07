#include <iostream>
#include <vector>
using namespace std;
struct  ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* getmiddle(ListNode* head){
	ListNode* slow = head;
	ListNode* fast = head;
	ListNode* pre = NULL;
	if (!head->next->next)
	{
		slow = head->next;
		head->next = NULL;
		return slow;
	}
	while(fast&&fast->next){
       fast = fast->next->next;
       if(!fast || !fast->next){
       	pre = slow;
       }
       slow = slow->next;
	}
	pre->next = NULL;
	return slow;
}

ListNode* merge(ListNode* head1,ListNode* head2){
   ListNode* head = new ListNode(-1);
   ListNode* tail = head;
   while(head1 && head2){
       if (head1->val < head2->val)
       {
       	tail->next = head1;
       	head1 = head1->next;
       }
       else{
       	tail->next = head2;
       	head2 = head2->next;
       }
       tail = tail->next;
   }
   if (head1)
   {
   	tail->next = head1;
   }
   else{
   	tail->next = head2;
   }
   return head->next;
}

ListNode* sortList(ListNode* head){
  if (!head || !head->next)
  {
  	return head;
  }
  ListNode* head1 = head;
  ListNode* head2 = getmiddle(head);
  head1 = sortList(head1);
  head2 = sortList(head2);
  return merge(head1,head2);
}

ListNode* mergeKLists(vector<ListNode*>& lists){
    int length = lists.size();
    if (length == 0)
    {
    	return NULL;
    }
    ListNode* phead = new ListNode(-1);
    ListNode* ptmp = phead;
    for (int i = 0; i < length; ++i)
    {
    	ptmp->next = &lists[i][0];
    	while(ptmp&&ptmp->next){
    		ptmp = ptmp->next;
    	}
    }
  return sortList(phead->next);
}

int main(){
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(4);
	ListNode* n3 = new ListNode(5);

	ListNode* n4 = new ListNode(2);
	ListNode* n5 = new ListNode(6);
	ListNode* n6 = new ListNode(7);

	ListNode* n7 = new ListNode(3);
	ListNode* n8 = new ListNode(8);
	ListNode* n9 = new ListNode(9);

	head1 = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	head2 = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;

	head3 = n7;
	n7->next = n8;
	n8->next = n9;
	n9->next = NULL;

	vector<ListNode*>& lists;
	lists.push_back(head1);
	lists.push_back(head2);
	lists.push_back(head3);
    
    ListNode* head = mergeKLists(lists);
    while(head){
    	cout<<head->val<<" ";
    	head = head->next;
    }
     cout<<endl;
	return 0;
}

