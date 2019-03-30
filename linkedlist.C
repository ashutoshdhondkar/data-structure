// Linked lists
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node {
	int data;
	struct node *next; // holds the address of next node
};
struct node *head = NULL; // pointer to the head node

void create_ll(){
	
	struct node *p,*temp;
	int n,i,element;
	
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	
	printf("Enter the element 1 : ");
	scanf("%d",&element);
	// creating a space
	temp = (struct node *)malloc(sizeof(struct node));
	
	temp -> data = element;
	temp -> next = NULL;
	p = temp; // header node
	head = p; // update the global head ptr
	
	// now creating the remaining nodes
	for(i=1;i<n;i++) {
		printf("Enter the element %d : ",i+1);
		scanf("%d",&element);
		temp = (struct node*)malloc(sizeof(struct node));
		temp -> data = element;
		p -> next = temp;
		temp -> next = NULL;
		p = temp;
			
	}
	
	
}

void display_ll() {
	struct node *p;
	p = head;
	printf("\n\nThe linked list is created as : \n\n");
	while(p -> next != NULL){
		printf("[ %d ]--->",p->data);
		p = p->next;
	}
	// printing the last data
	printf("[ %d ]\n\n",p->data);
	
}

void insert_at_beginning() {
	int element;
	struct node *p,*temp;
	printf("\nEnter the element to be inserted : ");
	scanf("%d",&element);
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = element;
	
	// holding the previous head
	p = head;
	
	// the head is npw updated
	head = temp;
	
	head -> next = p;
}

void insert_at_end() {
	struct node *p,*temp;
	int element;
	printf("\nEnter element to be inserted : ");
	scanf("%d",&element);
	
	// creating the node
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = element;
	p = head;
	while(p -> next != NULL){
		p = p->next;
	}
	p -> next = temp;
	temp -> next = NULL;
	
}

void insert_at_specific_position() {
	int element,pos,count = 0;
	struct node *p,*temp,*slow,*fast;
	
	printf("\nEnter the element to be inserted : ");
	scanf("%d",&element);
	printf("\nEnter position to be inserted : ");
	scanf("%d",&pos);
	
	temp = (struct node*)malloc(sizeof(node));
	temp -> data = element;
	
	// creating 2 pointers to hold the two values
	slow = head;
	fast = head;
	while(count!= pos-1){
		count++;
		slow = fast;
		fast = fast -> next;
	}
	slow -> next = temp;
	temp -> next = fast;
	
}

void delete_node_at_beginning() {
	struct node *p;
	
	// update the value of head
	p = head;
	head = p -> next;
	
	free(p);
}

void delete_node_at_end() {
	struct node *p,*prev;
	p = head;
	while(p->next != NULL) {
		prev = p;
		p = p->next;
	}
	prev -> next = NULL;
	free(p);
}

void delete_node_at_position() {
	int pos,count = 0;
	struct node *slow,*fast;
	
	printf("\nEnter position to be deleted : ");
	scanf("%d",&pos);
	
	
	fast = head;
	
	while(count != pos-1){
		slow = fast;
		fast = fast -> next;
		count ++;
	}
	slow -> next = fast -> next; // deleting the middle node
	free(fast);
}

void reverse_linked_list() {
	
	// reversing only the links
	
	struct node *p,*curr,*q;
	p = NULL;
	curr = head;
	
	while(curr != NULL) {
		q = curr -> next;
		curr -> next = p;
		p = curr;
		curr = q;
		
	}
	head = p; 
	display_ll();
}




int main() {
	
	int choice;
	printf("\nCreating the Linked List \n");
	create_ll();
	while(1){
		printf("\n1 : Insert the node at start");
		printf("\n2 : Insert the node at end");
		printf("\n3 : Insert the node at specific node");
		printf("\n4 : Delete the node at start");
		printf("\n5 : Delete the node at end");
		printf("\n6 : Delete the node at specific postion");
		printf("\n7 : Display the list");
		printf("\n\nEnter your choice here : >>>");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				insert_at_beginning();
				break;
			case 2 : 
				insert_at_end();
				break;
			case 3 :
				insert_at_specific_position();
				break;
			case 4 : 
				delete_node_at_beginning();
				break;
			case 5 : 
				delete_node_at_end();
				break;
			case 6 :
				delete_node_at_position();
				break;
			case 7 : 
				display_ll();
				break;
			case 8 :
				reverse_linked_list();
				break;
				
			default : 
				printf("Invalid choice !");
				break;
		}
	}
	
	
	return 0;
	
}


