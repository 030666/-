#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*	�㷨������
	ʱ�䣺2021.10.18
	Ŀ�ģ�����ʵ�ֶ��в���
*/
struct queue
{
	int data[100];//���е����壬������������
	int head;//����
	int tail;//��β
};
int main()
{
	struct queue q;
	int i;
	//��ʼ������
	q.head = 1;//����ͷ��0����1��ʼ������
	q.tail = 1;
	for (int i = 1; i <= 9; i++)
	{
		//������������9����
		scanf("%d", &q.data[q.tail]);
		q.tail++;
	}
	while (q.head < q.tail)//�����в�Ϊ�յ�ʱ��ִ��ѭ��
	{
		//��ӡ���ײ������׳���
		printf("%d ", q.data[q.head]);
		q.head++;

		//�Ƚ��¶��׵�����ӵ���β
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		//�ٽ����׳���
		q.head++;
	}
	system("pause");
	return 0;
}