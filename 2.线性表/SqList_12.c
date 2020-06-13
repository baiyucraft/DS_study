#include <stdio.h>
#include "SqList.h"

/*分析：时间o(n);空间o(1)
1-选定第一个元素为候选元素this，遇到等于this的，count++，反之count--；
2-当count = 0时，此时：已遍历的k项中的k/2为this，即前k项中的其他元素出现次数<=k/2—————这里意味着，前k项中，某一元素出现的次数最多只有k/2；
3-选定k+1个元素为this继续遍历，又遍历了l个元素，继续分析从k+1开始的l项中，某一元素出现的次数最多只有l/2；
。。。。。
遍历结束的两种情况：
	若count=0：易知n项中，某一元素最多出现n/2次，不存在主元素
	若count>0：即在最后一次选定this时，this出现的次数>最后一次遍历元素数a/2，最优情况，最后一次选定this之前，该元素出现次数等于前(n-a)/2
		此时主元素可能存在，故验证是否出现次数大于n/2
*/
// 参考答案
ElemtType Majarity(SqList* L) {
	// count计数
	int i, count = 1;
	// this表示候选主元素
	int this = L->data[0];
	// 遍历顺序表
	for (i = 1; i < L->length; i++) {
		// 如果第i+1个元素等于this，++
		if (L->data[i] == this)
			count++;
		// 不等于
		else {
			// 反之 --
			if (count > 0) {
				count--;
			}
			// 重新选定候选主元素
			else {
				this = L->data[i];
				count = 1;
			}
		}
	}
	// 如果count不为0，判断候选主元素是否为真正的主元素
	if (count > 0) {
		count = 0;
		for (i = 0; i < L->length; i++) {
			if (L->data[i] == this) {
				count++;
			}
		}
	}
	return count > L->length / 2 ? this : -1;
}

void SolveSqlist_12() {
	ElemtType a[6] = { 1,5,5,3,5,2 };
	SqList L;
	InitSqList(&L);
	CreateSqList(&L, a, 6);
	printf("原表：");
	PrintSqList(&L);
	printf("主元素：");
	printf("%d", Majarity(&L));
}