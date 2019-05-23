//基本思想： 在待排序子表中找出最大（小）元素，并将该元素放在子表的最前（后）面。

template<typename T>
void SelectSort(T A[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		T min = i;
		//找到未排序子表中最小数的位置
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[min])
				min = j;
		//将当前的最小数放到其位置上
		if (min != i)
		{
			T temp = A[min];
			A[min] = A[i];
			A[i] = temp;
		}
	}
}