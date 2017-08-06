#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x),next(NULL){}
};

int getlistsize(ListNode* head){
	int count = 0;
	while(head){
		count++;
		head = head->next;
	}
	return count;
}

ListNode* addHead(ListNode* head,ListNode* Node){
	Node->next = head;
	return Node;
}

ListNode* reverseKGroup(ListNode* head, int k){
	 int index = 0; 
     int length = getlistsize(head);
     ListNode* result = NULL;
     if (length < k || k == 1)
    {
    	return head;
    }
    else{
    	ListNode* ptmphead = new ListNode(-1);
    	while(length >= k){
    		ListNode* phead = NULL;
    		for (int i = 0; i <k ; ++i)
    		{
    			ListNode* temp = head;
    			head = head->next;
    			phead = addHead(phead,temp);
    		}
    		if (index == 0)
    		{
    			result = phead;
    			index = 1;
    		}

    		ptmphead->next = phead;
    		while(phead->next){
    			phead = phead->next;
    		}
    		ptmphead = phead;
    		length = length - k;
    	}
    	ptmphead->next = head;
    	return result;
    }

}

int main(){
	ListNode* head = NULL;
	int k = 4;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	

	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

    head = reverseKGroup(head, k);

    while(head){
    	cout<<head->val<<"   ";
    	head = head->next;
    }
    cout<<endl;
    
	return 0;
}
