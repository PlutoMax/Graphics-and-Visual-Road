//比较相邻的元素，如果反序则交换，过程也是分为有序区和无序区，
//初始时有序区为空，所有元素都在无序区，经过第一趟后就能找出最大的元素，然后重复便可

void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

/*
冒泡排序感觉非常好理解，第一个for循环是遍历所有元素，第二个for循环是每次遍历元素时都对无序区的相邻两个元素进行一次比较，若反序则交换

时间复杂度最坏的情况是反序序列，要比较n(n-1)/2次，时间复杂度为O(n^2 )，最好的情况是正序，只进行(n-1)次比较，不需要移动，时间复杂度为O(n)，而平均的时间复杂度为O(n^2 )

但是还有更好的方法，如果第一次比较完没有交换即说明已经有序，不应该进行下一次遍历
还有已经遍历出部分有序的序列后，那部分也不用进行遍历，即发生交换的地方之后的地方不用遍历
*/

void BubbleSort(int arr[], int len) {
	int i, temp;
	//记录位置，当前所在位置和最后发生交换的地方
	int current, last = len - 1;
	while (last > 0) {
		for (i = current = 0; i < last; ++i) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				//记录当前的位置，如果没有发生交换current值即for循环初始化的0
				current = i;
			}
		}
		//若current = 0即已经没有可以交换的元素了，即已经有序了
		last = current;
	}
}