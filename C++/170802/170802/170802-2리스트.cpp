#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node {
	int num = 0;
	Node * next = NULL;
};

void InsertNode(Node* pStart, int nPlace, int nValue)
{
	for (int i = 0; i < nPlace - 2; i++)
	{
		if (pStart == NULL) return ;
		pStart = pStart->next;
	}
	Node* pNew = new Node();
	pNew->num = nValue;

	pNew->next = pStart->next;
	pStart->next = pNew;
}

void DeleteNode(Node* pStart, int nPlace)
{
	for (int i = 0; i < nPlace-2; i++) 
	{
		if (pStart == NULL) return ;
		pStart = pStart->next;
	}
	Node* pDel = pStart->next;
	pStart->next = pStart->next->next;
	delete pDel;
}


int main() 
{
	int num = 0;
	int num2 = 0;
	Node * pStart = NULL;

	while (true) 
	{
		int input;
		cin >> input;

		if (input == 0) break;

		Node* pNew = new Node();
		pNew->num = input;


		if (pStart == NULL) 
		{
			pStart = pNew;
		}
		else {
			Node* pLast = pStart;
			while (pLast->next != NULL) 
			{
				pLast = pLast->next;
			}
			pLast->next = pNew;
		}
	}
	Node* pPrint1 = pStart;
	while (pPrint1 != NULL) 
	{
		cout << pPrint1->num << " ";
		pPrint1 = pPrint1->next;
		if (pPrint1 == NULL) break;
	}
	cout << endl;

	/*
	cout << "삭제할 노드번호를 입력하세요." << endl;
	cin >> num;

	DeleteNode(pStart, num);

	Node* pPrint2 = pStart;
	while (pPrint2 != NULL)
	{
		cout << pPrint2->num << " ";
		pPrint2 = pPrint2->next;
		if (pPrint2 == NULL) break;
	}
	cout << endl;
	*/

	cout << "추가할 장소를 입력하세요." << endl;
	cin >> num;
	cout << "추가할 값을 입력하세요." << endl;
	cin >> num2;

	InsertNode(pStart, num, num2);

	Node* pPrint2 = pStart;
	while (pPrint2 != NULL)
	{
		cout << pPrint2->num << " ";
		pPrint2 = pPrint2->next;
		if (pPrint2 == NULL) break;
	}
	cout << endl;

	Node* pDel = pStart;
	while (pDel != NULL) 
	{
		Node* pSub = pDel;
		pDel = pDel->next;
		delete pSub;
		if (pDel == NULL) break;
	}

	return 0;
}