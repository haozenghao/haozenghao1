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
#include <list>
using namespace std;

//60-2基于循环求筛子点数
int g_maxValue = 6;
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
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
		}
		flag = 1 - flag;
	}
	double total = pow((double)g_maxValue, number);
	for (int i = number; i <= g_maxValue * number; ++i)
	{
		double ratio = (double)pProbabilities[flag][i] / total;
		printf("%d%e\n", i, ratio);
	}
	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
	return;
}
int compare(const void* arg1, const void* arg2)
{
	return *(int*)arg1 - *(int*)arg2;
}
//61扑克牌中的顺子
bool IsContinue(int* numbers,int length)
{
	//sort(numbers, numbers + length);
	qsort(numbers, length, sizeof(numbers[0]),compare);
	for (int i = 0; i < length; i++)
		cout << numbers[i];
	int numberOf0 = 0;
	int numberOfGrap = 0;
	for (int i = 0; i < length && numbers[i] == 0; i++)
	{
		numberOf0++;
		
	}
	for (int i = 0; i < length ; i++)
	{
		if (i > 0 && numbers[i] - numbers[i - 1] == 0)
			return false;
		if (i > 0 && numbers[i] - numbers[i - 1] >= 0)
			numberOfGrap += numbers[i] - numbers[i - 1];
	}
	
	return (numberOfGrap > numberOf0) ? false : true;

}

//62圆圈中最后剩下的数字
int LastRemainNUM(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for (int i = 2; i <= n; i++)
	{
		last = (last + m) % i;
	}
	return last;
}
//63股票的最大利润
int MaxDiff(const int* numbers, unsigned length)
{
	if (numbers == nullptr && length < 2)
		return 0;
	int min = numbers[0];
	int maxDiff = numbers[1] - min;
	for (int i = 2; i < length; ++i)
	{
		if (numbers[i - 1] < min)
			min = numbers[i - 1];
		int currentDiff = numbers[i] - min;
		if(currentDiff > maxDiff)
			maxDiff = currentDiff;
	}
	return maxDiff;
}
//64求1+2+3  n
//（1）构造函数
class Temp
{
public:
	Temp() { ++N; Sum += N; }
	static void Reset() { N = 0; Sum = 0; }
	static unsigned int Getsum() { return Sum; }
private:
	static unsigned int N;
	static unsigned int	Sum;

};
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;
unsigned int Sum_Solution(unsigned int n)
{
	Temp::Reset();
	Temp* a = new Temp[n];
	delete[]a;
	a = nullptr;
	return Temp::Getsum();
}
//(2)
typedef unsigned int(*fun)(unsigned int);
unsigned int Solution3_Teminator(unsigned int n)
{
	return 0;
}
unsigned int Sum_solution3(unsigned int n)
{
	static fun f[2] = { Solution3_Teminator,Sum_solution3 };
	return n + f[!!n](n - 1);
}
//65不用加减城市做加法
int Add(int num1, int num2)
{
	int sum, carry;
	do
	{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
	} while (num2 != 0);
	return num1;
}
//66构建乘积数组
void Multiply(const vector<double>& array1, vector<double>& array2)
{
	int length1 = array1.size();
	int length2 = array2.size();
	if (length1 == length2 && length2 > 1)
	{
		array2[0] = 1;
		for (int i = 1; i < length1; i++)
		{
			array2[i] = array2[i-1] * array1[i - 1];
		}
		double temp = 1;
		for (int i = length1 - 2; i >= 0; --i)
		{
			temp *= array1[i + 1];
			array2[i] *= temp;
		}
		
	}

}
//67字符串转化为整数
enum Status { kValid = 0, kInvalid };
int g_nStatus = kValid;
int StrToInt(const char* str)
{
	g_nStatus = kInvalid;
	long long num = 0;
	if (str != nullptr && *str != '\0')
	{
		bool minus = false;
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			str++;
			minus = true;
		}
		if (*str != '\0')
		{
			num = StrToIntCore(str, minus);
		}
	}
	return (int)num;
}
long long StrToIntCore(const char* digit, bool minus)
{
	long long num = 0;
	while (*digit != '/0')
	{
		if (*digit >= '0' && *digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num=num*10+flag*(*digit-'0');
			if (!minus && num > 0x7FFFFFFF || (minus && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			digit++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	if (*digit == '\0')
	{
		g_nStatus = kValid;
	}
	return num;
}
//68树中两个节点的最低公共祖先
struct TreeNode
{
	int                       m_nValue;
	std::vector<TreeNode*>    m_vChildren;
};
bool GetNodePath(const TreeNode* pRoot, const TreeNode* pNode, list<const TreeNode*>& path)
{
	if (pRoot == pNode)
		return true;

	path.push_back(pRoot);

	bool found = false;

	vector<TreeNode*>::const_iterator i = pRoot->m_vChildren.begin();
	while (!found && i < pRoot->m_vChildren.end())
	{
		found = GetNodePath(*i, pNode, path);
		++i;
	}

	if (!found)
		path.pop_back();

	return found;
}

const TreeNode* GetLastCommonNode
(
	const list<const TreeNode*>& path1,
	const list<const TreeNode*>& path2
	)
{
	list<const TreeNode*>::const_iterator iterator1 = path1.begin();
	list<const TreeNode*>::const_iterator iterator2 = path2.begin();

	const TreeNode* pLast = nullptr;

	while (iterator1 != path1.end() && iterator2 != path2.end())
	{
		if (*iterator1 == *iterator2)
			pLast = *iterator1;

		iterator1++;
		iterator2++;
	}

	return pLast;
}

const TreeNode* GetLastCommonParent(const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2)
{
	if (pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
		return nullptr;

	list<const TreeNode*> path1;
	GetNodePath(pRoot, pNode1, path1);

	list<const TreeNode*> path2;
	GetNodePath(pRoot, pNode2, path2);

	return GetLastCommonNode(path1, path2);
}