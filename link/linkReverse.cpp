#include "stdio.h"

struct singleNode_t
{
	singleNode_t* next;
	int data;
};

class singlelist
{
public:
	//单向链表反转
	singleNode_t* reverse(singleNode_t* head)
	{
		singleNode_t* newHead = NULL;
		singleNode_t* p;

		while (head)
		{
			//1. 对之前的链表做头删
			p = head;
			head = head->next;

			//2. 对新链表做头插
			p->next = newHead;
			newHead = p;
		}
		return newHead;
	}
};


int main(int argc, char const *argv[])
{
	singleNode_t* pHead = new singleNode_t;
	pHead->data = 0;
	pHead->next = NULL;

	singleNode_t* p = pHead;
	for(int i = 1; i < 10; i++)
	{
		p->next = new singleNode_t;
		p = p->next;
		p->data = i;
		p->next = NULL;
	}

	p = pHead;
	while (p != NULL)
	{
		printf ("p = %p p->next = %p, p->data = %d \n", p,  p->next, p->data);
		p = p->next;
	}
	printf("\n");
	singlelist a;
	p = a.reverse(pHead);
	while (p != NULL)
	{
		printf ("p = %p p->next = %p, p->data = %d \n", p,  p->next, p->data);
		p = p->next;
	}

	printf("\n");
	return 0;
}
