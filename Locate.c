#include "common.h"
#include "seqlist.h"

int  Locate(seqlist L,int snumber)
{
	int i=0;
	while ((i<=L.last)&&(L.elem[i].snumber!=snumber))
		i++;
	if  (i<=L.last)
	{
		printf("该选手信息在线性表中的位置为:%d\n",i+1);
		return(i+1);
	}

	else
	{
		printf("在此线性表中没有该元素!\n");
		return(-1);

	}
}






void search(seqlist *L)
{
	int q,temp;
	printf("请输入要查找的选手编号:\n");
	scanf("%d",&q);
	temp=Locate(*L,q);
	if(temp!=-1)
    {
        printf("编号-----姓名-----性别-----节目名称------节目类别------班级-------电话号码\n");
        printf("%-13d",L->elem[temp-1].snumber);
		printf("%-9s",L->elem[temp-1].name);
		printf("%-9s",L->elem[temp-1].sex);
		printf("%-15s",L->elem[temp-1].project);
		printf("%-14d",L->elem[temp-1].classes);
		printf("%-10d",L->elem[temp-1].classa);
		printf("%-13d\n",L->elem[temp-1].number);
    }
}






void Delete(seqlist *L)
{
	int j;
	int i,q;

	printf("请输入要删除的选手编号:\n");
	scanf("%d",&q);
	i=Locate(*L,q);

	if(i<1||i>L->last+1)
	{
		printf("位序%d不存在的元素\n",i);
	}
	for(j=i;j<=L->last;j++)
		L->elem[j-1]=L->elem[j];
	L->last--;
	printf("位序为%d的元素已经删除\n",i);
	onput(L);
}






int Insert(seqlist *L)
{
	ElemType x;
	int q,i,j;

	printf("请输入要插入的选手信息(分别为选手编号，姓名，性别，节目名称，节目类别，班级，电话号码，评分):\n");
	printf("输入选手信息，编号为：");
	scanf("%d",&x.snumber);
	printf("输入选手信息，姓名为：");
	scanf("%s",x.name); 
	printf("输入选手信息，性别为：");
	scanf("%d",x.sex);
	printf("输入选手信息，节目名称为：");
	scanf("%d",x.project);
	printf("输入选手信息，节目类别为：");
	scanf("%d",&x.classa);
	printf("输入选手信息，班级为：");
	scanf("%d",&x.classa);
	printf("输入选手信息，电话号码为：");
	scanf("%d",&x.number);
	printf("输入选手信息，评分为：");
	for(j=0;j<=L->last2;j++)
		{
			scanf("%f",&x.grades[j]);
		}
	printf("请输入要插入的学生信息的位置:\n");
	scanf("%d",&q);
	i=Locate(*L,q);


	if(L->last==MAXSIZE-1)
	{
		printf(" 表满\n");
		return 0;
	}
	if(i<1)
	{
		printf("位序不合法\n");
		return 0;
	}
	for(j=L->last;j>=i-1;j--)
		L->elem[j+1]=L->elem[j];
	L->elem[i-1]=x;
	L->last++;
	onput(L);
	return 0;
}




void swap(ElemType *a, ElemType *b)
{
    ElemType temp;

    temp = *a;
    *a = *b;
    *b = temp;

    return ;
}






void quicksort(ElemType array[], int maxlen, int begin, int end)
{
    int i, j;

    if(begin < end)
    {
        i = begin + 1;
        j = end; 

        while(i < j)
        {
            if(array[i].snumber > array[begin].snumber) 
            {
                swap(&array[i], &array[j]);
                j--;
            }
            else
            {
                i++;
            }
        }

        if(array[i].snumber >= array[begin].snumber) 
        {
            i--;
        }

        swap(&array[begin], &array[i]); 

        quicksort(array, maxlen, begin, i);
        quicksort(array, maxlen, j, end);
    }
}





void add(seqlist *L)
{
	int r,i;
	int j;
	printf("请输入选手个数:");
	scanf("%d",&r);

	L->last = r-1;
	printf("请输入选手信息(分别为选手编号，姓名，性别，节目名称，节目类别，班级，电话号码,评分):\n");
	for(i=0; i<=r-1; i++)
	{
		
		printf("输入选手信息，编号为：");
		scanf("%d",&L->elem[i].snumber);
		printf("输入选手信息，姓名为：");
		scanf("%s",L->elem[i].name);
		printf("输入选手信息，性别为：");
		scanf("%s",L->elem[i].sex);
		printf("输入选手信息，节目名称为：");
		scanf("%s",L->elem[i].project);
		printf("输入选手信息，节目类别为：");
		scanf("%d",&L->elem[i].classes);
		printf("输入选手信息，班级为：");
		scanf("%d",&L->elem[i].classa);
		printf("输入选手信息，电话号码为：");
		scanf("%d",&L->elem[i].number);
		printf("输入选手信息，评分为：");
		L->elem[i].max=0;
		L->elem[i].min=100;
		L->elem[i].sum=0;
		for(j=0;j<=L->last2;j++)
		{
			scanf("%f",&L->elem[i].grades[j]);
			if(L->elem[i].max<L->elem[i].grades[j])
				L->elem[i].max=L->elem[i].grades[j];
			if(L->elem[i].min>L->elem[i].grades[j])
				L->elem[i].min=L->elem[i].grades[j];
			L->elem[i].sum=L->elem[i].sum+L->elem[i].grades[j];
		}
		L->elem[i].avg=(L->elem[i].sum-L->elem[i].max-L->elem[i].max)/(L->last2-1);
	}
	onput(L);
}





void addjudge(seqlist *L)
{
	int r,i;
	printf("请输入评委个数:");
	scanf("%d",&r);
	L->last2 = r-1;
	printf("请输入评委信息(分别为姓名，性别，电话号码):\n");
	for(i=0; i<=r-1; i++)
	{
		scanf("%s",L->elem1[i].name);
		scanf("%s",L->elem1[i].sex);
		scanf("%d",&L->elem1[i].telnumber);
	}
	onputjudge(L);
}




void onputjudge(seqlist *L)
{
	printf("现存评委信息：\n");
	int i;
	printf("姓名-----性别-----电话号码\n");
	for(i=0;i<=L->last2;i++)
	{
		printf("%-9s",L->elem1[i].name);
		printf("%-9s",L->elem1[i].sex);
		printf("%-9d\n",L->elem1[i].telnumber);
	}
}


void onput(seqlist *L)
{
	quicksort(L->elem, L->last+1, 0, L->last);
	printf("现存选手信息：\n");
	int i,j;
	printf("选手编号-----姓名-----性别-----节目名称------节目类别-------班级------电话号码--------总分----平均分\n");
	for(i=0;i<=L->last;i++)
	{
		printf("%-13d",L->elem[i].snumber);
		printf("%-9s",L->elem[i].name);
		printf("%-9s",L->elem[i].sex);
		printf("%-15s",L->elem[i].project);
		printf("%-14d",L->elem[i].classes);
		printf("%-10d",L->elem[i].classa);
		printf("%-13d",L->elem[i].number);
		printf("%-10.2f",L->elem[i].sum);
		printf("%-10.2f\n",L->elem[i].avg);
	}
}




void onput1(seqlist *L)
{
	quicksort(L->elem, L->last+1, 0, L->last);
	printf("现存选手信息：\n");
	int i,j;
	printf("选手编号-----姓名-------分数\n");
	for(i=0;i<=L->last;i++)
	{
		printf("%-13d",L->elem[i].snumber);
		printf("%-9s",L->elem[i].name);
		for(j=0;j<=L->last2;j++)
		{
			printf("%.2f  ",L->elem[i].grades[j]);
		}
		printf("\n");
	}
}



void save(seqlist *L)
{
    FILE *temp;
    temp=fopen("选手信息.csv","w");
    if(temp==NULL)
    {
        printf("文件打开失败！数据无法保存！\n");
        return ;
    }
    int i,j;
    fprintf(temp,"选手编号----姓名----性别----节目名称-----节目类别-----班级------电话号码----成绩\n");
    for(i=0;i<=L->last;i++)
	{
		fprintf(temp,"%d,",L->elem[i].snumber);
        fprintf(temp,"%s,",L->elem[i].name);
        fprintf(temp,"%s,",L->elem[i].sex);
        fprintf(temp,"%s,",L->elem[i].project);
        fprintf(temp,"%d,",L->elem[i].classes);
        fprintf(temp,"%d,",L->elem[i].classa);
        fprintf(temp,"%d,",L->elem[i].number);
        for(j=0;j<=L->last2;j++)
		{
			fprintf(temp,"%.2f,",L->elem[i].grades[j]);
		}
	}
	printf("文件成功保存到《选手信息.csv》中\n");
}





void save1(seqlist *L)
{
    FILE *temp;
    temp=fopen("评委信息.csv","w");
    if(temp==NULL)
    {
        printf("文件打开失败！数据无法保存！\n");

    }
    int i;
    fprintf(temp,"评委姓名-----性别------电话号码\n");
    for(i=0;i<=L->last2;i++)
	{
		fprintf(temp,"%s,",L->elem1[i].name);
        fprintf(temp,"%s,",L->elem1[i].sex);
        fprintf(temp,"%d\n",L->elem1[i].telnumber);
	}
	printf("文件成功保存到《评委信息.csv》中\n");
}





void Updata(seqlist *L)
{
    int tem,i,q,j;
    printf("请输入要修改的选手编号：\n");
    scanf("%d",&tem);
    q=Locate(*L,tem)-1;
    if(q==-1)
    {
        printf("你要修改的元素不存在！\n");
        return ;
    }
    else
    {
        printf("请输入除去选手编号以外的信息姓名，性别，节目名称，节目类别，班级，电话号码,成绩):\n");
        scanf("%d",L->elem[i].snumber);
		scanf("%s",L->elem[i].name);
		scanf("%s",L->elem[i].sex);
		scanf("%s",&L->elem[i].project);
		scanf("%d",&L->elem[i].classes);
		scanf("%d",&L->elem[i].classa);
		scanf("%d",&L->elem[i].number);
		for(j=0;j<=L->last2;j++)
		{
			scanf("%f",&L->elem[i].grades[j]);
		}
        printf("信息修改完成！\n");
    }
}


void menu()
{
	seqlist l;
	int n;
	while(1)
	{
		printf("\t                     1.存入选手信息                           \n");
		printf("\t                     2.查询选手信息                           \n");
		printf("\t                     3.插入选手信息                           \n");
		printf("\t                     4.修改选手信息                           \n");
		printf("\t                     5.删除选手信息                           \n");
		printf("\t                     6.输出所有选手信息                       \n");
		printf("\t                     7.退出并保存选手信息                     \n");
		printf("\t                     8.存入评委信息                           \n");
		printf("\t                     9.输出所有评委信息                       \n");
		printf("\t                     10.输出所有学生成绩                      \n");
		printf("\t                     11.保存评委信息                           \n");
		printf("请输入1-10:");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : add(&l); break;
			case 2 : search(&l); break;
			case 3 : Insert(&l); break;
			case 4 : Updata(&l); break;
			case 5 : Delete(&l); break;
			case 6 : onput(&l); break;
			case 7 : save(&l); return 0;
			case 8 : addjudge(&l); break;
			case 9 : onputjudge(&l); break;
			case 10 : onput1(&l); break;
			case 11 : save1(&l); break;
		}
	}
}



void main()
{
	menu();
	return 0;
}
