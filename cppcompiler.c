*** INFIX TO POSTFIX ***

#include <stdio.h>
#include <stdlib.h>
char stack[30];
char postfix[30];
int top=-1;
int priority(char w)
{
	switch(w)
	{
		case '+': return 1;
		case '-':return 2;
		case '*':return 3;
		case '/':return 4;
		default:return 0;
	}
}
int main()
{
	int i,j=0;
	char infix[30];
    printf("Give Infix expression\n");
    scanf("%s",infix);
    for(i=0;infix[i]!='\0';i++)
    {
		if(infix[i]=='(')
			{
				top++;
				stack[top]=infix[i];
			}
		else if(infix[i]==')')
		{
			while(stack[top]!='(')
			{
                postfix[j]=stack[top];
                j++;
                top--;
			}
			top--;
		}
		else if(infix[i]<'z'&&infix[i]>'a')
		{
            postfix[j]=infix[i];
            j++;
		}
		else if(priority(infix[i])>priority(stack[top]))
		{
            top++;
            stack[top]=infix[i];
		}
		else if(priority(infix[i])<priority(stack[top]))
		{
            while(priority(infix[i])<priority(stack[top]))
            {
                postfix[j]=stack[top];
                j++;
                top--;
            }
            top++;
            stack[top]=infix[i];
		}
		else
		{
            postfix[j]=infix[i];
            j++;
		}
    }

    postfix[j]='\0';
    printf("%s",postfix);
    return 0;
}

*** INFIX TO POSTFIX ***

*** POSTFIX EVAL ***

#include <stdio.h>
#include <stdlib.h>
int main()
{
    char postfix[20];
    float stack[20];
    int i=0,top=-1;
    float b;
    printf("GIB POSTFIX\n");
    scanf("%s",postfix);
    for(;postfix[i]!='\0';i++)
    {
        switch(postfix[i])
        {
    case '+':
        b=stack[top];
        top--;
        stack[top]=stack[top]+b;
        break;
    case '-':
        b=stack[top];
        top--;
        stack[top]=stack[top]-b;
        break;
    case '/':
        b=stack[top];
        top--;
        stack[top]=stack[top]/b;
        break;
    case '*':
        b=stack[top];
        top--;
        stack[top]=stack[top]*b;
        break;
    default:
        if(postfix[i]>='0'&&postfix[i]<='9')
        {
            top++;
            b=(float)(postfix[i]-'0')*1.0f;
            stack[top]=b;
        }
        }
    }
    printf("%f",stack[top]);
}

*** POSTFIX EVAL ***

*** CIRCULAR QUEUE ***

#include <stdio.h>
#include <stdlib.h>
#define max 5
int rare=-1,front=0;
int s[max];
void ins(void)
{
    if((rare-front)==max-1)
        printf("Overflown:(\n");
    else
    {
        rare++;
        printf("GIB no:");
        scanf("%d",&s[rare%max]);
    }
}
void del(void)
{
    if(front>rare)
        printf("Underflown\n");
    else if(front==rare)
    {
        printf("Deleted no: %d\n",s[front%max]);
        rare=-1;
        front=0;
    }
    else
    {
        printf("Deleted no: %d\n",s[front%max]);
        front++;
    }
}
void dis(void)
{
    int i;
    for(i=front;i<=rare;i++)
        printf("%d ",s[i%max]);
    printf("\n");
}
int main()
{
    int t;
    printf("1 for INS\n2 for Del\n3 for Dis\n4 for End\n");
    while(1)
    {
        scanf("%d",&t);
        switch(t)
        {
        case 1:
            ins();
            break;
        case 2:
            del();
            break;
        case 3:
            dis();
            break;
        case 4:
            return 0;
	}
}
}
/*
1 for INS
2 for Del
3 for Dis
4 for End
2
Underflown
1
GIB no:10
1
GIB no:20
1
GIB no:30
1
GIB no:40
1
GIB no:50
1
Overflown:(
2
Deleted no: 10
3
20 30 40 50 
1
GIB no:60
1
Overflown:(
2
Deleted no: 20
3
30 40 50 60 
4
*/

*** CIRCULAR QUEUE ***

*** SINGLE LINKED LIST ***

//Experinment 5:Single Liknedlist
#include <stdio.h>
#include <stdlib.h>
typedef struct linkedlist
{
    int data;
    struct linkedlist *next;
}llt;
llt *start,*ptr,*ptr1;
void ins_s()
{
    if(start==NULL)
	{
        start=malloc(sizeof(llt));
        printf("Give Data:");
        scanf("%d",&start->data);
        start->next=NULL;
	}
	else
	{
        ptr=malloc(sizeof(llt));
        printf("Give Data:");
        scanf("%d",&ptr->data);
        ptr->next=start;
        start=ptr;
	}
}
void ins_e()
{
    if(start==NULL)
	{
        start=malloc(sizeof(llt));
        printf("Give Data:");
        scanf("%d",&start->data);
        start->next=NULL;
	}
	else
	{
        	for(ptr=start;ptr->next!=NULL;ptr=ptr->next){}
        ptr1=malloc(sizeof(llt));
        printf("Give Data:");
        scanf("%d",&ptr1->data);
        ptr->next=ptr1;
        ptr1->next=NULL;
	}
}
void ins_m()
{
    int m;
    printf("Enter element to be inserted at:");
    scanf("%d",&m);
	for(ptr=start;ptr->data!=m;ptr=ptr->next){}
    ptr1=malloc(sizeof(llt));
    printf("Enter element:");
    scanf("%d",&ptr1->data);
    ptr1->next=ptr->next;
    ptr->next=ptr1;
}
void del_s()
{
    if(start==NULL)
        printf("Empty list\n");
	else
	{
		printf("Element deleted:%d\n",start->data);
        start=start->next;
	}
}
void del_e()
{
    if(start==NULL)
        printf("Empty list\n");
    else
    {
        for(ptr=start;ptr->next->next!=NULL;ptr=ptr->next){}
        printf("Element deleted:%d\n",ptr->next->data);
		ptr->next=NULL;
    }
}
void del_m()
{
	int m;
    if(start==NULL)
		printf("Empty LIst\n");
    else if(start->next==NULL)
    {
        del_s();
    }
    else
	{
		printf("Element to be deleted:");
		scanf("%d",&m);
		if(start->data==m)
            del_s();
		else
		{
			for(ptr=start;ptr->next->data!=m;ptr=ptr->next){}
			ptr->next=ptr->next->next;
		}
	}

}
void disp()
{
	for(ptr=start;ptr!=NULL;ptr=ptr->next)
        printf(" %d ",ptr->data);
    printf("\n");
}
int main()
{
	int t;
	start=NULL;
    printf("1 for insert at start\n2 for insert end\n3 for insert in middle\n4 for delete start");
    printf("\n5 for delete end\n6 for delete middle\n7 for display\n8 for end\n");
    while(1)
	{
        printf("Enter choice:");
		scanf("%d",&t);
		switch(t)
		{
            case 1:
            	ins_s();
            	break;
			case 2:
				ins_e();
				break;
			case 3:
				ins_m();
				break;
			case 4:
                del_s();
                break;
			case 5:
				del_e();
				break;
			case 6:
				del_m();
				break;
			case 7:
				disp();
				break;
			default:
				return 0;
		}
	}
}
/*
OUTPUT:
1 for insert at start
2 for insert end
3 for insert in middle
4 for delete start
5 for delete end
6 for delete middle
7 for display
8 for end
Enter choice:4
Empty list
Enter choice:1
Give Data:20
Enter choice:1
Give Data:10
Enter choice:2
Give Data:30
Enter choice:2
Give Data:40
Enter choice:3
Enter element to be inserted at:20
Enter element:25
Enter choice:7
 10  20  25  30  40
Enter choice:4
Element deleted:10
Enter choice:5
Element deleted:40
Enter choice:6
Element to be deleted:25
Enter choice:7
 20  30
Enter choice:8
*/


*** SINGLE LINKED LIST ***


*** DOUBLE LINKED LIST ***

//Experiment 6:Doubly Linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct doublylinkedlist
{
    int data;
    struct doublylinkedlist *next,*prev;
}dllt;
dllt *start,*end,*ptr,*ptr1;
void ins_s()
{
	if(start==NULL&&end==NULL)
	{
        start=malloc(sizeof(dllt));
        printf("Give Data:");
        scanf("%d",&start->data);
        start->next=NULL;
        start->prev=NULL;
        end=start;
	}
	else
	{
        ptr=malloc(sizeof(dllt));
        printf("enter Data:");
        scanf("%d",&ptr->data);
        ptr->next=start;
        start->prev=ptr;
        ptr->prev=NULL;
        start=ptr;
	}
}
void ins_e()
{
	if(start==NULL&&end==NULL)
	{
        start=malloc(sizeof(dllt));
        printf("Give Data:");
        scanf("%d",&start->data);
        start->next=NULL;
        start->prev=NULL;
        end=start;
	}
	else
	{
        ptr=malloc(sizeof(dllt));
        printf("enter Data:");
        scanf("%d",&ptr->data);
        end->next=ptr;
        ptr->prev=end;
        ptr->next=NULL;
        end=ptr;
	}
}
void ins_m()
{
    int m;
    printf("Enter element to be inserted at:");
    scanf("%d",&m);
	for(ptr=start;ptr->data!=m;ptr=ptr->next){}
    ptr1=malloc(sizeof(dllt));
	printf("Give Data:");
	scanf("%d",&ptr1->data);
    ptr1->next=ptr->next;
    ptr->next->prev=ptr1;
    ptr->next=ptr1;
    ptr1->prev=ptr;
}
void del_s()
{
    if(start==NULL&&end==NULL)
        printf("Empty list");
	else
		{
            printf("Element Delented:%d\n",start->data);
            start=start->next;
		}
}
void del_e()
{
    if(start==NULL&&end==NULL)
        printf("Empty list");
	else
		{
            printf("Element Delented:%d\n",end->data);
            end=end->prev;
            end->next=NULL;
		}
}
void del_m()
{
    int m;
    if(start==NULL&&end==NULL)
		printf("Empty");
	else
	{
        printf("Enter element to be deleted");
        scanf("%d",&m);
        for(ptr=start;ptr->data!=m;ptr=ptr->next){}
        ptr->next->prev=ptr->prev;
		ptr->prev->next=ptr->next;
	}
}
void disp()
{
	for(ptr=start;ptr!=NULL;ptr=ptr->next)
		printf(" %d ",ptr->data);
	printf("\n");
}
void rdisp()
{
	for(ptr=end;ptr->prev!=NULL;ptr=ptr->prev)
		printf(" %d ",ptr->data);
	printf("\n");
}
int main()
{
{
	int t;
	start=NULL;
	end=NULL;
    printf("1 for insert at start\n2 for insert end\n3 for insert in middle\n4 for delete start");
    printf("\n5 for delete end\n6 for delete middle\n7 for display\n8 for reverse traversal \n9 to end\n");
    while(1)
	{
        printf("Enter choice:");
		scanf("%d",&t);
		switch(t)
		{
            case 1:
            	ins_s();
            	break;
			case 2:
				ins_e();
				break;
			case 3:
				ins_m();
				break;
			case 4:
                del_s();
                break;
			case 5:
				del_e();
				break;
			case 6:
				del_m();
				break;
			case 7:
				disp();
				break;
			case 8:
				rdisp();
				break;
			default:
				return 0;
		}
	}
}
}
/*
OUTPUT:
1 for insert at start
2 for insert end
3 for insert in middle
4 for delete start
5 for delete end
6 for delete middle
7 for display
8 for reverse traversal
9 to end
Enter choice:4
Empty listEnter choice:1
Give Data:20
Enter choice:1
enter Data:10
Enter choice:2
enter Data:30
Enter choice:2
enter Data:40
Enter choice:7
 10  20  30  40
Enter choice:3
Enter element to be inserted at:20
Give Data:25
Enter choice:7
 10  20  25  30  40
Enter choice:4
Element Delented:10
Enter choice:5
Element Delented:40
Enter choice:7
 20  25  30
Enter choice:6
Enter element to be deleted25
Enter choice:7
 20  30
Enter choice:8
 30  20
Enter choice:9
*/


*** DOUBLE LINKED LIST ***

*** BINARY TREE ***

#include <stdio.h>
#include<malloc.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;
typedef struct node *tree;
void create(int);
void deletenode(int);
void delete1(tree);
int smallest(tree);
void search(tree,int);
void inorder(tree);
void preorder(tree);
void postorder(tree);
tree parentptr=NULL;
int main( )
{
   int val,c;
   do
   {printf("1.create\t2.inorder\t3.preorder\t4.postprder\t5.delete\n");
   scanf("%d",&c);
   switch(c)
   {    case 1:printf("Enter the value to insert in tree");
	       scanf("%d",&val);
               create(val);
               break;
        case 2:inorder(root);break;
        case 3:preorder(root);break;
        case 4:postorder(root);break;
        case 5:printf("Enter the value to delete in tree");
	       scanf("%d",&val);
               deletenode(val);break;
        default: printf("wroung choice"); 
    }
   }while(c>=1 && c<=5);
return 0;
    
}
void create(int val)
{ tree newnode,ptr;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=val;
  newnode->left=newnode->right=NULL;
  if(root==NULL)
   root=newnode;
  else
  { ptr=root;
    while(ptr!=NULL)
    {parentptr=ptr;
     if(val>ptr->data)
      ptr=ptr->right;
     else 
       ptr=ptr->left;
     }
    if(val>parentptr->data)
      parentptr->right=newnode;
     else 
       parentptr->left=newnode;
   }
}

void inorder(tree p)
{ if(p!=NULL)
   { inorder(p->left);
     printf("%d\t",p->data);
     inorder(p->right);
   }
}   
void preorder(tree p)
{ if(p!=NULL)
   { 
     printf("%d\t",p->data);
     preorder(p->left);
     preorder(p->right);
   }
}  
void postorder(tree p)
{ if(p!=NULL)
   { postorder(p->left);
     postorder(p->right);
     printf("%d\t",p->data);
   }
}  
 
void deletenode(int val)
{ parentptr=root;
  search(root,val);
}
int smallest(tree p)
{ if(p==NULL)
   {printf("tree is not created");
   }
 else
{
while(p->left!=NULL)
   {p=p->left;
   }
 return(p->data);
}
}
void search(tree p,int val)
{ if(p==NULL) printf("tree not created\n");
  else
   { 
      if(val>p->data)
      {parentptr=p;
       search(p->right,val);
      }
      else if(val<p->data)
      {parentptr=p;
       search(p->left,val);
      }
     else if(val==p->data) 
       delete1(p);
   }
}
void delete1(tree p)
{ int k; tree p2;
  if((p->left==NULL)&&(p->right==NULL))
  { if(parentptr->left==p)
        parentptr->left=NULL;
    else 
        parentptr->right=NULL;
     p=NULL;
     free(p);
     return;
  }
    else if(p->right==NULL)
     {  if(p==root)
           root=p->left;
        else if( parentptr->left==p)
        parentptr->left=p->left;
        else if( parentptr->right==p)
        parentptr->right=p->left; 
        p=NULL;
     free(p);
     return;
     }
    else if(p->left==NULL)
     {  if(p==root)
           root=p->right;
        else if( parentptr->left==p)
        parentptr->left=p->right;
        else if( parentptr->right==p)
        parentptr->right=p->right; 
        p=NULL;
     free(p);
     return;
     }
    else if((p->left!=NULL)&&(p->right!=NULL))
    {
      k=smallest(p->right);
      p2=p;
      search(root,k);
      p2->data=k;
      return;
     }
      
}
/* OUTPUT :

1.create        2.inorder       3.preorder      4.postprder     5.delete
1                                                                               
Enter the value to insert in tree 12                                            
1.create        2.inorder       3.preorder      4.postprder     5.delete        
1
Enter the value to insert in tree 56                                            
1.create        2.inorder       3.preorder      4.postprder     5.delete        
1                                                                               
Enter the value to insert in tree 67                                            
1.create        2.inorder       3.preorder      4.postprder     5.delete        
1                                                                               
Enter the value to insert in tree 75                                            
1.create        2.inorder       3.preorder      4.postprder     5.delete        
2                                                                               
12      56      67      75      1.create        2.inorder       3.preorder      
4.postprder     5.delete                                                        
3                                                                               
12      56      67      75      1.create        2.inorder       3.preorder      
4.postprder     5.delete                                                        
4                                                                               
75      67      56      12      1.create        2.inorder       3.preorder      
4.postprder     5.delete                                                        
8                                                                               
                                                                
*** BINARY TREE ***

*** BFS BREADTH FIRST SEARCH ***

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 100

#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAX][MAX];
int state[MAX];
void BF_Traversal();
void BFS(int v);

int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main()
{
    int i,j;   clrscr();
    printf("Enter number of vertices:");

    scanf("%d",&n);

    //read the adjecency matrix
    printf("\nEnter adjecency matrix of the graph:");

    for(i=1;i<=n;i++)
      { for(j=1;j<=n;j++)
	    scanf("%d",&adj[i][j]);
      }
    BF_Traversal();
    getch();
    return 0;
}

void BF_Traversal()
{
    int v;

    for(v=1; v<=n; v++)
	state[v] = initial;

    printf("Enter Start Vertex for BFS: \n");
    scanf("%d", &v);
    BFS(v);
}

void BFS(int v)
{
    int i;

    insert_queue(v);
    state[v] = waiting;

    while(!isEmpty_queue())
    {
	v = delete_queue( );
	printf("%d ",v);
	state[v] = visited;

	for(i=1; i<=n; i++)
	{
	    if(adj[v][i] == 1 && state[i] == initial)
	    {
		insert_queue(i);
		state[i] = waiting;
	    }
	}
    }
    printf("\n");
}

void insert_queue(int vertex)
{
    if(rear == MAX-1)
	printf("Queue Overflow\n");
    else
    {
	if(front == -1)
	    front = 0;
	rear = rear+1;
	queue[rear] = vertex ;
    }
}

int isEmpty_queue()
{
    if(front == -1 || front > rear)
	return 1;
    else
	return 0;
}

int delete_queue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
	printf("Queue Underflow\n");
	exit(1);
    }

    delete_item = queue[front];
    front = front+1;
    return delete_item;
}

 /*
 OUTPUT
 Enter number of vertices:4

Enter adjecency matrix of the graph:0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter starting vertex :4
4 2 3 1
*/

*** BFS BREADTH FIRST SEARCH ***


*** DFS DEPTH FIRST SEARCH ***

#include<stdio.h>
#include<conio.h>

void DFS(int);
int G[10][10],visited[10],n;    //n is no of vertices and graph is sorted in array G[10][10]

void main()
{
    int i,j;clrscr();
    printf("Enter number of vertices:");

    scanf("%d",&n);

    //read the adjecency matrix
    printf("\nEnter adjecency matrix of the graph:");

    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
	    scanf("%d",&G[i][j]);

    //visited is initialized to zero
   for(i=1;i<=n;i++)
	visited[i]=0;

    DFS(1);
    getch();
}

void DFS(int i)
{
    int j;
    printf("\n%d",i);
    visited[i]=1;

    for(j=2;j<=n;j++)
      { if(!visited[j]&&G[i][j]==1)
	    DFS(j);
      }
}

*** DFS DEPTH FIRST SEARCH ***


*** TOPOLOGICAL SORTING ***

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 100

int n;
int adj[MAX][MAX];
int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int find_indegree(int);
void topologicalsort();
int main()
{
    int i,j;   clrscr();
    printf("Enter number of vertices:");
    scanf("%d",&n);
    //read the adjecency matrix
    printf("\nEnter adjecency matrix of the graph:");
    for(i=1;i<=n;i++)
      { for(j=1;j<=n;j++)
	    scanf("%d",&adj[i][j]);
      }
     printf("\nAdjecency matrix of the graph:");
    for(i=1;i<=n;i++)
      { for(j=1;j<=n;j++)
	    printf("%d\t", adj[i][j]);
	printf("\n");
      }
    topologicalsort();
    getch();
    return 0;
}
void topologicalsort()
{ int node,indeg[MAX],del_node,topo_sort[MAX],j=1,i;
  /*find dgree*/
  for(node=1;node<=n;node++)
  {  indeg[node]=find_indegree(node);
     printf("\nIndedree of % d is %d\n",node,indeg[node]);
      if(indeg[node]==0)
	 insert_queue(node);
  }
  while(front<=rear)
  {  del_node=delete_queue();
     topo_sort[j]=del_node;
     j++;
     /*delete edge*/
     for(node=1;node<=n;node++)
     {
	if(adj[del_node][node]==1)
	{  adj[del_node][node]=0;
	   indeg[node]=indeg[node]-1;
	   if(indeg[node]==0)
	      insert_queue(node);
	 }
      }
  }
      printf("The Topological sort can be given as:\n");
      for(node=1;node<j;node++)
	printf("%d\t",topo_sort[node]);
}
void insert_queue(int val)
{
    if(rear == MAX-1)
	printf("Queue Overflow\n");
    else
    {
	if(front == -1)
	   { front = 0;
	    rear=0;}
	else
	    rear++;
    queue[rear] = val;
    }
}

int delete_queue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
	printf("Queue Underflow\n");
	exit(1);
    }

    delete_item = queue[front];
    front = front+1;
    return delete_item;
}

int find_indegree(int node)
{  int i,in_deg=0;
   for(i=1;i<=n;i++)
   { if(adj[i][node]==1)
	 in_deg++;
   }
  return in_deg;
}

*** TOPOLOGICAL SORTING ***


*** QUICK SORTING ***

#include<stdio.h>
#include<conio.h>
int number[25];
void quicksort(int first,int last)
{
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
	 while(number[i]<=number[pivot]&&i<last)
	    i++;
	 while(number[j]>number[pivot])
	    j--;
	 if(i<j){
	    temp=number[i];
	    number[i]=number[j];
	    number[j]=temp;
	 }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(first,j-1);
      quicksort(j+1,last);

   }
}

int main(){
   int i, count;

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   quicksort(0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
   getch();
   return 0;
}

/* OUTPUT :
How many elements are u going to enter?: 5
Enter 5 elements: 1                                                             
2                                                                               
64                                                                              
35                                                                              
23                                                                              
Order of Sorted elements:  1 2 23 35 64                                         

*** QUICK SORTING ***

*** BINARY SEARCH ***

#include <stdio.h>
#include<conio.h>
 int main()
 { int c, first, last, middle, n, search, array[100];
 clrscr();
 printf("Enter number of elements\n");
scanf("%d",&n);
printf("Enter %d integers\n", n);
 for (c = 0; c < n; c++)
scanf("%d",&array[c]);
printf("Enter value to find\n");
scanf("%d", &search);
 first = 0;
 last = n - 1;
 middle = (first+last)/2;
while (first <= last)
{ if (array[middle] < search)
       first = middle + 1;
else if (array[middle] == search)
 { printf("%d found at location %d.\n", search, middle+1); break; }
 else
	 last = middle - 1;
middle = (first + last)/2;
 }
 if (first > last)
printf("Not found! %d isn't present in the list.\n", search);
getch();
return 0;

 }

 /* OUTPUT :

 Enter number of elements
7                                                                               
Enter 7 integers                                                                
1                                                                               
3                                                                               
5                                                                               
7                                                                               
9                                                                               
11                                                                              
13                                                                              
Enter value to find                                                             
11                                                                              
11 found at location 6.                                                         


*** BINARY SEARCH ***
