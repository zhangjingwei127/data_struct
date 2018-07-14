#include <stdio.h>
#include <malloc.h>

typedef struct ListNode
{
	int data;
	struct ListNode* next;
}List,*LPList;
//struct ListNode == List
//struct ListNode* == LPList
LPList createList()
{
	LPList head = (LPList)malloc(sizeof(List));
	//head->data = 0;
	head->next = NULL;
	return head;
}
LPList createNode(int data)
{
	LPList newnode = (LPList)malloc(sizeof(List));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void boolNULL(LPList list)
{
	LPList frontNode = list;
	LPList posDataNode = list->next;
	if(list->next == NULL)
	{
		printf("list is NULL");
		return;
	}
}
void insertNodeByHead(LPList list,int data)
{
	LPList newnode = createNode(data);
	newnode->next = list->next;
	list->next = newnode;
}
void insertNodeByAppion(LPList list,int data,int posData)
{
	LPList frontNode = list;
	LPList posDataNode = list->next;
	if(posDataNode == NULL)
	{
		printf("No find aim,no way insert!");
		return;
	}
	while(posDataNode != NULL && posDataNode->data != posData)
	{
		frontNode = posDataNode;
		posDataNode = posDataNode->next;
		if(posDataNode == NULL)
		{
			printf("No find aim,no way insert!");
			return;
		}
	}
	
	LPList newNode = createNode(data);
	newNode->next = posDataNode;
	frontNode->next = newNode;
	return;
}
void insertNodeByTail(LPList list,int data)
{
	LPList frontNode = list;
	LPList posDataNode = list->next;
	if(posDataNode == NULL)
	{
		printf("NULL,no way insert!");
		return;
	}
	while(posDataNode != NULL )
	{
		frontNode = posDataNode;
		posDataNode = posDataNode->next;
	}
	
	LPList newNode = createNode(data);
	frontNode->next = newNode;
	return;
}
void deleteNodeByHead(LPList list)
{
	boolNULL(list);
	LPList firstNode = list;
	LPList secondNode = list->next; 
	if(secondNode->next == NULL)
	{
		list->next == NULL;
		free(secondNode);
		return;
	}
	list->next = secondNode->next;
	secondNode->next = NULL;
	free(secondNode);
}
void deleteNodeByTail(LPList list)
{
	LPList firstNode = list;
	LPList secondNode = list->next;
	boolNULL(list);
	while(secondNode->next)
	{
		firstNode = secondNode;
		secondNode = secondNode->next;
	}
	free(secondNode);
	firstNode->next = NULL;
}
void deleteNodeByAppion(LPList list,int posData)
{
	boolNULL(list);
	LPList firstNode = list;
	LPList secondNode = list->next;
	while(secondNode)
	{
		if(secondNode->data == posData)
		{
			firstNode->next = secondNode->next;
			secondNode->next = NULL;
			free(secondNode);
			return;
		}
		firstNode = secondNode;
		secondNode = secondNode->next;
	}
	printf("No find posData!\n");
	return;
}
	
void printList(LPList list)
{
	LPList nextNode = list->next;
	while(nextNode)
	{
		printf("%d\t",nextNode->data);
		nextNode = nextNode->next;
	}
	printf("\n");
}
int main()
{
	LPList list = createList();
	insertNodeByHead(list,1);
	insertNodeByHead(list,2);
	insertNodeByHead(list,4);
	printList(list);
	insertNodeByAppion(list,3,2);
    insertNodeByAppion(list,5,4);
	printList(list);
	deleteNodeByAppion(list,3);
	insertNodeByTail(list,0);
	printList(list);
	deleteNodeByHead(list);
	printList(list);
	for(int num = 0;num < 2;++num)
	{
		deleteNodeByHead(list);
	}
	printList(list);
	deleteNodeByTail(list);
	printList(list);
	deleteNodeByAppion(list,2);
	printList(list);
	deleteNodeByAppion(list,1);
	printList(list);
	return 0;
}
