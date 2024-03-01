#include <stdio.h> 
#include <stdlib.h>

typedef struct node *NODE;
struct node
{
    int ele;
    NODE next;
};
typedef struct linked_list *LIST;
struct linked_list
{
    int count;
    NODE head;
};
LIST createNewList()
{
    LIST myList;
    myList = (LIST)malloc(sizeof(struct linked_list));
    myList->count = 0;
    myList->head = NULL;
    return myList;
}
NODE createNewNode(int value)
{
    NODE myNode;
    myNode = (NODE)malloc(sizeof(struct node));
    myNode->ele = value;
    myNode->next = NULL;
    return myNode;
}
void insertAfter(int searchEle, NODE n1, LIST l1)
{
    if (l1->head == NULL)
    {
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }
    else
    {
        NODE temp = l1->head;
        NODE prev = temp;
        while (temp != NULL)
        {
            if (temp->ele == searchEle)
                break;
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Element not found\n");
            return;
        }
        else
        {
            if (temp->next == NULL)
            {
                temp->next = n1;
                n1->next = NULL;
                l1->count++;
            }
            else
            {
                prev = temp;
                temp = temp->next;
                prev->next = n1;
                n1->next = temp;
                l1->count++;
            }
            return;
        }
    }
    return;
}
void printList(LIST l1)
{
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while (temp != NULL)
    {
        printf(" %d ->", temp->ele);
        temp = temp->next;
    }
    printf(" [NULL]\n");
}

void rotate(LIST l1, int k)
{
	NODE temp = l1->head;
	NODE end = l1->head;
    while (temp != NULL)
    {
        if (temp->ele == k)
                break;
        temp = temp->next;
    }
    while (end->next != NULL)
        end = end->next;

    end->next = l1->head;
    l1->head = temp->next;
    temp->next = NULL;
}

void reverseList(LIST l1)
{
	NODE temp = l1->head;
	NODE prev = NULL;
	while (temp != NULL){
		l1->head = temp->next;
		temp->next = prev;
		prev = temp;
		temp = l1->head;
	}
	l1->head = prev;
}

void insertFirst(NODE n1, LIST l1)
{
	if (l1->head == NULL)
    {
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }
    else
    {
    	n1->next = l1->head;
    	l1->head = n1;
    }
}

LIST addList(LIST l1, LIST l2)
{
	NODE temp1 = l1->head;
	NODE temp2 = l2->head;
	LIST ans = createNewList();
	int carry = 0;
	while(temp1 != NULL && temp2 != NULL){
		int add = temp1->ele + temp2->ele +carry;
		int digit = add%10;
		insertFirst(createNewNode(digit), ans);
		carry = add/10;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if (carry != 0)
	{
		insertFirst(createNewNode(carry), ans);
	}
	return ans;
}


int main(){
	// LIST intList = createNewList();
	// insertAfter(0, createNewNode(1), intList);
	// insertAfter(1, createNewNode(2), intList);
	// insertAfter(2, createNewNode(3), intList);
	// insertAfter(3, createNewNode(4), intList);
	// insertAfter(4, createNewNode(5), intList);

	// printList(intList);
	// reverseList(intList);
	// printList(intList);
	// rotate(intList, 2);
	// printList(intList);

	LIST l1 = createNewList();
	insertFirst(createNewNode(3),l1);
	insertFirst(createNewNode(0),l1);
	insertFirst(createNewNode(0),l1);
	insertFirst(createNewNode(2),l1);

	LIST l2 = createNewList();
	insertFirst(createNewNode(9),l2);
	insertFirst(createNewNode(1),l2);
	insertFirst(createNewNode(1),l2);
	insertFirst(createNewNode(9),l2);

	LIST addition = addList(l1, l2);
	reverseList(l1);
	reverseList(l2);
	printList(l1);
	printList(l2);
	
	printList(addition);

	return 0;
}