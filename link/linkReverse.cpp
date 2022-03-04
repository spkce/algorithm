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

	singleNode_t* swap(singleNode_t* pfront, singleNode_t* p)
	{
		singleNode_t* temp = p->next;
		if (temp == NULL)
		{
			return p;
		}

		if (pfront)
		{
			pfront->next = temp;
			p->next = temp->next;
			temp->next = p;
		}
		else
		{
			p->next = temp->next;
			temp->next = p;
		}
		return temp;
	}

	singleNode_t* sort(singleNode_t* phead, int n)
	{
		if (phead == NULL || phead->next == NULL)
		{
			return phead;
		}
		singleNode_t* pExt = new singleNode_t;
		pExt->data = 0;
		pExt->next = phead;
	
		//printf("\033[35m""pi:%p pih:%p""\033[0m\n", pi, pih);
		
		singleNode_t* pi;
		singleNode_t* pif;
	
		for (int i = 0; i < n; i++)
		{
			pi = phead;
			pif = pExt;
	
			while (pi->next != NULL)
			{
				if (pi->data > pi->next->data)
				{
					pi = swap(pif, pi);
				}
				pif = pi;
				pi = pi->next;
			}
			
		}
	
		singleNode_t* pRet = pExt->next;
		delete pExt;
		return pRet;
	}

	singleNode_t* merge(singleNode_t* pA, singleNode_t* pB)
	{
		singleNode_t* head = pB;
		while (pA != NULL)
		{
			singleNode_t* tempA = pA;
			singleNode_t* lastB = NULL;
			pA = pA->next;
			pB = head;
			
			while (pB != NULL)
			{
				if ( tempA->data < pB->data)
				{
					if (lastB == NULL)
					{
						head = tempA;
					}
					else
					{
						lastB->next = tempA;
					}
					tempA->next = pB;
					break;
				}
				lastB = pB;
				pB = pB->next;
			}
		}
		
		return head;
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

	if (0)
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


	{
		singleNode_t *pA = new singleNode_t;
		pA->data = 0;
		pA->next = NULL;
		singleNode_t *p = pA;
		for (int i = 1; i < 10; i++)
		{
			
			p->next = new singleNode_t;
			p = p->next;
			p->data = i;
			p->next = NULL;
		}
		
		p = pA;
		while (p != NULL)
		{
			printf("pA = %p pA->next = %p, pA->data = %d \n", p, p->next, p->data);
			p = p->next;
		}

		singleNode_t *pB = new singleNode_t;
		pB->data = 0;
		pB->next = NULL;
		p = pB;
		for (int i = 1; i < 10; i++)
		{
			
			p->next = new singleNode_t;
			p = p->next;
			p->data = i+10;
			p->next = NULL;
		}

		p = pB;
		while (p != NULL)
		{
			printf("pB = %p pB->next = %p, pB->data = %d \n", p, p->next, p->data);
			p = p->next;
		}

		printf("sort:\n");
		singlelist a;
		p = a.merge(pA, pB);
		while (p != NULL)
		{
			printf("p = %p p->next = %p, p->data = %d \n", p, p->next, p->data);
			p = p->next;
		}
		printf("\n");
	}
	return 0;
}

