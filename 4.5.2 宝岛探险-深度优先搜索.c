#define  _CRT_SECURE_NO_WARNINGS  
//	�㷨��DFS
//	ʱ�䣺2021.10.29
#include<stdio.h>
int a[51][51];
int book[51][51], n, m, sum;
void dfs(int x, int y)
{
	//����һ����������
	int next[4][2] = {
		{0,1},//������
		{1,0},//������
		{0,-1},//������
		{-1,0}//������
	};
	int k, tx, ty;

	//ö��4������
	for (k = 0; k <= 3; k++)
	{
		//������һ������
		tx = x + next[k][0];
		ty = y + next[k][1];
		//�ж��Ƿ�Խ��
		if (tx<1 || tx>n || ty<1 || ty>m)
			continue;
		//�ж��Ƿ���½��
		if (a[tx][ty] > 0 && book[tx][ty] == 0)
		{
			sum++;
			book[tx][ty] = 1;//�����������߹�
			dfs(tx, ty);//��ʼ������һ����
		}
	}
	return;
}
int main()
{
	int i, j, startx, starty;
	scanf("%d %d %d %d", &n, &m, &startx, &starty);
	//�����ͼ
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);

	book[startx][starty] = 1;
	sum = 1;
	//�ӽ����λ�ÿ�ʼ
	dfs(startx, starty);
	//����������Ĵ�С
	printf("%d\n", sum);
	getchar(); getchar();
	return 0;
}