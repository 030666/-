#define  _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
/*	�㷨��ջ��ģ��
	ʱ�䣺2021.10.18
	Ŀ�ģ�����ջ�������������
*/
int main()
{
	char a[101], s[101];
	int i, len, mid, next, top;

	gets(a);//����һ���ַ���
	len = strlen(a);//���ַ����ĳ���
	mid = len / 2 - 1;//���ַ������е�

	top = 0;//ջ�ĳ�ʼ��
	//��midǰ���ַ�������ջ
	for (i = 0; i <= mid; i++)
	{
		s[++top] = a[i];
	}

	//�ж��ַ����ĳ�������������ż�������ҳ���Ҫ�����ַ�ƥ�����ʼ�±�
	if (len % 2 == 0)
		next = mid + 1;
	else
		next = mid + 2;
	//��ʼƥ��
	for (i = next; i <= len - 1; i++)
	{
		if (a[i] != s[top])
			break;
		top--;
	}
	//���top��ֵΪ0����˵��ջ�����е��ַ�����һһƥ����
	if (top == 0)
		printf("yes!\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}