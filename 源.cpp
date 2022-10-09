#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

		char short int long float double  -  内置类型，c语言自己的数据类型
		 结构体、枚举、联合体 - 自定义数据类型

		声明一个结构体类型
struct stu
struct - 结构体名称     stu - 结构体标签
{
	char name[20];
	char sex[10];
	int age;
	char tele[12];
}s3,s4;
struct stu s2;
		s2,s3,s4均为全局变量，下面s1是局部变量
int main()
{
	struct stu s1;
	 使用上面声明的类型创建的结构体类型变量
	 int n=0; 类型是int，n是变量，只不过结构体类型是两个词一起
	return 0;
}

			匿名结构体类型 - 只能用一次
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
 匿名结构体类型 pstu结构体指针
int main()
{
	pstu = &stu; 非法 
	return 0;
}

		结构体自引用
 1. 错误的引用
struct stu1
{
	int data;
	struct stu next;
		
};

 2. 正确用法
struct stu2
{
	int data;
	 将自己的数据存在数据域
	struct stu* next;
	 将下一个结点的地址存在地址域中
	short a;
	0-1,后面2-7仍然记为大小 = 8
	double b;
	8-16 = 8
	int c;
	16-20 = 4
	 共8+8+4=20，但是要为8的倍数，所以是24
};
int main()
{
	printf("%d ",sizeof(struct stu2));
	结构体变量的总大小要为结构体中最大的变量的整数倍 8*2
	return 0;
}

			结构体重命名
typedef struct stu
{	// typedef 类型重命名
	int data;
	struct stu* next;
}stu;	// 将struct stu 重命名为stu
	 但是如果把stu删去，改成匿名结构体类型
typedef struct
{
	int data;
	stu1* next;	//  error
}stu1;
int main()
{
	struct stu s1;
	stu s1;
	 两种类型等价
	return 0;
}

			结构体的定义 、 初始化 、 访问
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

			结构体内存对齐

struct s1
{
	char c1;	// 1字节|8 - 1		内存中从0（1的倍数）开始，后面偏移123都浪费
	int c2;		// 4字节|8 - 4		内存中从4（4的倍数）开始存放，5678
	char c3;	// 1字节|8 - 1		内存中从8（1的倍数）开始存放，9，后面便宜10 11 12 都浪费
				1-4 = 4，+4，9-12 = 4，共12
};
	结构体对齐规则
	1.第一个成员在结构体变量偏移量为0的地址处
	2.其他成员变量要对齐到 对齐数 的整数倍地址处
	   对齐数：编译器默认的一个对齐数 与该成员大小的较小值，如上面int 4|8的较小值4   - vs默认为8
	3.结构体总大小为最大对齐数 的整数倍 上面int 4最大，总大小就是12 - 3倍
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
	int a5;// 12-16		共16
};
struct s4
{
	double a1;	// 8  : 0 - 8    存放在 8 的倍数处，不过是第一个成员，放在0开始
	char a2;	// 1  : 8 - 9
	int a3;		// 4  : 12 - 16(9补到12) 存放在 1 的倍数处		共16
			必须从自己对齐数的倍数开始存放，int - 4  存放在 4 的倍数处
};
struct s5
{
	char a1;	// 0-1 2-8中间浪费
	struct s4 a2;	// 8-24偏移   -  占16字节
	 嵌套结构体类型，从该结构体内最大对齐数的整数倍 8 开始偏移
	double a3;	// 24-32      
				总大小32，是最大对齐数 8 的倍数
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