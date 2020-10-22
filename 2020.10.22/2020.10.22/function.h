#pragma once

/*数据结构
1、数据域的值重复，无序，删除关键字为key的节点
2、数据域值不重复，将头节点从头部删除，尾插到尾节点之后
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