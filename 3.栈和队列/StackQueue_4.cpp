#include <stdio.h>
#include "SqQueue.h"

// ��������ʵ��
// ���϶���q���ͳ�����car����������truck
void manager(SqQueue& q, SqQueue& car, SqQueue& truck) {
	// i��ʾ���������Ŀͳ�����
	int i = 0;
	// j��ʾ���ϳ�������
	int j = 0;
	while (j < 10) {
		// ����ͳ����зǿգ����Ҵ��������Ŀͳ�����4������ͳ�
		if (!EmptySqQueue(car) && i < 4) {
			EnSqQueue(q, DeSqQueue(car));
			i++; 
			j++;
		}
		// ������������Ŀͳ���4�����һ������зǿգ���һ������
		else if (i == 4 && !EmptySqQueue(truck)) {
			EnSqQueue(q, DeSqQueue(truck));
			// �ͳ�������0
			i = 0;
			j++;
		}
		// �ͳ�����Ϊ�գ������ֱ��j������4
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