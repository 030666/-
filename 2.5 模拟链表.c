#define  _CRT_SECURE_NO_WARNINGS  
/*	�㷨��ģ������
	ʱ�䣺2021.10.27
	Ŀ�ģ�ѧ��������ģ������
*/
#include<stdio.h>
int main()
{
	int data[101], right[101];
	int i, n, t, len;
	//�������е���
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &data[i]);
	len = n;
	//��ʼ������right
	for (i = 1; i <= n; i++)
	{
		if (i != n)
			right[i] = i + 1;
		else
			right[i] = 0;
	}
	//ֱ��������data��ĩβ����һ����
	len++;
	scanf("%d", &data[len]);

	//�������ͷ����ʼ����
	t = 1;
	while (t != 0)
	{
		if (data[right[t]] > data[len])//�����ǰ�����һ������ֵ���ڴ����������������뵽�м�
		{
			right[len] = right[t];//�²���������һ������ŵ��ڵ�ǰ������һ�������
			right[t] = len;//��ǰ������һ������ž����²������ı��
			break;
		}
		t = right[t];
	}

	//������������е���
	t = 1;
	while (t != 0)
	{
		printf("%d ", data[t]);
		t = right[t];
	}
	system("pause");
	return 0;
}