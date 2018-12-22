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

int main(int argc, char* argv[])
{
	insert(3,3);
	insert(11,1);
	addatbegin(12);
	addatbegin(13);
	addatbegin(14);
	insert(15,6);
	insert(15,5);
	display();
	int len=Length();
	printf("\nlength=%d\n",len);

	return 0;
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

