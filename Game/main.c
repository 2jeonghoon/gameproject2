#include <stdio.h>
#include <malloc.h>
#include "game.h"

int main(void)
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	init(head);
	char* itemList[15] = { "��������","ĭ���� ����","��ä�� �ǻ�","�η��� ��ɷ�","�ش�","������","�� �ҵ���","�ѱ��� ����","K2 ����","K5 ����","���� ����","���� �ķ�","���� �ҽ���","ACDC ��ȯ ��ġ"};
	head = insert_last(head, itemList[0]);
	head = insert_last(head, itemList[1]);
	print_list(head);



	return 0;
}
