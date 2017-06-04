#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <stdexcept>

using namespace std;

struct Pit
{
	vector<int> vec;
	int count;

	Pit() : count(0) {}

	void add(int value)
	{
		count++;
		vec.push_back(value);
	}

	void del()
	{
		if (count > 0) {
			int min = vec[0];
			int top = 0;
			for (int i = 0; i < count; ++i)
			{
				if (min > vec[i])
				{
					min = vec[i];
					top = i;
				}
			}

			count--;
			vec.erase(vec.begin() + top);
		}
		else
			throw runtime_error("Stack is empty");
	}

	void get()
	{
		if (count > 0)
		{
			int min = INT_MAX;
			for (int i = 0; i < count; ++i)
			{
				if (min > vec[i])
				{
					min = vec[i];
				}
			}
			cout << "Min value " << min << endl;
		}
		else
			throw runtime_error("Stack is empty");
	}
};

void message(const Pit& x)
{
	if (x.count < 1)
		throw runtime_error("Stack is empty");

	for (int i = 0; i < x.vec.size(); ++i)
	{
		cout << x.vec[i] << " ";
	}
	cout << endl;
}

int main()
{
	try {
		Pit Stack;

		Stack.add(4);
		Stack.add(13);
		Stack.add(7);
		Stack.add(15);
		Stack.add(21);

		message(Stack);

		Stack.get();

		Stack.del();
		Stack.del();

		message(Stack);

		Stack.get();

	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}