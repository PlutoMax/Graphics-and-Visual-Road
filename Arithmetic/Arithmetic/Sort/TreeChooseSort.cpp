/*
基本思想：

1.树形选择排序（Tree Selection Sort），是一种按照锦标赛的思想进行选择排序的方法。

2.首先对n个记录进行两两比较，然后优胜者之间再进行两两比较，如此重复，直至选出最小关键字的记录为止。这个过程可以用一棵有n个叶子结点的完全二叉树表示。根节点中的关键字即为叶子结点中的最小关键字。

3.在输出最小关键字之后，欲选出次小关键字，仅需将叶子结点中的最小关键字改为“最大值”，如∞，然后从该叶子结点开始，和其兄弟的关键字进行比较，修改从叶子结点到根的路径上各结点的关键字，最后根结点的关键字即为次小关键字。

*/

template<typename T>
void TreeSelectionSort(T data[], int n)
{
	T MinValue = -100000000;  //用该数表示负无穷
	int baseSize;             //刚好能存储n个数的最小的2的幂，等于满二叉树最下一层的叶子树
	int treeSize;             //整个二叉树的节点数
	int i;
	T max;
	int maxIndex;

	baseSize = 1;
	while (baseSize < n)
	{
		baseSize *= 2;
	}
	//用最下一层的叶子树计算总节点数
	treeSize = baseSize * 2 - 1;

	//创建数组存放二叉树，数据从下标1开始存放
	T* tree = new T[treeSize + 1]();

	//将数据放入最下一层中
	for (i = 0; i < n; i++)
	{
		tree[treeSize - i] = data[i];
	}
	//将二叉树的其他节点初始化为负无穷，如果每轮是求一个最小值则应初始化为正无穷
	for (; i < baseSize; i++)
	{
		tree[treeSize - i] = MinValue;
	}
	// 构造一棵树，根节点是最大值
	for (i = treeSize; i > 1; i -= 2)
	{
		tree[i / 2] = (tree[i] > tree[i - 1] ? tree[i] : tree[i - 1]);
	}
	n -= 1;    //未排序的数量-1
	while (n >= 0)
	{
		max = tree[1];             //取出最大值
		data[n--] = max;          //将当前找到的最大值放到数组的最后面
		//在二叉树的最下面一层找到当前最大值的位置
		maxIndex = treeSize;
		while (tree[maxIndex] != max)
		{
			maxIndex--;
		}
		tree[maxIndex] = MinValue;  //将树中底层的现最大值替换为负无穷

		//从被替换的位置向上计算，修改从叶子结点到根的路径上各结点的值
		while (maxIndex > 1)
		{
			if (maxIndex % 2 == 0)
			{
				tree[maxIndex / 2] = (tree[maxIndex] > tree[maxIndex + 1] ? tree[maxIndex] : tree[maxIndex + 1]);
			}
			else
			{
				tree[maxIndex / 2] = (tree[maxIndex] > tree[maxIndex - 1] ? tree[maxIndex] : tree[maxIndex - 1]);
			}
			maxIndex /= 2;
		}
	}
	delete[] tree;
}