//����˼�룺 �ڴ������ӱ����ҳ����С��Ԫ�أ�������Ԫ�ط����ӱ����ǰ�����档

template<typename T>
void SelectSort(T A[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		T min = i;
		//�ҵ�δ�����ӱ�����С����λ��
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[min])
				min = j;
		//����ǰ����С���ŵ���λ����
		if (min != i)
		{
			T temp = A[min];
			A[min] = A[i];
			A[i] = temp;
		}
	}
}