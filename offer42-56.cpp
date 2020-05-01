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

//42(2)连续子数组的最大和动态规划法
int getMaxSum(int array1[],int length)
{
	int max = 0;
	int fijiany1 = array1[0];//f（i-1)
	int fi = 0;
	for (int i =1 ; i < length; i++)
	{
		if (fijiany1 < 0)
			fi = array1[i];
		if (fijiany1 > 0)
		{
			fi = fijiany1 + array1[i];
			
		}
		if (max < fi)
			max = fi;
		fijiany1 = fi;
	}
	return max;
}
//431-n整数中1出现的次数
int NumberOfBeteen1toN(unsigned int n)
{
	int number = 0;
	for (unsigned int i = 1; i <= n; ++i)
	{
		number += NumberOf(i);
	}
	return number;
}
int NumberOf(unsigned int n)
{
	int number = 0;
	while (n)
	{
		if (n % 10 == 1)
			number++;
		n = n / 10;
	}
	return number;
}
//43-2未完成
//int NumberOfI(const char* strN)
//{
//	if (!strN || *strN < 0 || *strN>'9' || *strN == '\0')
//		return 0;
//	int first = *strN - '0';
//	unsigned int length = static_cast<unsigned int>;
//}
//44数字序列中某一位的数字
//int digitAtIndex(int Index)
//{
//	2351
//	int digitsum = 10;
//	int digita = 1;
//	while (true)
//	{
//		
//		digitsum =   9*pow(10,digita);
//		if (Index < digitsum)
//			return digitA(Index, digita);
//		Index -= digita * digitsum;
//		digita++;
//	}
//	第一步找到所在的位数
//	                
//	return -1;
//}
//int digitA(int index, int digits)
//{
//	int number = pow(10, digits - 1) - index / digits;
//	int indexFromRight = digits - index % digits;
//	int index = digits - index % digits;
//}
////45b把数组排成最小的数
//const int MaxNumberLength = 10;
//char* g_StrCombine1 = new char[MaxNumberLength * 2 + 1];
//char* g_StrCombine2= new char[MaxNumberLength * 2 + 1];
//{
//
//}
//int compare(const void* strNumber, const void* strNumber2)
//{
//	strcpy(g_StrCombine1, *(const char**)strNumber);
//}
//46把数字翻译成字符串
int GetTranslation(const string& number)
{
	int length = number.length();
	int* counts = new int[length];
	int count = 0;
	for (int i = length - 1; i >= 0; --i)
	{
		count = 0;
		if (i < length - 1)
			count = counts[i + 1];
		else
			count = 1;
		if (i < length - 1)
		{
			int digit1 = number[i] - '0';
			int digit2 = number[i + 1] - '0';
			int converted = digit1 * 10 + digit2;
			if (converted >= 10 && converted <= 25)
			{
				if (i < length - 2)
					count += counts[i + 2];
				else
					count += 1;
			}
		}
		counts[i] = count;

	}
	count = counts[0];
	delete[] counts;
	return count;
}
//47礼物的最大价值(1)动态规划

int getMaValue_Solution(const int* values, int rows, int cols)
{
	if(values == nullptr)
		return 0;

	int** MaxValues = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		MaxValues[i] = new int[cols];
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int left = 0;
			int up = 0;
			if (i > 0)
				up = MaxValues[i - 1][j];
			if (j > 0)
				left = MaxValues[i][j - 1];
			MaxValues[i][j] = std::max(left, up) + values[i * cols + j];
		}	
	}
	int maxValue = MaxValues[rows - 1][cols - 1];
	for (int i = 0; i < rows; ++i)
	{
		delete[] MaxValues[i];
	}
	delete[] MaxValues;
	return maxValue;
}
//(2)
int getMaValue_Solution2(const int* values, int rows, int cols)
{
	if (values == nullptr)
		return 0;

	int* MaxValues = new int [cols];
	
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int left = 0;
			int up = 0;
			if (i > 0)
				up = MaxValues[j];
			if (j > 0)
				left = MaxValues[j - 1];
			MaxValues[j] = std::max(left, up) + values[i * cols + j];
		}
	}
	int maxValue = MaxValues[cols - 1];

	delete[] MaxValues;
	return maxValue;
}
//48最长不含重复字符的子字符串
int longestSubstringWithoutDuplication(const string& str)
{
	int curLength = 0;
	int maxLength = 0;
	int* position = new int[26];
	for (int i = 0; i < 26; i++)
	{
		position[i] = -1;//每个字符的位置

	}
	for (int i = 0; i < str.length(); ++i)
	{
		int prevIndex = position[str[i] - 'a'];
		if (prevIndex<0 || i - prevIndex>curLength)
			++curLength;
		else
		{
			if (curLength > maxLength)
				maxLength = curLength;
			curLength = i - prevIndex;
		}
		position[str[i] - 'a'] = i;
		if (curLength > maxLength)
			maxLength = curLength;

		delete[] position;
		return maxLength;
	}
}
//
//int longestSubstringWithoutDuplication(const string& str)
//{
//	int curLength = 0;
//	int maxLength = 0;
//	int* position = new int[26];
//	for (int i = 0; i < 26; i++)
//	{
//		position[i] = -1;
//	}
//	for (int i = 0; i < str.length(); i++)
//	{
//		int prevIndex = position[str[i] - 'a'];
//		if (prevIndex <= 0 || i - prevIndex > curLength)
//			++curLength;
//		else
//		{
//			if (curLength > maxLength)
//				maxLength = curLength;
//			curLength = i - prevIndex;
//		}
//	}
//}
//49丑数
int GetUglyNumber(int index)
{
	int* pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyindex = 1;
	int* pMultiply2 = pUglyNumbers;
	int* pMultiply3 = pUglyNumbers;
	int* pMultiply5 = pUglyNumbers;

	while (nextUglyindex < index)
	{
		int Mmin = min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumbers[nextUglyindex] = Mmin;
		while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyindex])
			++pMultiply2;
		while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyindex])
			++pMultiply3;
		while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyindex])
			++pMultiply5;
		++nextUglyindex;
	}
	int ugly = pUglyNumbers[nextUglyindex - 1];
	delete[] pUglyNumbers;
	return ugly;
}
//50 第一个只出现一次的字符
//
char FirstNotRepeatingChar(char* pString)
{
	if (pString == nullptr)
		return '\0';
	const int tableSize = 256;
	unsigned int hashtable[tableSize];
	for (unsigned int i = 0; i < tableSize; ++i)
	{
		hashtable[i] = 0;
	}
	char* pHashKey = pString;
	while (*(pHashKey) != '\0')
		hashtable[*(pHashKey++)]++;
	pHashKey = pString;
	while (*(pHashKey) != '\0') 
	{
		if (hashtable[*pHashKey] == 1)
			return *pHashKey;
	}
	return '\0';

}
//46-5z字符流中第一个只出现一次的字符
class CharStatistics
{
public:
	CharStatistics() :index(0)
	{
		for (int i = 0; i < 256; ++i)
			{
			occurrence[i] = -1;
			}
	}
	void Insert(char ch)
	{
		if (occurrence[ch] == -1)
			occurrence[ch] = index;
		else if (occurrence[ch] >= 0)
			occurrence[ch] = -2;
	}
	char FistApperingOnce()
	{
		char ch = '\0';
		int minIndex = numeric_limits<int>::max();
		for (int i = 0; i < 256 ; ++i)
		{
			if (occurrence[i] >= 0 && occurrence[i] < minIndex)
			{
				ch = (char)i;
				minIndex = occurrence[i];
			}
		}
	}
private:
	int occurrence[256];
	int index;

};
////归并排序
///**
//	 * 归并排序
//	 *
//	 * @param array
//	 * @return
//	 */
//  int[] MergeSort(int[] array) 
// {
//	if (array.length < 2) return array;
//	int mid = array.length / 2;
//	int[] left = Arrays.copyOfRange(array, 0, mid);
//	int[] right = Arrays.copyOfRange(array, mid, array.length);
//	return merge(MergeSort(left), MergeSort(right));
//}
///**
// * 归并排序——将两段排序好的数组结合成一个排序数组
// *
// * @param left
// * @param right
// * @return
// */
//  int[] merge(int[] left, int[] right)
//  {
//	int[] result = new int[left.length + right.length];
//	for (int index = 0, i = 0, j = 0; index < result.length; index++) {
//		if (i >= left.length)
//			result[index] = right[j++];
//		else if (j >= right.length)
//			result[index] = left[i++];
//		else if (left[i] > right[j])
//			result[index] = right[j++];
//		else
//			result[index] = left[i++];
//	}
//	return result;
//}

//51数组中的逆序对
//52两个链表的第一个公共节点
struct ListNode
{
	int m_nKey;
	ListNode* M_pNext;
};
ListNode* FindeCommenNode(ListNode* pHead1, ListNode* pHead2)
{
	unsigned int nLength1 = GetListLength(pHead1);
	unsigned int nLength2 = GetListLength(pHead2);
	int nLengthDif = nLength1 - nLength2;
	ListNode* pListHeadLong = pHead1;
	ListNode* pListHeadShort = pHead2;
	if (nLength2 > nLength1)
	{
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
	}
	for (int i = 0; i < nLengthDif; ++i)
	{
		pListHeadLong = pListHeadLong->M_pNext;
	}
	while ((pListHeadLong != nullptr) && (pListHeadShort != nullptr) && (pListHeadLong != pListHeadShort))
	{
		pListHeadLong = pListHeadLong->M_pNext;
		pListHeadShort = pListHeadShort->M_pNext;
	}
	ListNode* pCommentNode = pListHeadLong;
	return pCommentNode;
}
unsigned int GetListLength(ListNode* pHead)
{
	unsigned int length = 0;
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		++length;
		pNode = pNode->M_pNext;
	}
	return length;
}
struct BinaryTreeNode {

	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;

};
//二分查找算法

//54e二叉搜索树的dik大个节点
BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, unsigned int k)
{
	if (pRoot == nullptr || k == 0)
		return nullptr;
	return KthNodeCore(pRoot, k);
}
BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, unsigned int& k)
{
	BinaryTreeNode* target = nullptr;
	if (pRoot->m_pLeft != nullptr)
		target = KthNodeCore(pRoot->m_pLeft, k);
	if (target == nullptr)
	{
		if (k == 1)
			target == pRoot;
		k--;
	}
	if (target == nullptr && pRoot->m_pRight != nullptr)
		target = KthNodeCore(pRoot->m_pRight, k);
	return target;
}
int binarySearch(int* arr, int low, int high, int target)//递归实现
{
	int middle = (low + high) / 2;
	if (low > high)
		return -1;
	if (arr[middle] == target)
		return middle;
	if (arr[middle] > target)
		return binarySearch(arr, low, middle - 1, target);
	if (arr[middle] < target)
		return binarySearch(arr, middle + 1, high, target);
}

int binarySearch1(int a[], int n, int target)//循环实现
{
	int low = 0, high = n, middle;
	while (low < high)
	{
		middle = (low + high) / 2;
		if (target == a[middle])
			return middle;
		else if (target > a[middle])
			low = middle + 1;
		else if (target < a[middle])
			high = middle;
	}
	return -1;
};

//53在排序数组中查找数字  找到第一个k，找到最后一个k
int GetFirstK(int* data, int length, int k, int start, int end)
{
	if (start > end)
		return -1;
	int middleIndex = (end + start) / 2;
	int middleData = data[middleIndex];

	if (data[middleIndex] == k)
	{
		if (middleIndex > 0 && data[middleIndex - 1] != k||middleIndex == 0)
			return middleIndex;
		else
			end = middleIndex - 1;
	}
	else if (middleData > k)
		end = middleIndex - 1;
	else 
	{
		start = middleIndex + 1;
	}
	return GetFirstK(data, length, k, start, end);
}
//int GetLastk(int* data, int length, int k, int start, int end)
//0-n-1中
int GetMissingNumber(int* data, int length,int start,int end)
{
	int start = 0;
	int end = length - 1;
	
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (data[mid] != mid)
		{
			if (mid == 0 || data[mid - 1] == mid - 1)
				return mid;
			else
				end = mid + 1;
		}
		else
			start = mid + 1;
	}
	if (start == length)
		return -1;
	return -1;
}

//54二叉搜索树的第k个大节点//中序遍历
int BinaryTreeDeth(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	int left = BinaryTreeDeth(pRoot->m_pLeft);
	int right = BinaryTreeDeth(pRoot->m_pRight);
	return (left > right) ? (left + 1) : (right + 1);
}
//55只遍历一次判断是否平衡二叉树
bool IsBalanced(BinaryTreeNode* pRoot)
{
	int depth = 0;
	return IsBalanced(pRoot, &depth);
}
bool IsBalanced(BinaryTreeNode* pRoot, int* pDepth)
{
	if (pRoot == nullptr)
	{
		*pDepth = 0;
		return true;
	}
	int left, right;
	if (IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right) ? left : right;
			return false;
		}
	}
	return false;
}
//56数组中数字出现的次数
void FindNumsApperOnce(int data[], int length, int* num1, int* num2)
{
	if (data == nullptr || length < 2)
		return;
	int resultExclusiveOR = 0;
	for (int i = 0; i < length; ++i)
	{
		resultExclusiveOR ^= data[i];
	}
	unsigned int indexOf1 = FindFirstBitIs(resultExclusiveOR);

	*num1 = *num2 = 0;
	for (int j = 0; j < length; ++j)
	{
		if (IsBit1(data[j], indexOf1))
			*num1 ^= data[j];
		else
			*num2 ^= data[j];
	}
}
unsigned int FindFirstBitIs(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}
bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);

}
