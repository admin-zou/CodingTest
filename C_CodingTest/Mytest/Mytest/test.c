/*	C������һЩ��������⣬�������ʮ�����ң��ɼ��ѣ�
*�������ҵ�����ʵ�֣��Ҷ����Թ��������ܱ�֤��ȫû��bug
*/

#define _CRT_SECURE_NO_WARNINGS

//1.���hello world
#include<stdio.h>
int main()
{
	printf("hello world\n");
	return 0;
}

//2.1+2+3+......+100
#include<stdio.h>
int main()
{
	int count = 0;
	int i = 1;
	int j = 2;
	int k = 0;
	for (; k < 50; ++k)
	{
		count = count + i + j;
		i += 2;
		j += 2;
	}
	printf("%d \n",count);
	return 0;
}

//3.9*9�ھ���
#include<stdio.h>
int main()
{
	int i = 1;
	int j = 1;
	for (i = 1; i < 10; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
			printf("%1d*%1d=%2d ", j, i, i*j);
		}
		printf("\n");
	}
	return 0;
}

//4.�������ϴ��һ��
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int max = 0;
	if (a > b)
		max = a;
	else
		max = b;
	printf("%d \n", max);
	return 0;
}


//5.��10�����е������
#include<stdio.h>
int main()
{
	int a[10];
	int i = 0;
	for (i = 0; i < 10; ++i)
		scanf("%d", &a[i]);
	int max = a[0];
	for (i = 1; i < 10; ++i)
	{
		if (a[i] > max)
			max = a[i];
	}
	printf("%d \n", max);
	return 0;
}


//6.��1��100֮�������
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 1; i <= 100; i++)
	{
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		if (flag == 1)
			printf("%d ",i);
	}
	printf("\n");
	return 0;
}


//7.շת����������Լ��
int great_gcd(int x, int y)
{
	do{
		if (y > x)
			swap(&x, &y);
		x = x % y;
	} while (x != 0);
	return y;
}

#include<stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int ret = great_gcd(a, b);
	printf("%d \n", ret);
}

//8.��������������С������
//��С��������������֮���������ǵ����Լ��
#include<stdio.h>
void swap(int *x, int *y)
{
	int p = *x;
	*x = *y;
	*y = p;
}
int great_gcd(int x, int y)
{
	do{
		if (y > x)
			swap(&x, &y);
		x = x % y;
	} while (x != 0);
	return y;
}

int main()
{
	int a, b;
	scanf("%d %d",&a,&b);
	int ret = a * b;
	int tmp = great_gcd(a, b);
	printf("%d \n", ret/tmp);
	return 0;
}

//9.����������ֵ
#include<stdio.h>
void swap(int *x, int*y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void swap(int *x, int* y)
{
	if (*x != *y)
	{
		*x = *x ^ *y;
		*y = *x ^ *y;
		*x = *x ^ *y;
	}
}

int main()
{
	int a;
	int b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d %d\n",a,b);
	return 0;
}

//10.����������ֵ(��ֵ)
#include<stdio.h>
void swap(int x, int y)//���ܸı�a��b��ֵ
{
	int tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int a = 1;
	int b = 2;
	swap(a, b);
	printf("%d %d\n", a, b);
	return 0;
}
/*
a = a + b;
b = a - b;
a = a - b;

a ^= b ^= a ^= b;
a = a + b - (b = a);
*/

#include<stdio.h>
int main()
{
	int total = 0;
	int ret = 1;
	int n;
	int i;
	scanf("%d",&n);
	for (i = n; i > 1; i--)
	{
		total = 2 * (ret + 1);
		ret = total;
	}
	printf("%d", total);
	return 0;
}


//11.��1��2��3��4�ĸ����֣�����ɶ��ٸ������ظ��һ�����ͬ����λ�����ֱ��г�����
#include<stdio.h>

int main()
{
	int i = 1;
	int j = 1;
	int k = 1;
	for (i = 1; i <= 4;++i)
	{
		for (j = 1; j <= 4;++j)
		{
			if (j == i)
				continue;
			for (k = 1; k <= 4;++k)
			{
				if (k == j || k == i)
					continue;
				printf("%d\t", i * 100 + j * 10 + k);
			}
		}
	}
	return 0;
}


//12.��c����д��2000��֮ǰ������
#include<stdio.h>
int main()
{//4 100 400
	int count = 0;
	int i = 0;
	for (i = 1; i <= 2000; ++i)
	{
		if ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0))
		{
			printf("%d\t", i);
			count++;
		}
	}
	printf("\n toatl: %4d \n", count);
	return 0;
}


//13.��һ�������У�2/1��3/2��5/3��8/5��13/8��21/13...���������е�ǰ20��֮�� 
#include<stdio.h>
int main()
{
	int i = 0;
	float n1 = 2;
	float n2 = 1;
	float count = 0;
	for (i = 0; i < 20; ++i)
	{
		count += n1 / n2;
		int tmp = n1;
		n1 = n1 + n2;
		n2 = tmp;
	}
	printf("%f\n",count);
	return 0;
}

//14.s=a+aa+aaa+...+aa..aaa����a�����֣�����2+22+222+2222+22222����ʱa=2��5������ӣ���a���ɼ��̿��ƣ�
#include<stdio.h>
int main()
{
	int a, n;
	int i = 0;
	int count = 0;
	scanf("%d %d",&a,&n);
	int tmp=a;
	for (; i < n; ++i)
	{
		count += tmp;
		tmp = tmp * 10 + a;
	}
	printf("%d \n",count);
	return 0;
}

//15.һ���100�׸߿�����,ÿ����غ�����ԭ���߶ȵ�һ�룻�����£������ڵ�ʮ�����ʱ�������������ף���ʮ�η����ĸ߶ȣ�
#include<stdio.h>
int main()
{
	float total = 0;
	float hight = 100;
	int n;
	printf("�����뷴��������");
	scanf("%d", &n);
	while (n > 0)
	{
		total += 2 * hight;
		hight /= 2;
		n--;
	}
	printf("������%f��,�����߶�%f��\n", total-100, hight);
	return 0;
}


//16���ӳ���
#include<stdio.h>
int main()
{
	int total = 0;
	int ret = 1;
	int i = 10;
	for (i = 10; i > 1; i--)
	{
		total = 2 * (ret + 1);
		ret = total;
	}
	/*for (i = 0; i < 10; i++)
	{
		total = total / 2 - 1;
	}*/
	printf("���ӹ�ժ��%d������\n", total);
	return 0;
}


//17.������1 - 1/2 + 1/3 - 1/4 + 1/5... + 1/99 - 1/100
#include<stdio.h>
int main()
{   
	double i = 1;
	double ret = 0;
	double tmp = 0;
	while (i <= 100)
	{
		ret =ret + 1/(i * (i+1));
		i+=2;
	}
	printf("%f \n", ret);
	return 0;
}


//18.��1! + 2! + 3! + ... + 20!
#include<stdio.h>
int main()
{
	int ret = 0;
	int tmp = 1;
	int i = 1;
	for (; i <= 20; ++i)
	{
		tmp *= i;
		ret += tmp;
	}
	printf("%d\n",ret);
	return 0;
}


//19.�ж�һ�����Ƿ��ǻ���
#include <stdio.h>
int main()
{
	//121
	int num;
	int tmp = 0;
	int data = 0;
	scanf("%d", &num);
	tmp = num;
	while (tmp != 0)
	{
		data = data * 10 + tmp % 10;
		tmp /= 10;
	}
	printf("%d", num);
	if (data == num)
	{ printf("�ǻ���\n");}
	else
	{ printf("���ǻ���\n");}
	return 0;
}


//20.�ж�һ���ַ����Ƿ��ǻ��Ĵ�
#include <stdio.h>
int main()
{
	char array[15];
	int head = 0, rear = 0;
	scanf("%s", array);
	while (array[rear+1] != '\0')
		rear++;
	while (head < rear)
	{
		if (array[head++] != array[rear--])
		{
			printf("%s ���ǻ���\n",array);
			return 0;
		}
	}
	printf("%s �ǻ���\n", array);
	return 0;
}


//21��һ��3*3����Խ���Ԫ��֮�͡�
#include <stdio.h>
int main()
{
	int i = 0,j=0;
	int a[3][3];
	printf("������3*3�����Ԫ�أ�\n");
	for (i = 0; i < 3; i++)
	{
		printf("�����%d��Ԫ��:", i + 1);
		for (j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	}
	printf("***************\n");
	for (i = 0; i < 3; i++)
	{
		printf("**  ");
		for (j = 0; j < 3; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("**");
		printf("\n");
	}
	printf("***************\n");
	printf("�Խ���1��Ԫ��֮��Ϊ��%d\n", a[0][0] + a[1][1] + a[2][2]);
	printf("�Խ���2��Ԫ��֮��Ϊ: %d\n", a[2][0] + a[1][1] + a[0][2]);
}


//22��һ��������������
#include <stdio.h>
#define Size 100
int main()
{
	int array[100];
	int num;
	int i = 0;
	int j = 0;
	int tmp;
	printf("����������Ĵ�С��");
	while (1)
	{
		scanf("%d", &num);
		if (num <= Size)
			break;
		else
			printf("�������������\n");
	}
	printf("������:");
	for (i = 0; i < num; i++)
	{
		scanf("%d",&array[i]);
	}
	i = 0;
	j = num - 1;
	while (i < j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		++i;
		--j;
	}
	for (i = 0; i < num; i++)
		printf("%d  ",array[i]);

	printf("\n");
	return 0;
}


//23ð�ݷ���������������
#include <stdio.h>
#define Size 100
int main()
{
	int array[100];
	int i = 0, j = 0;
	int num;
	printf("�����������С:");
	scanf("%d",&num);
	for (i = 1; i <= num; i++)
		scanf("%d",&array[i]);
	for (i = num; i >=1; i--)
	{
		array[0] = array[1];
		for (j = 2; j <= i; j++)
		{
			if (array[j] < array[j-1])
			{
				array[0] = array[j - 1];
				array[j - 1] = array[j];
				array[j] = array[0];
			}
		}
	}
	printf("�����:");
	for (i = 1; i <= num; i++)
		printf("%d  ",array[i]);
}


//24������ַ�����������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
int main()
{
	char tmp[SIZE];
	int num;
	int i = 0, j = 0;
	scanf("%d",&num);
	char** str = (char**)malloc(sizeof(char*)*num);
	for (i = 0; i < num; i++)
	{
		str[i] = (char*)malloc(sizeof(char)*SIZE);
		scanf("%s",str[i]);
	}
	for (i = 0; i < num - 1; i++)
	{
		for (j = i + 1; j < num - i-1; j++)
		{
			if (strcmp(str[j - 1], str[j]) == 1)
			{
				strcpy(tmp, str[j - 1]);
				strcpy(str[j - 1], str[j]);
				strcpy(str[j], tmp);
			}
		}
	}
	for (i = 0; i < num; i++)
	{
		printf("\n%s\n",str[i]);
	}
	return 0;
}


//25.�ݹ����쳲���д��n����
#include<stdio.h>
int retfblx(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return retfblx(n - 1) + retfblx(n-2);
}

int retfblx(int n)
{
	return n >= 2 ? (retfblx(n - 1) + retfblx(n - 2)) : n;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", retfblx(n));
}


//26�÷ǵݹ���쳲���д��n����
#include <stdio.h>
int retfblax(int n)
{
	int n_val;
	int i = 0;
	int n1 = 1, n2 = 1;
	int tmp = 0;
	if (n <= 0)
	{
		n_val = 0;
	}
	else if (n == 1 || n == 2)
	{
		n_val = 1;
	}
	else
	{
		i = 3;
		while (i <= n)
		{
			n_val = n1 + n2;
			tmp = n2;
			n2 = n2 + n1;
			n1 = tmp;
			++i;
		}
	}
	return n_val;
}

int main()
{
	int n;
	int n_val = 0;
	printf("������n:");
	scanf("%d", &n);
	n_val = retfblax(n);
	printf("��n�����ǣ�%d\n",n_val);
	return 0;
}


//27��дһ���������ַ����ĳ���
#include <stdio.h>
#include <assert.h>
int Strlen(char * src)
{
	int length=0;
	assert(src);
	if (*src == '\0')
	{ return 0;}
	else
	{
		while(*src != '\0')
		{
			length++;
			src++;
		}
	}
	return length;
}

int main()
{
	int strlen = 0;
	char array[30];
	scanf("%s", array);
	strlen = Strlen(array);
	printf("�����ǣ�%d\n", strlen);
}


//28��������ʱ������һ���ַ����ĳ���
#include <stdio.h>
#include <assert.h>
int Strlen(char* src)
{
	assert(src);
	if (*src == '\0')
		return 0;
	return Strlen(src + 1) + 1;
}

int main()
{
	printf("%d\n",Strlen("hellowrold"));
	return 0;
}


//29 ������һ��������������ѡ������
#include <stdio.h>
int* SelectSort(int* array, int size)
{
	int i, j, tmp, pos;
	for (i = 0; i < size - 1; i++)
	{
		tmp = array[i];
		pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pos])
			{
				pos = j;
			}
		}
		if (pos != i)
		{
			tmp = array[pos];
			array[pos] = array[i];
			array[i] = tmp;
		}
	}
	return array;
}

int main()
{
	int i = 0;
	int arr[10] = {7,5,6,3,9,1,2,8,10,4};
	SelectSort(arr, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}


//30��һ�����Ķ�������1�ĸ���
#include <stdio.h>
int GetBinaryNum(int value)
{
	int count = 0;
	int i;
	for (i = 0; i < 31; i++)
	{
		if ((value >> i) & 1 == 1)
			count++;
	}
	return count;
}

int GetBinaryNum(int value)
{
	int count = 0;
	while (value)
	{
		value &= (value - 1);
		count++;
	}
	return count;
}

int main()
{
	printf("%d\n",GetBinaryNum(25));
	return 0;
}


//31 �жϴ�С��
#include <stdio.h>
int main()
{
	int a = 1;
	int * p = &a;
	char ch = *(char*)p;
	if (ch == 1)
	{
		printf("xiaoduan\n");
	}
	else
	{
		printf("daduan\n");
	}
	return 0;
}

#include<stdio.h>
int main()
{
	union a {
		char c;
		int b;
	}u;
	u.c = 1;

	if (u.b == 1)
	{
		printf("da\n");
	}
	else
	{
		printf("xiao\n");
	}
	return 0;
}


//32����������������������������
#include <stdio.h>
//#define Swap(a,b) {a=(a+b);b=(a-b);a=(a-b);}
#define Swap(a,b) {a ^= b ; b ^= a ;a ^= b;}
int main()
{
	int p, q;
	scanf("%d %d", &p, &q);
	Swap(p,q);
	printf("%d %d\n",p,q);
	return 0;
}


//33��1��100֮��9���ֵĴ���
#include <stdio.h>
int main()
{
	int count = 0;
	int i = 0, tmp = 0;
	for (i = 1; i <= 100; i++)
	{
		tmp = i;
		while (tmp)
		{
			if (tmp / 10 == 9)
				count++;
			tmp = i % 10;
			if (tmp == 9)
				count++;
			tmp = tmp / 10;
		}
	}
	printf("%d\n",count);
	return 0;
}


//34 1234 --> 1 2 3 4
#include <stdio.h>
void PutNum(int num)
{
	if (num == 0)
	{
		return;
	}
	PutNum(num / 10);
	printf("%d ",num%10);
}

int main()
{
	int a = 1234;
	PutNum(a);
	return 0;
}


//35����һ�ַ����е�ĳ���ַ���һ�γ��ֵ�λ�ã�������
#include <stdio.h>
char* FirstIn(char* src, char ch)
{
	if (src == NULL)
		return NULL;
	int pos = 0;
	while (*src != '\0')
	{
		if (*src == ch)
		{
			printf("%d\n", pos);
			return src;
		}
		pos++;
		src++;
	}
	return NULL;
}

int main()
{
	FirstIn("swrtyuio",'i');
	return 0;
}


//36���ַ�������
#include <stdio.h>
#include <assert.h>
char* Rever(char* str)
{
	assert(str);
	char* ret = str;
	char tmp;
	int left=0, right = 0;
	while (*str != '\0')
	{
		right++;
		str++;
	}
	right = right - 1;
	while (left < right)
	{
		tmp = ret[left];
		ret[left] = ret[right];
		ret[right] = tmp;
		left++;
		right--;
	}
	return ret;
}

int main()
{
	char str[] = "bit-tech";
	printf("%s\n",Rever(str));
	return 0;
}


//37intsubstr(char dst[],char src[],int start,int len)
#include <stdio.h>
#include <assert.h>
int substr(char dst[], char src[], int start, int len)
{
	assert(src);
	int i = 0, j = 0, ret = 0;
	while (i < len && src[start + 1] != '\0')
	{
		dst[j++] = src[start + i];
		i++;
		ret++;
	}
	dst[j] = '\0';
	printf("%s\n",dst);
	return ret;
}

int main()
{
	char str[20];
	char str2[25] = "hajsdahsasdas";
	substr(str, str2, 5, 6);
	return 0;
}


//38��ȡ�ַ�������дת��ΪСд�����಻��
#include <stdio.h>
int main()
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		if (ch >= 'A' && ch <= 'Z')
			ch = ch + 32;
		putchar(ch);
	}
	return 0;
}


//39����һ�ַ�����a���Z������b���Y������z���A��ʱ�临�Ӷ�ΪO��1��
#include <stdio.h>
int main()
{
	char ch; 
    while ((ch = getchar()) != '\n')
	{
		ch = 'Z' - (ch - 'a');
		printf("%c ", ch);
	}	
return 0;
}


//40 strcpy()
#include<stdio.h>
char* Strcpy(char* dst, char* src)
{
	if (src == NULL)
		return NULL;
	int i = 0;
	while (*src != '\0')
	{
		dst[i++] = *src;
		src++;
	}
	dst[i] = '\0';
	return dst;
}

int main()
{
	char  str1[20] = "";
	char* str2 = "hello world";
	printf("%s\n",Strcpy(str1,str2));
	return 0;
}


//41strcat
#include<stdio.h>
char* Strcat(char* dst, char* src)
{
	if (src == NULL)
		return NULL;
	int i = 0, j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
		dst[i++] = src[j++];
	dst[i] = '\0';
	return dst;
}

int main()
{
	char str1[20] = "hello ";
	char* str2 = "world";
	printf("%s\n",Strcat(str1,str2));
	return 0;
}


//42 strcmp
#include <stdio.h>
int Strcmp(char* des1, char* des2)
{
	int i = 0;
	if (des1 == NULL && des2 == NULL)
		return 0;
	if (des1 == NULL)
		return -1;
	if (des2 == NULL)
		return 1;
	while (des1[i] != '\0' && des2[i] != '\0')
	{
		if (des1[i] > des2[i])
			return 1;
		if (des1[i] < des2[i])
			return -1;
		i++;
	}
	if (des1[i] == '\0' && des2[i] == '\0')
		return 0;
	if (des1[i] == '\0')
		return -1;
	if (des2[i] == '\0')
		return 1;
}

#include<stdio.h>
int main()
{
	printf("%d\n",Strcmp("",""));
	printf("%d\n", Strcmp("ab", "bc"));
	printf("%d\n", Strcmp("ab", "abc"));
	printf("%d\n", Strcmp("abcd", "abc"));
	printf("%d\n", Strcmp("abc", "abc"));
	return 0;
}


//43memcopy
#include<stdio.h>
#include<assert.h>
void* Memcpy(void *dst, const void *src, size_t count)
{
	assert(dst);
	assert(src);
	char *ret = (char*)dst;
	char* dest = (char*)dst;
	char* tmp = (char*)src;
	while (count--)
	{
		*dest++ = *tmp++;
	}
	return ret;
}
int main()
{
		char str[12]="";
		char str2[10] ="heheh";
		Memcpy(str, str2, 5);
		printf("%s\n",str);
		return 0;
}

//44memmove
#include<stdio.h>
#include <assert.h>
void* Memmove(void* dst, const void* src, size_t count)
{
	assert(dst);
	assert(src);
	char* dest = (char*)dst;
	char* tmp = (char*)src;
	if (dest <= tmp)
	{
		while (count--)
			*dest++ = *tmp++;
	}
	else
	{
		dest = dest + count;
		tmp = tmp + count;
		while (count--)
			*dest-- = *tmp--;
	}
	return dst;
}

int main()
{
	char str[11]="helloworld";
	Memmove(str+1, str, 5);
	printf("%s\n",str);
	return 0;
}

//45memset
#include <stdio.h>
#include <assert.h>
void * Memset(void* dest, int c, size_t count)
{
	assert(dest);
	int *ret = (int*)dest;
	int *dst = (int*)dest;
	while (count--)
	{
		*dst++ = c;
	}
	return ret;
}

int main()
{
	int arr[100];
	Memset(arr, 0, 100);
	return 0;
}

//memmove test
#include <stdio.h>
#include <string.h>
int main()
{
	char str[11] = "helleworld";
	memmove(str, str + 1,5);
	printf("%s\n",str);
	return 0;
}


//46ʵ��atof
#include <stdio.h>
double Atof(char* str)
{
	if (str == NULL)
		return 0;
	int flag = 1, mod = 0;
	double count = 0;
	if (str[0] == '-')
		flag = -1;
	else if (str[0] == '+')
		flag = 1;
	else if (str[0] >= '0'&&str[0] <= '9')
	{
		count = str[0] - '0';
	}
	else
	{
		return 0;
	}
	str ++ ;
	//while (*str != '\0')
	while (*str>='0' && *str<='9'  ||  *str=='.')
	{
		if (*str == '.' && mod > 0)
			return count / mod;
		if (mod > 0)
			mod *= 10;
		if (*str == '.'&& mod == 0)
		{
			mod = 1;
			str++;
			continue;
		}
		count = count * 10 + *str - '0';
		str++;
	}
	if (mod)
		count = flag*count / mod;
	else
		count = flag*count;
	
	return count;
}

int main()
{
	printf("%f\n",Atof("-12.34"));
	return 0;
}


//47����ˮ
#include<stdio.h>

int Maxdrink(int n)
{
	int total = n;
	int empty = n;
	int tmp = 0;
	while (empty > 1)
	{
		if (empty % 2 != 0)  //����
		{
			tmp = 1; //������һ����ƿ
			total += (empty - 1) / 2;
			empty = (empty - 1) / 2;
			empty = empty + 1;
		}
		else     //ż��
		{
			total += empty / 2;
			empty = empty / 2;
		}
	}
	return total;
}

int main()
{
	printf("%d\n",Maxdrink(20));
	printf("%d\n",Maxdrink(21));
	return 0;
}


ע��һ��
//48 �ò����б���������ƽ��ֵ
#include <stdio.h>
#include <stdarg.h>

float Avarge(int val, ...)
{
	va_list arg;
	int count;
	float sum = 0;
	va_start(arg, val);
	for (count = 0; count < val; count++)
	{
		sum += va_arg(arg,int);
	}
	va_end(arg);
	return sum / val;
}

int main()
{

	printf("%f\n",Avarge(4,1,2,3,5));
	return 0;
}


//49��student a am iת��Ϊi am a student //�ռ临�Ӷ�Ϊ1
#include <stdio.h>
int main()
{
	char str[] = "student a am i";
	char ch;
	int i = 0, j = 0, k = 0, len = 0;
	while (str[i] != '\0')
	{
		k = i;
		j = i;
		len = 0;
		while (str[j] != ' ' && str[j] != '\0')
		{
			len++;
			j++;
		}
		if (len >= 1 )
		{
			i = i + len;
			len = k + len - 1;
			while (k < len)
			{
				ch = str[k];
				str[k] = str[len];
				str[len] = ch;
				k++;
				len--;
			}
		}
		else
			i = i + 1;
	}
	i = 0;
	j = 0;
	while(str[j] != '\0')
	{
		j++;
	}
	j = j - 1;
	while (i < j)
	{
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
		i++;
		j--;
	}
	printf("%s\n",str);
	return 0;
}


//50�����ҷ�ת
#include<stdio.h>
unsigned int  reverse_bit(unsigned int value)
{
	unsigned int val = 0;
	int i = 0;
	for (i = 0; i < 31; i++)
	{
		if (value & 1 == 1)
		{
			val = val | 1;
		}
		value >>= 1;
		val <<= 1;
	}
	return val;
}
int main()
{
	printf("%u\n",reverse_bit(25));
	return 0;
}