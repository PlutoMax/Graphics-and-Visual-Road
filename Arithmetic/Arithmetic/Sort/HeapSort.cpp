/*
�ѵĽṹ��������ȫ��������ÿ������ֵ��С�ڻ��ߵ��������Һ��ӽ���ֵ������ÿ���ڵ��ֵ�����ڻ���������Һ��ӵ�ֵ

��������̽�����������й����һ���ѣ�ѡ�������������ߣ��ٰ�ʣ���Ԫ�ص����ɶѣ��ҳ����������ߣ��ظ�ֱ������
*/

//����һ��ʵ��
//������
void HeapSort(int arr[], int len) {
	int i;
	//��ʼ���ѣ������һ�����ڵ㿪ʼ
	for (i = len / 2 - 1; i >= 0; --i) {
		Heapify(arr, i, len);
	}
	//�Ӷ��е�ȡ������Ԫ���ٵ�����
	for (i = len - 1; i > 0; --i) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		//�����ɶ�
		Heapify(arr, 0, i);
	}
}

//�ٿ������ɶѵĺ���
void Heapify(int arr[], int first, int end) {
	int father = first;
	int son = father * 2 + 1;
	while (son < end) {
		if (son + 1 < end && arr[son] < arr[son + 1]) ++son;
		//������ڵ�����ӽڵ����ʾ�������
		if (arr[father] > arr[son]) break;
		else {
			//��Ȼ�ͽ������ڵ���ӽڵ��Ԫ��
			int temp = arr[father];
			arr[father] = arr[son];
			arr[son] = temp;
			//�����ӽڵ�����һ��Ҫ�Ƚϵ�λ��
			father = son;
			son = 2 * father + 1;
		}
	}
}