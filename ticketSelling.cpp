#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#define H 8
#define L 8
struct order
{
	char yonghu[20];//已购票用户ID     
	char chang[20];//购买场次号   
	char  zuowei[20];//座位号码 
	int  duoshao;//购买票数 
	int  year;//购票月 
	int  month;//购票日 
	int  day;//购票时     
	float price;//票价     
	char st[20];//开始时间    
	char et[20];//结束时间    
	char yingyuan[20];//影院
	int  numorder;//订单号
	char movie[20];//电影名称 
};
struct order ode[99];//订单结构 

struct SES
{
	char number[20];//场次号
	char name[99];//电影名称 
	char place[100];//所属影院 
	int screen;//放映影厅
	char start_time[20];//电影开始时间 
	char end_time[20];//电影结束时间 
	char totaltime[20];//电影时长 
	int margin;//场次余票数
	float ticket;//场次票价  
	char kind[20];//场次放映类型
	char sort[20]; //放映影厅类型
	float discounts;//场次优惠活动
};
struct SES cin[99];//场次信息结构

struct BUY 
{
    char ID[20];//用户ID 
    char name[20];//姓名 
    char gender[20];//性别 
    char tele[20];//电话 
    char password[20];//密码 
    char mail[20];//邮箱 
    int balance;//账户余额 
}buy[100];
struct BUY user[99];//用户信息结构 

using namespace std;
struct movie
{
	char information[12][20];
};//查询结构 

struct ADM
{
	char ID[10];//管理员ID
	char place[20];//所属影院 
	char name[20];//姓名 
	char mail[99];//邮箱 
	char password[16];//密码 
};

struct ADM admin[99];//管理员信息结构 

struct cinema
{
	int ID;//影厅编号 
	char ying[20];//所属影院 
	char seat[20];//影厅总座位
	char kind[20];//影厅类型
	int hang;//影厅有多少行
	int lie;//影厅有多少列 
};
struct cinema hall[99];//影厅结构

struct GESHU
{
	char chang[20];//场次号
	int num;//场次订单数 
};
struct GESHU geshu[10];//场次与对应订单数 

struct LV
{
	char chang[20];//场次号
	float rate;//场次上座率 
};
struct LV lv[4];//场次与对应上座率

struct TOTAL
{
	char chang[20];//场次号
	float money;//场次总票价 
};
struct TOTAL total[4];//场次与对应总票价


struct YT
{
	int ting;//影厅号 
	float money;//影厅总票价 
};
struct YT yt[4];//影厅与对应总票价 


int testshu(char []);//验证函数 
void enter();//最初进入页面 
void userfunction();//用户功能 
void uregister();//用户注册 
 
void search_fn();//根据电影名查询
void selectkey();// 根据电影名与影院查询
void choose_sort();//根据2D、3D筛选电影
void choose_kind();// 根据英语、国语筛选电影
void search_price();//根据票价排序所有场次
void search_margin();//根据余票数排序所有场次
void search_time();//根据时间排序所有场次


int test_changci(char [20]);//检验用户输入场次号是否正确 
int test_time(char [],char []);//对比电影时间给出提醒 
int tuijian1(int [H][L],char getci[20],char zuoweihao[20]); //推荐一个座位并显示座位图函数 
int tuijian2(int [H][L],char getci[20],char zuoweihao[20]); //推荐两个座位并显示座位图函数
int tuijian3(int [H][L],char getci[20],char zuoweihao[20]); //推荐三个座位并显示座位图函数
int zizhu1(int [H][L]); //用户自己选一个座位函数 
int zizhu2(int [H][L]);//用户自己选俩个座位函数 
int zizhu3(int [H][L]); //用户自己选三个座位函数 
int test_shuliang(char []);//检测用户订单数量 
int test_same(char [],char []);//检测用户购买同一部影片 
void read_order();// dingdanA读取函数
void read_cin();//场次信息读取函数
void read_user();//userinformation读取函数
void goupiao();//  购票函数！！
void check_price(char [20],int,char getci[20]); //检验用户余额函数并充值 
int test_yu(int);// 检测余额 
void change_yu(char [20]);//充值后改变用户余额 
void change_yupiaoshu(char [],int);//改变余票数 


void read_user();
int test_phone(char []);//检验用户手机长度是否为十一位数字 
void change_phone(char []);//修改用户手机号码
int test_email();//检验用户手机号码格式 
void change_email(char []);//修改用户邮箱
int test_long(char []);//检验密码长度 
int testCODE(char[],char[]);// 检验确认密码输入正确 
void change_pass(char []);//修改用户密码 
void PIM(char []);//用户个人信息管理 


void change_yue(char []);//单独充值 
void inquiry_order(char [20]); 
void cancel_order();//取消订单 


void admfunction(char []);//管理员功能 
void admdenglu();//管理员登陆
void examine_order(char []);//管理员查询订单
void tongji_dingdan(char []);//管理员统计订单
void px_dingdan(char [20]);//排序场次订单数
void px_rate(char [20]);//排序场次上座率
void px_changci(char [20]);//排序场次总票价 
void px_yingting(char [20]);//排序影厅总票价 
void read_admin();//读取管理员文件信息 
void  examine_hall(char [20]);//管理员查询影厅信息 
void read_hall();//影厅信息进入函数 
void examine_chang(char [20]);//管理员查询所有开设的影厅信息 
void admin_pass(char []);
void admin_email(char []);
int test_email2(char []);//检验邮箱格式标准 
int test_long2(char [10]);//测试密码长度
int testCODE2(char [],char []);//检验确认密码输入正确
void increase_ci(char []);// 添加场次 
void increase_room(char []);// 添加新影厅 
int test_number(char numbera[]);//检验输入的影厅总座位为数字

int nameuser=0,nameode=0,namecin=0,nameadmin=0,namehall=0;
int i,n;
char userID[20]={'\0'}; 
char admID[20]={'\0'};

int main()
{
	enter(); //引用欢迎界面 
    return 0;
}







/****************************************最初进入页面*********************************************/ 


 void enter() 
{
	char step1[10]={'\0'};
    char choose1[10];
	char userpassword[20]={'\0'};
	char choose2[10]; 
	int h=0,q=0;
	int success=1;
	char a;
	printf("\n					    电影票销售系统\n");
	printf("****************************************************************************************************************\n						1.用户\n						2.管理员\n");//给出选择 
	printf("请输入您的选项：\n");
	scanf("%s",step1);//第一级选择 
	if(strlen(step1)>1)
	{
		printf("您输入的指令有误，请重新输入：\n");
		enter();
	}
	if(strcmp(step1,"1")==0)//当选择1用户选项时 
	{ 
		while(strcmp(choose1,"1")!=0&&strcmp(choose1,"2")!=0)
		{
			printf("****************************************************************************************************************\n						1.注册\n						2.登录\n						3.返回上一步\n");
	   		scanf("%s",choose1);//用户第二级选择 
		if(strcmp(choose1,"2")==0) //当用户选择登录时 
		{
	        int h=0;
	        printf("欢迎来到登录界面！\n");
	        FILE *inFile;
	        while(success&&q!=3)
	           {
		            printf("请输入您的ID账号:\n"); 
                    scanf("%s",userID); 
	                printf("请输入您的密码：\n");
	  	            scanf("%s",userpassword); 
	                inFile=fopen("userInformation.txt","r");
	                if(inFile==NULL)
	                 {
   		               	printf("未查询到您的账户，请核对后重新输入\n");
   		               	enter();
                     }
	                while(fscanf(inFile,"%s %s %s %s %s %s %d\n ",buy[h].ID,buy[h].name,buy[h].gender,buy[h].tele,
							buy[h].password,buy[h].mail,&buy[h].balance)!=EOF) 
		                {
		                    if (strcmp(userID,buy[h].ID)==0&&strcmp(userpassword,buy[h].password)==0)
		                       {
				                     printf("成功登录！\n"); 
			                     success=0;
			                     break;//如果匹配则跳出循环继续进行 
                               }
                               h++;
	                    }
	                if(success!=0)
	               {
	               		q++;
	               		printf("登陆失败，您还有%d次机会，请确认您的ID和密码\n",3-q);//不匹配时做出提醒 
				   }
	            }
	        fclose(inFile);
	        if(q==3)
	    		enter();
	    	else
	    	{
	    		userfunction();//用户进入功能页面 
			}
	       
		}
		else if (strcmp(choose1,"1")==0)
		{
			uregister();//用户注册
			enter();
		}
		else if (strcmp(choose1,"3")==0)
		{
			enter();
		}
		else
		{
			printf("您输入的指令有误，请重新输入：\n");
		}
		}
   	}
   	
   	else if(strcmp(step1,"2")==0)//当选择2管理员选项时
   	{
   	 	printf("****************************************************************************************************************\n						1.登陆\n						2.返回上一步\n");
	    scanf("%s",choose2);//管理员二级选择 
		if(strlen(choose2)>1)
		{
			printf("您输入的指令有误，请重新输入：\n");
			enter() ;
		}	
		if(strcmp(choose2,"1")==0)
		{
			admdenglu();//管理员登陆 
		}	
		if(strcmp(choose2,"2")==0)
		{
			printf("欢迎下次使用");
			enter();
		}
   	 	exit(0);
	}
	
	else
	{
		printf("您输入的数字有误请重新输入");
		enter();
	}
} 
//--------------注册------------ 
void uregister() 
{
	FILE*userInformation=fopen("userInformation.txt","a+");//文件
	char userpassword[20]={'\0'},userpassword2[20]={'\0'};
	char telephone[20]={'\0'};
	char youxiang[20]={'\0'};
	char username[20]={'\0'};
	char usergender[20]={'\0'};
	char ch[20]={'\0'};
	int  ok,i,zhi,pp;
	float charge;
	int Ybalance;
	char Scharge[20];
	//ID
	ok=1;
	int p=0;
    while(ok)
    {
        int a=0,b=0,c=0;
        printf("请创建您的账号,账号为由数字和字母组合成字符串，长度为6位到10位：\n");
        scanf("%s",userID);
        if(strlen(userID)<6||strlen(userID)>10) //检查账号的长度
        {
            printf("您输入的账号不符合位数要求要求，请重新创建！\n");
            a=1;
        }
        for (i=0;i<strlen(userID);i++)//检查账号是否都有数字和字母组成
        {
            if(isalpha(userID[i]) == 0 && isdigit(userID[i]) == 0)//既不是英文字母又不是数字 
            {
                printf("您输入的账号含有非法字符，请重新创建\n");
                b= 1;
                break;
            }    
        }
     	while(fscanf(userInformation,"%s""%s""%s""%s""%s""%s""%d",buy[p].ID,buy[p].name,buy[p].gender,buy[p].tele,
							buy[p].password,buy[p].mail,&buy[p].balance)!=EOF) 
		 {
		 	if(strcmp(buy[p].ID,userID)==0)
		 	{
		 		c=1;
		 		printf("帐户名称重复请重新输入ID：\n");
		 		break;
			 }
			 p++;
		 }
        if (a==0&&b==0&&c==0)
            ok=0;
        else
            ok=1;
    }
    
    //姓名
     printf("请输入您的姓名：\n"); 
     scanf("%s",username);
          
    //性别 
     ok=1;
     while(ok)
     {
     	printf("您的性别 请输入'man'or'woman'：\n");
     	scanf("%s",usergender);
     	if(strcmp(usergender,"man")==0||strcmp(usergender,"woman")==0)
     	{
	     	ok=0;
	     }
	     else
	     printf("您的性别输入有误，请重新输入"); 
     	
     }
     
     //联系电话
	ok=1;
	int k,a=0,b=0;
	while(ok) 
	{
		printf("请输入联系人的11位电话:\n");
		scanf("%s",telephone); 
		if(strlen(telephone)!=11)
			a=1;
		for(k=0;k<strlen(telephone);k++)
		{
			if(isdigit(telephone[k]) == 0)
		{
			b=1;
			break;
		}
		}
		if(a==0&&b==0)
		{
			ok=0;	
		}
		if(a!=0)
		{
			printf("输入联系人电话位数有误请重新输入：\n");
			a=0;
			b=0;
		}
		if(b!=0)
		{
			printf("输入联系人电话含非法字符请重新输入：\n");
			a=0;
			b=0;
		}
	}
    //密码
	ok=1;
    while(ok)
    {
        printf("请创建您的密码\n");
        scanf("%s",userpassword);
        printf("请再次输入您的密码\n");
        scanf("%s",userpassword2);
        if(strcmp(userpassword,userpassword2)!=0)
            printf("两次输入密码不同，请重新创建密码\n");
        else
            ok=0;
    }

	//邮箱
	printf("请输入邮箱(格式***@***.***):");
	scanf("%s",youxiang);
	pp=test_email2(youxiang);
	while(pp!=1)
	{
		
	    printf("邮箱不符合要求，请重新输入(格式***@***.***):");
		scanf("%s",youxiang);
		pp=test_email2(youxiang);
	}
     //充值 
     ok=1;
     while(ok)
     {
     	 printf("您是否充值账户：1.充值        2.不充值\n"); 
         scanf("%s",ch);
         if(strcmp(ch,"1")==0)
         {
     	       printf("请输入充值金额(整数）:\n");
     	       scanf("%s",Scharge);
 	        if(testshu(Scharge))
	        {
    	     	charge=atoi(Scharge);
    	     	if(charge>0)
     	        {
	             Ybalance=charge;
			     ok=0;
	            }
	            else
    	        {
     	    	printf("输入有误，请重新输入\n");
     	    	ok=1;
    	        }
    	     	
    	     }
    	     else
    	        {
     	    	printf("输入有误，请重新输入\n");
     	    	ok=1;
    	        }
 	     }
          
            
		else if(strcmp(ch,"2")==0)
            {Ybalance=0;
            ok=0;}
        else
       {
       	printf("输入有误，请重新输入\n");
     	    	ok=1;
       } 
             
          
     }
    
   	



    
    printf("恭喜您完成注册\n");
    system("pause");
    system("CLS");
    
    fprintf(userInformation,"%s %s %s %s %s %s %d\n",userID,userpassword,usergender,telephone,userpassword,youxiang,Ybalance);//写入文件 
    fclose(userInformation);
     
}


/******************************************管理员登陆*************************************/

 
void admdenglu()       
{	   
   	int h=0,q=0;
	int success=1;
	char admpassword[20]={'\0'};
	printf("欢迎来到管理员登录界面！\n");
    FILE *infile;
	while(success&&q!=3)
	           {
		            printf("请输入您的ID账号:\n"); 
                    scanf("%s",admID); 
	                printf("请输入您的密码：\n");
	  	            scanf("%s",admpassword); 
	                infile=fopen("admInformation.txt","r");
	                if(infile==NULL)
	                 {
   		               	printf("未查询到您的账户，请核对后重新输入\n");
   		               	enter();
                     }
	                while(fscanf(infile,"%s %s %s %s %s",admin[h].ID,admin[h].place,admin[h].name,admin[h].mail,admin[h].password)!=EOF) 
		                {
		                    if (strcmp(admID,admin[h].ID)==0&&strcmp(admpassword,admin[h].password)==0)
		                       {
				                     printf("成功登录！\n"); 
			                     success=0;
			                     break;//如果匹配则跳出循环继续进行 
                               }
                               h++;
	                    }
	                if(success!=0)
	               {
	               		q++;
	               		printf("登陆失败，您还有%d次机会，请确认您的ID和密码\n",3-q);//不匹配时做出提醒 
				   }
	            }
	        fclose(infile);
	        if(q==3)
	    		enter();
	    	else
	    	{
	    		admfunction(admID);//用户进入功能页面 
			}


}
 

/*******************************************用户功能*********************************/

void userfunction()//用户功能 
{ 
    
	int cnumber,fh,a=1;
	char Spage_num[20];
	while(a==1)
	{
		a=0; 
		int page_num,b=1;
		system("pause");
		system("CLS");
		printf("************************************************************************************************\n1.查询\n2.购票\n3.用户个人信息管理\n4.充值\n5.查询订单\n6.取消订单\n7.返回\n");
		scanf("%s",Spage_num);
		system("CLS");
		fh=testshu(Spage_num);
		if(fh==1)
		{
			page_num=atoi(Spage_num);
		}
		else
		{
			printf("输入错误，请输入正确数字\n");
			userfunction();
		}
		switch(page_num)
		{
			//选择查询方式 
			case 1:
			{
				while(b==1)
			    {
			        b=0;
					int chnumber2,fanh;
					char Schnumber2[20];
			        printf("1.根据影片名查询\n2.根据影片名+影院名查询\n3.用放映影厅类型3D、2D查询\n4.用放映场次类型英语、国语查询\n5.根据放映开始时间排序所有场次\n6.根据场次票价排序所有场次\n7.根据场次余票数排序所有场次\n"); 
					scanf("%s",Schnumber2);
					 fanh=testshu(Schnumber2);
					 if(fh==1)
		            {
			               chnumber2=atoi(Schnumber2);
		            }
	 	             else
		            {
		               printf("输入错误，请输入正确数字\n");
			            userfunction();
		             }
			        switch(chnumber2)
			        {
	                    case 1:
				        search_fn();//根据影片名查询
				        break; 
				        case 2:
                        selectkey();//根据影片名+影院名查询
                        break;
                        case 3:
                        choose_sort();//用放映影厅类型3D、4D查询
                        break;
                        case 4:
						choose_kind(); //用放映场次类型英语、国语查询
						break; 
						case 5:
                        search_time();//根据放映开始时间排序所有场次
                        break;
						case 6:
				        search_price();//根据场次票价排序所有场次
				        break;
						case 7:
                        search_margin(); //根据场次余票数排序所有场次
                        break;
						default:
                        printf("您的输入有误，请输入1-7\n");
		                userfunction();
		                b=1;
		            }
			    }
			}
  			goupiao();
			case 2:
            {
			goupiao();
			break;
            }
            case 3:
            {
  		        PIM(userID);
	       		break;
    	    }
			case 4:
			{
				change_yue(userID);
	       		break;
			} 
			case 5:
			{
				inquiry_order(userID);
	       		break;
			} 
			case 6:
			{
				cancel_order();
	       		break;
			}
			case 7:
			{
				enter();
			}
			default:
			printf("您的输入有误，请输入1-6\n");
		    userfunction();
			a=1; 
			
		}
	}



} //printf("\n您的输入有误，请重新输入");
			



/*********************************dingdanA读取函数****************************/


void read_order()
{
	i=0;
	FILE *infile;
	infile=fopen("dingdanA.txt","a+");	
	
	if(infile==NULL)
	{
		printf("无法获取订单信息"); 
		exit(1);
	}
	while(1)               
	{ 
	
		if(feof(infile))
			break;
			fscanf(infile,"%s %s %s %d %d %d %d %f %s %s %s %d %s",ode[i].yonghu,ode[i].chang,ode[i].zuowei,&ode[i].duoshao,&ode[i].year,&ode[i].month,&ode[i].day,&ode[i].price,ode[i].st,ode[i].et,ode[i].yingyuan,&ode[i].numorder,ode[i].movie);
		i++;
	}
	nameode=i-1;
}






/*********************************场次信息读取函数****************************/


void read_cin()
{
	i=0;
	FILE *infile;
	infile=fopen("场次信息.txt","a+");
	if(infile==NULL){
		printf("无法获取场次信息"); 
		exit(1);
	}
	while(1)
	{ 
		if(feof(infile))
			break;
		fscanf(infile,"%s %s %s %d %s %s %s %d %f %s %s %f",cin[i].number,cin[i].name,cin[i].place,&cin[i].screen,cin[i].start_time,cin[i].end_time,
		cin[i].totaltime,&cin[i].margin,&cin[i].ticket,cin[i].kind,cin[i].sort,&cin[i].discounts);
		i++; 
	}
	namecin=i;
} 
/***************************userinformation读取函数*******************************/ 
void read_user()
{
	i=0;
	FILE *infile;
	infile=fopen("userInformation.txt","a+");	
	
	if(infile==NULL)
	{
		printf("无法获取用户信息"); 
		exit(1);
	}
	while(1)               
	{ 
	
		if(feof(infile))
			break;
			fscanf(infile,"%s %s %s %s %s %s %d",user[i].ID,user[i].name,user[i].gender,user[i].tele,user[i].password,user[i].mail,&user[i].balance);
		
		i++;
	}
	nameuser=i;
}


/**********************************读取管理员信息函数********************************/

 
void read_admin()
{
	 i=0;
	FILE *infile;
	infile=fopen("admInformation.txt","a+");	
	
	if(infile==NULL)
	{
		printf("无法获取管理员信息"); 
		exit(1);
	}
	while(1)               
	{ 
	
		if(feof(infile))
			break;
			fscanf(infile,"%s %s %s %s %s",admin[i].ID,admin[i].place,admin[i].name,admin[i].mail,admin[i].password);
		
		i++;
	}
	nameadmin=i-1;
}

/*************************************读取影厅信息*********************************/ 
void read_hall()
{
    i=0;
	FILE *infile;
	infile=fopen("影厅信息.txt","a+");	
	
	if(infile==NULL)
	{
		printf("无法获取影厅信息"); 
		exit(1);
	}
	while(1)               
	{ 
	
		if(feof(infile))
			break;
			fscanf(infile,"%d %s %s %s  %d  %d",&hall[i].ID,hall[i].ying,hall[i].seat,hall[i].kind,&hall[i].hang,&hall[i].lie);
		i++;
	}
	namehall=i-1;
}


/***************************************查询函数************************************************/ 

void search_fn()
{
    system("CLS");
    char cho[10] ={'\0'};
	int okk=0,k=0;
	char p[20]={'\0'};//输入影片名 
	read_cin();
  	printf("请输入查询的电影名：\n");
  	scanf("%s",p);
  
    printf("---------------------------------------------------------------------------------------------------------\n");
   	printf("|场次号|电影名称|所属影院|放映影厅|电影开始时间|电影结束时间|电影时长|余票数|票价|影厅类型|场次类型|折扣|\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

	
	for(i=0;i<namecin;i++)
	{
		    if(strcmp(cin[i].name,p)==0)
 			{
		    printf("%s%12s  %s       %d       %s      %s        %s      %d      %.2f    %s   %s    %.2f\n\n",cin[i].number,cin[i].name,cin[i].place,cin[i].screen,cin[i].start_time,cin[i].end_time,
		            cin[i].totaltime,cin[i].margin,cin[i].ticket,cin[i].kind,cin[i].sort,cin[i].discounts);	
			okk=1;
		
			}
			else
			continue;		
 	} 
 	if(okk!=1)
 	{
	 	printf("未查到该电影有关信息，请重新输入\n");
	 	system("pause");
	    search_fn();
	 }
	else 
	{
	printf("返回主页面请输入 1      购票请输入  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	{
		printf("您输入的指令有误，请重新输入：\n");
		system("pause");
		search_fn();
	}
	if(strcmp(cho,"1")==0)
	userfunction();
	else if(strcmp(cho,"2")==0)
	goupiao();
	else
	{
		printf("您输入的数字有误请重新输入");
		system("pause");
		search_fn();
	}
		
    }
}
void selectkey()//根据电影名与影院查询 
{
    system("CLS");
	char cho[10] ={'\0'};
	int okk=0,k=0;
	char p[20]={'\0'};//输入影片名 
	char q[20]={'\0'};//输入影院名
	read_cin();
  	printf("请输入查询的电影名：\n");
  	scanf("%s",p);
    printf("请输入查询的影院名：\n");
  	scanf("%s",q);
    printf("---------------------------------------------------------------------------------------------------------\n");
   	printf("|场次号|电影名称|所属影院|放映影厅|电影开始时间|电影结束时间|电影时长|余票数|票价|影厅类型|场次类型|折扣|\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

	
	for(i=0;i<namecin;i++)
	{
		    if(strcmp(cin[i].name,p)==0&&strcmp(cin[i].place,q)==0)
 			{
		    printf("%s%12s  %s       %d       %s      %s        %s      %d      %.2f    %s   %s    %.2f\n\n",cin[i].number,cin[i].name,cin[i].place,cin[i].screen,cin[i].start_time,cin[i].end_time,
		            cin[i].totaltime,cin[i].margin,cin[i].ticket,cin[i].kind,cin[i].sort,cin[i].discounts);	
			okk=1;
		
			}
			else
			continue;		
 	} 
 	if(okk!=1)
 	{
	 	printf("未查到该电影有关信息，请重新输入\n");
	 	system("pause");
	    selectkey();
	 }
	else 
	{printf("返回主页面请输入 1      购票请输入  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	{
		printf("您输入的指令有误，请重新输入：\n");
		system("pause");
		selectkey();
	}
	if(strcmp(cho,"1")==0)
	userfunction();
	else if(strcmp(cho,"2")==0)
	goupiao();
	else
	{
		printf("您输入的数字有误请重新输入");
		system("pause");
		selectkey();
	}
	
	}
}
void choose_sort()//根据2D、3D筛选 
{
    system("CLS");
    char cho[10] ={'\0'};
	int testb=0;
	char entera[20];
	char chara[20]="3D",charb[20]="2D";
	read_cin();
	do
	{
		printf("请输入你想要查询的场次影厅类型");
	    printf("\n1.3D\n2.2D");
	    scanf("%s",entera);
	    if(strcmp(entera,"1")==0)
	    {
    		printf("---------------------------------------------------------------------------------------------------------\n");
	    	printf("|场次号|电影名称|所属影院|放映影厅|电影开始时间|电影结束时间|电影时长|余票数|票价|影厅类型|场次类型|折扣|\n");
		    printf("---------------------------------------------------------------------------------------------------------\n");
			for(i=0;i<namecin;i++)
    		{
				if(strcmp(chara,cin[i].sort)==0)
    			{ 
					printf("%s%12s  %s       %d       %s      %s        %s      %d      %.2f    %s   %s    %.2f\n",cin[i].number,cin[i].name,cin[i].place,cin[i].screen,cin[i].start_time,cin[i].end_time,
		            cin[i].totaltime,cin[i].margin,cin[i].ticket,cin[i].kind,cin[i].sort,cin[i].discounts);
    			}
    	
		    }
		    testb=1;
		    break; 
    	}
    	else if(strcmp(entera,"2")==0)
    	{
	    	printf("---------------------------------------------------------------------------------------------------------\n");
	    	printf("|场次号|电影名称|所属影院|放映影厅|电影开始时间|电影结束时间|电影时长|余票数|票价|影厅类型|场次类型|折扣|\n");
			printf("---------------------------------------------------------------------------------------------------------\n");
			for(i=0;i<namecin;i++)
    		{
    			if(strcmp(charb,cin[i].sort)==0)
    			{
					printf("%s%12s  %s       %d       %s      %s        %s      %d      %.2f    %s   %s    %.2f\n",cin[i].number,cin[i].name,cin[i].place,cin[i].screen,cin[i].start_time,cin[i].end_time,
		            cin[i].totaltime,cin[i].margin,cin[i].ticket,cin[i].kind,cin[i].sort,cin[i].discounts);
    			}
		    }
		    testb=1;
			break;  
	     }
	    else
	    {
		printf("您输入的数字有误请重新输入");
		testb=0;
	    }
	    
    }while(testb==0);
		
	{
	printf("返回主页面请输入 1      购票请输入  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	   {
		printf("您输入的指令有误，请重新输入：\n");
		system("pause");
		choose_sort();
	    }
	if(strcmp(cho,"1")==0)
	   userfunction();
	else if(strcmp(cho,"2")==0)
	     goupiao();
	else
	  {
		printf("您输入的数字有误,请重新输入:\n");
		system("pause");
		choose_sort();
	  }
	
	}
}
	
void choose_kind()
{	
	read_cin();
	system("CLS");
	char cho[10] ={'\0'};
	int testb=0;
	char entera[20];
	char chara[20]="国语",charb[20]="英语";
	do
	{
		printf("请输入你想要查询的影片类型\n");
	    printf("\n1.国语\n2.英语\n");
	    scanf("%s",entera);
	   if(strcmp(entera,"1")==0)
	    {
    		printf("---------------------------------------------------------------------------------------------------------\n");
	    	printf("|场次号|电影名称|所属影院|放映影厅|电影开始时间|电影结束时间|电影时长|余票数|票价|影厅类型|场次类型|折扣|\n");
		    printf("---------------------------------------------------------------------------------------------------------\n"); 
			for(i=0;i<namecin;i++)
    		{
				if(strcmp(chara,cin[i].kind)==0)
    			{
			    	printf("%s%12s  %s       %d       %s      %s        %s      %d      %.2f    %s   %s    %.2f\n",cin[i].number,cin[i].name,cin[i].place,cin[i].screen,cin[i].start_time,cin[i].end_time,
		            cin[i].totaltime,cin[i].margin,cin[i].ticket,cin[i].kind,cin[i].sort,cin[i].discounts);
    			}
    			else
    			continue;
		    }
		    testb=1;
		    break;
    	}
    	else if(strcmp(entera,"2")==0)
    	{
	    	printf("---------------------------------------------------------------------------------------------------------\n");
	    	printf("|场次号|电影名称|所属影院|放映影厅|电影开始时间|电影结束时间|电影时长|余票数|票价|影厅类型|场次类型|折扣|\n");
		    printf("---------------------------------------------------------------------------------------------------------\n");
			for(i=0;i<namecin;i++)
    		{
    			if(strcmp(charb,cin[i].kind)==0)
    			{
					printf("%s%12s  %s       %d       %s      %s        %s      %d      %.2f    %s   %s    %.2f\n",cin[i].number,cin[i].name,cin[i].place,cin[i].screen,cin[i].start_time,cin[i].end_time,
		            cin[i].totaltime,cin[i].margin,cin[i].ticket,cin[i].kind,cin[i].sort,cin[i].discounts);
    			}
		    }
		    testb=1;
			break;  
	    }
	   else
	    {
		printf("您输入的数字有误请重新输入");
		testb=0;
	    }
       }while(testb==0);
	{
	printf("返回主页面请输入 1      购票请输入  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	   {
		printf("您输入的指令有误，请重新输入：\n");
		system("pause");
		choose_kind();
	    }
	if(strcmp(cho,"1")==0)
	   userfunction();
	else if(strcmp(cho,"2")==0)
	     goupiao();
	else
	  {
		printf("您输入的数字有误,请重新输入:\n");
		system("pause");
		choose_kind();
	  }
	
	}
	
}

/***************************************排序函数************************************************/ 

void search_price()//根据票价排序所有场次
{
	int ok,i=0,fanhui;
	char cho[10] ={'\0'};
	system("cls"); 
	struct SES cin[20];
	FILE *fp1;
	fp1=fopen("场次信息.txt","r");//打开读取文件
	printf("\n             以下为根据票价的排序！！             \n");
	if(fp1==NULL)//检验文件是否打开 
	{
		printf("\n             未查询到，请核对后重新输入！\n");
		exit(1);
	}
	else
	{
		while(fscanf(fp1,"%s %s %s %d %s %s %s %d %f %s %s %f \n",cin[i].number,cin[i].name,
				cin[i].place,&cin[i].screen,cin[i].start_time,cin[i].end_time,cin[i].totaltime,
				&cin[i].margin,&cin[i].ticket,cin[i].kind,cin[i].sort,&cin[i].discounts)!=EOF)
		{
			i++;
		}	
	}
	//排序法
	int m,n; 
	struct SES k;
	for(m=0;m<=i-1;m++)
	{  
		for(n=0;n<=i-2-m;n++)
		{
	    	if(cin[n].ticket>cin[n+1].ticket)
	    	{  
				k=cin[n];
				cin[n]=cin[n+1];
				cin[n+1]=k;    	//票价由小到大排序	    
	       	}
		}
	}
		
	int p=0;
	printf("票价由低到高排序如下：\n");	
	for (;p<i;p++)
		{	
			printf("\n场次号：%s\n电影名称：%s\n所属影院：%s\n放映影厅：%d\n电影开始时间：%s\n电影结束时间：%s\n电影时长：%s\n场次余票数：%d\n场次票价：%.2f\n场次放映类型：%s\n放映影厅类型：%s\n该场次优惠活动：%f\n",
			cin[p].number,cin[p].name,cin[p].place,cin[p].screen,cin[p].start_time,cin[p].end_time,cin[p].totaltime,
				cin[p].margin,cin[p].ticket,cin[p].kind,cin[p].sort,cin[p].discounts);
		}
		 
	fclose(fp1);
	{
	printf("返回主页面请输入 1      购票请输入  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	   {
		printf("您输入的指令有误，请重新输入：\n");
		system("pause");
		search_price();
	    }
	if(strcmp(cho,"1")==0)
	   userfunction();
	else if(strcmp(cho,"2")==0)
	     goupiao();
	else
	  {
		printf("您输入的数字有误,请重新输入:\n");
		system("pause");
		choose_kind();
	  }
	
	}
}


void search_margin()//根据余票数排序所有场次
{
	int i=0;
	char cho[20];
	system("cls"); 
	struct SES cin[20];
	FILE *fp1;
	fp1=fopen("场次信息.txt","r");//打开读取文件
	printf("\n             以下为根据余票数的排序！！             \n");
	if(fp1==NULL)//检验文件是否打开 
	{
		printf("\n             未查询到，请核对后重新输入！\n");
		exit(1);
	}
	else
	{
		while(fscanf(fp1,"%s %s %s %d %s %s %s %d %f %s %s %f \n",cin[i].number,cin[i].name,
				cin[i].place,&cin[i].screen,cin[i].start_time,cin[i].end_time,cin[i].totaltime,
				&cin[i].margin,&cin[i].ticket,cin[i].kind,cin[i].sort,&cin[i].discounts)!=EOF)
		{
			i++;
		}	
	}
	//排序法
	int m,n; 
	struct SES k;
	for(m=0;m<=i-1;m++)
	{  
		for(n=0;n<=i-2-m;n++)
		{
	    	if(cin[n].margin>cin[n+1].margin)
	    	{  
				k=cin[n];
				cin[n]=cin[n+1];
				cin[n+1]=k;    	//余票数由小到大排序	    
	       	}
		}
	}
		
	int p=0;
	printf("余票数由低到高排序如下：\n");	
	for (;p<i;p++)
		{	
			printf("\n场次号：%s\n电影名称：%s\n所属影院：%s\n放映影厅：%d\n电影开始时间：%s\n电影结束时间：%s\n电影时长：%s\n场次余票数：%d\n场次票价：%.2f\n场次放映类型：%s\n放映影厅类型：%s\n该场次优惠活动：%f\n",
			cin[p].number,cin[p].name,cin[p].place,cin[p].screen,cin[p].start_time,cin[p].end_time,cin[p].totaltime,
				cin[p].margin,cin[p].ticket,cin[p].kind,cin[p].sort,cin[p].discounts);
		}
		 
	fclose(fp1);
	{
	printf("返回主页面请输入 1      购票请输入  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	   {
		printf("您输入的指令有误，请重新输入：\n");
		system("pause");
		search_margin();
	    }
	if(strcmp(cho,"1")==0)
	   userfunction();
	else if(strcmp(cho,"2")==0)
	     goupiao();
	else
	  {
		printf("您输入的数字有误,请重新输入:\n");
		system("pause");
		search_margin();
	  }
	
	}
	
}




void search_time()//根据开始时间排序所有场次
{
	int i=0;
	char cho[20];
	system("cls"); 
	struct SES cin[20];
	FILE *fp1;
	fp1=fopen("场次信息.txt","r");//打开读取文件
	printf("\n 以下为根据开始时间的排序！！             \n");
	if(fp1==NULL)//检验文件是否打开 
	{
		printf("\n             未查询到，请核对后重新输入！\n");
		exit(1);
	}
	else
	{
		while(fscanf(fp1,"%s %s %s %d %s %s %s %d %f %s %s %f \n",cin[i].number,cin[i].name,
				cin[i].place,&cin[i].screen,cin[i].start_time,cin[i].end_time,cin[i].totaltime,
				&cin[i].margin,&cin[i].ticket,cin[i].kind,cin[i].sort,&cin[i].discounts)!=EOF)
		{
			i++;
		}	
	}
	//排序法
	int m,n; 
	float o;
	struct SES k;
	for(m=0;m<=i-1;m++)
	{  
		for(n=0;n<=i-2-m;n++)
		{
			if(strcmp(cin[n].start_time,cin[n+1].start_time)>0)
	    	{  
				k=cin[n];
				cin[n]=cin[n+1];
				cin[n+1]=k;    	//开始时间由小到大排序	    
	       	}
		}
	}
		
	int p=0;
	printf("开始时间由低到高排序如下：\n");	
	for (;p<i;p++)
		{	
			printf("\n场次号：%s\n电影名称：%s\n所属影院：%s\n放映影厅：%d\n电影开始时间：%s\n电影结束时间：%s\n电影时长：%s\n场次余票数：%d\n场次票价：%.2f\n场次放映类型：%s\n放映影厅类型：%s\n该场次优惠活动：%f\n",
			cin[p].number,cin[p].name,cin[p].place,cin[p].screen,cin[p].start_time,cin[p].end_time,cin[p].totaltime,
				cin[p].margin,cin[p].ticket,cin[p].kind,cin[p].sort,cin[p].discounts);
		}
		 
	fclose(fp1);
	
	{
	printf("返回主页面请输入 1      购票请输入  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	   {
		printf("您输入的指令有误，请重新输入：\n");
		system("pause");
		search_time();
	    }
	if(strcmp(cho,"1")==0)
	   userfunction();
	else if(strcmp(cho,"2")==0)
	     goupiao();
	else
	  {
		printf("您输入的数字有误,请重新输入:\n");
		system("pause");
		search_time();
	  }
	
	}
}


/*********************************购票函数************************************/ 

void goupiao()
{

	int Jshuliang,Jdianying=0,shi,yue,ri;
	int i,j,x,y,s,d=0;
	int dijige=0;
	int Ttime,Tpiaoshu,fangshi,piaoshu,count=0;
	char Spiaoshu[10];
	char Sfangshi[10];
	int ok=1;
	int a[H][L]={0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,};
    char zuoweihao[20];
    char zzz[20];
    char getci[20];
   	read_order();
	read_cin();
    read_user(); 
	/*显示你选择的场次的所有信息*/ 
	do{
	printf("请输入你想要选择的场次");
	scanf("%s",getci);}while(test_changci(getci)) ; 
    Ttime=test_time(userID,getci);
	if(Ttime==1)
	{;}
	else
	goupiao();
    for(i=0;i<namecin;i++)
    {
    	if(strcmp(getci,cin[i].number)==0)
    	{
    	   Jdianying=test_same(userID,cin[i].name); 
    	   if(Jdianying==1)
          { 
		    system("CLS");
			printf("\n场次号 电影名称 所属影院 放映影厅 电影开始时间 结束时间  电影时长 场次余票数 场次票价 放映类型 放映影厅类型 场次优惠活动\n");
	        printf("%s   %s  %s   %d      %s        %s      %s       %d          %.2f      %s      %s      %.2f",cin[i].number,cin[i].name,cin[i].place,cin[i].screen,cin[i].start_time,cin[i].end_time,
		    cin[i].totaltime,cin[i].margin,cin[i].ticket,cin[i].kind,cin[i].sort,cin[i].discounts);}
        if(Jdianying==2)
          goupiao(); 
    	      
		 } 
    }
    
    
 	i=0;
	 do
    {
    
		if(strcmp(getci,ode[i].chang)==0)
	 { 	
    	switch(ode[i].duoshao)
    	{
	    	case 1:
	    	strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
			strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 2:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 3:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+4,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+5,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
    	}
      }i++;
    }while(i<50);
 	
	printf("\n\n\n         电影院座位表：\n");
	printf("列1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" ▇ ");
		else 
			printf(" □ ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
	printf(" \n(▇ 代表此座位已经有人，请选择 □处的座位)\n");
	while(ok) 
	{
	    printf("\n请输入要购电影票数(最多购买3张):\n");
	    scanf("%s",Spiaoshu);
	
		if(strcmp(Spiaoshu,"1")==0||strcmp(Spiaoshu,"2")==0||strcmp(Spiaoshu,"3")==0)
		ok=0;
		else
		printf("您的输入有误，请重新输入\n");
	}
     piaoshu=atoi(Spiaoshu);
	printf("*****************请选择购票方式*****************\n");
	
	
	ok=1;
	while(ok) 
	{
	    printf("1.自主选票           2.推荐选票\n");
	    scanf("%s",Sfangshi);
	
		if(strcmp(Sfangshi,"1")==0||strcmp(Sfangshi,"2")==0)
		ok=0;
		else
		printf("您的输入有误，请重新输入\n");
	}
	fangshi=atoi(Sfangshi);
	switch(fangshi)
	{
		case 1:
		switch(piaoshu)
		{ 
		    case 1:
		    itoa(zizhu1(a), zzz, 10);
			break;
            case 2:
            itoa(zizhu2(a), zzz, 10);
			break;
			case 3:
		    itoa(zizhu3(a), zzz, 10);
			break;
		}			
							
		    break;
		
		case 2:
		switch(piaoshu)
		{
			case 1:
			itoa(tuijian1(a,getci,zuoweihao), zzz, 10);
			break;
			case 2:
			itoa(tuijian2(a,getci,zuoweihao), zzz, 10);
			break;
			case 3:
			itoa(tuijian3(a,getci,zuoweihao), zzz, 10);
			break;
		}
		break;
		
	}
	 
	
	
 	i=0;
	 do
    {
    
		if(strcmp(getci,ode[i].chang)==0)
	 { 	
    	switch(ode[i].duoshao)
    	{
	    	case 1:
	    	strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
			strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 2:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 3:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+4,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+5,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
    	}
      }i++;
    }while(i<20);
    system("CLS");
	printf("         电影院座位表：\n");
	printf("列1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j]==1)
			printf(" ▇ ");
		else 
			printf(" □ ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
	
	for(i=0;i<namecin;i++)
    {
    	if(strcmp(getci,cin[i].number)==0)
    	dijige=i; 
    }
 	
 	
 	FILE *infile;
	infile=fopen("dingdanA.txt","a");	
	
	if(infile==NULL)
	{
		printf("无法获取订单信息"); 
		exit(1);
	}
	
	Jshuliang=test_shuliang(userID);
    if(Jshuliang<5)
	{;} 
    else
    {
    	printf("一个用户一天最多购买五个订单，您今日已达到最大额度无法继续购买\n");
    	enter();
    }
	     //完成购票，输入下单日期，以生成订单 
	time_t timer;
   struct tm *tblock;
    timer=time(NULL);
    tblock=localtime(&timer);
    yue = tblock->tm_mon+1;//月
    ri= tblock->tm_mday;//日
    shi = tblock->tm_hour;//时
    check_price(userID,piaoshu,getci); 
    system("pause");
    nameode=nameode+1; 
	fprintf(infile,"%s       %s        %s        %d        %d       %d         %d       %.2f       %s        %s       %s        %d     %s\n",userID,getci,zzz,piaoshu,yue,ri,shi,cin[dijige].ticket,cin[dijige].start_time,cin[dijige].end_time,cin[dijige].place,nameode,cin[dijige].name);	
	system("CLS");
	printf("订单已生成！\n您的订单信息如下\n\n");
	printf("ID号码:    %s\n购买场次号:   %s\n座位号码:   %s\n购买票数:  %d\n购票日期：%d月%d日%d时\n票价：  %.2f元\n开始时间： %s    结束时间：  %s\n影院名：  %s\n订单号： %d\n电影名称：   %s\n",userID,getci,zzz,piaoshu,yue,ri,shi,cin[dijige].ticket,cin[dijige].start_time,cin[dijige].end_time,cin[dijige].place,nameode,cin[dijige].name); 
	printf("恭喜您完成购票!!!\n");
	change_yupiaoshu(getci,piaoshu);
	fclose(infile);
	printf("请点击任意键进入功能函数\n");
    userfunction(); 

}




/******************************检测电影时间冲突函数********************************/    

int test_time(char getid[20],char chang[20])
{
	read_cin();
	read_order(); 
	char start[20],end[20],ostart[20],oend[20];
	int j=0,k=0;
	int l=0,m=0;
	int y=0,t=0;
	int o=0,g=0;
	int testnumcheck=0,check_a=1;
	char Stestnumcheck[20];
	int testnumcheck2=0;
	char Stestnumcheck2[20];
	int an[20],bn[20];
	int ane[20],bne[20];
	int af[20],bf[20];
	int afe[20],bfe[20];
	int aaa[20],bbb[20];
	int ccc[20],ddd[20];
	 
	//把所有的字符型时间都化为整数，前两位后两位形式
	for(k=0;k<nameode;k++)//订单开始时间 
	{
		strncpy(start,ode[k].st,2);
	    an[k]=atoi(start);
    	strncpy(start,ode[k].st+3,2); 
    	bn[k]=atoi(start);	
	}
	for(j=0;j<nameode;j++)//订单结束时间 
	{
		strncpy(end,ode[j].et,2);
	    ane[j]=atoi(end);
    	strncpy(end,ode[j].et+3,2); 
    	bne[j]=atoi(end);
	}
	for(l=0;l<namecin;l++)//场次开始时间 
	{
		strncpy(ostart,cin[l].start_time,2);
	    af[l]=atoi(ostart);
    	strncpy(ostart,cin[l].start_time+3,2); 
    	bf[l]=atoi(ostart);
	}
	for(m=0;m<namecin;m++)//场次结束时间 
	{
		strncpy(oend,cin[m].end_time,2);
	    afe[m]=atoi(oend);
    	strncpy(oend,cin[m].end_time+3,2); 
    	bfe[m]=atoi(oend);
	}
	//把两个两位整数合成一个数进行比较		
	for(y=0;y<namecin;y++)//场次开始时间 
	{
		aaa[y]=af[y]*100+bf[y];	 
	} 

	for(t=0;t<namecin;t++)//场次结束时间 
	{
		bbb[t]=afe[t]*100+ bfe[t];		
	}
	for(o=0;o<nameode;o++)//订单开始时间 
	{
		ccc[o]=an[o]*100+bn[o];
	}
	for(g=0;g<nameode;g++)//订单结束时间 
	{
		ddd[g]=ane[g]*100+bne[g];
	}	
	j=0,i=0;	
    int test_number=1,testnum=0,test_number1=1;
    int time_s,time_e;      
	for(i=0;i<namecin;i++)
	{
      if(strcmp(chang,cin[i].number)==0)//去场次信息中找到对应场次，这部电影的开始时间就是 time_s,结束时间是time_e)
      {
      	time_s=aaa[i];
      	time_e=bbb[i];	
      }
	}			
	for(j=0;j<nameode;j++)
	{
		if(strcmp(getid,ode[j].yonghu)==0)//在订单信息中找到用户名字一样的人 ，每一个订单开始时间ccc[j],结束时间ddd[j]
	    {
    		if(time_s<ccc[j])//要看的开始时间比订单中的小,开始时间在订单之前 
    		{
				if(time_e<=ccc[j])//要看的结束时间比订单中的小
		    	{
	    			test_number=1;
	    		}
	    		else
	    		{
		    		printf("\n您购买的影片场次的时间和订单号为%d这个场次时间冲突，请选择是否继续购买：",ode[j].numorder); 
		    		do
		    		{
	                    printf("\n1.继续购买\n2.取消 返回重新选择场次号\n");
				        scanf("%s",Stestnumcheck);
				        if(testshu(Stestnumcheck))
				        {
        					testnumcheck=atoi(Stestnumcheck);
        				}
        				else
        				{
				        	printf("输入有误，请输入正确数字1或2 \n");
				        	system("pause");
				        	test_time(getid,chang);
				        }
						switch(testnumcheck)
                        {
						    	case 1:
    							check_a=0;
    							break;
    							case 2:
    							check_a=0;
    							test_number=0;
								return 2;
								break;
								default:;
							
		     	          }	
		    		}while(check_a==1); 
		    	}
		    }
		    else if(time_s>=ddd[j])
		      test_number=1;
            else
            {
				printf("\n您购买的影片场次的时间和订单号为%d这个场次时间冲突，请选择是否继续购买：",ode[j].numorder); 
    		    do
    		    {
                        printf("\n1.继续购买。\n2.取消，返回重新选择场次号");
				         scanf("%s",Stestnumcheck2);
				        if(testshu(Stestnumcheck2))
				        {
        					testnumcheck2=atoi(Stestnumcheck2);
        				}
        				else
        				{
				        	printf("输入有误，请输入正确数字1或2 \n");
				        	system("pause");
				        	test_time(getid,chang);
				        }
				        
						switch(testnumcheck2)
                        {
    							case 1:
    							check_a=0;
    							break;
    							case 2:
    							check_a=0;
    							test_number=0;
								return 2;
								break;
								default:;
								
                       }	
    		     }while(check_a==1); 
            }
            				
    	}
    	else
    	test_number=1;
	}
	if(test_number==1)
	return 1;    
}







 

/*************************************推荐座位函数****************************************/
 
int tuijian1(int a[H][L],char getci[20],char zuoweihao[20] )      //推荐1个座位 
{
//0代表座位为空，1代表座位已经卖出
int count=0,i,j,x,y,sc,q,ok=1,P=0,I=0,J=0;
char Sq[20];  
int max=100;
      for (int i=0; i<8; i++) {      //遍历行
            for (int j=0; j<8; j++) {  //遍历列
                  if (a[i][j]!=1) {
             P = (i-4)*(i-4)+(j-4)*(j-4);       //计算座位据最佳座位的距离
                      if (max > P) {
                           max = P;
                I = i;
                J = j;
            }
         }
      }
}
      
	  printf("\n为您推荐的座位为：第%d行 第%d列\n",I+1,J+1);
	  a[I][J]=1;
	      
 	i=0;
	 do
    {
    
		if(strcmp(getci,ode[i].chang)==0)
	 { 	
    	switch(ode[i].duoshao)
    	{
	    	case 1:
	    	strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
			strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 2:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 3:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+4,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+5,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
    	}
      }i++;
    }while(i<20);
	  	
	printf("列1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" ▇ ");
		else 
			printf(" □ ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
	    
      while(ok)
	  {printf("\n请输入是否选择推荐座位\n     1.选择推荐座位   2.自主选择座位 \n");
      scanf("%s",Sq);
      if(strcmp(Sq,"1")==0||strcmp(Sq,"2")==0)
      {ok=0;}
	  else
	  printf("请按规定输入1或2\n");
	  }
	  q=atoi(Sq);
      switch(q)
      {case 1:
      a[I][J]=1;        //选中的座位被标记为1
	  sc=10*(I+1)+(J+1);
	  return(sc);
	   break;
       case 2:
       a[I][J]=0; 
      return(zizhu1(a)); 
	  break;        //回到自主购票函数  
      }

	 
	  }


int tuijian2(int a[H][L],char getci[20],char zuoweihao[20])    //推荐2个座位 
{
//0代表座位为空，1代表座位已经卖出
int count=0,ii,j,x,y,sc,q,ok=1,P=0,I=0,J=0;   
char Sq[20];
int max=100;
  do{
  	
 
      for (int ii=0; ii<8; ii++) {      //遍历行
            for (int j=0; j<8; j++) {  //遍历列
                  if (a[ii][j]!=1) {
             P = (ii-4)*(ii-4)+(j-4)*(j-4);       //计算座位据最佳座位的距离
                      if (max > P) {
                           max = P;
                I = ii;
                J = j;
            }
         }
      }
      }
      a[I][J]=1;
   if(a[I][J-1]==0)            //寻找最佳座位旁边的座位 
   { 
	  a[I][J-1]=1;

    //如果左边座位为空，则选定 
   printf("\n为您推荐的座位为：第%d行 第%d列 和 第%d行 第%d列(如下图)\n",I+1,J,I+1,J+1); 
  	i=0;
	 do
    {
    
		if(strcmp(getci,ode[i].chang)==0)
	 { 	
    	switch(ode[i].duoshao)
    	{
	    	case 1:
	    	strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
			strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 2:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 3:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+4,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+5,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
    	}
      }i++;
    }while(i<20);
	  	
	printf("列1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" ▇ ");
		else 
			printf(" □ ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
    sc=1000*(I+1)+100*(J+1)+10*(I+1)+(J+2);
     break;}
     
     if(a[I][J+1]==0)            //寻找最佳座位旁边的座位 
   { 
	  a[I][J+1]=1;

    //如果右边座位为空，则选定 
   printf("\n为您推荐的座位为：第%d行 第%d列 和 第%d行 第%d列(如下图)\n",I+1,J+1,I+1,J+2); 
    	i=0;
	 do
    {
    
		if(strcmp(getci,ode[i].chang)==0)
	 { 	
    	switch(ode[i].duoshao)
    	{
	    	case 1:
	    	strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
			strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 2:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 3:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+4,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+5,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
    	}
      }i++;
    }while(i<20);
	  	
	printf("列1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" ▇ ");
		else 
			printf(" □ ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
    sc=1000*(I+1)+100*(J+1)+10*(I+1)+(J+2);
     break;}
     
   else 
   {a[I][J]=2; }              //如果旁边座位有人，则标记为2，再次进行选择最佳座位 
   } while(1);
   
      while(ok)
	  {printf("请输入是否选择推荐座位\n     1.选择推荐座位   2.自主选择座位 \n");
      scanf("%s",Sq);
      if(strcmp(Sq,"1")==0||strcmp(Sq,"2")==0)
      {ok=0;}
	  else
	  printf("请按规定输入1或2\n");
	  }
	  q=atoi(Sq);
      switch(q)
      {case 1:
	   return(sc);
	  break;         //选中的座位被标记为1
       case 2: 
	   if(a[I][J-1]==1)
	   a[I][J]=0;
	   a[I][J-1]=0;
	        
	   if(a[I][J+1]==1)
	   a[I][J]=0;
	   a[I][J+1]=0;
      return(zizhu2(a)); 
	  break;        //回到自主购票函数  
      }
   
   
   
   
   
   
} 

 int tuijian3(int a[H][L],char getci[20],char zuoweihao[20])    //推荐3人座位 
{
//0代表座位为空，1代表座位已经卖出
int count=0,ii,j,x,y,sc,q,ok=1,P=0,I=0,J=0;   
char Sq[20];
int max=100;
  do{
  	
 
      for (int ii=0; ii<8; ii++) {      //遍历行
            for (int j=0; j<8; j++) {  //遍历列
                  if (a[ii][j]!=1) {
             P = (ii-4)*(ii-4)+(j-4)*(j-4);       //计算座位据最佳座位的距离
                      if (max > P) {
                           max = P;
                I = ii;
                J = j;
            }
         }
      }
      }
   a[I][J]=1;
  if(a[I][J+1]==0&&a[I][J-1]==0)
   { 
   a[I][J+1]=1;          //如果右边和左边2个座位为空，则选定
   a[I][J-1]=1;  
   printf("\n为您推荐的座位为：第%d行 第%d列 第%d行 第%d列 和 第%d行 第%d列\n",I+1,J,I+1,J+1,I+1,J+2); 
     	i=0;
	 do
    {
    
		if(strcmp(getci,ode[i].chang)==0)
	 { 	
    	switch(ode[i].duoshao)
    	{
	    	case 1:
	    	strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
			strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 2:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 3:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+4,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+5,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
    	}
      }i++;
    }while(i<20);
	  	
	printf("列1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" ▇ ");
		else 
			printf(" □ ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	} 
	 
	 
	 sc=100000*(I+1)+10000*(J)+1000*(I+1)+100*(J+1)+10*(I+1)+(J+2);
	 break;}
      

        

        
  if(a[I][J-1]==0&&a[I][J-2]==0)
   { 
   a[I][J-1]=1;           //如果左边2个座位为空，则选定 
   a[I][J-2]=1;  
   printf("\n为您推荐的座位为：第%d行 第%d列 第%d行 第%d列 和 第%d行 第%d列\n",I+1,J-1,I+1,J,I+1,J+1); 
     
	  	i=0;
	 do
    {
    
		if(strcmp(getci,ode[i].chang)==0)
	 { 	
    	switch(ode[i].duoshao)
    	{
	    	case 1:
	    	strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
			strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 2:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 3:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+4,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+5,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
    	}
      }i++;
    }while(i<20);
	  	
	printf("列1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" ▇ ");
		else 
			printf(" □ ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
	 
	 
	 sc=100000*(I+1)+10000*(J-1)+1000*(I+1)+100*J+10*(I+1)+(J+1);
	 break;}   
	 
	 if(a[I][J+1]==0&&a[I][J+2]==0)
   { 
   a[I][J+1]=1;         //如果右边2个座位为空，则选定 
   a[I][J+2]=1;  
   printf("\n为您推荐的座位为：第%d行 第%d列 第%d行 第%d列 和 第%d行 第%d列\n",I+1,J+1,I+1,J+2,I+1,J+3); 
     
	  	i=0;
	 do
    {
    
		if(strcmp(getci,ode[i].chang)==0)
	 { 	
    	switch(ode[i].duoshao)
    	{
	    	case 1:
	    	strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
			strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 2:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            
            case 3:
            strncpy(zuoweihao, ode[i].zuowei,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+1,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+2,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+3,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
            strncpy(zuoweihao, ode[i].zuowei+4,1);
            x=atoi(zuoweihao)-1;
            strncpy(zuoweihao, ode[i].zuowei+5,1);
            y=atoi(zuoweihao)-1;
            a[x][y]=1;
    	}
      }i++;
    }while(i<20);
	  	
	printf("列1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" ▇ ");
		else 
			printf(" □ ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
	 
	 
	 
	 sc=100000*(I+1)+10000*(J+1)+1000*(I+1)+100*(J+2)+10*(I+1)+(J+3);
	 break;}
   else 
   {a[I][J]=2; }        //如果两边都有人则重新选择 
   } while(1);
   
   
      while(ok)
	  {printf("请输入是否选择推荐座位\n     1.选择推荐座位   2.自主选择座位 \n");
      scanf("%s",Sq);
      if(strcmp(Sq,"1")==0||strcmp(Sq,"2")==0)
      {ok=0;}
	  else
	  printf("请按规定输入1或2\n");
	  }
	  q=atoi(Sq);
      switch(q)
      {case 1:        //选中的座位已经被标记为1
	  return(sc);
	  break;         //选中的座位已经被标记为1
      case 2:
      
      if(a[I][J+1]==1&&a[I][J+2]==1)
   { 
   a[I][J]=0;
   a[I][J+1]=0;         //将推荐座位标为0 
   a[I][J+2]=0;  
     }
     
      if(a[I][J+1]==1&&a[I][J-1]==1)
   { 
     a[I][J]=0;
	 a[I][J+1]=0;          //将推荐座位标为0 
     a[I][J-1]=0;  
     }
     
     if(a[I][J-1]==1&&a[I][J-2]==1)
   { 
   a[I][J]=0;
   a[I][J-1]=0;           //将推荐座位标为0 
   a[I][J-2]=0;  
     }
      return(zizhu3(a));
	  break;        //回到自主购票函数  
      }
   
   
} 

/***********************************自主选票函数***********************************/

 
int zizhu1(int a[H][L])       //自主选1张票 
{ 
 int x,y,j,sc,hang,lie,ok=1;
 char Shang[20],Slie[20];
 char zuoweihao[20];
   		    
            printf("您选择座位的行数为： ");     //选择第一个座位 
			scanf("%s",Shang); 
		    printf("您选择座位的列数为 ");
			scanf("%s",Slie) ;	
			if(strcmp(Shang,"1")==0||strcmp(Shang,"2")==0||strcmp(Shang,"3")==0||strcmp(Shang,"4")==0||strcmp(Shang,"5")==0||strcmp(Shang,"6")==0||strcmp(Shang,"7")==0||strcmp(Shang,"8")==0)
			{hang=atoi(Shang);}
			else 
			{printf("您的输入有误，请输入数字1-8\n");
			zizhu1(a);}
			if(strcmp(Slie,"1")==0||strcmp(Slie,"2")==0||strcmp(Slie,"3")==0||strcmp(Slie,"4")==0||strcmp(Slie,"5")==0||strcmp(Slie,"6")==0||strcmp(Slie,"7")==0||strcmp(Slie,"8")==0)
			{lie=atoi(Slie);}
			else 
			{printf("您的输入有误，请输入数字1-8\n");
			zizhu1(a);}
	        a[hang-1][lie-1]=1;
	//检测是否按规定输入数字1-8
		  //输入不符则再次循环
	
	//检测函数
	
		for(i=0;i<H;i++)
		{
			for(j=0;j<L;j++)
			{
				if(a[i][j]==1&&a[i][j+1]==0&&a[i][j+2]==1)
				{printf("两个座位中间不能空1个座位，请重新输入：\n");
				a[hang-1][lie-1]=0;
				zizhu1(a);}
	 
			}
		}	
		sc=hang*10+lie;
       return(sc);		
	
	
}
int zizhu2(int a[H][L])        //自主选2张票 
{ 
  int x,y,j,sc,hang1,lie1,hang2,lie2;
  char Shang1[20],Slie1[20],Shang2[20],Slie2[20];
  char zuoweihao[20];
 
        
			printf("您选择第一个座位的行数为： ");     //选择第一个座位 
			scanf("%s",Shang1); 
		    printf("您选择第一个座位的列数为 ");
			scanf("%s",Slie1) ;	
			if(strcmp(Shang1,"1")==0||strcmp(Shang1,"2")==0||strcmp(Shang1,"3")==0||strcmp(Shang1,"4")==0||strcmp(Shang1,"5")==0||strcmp(Shang1,"6")==0||strcmp(Shang1,"7")==0||strcmp(Shang1,"8")==0)
			{hang1=atoi(Shang1);}
			else 
			{printf("您的输入有误，请输入数字1-8\n");
			zizhu2(a);}
			if(strcmp(Slie1,"1")==0||strcmp(Slie1,"2")==0||strcmp(Slie1,"3")==0||strcmp(Slie1,"4")==0||strcmp(Slie1,"5")==0||strcmp(Slie1,"6")==0||strcmp(Slie1,"7")==0||strcmp(Slie1,"8")==0)
			{lie1=atoi(Slie1);}
			else 
			{printf("您的输入有误，请输入数字1-8\n");
			zizhu2(a);}
			do{
			printf("您选择第二个座位的行数为： ");   //选择第二个座位 
			scanf("%s",Shang2); //如果与第一个座位相同则 再次输入 
		    printf("您选择第二个座位的列数为 ");
			scanf("%s",Slie2) ;
			if(strcmp(Shang2,"1")==0||strcmp(Shang2,"2")==0||strcmp(Shang2,"3")==0||strcmp(Shang2,"4")==0||strcmp(Shang2,"5")==0||strcmp(Shang2,"6")==0||strcmp(Shang2,"7")==0||strcmp(Shang2,"8")==0)
			{hang2=atoi(Shang2);}
			else 
			{printf("您的输入有误，请输入数字1-8\n");
			zizhu2(a);}
			if(strcmp(Slie2,"1")==0||strcmp(Slie2,"2")==0||strcmp(Slie2,"3")==0||strcmp(Slie2,"4")==0||strcmp(Slie2,"5")==0||strcmp(Slie2,"6")==0||strcmp(Slie2,"7")==0||strcmp(Slie2,"8")==0)
			{lie2=atoi(Slie2);}
			else 
			{printf("您的输入有误，请输入数字1-8\n");
			zizhu2(a);}
				
			} while(hang1==hang2&&lie1==lie2);
			
			a[hang1-1][lie1-1]=1;
            a[hang2-1][lie2-1]=1;
			
			
           //检测是否按规定输入数字1-8
		  //输入不符则再次循环
		
	//检测函数
	
		for(i=0;i<H;i++)
		{
			for(j=0;j<L;j++)
			{
				if(a[i][j]==1&&a[i][j+1]==0&&a[i][j+2]==1)
				{printf("两个座位中间不能空1个座位，请重新输入：\n");
				a[hang1-1][lie1-1]=0;
	            a[hang2-1][lie2-1]=0;
				zizhu2(a);}
	 
			}
		}
	sc=hang1*1000+lie1*100+hang2*10+lie2;
    return(sc);
				
	   			
} 

int zizhu3(int a[H][L])      //自主选3张票 
{
  int i,j,sc,hang1,lie1,hang2,lie2,hang3,lie3;
  char Shang1[20],Slie1[20],Shang2[20],Slie2[20],Shang3[20],Slie3[20];
  char zuoweihao[20];

  
  	        printf("您选择第一个座位的行数为： ");     //选择第一个座位 
			scanf("%s",Shang1); 
		    printf("您选择第一个座位的列数为 ");
			scanf("%s",Slie1) ;	
			if(strcmp(Shang1,"1")==0||strcmp(Shang1,"2")==0||strcmp(Shang1,"3")==0||strcmp(Shang1,"4")==0||strcmp(Shang1,"5")==0||strcmp(Shang1,"6")==0||strcmp(Shang1,"7")==0||strcmp(Shang1,"8")==0)
			{hang1=atoi(Shang1);}
			else 
			{printf("您的输入有误，请输入数字1-8\n");
			zizhu3(a);}
			if(strcmp(Slie1,"1")==0||strcmp(Slie1,"2")==0||strcmp(Slie1,"3")==0||strcmp(Slie1,"4")==0||strcmp(Slie1,"5")==0||strcmp(Slie1,"6")==0||strcmp(Slie1,"7")==0||strcmp(Slie1,"8")==0)
			{lie1=atoi(Slie1);}
			else 
			{printf("您的输入有误，请输入数字1-8\n");
			zizhu3(a);}
			do{
			printf("您选择第二个座位的行数为： ");   //选择第二个座位 
			scanf("%s",Shang2); //如果与第一个座位相同则 再次输入 
		    printf("您选择第二个座位的列数为 ");
			scanf("%s",Slie2) ;
			if(strcmp(Shang2,"1")==0||strcmp(Shang2,"2")==0||strcmp(Shang2,"3")==0||strcmp(Shang2,"4")==0||strcmp(Shang2,"5")==0||strcmp(Shang2,"6")==0||strcmp(Shang2,"7")==0||strcmp(Shang2,"8")==0)
			{hang2=atoi(Shang2);}
			else 
			{printf("您的输入有误，请输入数字1-8\n");
			zizhu3(a);}
			if(strcmp(Slie2,"1")==0||strcmp(Slie2,"2")==0||strcmp(Slie2,"3")==0||strcmp(Slie2,"4")==0||strcmp(Slie2,"5")==0||strcmp(Slie2,"6")==0||strcmp(Slie2,"7")==0||strcmp(Slie2,"8")==0)
			{lie2=atoi(Slie2);}
			else 
			{printf("您的输入有误，请输入数字1-8\n");
			zizhu3(a);}
				
			} while(hang1==hang2&&lie1==lie2);
		    
            do{
			printf("您选择第三个座位的行数为： ");   //选择第三个座位 
			scanf("%s",Shang3);
		    printf("您选择第三个座位的列数为 ");     //如果与第一个或第二个座位相同则 再次输入
			scanf("%s",Slie3) ;
			if(strcmp(Shang3,"1")==0||strcmp(Shang3,"2")==0||strcmp(Shang3,"3")==0||strcmp(Shang3,"4")==0||strcmp(Shang3,"5")==0||strcmp(Shang3,"6")==0||strcmp(Shang3,"7")==0||strcmp(Shang3,"8")==0)
			{hang3=atoi(Shang3);}
			else 
			{printf("您的输入有误，请输入数字1-8\n");
			zizhu3(a);}
			if(strcmp(Slie3,"1")==0||strcmp(Slie3,"2")==0||strcmp(Slie3,"3")==0||strcmp(Slie3,"4")==0||strcmp(Slie3,"5")==0||strcmp(Slie3,"6")==0||strcmp(Slie3,"7")==0||strcmp(Slie3,"8")==0)
			{lie3=atoi(Slie3);}
			else 
			{printf("您的输入有误，请输入数字1-8\n");
			zizhu3(a);} 
        	}while(hang1==hang3&&lie1==lie3||hang2==hang3&&lie2==lie3);
			
            //检测是否按规定输入数字1-8 
	        //输入不符则再次循环
			
		
	a[hang1-1][lie1-1]=1;
	a[hang2-1][lie2-1]=1;
	a[hang3-1][lie3-1]=1;
	//对座位数组进行修改 	
	//检测函数	
	
		for(i=0;i<H;i++)
		{
			for(j=0;j<L;j++)
			{
				if(a[i][j]==1&&a[i][j+1]==0&&a[i][j+2]==1)
				{printf("两个座位中间不能空1个座位，请重新输入：\n");
				a[hang1-1][lie1-1]=0;
	            a[hang2-1][lie2-1]=0;
                a[hang3-1][lie3-1]=0;
				zizhu3(a);}
	 
			}
		}
sc=hang1*100000+lie1*10000+hang2*1000+lie2*100+hang3*10+lie3;
return(sc);
	
	
  }
  
  


/*****************************测试输入场次是否正确函数*****************************/

 
int test_changci(char getci[20])
{
	read_cin();
	i=0;
	int testa=0;
	for(i=0;i<namecin;i++)
	{
		if(strcmp(getci,cin[i].number)==0)
		{
			testa=1;
			return 0;
		}
	}
	if(testa==0)
	{return 1;} 
} 


/********************************测试一个用户没有超过五个订单*************************************/ 

int test_shuliang(char getid[20])
{
    int amount=0,i=0;
	read_order();
	
	do
    {
		if(strcmp(getid,ode[i].yonghu)==0)
    	amount++;
    	else
    	amount=amount;
    i++;	
    }while(i<nameode);
   return (amount);   	
}


/********************************测试一个用户看同一部电影****************************************/ 

int test_same(char getid[20],char moviename[20])
{
      int amount=0,h,f=1,test_num=0; 
	  char Sh[20]; 
    read_order();
	for(i=0;i<nameode;i++)
    {
	    	if(strcmp(moviename,ode[i].movie)==0&&strcmp(getid,ode[i].yonghu)==0)
	    	{
			  printf("您已经购买过相同影片的影票,请选择是否继续购买当前影片\n");	
			  do{
				   printf("1.继续购买\n2.取消购买，返回重新选择场次\n请选择：");
			       scanf("%s",Sh);
			       if(testshu(Sh))
			       {
       				h=atoi(Sh);
       			    }
       			  else
       			    {
			       	printf("输入有误，请重新输入1或2\n");
			       	system("pause");
			       	test_same(getid,moviename);
			         }
				   switch(h)
			       {
				   case 1: 
				   f=0;
				   return 1;
				   case 2:
				   {
   					  f=0;
   					  test_num=1;
   					  return 2;
   				    } 
				   default:
				   {
			       
		    	   f=1;} 
   				   }
   				}while(f==1);	    	   
			}
			else
			continue;

    }
    if(test_num==0)
    return 1;
} 

/************************************检测用户余额并充值函数*************************************/ 
void check_price(char getid[20],int piaoshu,char chang[20])
{
	float start_yu,everyprice;
	int  check_num=0,totalyu,n,num;	
	read_cin();
	read_user();
	for(i=0;i<nameuser;i++)
	{
		if(strcmp(getid,user[i].ID)==0)
		{
			start_yu=user[i].balance;
			num=i;
		}
	}
	for(i=0;i<namecin;i++)
	{
		if(strcmp(chang,cin[i].number)==0)
		{
			everyprice=cin[i].ticket; 
		}
	}
	do{
	if(start_yu<everyprice*piaoshu)
	{
		printf("您的余额不足，请进行充值");
		change_yu(getid);
		start_yu=user[num].balance; 
	}
	else	
	check_num=1;
	}while(check_num==0);
	totalyu=start_yu-everyprice*piaoshu;
	printf("您的账户余额购票后已经变成%d",totalyu);
	user[num].balance=totalyu;
	FILE *outfile;
	outfile=fopen("userInformation.txt","w");
	for(n=0;n<nameuser;n++)
	{
		fprintf(outfile,"\n%s %s %s %s %s %s %d",user[n].ID,user[n].name,user[n].gender,user[n].tele,user[n].password,user[n].mail,user[n].balance);
	}
	fclose(outfile);
}


int test_yu(int yu)
{
    if(yu>=0)
    return 1;
    else
    return 2;
}





void change_yu(char getid[20])
{
	read_user();
	int n=0,a=0,b=2,p,j=0,fanhui;
	int add_yu;
	char Sadd_yu[20] ;
     strcpy(getid,userID);

			for(j=0;j<nameuser;j++)
			{
			if(strcmp(getid,user[j].ID)==0)
			{
				printf("现在您的账户上的余额为:%d\n",user[j].balance);
				printf("请选择您要充值的金额为：");
				scanf ("%s",Sadd_yu);
				if(testshu(Sadd_yu)==1)
				{
					add_yu=atoi(Sadd_yu);
					user[j].balance=user[j].balance+add_yu;	
					printf("您的账户余额已更改为:%d\n",user[j].balance);
				}
				else
				{
					printf("输入有误，请重新输入：\n");
					change_yue(getid);
				}
			}
					
			}
	 			
			
			
	    FILE *outfile;				
    	outfile=fopen("userInformation.txt","w");
	for(n=0;n<nameuser;n++)
	{
		fprintf(outfile,"\n%s %s %s %s %s %s %d",user[n].ID,user[n].name,user[n].gender,user[n].tele,user[n].password,user[n].mail,user[n].balance);
	}
	fclose(outfile);
	userfunction();
	}
/***********************************改变余票数******************************/ 
void change_yupiaoshu(char getci[20],int piaoshu)
{
	int n;
	for(i=0;i<namecin;i++)
	{
		if(strcmp(getci,cin[i].number)==0)
		{
			cin[i].margin=cin[i].margin-piaoshu;
		}
	}
	FILE *infile;
	infile=fopen("场次信息.txt","w");
	for(n=0;n<namecin;n++)
	{
		fprintf(infile,"%s   %s   %s   %d   %s   %s   %s   %d   %.2f   %s   %s   %.2f\n",cin[n].number,cin[n].name,cin[n].place,cin[n].screen,cin[n].start_time,cin[n].end_time,
		cin[n].totaltime,cin[n].margin,cin[n].ticket,cin[n].kind,cin[n].sort,cin[n].discounts);
	
	}
    fclose(infile);
} 




/*******************************************用户个人信息管理*********************************************/ 


void PIM(char userID[20])//用户个人信息管理 
{
	read_user(); 
	int testnum=0;
	char cho[10] ={'\0'};
	do
	{
        printf("请选择你要修改的信息");
	    printf("\n1.电话\n2.邮箱\n3.密码");
        scanf("\n%s",cho);
		
			if(strcmp(cho,"1")==0)
			{change_phone(userID);
			testnum=1;
			}
			else if(strcmp(cho,"2")==0)
			{change_email(userID);
			testnum=1;
			}
			else if(strcmp(cho,"3")==0)
			{change_pass(userID);
			testnum=1;
			}
			else
	     {printf("您输入的数字无效，请输入有效选项（1、2、3）");}
			
		
	}while(testnum==0);
	userfunction();
} 

int test_phone(char phone[])//检验手机号为11位数字 
{
	int i,count=0;
	for(i=0;phone[i]!='\0';i++)
	{
		if(isdigit(phone[i])!=0)
			count++;
		else
	 		return 2;
	}
	if(count==11)
		return 1;
	else
		return 2;
}


void change_phone(char userID[20])//用户修改手机号
{
	int n,a=0,b=2,p,j=0;
	char newphone[11];	
	do
	{
		do
		{
			if(strcmp(userID,user[j].ID)==0)
			{
				printf("原手机号:%s\n",user[j].tele);
				printf("请输入新手机号(请输入11位数字):");
				scanf("%s",&newphone);
				p=test_phone(newphone);
				while(p==2)
				{
					printf("手机号不符合要求，请重新输入(请输入11位数字):");
					scanf("%s",&newphone);
					p=test_phone(newphone);
				}
				strcpy(user[j].tele,newphone);
				printf("您的手机号已更改为:%s\n",user[j].tele);
				a=1;
				b=1;
				break;
			}
			j++;	
		}while(j<nameuser);
		if(a!=1)
		{
			printf("用户ID不存在，请重新输入:");
			scanf("%s",&userID);
			b=2;
			j=0;
		}
		else
			break;
	}while(b!=1);
		
	FILE *outfile;
	outfile=fopen("userInformation.txt","w");
	for(n=0;n<nameuser;n++)
	{
		fprintf(outfile,"\n%s %s %s %s %s %s %d",user[n].ID,user[n].name,user[n].gender,user[n].tele,user[n].password,user[n].mail,user[n].balance);
	}
	fclose(outfile);
	
}


int test_email(char email[])//检验邮箱格式标准 
{
	char a='@',b='.',*string;
	string=strchr(email,a);
	if(string==NULL)
		return 0;
	else if(email>=string)
		return 0;
	else if(strchr(string+1,a)!=NULL)
		return 0;
	else if(strchr(string+1,b)==NULL)
		return 0;
	else if(strchr(email,b)<string)
		return 0;
	else if(strlen(string+1)<strlen(strchr(email,b)-1))
		return 0;
	else if(strlen(strchr(email,b)+1)<1)
		return 0;
	else
		return 1;
}


void change_email(char userID[20])//用户登录-用户信息管理-修改信息-修改邮箱
{
 int n,a=0,b=2,p,j=0;
 char newemail[20];
 do
 {
  do
  {
   if(strcmp(userID,user[j].ID)==0)
   {
    printf("原邮箱:%s\n",user[j].mail);
    printf("请输入新邮箱(格式***@***.***):");
    scanf("%s",&newemail);
    p=test_email(newemail);
    while(p!=1)
    {
     printf("邮箱不符合要求，请重新输入(格式***@***.***):");
     scanf("%s",&newemail);
     p=test_email(newemail);
    }
    strcpy(user[j].mail,newemail);
    printf("您的邮箱已更改为:%s\n",user[j].mail);
    a=1;
    b=1;
    break;
   }
   j++; 
  }while(j<nameuser);
  if(a!=1)
  {
   printf("用户ID不存在，请重新输入:");
   scanf("%s",&userID);
   b=2;
   j=0;
  }
  else
   break;
 }while(b!=1);
  
 FILE *outfile;
 outfile=fopen("userInformation.txt","w");
 for(n=0;n<nameuser;n++)
 {
  fprintf(outfile,"\n%s %s %s %s %s %s %d",user[n].ID,user[n].name,user[n].gender,user[n].tele,user[n].password,user[n].mail,user[n].balance);
 }
 fclose(outfile);
}



int test_long(char ID[10])//测试密码长度
{
	int i,count=0;
	for(i=0;ID[i]!='\0';i++)
	{
		count++;
	}
	if(count>10||count<6)
 		return 2;
	else
		return 1;
}


int testCODE(char codeone[],char codetwo[])//检验确认密码输入正确 
{
	return (strcmp(codeone,codetwo));
}




void change_pass(char userID[20])//修改密码 
{
	int n,a=0,b=2,m,p,j=0;
	char newpass[10],code2[10]; 
	do
	{
		do
		{
			if(strcmp(userID,user[j].ID)==0)
			{
				printf("原密码:%s\n",user[j].password);
				printf("请输入新密码(请输入6-10位):");
				scanf("%s",&newpass);
				p=test_long(newpass);
					while(p==2)
				{
					printf("密码不符合要求，请重新输入(请输入6-10位):");
					scanf("%s",&newpass);
					p=test_long(newpass);
				}
				printf("确认密码:");
				scanf("%s",&code2);
				m=testCODE(newpass,code2);
				while(m!=0)
				{
					printf("密码输入不一致，请重新输入新密码:");
					scanf("%s",&newpass);
					p=test_long(newpass);
					while(p==2)
					{
						printf("密码不符合要求，请重新输入:");
						scanf("%s",&newpass);
						p=test_long(newpass);
					}
					printf("再次新确认密码:");
					scanf("%s",&code2);
					m=testCODE(newpass,code2);
				}
				strcpy(user[j].password,newpass);
				printf("您的密码已更改为:%s\n",user[j].password);
				a=1;
				b=1;
				break;
			}
			j++;	
		}while(j<nameuser);
		if(a!=1)
		{
			printf("用户ID不存在，请重新输入:");
			scanf("%s",&userID);
			b=2;
			j=0;
		}
		else
			break;
	}while(b!=1);
				
	FILE *outfile;	
	outfile=fopen("userInformation.txt","w");
	for(n=0;n<nameuser;n++)
	{
		fprintf(outfile,"\n%s %s %s %s %s %s %d",user[n].ID,user[n].name,user[n].gender,user[n].tele,user[n].password,user[n].mail,user[n].balance);
	}
	fclose(outfile);

}

/**********************************************充值函数**********************************/ 

void change_yue(char getid[20])
{
	read_user();
	int n=0,a=0,b=2,p,j=0,fanhui;
	int add_yu;
	char Sadd_yu[20] ;
     strcpy(getid,userID);

			for(j=0;j<nameuser;j++)
			{
			if(strcmp(getid,user[j].ID)==0)
			{
				printf("现在您的账户上的余额为:%d\n",user[j].balance);
				printf("请选择您要充值的金额为：");
				scanf ("%s",Sadd_yu);
				if(testshu(Sadd_yu)==1)
				{
					add_yu=atoi(Sadd_yu);
					user[j].balance=user[j].balance+add_yu;	
					printf("您的账户余额已更改为:%d\n",user[j].balance);
				}
				else
				{
					printf("输入有误，请重新输入：\n");
					change_yue(getid);
				}
			}
					
			}
	 			
			
			
	    FILE *outfile;				
    	outfile=fopen("userInformation.txt","w");
	for(n=0;n<nameuser;n++)
	{
		fprintf(outfile,"\n%s %s %s %s %s %s %d",user[n].ID,user[n].name,user[n].gender,user[n].tele,user[n].password,user[n].mail,user[n].balance);
	}
	fclose(outfile);
	userfunction();
	}

/****************************************查询订单函数***********************************/ 

void inquiry_order(char userID[20])
{ 
	read_order();
	int i=0;	
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|您的ID|购买场次号|座位号码|购买票数|购买日期(月)|(日)|(时)|票价|开始时间|结束时间|影院|订单号|电影名称|");
	printf("\n--------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<nameode;i++)
	{
		if(strcmp(userID,ode[i].yonghu)!=0)
		continue;
		else 
		printf("\n%s%8s%10s%10d%8d%8d%6d%7.2f%7s%8s%8s%5d   %s\n",ode[i].yonghu,ode[i].chang,ode[i].zuowei,ode[i].duoshao,ode[i].year,ode[i].month,ode[i].day,ode[i].price,ode[i].st,ode[i].et,ode[i].yingyuan,ode[i].numorder,ode[i].movie); 
	}
	userfunction();
} 

/**************************************取消订单函数**********************************/ 

void cancel_order()
{
	
	read_order();
	int j,flag,fanhui,ok=0,test_total=0;
	int ordernum;
	char Sordernum[20];
		FILE *infile;
	printf("请选择你要取消的订单的订单号");
	scanf("%s",Sordernum);
	fanhui=testshu(Sordernum); 
	if(fanhui==1)
	{
		ordernum=atoi(Sordernum);
	}
	
	if(ordernum>nameode+1)
	{
	    printf("未查询到所属订单号，请重新输入：\n");
		cancel_order();
	}
	else{
	for(i=0;i<nameode;i++)
	{
		if(ordernum==ode[i].numorder)
		flag=i;
	}	
	infile=fopen("dingdanA.txt","w");
	for(j=flag;j<nameode;j++)
	ode[j]=ode[j+1];
	for(i=0;i<nameode-1;i++)
    {fprintf(infile,"%s       %s        %s        %d        %d       %d         %d       %.2f       %s        %s       %s        %d     %s\n",
						ode[i].yonghu,ode[i].chang,ode[i].zuowei,ode[i].duoshao,ode[i].year,
						ode[i].month,ode[i].day,ode[i].price,ode[i].st,ode[i].et,
						ode[i].yingyuan,ode[i].numorder,ode[i].movie); }	
	fclose(infile);
	nameode=nameode-1; 
	printf("订单已取消\n");
	userfunction();}
	
}


void admfunction(char admID[20])//管理员功能 

{ 
    
	int a=1;
	while(a==1)
	{
		a=0; 
		int page_num,b=1,c=1,d=1,xiugai,fh;
		char Spage_num[20];
		system("pause");
		system("CLS");
		printf("************************************************************************************************\n1.订单管理\n2.影厅管理\n3.场次管理\n4.个人信息管理\n5.返回\n");
		scanf("%s",Spage_num);
		system("CLS");
		fh=testshu(Spage_num);
		if(fh==1)
		{
			page_num=atoi(Spage_num);
		}
		else
		{
			printf("输入错误，请输入正确数字\n");
			admfunction(admID);
		}
		system("CLS");
		switch(page_num)
		{
			//选择查询方式 
			case 1:
			{
				while(b==1)
			    {
			        b=0;
					int admnumber1,fanh;
					char Sadmnumber1[20];
			        printf("1.查看用户订单情况\n2.统计用户订单信息\n"); 
					scanf("%s",Sadmnumber1);
					 fanh=testshu(Sadmnumber1);
					 if(fanh==1)
		            {
			               admnumber1=atoi(Sadmnumber1);
		            }
	 	             else
		            {
		               printf("输入错误，请输入正确数字\n");
			            admfunction(admID);
		             } 
					
			        switch(admnumber1)
			        {
	                    case 1:
				        examine_order(admID);//查看用户订单情况
				        break; 
				        case 2:
                        tongji_dingdan(admID);//统计用户订单信息
                        break;
						default:
                        printf("\n 输入错误，请重新输入\n");
                        admfunction(admID);
		                b=1;
		            }
			    }
  			
			case 2:
            {
			while(c==1)
			    {
			        c=0;
					int admnumber2,fanh;
					char Sadmnumber2[20];
			        printf("1.影厅查询\n2.添加影厅\n"); 
					scanf("%s",Sadmnumber2);
					 fanh=testshu(Sadmnumber2);
					 if(fanh==1)
		            {
			               admnumber2=atoi(Sadmnumber2);
		            }
	 	             else
		            {
		               printf("输入错误，请输入正确数字\n");
			            admfunction(admID);
		             } 
			        switch(admnumber2)
			        {
	                    case 1:
				        examine_hall(admID);//影厅查询
				        break; 
				        case 2:
                        increase_room(admID);//添加影厅
                        break;
						default:
                        printf("\n输入错误，请重新输入\n");
                        admfunction(admID);
		                c=1;
		            }
			    }
			break;
            }
            case 3:
            {
  		        while(d==1)
			    {
			        d=0;
					int admnumber3,fanh;
					char Sadmnumber3[20];
			        printf("1.场次查询\n2.添加场次\n"); 
					scanf("%s",Sadmnumber3);
					 fanh=testshu(Sadmnumber3);
					 if(fanh==1)
		            {
			               admnumber3=atoi(Sadmnumber3);
		            }
	 	             else
		            {
		               printf("输入错误，请输入正确数字\n");
		               admfunction(admID);
		             }  
			        switch(admnumber3)
			        {
	                    case 1:
				        examine_chang(admID);//场次查询
				        break; 
				        case 2:
                        increase_ci(admID);//添加场次
                        break;
						default:
                        printf("\n输入错误，请重新输入\n");
                        admfunction(admID);
		                d=1;
		            }
	       		break;
    	    }
			case 4:
			{
				int fanh;
				char Sxiugai[20];
				printf("请输入修改内容   1.密码   2.邮箱\n");
				scanf("%s",Sxiugai);
					 fanh=testshu(Sxiugai);
					 if(fanh==1)
		            {
                        xiugai=atoi(Sxiugai);
		            }
	 	             else
		            {
		               printf("输入错误，请输入正确数字\n");
			            admfunction(admID);
		             } 
				if(xiugai==1)
				admin_pass(admID);
				else if(xiugai==2)
				admin_email(admID);
				else
				printf("输入有误，请重新输入\n"); 
				admfunction(admID);
	       		break;
			} 
			case 5:
			{
				enter();
			}
			
			default:
			printf("\n输入错误，请输入正确数字\n");
			admfunction(admID);
			a=1; 
		}
	}
 } 
}

}



/******************************************管理员查询订单******************************/

void examine_order(char admID[20])//管理员查询订单
{
	read_admin();
	read_order();
	int numbera,n=0;
	for(n=0;n<nameadmin;n++)
	{
		if(strcmp(admID,admin[n].ID)==0)
		numbera=n;
	}
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|购票用户ID|购买场次号|座位号码|购买票数|购买日期(年)|(月)|(日)|票价|开始时间|结束时间|影院|订单号|电影名称|");
	printf("\n--------------------------------------------------------------------------------------------------------");
	for(i=0;i<nameode;i++)
	{
		if(strcmp(admin[numbera].place,ode[i].yingyuan)==0)
		printf("\n   %s%8s%10s%10d%8d%8d%6d%7.2f%7s%8s%8s%5d   %s\n",ode[i].yonghu,ode[i].chang,ode[i].zuowei,ode[i].duoshao,ode[i].year,ode[i].month,ode[i].day,ode[i].price,ode[i].st,ode[i].et,ode[i].yingyuan,ode[i].numorder,ode[i].movie);
	}	
	 admfunction(admID);
}



/**************************************管理员统计订单信息**********************************/ 

void tongji_dingdan(char admID[20])
{
	char cho[10] ={'\0'};
	printf("请选择要统计的订单信息\n1.场次订单个数排序      2.场次上座率排序       3.场次总票价排序         4.影厅总票价排序\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	{
		printf("您输入的指令有误，请重新输入：\n");
		tongji_dingdan(admID);
	}
	if(strcmp(cho,"1")==0)
	px_dingdan(admID);
	else if(strcmp(cho,"2")==0)
	px_rate(admID);
	else if(strcmp(cho,"3")==0)
	px_changci(admID);
	else if(strcmp(cho,"4")==0)
	px_yingting(admID);
	else
	{
		printf("您输入的数字有误请重新输入");
		tongji_dingdan(admID);
	}
	
}


/************排序场次订单数**********/
 
void px_dingdan(char admID[20])
	
{ 
    read_admin();
	read_cin();
	read_order();
	int a,x,s=0,n=0,shu=0,numberb,p=0;
	for(n=0;n<nameadmin;n++)//对比输入的管理员ID 
	{
		if(strcmp(admID,admin[n].ID)==0)//得到管理员管理电影院名称 
		numberb=n;
	}
	for(a=0;a<namecin;a++)
    {
    	if(strcmp(admin[numberb].place,cin[a].place)==0)//在订单信息中循环得到其影院场次的订单数 
    	{
    		 strcpy(geshu[s].chang,cin[a].number);//将场次信息保存在结构中
			 for(x=0;x<nameode;x++)
		     {if(strcmp(cin[a].number,ode[x].chang)==0) // 将场次对应的订单数保存在结构中 
				shu++;}
			geshu[s].num=shu;
			shu=0;
			s++;
    	}
	} 	
	//排序法	
	int m;
	struct GESHU k; 
	for(m=1;m<=s-1;m++)
	{  
		for(n=0;n<=s-1-m;n++)
		{
	    	if(geshu[n].num<geshu[n+1].num)//大的在前 小的在后 
	    	{  
				k=geshu[n];
				geshu[n]=geshu[n+1];
				geshu[n+1]=k;    		    
	       	}
		}
	}       
		//由大到小排序场次订单数	  
  
  printf("您管理的影院场次订单排序如下：\n\n");
  printf("场次    订单数\n");
  for (;p<s;p++)
		{	
			
			printf("%s      %d\n",geshu[p].chang,geshu[p].num);
		}
		 
  //打印排好序的结构体 
   admfunction(admID);
   	
    	
} 

/*********************排序场次上座率******************/

void px_rate(char admID[20])
	
{ 
    read_admin();
	read_cin();
	read_order();
	int a,x,s=1,n=0,shu=0,numberb,jisuan,p=1;
	for(n=0;n<nameadmin;n++)//对比输入的管理员ID 
	{
		if(strcmp(admID,admin[n].ID)==0)//得到管理员管理电影院名称 
		numberb=n;
	}
	for(a=0;a<namecin;a++)
    {
    	if(strcmp(admin[numberb].place,cin[a].place)==0)//在场次信息中循环得到其影院场次的余票数 
    	{
    		strcpy(lv[s].chang,cin[a].number);// 将场次对应的场次好保存在结构中 
    		jisuan=(64-cin[a].margin);
			lv[s].rate=jisuan*100/64 ;
			s++;
    	}
	} 	
		//排序法
	int m;
	struct LV k; 
	for(m=1;m<=s-1;m++)
	{  
		for(n=1;n<=s-1-m;n++)
		{
	    	if(lv[n].rate<lv[n+1].rate)//大的在前 小的在后 
	    	{  
				k=lv[n];
				lv[n]=lv[n+1];
				lv[n+1]=k;    		    
	       	}
		}
	}       
			  
  //由大到小排序场次上座率 
  printf("您管理的影院场次上座率排序如下：\n\n");
  printf("场次      上座率\n");
  for (;p<s;p++)
		{	
			
			printf("%s      %.1f%c\n",lv[p].chang,lv[p].rate,'%');
		}
		 
  
   	 //打印排好序的结构体 
     admfunction(admID);	
}


/************************排序场次总票价**********************/

void px_changci(char admID[20])
	
{ 
    read_admin();
	read_cin();
	read_order();
	int a,x,s=1,n=0,shu=0,numberb,p=1;
	for(n=0;n<nameadmin;n++)//对比输入的管理员ID 
	{
		if(strcmp(admID,admin[n].ID)==0)//得到管理员管理电影院名称 
		numberb=n;
	}
	for(a=0;a<namecin;a++)//在场次信息中循环得到其影院场次的余票数
    {
    	if(strcmp(admin[numberb].place,cin[a].place)==0)//找到对应电影的价格 
    	{
    		strcpy(total[s].chang,cin[a].number);// 将场次对应的场次好保存在结构中
			total[s].money= (64-cin[a].margin)*cin[a].ticket;
			s++;
    	}
	} 	
		//排序法	
	int m;
	struct TOTAL k; 
	for(m=1;m<=s-1;m++)
	{  
		for(n=1;n<=s-1-m;n++)
		{
	    	if(total[n].money<total[n+1].money)//大的在前 小的在后 
	    	{  
				k=total[n];
				total[n]=total[n+1];
				total[n+1]=k;    		    
	       	}
		}
	}       
			  
  //由大到小排序场次总票价
  printf("您管理的影院场次总票价排序如下：\n\n");
  printf("场次      总票价\n");
  for (;p<s;p++)
		{	
			
			printf("%s      %.2f\n",total[p].chang,total[p].money);
		}
		 
   //打印排好序的结构体 
   	 admfunction(admID);
    	
}

/*****************************排序影厅总票价*********************/

 void px_yingting(char admID[20])
	
{ 
    read_admin();
	read_cin();
	read_order();
	int a,x,s=1,n=0,shu=0,numberb,p=1;
	for(n=0;n<nameadmin;n++)//对比输入的管理员ID 
	{
		if(strcmp(admID,admin[n].ID)==0)//得到管理员管理电影院名称 
		numberb=n;
	}
	for(a=0;a<namecin;a++)
    {
    	if(strcmp(admin[numberb].place,cin[a].place)==0)//在场次信息中循环得到其影院场次的余票数
    	{
    		yt[s].ting=cin[a].screen;// 将场次对应的场次好保存在结构中
			yt[s].money= (64-cin[a].margin)*cin[a].ticket;//找到对应电影的价格
			s++;
    	}
	} 	
			//排序法
	int m;
	struct YT k; 
	for(m=1;m<=s-1;m++)
	{  
		for(n=1;n<=s-1-m;n++)
		{
	    	if(yt[n].money<yt[n+1].money)//大的在前 小的在后 
	    	{  
				k=yt[n];
				yt[n]=yt[n+1];
				yt[n+1]=k;    		    
	       	}
		}
	}       
		//由大到小排序影厅总票价	  
  
  printf("您管理的影厅总票价排序如下：\n\n");
  printf("影厅      总票价\n");
  for (;p<s;p++)
		{	
			
			printf("%d厅      %.2f\n",yt[p].ting,yt[p].money);
		}
		 
   //打印排好序的结构体 
   	 admfunction(admID);
    	
}




/******************************************管理员查询影厅信息******************************/


void  examine_hall(char admID[20])
{
	read_admin();
	read_hall();
	int numberc,a=0,n=0,m=0;
	for(n=0;n<nameadmin;n++)
	{
		if(strcmp(admID,admin[n].ID)==0)
		numberc=n;
	}
	for(a=0;a<namehall;a++)
	{
		if(strcmp(admin[numberc].place,hall[a].ying)==0)
		{
			printf("----------------------------------------\n");
            printf("|影厅编号|所属影院 |影厅总座位|影厅类型|");
	        printf("\n---------------------------------------");
		    printf("\n%d          %s      %s          %s", hall[a].ID,hall[a].ying,hall[a].seat,hall[a].kind);
		    for(n=0;n<hall[a].hang;n++)
		    {
		       printf("\n");
			   for(m=0;m<hall[a].lie;m++)
			   {
				  printf(" ▇");
			   }
			} 
            printf("\n");
		} 
	}
	 admfunction(admID);
} 



/******************************管理员场次查询****************************************/ 
void examine_chang(char admID[20])
{
	read_admin();
	read_cin();
	int numberb,n=0,a=0;
	for(n=0;n<nameadmin;n++)
	{
		if(strcmp(admID,admin[n].ID)==0)
		numberb=n;
	}
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|场次号|电影名称|所属影院|放映影厅|电影开始时间|电影结束时间|电影时长|余票数|票价|影厅类型|场次类型|折扣|\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<namecin;a++)
    {
    	if(strcmp(admin[numberb].place,cin[a].place)==0)
    	printf("%s%12s  %s       %d       %s      %s        %s      %d      %.2f    %s   %s    %.2f\n",cin[a].number,cin[a].name,cin[a].place,cin[a].screen,cin[a].start_time,cin[a].end_time,
        cin[a].totaltime,cin[a].margin,cin[a].ticket,cin[a].kind,cin[a].sort,cin[a].discounts);
    }
     admfunction(admID);
	
}


/*********************************修改管理员密码**************************************/



void admin_pass(char admID[20])
{
	read_admin();
	int b,numbere,m,p,n;
	char newpass[20],code[20];
	for(b=0;b<nameadmin;b++)
	{
		if(strcmp(admID,admin[b].ID)==0)
		numbere=b;
	}
	printf("原密码:%s\n",admin[numbere].password);
	printf("请输入新密码(请输入6-10位):");
	scanf("%s",newpass);
	p=test_long2(newpass);
	while(p==2)
	{
	    printf("密码不符合要求，请重新输入(请输入6-10位):");
	    scanf("%s",newpass);
	    p=test_long2(newpass);
	}
	printf("确认密码:");
	scanf("%s",code);
	m=testCODE2(newpass,code);
	while(m!=0)
	{
	    printf("密码输入不一致，请重新输入新密码:");
	    scanf("%s",&newpass);
	    p=test_long2(newpass);
	    while(p==2)
	    {
            printf("密码不符合要求，请重新输入:");
	        scanf("%s",&newpass);
            p=test_long2(newpass);
	    }
        printf("再次新确认密码:");
	    scanf("%s",code);
        m=testCODE2(newpass,code);
	}
	
	strcpy(admin[numbere].password,newpass);
	printf("您的密码已更改为:%s\n",admin[numbere].password);
	FILE *outfile;
	outfile=fopen("admInformation.txt","w");
	for(n=0;n<nameadmin;n++)
	{
		fprintf(outfile,"%s   %s   %s   %s   %s\n",admin[n].ID,admin[n].place,admin[n].name,admin[n].mail,admin[n].password);
	}
	fclose(outfile);
	 admfunction(admID);	
} 
 
 
 /************************************修改管理员邮箱********************************/
 
 
 void admin_email(char admID[20])
{
	read_admin();
	int b,numberd,p,n;
	char newmail[20];
	for(b=0;b<nameadmin;b++)
	{
		if(strcmp(admID,admin[b].ID)==0)
		numberd=b;
	}
	printf("原邮箱:%s\n",admin[numberd].mail);
	printf("请输入新邮箱(格式***@***.***):");
	scanf("%s",newmail);
	p=test_email2(newmail);
	while(p!=1)
	{
		
	    printf("邮箱不符合要求，请重新输入(格式***@***.***):");
		scanf("%s",newmail);
		p=test_email2(newmail);
	}
	strcpy(admin[numberd].mail,newmail);
	printf("您的邮箱已更改为:%s\n",admin[numberd].mail);
	FILE *outfile;
	outfile=fopen("admInformation.txt","w");
	for(n=0;n<nameadmin;n++)
	{
		fprintf(outfile,"%s   %s   %s   %s   %s\n",admin[n].ID,admin[n].place,admin[n].name,admin[n].mail,admin[n].password);
	}
	fclose(outfile);
	 admfunction(admID);	
} 



/********************************个人信息管理***************************************/


int test_long2(char ID[10])//测试密码长度
{
	int i,count=0;
	for(i=0;ID[i]!='\0';i++)
	{
		count++;
	}
	if(count>10||count<6)
 		return 2;
	else
		return 1;
}


int testCODE2(char codeone[],char codetwo[])//检验确认密码输入正确 
{
	return (strcmp(codeone,codetwo));
}




int test_email2(char email[])//检验邮箱格式标准 
{
	char a='@',b='.',*string;
	string=strchr(email,a);
	if(string==NULL)
		return 0;
	else if(email>=string)
		return 0;
	else if(strchr(string+1,a)!=NULL)
		return 0;
	else if(strchr(string+1,b)==NULL)
		return 0;
	else if(strchr(email,b)<string)
		return 0;
	else if(strlen(string+1)<strlen(strchr(email,b)-1))
		return 0;
	else if(strlen(strchr(email,b)+1)<1)
		return 0;
	else
		return 1;
}

/*******************************添加场次*****************************************/

void increase_ci(char admID[20])
{
	read_cin();
	read_admin();
	int n,a,cishu=0,test_a=1,numberc,test_b=1,newscreen,b,nume=0,test_c=1,test_d=1,h;
	char newci[20],newname[20],choosea[20],entera[20],enterd[20];
	float newticket;
	namecin=namecin+1;
	//确定管理员所管影院 
	for(n=0;n<nameadmin;n++)
	{
		if(strcmp(admID,admin[n].ID)==0)
		numberc=n;
	}
	
	do{
	printf("请输入想添加的场次号"); 
	scanf("%s",newci);
	for(a=0;a<namecin;a++)
	{
			if(strcmp(cin[a].number,newci)==0&&strcmp(cin[a].place,admin[numberc].place)==0)
				cishu++;									
	}
	
	if(cishu!=0)
	{
		printf("\n你输入的场次号已经存在,请重新输入");
	}
	else
	{
		test_a=0;
		break;
	}	
	}while(test_a==1);	 
	strcpy(cin[namecin].number,newci);
	/*新添场次的影片的名字*/
	do{
	nume=0;
	printf("请输入您的新增场次的电影名字");
	scanf("%s",newname);
	if(strcmp(newname,"\0")==0)
	printf("输入影片名不能为空，请重新输入");
	else
	test_b==0;
	break;
	}while(test_b==1);
	strcpy(cin[namecin].name,newname);
	/*新添场次的所属影院*/
	strcpy(cin[namecin].place,admin[numberc].place);
	/*新添场次的影厅*/
	printf("输入你想输入的影厅编号（1-4）\n");
	scanf("%d",&newscreen);
	cin[namecin].screen=newscreen;
	/*新添场次的开始时间,结束时间，时长*/
	do{
	nume=1;
	printf("请选择新添场次的开始时间:\n");
	printf(" 1.10:00\n 2.12:00\n 3.14:00\n 4.16:00\n 5.18:00\n 6.20:00\n "); 
	scanf("%s",choosea);
	if(strcmp(choosea,"1")==0)
	{
		strcpy(cin[namecin].start_time,"10:00");
		strcpy(cin[namecin].end_time,"12:00");
		strcpy(cin[namecin].totaltime,"2");			
	}
	else if(strcmp(choosea,"2")==0)
	{
		strcpy(cin[namecin].start_time,"12:00");
		strcpy(cin[namecin].end_time,"14:00");
		strcpy(cin[namecin].totaltime,"2");	
	}
	else if(strcmp(choosea,"3")==0)
	{
		strcpy(cin[namecin].start_time,"14:00");
		strcpy(cin[namecin].end_time,"16:00");
		strcpy(cin[namecin].totaltime,"2");	
	}
	else if(strcmp(choosea,"4")==0)
	{
		strcpy(cin[namecin].start_time,"16:00");
		strcpy(cin[namecin].end_time,"18:00");
		strcpy(cin[namecin].totaltime,"2");	
	}
	else if(strcmp(choosea,"5")==0)
	{
		strcpy(cin[namecin].start_time,"18:00");
		strcpy(cin[namecin].end_time,"20:00");
		strcpy(cin[namecin].totaltime,"2");	
	}
	else if(strcmp(choosea,"6")==0)
	{
		strcpy(cin[namecin].start_time,"20:00");
		strcpy(cin[namecin].end_time,"22:00");
		strcpy(cin[namecin].totaltime,"2");	
	}
	else
	{
		printf("请输入有效数字（1—6）");
		nume=0;	 
	}
	for(b=0;b<namecin-1;b++)
	{
		if(newscreen==cin[b].screen&&strcmp(cin[b].place,admin[numberc].place)==0)
		{
			if(strcmp(cin[namecin].start_time,cin[b].start_time)==0||strcmp(cin[namecin].start_time,cin[b].end_time)==0
			||strcmp(cin[namecin].end_time,cin[b].start_time)==0||strcmp(cin[namecin].end_time,cin[b].end_time)==0)
		    {
    			printf("\n该场次放映时间和场次号为 %s 的场次相隔时间太近，排片时间应该考虑错开各影厅入场和散场的时间错开,请重新选择",cin[b].number);
    			nume=0;
    		}
		}
	} 
	}while(nume==0); 
	/*输入该场次票价*/ 
	cin[namecin].margin=64;
	printf("请输入该场次票价");
	scanf("%f",&newticket);
	cin[namecin].ticket=newticket;
	
	/*输入该场次类型*/ 
	do{
	printf("请选择该场次类型");
	printf("\n1.国语 2.英语");
	scanf("%s",entera);
	if(strcmp(entera,"1")==0)
	{
		strcpy(cin[namecin].kind,"国语");
		test_c=0;
		break; 
	} 
	else if(strcmp(entera,"2")==0)
	{
		strcpy(cin[namecin].kind,"英语");
		test_c=0;
		break; 
	}
	else
	{
		printf("请输入有效数字"); 
	}
	}while(test_c==1);
	
	
	
	/*输入该场次电影类型*/ 
	
	do{
	printf("请选择该场次电影类型");
	printf("\n1.3D 2.2D");
	scanf("%s",enterd);
	if(strcmp(enterd,"1")==0)
	{
		strcpy(cin[namecin].sort,"3D");
		test_d=0;
		break; 
	} 
	else if(strcmp(enterd,"2")==0)
	{
		strcpy(cin[namecin].sort,"2D");
		test_d=0;
		break; 
	}
	else
	{
		printf("请输入有效数字"); 
	}
	}while(test_d==1);
	/*输入折扣*/ 
	cin[namecin].discounts=1.00;
	//新加一行场次 
	FILE *outfile;
	outfile=fopen("场次信息.txt","a");
		fprintf(outfile,"%s %s %s %d %s %s %s %d %.2f %s %s %.2f\n",cin[namecin].number,cin[namecin].name,cin[namecin].place,cin[namecin].screen,cin[namecin].start_time,cin[namecin].end_time,
		cin[namecin].totaltime,cin[namecin].margin,cin[namecin].ticket,cin[namecin].kind,cin[namecin].sort,cin[namecin].discounts);
	fclose(outfile);
	printf("添加场次成功！！");	
	admfunction(admID);

		 
} 

/*************************************添加影厅*****************************************/

void increase_room(char admID[20])
{
	read_hall();
	read_admin();
	int frequency,counta=0,countb=0,countc=0,newID,a,test_num=1,newhang,newlie,testa,f,n,numberc;
	char newseat[20],choose_num[20];
	namehall=namehall+1;
	//确定管理员所管影院 
	for(n=0;n<nameadmin;n++)
	{
		if(strcmp(admID,admin[n].ID)==0)
		numberc=n;
	}
	if((strcmp(admin[numberc].place,hall[0].ying))==0)
	{
		counta++;
		newID=counta+1;
		hall[namehall].ID=newID;//新的影厅编号 
		strcpy(hall[namehall].ying,hall[0].ying);//新的所属影院 
	}
	else if((strcmp(admin[numberc].place,hall[1].ying))==0)
	{
		countb++;
		newID=countb+1;
		hall[namehall].ID=newID;
		strcpy(hall[namehall].ying,hall[1].ying);
	}
	else
	{
		countc++;
		newID=countc+1;
		hall[namehall].ID=newID;
		strcpy(hall[namehall].ying,hall[2].ying);
	}
	//添加新的影厅的总座位数 
	do{
		printf("请输入您当前添加影厅的总座位数");
	    scanf("%s",newseat); 
	    a=test_number(newseat);
	    if(a==1)
	    {
    		test_num=0;
	        break;
    	}
	    else
	    printf("请输入数字"); 
	    test_num=1;
	}while(test_num==1);
	  strcpy(hall[namehall].seat,newseat);
	  //选择新的影厅类型 
	  do{
  		printf("请选择改场次影厅类型");
	    printf("\n1.3D\n2.2D");
	    scanf("%s",choose_num);
	    if(strcmp(choose_num,"1")==0)
	    {
    		strcpy(hall[namehall].kind,"3D");
	        testa=0;
	        break;
    	}
	    else if(strcmp(choose_num,"2")==0)
	    {
    		testa=0;
	        strcpy(hall[namehall].kind,"2D");
			break;
    	}
	    else
	    {
		printf("\n请输入正确选项"); 
		testa=1;
		}
  	    }while(testa==1);
	  //新添影厅的行和列 
	  printf("当前新增影厅有：___行");
	  scanf("%d",&newhang);
	  hall[namehall].hang=newhang; 
      printf("当前新增影厅有：___列");
	  scanf("%d",&newlie);
	  hall[namehall].lie=newlie;
	  
     FILE *outfile;
	outfile=fopen("影厅信息.txt","a");
		fprintf(outfile,"%d %s %s %s  %d  %d\n",hall[namehall].ID,hall[namehall].ying,hall[namehall].seat,hall[namehall].kind,hall[namehall].hang,hall[namehall].lie);
	fclose(outfile);
	printf("添加影厅成功！！");	
	 admfunction(admID);
} 

int test_number(char numbera[])//检验输入的影厅总座位为数字
{ 
	int count=0,len,i;
	for(i=0;numbera[i]!='\0';i++)
	{
		len=i+1;
		if(isdigit(numbera[i])!=0)
		{
			count++;
		} 
		
	}
	if(len==count)
	return 1;
	else
	return 0;
} 

 //验证函数 
 int testshu(char stra[])
{
    int i,n,k=0;
    n=strlen(stra);
   for(i=0;i<n;i++)
    {
	if(isdigit(stra[i])!=0)
	k++;
	else
	return 0;
	
    }
   if(k==n)
   {
       return 1;
    }
}

