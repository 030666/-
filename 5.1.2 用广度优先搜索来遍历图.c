#define  _CRT_SECURE_NO_WARNINGS  
//	ʱ�䣺2021.10.30
//  Ŀ�ģ��ù��������������ͼ(����
#include<stdio.h>
int main()
{
	int i, j, n, m, a, b, cur, book[101] = { 0 }, e[101][101];
	int que[10001], head, tail;
	scanf("%d %d", &n, &m);
	//��ʼ����ά����
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j) e[i][j] = 0;
			else e[i][j] = 99999999;//����99999999Ϊ�����

	//���붥��֮��ı�
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;//��Ϊ����������ͼ
	}
	//���г�ʼ��
	head = 1;
	tail = 1;

	//��1�Ŷ����������1�Ŷ���������
	que[tail] = 1;
	tail++;
	book[1] = 1;//���1�Ŷ����ѷ���

	//�����в�Ϊ�յ�ʱ��ѭ��
	while (head < tail)
	{
		cur = que[head];//��ǰ���ڷ��ʵĶ�����
		for (i = 1; i <= n; i++)//��1-n���γ���
		{
			//�жϴӶ���cur������i�Ƿ��бߣ����ж϶���i�Ƿ��Ѿ����ʹ�
			if (e[cur][i] == 1 && book[i] == 0)
			{
				//����Ӷ���cur������i�бߣ����Ҷ���iû�б����ʹ����򽫶���i���
				que[tail] = i;
				tail++;
				book[i] = 1;//��Ƕ���i�ѷ���
			}
			//���tail����n����������ж��㶼�Ѿ������ʹ���
			if (tail > n)
				break;
		}
		head++;//ע������ط���ǧ��Ҫ���ǵ�һ��������չ������head++��Ȼ����ܼ���������չ
	}
	for (i = 1; i < tail; i++)
		printf("%d ", que[i]);
	getchar(); getchar();
	return 0;
}