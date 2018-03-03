#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node 
{
	int num = 0;
	Node* next = NULL;
};
int main()
{
	Node* pStart = NULL;
	while (true)
	{
		int input;
		cin >> input;

		Node* pNew = new Node();
		pNew->num = input;

		if (pStart == NULL)
		{
			pStart = pNew;
		}
		else
		{
			Node* pLast = pStart;
			while (pLast != NULL)
			{
				pLast = pLast->next;
			}
			pLast->next = pNew;
		}
	}
	return 0;
}