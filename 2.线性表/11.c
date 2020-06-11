#include <stdio.h>
#include "SqList.h"

// 空间上不高效（合并然后找中位数）时间o（n），空间o（2n）
ElemtType MidNum(SqList* L1, SqList* L2) {
	SqList L = Merge(L1, L2);
	PrintList(&L);
	return L.data[(L.length / 2) - 1];
}
// 分别取中位数比较（空间高效）--答案题解 时间o（log2 n），空间o（1）
ElemtType MidNum2(SqList* L1, SqList* L2) {
	if (L1->length != L2->length) {
		printf("两个表不一样长");
		return;
	}
	// 分别表示L1、L2的第一个元素，最后一个元素，中位数
	int first1 = 0, after1 = L1->length - 1, mid1;
	int first2 = 0, after2 = L2->length - 1, mid2;
	// 直到首尾元素指针变为同一个（L1、L2均只剩一个元素），该值取较小的元素
	while (first1 != after1 || first2 != after2) {
		mid1 = (first1 + after1) / 2;
		mid2 = (first2 + after2) / 2;
		// 如果L1的中位数和L2的中位数相等，返回该值
		if (L1->data[mid1] == L2->data[mid2]) {
			return L1->data[mid1];
		}
		// 如果L1的中位数 < L2的中位数，舍弃L1的前半部分，L2的后半部分（这里要保证舍弃长度相等）
		if (L1->data[mid1] < L2->data[mid2]) {
			// 若长度为奇数，中位数左右元素相等，舍弃前后即可
			if ((first1 + after1) % 2 == 0) {
				first1 = mid1;
				after2 = mid2;
			}
			// 若长度为偶数，中位数左边元素比右边元素少一个，故L1左侧多舍弃一个
			else {
				first1 = mid1 + 1;
				after2 = mid2;
			}
		}
		// 如果L1的中位数 > L2的中位数，舍弃L1的后半部分，L2的前半部分（这里要保证舍弃长度相等）
		else {
			// 若长度为奇数，中位数左右元素相等，舍弃前后即可
			if ((first1 + after1) % 2 == 0) {
				after1 = mid1;
				first2 = mid2;
			}
			// 若长度为偶数，中位数左边元素比右边元素少一个，故L2左侧多舍弃一个
			else {
				after1 = mid1;
				first2 = mid2 + 1;
			}
		}
	}
	// 返回较小的（因为两个顺序表的和为偶数个，取小的）
	return L1->data[first1] < L2->data[first2] ? L1->data[first1] : L2->data[first2];
}

/*
分析：
1）分别求L1、L2的中位数a、b，并比较大小
	1-若a=b，则a或b为所求中位数，算法结束
	2-若a<b，舍弃L1中前半段，L2中的后半段（需要保证两次舍弃长度相等）？因为L1中前半段比a小，L2中后半段比b大
	3-若a>b，舍弃L1中后半段，L2中的前半段（需要保证两次舍弃长度相等）？因为L1中后半段比a大，L2中前半段比b小
2）重复上述步骤，直到L1、L2中只剩一个元素，较小为中位数（因为两个顺序表的和为偶数个，取小的）

分解：
1）L1中[1,2,5,7,9],L2中[1,3,6,7,8]————first1=0，after1=4，first2=0，after2=4————mid1：2（5），mid2：2（6）；括号中为中位数：5<6
2）L1中[5,7,9],L2中[1,3,6]————first1=2，after1=4，first2=0，after2=2————mid1：3（7），mid2：1（3）；括号中为中位数：7>3
3）L1中[5,7],L2中[3,6]————first1=2，after1=3，first2=1，after2=2————mid1：2（5），mid2：1（3）；括号中为中位数：5>3
3）L1中[5],L2中[6]————first1=2，after1=2，first2=2，after2=2——————循环停止得5
*/




void Solve11() {
	ElemtType a[5] = { 1,2,5,7,9 };
	SqList L1;
	InitSqList(&L1);
	CreateList(&L1, a, 5);
	ElemtType b[5] = { 1,3,6,7,8 };
	SqList L2;
	InitSqList(&L2);
	CreateList(&L2, b, 5);
	printf("表1：");
	PrintList(&L1);
	printf("表2：");
	PrintList(&L2);
	printf("中位数：");
	printf("%d", MidNum2(&L1, &L2));
}