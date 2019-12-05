#include <stdio.h>

/*客户*/
typedef struct {
	int uid;
	char uname[20];
	int member;
	float ratio;
} USER;
/*商品*/
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

USER sampleUser[] = { {0, " ", 0, 1},  {1, "张三", 1, 0.9}, {2, "李四", 2, 0.95}};
GOODS sampleGoods[] = { {1, "雀巢咖啡", 48, 0},  {2, "咖啡杯", 60, 1}, {3, "巧克力", 48.8, 1}, {4, "果粒茶", 118, 1}};

int main()
{
	int id;
	int gid;
	float price;
	char key = 'y';
	USER *muser;
	int gidnum[4][2] = {};
	printf("请输入客户id: ");
	scanf("%d", &id);
	muser = findById(sampleUser, id);
	if(muser)
	{
		printf("客户信息：\n");
		printf("客户ID:%d\n客户姓名：%s\n折扣：%.2f\n", muser->uid,muser->uname,muser->ratio);
	}
	while(key == 'y')
	{	
	static int i = 0;
	printf("请输入商品编号: ");
	scanf("%d", &gidnum[i][0]);	
	printf("请输入购买数量数量：\n");
	scanf("%d",&gidnum[i][1]);
	printf("是否需要买其它商品？yes or no?\n");
	scanf("%s",&key);
	i++;
	}
	printf("购物清单：\n");
	printf("---------*****---------\n");
	printf("编号 名称 单价 特价 数量\t\n");

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
	printf("收费：%.2f", price);
}
/*通过用户ID查询用户信息*/
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
/*通过商品编号查询商品信息*/
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
/*结算*/
float check(USER *user, GOODS *goods)
{
	float count;
	count = goods->price * (user->ratio + goods->producttype * (1 - user->ratio));
	return count;
}
/*打印商品信息*/
void printmsg_goods(GOODS *goods, int n)
{
	printf("%d %s %.2f %d %d\n", goods->gid,goods->productname,goods->price,goods->producttype,n);	
}
