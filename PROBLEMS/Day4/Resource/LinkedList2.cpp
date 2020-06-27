#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d){
		data = d;
		next = NULL;
	}
};

int lengthLL(node* head){
	int count = 0;
	while(head){
		count++;
		head = head->next;
	}
	return count;
}

void InsertAtFront(node* &head,int data){
	if(head == NULL){
		head = new node(data);
	}
	else{
		node* n = new node(data);
		n->next = head;
		head = n;
	}
}

void Print(node* head){

	while(head){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}

node* mid(node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}

	node* slow = head;
	node* fast = head->next;

	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

/*
    sorted two linked list
    The idea to solve problem is simple is simple we
    have given two linked list and we have to merge it.
    h1->  1->2->3->NULL;
    h2->   5->7->9->NULL;

    let's take newHead which will point to the new ead
    every time we call for recursive



*/

node* merge(node* h1,node* h2){
	// Base case
	if(h1 == NULL){
		return h2;
	}
	if(h2 == NULL){
		return h1;
	}

	// Recursive case
	node* newHead;
	//Comparing h1 and h2 for smaller element

	if(h1->data<h2->data){
		newHead = h1;
		newHead->next = merge(h1->next,h2);
	}
	else{
		newHead = h2;
		newHead->next = merge(h1,h2->next);
	}
	return newHead;
}

node* mergeSortLL(node* head){
	// Base case
	if(head == NULL || head->next == NULL){
		return head;
	}

	// Recursive case
	//1. Divide
	node* mid1 = mid(head);

	node* a = head;
	node* b = mid1->next;
	mid1->next = NULL; //To make two linked list so we have to poin the last node
	//mid to NULL

	//2 . Sort
	a = mergeSortLL(a);
	b = mergeSortLL(b);

	//3. Merge a and b
	node* newHead = merge(a,b);
	return newHead;
}

/*
    The idea we use to solve the problem is to traverse the array
    take two pointer at same point and increase
    one by one and other by two

    if both meet at any point then must be in the circular path.
    Let's assume two person are running on the circular track with speed x and 2x
    then both should must meet at point at some particular time.Which proves that they
    are in circular track.Same concept we use to solve the problem.

*/

bool isCyclic(node *head){

	node* slow = head;
	node* fast = head;

	while(fast && fast->next){
		fast = fast->next->next;//move two step
		slow = slow->next;//move 1 steps.
		if(fast == slow){
			return true;
		}
	}
	return false;
}

//CreateCycle means we will create the cycle by joing the first and last point int the array

void CreateCycle(node* head){
	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = head->next->next;
}

//the linked list should be sorted
node*removerDuplicate(node*head){

        node* curr = head;
        //Run while we not the reacht the end of the linked list

        while(curr && curr->next!=NULL){
            if(curr->data == curr->next->data){
                //It store the duplicate element for deletion
                node* pDuplicate = curr->next;
                curr->next= curr->next->next;
                delete pDuplicate;
            }else{
                curr = curr->next;
            }
        }
        return head;
}

/// Intersection of the two linked list

int main(){

	node* head = NULL;

	InsertAtFront(head,2);
	InsertAtFront(head,2);
	InsertAtFront(head,3);

	Print(head);
	node*newhead = removerDuplicate(head);
	Print(newhead);
	/*
	CreateCycle(head);
	// Print(head);
	if(isCyclic(head)){
		cout<<"Cycle Detected"<<endl;
	}
	else{
		cout<<"No Cycle"<<endl;
	}
    */
	return 0;
}
