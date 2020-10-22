#pragma once

/*���ݽṹ
1���������ֵ�ظ�������ɾ���ؼ���Ϊkey�Ľڵ�
2��������ֵ���ظ�����ͷ�ڵ��ͷ��ɾ����β�嵽β�ڵ�֮��
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int DateType;

typedef struct ListNode
{
	DateType _date;
	struct ListNode* _next;
	struct ListNode* _prev;

}ListNode;
void Delete_Key(ListNode* plist,DateType key)
{
	if (plist == NULL)
		return;
	ListNode* cur = plist->_next;
	while (cur!=plist)
	{
		if (plist->_date == key)
		{
			cur->_prev->_next = cur->_next;
			cur->_next->_prev = cur->_prev;
			free(cur);
			cur = NULL;
		}
	}
}
void Delete_Head(ListNode* plist)
{
	if (plist == NULL)
		return;
	ListNode* cur = plist->_next;
	plist->_next = plist->_next->_next;
	plist->_next->_next->_prev = plist;
	plist->_prev->_next = cur;
	cur->_prev = plist->_prev;
	cur->_next = plist;
	plist->_prev = cur;
	cur = NULL;
}