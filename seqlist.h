#define	MAXSIZE  100   /*此处的宏定义常量表示线性表可能达到的最大长度*/
struct Student
{
	int snumber;
	char name[20];
	char sex[20];
	char project[20];
	int classes; 
	int classa;
	int number;
	float grades[20];
	float sum;
	float avg;
	float min;
	float max;
};


struct Judge
{
	char name[20];
	char sex[10];
	int telnumber;
};

typedef struct Judge ElemType1;
typedef struct Student ElemType;

typedef struct
{
	ElemType  elem[MAXSIZE];  /*线性表占用的数组空间*/
	ElemType1  elem1[MAXSIZE];
	int last; 
    int last2;
	   /*记录线性表中最后一个元素在数组elem[ ]中的位置（下标值），空表置为-1*/
}seqlist;

