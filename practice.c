#include <stdio.h>

/*�ͻ�*/
typedef struct {
	int uid;
	char uname[20];
	int member;
	float ratio;
} USER;
/*��Ʒ*/
typedef struct {
	int gid;
	char productname[20];
	float price;
	int producttype;
} GOODS;

USER *findById(USER user[], int uid);
GOODS *findByGid(GOODS goods[], int gid);
float check(USER *user, GOODS *goods);
void printmsg_goods(GOODS *goods, int n);

USER sampleUser[] = { {0, " ", 0, 1},  {1, "����", 1, 0.9}, {2, "����", 2, 0.95}};
GOODS sampleGoods[] = { {1, "ȸ������", 48, 0},  {2, "���ȱ�", 60, 1}, {3, "�ɿ���", 48.8, 1}, {4, "������", 118, 1}};

int main()
{
	int id;
	int gid;
	float price;
	char key = 'y';
	USER *muser;
	int gidnum[4][2] = {};
	printf("������ͻ�id: ");
	scanf("%d", &id);
	muser = findById(sampleUser, id);
	if(muser)
	{
		printf("�ͻ���Ϣ��\n");
		printf("�ͻ�ID:%d\n�ͻ�������%s\n�ۿۣ�%.2f\n", muser->uid,muser->uname,muser->ratio);
	}
	while(key == 'y')
	{	
	static int i = 0;
	printf("��������Ʒ���: ");
	scanf("%d", &gidnum[i][0]);	
	printf("�����빺������������\n");
	scanf("%d",&gidnum[i][1]);
	printf("�Ƿ���Ҫ��������Ʒ��yes or no?\n");
	scanf("%s",&key);
	i++;
	}
	printf("�����嵥��\n");
	printf("---------*****---------\n");
	printf("��� ���� ���� �ؼ� ����\t\n");

	for(int i = 0; i < 4; i++)
	{

		GOODS *igoods;
		igoods = findByGid(sampleGoods, gidnum[i][0]);
		if(igoods)
		{
			printmsg_goods(igoods, gidnum[i][1]);
			price += gidnum[i][1]*check(muser,igoods);
		}	
	}
	printf("�շѣ�%.2f", price);
}
/*ͨ���û�ID��ѯ�û���Ϣ*/
USER *findById(USER user[],int uid)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if(user[i].uid == uid)
		{
			return &user[i];
		}
	}
	
	return 0;
}
/*ͨ����Ʒ��Ų�ѯ��Ʒ��Ϣ*/
GOODS *findByGid(GOODS goods[], int gid)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if(goods[i].gid == gid)
		{
			return &goods[i];
		}
	}
	
	return 0;
}
/*����*/
float check(USER *user, GOODS *goods)
{
	float count;
	count = goods->price * (user->ratio + goods->producttype * (1 - user->ratio));
	return count;
}
/*��ӡ��Ʒ��Ϣ*/
void printmsg_goods(GOODS *goods, int n)
{
	printf("%d %s %.2f %d %d\n", goods->gid,goods->productname,goods->price,goods->producttype,n);	
}
