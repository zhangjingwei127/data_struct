#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node* next;
}List,*LPList;

LPList createList()
{
	LPList head = (LPList)malloc(sizeof(List));
	if(head != NULL)
	{
		head->next = NULL;
		return head;
	}
	printf("分配头内存失败\n");
	return NULL;
}

LPList createNode(int data)
{
	LPList newNode = (LPList)malloc(sizeof(List));
	if(newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
	}
	printf("分配结点内存失败\n");
	return NULL;
}

int boolNULL(LPList list)
{
	if(list->next == NULL)
	{
		printf("list is NULL.\n");
		return 1;
	}
	else
		return 0;
}

void insertNodeByHead(LPList list,int data)
{
	LPList firstNode = list;
	LPList secondNode = list->next;
	LPList newNode = createNode(data);
	list->next = newNode;
	newNode->next = secondNode;
}

void insertNodeByTail(LPList list,int data)
{
	LPList firstNode = list;
	LPList secondNode = list->next;
	while(secondNode)
	{
		firstNode = secondNode;
		secondNode = secondNode->next;
	}
	LPList newNode = createNode(data);
	firstNode->next = newNode;
}

void insertNodeByFrontAimData(LPList list,int aimData,int data)
{
	if(boolNULL(list))
	{
		return;
	}
	LPList firstNode = list;
	LPList secondNode = list->next;
	while(secondNode)
	{
		if(secondNode->data == aimData)
		{
			LPList newNode = createNode(data);
			firstNode->next = newNode;
			newNode->next = secondNode;
			return;
		}
		firstNode = secondNode;
		secondNode = secondNode->next;
	}
	printf("No find aimData,don't insert.\n");
	return;
}
			
void deleteNodeByHead(LPList list)
{
	if(boolNULL(list))
	{
		return;
	}
	LPList firstNode = list;
	LPList secondNode = list->next;
	firstNode->next = secondNode->next;
	free(secondNode);
}

void deleteNodeByTail(LPList list)
{
	if(boolNULL(list))
	{
		return;
	}
	LPList firstNode = list;
	LPList secondNode = list->next;
	while(secondNode->next)
	{
		firstNode = secondNode;
		secondNode = secondNode->next;
	}
	firstNode->next = NULL;
	free(secondNode);
	return;
}

void deleteNodeByAimData(LPList list,int aimData)
{
	if(boolNULL(list))
	{
		return;
	}
	LPList firstNode = list;
	LPList secondNode = list->next;
	while(secondNode)
	{
		if(secondNode->data == aimData)
		{
			firstNode->next = secondNode->next;
			free(secondNode);
			return;
		}
		firstNode = secondNode;
		secondNode = secondNode->next;
	}
	printf("No find aimData node,don't delete.\n");
	return;
}

void print(LPList list)
{
	LPList node = list->next;
	if(boolNULL(list))
	{
		return;
	}
	while(node)
	{
		printf("%d\t",node->data);
		node = node->next;
	}
	printf("\n");
}
int main()
{
	LPList list = createList();
	insertNodeByHead(list,5);
	insertNodeByHead(list,4);
	insertNodeByHead(list,2);
	print(list);
	insertNodeByFrontAimData(list,4,3);
	insertNodeByFrontAimData(list,2,1);
	print(list);
	insertNodeByTail(list,6); 
	print(list);
	deleteNodeByHead(list);
	print(list);
	deleteNodeByTail(list);
	print(list);
	deleteNodeByAimData(list,4);
	print(list);
	deleteNodeByAimData(list,9);
	print(list);
	return 0;
}
