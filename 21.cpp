#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v):val(v){}
};

ListNode* Merge(ListNode* L1,ListNode* L2){
	if(L1==NULL)
	return L2;
	else if(L2==NULL)
	return L1;
	
	ListNode* merge=NULL;
	if(L1->val<L2->val){
		merge=L1;
		merge->next=Merge(L1->next,L2);
	}
	else{
		merge=L2;
		merge->next=Merge(L1,L2->next);
	}
	return merge;
}

int main(){
	ListNode* L1=NULL;
	ListNode* L2=NULL;
	
	ListNode* n1=new ListNode(1);
	ListNode* n3=new ListNode(3);
	ListNode* n5=new ListNode(5);
	ListNode* n7=new ListNode(7);
	L1=n1;
	n1->next=n3;
	n3->next=n5;
	n5->next=n7;
	n7->next=NULL;
	
	while(L1->next!=NULL){
    	 cout<<L1->val<<" ";
    	 L1=L1->next;
    }
    cout<<L1->val<<endl;
    
    L1=n1;
	
	ListNode* n2=new ListNode(2);
	ListNode* n4=new ListNode(4);
	ListNode* n6=new ListNode(6);
	ListNode* n8=new ListNode(8);
	L2=n2;
	n2->next=n4;
	n4->next=n6;
	n6->next=n8;
	n8->next=NULL;
	
	while(L2->next!=NULL){
        cout<<L2->val<<" ";
    	 L2=L2->next;
    }
    
    cout<<L2->val<<endl;
    L2=n2;
	
	ListNode* result;
    result=Merge(L1,L2);
    
    while(result->next!=NULL){
    	 cout<<result->val<<" ";
    	 result=result->next;
    }
    cout<<result->val<<endl;
   
	return 0;
}
