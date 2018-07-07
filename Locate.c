#include "common.h"
#include "seqlist.h"

int  Locate(seqlist L,int snumber)
{
	int i=0;
	while ((i<=L.last)&&(L.elem[i].snumber!=snumber))
		i++;
	if  (i<=L.last)
	{
		printf("��ѡ����Ϣ�����Ա��е�λ��Ϊ:%d\n",i+1);
		return(i+1);
	}

	else
	{
		printf("�ڴ����Ա���û�и�Ԫ��!\n");
		return(-1);

	}
}






void search(seqlist *L)
{
	int q,temp;
	printf("������Ҫ���ҵ�ѡ�ֱ��:\n");
	scanf("%d",&q);
	temp=Locate(*L,q);
	if(temp!=-1)
    {
        printf("���-----����-----�Ա�-----��Ŀ����------��Ŀ���------�༶-------�绰����\n");
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

	printf("������Ҫɾ����ѡ�ֱ��:\n");
	scanf("%d",&q);
	i=Locate(*L,q);

	if(i<1||i>L->last+1)
	{
		printf("λ��%d�����ڵ�Ԫ��\n",i);
	}
	for(j=i;j<=L->last;j++)
		L->elem[j-1]=L->elem[j];
	L->last--;
	printf("λ��Ϊ%d��Ԫ���Ѿ�ɾ��\n",i);
	onput(L);
}






int Insert(seqlist *L)
{
	ElemType x;
	int q,i,j;

	printf("������Ҫ�����ѡ����Ϣ(�ֱ�Ϊѡ�ֱ�ţ��������Ա𣬽�Ŀ���ƣ���Ŀ��𣬰༶���绰���룬����):\n");
	printf("����ѡ����Ϣ�����Ϊ��");
	scanf("%d",&x.snumber);
	printf("����ѡ����Ϣ������Ϊ��");
	scanf("%s",x.name); 
	printf("����ѡ����Ϣ���Ա�Ϊ��");
	scanf("%d",x.sex);
	printf("����ѡ����Ϣ����Ŀ����Ϊ��");
	scanf("%d",x.project);
	printf("����ѡ����Ϣ����Ŀ���Ϊ��");
	scanf("%d",&x.classa);
	printf("����ѡ����Ϣ���༶Ϊ��");
	scanf("%d",&x.classa);
	printf("����ѡ����Ϣ���绰����Ϊ��");
	scanf("%d",&x.number);
	printf("����ѡ����Ϣ������Ϊ��");
	for(j=0;j<=L->last2;j++)
		{
			scanf("%f",&x.grades[j]);
		}
	printf("������Ҫ�����ѧ����Ϣ��λ��:\n");
	scanf("%d",&q);
	i=Locate(*L,q);


	if(L->last==MAXSIZE-1)
	{
		printf(" ����\n");
		return 0;
	}
	if(i<1)
	{
		printf("λ�򲻺Ϸ�\n");
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
	printf("������ѡ�ָ���:");
	scanf("%d",&r);

	L->last = r-1;
	printf("������ѡ����Ϣ(�ֱ�Ϊѡ�ֱ�ţ��������Ա𣬽�Ŀ���ƣ���Ŀ��𣬰༶���绰����,����):\n");
	for(i=0; i<=r-1; i++)
	{
		
		printf("����ѡ����Ϣ�����Ϊ��");
		scanf("%d",&L->elem[i].snumber);
		printf("����ѡ����Ϣ������Ϊ��");
		scanf("%s",L->elem[i].name);
		printf("����ѡ����Ϣ���Ա�Ϊ��");
		scanf("%s",L->elem[i].sex);
		printf("����ѡ����Ϣ����Ŀ����Ϊ��");
		scanf("%s",L->elem[i].project);
		printf("����ѡ����Ϣ����Ŀ���Ϊ��");
		scanf("%d",&L->elem[i].classes);
		printf("����ѡ����Ϣ���༶Ϊ��");
		scanf("%d",&L->elem[i].classa);
		printf("����ѡ����Ϣ���绰����Ϊ��");
		scanf("%d",&L->elem[i].number);
		printf("����ѡ����Ϣ������Ϊ��");
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
	printf("��������ί����:");
	scanf("%d",&r);
	L->last2 = r-1;
	printf("��������ί��Ϣ(�ֱ�Ϊ�������Ա𣬵绰����):\n");
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
	printf("�ִ���ί��Ϣ��\n");
	int i;
	printf("����-----�Ա�-----�绰����\n");
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
	printf("�ִ�ѡ����Ϣ��\n");
	int i,j;
	printf("ѡ�ֱ��-----����-----�Ա�-----��Ŀ����------��Ŀ���-------�༶------�绰����--------�ܷ�----ƽ����\n");
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
	printf("�ִ�ѡ����Ϣ��\n");
	int i,j;
	printf("ѡ�ֱ��-----����-------����\n");
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
    temp=fopen("ѡ����Ϣ.csv","w");
    if(temp==NULL)
    {
        printf("�ļ���ʧ�ܣ������޷����棡\n");
        return ;
    }
    int i,j;
    fprintf(temp,"ѡ�ֱ��----����----�Ա�----��Ŀ����-----��Ŀ���-----�༶------�绰����----�ɼ�\n");
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
	printf("�ļ��ɹ����浽��ѡ����Ϣ.csv����\n");
}





void save1(seqlist *L)
{
    FILE *temp;
    temp=fopen("��ί��Ϣ.csv","w");
    if(temp==NULL)
    {
        printf("�ļ���ʧ�ܣ������޷����棡\n");

    }
    int i;
    fprintf(temp,"��ί����-----�Ա�------�绰����\n");
    for(i=0;i<=L->last2;i++)
	{
		fprintf(temp,"%s,",L->elem1[i].name);
        fprintf(temp,"%s,",L->elem1[i].sex);
        fprintf(temp,"%d\n",L->elem1[i].telnumber);
	}
	printf("�ļ��ɹ����浽����ί��Ϣ.csv����\n");
}





void Updata(seqlist *L)
{
    int tem,i,q,j;
    printf("������Ҫ�޸ĵ�ѡ�ֱ�ţ�\n");
    scanf("%d",&tem);
    q=Locate(*L,tem)-1;
    if(q==-1)
    {
        printf("��Ҫ�޸ĵ�Ԫ�ز����ڣ�\n");
        return ;
    }
    else
    {
        printf("�������ȥѡ�ֱ���������Ϣ�������Ա𣬽�Ŀ���ƣ���Ŀ��𣬰༶���绰����,�ɼ�):\n");
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
        printf("��Ϣ�޸���ɣ�\n");
    }
}


void menu()
{
	seqlist l;
	int n;
	while(1)
	{
		printf("\t                     1.����ѡ����Ϣ                           \n");
		printf("\t                     2.��ѯѡ����Ϣ                           \n");
		printf("\t                     3.����ѡ����Ϣ                           \n");
		printf("\t                     4.�޸�ѡ����Ϣ                           \n");
		printf("\t                     5.ɾ��ѡ����Ϣ                           \n");
		printf("\t                     6.�������ѡ����Ϣ                       \n");
		printf("\t                     7.�˳�������ѡ����Ϣ                     \n");
		printf("\t                     8.������ί��Ϣ                           \n");
		printf("\t                     9.���������ί��Ϣ                       \n");
		printf("\t                     10.�������ѧ���ɼ�                      \n");
		printf("\t                     11.������ί��Ϣ                           \n");
		printf("������1-10:");
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
