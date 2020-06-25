// LinkedList
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

///Find the length of the linked list
int lengthLL(node* head){
    ///initilize a counter to count the number of the node
	int count = 0;
	///loop till we do not get the null
	/*
        1->2->3->5->NULL
	*/
	while(head){
		count++;/// increasement each time we encounter a node.
		head = head->next;
	}
	return count;
}

/*
    Inserting Node at front simple point to conside
    1. if head->null;
        Simply make new node here and attach
    2. a.else create a node and attach it to head
       b.   head should be shifted to new node n.
*/
void InsertAtFront(node* &head,node* &tail,int data){
	if(head == NULL){
		head = tail = new node(data);
	}
	else{
		node* n = new node(data);
		n->next = head;
		head = n;
	}
}

/*
    inserting node at end simply we go the tail pointer and make a node
    new node(data) and attach to the tail of node make the new node as tail.
*/

void InsertAtEnd(node* &head,node* &tail,int data){
	if(head == NULL){
		head = tail = new node(data);
	}
	else{
		node*n = new node(data);
		tail->next = n;
		tail = n;
	}
}

/*
    insert at position i.So,we will three things
    1.if pos == 0 means we have to inset the node at front only.
    2.if the post >= lenghtll- 1; means we at last post so we should insertatend
    3.
        let take an example to understand it better
        1->2->3->4->NULL;
        we have insert after 3.
        A. we will iterate over the node till using the pos given by user
        node*temp = head;
        int cnt = 1;
        while(cnt<=pos-1){
            temp = temp->next;
            cnt++;
        }

        B.now we will create the node
        1->2->3->4->NULL
                 |
                 temp
        node*n = new node(7);
            | 7 |
             n

        logic we will break the pointer of 3 and attach to 4 and then n->next = temp->next;
*/
void InsertAtMid(node* &head,node* &tail,int pos,int data){
	if(pos == 0){
		InsertAtFront(head,tail,data);
	}
	else if(pos>=lengthLL(head)-1){
		InsertAtEnd(head,tail,data);
	}
	else{
		node* temp = head;
		int count = 1;
		while(count<=pos-1){
			temp = temp->next;
			count++;
		}

		node* n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
}

/*
    if head->nULL; THEN WE RETURN
    else if head->100 means there is a node we check for the what the head->next contains if NULL then
        delete head and head and teil both are same point to NULL

    else
        1->2->3->NULL;
        |
        head

        temp = head;
        head ko store kr lo by using head = head->next;
        delete temp.

*/
void DeleteAtFront(node*&head,node*&tail){
    if(head==NULL){
        return;
    }else if(head->next == NULL){
        delete head;
        head =tail= NULL;
    }
    else{
        node*temp = head;
        head= head->next;
        delete temp;
    }
}

/*
    same a above two point
    1.head== NULL
    2.head->next ==NULL;
    3.point is to think???


*/
void deletionAtEnd(node*&head,node*&tail){

    if(head== NULL){
        return;
    }else if(head->next==NULL){
        node*temp = head;
        head=head->next;
        delete temp;
    }
    else{
        node*temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        temp->next = NULL;
    }
}


void DeleteAtMid(node* &head,node* &tail,int pos){
	if(pos == 0){
		DeleteAtFront(head,tail);
	}
	else if(pos>=lengthLL(head)-1){
		deletionAtEnd(head,tail);
	}
	else{
		node* temp = head;
		int count = 1;
		while(count<=pos-1){
			temp = temp->next;
			count++;
		}
		node* n = temp->next;
		temp->next = n->next;
		delete n;
	}
}

//*  Print function to print the node    *//
void Print(node* head){

	while(head){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}

node* SearchLL(node* head,int key){

	while(head){
		if(head->data == key){
			return head;
		}
		head =head->next;
	}
	return NULL;
}


void ReverseLL(node* &head,node* &tail){
	node* p = NULL;
	node* c = head;
	while(c){
		node* n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	tail = head;
	head = p;
}



int main(){
    node* head = NULL;
    node* tail = NULL;

    InsertAtFront(head,tail , 4);
    InsertAtFront(head,tail,3);
    InsertAtFront(head,tail,2);
    InsertAtEnd(head,tail,1);
    InsertAtEnd(head,tail,9);

    InsertAtMid(head,tail,3,0);

    Print(head);
    DeleteAtFront(head,tail);
    Print(head);
    deletionAtEnd(head,tail);
    Print(head);

    /*
    node*ans = SearchLL(head, 3);
    if(ans->data!=NULL){
        cout<<"Node found!!"<<endl;
    }
    else {
        cout<<"Node not found!!"<<endl;
    }
    */

    ReverseLL(head,tail);
    Print(head);

    return 0;

}
