#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqList.h"
/*分析： 时间o(n)；空间o(n)
题目要求时间上足够高效，故采取空间换时间的做法
做法：
1-创造一个n项的数组Temp，分别代表1、2、3、、、n————>即a[i]代表数i+1——————>给每一项赋初值0
2-遍历表，只要在1、2、3···n的数出现过一次，Temp中对应项的值就为1
	个人思考：如果表中元素小于1或者大于n，不是没有表示了吗？
		——> 因为题目中只要求最小的正整数 ——>若顺序表中恰好有1、2、3···n，则最小为n+1；
									  若顺序表中有一项不是1-n中的，假设第i项，那不管缺项元素是啥，最小正整数就是第i项
3-遍历数组Temp，取最小Temp[i]=0的值，
*/
ElemtType FindMissMin(SqList* L) {
	int i;
	ElemtType* Temp;
	// 给辅助数组动态分配空间
	Temp = (ElemtType*)malloc(sizeof(ElemtType) * L->length);
	// 给数组空间中的每个字节赋值为0，这里就相当于赋值为0
	memset(Temp, 0, sizeof(ElemtType) * L->length);
	// 遍历表找到是否属于1-n的数
	for (i = 0; i < L->length; i++) {
		if (L->data[i] > 0 && L->data[i] <= L->length) {
			Temp[L->data[i] - 1] = 1;
		}
	}
	// 找到最小正整数
	for (i = 0; i < L->length; i++) {
		if (Temp[i] == 0)
			break;
	}
	return i + 1;
}

void SolveSqlist_13() {
	ElemtType a[6] = { 1,2,3,4,5,6 };
	SqList L;
	InitSqList(&L);
	CreateSqList(&L, a, 6);
	printf("原表：");
	PrintSqList(&L);
	printf("最小正整数为：");
	printf("%d", FindMissMin(&L));
}