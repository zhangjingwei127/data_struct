//StaticLink
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *next;
};

int main()
{
	struct Node Node1 = {1,NULL};
	struct Node Node2 = {2,NULL};
	struct Node Node3 = {3,NULL};

	Node1.next = &Node2;
	Node2.next = &Node3;
	printf("%d\n",Node2.next->data);
	while(1);//
	return 0;
}
