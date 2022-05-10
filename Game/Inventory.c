#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

ListNode* insert_last(ListNode* head, element* data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head->link == head || head->prelink == head) {
		head->link = node;
		head->prelink = node;
		node->link = head;
		node->prelink = head;
	}
	else {
		node->prelink = head->prelink;
		node->link = head;
		head->prelink->link = node;
		head->prelink = node;
	}
	return head;
}
ListNode* insert_first(ListNode* head, element* data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head->link == head || head->prelink == head) {
		node->link = head;
		node->prelink = head;
		head->link = node;
		head->prelink = node;

	}
	else {
		node->prelink = head;
		node->link = head->link;
		node->link->prelink = node;
		head->link = node;
	}
	return head;
}
ListNode* insert(ListNode* head, ListNode* pre, element* data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head->link == head || head->prelink == head || head == pre) {
		head = insert_first(head, data);
		return head;
	}
	else {
		node->prelink = pre;
		node->link = pre->link;
		pre->link->prelink = node;
		pre->link = node;
	}
	return head;
}
void print_list(ListNode* head)
{
	ListNode* p;
	int num = 1;
	if (head->prelink == head || head->link == head)
	{
		printf("=================INVENTORY===================\n");
		printf("�������\n");
		printf("=============================================\n");
		return;
	}
	p = head->link;
	printf("=================INVENTORY===================\n");
	do {

		printf("%d.%s", num, p->data);
		num++;
		p = p->link;
		printf("\n");
	} while (p != head);
	printf("=============================================\n");
}
ListNode* deleted(ListNode* head, ListNode* removed) {
	if (head == removed) return;
	else {
		removed->link->prelink = removed->prelink;
		removed->prelink->link = removed->link;
		free(removed);
	}
	return head;
}
ListNode* getdeleteNode(ListNode* head, element* data) {
	if (head->link == head || head->prelink == head) {
		printf("����ֽ��ϴ�.\n");
		return;
	}
	ListNode* removed = NULL;
	for (ListNode* p = head->link; p != head; p = p->link) {
		if (!strcmp(p->data, data)) {
			removed = p;
			break;
		}
	}
	if (removed == NULL) {
		printf("�ش� ���� �����ϴ�.\n");
		return head;
	}
	return removed;
}
void init(ListNode* head) {
	head->link = head;
	head->prelink = head;
	head->data = 'None';
}

