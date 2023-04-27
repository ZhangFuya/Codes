#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
	int data;
	struct node* nextNode;
}LinkList;

LinkList* linklistInit() {
	LinkList* ptrList = malloc(sizeof(LinkList));
	if (ptrList) {
		ptrList->data = 0;
		ptrList->nextNode = NULL;
	}
	return ptrList;
}  //linklistInit

void linklistPrint(LinkList* list) {
	LinkList* ptrList = list;
	while (ptrList->nextNode) {
		printf("%d  ", ptrList->nextNode->data);
		ptrList = ptrList->nextNode;
	}
	printf("\n");
}  //linklistPrint

unsigned int linklistSize(LinkList* list) {
	unsigned int size = 0;
	LinkList* ptrList = list;
	while (ptrList->nextNode) {
		++size;
		ptrList = ptrList->nextNode;
	}
	return size;
}  //linllistSize

void linklistHeadInsert(int data, LinkList* list) {
	LinkList* ptrNode = (LinkList*)malloc(sizeof(LinkList));
	if (ptrNode) {
		ptrNode->data = data;
	}
	LinkList* ptrList = list;
	ptrNode->nextNode = ptrList->nextNode;
	ptrList->nextNode = ptrNode;
	return;
}  //linklistHeadInsert

void linklistAppend(int dataValue, LinkList* list) {
	LinkList* ptrNode = (LinkList*)malloc(sizeof(LinkList));
	if (ptrNode) {
		ptrNode->data = dataValue;
		ptrNode->nextNode = NULL;
	}

	LinkList* ptrList = list;
	while (ptrList->nextNode) {
		ptrList = ptrList->nextNode;
	}
	ptrList->nextNode = ptrNode;
}  //linklistAppend

void linlistInsert(int pos, int dataValue, LinkList* list) {
	LinkList* ptrNode = (LinkList*)malloc(sizeof(LinkList));
	if (ptrNode) {
		ptrNode->data = dataValue;
		ptrNode->nextNode = NULL;
	}

	LinkList* ptrList = list;
	if (ptrList == NULL) return;
	int index = 0;
	while (index++ != pos - 1) {
		ptrList = ptrList->nextNode;
	}
	ptrNode->nextNode = ptrList->nextNode;
	ptrList->nextNode = ptrNode;
}  //linklistInsert

void linklistDelOnPos(unsigned int pos, LinkList* list) {
	assert(list->nextNode);
	unsigned int index = 0;
	LinkList* ptrList = list;
	while (index++ != pos - 1) {
		ptrList = ptrList->nextNode;
	}
	LinkList* ptrDelNode = ptrList->nextNode;
	ptrList->nextNode = ptrDelNode->nextNode;
	free(ptrDelNode);
}  //linklistDelOnPos

void linklistDelOnData(int data, LinkList* list) {
	LinkList* ptrlist = list;
	LinkList* ptrDelNode;
	while (ptrlist->nextNode) {
		if (ptrlist->nextNode->data == data) {
			ptrDelNode = ptrlist->nextNode;
			ptrlist->nextNode = ptrDelNode->nextNode;
			free(ptrDelNode);
			continue;
		}
		ptrlist = ptrlist->nextNode;
	}
}  //linklistDelOnData

void linklistModifyOnPos(unsigned int pos, int data, LinkList* list) {
	LinkList* ptrList = list;
	unsigned int index = 0;
	while (index++ != pos) {
		ptrList = ptrList->nextNode;
	}
	ptrList->data = data;
}  //linklistModifyOnPos

void linklistModifyOnValue(int data, int newdata, LinkList* list) {
	LinkList* ptrList = list->nextNode;
	while (ptrList) {
		if (ptrList->data == data) ptrList->data = newdata;
		ptrList = ptrList->nextNode;
	}
}  //linklistModifyOnValue

unsigned linklistSearchOnValue(int data, LinkList* list) {
	LinkList* ptrList = list;
	int index = 0;
	while (ptrList->nextNode) {
		if (ptrList->nextNode->data == data) {
			return ++index;
		}
		ptrList = ptrList->nextNode;
		index++;
	}
	return 0;
}  //linklistSearchOnValue

int main(int argc, char const* argv[]) {
	LinkList* list = linklistInit();
	for (int i = 0; i < 10; i++) {
		linklistAppend(i, list);
	}
	for (int i = 0; i < 10; i++) {
		linklistHeadInsert(i, list);
	}
	linlistInsert(2, 30, list);
	linlistInsert(1, 50, list);
	linlistInsert(linklistSize(list) + 1, 100, list);

	linklistPrint(list);
	linklistDelOnPos(2, list);
	linklistDelOnPos(1, list);
	linklistDelOnPos(linklistSize(list), list);
	linklistPrint(list);
	linklistDelOnData(0, list);
	linklistDelOnData(30, list);
	linklistDelOnData(9, list);

	linklistModifyOnPos(1, 11, list);
	linklistModifyOnPos(linklistSize(list), 22, list);
	linklistModifyOnPos(3, 33, list);
	linklistPrint(list);
	linklistModifyOnValue(5, 55, list);
	linklistModifyOnValue(11, 111, list);
	linklistModifyOnValue(22, 222, list);
	linklistPrint(list);

	printf("元素: 22, 所在的位置: %u\n", linklistSearchOnValue(22, list));
	printf("元素: 222, 所在的位置: %u\n", linklistSearchOnValue(222, list));
	return 0;
}  //main
