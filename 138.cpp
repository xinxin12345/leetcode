#include <iostream>
using namespace std;
struct RandomListNode
{
	int label;
	RandomListNode *next,*random;
	RandomListNode(int x):label(x),next(NULL),random(NULL){}
};

 RandomListNode *copyRandomList(RandomListNode *head){
     if (!head)
     {
     	return NULL;
     }
     unordered_map<RandomListNode*,RandomListNode*> mp;
     RandomListNode* new_head = new RandomListNode(head->label);
     RandomListNode* node1 = head,* node2 = new_head;
     while(node1->next){
         mp[node1] = node2;
         node1 = node1->next;
         node2->next = new RandomListNode(node1->label);
         node2 = node2->next;
     }
     mp[node1] = node2;

     node1 = head;
     node2 = new_head;
     while(node1->next){
     	node2->random = mp[node1->random];
     	node1 = node1->next;
     	node2 = node2->next;
     }
     node2->random = mp[node1->random];
     return new_head;
 }

int main(){
	return 0;
}