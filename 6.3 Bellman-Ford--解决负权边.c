#define  _CRT_SECURE_NO_WARNINGS  
//	ʱ�䣺2021.11.14  22��08��
//	�㷨��Bellman-Ford
//	Ŀ�ģ������Ȩ�ߵ�����
#include<stdio.h>
int main()
{
	int dis[10], bak[10], i, k, n, m, u[10], v[10], w[10], check, flag;
	int inf = 99999999;//��inf�洢һ��������Ϊ��������ֵ
	//����n��m��n��ʾ���������m��ʾ�ߵĸ���
	scanf("%d %d", &n, &m);

	//�����
	for (i = 1; i <= m; i++)
		scanf("%d %d %d", &u[i], &v[i], &w[i]);

	//��ʼ��dis���飬������1�Ŷ��㵽�����������ó�ʼ·��
	for (i = 1; i <= n; i++)
		dis[i] = inf;
	dis[1] = 0;

	//Bellman-Ford�㷨�������
	for (k = 1; k <= n - 1; k++)
	{
		//��dis���鱸�ݵ�bak������
		for (i = 1; i <= n; i++) bak[i] = dis[i];
		//����һ���ɳ�
		for (i = 1; i <= m; i++)
			if (dis[v[i]] > dis[u[i]] + w[i])
				dis[v[i]] = dis[u[i]] + w[i];
		//�ɳ���Ϻ���dis�Ƿ��и���
		check = 0;
		for (i = 1; i <= n; i++) if (bak[i] != dis[i]) { check = 1; break; }
		if (check == 0) break;//���dis����û�и��£���ǰ�˳�ѭ�������㷨
	}
	//��⸺Ȩ��·
	flag = 0;
	for (i = 1; i <= m; i++)
		if (dis[v[i]] > dis[u[i]] + w[i]) flag = 1;

	if (flag == 1) printf("��ͼ���и�Ȩ��·");
	else
	{
		//������յĽ��
		for (i = 1; i <= n; i++)
			printf("%d ", dis[i]);
	}
	getchar(); getchar();
	return 0;
}