#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

//struct node *head, *temp;// GLOBAL

struct node* create(int n,struct node *head,struct node *temp){
	head= (struct node *)malloc(sizeof(struct node));// MEMORY LOCATION
	if(head==NULL){
		printf("\nNo  memory");
		exit(0);
	}
	int d;
	printf("\nEnter data: ");
	scanf("%d", &d);
	head->data=d;
	head->next= NULL;
	temp= head;
	for(int i=2;i<=n;i++){
		struct node *new= (struct node *)malloc(sizeof(struct node));
		if(new == NULL){
			printf("Not Enough memory");
			break;
		}
		int da;
		printf("\nEnter data: ");
		scanf("%d", &da);
		new->data= da;
		new->next= NULL;
		temp->next= new;
		temp= temp->next;
	}
    return head;
}

void display(struct node *h){
	int i=1;
	while(h){
		printf("\nData at node %d: %d", i, h->data);
		h= h->next;
		i++;
	}
}
struct node*InsertAfterNode(struct node*head,int node,int data)
{
  struct node*temp=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
		printf("\nNo  memory");
		exit(0);
	}
    struct node*itr=head;
    //struct node*temp;
    int c=1;
    while(itr->next!=NULL )
    {
        if(c==node)
        {
            temp->data=data;
            temp->next=itr->next;
			itr->next=temp;
            break;
        }
        else{
            c++;
            itr=itr->next;
        }
    }
   return head;
}


int main(){
	int n;
    struct node*head;
    struct node*temp;
	printf("Enter the nodes that you want to insert: ");
	scanf("%d",&n);
	head=create(n,head,temp);
    printf("The Original link list is:\n");
	display(head);
    int node;
    int data;
    printf("\nEnter the value of node and data \n");
    scanf("%d%d",&node,&data);
    head=InsertAfterNode(head,node,data);//VALUE mean the nth NODE AFTER WHICH U WANT TO JOIN ANOTHER NODE
    printf("The link list After changes is:\n");
	display(head);
}