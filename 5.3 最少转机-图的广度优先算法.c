#define  _CRT_SECURE_NO_WARNINGS  
//   ʱ�䣺2021.11.3
#include<stdio.h>
struct node
{
	int x;//���б��
	int s;//ת������
};

int main()
{
	struct node que[2501];
	int e[51][51] = { 0 }, book[51] = { 0 };
	int head, tail;
	int i, j, n, m, a, b, cur, start, end, flag = 0;
	scanf("%d %d %d %d", &n, &m, &start, &end);
	//��ʼ����ά����
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)  e[i][j] = 0;
			else  e[i][j] = 99999999;
	//�������֮��ĺ���
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		//ע������������ͼ
		e[a][b] = 1;
		e[b][a] = 1;
	}
	//���г�ʼ��
	head = 1;
	tail = 1;

	//��start�ų��г�������start�ų��м������
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[1] = start;//���start�ų������ڶ�����

	//�����в�Ϊ�յ�ʱ��ѭ��
	while (head < tail)
	{
		cur = que[head].x;//��ǰ�������׳��еı��
		for (j = 1; j <= n; j++)//��1��n���γ���
		{
			//�ӳ���cur������j�Ƿ��к��ಢ���жϳ���j�Ƿ��Ѿ��ڶ�����
			if (e[cur][j] != 99999999 && book[j] == 0)
			{
				//����ӳ���cur������j�к��ಢ�ҳ���j���ڶ����У���j�ų������
				que[tail].x = j;
				que[tail].s = que[head].s + 1;//ת������+1
				tail++;
				//��ǳ���j�Ѿ��ڶ�����
				book[j] = 1;
			}
			//�������Ŀ����У�ֹͣ��չ������������˳�ѭ��
			if (que[tail].x == end)
			{
				//ע���������仰��λ��ǧ��Ҫд�ߵ���
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;//ע����ط���ǧ��Ҫ���ǵ�һ������չ������head++���ܼ�����չ
	}

	//��ӡ������ĩβ���һ����Ŀ����У���ת������
	//ע��tail��ָ����ж�β�������һλ������һ��λ�ã�������Ҫ-1
	printf("%d", que[tail - 1].s);

	getchar(); getchar();
	return 0;
}