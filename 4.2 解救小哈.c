#define  _CRT_SECURE_NO_WARNINGS  
/*	�㷨�������������(DFS)
	ʱ�䣺2021.10.28
	Ŀ�ģ��ҳ�С�߽��С�������·��
*/
#include<stdio.h>
int n, m, p, q, min = 99999999;
int a[51][51], book[51][51];
void dfs(int x, int y, int step)
{
	int next[4][2] = {
		{0,1},//������
		{1,0},//������
		{0,-1},//������
		{-1,0}//������
	};
	int tx, ty, k;
	//�ж��Ƿ񵽴�С����λ��
	if (x == p && y == q)
	{
		//������Сֵ
		if (step < min)
			min = step;
		return;//��ע������ķ��غ���Ҫ
	}

	//ö��4���߷�
	for (k = 0; k <= 3; k++)
	{
		//������һ��������
		tx = x + next[k][0];
		ty = y + next[k][1];
		//�ж��Ƿ�Խ��
		if (tx<1 || tx>n || ty<1 || ty>m)
			continue;
		//�жϸõ��Ƿ�Ϊ�ϰ�������Ѿ���·����
		if (a[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;//���������Ѿ����߹�
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;//���Խ�����ȡ�������ı��
		}
	}
	return;

}
int main()
{
	int i, j, startx, starty;
	//����n��m��nΪ��mΪ��
	scanf("%d %d", &n, &m);
	//�����Թ�
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

	//���������յ�����
	scanf("%d %d %d %d", &startx, &starty, &p, &q);

	//����㿪ʼ����
	book[startx][startx] = 1;//�������Ѿ���·���У���ֹ�����ظ���
	//��һ������������x���꣬�ڶ�������������y���꣬�����������ǳ�ʼ����Ϊ0
	dfs(startx, starty, 0);

	//�����̲���
	printf("%d", min);
	getchar(); getchar();
}