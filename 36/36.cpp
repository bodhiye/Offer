#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
	ListNode() {}
};

ListNode* newList()
{
	ListNode* L = new ListNode;
	L->next = NULL;
	ListNode* q = L;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ListNode *p = new ListNode;
		cin >> p->val;
		q->next = p;
		q = p;
	}
	q->next = NULL;
	return q;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* p1 = pHead1;
	ListNode* p2 = pHead2;
	while (p1 != p2)
	{
		p1 = (p1 != NULL ? p1->next : pHead2);
		p2 = (p2 != NULL ? p2->next : pHead1);
	}
	return p1;
}

int main()
{
	ios::sync_with_stdio(false);
	ListNode* L1 = newList();
	ListNode* L2 = newList();
	cout << FindFirstCommonNode(L1, L2)->val << endl;
	return 0;
}