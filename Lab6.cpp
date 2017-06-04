#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <ctime>
#include <climits>

using namespace std;

template <typename tname>
struct Pit
{
	vector<tname> vec;
	int count;

	Pit() : count(0) {}

	void add(tname value)
	{
		count++;
		vec.push_back(value);
	}
	void del()
	{
		if (count > 0) {
			tname min = vec[0];
			int pos = 0;
			for (int i = 0; i < count; ++i)
			{
				if (min > vec[i])
				{
					min = vec[i];
					pos = i;
				}
			}
			count--;
			vec.erase(vec.begin() + pos);
		}
		else
			throw runtime_error("stack pust");
	}

	void get()
	{
		if (count > 0)
		{
			tname min = INT_MAX;
			for (int i = 0; i < count; i++)
			{
				if (min > vec[i])
				{
					min = vec[i];
				}
			}
			cout << "min value = " << min << endl;
		}
		else
			throw runtime_error("stack pust");

	}

	void output()
	{
		if (count > 0)
		{
			for (int i = 0; i < count; i++)
			{
				cout << vec[i] << "  ";
			}
			cout << endl;
		}
		else
			throw runtime_error("stack pust");
	}
};

int main()
{
	try
	{
		cout << "int" << endl;;

		Pit <int> stack;
		stack.add(2);
		stack.add(365);
		stack.add(-76473);
		stack.add(231);
		stack.add(3213);
		stack.output();
		stack.get();
		stack.del();
		stack.del();
		stack.output();
		stack.get();

		cout << "double" << endl;

		Pit <double> stack2;

		stack2.add(2.213);
		stack2.add(2135.324);
		stack2.add(231.23);
		stack2.add(123.22);
		stack2.add(-235.53);
		stack2.output();
		stack2.get();
		stack2.del();
		stack2.del();
		stack2.output();
		stack2.get();

	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}
