#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

		char short int long float double  -  �������ͣ�c�����Լ�����������
		 �ṹ�塢ö�١������� - �Զ�����������

		����һ���ṹ������
struct stu
struct - �ṹ������     stu - �ṹ���ǩ
{
	char name[20];
	char sex[10];
	int age;
	char tele[12];
}s3,s4;
struct stu s2;
		s2,s3,s4��Ϊȫ�ֱ���������s1�Ǿֲ�����
int main()
{
	struct stu s1;
	 ʹ���������������ʹ����Ľṹ�����ͱ���
	 int n=0; ������int��n�Ǳ�����ֻ�����ṹ��������������һ��
	return 0;
}

			�����ṹ������ - ֻ����һ��
struct
{
	char name[20];
	int age;
}stu;		
struct
{
	char name[20];
	int age;
}* pstu;
 �����ṹ������ pstu�ṹ��ָ��
int main()
{
	pstu = &stu; �Ƿ� 
	return 0;
}

		�ṹ��������
 1. ���������
struct stu1
{
	int data;
	struct stu next;
		
};

 2. ��ȷ�÷�
struct stu2
{
	int data;
	 ���Լ������ݴ���������
	struct stu* next;
	 ����һ�����ĵ�ַ���ڵ�ַ����
	short a;
	0-1,����2-7��Ȼ��Ϊ��С = 8
	double b;
	8-16 = 8
	int c;
	16-20 = 4
	 ��8+8+4=20������ҪΪ8�ı�����������24
};
int main()
{
	printf("%d ",sizeof(struct stu2));
	�ṹ��������ܴ�СҪΪ�ṹ�������ı����������� 8*2
	return 0;
}

			�ṹ��������
typedef struct stu
{	// typedef ����������
	int data;
	struct stu* next;
}stu;	// ��struct stu ������Ϊstu
	 ���������stuɾȥ���ĳ������ṹ������
typedef struct
{
	int data;
	stu1* next;	//  error
}stu1;
int main()
{
	struct stu s1;
	stu s1;
	 �������͵ȼ�
	return 0;
}

			�ṹ��Ķ��� �� ��ʼ�� �� ����
struct stu1 
{
	double weight;
	char tele[13];
};
struct stu
{
	char name[20];
	char sex[10];
	int age;
	double height;
	struct stu1 s1;
};

int main()
{
	struct stu s = { "Joyce","male",21,181.00 };
	struct stu s = { "Joyce","male",21,181.00 ,{120.00,"19906932001"} };
	printf("%s %s %d %lf %lf % s", s.name, s.sex, s.age, s.height,s.s1.weight,s.s1.tele);
	return 0;
}

			�ṹ���ڴ����

struct s1
{
	char c1;	// 1�ֽ�|8 - 1		�ڴ��д�0��1�ı�������ʼ������ƫ��123���˷�
	int c2;		// 4�ֽ�|8 - 4		�ڴ��д�4��4�ı�������ʼ��ţ�5678
	char c3;	// 1�ֽ�|8 - 1		�ڴ��д�8��1�ı�������ʼ��ţ�9���������10 11 12 ���˷�
				1-4 = 4��+4��9-12 = 4����12
};
	�ṹ��������
	1.��һ����Ա�ڽṹ�����ƫ����Ϊ0�ĵ�ַ��
	2.������Ա����Ҫ���뵽 ������ ����������ַ��
	   ��������������Ĭ�ϵ�һ�������� ��ó�Ա��С�Ľ�Сֵ��������int 4|8�Ľ�Сֵ4   - vsĬ��Ϊ8
	3.�ṹ���ܴ�СΪ�������� �������� ����int 4����ܴ�С����12 - 3��
  4.
struct s2
{
	char c1;
	char c2;
	int c3;
};
struct s3
{
	double a4;  // 0-8
	char a1;  // 8-9
	char a2;// 9-10
	char a3;// 10-11
	int a5;// 12-16		��16
};
struct s4
{
	double a1;	// 8  : 0 - 8    ����� 8 �ı������������ǵ�һ����Ա������0��ʼ
	char a2;	// 1  : 8 - 9
	int a3;		// 4  : 12 - 16(9����12) ����� 1 �ı�����		��16
			������Լ��������ı�����ʼ��ţ�int - 4  ����� 4 �ı�����
};
struct s5
{
	char a1;	// 0-1 2-8�м��˷�
	struct s4 a2;	// 8-24ƫ��   -  ռ16�ֽ�
	 Ƕ�׽ṹ�����ͣ��Ӹýṹ�������������������� 8 ��ʼƫ��
	double a3;	// 24-32      
				�ܴ�С32������������ 8 �ı���
};
int main()
{
	struct s1 s1 = { 0 };
	printf("%d ", sizeof(s1));
	struct s2 s2 = { 0 };
	printf("%d ", sizeof(s2));
	printf("%d ", sizeof(s3));
	printf("%d ", sizeof(s4));
	printf("%d ", sizeof(s5));
	return 0;
}