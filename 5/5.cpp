#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<int> stack1, stack2;
queue<int> queue1, queue2;


void push1(int node)
{
	stack1.push(node);
}

int pop1()
{
	int node;
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			node = stack1.top();
			stack2.push(node);
			stack1.pop();
		}
	}
	node = stack2.top();
	stack2.pop();
	return node;
}

void push2(int node)
{
	queue1.push(node);
}

int pop2()
{
	int node;
	while (queue1.size() > 1)
	{
		int temp = queue1.front();
		queue1.pop();
		queue2.push(temp);
	}
	node = queue1.front();
	queue1.pop();
	while (queue2.size())
	{
		int temp = queue2.front();
		queue2.pop();
		queue1.push(temp);
	}
	return node;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, temp;
	cin >> n;
	cout << "������ջʵ��һ�����У�" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		push1(temp);
	}
	while (!stack1.empty() || !stack2.empty())
	{
		cout << pop1() << " ";
	}
	cout << endl << "����������ʵ��һ��ջ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		push2(temp);
	}
	while (!queue1.empty())
	{
		cout << pop2() << " ";
	}
	cout << endl;
	return 0;
}