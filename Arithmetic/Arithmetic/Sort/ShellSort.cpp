/*
基本思想：
将待排序列划分为若干组，在每组内进行直接插入排序，以使整个序列基本有序，然后再对整个序列进行直接插入排序。

分组方法：
对给定的一个步长d(d>0)，将下标相差为d的倍数的元素分在一组。d的取值依次为: d1=n/2, d2=d1/2, ……，dk=1
*/

template<typename T>
void ShellSort(T A[], int n) {
	int d = n / 2;     //步长初始为n/2
	while (d > 0) {
		for (int i = d; i < n; i++) {
			T x = A[i];
			int j = i - d;
			while (j >= 0 && x < A[j]) {
				A[j + d] = A[j];
				j = j - d;
			}
			A[j + d] = x;
		}
		d = d / 2;    //步长变为原来的1/2
	}
}
//也是插入排序的一种