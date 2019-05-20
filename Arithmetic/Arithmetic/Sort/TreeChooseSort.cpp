/*
����˼�룺

1.����ѡ������Tree Selection Sort������һ�ְ��ս�������˼�����ѡ������ķ�����

2.���ȶ�n����¼���������Ƚϣ�Ȼ����ʤ��֮���ٽ��������Ƚϣ�����ظ���ֱ��ѡ����С�ؼ��ֵļ�¼Ϊֹ��������̿�����һ����n��Ҷ�ӽ�����ȫ��������ʾ�����ڵ��еĹؼ��ּ�ΪҶ�ӽ���е���С�ؼ��֡�

3.�������С�ؼ���֮����ѡ����С�ؼ��֣����轫Ҷ�ӽ���е���С�ؼ��ָ�Ϊ�����ֵ������ޣ�Ȼ��Ӹ�Ҷ�ӽ�㿪ʼ�������ֵܵĹؼ��ֽ��бȽϣ��޸Ĵ�Ҷ�ӽ�㵽����·���ϸ����Ĺؼ��֣��������Ĺؼ��ּ�Ϊ��С�ؼ��֡�

*/

template<typename T>
void TreeSelectionSort(T data[], int n)
{
	T MinValue = -100000000;  //�ø�����ʾ������
	int baseSize;             //�պ��ܴ洢n��������С��2���ݣ�����������������һ���Ҷ����
	int treeSize;             //�����������Ľڵ���
	int i;
	T max;
	int maxIndex;

	baseSize = 1;
	while (baseSize < n)
	{
		baseSize *= 2;
	}
	//������һ���Ҷ���������ܽڵ���
	treeSize = baseSize * 2 - 1;

	//���������Ŷ����������ݴ��±�1��ʼ���
	T* tree = new T[treeSize + 1]();

	//�����ݷ�������һ����
	for (i = 0; i < n; i++)
	{
		tree[treeSize - i] = data[i];
	}
	//���������������ڵ��ʼ��Ϊ��������ÿ������һ����Сֵ��Ӧ��ʼ��Ϊ������
	for (; i < baseSize; i++)
	{
		tree[treeSize - i] = MinValue;
	}
	// ����һ���������ڵ������ֵ
	for (i = treeSize; i > 1; i -= 2)
	{
		tree[i / 2] = (tree[i] > tree[i - 1] ? tree[i] : tree[i - 1]);
	}
	n -= 1;    //δ���������-1
	while (n >= 0)
	{
		max = tree[1];             //ȡ�����ֵ
		data[n--] = max;          //����ǰ�ҵ������ֵ�ŵ�����������
		//�ڶ�������������һ���ҵ���ǰ���ֵ��λ��
		maxIndex = treeSize;
		while (tree[maxIndex] != max)
		{
			maxIndex--;
		}
		tree[maxIndex] = MinValue;  //�����еײ�������ֵ�滻Ϊ������

		//�ӱ��滻��λ�����ϼ��㣬�޸Ĵ�Ҷ�ӽ�㵽����·���ϸ�����ֵ
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