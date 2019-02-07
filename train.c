#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

// head of the linked list
struct node* root=NULL;


/*function prototype*/
void addatbegin(int data);
void display(void);
int Length (void);
void insert(int input_data,int location);
void delete(int location);
void reverse(void);
void display_Rec(struct node* temp);
void display_Rec_Rev(struct node* temp);
struct node* Rev_linkedlist_Rec(struct node* head);

int main(int argc, char* argv[])
{
	insert(3,3);
	insert(11,1);
	addatbegin(12);
	addatbegin(13);
	addatbegin(14);
	insert(15,6);
	insert(15,4);
	display();
	display();
	delete(4);
	display();
	delete(1);
	display();
	int len=Length();
	printf("\nlength=%d\n",len);
	reverse();
	display();
	struct node* temp=root;
	display_Rec(temp);
	display_Rec_Rev(temp);
	display();

	return 0;
}

/*reverse linked list using recurssion*/
struct node* Rev_linkedlist_Rec(struct node* head)
{
	if (head==NULL)
	{
		return;//linkedlist is empty
	}
	/*recursion part*/
	struct node* p,*q;
	p=head;
	q=p->next;

	if (q==NULL)// end of the list
	{
		return;
	}
	q=Rev_linkedlist_Rec(q);// update the head each time with q value
	p->next->next=p;
	p->next=NULL;
	return q;
	
}
 
/*display linkedlist in reverse order*/
void display_Rec_Rev(struct node* temp)
{
	if (temp==NULL)
	{
		printf("\n");
		return;
	}
	display_Rec_Rev(temp->next);
	printf(" %d", temp->data);
}
/*display linkedlist using recursion*/
void  display_Rec(struct node* temp)
{
	if (temp->next==NULL)
	{
		printf(" %d",temp->data);
		printf("\n");
		return;
	}
	printf(" %d",temp->data);
	display_Rec(temp->next);
}

/*reverse single linkedlist*/
void reverse(void)
{
	struct node *p,*q,*temp;
	p=NULL;
	temp=root;
	/*
	temp=pointer to the current node
	p=popinter to the previous node
	q=pointerto the next node
	*/

	while(temp!=NULL)
	{
		q=temp->next;
		temp->next=p;
		p=temp;
		temp=q;
	}
	root=p;
}

/*delete a node from linkedlist*/
void delete(int location)
{
	if (location>Length())
	{
		return;
	}

	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=root;
	int count=1;
	
	while(count<location-1)
	{
		temp=temp->next;
		count++;
	}
	p=temp->next;

	temp->next=p->next;
	p->next=NULL;
	free(p);
}
/*inserafter nth location*/
void insert(int input_data, int location)
{
	
	if (location>Length() && location!=1)
	{
		return;
	}
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=input_data;
	temp->next=NULL;
	if (location==1)
	{
		temp->next=root;
		root=temp;
	
	}else{
	
		struct node* p;
		p=root;
		int  i=1;
		while(i<location-1)
		{
			p=p->next;
			i++;
		}
		temp->next=p->next;
		p->next=temp;
	}
}

/*length of the linkedlist*/
int Length(void)
{
	struct node* temp;
	temp=root;
	if(root==NULL)
	{
		return 0;
	}
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}


/*display function*/
void display(void)
{
	struct node* temp;
	temp=root;
	if (root==NULL)
	{
		printf("\nlinkedlist is empty!\n");
	}
	printf("\nlinked list nodes are: ");
	while(temp!=NULL)
	{
		printf(" %d", temp->data);
		temp=temp->next;
	}
	printf("\n");
}

/*insert a node into the linked list*/
void addatbegin(int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;

	if (root==NULL)
	{
		root=temp;
		return;
	}
	temp->next=root;
	root=temp;
}
