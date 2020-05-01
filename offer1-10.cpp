#include<iostream>;
using namespace std;
#include <exception>
#include <cstdio>
//#include<main.h>

//3数组中重复的数字
bool duplicate(int numbers[], int length, int* duplication)
{
    if (numbers == nullptr || length <= 0)
    {
        return false;
    }
    for (int i = 0; i < length; i++)
    {
        if (numbers[i]<0 || numbers[i]>length - 1)
            return false;
    }
    for (int i = 0; i < length; i++)
    {
        while (numbers[i] != i)
        {
            if (numbers[i] = numbers[numbers[i]])
            {
               * duplication = numbers[i];
                return true;
            }
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;

        }

    }
    return false;
}
//（2）
int countRange(const int* numbers, int length, int start, int end)
{
    if (numbers = nullptr)
        return 0;
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] >= start && numbers[i] <= end)
            ++count;
    }
    return count;
}
int getDuplication(const int* numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        return -1;
    int start = 1;
    int end = length - 1;
    while (end >= start)
    {
        int middle = ((end - start) >> 1) + start;
        int count = countRange(numbers, length, start, middle);
            if (end == start)
            {
                if (count > 1)
                    return start;
                else
                    break;
            }
            if (count > (middle - start + 1))
                end = middle;
            else
                start = middle + 1;
    }
    
    return -1;

}
//4二维数组中的查找
bool find(int *numbers, int rows, int cols, int number)
{
    bool found = false;
    if (numbers == nullptr||number<numbers[0])
        return false;
    int i = 0;
    int j = cols - 1;
    while (i < rows && j >= 0)
    {
        if(numbers[i*cols+j]=number)
        {
            found = true;
            break;
        }
        else if (numbers[i * cols + j] >number)

        {
            --j;
        }
        else
        {

        }

    }


}
//面试题5替换空格
void ReplaceBlank(char string[], int length)
{
    if (string == nullptr || length == 0)
        return;
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (string[i] != '/0')
    {
        ++originalLength;
        if (string[i] = ' ')
            ++numberOfBlank;
        ++i;
    }
    int newLength = originalLength + numberOfBlank * 2;
    if (newLength > length)
        return;
    int indexOfOirginal = originalLength;
    int indexOfnew = newLength;
    while (indexOfOirginal >= 0 && indexOfnew > indexOfOirginal)
    {
        if (string[indexOfOirginal] = ' ')
        {
            string[indexOfnew--] = '0';

        }
        else
        {
            string[indexOfnew--] = string[indexOfOirginal];

        }
        --indexOfOirginal;

    }

}
//6
//单项链表
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
//添加链表节点
void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = nullptr;
    if (*pHead = nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while (pNode->m_pNext != nullptr)
            pNode = pNode->m_pNext;
        pNode->m_pNext = pNew;
    }
}
void addtotail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = nullptr;
    if (*pHead == nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while (pNode->m_pNext != nullptr)
            pNode = pNode->m_pNext;

        pNode->m_pNext = pNew;

    }
}
//删除含有某个直的节点面试题6之前
void RemoveNode(ListNode** pHead, int value)
{
    if (pHead == nullptr || *pHead == nullptr)
        return;
    ListNode* pToBeDeleted = nullptr;
    if ((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode = *pHead;
        while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
            pNode = pNode->m_pNext;
        if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
            pToBeDeleted = pNode->m_pNext;
        pNode->m_pNext = pNode->m_pNext->m_pNext;

    }
    if (pToBeDeleted != nullptr)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;

    }
}

////面试题6，从尾到头打印链表
//void PrintListReversingly_Iteratively(ListNode* pHead)
//{
//    std::stack<ListNode*> nodes;
//    ListNode* pNode = pHead;
//    while (pNode != nullptr)
//    {
//        nodes.push(pNode);
//        pNode = pNode->m_pNext;
//    }
//    while (!nodes.empty())
//    {
//        pNode = node.top();
//        printf("%d\t", pNode->m_nValue)
//            nodes.pop();
//    }
//}
void PrintListReversingly_RECURSIVELY(ListNode* pHead)
{
    if (pHead != nullptr)
    {
        if (pHead->m_pNext != nullptr)
        {
            PrintListReversingly_RECURSIVELY(pHead->m_pNext);

        }
        printf("\t%d", pHead->m_nValue);
    }
}
//7树
struct BinaryTreeNode {

    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pParent;

};
//二叉树递归遍历(自己 写的)
void   PreOrder__(BinaryTreeNode* bt)
{
    if (bt == NULL)
        return;
    printf("%d", bt->m_nValue);
    PreOrder__(bt->m_pLeft);
    PreOrder__(bt->m_pRight);
}
BinaryTreeNode* ConstructCore
(
    int* startPreorder, int* endPreorder,
    int* startInorder, int* endInorder
    );
//7重建二叉树
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if (preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;
    return ConstructCore(preorder, preorder + length - 1,inorder,inorder+length+1);
}
BinaryTreeNode* ConstructCore(
    int* startPreorder, int* endPreorder,
    int* startInorder, int* endInorder )
{
    // 前序遍历序列的第一个数字是根结点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            throw std::exception("Invalid input.");
    }

    // 在中序遍历中找到根结点的值
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;

    if (rootInorder == endInorder && *rootInorder != rootValue)
        throw std::exception("Invalid input.");

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0)
    {
        // 构建左子树
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
            startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder)
    {
        // 构建右子树
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
            rootInorder + 1, endInorder);
    }

    return root;
}
void TestConstructCore()
{
    int preorder[8] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int inorder[8] = { 4, 7, 2, 1, 5, 3, 8, 6 };

    

    printf("The preorder sequence is: ");
    for (int i = 0; i < 8; ++i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for (int i = 0; i < 8; ++i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, 8);
        PreOrder__(root);

       // DestroyTree(root);
    }
    catch (std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}
//8二叉树的下一个节点
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if (pNode == nullptr)
        return nullptr;
    BinaryTreeNode* pNext = nullptr;
    if (pNode->m_pRight != nullptr)
    {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while (pRight->m_pLeft != nullptr)
        {
            pRight = pRight->m_pLeft;     
        }
        pNext = pRight;
    }
    else if (pNode->m_pParent != nullptr)
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while (pParent != nullptr && pCurrent == pParent->m_pRight)//如果节点是右节点
        {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        pNext = pParent;

    }
    return pNext;
}
////9用两个栈实现队列
//template<typename T>class CQueue
//{
//public:
//    CQueue(void);
//    ~CQueue(void);
//    void appendTail(const T& node);
//    T deleteHead();
//private:
//    stack<T> stack1;
//    stack<T> stack2;
//};
//
//template<typename T>void CQueue<T>::appendTail(const T& element)
//{
//    stack1::push(element);
//}
//template<typename T>T CQueue<T>::deleteHead()
//{
//    if (stack2.size() <= 0)
//    {
//        while (stack1.size() > 0)
//        {
//            T& data = stack1.top();
//            stack1.pop();
//            stack2.push(data);
//        }
//    }
//    if (stack2.size() == 0)
//        throw new exception("queue is empty");
//    T head = stack2.pop();
//    stack2.pop();
//
//    return head;
//}

//10实现斐波那契数列
int Fibonacci(int n)
{
    int all = 0;
    int alln1 = 1;
    int alln2 = 0;
    for (int i = 2; i < n; n++)
    {

        all = alln1 + alln2;
        alln1 = all;
        alln2 = alln1;
    }
    return all;
}
//查找和排序之快速排序
//int Partition(int data[], int length, int start, int end)
//{
//    if (data==nullptr)
//        return;
//    int index=RandomInRange(start,end);
//    Swap(&data[index], &data[end]);
//    
//    int small = start - 1;
//    for (index = start; index < end; ++index)
//    {
//        if (data[index] < data[end])
//        {
//            ++small;
//            if (small != index)
//                Swap(&data[index], &data[small]);
//        }
//    }
//    ++small;
//    Swap(&data[small], &data[end]);
//
//    return small;
//}
///快速排序
//int Partition(int data[], int length, int start, int end)
//{
//    if (data == nullptr || length < 0 || start < 0 || end >= length)
//        throw new std::exception("INVALID,PARAMETERS");
//    
//    int index = RandomInRange(start, end);
//    Swap(&data[index], &data[end]);
//    int small = start - 1;
//    for (index = start; index < end; ++index)
//    {
//        if (data[index] < data[end])
//        {
//            ++small;
//            if (small != index)
//                Swap(&data[index], &data[small]);
//        }
//
//    }
//    ++small;
//    Swap(&data[small], &data[end]);
//    return small;
//}
//快速排序：递归的把小于index的放到左边，大于index的放到右边
//
//void QuickSort(int data[], int length, int start, int end)
//{
//    if (start == end)
//        return;
//    int index = Partition(data, length, start, end);
//    if (index > start)
//        QuickSort(data, length, start, index - 1);
//    if (index < end)
//        QuickSort(data, length, index + 1, end);
//}
void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//排序算法

//选择排序

void selectsort(int arr[],int n)
{
    int maxindex=0;
    for (int i = 0; i < n - 1; i++)
    {
        maxindex = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[maxindex] < arr[j])
                maxindex = j;

        }
        Swap(&arr[maxindex], &arr[n - i-1]);

    }

}
//快速排序

