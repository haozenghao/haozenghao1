
#pragma once
#include<iostream>;
#include <exception>
#include <cstdio>
#include<vector>
#include <stack>
#include <assert.h>
#include <fstream>
#include<set>
using namespace std;
//9用两个栈实现队列
template<typename T>class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template<typename T>void CQueue<T>::appendTail(const T& element)
{
    stack1::push(element);
}
template<typename T>T CQueue<T>::deleteHead()
{
    if (stack2.size() <= 0)
    {
        while (stack1.size() > 0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if (stack2.size() == 0)
        throw new exception("queue is empty");
    T head = stack2.pop();
    stack2.pop();

    return head;
}
//11旋转数组的最小数字
int Min(int* numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        throw new std::exception("Invalid para");

    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    while (numbers[index1] >= numbers[index2])
    {
        if (index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;
        if (numbers[indexMid] >= numbers[index1])
            index1 = indexMid;
        else if (numbers[indexMid] <= numbers[index2])
            index2 = indexMid;
    }
   
    return numbers[indexMid];

}
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited);
//12矩阵中的矩阵
//bool hasPath(char* matrix,int rows, int cols,char* str)
//{ 
//    if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
//        return false;
//    bool* visited = new bool[rows * cols];
//    memset(visited, 0, rows * cols);
//
//    int pathLength = 0;
//    for (int row = 0; row < rows; ++row)
//    {
//        for (int col = 0; col < cols; ++col)
//        {
//            if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
//            {
//                return false;
//            }
//        }
//    }
//    delete[] visited;
//    return false;
//}

//12回溯法矩阵中的路径
bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if (matrix == nullptr)
        return false;
    bool* visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);
    int pathLength = 0;
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
            {
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
    if (str[pathLength] == '\0')
        return false;
    bool hasPath = false;
    if (row >= 0 && row < rows && col < cols && col >= 0 && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
    {
        ++pathLength;
        visited[rows * cols + col] = true;
        
        hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
        if (!hasPath)
        {
            --pathLength;
            visited[row * cols + col] = false;
        }
    }
    return hasPath;
}
//int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
////13机器人的运动范围
//int movingCount(int threshold, int rows, int cols)
//{
//    bool* visited = new bool[rows * cols];
//    for (int i = 0; i < rows * cols; ++i)
//    {
//        visited[i] = false;
//    }
//    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
//    delete[] visited;
//    return count;
//}
//int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
//{
//    int count = 0;
//    if (check(threshold, rows, cols, row, col, visited))
//    {
//        visited[row * cols + col] = true;
//        count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
//            + movingCountCore(threshold, rows, cols, row, col - 1, visited)
//            + movingCountCore(threshold, rows, cols, row + 1, col, visited)
//            + movingCountCore(threshold, rows, cols, row, col + 1, visited);
//    }
//    return count;
//}
//bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
//{
//    if (row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row * cols + col])
//        return true;
//
//    return false;
//}
int getDigitSum(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number %  10;
        cout << "sum=" << sum << endl;
        number /= 10;
        cout << "number=" << number << endl;
    }
    return sum;
}
//14剪绳子
int maxProductAfterCuttint_solution(int length)
{
    int* products = new int[length + 1];
    int max = 0;
    for (int i = 4; i <= length; ++i)
    {
        max = 0;
        for (int j = 1; j <= i / 2; ++j)
        {
            int product = products[j] * products[i - j];
            if (max < product)
                max = product;
            products[i] = max;
        }
        max = products[length];
        delete[] products;

        return max;
    }
}

//数值的整数次方
//bool g_InvalidInput = false;
//double Power(double base, int exponent)
//{
//    g_InvalidInput = false;
//    if (equal(base, 0.0) && exponent < 0)
//    {
//        g_InvalidInput = true;
//        return 0.0;
//    }
//    unsigned int absExponent = (unsigned int)(exponent);
//    if (exponent < 0)
//        absExponent = (unsigned int)(-exponent);
//
//     double result = PowerWithUnsignedExponent(base, absExponent);
//    if (exponent < 0)
//        result = 1.0 / result;
//    return result;
//}
//double PowerWithUnsignedExponent(double base, unsigned int exponent)
//{
//    double result = 1.0;
//    for (int i = 1; i < exponent; ++i)
//        result *= base;
//
//    return result;
//}
//double PowerWithUnsignedExponent(double base, unsigned int exponent)
//{
//    if (exponent == 0)
//        return 1;
//    if (exponent == 1)
//        return base;
//    double result = PowerWithUnsignedExponent(base, exponent >> 1);
//    result *= result;
//    if (exponent & 0x1 == 1)
//        result *= base;
//    return result;
//}
//17打印从1到最大的n个数
bool Increment(char* number);
void PrintNumber(char* number);
void PrintToMaxOfNDigits(int n)
{
    if (n <= 0)
        return;
    char* number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '/0';
    while (!Increment(number))
    {
        PrintNumber(number);
    }
    delete[] number;
}

bool Increment(char* number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);
    for (int i = nLength - 1; i >= 0; i--)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
            nSum++;
        if (nSum >= 10)
        {
            if (i == 0)
                isOverflow = true;
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;

            }

        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }

    }
    return isOverflow;
}
void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; ++i)
    {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        if (isBeginning0)
        {
            printf("%c", number[i]);
        }

    }
    printf("\t");
}
//17全排列方法
void PrintToMaxOfNDigitsRecursively(char* number, int length, int index);
void Print1ToMaxOfNDigits(int n)
{
    if (n <= 0)
        return;
    char* number = new char[n + 1];
    number[n] = '/0';
    for (int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        PrintToMaxOfNDigitsRecursively(number, n, 0);
    }
    delete[] number;
}
void PrintToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if (index == length - 1)
    {
        PrintNumber(number);
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        PrintToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}
//单项链表
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
//产出链表中的重复节点18-2
void DeleteDuplication(ListNode** pHead)
{
    if (pHead == nullptr || *pHead == nullptr)
        return;
    ListNode* pPreNode = nullptr;
    ListNode* pNode = *pHead;
    while (pNode != nullptr)
    {
        ListNode* pNext = pNode->m_pNext;
        bool needDelete = false;
        if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
            needDelete = true;
        if (!needDelete)
        {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        }
        else
        {
            int value = pNode->m_nValue;
            ListNode* pToBeDel = pNode;
            while (pToBeDel != nullptr && pToBeDel->m_nValue == value)
            {
                pNext = pToBeDel->m_pNext;
                delete pToBeDel;
                pToBeDel = nullptr;
                pToBeDel = pNext;
                if (pPreNode == nullptr)
                    *pHead = pNext;
                else
                    pPreNode->m_pNext = pNext;
                pNode = pNext;
            }
        }
    }

}
//19正则表达式匹配
bool match(char* str, char* pattern)
{

}
bool matchCore(char* str, char* pattern)
{
    if (*str == '\0' || *pattern == '\0')
        return true;
    if (*str != '\0' && *pattern == '\0')
        return false;
    if (*(pattern + 1) == '*')
    {
        if (*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
        else
            return matchCore(str, pattern + 2);
    }
    if (*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);
    return false;   
}
//20 表示数值的字符串
bool scanUnsignedInteger(const char** str)
{
    const char* before = *str;
    while (**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);
    return *str > before;
}
bool scanInteger(const char** str)
{
    if (**str == '+' || **str == '-')
        ++(*str);
    return scanUnsignedInteger(str);
}
bool isNumberic(const char* str)
{
    if (str == nullptr)
        return false;
    bool numeric = scanInteger(&str);
    if(*str=='.')
    {
        ++str;
        numeric = scanUnsignedInteger(&str) || numeric;
    }
    if (*str == 'e' || *str == 'E')
    {
        ++str;
        numeric = numeric && scanInteger(&str);
    }
    return numeric && *str == '\0';
}

//23连变种环的入口节点
ListNode* MeetingNode(ListNode* pHead)
{
    if (pHead == nullptr)
        return nullptr;
    ListNode* pSlow = pHead->m_pNext;
    if (pSlow == nullptr)
        return nullptr;
    ListNode* pFast = pSlow->m_pNext;
    while (pFast != nullptr&&pSlow!=nullptr)
    {
        if (pFast == pSlow)
            return pFast;
        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext;
        if (pFast != nullptr)
            pFast = pFast->m_pNext;
    }
    return nullptr;
}
//23得到环的节点数目和入口节点
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode* meetingNode = MeetingNode(pHead);
    if (meetingNode == nullptr)
        return nullptr;
    int nodesInLoop = 1;
    ListNode* pNode1 = meetingNode;
    while (pNode1->m_pNext != meetingNode)
    {
        pNode1 = pNode1->m_pNext;
        ++nodesInLoop;
    }
    pNode1 = pHead;
    for (int i = 0; i < nodesInLoop; ++i)
    {
        pNode1 = pNode1->m_pNext;
    }
    ListNode* pNode2 = pHead;
    while (pNode1 != pNode2)
    {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    return pNode1;
}
//24反转链表
ListNode* ReverseList(ListNode* pHead)
{
    if (pHead == nullptr)
        return nullptr;
    ListNode* reverseList = nullptr;
    ListNode* pNode = pHead;
    ListNode* pPrev = nullptr;
    while (pNode->m_pNext != nullptr)
    {
        ListNode* pNext = pNode->m_pNext;
        if (pNext == nullptr)
            reverseList = pNode;
        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return reverseList;
}
//25合并两个排序的链表
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == nullptr)
        return pHead2;
    else if (pHead2 == nullptr)
        return pHead1;
    ListNode* pMergeHead = nullptr;
    if (pHead1->m_nValue < pHead2->m_nValue)
    {
        pMergeHead = pHead1;
        pMergeHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else
    {
        pMergeHead = pHead2;
        pMergeHead->m_pNext = Merge(pHead1, pHead2->m_pNext);

    }
    return pMergeHead;
}
//二叉树
struct BinaryTreeNode
{
    double m_dbValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
//递归遍历二叉树
void PreOrder(BinaryTreeNode* pHead)
{
    if (pHead == nullptr)
        return;
    cout << pHead->m_dbValue << endl;
    PreOrder(pHead->m_pLeft);
    PreOrder(pHead->m_pRight);
}
////非递归遍历二叉树
//void InOrderNonRec(BinaryTreeNode bt)
//{
//    Stack s;
//    BinaryTreeNode p;
//    Initstack s;
//    pushback p;
//
//    while (!Emptystack)
//    {
//        p = topstack(s);
//        while (p != Null)
//        {
//            pushback Lchild;
//            p = topstack;
//        }
//        p = popstack(s);
//        if (!empty s)
//        {
//            p = popstack(s);
//            Visit(p->Data);
//            pushback(s, p - rcild);
//        }
//
//    }
//}
////层次遍历二叉树
//void LevelOrder(BinaryTreeNode* bt)
//{
//    BinaryTreeNode* Queue[20];
//    int front, rear;
//    
//    if (bt == NULL)
//        return;
//    front = 1;
//    rear = 0;
//    Queue[rear] =bt;
//    while (front != rear)
//    {
//        front++;
//        cout << Queue[front]->m_dbValue << endl;
//        if (Queue[front]->m_pLeft != nullptr)
//        {
//            rear++;
//            Queue[rear] = Queue[front]->m_pLeft;
//        }
//        if (Queue[front]->m_pRight != nullptr) 
//        {
//            rear++;
//            Queue[rear] = Queue[front]->m_pRight;
//        }
//    }
//    
//}
//26输入两科二叉树判断b是不是a的子结构
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    bool result = false;
    if (pRoot1 != nullptr && pRoot2 != nullptr)
    {
        if (pRoot1->m_dbValue==pRoot2->m_dbValue)
            result = DoseTree1HaveTree2(pRoot1,pRoot2);
        if (!result)
            HasSubTree(pRoot1->m_pLeft, pRoot2);
        if (!result)
            HasSubTree(pRoot2->m_pRight, pRoot2);
    }
    return result;
}
bool DoseTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if (pRoot2 == nullptr)
        return true;
    if (pRoot1 == nullptr)
        return false;
    if (pRoot1->m_dbValue != pRoot2->m_dbValue)
        return false;
    return DoseTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoseTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}
//27二叉树的镜像
void MirrorBinaryTreeNode(BinaryTreeNode* pHead)
{
    if (pHead == nullptr)
        return;
    if (pHead->m_pLeft == nullptr && pHead->m_pRight == nullptr)
        return;
    BinaryTreeNode* pTemp = pHead->m_pLeft;
    pHead->m_pLeft = pHead->m_pRight;
    pHead->m_pRight = pTemp;
    if (pHead->m_pLeft)
        MirrorBinaryTreeNode(pHead->m_pLeft);
    if (pHead->m_pRight)
        MirrorBinaryTreeNode(pHead->m_pRight);
}
//28p判断二叉树是不是对称的
bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if (pRoot1 == nullptr && pRoot2 == nullptr)
        return true;
    if (pRoot1 == nullptr || pRoot2 != nullptr)
        return false;
    if (pRoot1->m_dbValue != pRoot2->m_dbValue)
        return false;
    return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}
bool isSymmetrical(BinaryTreeNode* pRoot)
{
    return isSymmetrical(pRoot, pRoot);
}

//29顺时针打印矩阵
//void PrintMatrixClockwisely(int** numbers, int columns, int rows)
//{
//    if (numbers == nullptr || columns <= 0 || rows <= 0)
//        return;
//    int start = 0;
//    while (columns > start * 2 && rows > start * 2)
//    {
//        PrintMatrixInCircle(numbers, columns, rows, start);
//        ++start;
//    }
//}
//void PrintMatrixInCircle(int** numbers, int colnums, int rows, int start)
//{
//    int endX = colnums - 1 - start;
//    int endY = rows - 1 - start;
//
//    for (int i = start; i <= endX; ++i)
//    {
//        int number = numbers[start][i];
//        PrintNumber(number);
//    }
//    
//}b
////30包含min函数的栈
//template<typename T> class StackWithMin
//{
//public:
//    StackWithMin();
//    ~StackWithMin();
//    T& top();
//    const   T& top() const;
//    void push(const T& value);
//    void pop();
//
//    const T& min()  const;
//    bool empty() const;
//    size_t size() const;
//
//private:
//    std::stack<T> m_data;
//    std::stack<T> m_min;
//
//};
//template<typename T> void StackWithMin<T>::push(const T& value)
//{
//    m_data.push(value);
//    if (m_min.size() == 0 || value < m_min.top())
//        m_min.push(value);
//    else
//        m_min.push(m_min.top());
//}
//template<typename T> void StackWithMin<T>::pop()
//{
//    assert(m_data > 0 && m_min.size() > 0);
//    m_data.pop();
//    m_min.pop();
//}
//template<typename T> const T& StackWithMin<T>::min() const
//{
//    assert(m_data.size() > 0 && m_min.size() > 0);
//    return m_min.top();
//}
//StackWithMin::StackWithMin()
//{
//    
//}
//
//StackWithMin::~StackWithMin()
//{
//}
//31压入，弹出序列
bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
    bool bPossible = false;
    if (pPush != nullptr && pPop != nullptr && nLength > 0)
    {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;

        std::stack<int>stackData;
        while (pNextPop - pPop < nLength)
        {
            while (stackData.empty() || stackData.top() != *pNextPop)
            {
                if (pNextPush - pPush == nLength)
                    break;
                stackData.push(*pNextPush);
                pNextPush++;
            }
            if (stackData.top() != *pNextPop)
                break;
            pNextPop++;
        }
        if (stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }
    return bPossible;
}
//33层次遍历

template<typename T>class Queue 
{
public:
    void push(const T& node);
    T pop();
    
private:
    stack<T> stack1;
    stack<T> stack2;
};
template<typename T> void Queue<T>::push(const T& node)
{
    stack1.push(node);
}
template<typename T> T Queue<T>::pop()
{
    if (stack2.size() <= 0)
    {
        while (stack1.size() > 0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if (stack2.size() == 0)
        throw new exception("queue is empty");
    T head = stack2.pop();
    stack2.pop();
    return head;
}   
//32层次遍历
void printFromTopToBottom(BinaryTreeNode* pHead)
{
    std::deque<BinaryTreeNode*> dequeTree;
    if (pHead == nullptr)
        return;
    dequeTree.push_back(pHead);
    while (dequeTree.size())
    {
        BinaryTreeNode* pNode = dequeTree.front();
        dequeTree.pop_front();
        printf("%d", pNode->m_dbValue);
        if (pNode->m_pLeft)
            printFromTopToBottom(pNode->m_pLeft);
        if (pNode->m_pRight)
            printFromTopToBottom(pNode->m_pRight);
    }
}
//32(2)
void Print(BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr)
        return;
    std::deque<BinaryTreeNode*> nodes;
    nodes.push_back(pRoot);
    int nextLevel = 0;
    int toBePrinted = 1;
    while (!nodes.empty())
    {
        BinaryTreeNode* pNode = nodes.front();
        printf("%d", pNode->m_dbValue);
        if (pNode->m_pLeft != nullptr)
        {
            nodes.push_back(pNode->m_pLeft);
            ++nextLevel;
        }
        if (pNode->m_pRight != nullptr)
        {
            nodes.push_back(pNode->m_pRight);
            ++nextLevel;
        }
        nodes.pop_back();
        --toBePrinted;
        if (toBePrinted == 0)
        {
            printf("\n");
            toBePrinted = nextLevel;
            nextLevel = 0;
        }
    }

}
//32(3)
void Print(BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr)
        return;
    std::stack<BinaryTreeNode*>levels[2];
    int current = 0;
    int next = 1;

    levels[current].push(pRoot);
    while (!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode* pNode = levels[current].top();
        levels[current].pop();

        printf("%d", pNode->m_dbValue);
        if (current == 0)
        {
            if (pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
            if (pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
        }
        else
        {
            if(pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
            if (pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
        }
        if (levels[current].empty())
        {
            printf("\n");
            current = 1 - current;
            next = 1 - next;

        }
    }
}
//33二叉搜索树的后序遍历序列
bool VerifySquencOfBST(int sequence[], int length)
{
    if (sequence == nullptr || length < 0)
        return false;
    int root = sequence[length - 1];

    int i = 0;//在二叉搜索树中左节点的值小于根节点的值
    for (; i < length - 1; ++i)
    {
        if (sequence[i] > root)//此时i为序列的右节点的开始
            break;
    }
    int j = i;//此时i为序列的右节点的开始
    for (; j < length - 1; ++j)
    {
        if (sequence[j] < root)//若右子树中有节点的值小于根节点则false
            return false;
    }
    bool left = true;
    if (i > 0)
        left = VerifySquencOfBST(sequence, i);
    bool right = true;
    if (i < length - 1)
        right = VerifySquencOfBST(sequence + i, length - i - 1);
    return (left & right);
}

//34二叉树中和为某一值的路径
void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
    if (pRoot == nullptr)
        return;
    std::vector<int> path;
    int currentSum = 0;
    FindPath(pRoot, expectedSum, path, currentSum);
}
void FindPath(BinaryTreeNode* pRoot,int expectedSum,vector<int>path,int currentSum)
{
    currentSum += pRoot->m_dbValue;
    path.push_back(pRoot->m_dbValue);
    //如果是叶节点并且路径上节点值的 和等于输入的值
   
    if (pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr && currentSum == expectedSum)
    {
        printf("ok");
        std::vector<int>::iterator iter = path.begin();
        for (; iter != path.end(); ++iter)
        {
            printf("%d\t", *iter);            
        }
    }
    if (pRoot->m_pLeft != nullptr)
    {
        FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
    }
    if (pRoot->m_pRight != nullptr)
    {
        FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
    }
    path.pop_back();
}
//void GetPath(BinaryTreeNode* pRoot,int expectedSum)
//{
//    if (pRoot == nullptr)
//        return;
//    vector<int> path;
//    int currentSum = 0;
//     FindPath(pRoot, expectedSum,path, currentSum);
//}
//void FindPath(BinaryTreeNode* pRoot, int expectedSum ,vector<int>& path,int currentSum)
//{
//   
//    currentSum = pRoot->m_dbValue + currentSum;
//    path.push_back(pRoot->m_dbValue);
//    bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
//    if(currentSum==expectedSum&&isLeaf)
//    {
//        printf("AP");
//        vector<int>::iterator iter = path.begin();
//        for (iter; iter != path.end(); iter++)
//        {
//            printf("\t", *iter);
//        }
//        printf("\n");
//
//    }
//    if (pRoot->m_pLeft != nullptr)
//    {
//        FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
//    }
//    if(pRoot->m_pRight!=nullptr)
//    
//     FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
//
//   
//}
//35复杂链表的复制
struct ComplexListNode 
{
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};
//第一步复制链表
void CloneNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while (pHead != nullptr)
    {
        ComplexListNode* temp = new ComplexListNode();
        temp->m_nValue = pNode->m_nValue;
        temp->m_pNext = pNode->m_pNext;
        temp->m_pSibling = nullptr;

        pNode->m_pNext = temp;
        pNode = temp->m_pNext;
    }
}
//连接temp链表
void ConnectedSiblingNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while (pHead->m_pNext != nullptr)
    {
        ComplexListNode* ClonedList = pHead->m_pNext;
        if (pNode->m_pSibling != nullptr)
        {
            ClonedList->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        pNode = ClonedList->m_pNext;
    }
}
// 分成两个链表C
ComplexListNode* ReconnectedList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = nullptr;
    ComplexListNode* pClonedNode = nullptr;

    if (pNode != nullptr)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    while (pNode != nullptr)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode->m_pNext = pClonedHead->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
    }

    return pClonedHead;
}
ComplexListNode* Clone(ComplexListNode* pHead)
{
    CloneNodes(pHead);
    ConnectedSiblingNodes(pHead);
    return ReconnectedList(pHead);
}
//36二叉搜索树与双向链表
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode* pLastNodeInList = nullptr;
    ConvertNode(pRootOfTree, &pLastNodeInList);

    BinaryTreeNode* pHeadOfList = pLastNodeInList;
    while (pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
        pHeadOfList = pHeadOfList->m_pLeft;
    return pHeadOfList;
}
void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInlist)
{
    if (pNode == nullptr)
        return;
  //  BinaryTreeNode
}
//37 序列化二叉树 
bool ReadStream(istream& stream, int* number)
{
    if (stream.eof())
        return false;

    char buffer[32];
    buffer[0] = '\0';

    char ch;
    stream >> ch;
    int i = 0;
    while (!stream.eof() && ch != ',')
    {
        buffer[i++] = ch;
        stream >> ch;
    }

    bool isNumeric = false;
    if (i > 0 && buffer[0] != '$')
    {
        *number = atoi(buffer);
        isNumeric = true;
    }

    return isNumeric;
}
void Deserialize(BinaryTreeNode** pRoot, istream& stream)
{
    int number;
    if (ReadStream(stream, &number))
    {
        *pRoot = new BinaryTreeNode();
        (*pRoot)->m_dbValue = number;
        (*pRoot)->m_pLeft = nullptr;
        (*pRoot)->m_pRight = nullptr;
               
    }
}
//38字符串的排列
void Permutation(char* pStr)
{
    if (pStr == nullptr)
        return;
   
    Permutation(pStr, pStr);
}
void Permutation(char* pStr, char* pBegin)
{
    if (*pBegin == '/0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            Permutation(pStr, pBegin+1);

            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}//39数组中出现次数()超过一半的数字
//int MoreThanHalfNum(int* numbers, int length)
//{
//    if (numbers == nullptr || length == 0)
//        return 0;
//    int middle = length >> 1;
//    int start = 0;
//    int end = length - 1;
//    int index = Patition(numbers, length, start, end);
//    while (index != middle)
//    {
//        if (index > middle)
//        {
//            end = index - 1;
//            index = Patition(numbers, length, start, end);
//        }
//        if (index < middle)
//        {
//            start = index + 1;
//            index = Patition(numbers, length, start, end);
//        }
//    }
//    int result = numbers[middle];
//    if (0)//p判断result出现的次数*2是否大于=length
//        result = 0;
//    return result;
//}
//int  Patition(int numbers[], int length, int start, int end)
//{
//    if (numbers== nullptr || length == 0)
//        throw new std::exception("Invalid Parameters");
//    int index = RandomInRange(start, end);
//    swap(numbers[index], numbers[end]);
//    int small = start - 1;
//    for (index = start ; index < end; ++index)
//    {
//        if (numbers[index] < numbers[end])
//        {
//            ++small;
//            if (small != index)
//                swap(numbers[index], numbers[small]);
//        }
//    }
//    small++;
//    swap(numbers[small], numbers[end]);
//    return small;
//}
//39-2
int moreThanHalfNum(int* numbers, int length)
{
    int result = numbers[0];
    int times = 1;
    for (int i = 1; i < length; i++)
    {
        if (times = 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if (numbers[i] = result)
            times++;
        else
            times--;
    }
   // if (0)//p判断result出现的次数*2是否大于=length
//        result = 0;
    return result;
}
//40最小的k个数(2)
//用红黑树实现的STL中的set和multiset来实现include<set>
typedef multiset<int, greater<int>> inSet;//greater是从大到小
typedef multiset<int, greater<int>>::iterator setIterator;
void GetLeastNumbers(const vector<int>& data, inSet& leastNumbers, int k)
{
    leastNumbers.clear();
    if (k < 1 || data.size() < k)
        return;
    vector<int>::const_iterator iter = data.begin();
    for (; iter < data.end(); ++iter)
    {
        if (leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else
        {
            setIterator iterGreatest = leastNumbers.begin();
            if (*iter < *(leastNumbers.begin()))
            {
                leastNumbers.erase(iterGreatest);//删除最大的插入当前值
                leastNumbers.insert(*iter);
            }
        }
    }
}
////41数据流中的中位数
////实现最大堆和最小堆i0000000000000
//template<typename T>class DynamicArray
//{
//public:
//    void Insert(T num)
//    {
//        if (((min.size() + max.size()) & 1) == 0)//奇数
//        {
//            if (max.size() > 0 && num < max[0])
//            {
//                max.push_back(num);
//                push_heap(max.begin(), max.end(), less<T>());
//
//                num = max[0];
//                pop_heap(max.begin(), max, end(), less<T>());
//                max.pop_back();
//            }
//            min.push_back(num);
//        }
//    }
//    T getMedian()
//    {
//    }
//private:
//    vector<T> min;
//    vector<T> max;
//};
