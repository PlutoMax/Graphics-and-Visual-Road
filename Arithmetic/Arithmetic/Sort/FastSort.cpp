/*
������������ѡһ����ֵ(pivot��Ҳ�нл�׼��)�����������¼���ֳɶ����������֣�����Ԫ�ؾ�С����ֵ���Ҳ��Ԫ�ؾ����ڻ������ֵ��Ȼ��������������ظ���ֱ��������������

�����ǺͶ������������ƣ�����һ���ݹ�Ĺ���
*/
//������
QuickSort(int arr[], int first, int end) {
	if (first < end) {
		int pivot = OnceSort(arr, first, end);
		//�Ѿ�����ֵ�ˣ��ٶ���ֵ���ҽ��еݹ�
		QuickSort(arr, first, pivot - 1);
		QuickSort(arr, pivot + 1, end);
	}
}

//һ������ĺ���
int OnceSort(int arr[], int first, int end) {
	int i = first, j = end;
	//��i<j���ƶ��ĵ㻹û���м�ʱѭ��
	while (i < j) {
		//�ұ�����ʼ����֤i<j����arr[i]С�ڻ��ߵ���arr[j]��ʱ����������
		while (i < j && arr[i] <= arr[j]) --j;
		//��ʱ���Ѿ�����ѭ����˵��j>i ���� arr[i]����arr[j]�ˣ����i<j�Ǿ���arr[i]����arr[j]���Ǿͽ���
		if (i < j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		//����һ��ִ��ͬ���Ĳ���
		while (i < j && arr[i] <= arr[j]) ++i;
		if (i < j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//�����Ѿ��ƶ���һ�ߵ����´��������ֵ
	return i;
}