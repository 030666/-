#define  _CRT_SECURE_NO_WARNINGS  
/*	�㷨���������������BFS)
	ʱ�䣺2021.10.28
	Ŀ�ģ��Ż�3.2ը���˵Ĵ���
*/
#include<stdio.h>
struct node
{
	int x;//������
	int y;//������
};
char a[20][21];//�����洢��ͼ
int getnum(int i, int j)
{
	int sum, x, y;
	sum = 0;//sum������������������ĵ������������Գ�ʼ��Ϊ0
	//������i,j���Ƶ������±���x,y�У��Ա��Ժ������������ĸ�����ͳ�ƿ�������ĵ�����

	//����ͳ�ƿ�������ĵ�����
	x = i; y = j;
	while (a[x][y] != '#')//�жϵĵ㲻��ǽ���������ǽ�ͼ���
	{
		//�����ǰ�ĵ��ǵ��ˣ�����м���
		if (a[x][y] == 'G')
			sum++;
		//x--�������Ǽ�������ͳ��
		x--;
	}

	//����ͳ�ƿ�������ĵ�����
	x = i; y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		//x++�������Ǽ�������ͳ��
		x++;
	}

	//����ͳ�ƿ�������ĵ�����
	x = i; y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		//y--�������Ǽ�������ͳ��
		y--;
	}

	//����ͳ�ƿ�������ĵ�����
	x = i; y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		//y++�������Ǽ�������ͳ��
		y++;
	}
	return sum;
}
int main()
{
	struct node que[401];//�����ͼ��С������20*20����˶�����չ���ᳬ��400��
	int head, tail;
	int book[20][20] = { 0 };//����һ��������鲢ȫ����ʼ��Ϊ0
	int i, j, k, sum, max = 0, mx, my, n, m, startx, starty, tx, ty;

	//����һ�����ڱ���ߵķ��������
	int next[4][2] = {
		{0,1},//������
		{1,0},//������
		{0,-1},//������
		{-1,0}//������
	};
	
	//����n��m,n��ʾ�ж������ַ���m��ʾÿ���ж�����
	scanf("%d %d %d %d", &n, &m, &startx, &starty);

	//����n���ַ�
	for (i = 0; i <= n - 1; i++)
		scanf("%s", &a[i]);

	//���г�ʼ��
	head = 1;
	tail = 1;
	//�����в���С�˵���ʼ����
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	max = getnum(startx, starty);
	mx = startx;
	my = starty;
	//�����в�Ϊ�յ�ʱ��ѭ��
	while (head < tail)
	{
		//ö��4������
		for (k = 0; k <= 3; k++)
		{
			//�����ߵ���һ���������
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			//�ж��Ƿ�Խ��
			if (tx<0 || tx>n - 1 || ty<0 || ty>m - 1)
				continue;
			//�ж��Ƿ�Ϊƽ�ػ��������߹�
			if (a[tx][ty] == '.' && book[tx][ty] == 0)
			{
				//ÿ����ֻ���һ�Σ�������Ҫ���������Ѿ��߹�
				book[tx][ty] = 1;
				//��������չ�ĵ㵽������
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;

				//ͳ�Ƶ�ǰ����չ�ĵ��������ĵ�������
				sum = getnum(tx, ty);
				//����max��ֵ
				if (sum > max)
				{
					//�����ǰͳ�Ƴ��������������������max,�����max
					//����mx��my��¼�õ�����
					max = sum;
					mx = tx;
					my = ty;
				}
			}
		}
		head++;//ע����ط�ǧ��Ҫ���ǣ���һ������չ�����󣬱���Ҫhead++���ܶԺ���ĵ������չ

	}
	//����������������������ĵ�����
	printf("��ը�������ڣ�%d,%d)������������%d������\n", mx, my, max);
	getchar(); getchar();
}