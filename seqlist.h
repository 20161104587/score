#define	MAXSIZE  100   /*�˴��ĺ궨�峣����ʾ���Ա���ܴﵽ����󳤶�*/
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
	ElemType  elem[MAXSIZE];  /*���Ա�ռ�õ�����ռ�*/
	ElemType1  elem1[MAXSIZE];
	int last; 
    int last2;
	   /*��¼���Ա������һ��Ԫ��������elem[ ]�е�λ�ã��±�ֵ�����ձ���Ϊ-1*/
}seqlist;

