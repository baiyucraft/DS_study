#include <stdio.h>
#include "SqQueue.h"

// 不做具体实现
// 船上队列q，客车队列car，货车队列truck
void manager(SqQueue& q, SqQueue& car, SqQueue& truck) {
	// i表示船上连续的客车数量
	int i = 0;
	// j表示船上车的数量
	int j = 0;
	while (j < 10) {
		// 如果客车队列非空，并且船上连续的客车不足4辆，入客车
		if (!EmptySqQueue(car) && i < 4) {
			EnSqQueue(q, DeSqQueue(car));
			i++; 
			j++;
		}
		// 如果船上连续的客车满4辆，且货车队列非空，入一辆货车
		else if (i == 4 && !EmptySqQueue(truck)) {
			EnSqQueue(q, DeSqQueue(truck));
			// 客车计数变0
			i = 0;
			j++;
		}
		// 客车队列为空，入货车直到j满或满4
		else {
			while (j < 10 && i < 4 && !EmptySqQueue(truck)) {
				EnSqQueue(q, DeSqQueue(truck));
				i++;
				j++;
			}
			i = 0;
		}
		if (EmptySqQueue(car) && EmptySqQueue(truck))
			j = 11;
	}
}