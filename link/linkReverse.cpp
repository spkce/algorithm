#include "stdio.h"
#include <iostream>
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

	int linkSize(singleNode_t* head)
	{
		int i = 0;
		while(head != NULL)
		{
			head = head->next;
			i++;

		}
		return i;
	}

	singleNode_t* sort(singleNode_t* head)
	{
		if (head == NULL || head->next == NULL)
		{
			return head;
		}

		singleNode_t* pMin = head;
		singleNode_t* pMinLast = NULL;

		singleNode_t* pi = head;
		singleNode_t* piLast = NULL;

		while (pi->next != NULL)
		{
			printf("pi = %p pi->next = %p, pi->data = %d \n", pi, pi->next, pi->data);
			singleNode_t* pj = pi->next;
			singleNode_t* pjLast = pi;
			pMin = pi->next;
			pMinLast = pi;
			while(pj != NULL)
			{
				if (pj->data < pMin->data)
				{
					pMinLast = pjLast;
					pMin = pj;
				}

				pjLast = pj;
				pj = pj->next;
			}

			if (pMin != pi)
			{
				printf("pMin = %p pMin->next = %p, pMin->data = %d \n", pMin, pMin->next, pMin->data);
				printf("pMinLast = %p \n", pMinLast);
				if (piLast != NULL)
				{
					piLast->next = pMin;
				}
				if (pMinLast != NULL)
				{
					pMinLast->next = pi;
				}
				
				singleNode_t* temp = pi->next;
				pi->next = pMin->next;
				pMin->next = temp;

				if (pi == head)
				{
					head = pMin;
				}

				pi = pMin->next;
				piLast = pMin;
			}
			else
			{
				pi = pi->next;
				piLast = pi;
			}
		}

		return head;
	}

	singleNode_t* merge(singleNode_t* a, singleNode_t* b)
	{
		
	}
};


int main(int argc, char const *argv[])
{
	if (0)
	{
		singleNode_t* pHead = new singleNode_t;
		pHead->data = 0;
		pHead->next = NULL;
		singleNode_t *p = pHead;
		for (int i = 1; i < 10; i++)
		{
			p->next = new singleNode_t;
			p = p->next;
			p->data = i;
			p->next = NULL;
		}

		p = pHead;
		while (p != NULL)
		{
			printf("p = %p p->next = %p, p->data = %d \n", p, p->next, p->data);
			p = p->next;
		}
		printf("\n");
		printf("reverse:\n");
		singlelist a;
		p = a.reverse(pHead);
		while (p != NULL)
		{
			printf("p = %p p->next = %p, p->data = %d \n", p, p->next, p->data);
			p = p->next;
		}
	}

	{
		singleNode_t *pHead = new singleNode_t;
		pHead->data = 0;
		pHead->next = NULL;
		singleNode_t *p = pHead;
		for (int i = 1; i < 10; i++)
		{
			
			p->next = new singleNode_t;
			p = p->next;
			p->data = 10-i;
			p->next = NULL;
		}

		p = pHead;
		while (p != NULL)
		{
			printf("p = %p p->next = %p, p->data = %d \n", p, p->next, p->data);
			p = p->next;
		}

		printf("sort:\n");
		singlelist a;
		p = a.sort(pHead);
		while (p != NULL)
		{
			printf("p = %p p->next = %p, p->data = %d \n", p, p->next, p->data);
			p = p->next;
		}
		printf("\n");
	}
	return 0;
}

