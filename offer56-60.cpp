#pragma once
#include<iostream>;
#include <exception>
#include <cstdio>
#include<vector>
#include <stack>
#include <assert.h>
#include <fstream>
#include< algorithm >
#include<set>
using namespace std;
//56s数组中数字出现的字数(1)
void FindNumAppendOnce(int data[], int length, int* num1, int* num2)
{
	if (data == nullptr)
		return;
}
//56(2)
//57和为s的数字
//（1）和为s的两个数字
bool FindIfSumEquals(int data[], int length, int sum, int* num1, int* num2)
{
	bool found = false;
	if (length < 1 || num1 == nullptr || num2 == nullptr)
		return found;
	int ahead = length - 1;
	int behind = 0;
	while (ahead>behind)
	{
		long long curSum = data[ahead] + data[behind];
		if (curSum == sum)
		{
			*num1 = data[behind];
			*num2 = data[ahead];
			found = true;
			break;
		}
		else if (curSum > sum)
			ahead--;
		else
			behind++;
	}
	return found;
} 
//57(2)
void FindContinueSequence(int s)
{
	if (s < 3)
		return;
	int start = 1;
	int end = 2;
	int sum = 3;
	while (end < (s+1)/ 2)
	{
		
		if (sum == sum)
			cout << endl;
		while (sum > s && start < (s + 1) / 2)
		{
			sum -= start;
		start++;
		if (sum = s)
			cout << endl;
		}
		end++;
		sum += end;
	}
}
//58翻转字符串（1）翻转单词顺序
void Reverse(char* pBegin, char* pEnd)
{
	while (pBegin != pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
	}
	pBegin++;
	pEnd--;
}
void ReverseStr(char* pData)
{
	if (pData == nullptr)
		return;
	char* pBegin = pData;
	char* pEnd = pData;
	while (*pEnd!='\0')
	{
		pEnd++;
	}
	pEnd--;
	Reverse(pBegin, pEnd);
	pBegin = pEnd = pData;
	while (*pData != '\0')
	{
		if(*pBegin==' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
	}
}
//58(2)翻转三次
//59 队列的最大值
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> maxInWindows;
	if (num.size() >= size && size >= 1)
	{
		deque<int>index;
		for (unsigned int i = 0; i < size; ++i)
		{
			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			index.push_back(i);
		}
		for (unsigned int i = size; i < num.size(); ++i)
		{
			maxInWindows.push_back(num[index.front()]);
			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			if (!index.empty() && index.front() < (int)(i - size))
				index.pop_front();
			index.push_back(i);
		}
		maxInWindows.push_back(num[index.front()]);
	}
	return maxInWindows;
}
//59(2)队列的最大值
//定义一个队列
template<typename T>class QueueWithMax
{
public:
	QueueWithMax() :currentIndex(0)
	{}
	void push_back(T number)
	{
		while (!maximums.empty() && number >= maximums.back().number)
			maximums.pop_back();
		InternalData internalData = { number,currentIndex };
		data.push_back(InternaData);
		maximums.push_back(InternaData);
		++currentIndex;
	}
	void pop_front()
	{
		if (maximums.empty())
			throw new exception("queue is empty");
		if (maximums.front().inde == data.front().index)
			maximums.pop_front();
		data.pop_front;
	}
	T max() const
	{
		if (maximums.empty())
			throw new exception("ueueu is emtpy")
			return maximums.front().number;
	}
private:
	struct InternaData
	{
		T number;
		int index;
	};
	deque<InternalData> data;
	deque<InternalData> maximums;
	int currentIndex;
};

//60筛子上的点数：把n个筛子扔在地上点数和s输入n打印出su偶有可能出现值得概率公寓6n次幂得总数，和为s得个数为？
//将从n到6n的点数都统计，得到
int g_maxValue = 6;
void GetProbality(int number)
{
	if (number < 1)
		return;
	int maxSum = number * g_maxValue;
	int* pProbabilities = new int[maxSum - number + 1];
	for (int i = number; i <= maxSum; ++i)
	{
		pProbabilities[i - number] = 0;
	}
	Probability(number, pProbabilities);
	int total = std::pow((double)g_maxValue, number);
	for (int i = number; i <= maxSum; ++i)
	{
		
	}
	delete[] pProbabilities;

}

void Probability(int number, int* pProbabilities)
{
	for (int i = 1; i <= g_maxValue; ++i)
	{
		Probability(number, number, i, pProbabilities);
	}
}
void Probability(int original, int current, int sum, int* pProbabilities)
{
	if (current == 1)
		pProbabilities[sum - original]++;
	else
		for (int i = 1; i <= g_maxValue; ++i)
		{
			Probability(original, current - 1, i + sum, pProbabilities);
		}
}
//60-2基于循环求筛子点数
void PrintProbality(int number)
{
	if (number < 1)
		return;
	int* pProbabilities[2];
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];
	for (int i = 0; i < g_maxValue * number + 1; ++i)
	{
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}
	int flag = 0;
	for (int i = 0; i <= g_maxValue; ++i)
	{
		pProbabilities[flag][i] = 1;
	}
	for (int k = 2; k <= number; ++k)
	{
		for (int i = 0; i < k; i++)
		{
		pProbabilities[1 - flag] = 0;
		}
		for (int i = k; i <= g_maxValue * k; ++i)
		{
			pProbabilities[1 - flag][i] = 0;
			for (int j = 1; j <= i && j <= g_maxValue; ++j)
				pProbabilities[1 - flag][i] += pProbabilities[flag][i- j];
		}
	}
}
 