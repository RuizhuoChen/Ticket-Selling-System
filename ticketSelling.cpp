#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#define H 8
#define L 8
struct order
{
	char yonghu[20];//�ѹ�Ʊ�û�ID     
	char chang[20];//���򳡴κ�   
	char  zuowei[20];//��λ���� 
	int  duoshao;//����Ʊ�� 
	int  year;//��Ʊ�� 
	int  month;//��Ʊ�� 
	int  day;//��Ʊʱ     
	float price;//Ʊ��     
	char st[20];//��ʼʱ��    
	char et[20];//����ʱ��    
	char yingyuan[20];//ӰԺ
	int  numorder;//������
	char movie[20];//��Ӱ���� 
};
struct order ode[99];//�����ṹ 

struct SES
{
	char number[20];//���κ�
	char name[99];//��Ӱ���� 
	char place[100];//����ӰԺ 
	int screen;//��ӳӰ��
	char start_time[20];//��Ӱ��ʼʱ�� 
	char end_time[20];//��Ӱ����ʱ�� 
	char totaltime[20];//��Ӱʱ�� 
	int margin;//������Ʊ��
	float ticket;//����Ʊ��  
	char kind[20];//���η�ӳ����
	char sort[20]; //��ӳӰ������
	float discounts;//�����Żݻ
};
struct SES cin[99];//������Ϣ�ṹ

struct BUY 
{
    char ID[20];//�û�ID 
    char name[20];//���� 
    char gender[20];//�Ա� 
    char tele[20];//�绰 
    char password[20];//���� 
    char mail[20];//���� 
    int balance;//�˻���� 
}buy[100];
struct BUY user[99];//�û���Ϣ�ṹ 

using namespace std;
struct movie
{
	char information[12][20];
};//��ѯ�ṹ 

struct ADM
{
	char ID[10];//����ԱID
	char place[20];//����ӰԺ 
	char name[20];//���� 
	char mail[99];//���� 
	char password[16];//���� 
};

struct ADM admin[99];//����Ա��Ϣ�ṹ 

struct cinema
{
	int ID;//Ӱ����� 
	char ying[20];//����ӰԺ 
	char seat[20];//Ӱ������λ
	char kind[20];//Ӱ������
	int hang;//Ӱ���ж�����
	int lie;//Ӱ���ж����� 
};
struct cinema hall[99];//Ӱ���ṹ

struct GESHU
{
	char chang[20];//���κ�
	int num;//���ζ����� 
};
struct GESHU geshu[10];//�������Ӧ������ 

struct LV
{
	char chang[20];//���κ�
	float rate;//���������� 
};
struct LV lv[4];//�������Ӧ������

struct TOTAL
{
	char chang[20];//���κ�
	float money;//������Ʊ�� 
};
struct TOTAL total[4];//�������Ӧ��Ʊ��


struct YT
{
	int ting;//Ӱ���� 
	float money;//Ӱ����Ʊ�� 
};
struct YT yt[4];//Ӱ�����Ӧ��Ʊ�� 


int testshu(char []);//��֤���� 
void enter();//�������ҳ�� 
void userfunction();//�û����� 
void uregister();//�û�ע�� 
 
void search_fn();//���ݵ�Ӱ����ѯ
void selectkey();// ���ݵ�Ӱ����ӰԺ��ѯ
void choose_sort();//����2D��3Dɸѡ��Ӱ
void choose_kind();// ����Ӣ�����ɸѡ��Ӱ
void search_price();//����Ʊ���������г���
void search_margin();//������Ʊ���������г���
void search_time();//����ʱ���������г���


int test_changci(char [20]);//�����û����볡�κ��Ƿ���ȷ 
int test_time(char [],char []);//�Աȵ�Ӱʱ��������� 
int tuijian1(int [H][L],char getci[20],char zuoweihao[20]); //�Ƽ�һ����λ����ʾ��λͼ���� 
int tuijian2(int [H][L],char getci[20],char zuoweihao[20]); //�Ƽ�������λ����ʾ��λͼ����
int tuijian3(int [H][L],char getci[20],char zuoweihao[20]); //�Ƽ�������λ����ʾ��λͼ����
int zizhu1(int [H][L]); //�û��Լ�ѡһ����λ���� 
int zizhu2(int [H][L]);//�û��Լ�ѡ������λ���� 
int zizhu3(int [H][L]); //�û��Լ�ѡ������λ���� 
int test_shuliang(char []);//����û��������� 
int test_same(char [],char []);//����û�����ͬһ��ӰƬ 
void read_order();// dingdanA��ȡ����
void read_cin();//������Ϣ��ȡ����
void read_user();//userinformation��ȡ����
void goupiao();//  ��Ʊ��������
void check_price(char [20],int,char getci[20]); //�����û���������ֵ 
int test_yu(int);// ������ 
void change_yu(char [20]);//��ֵ��ı��û���� 
void change_yupiaoshu(char [],int);//�ı���Ʊ�� 


void read_user();
int test_phone(char []);//�����û��ֻ������Ƿ�Ϊʮһλ���� 
void change_phone(char []);//�޸��û��ֻ�����
int test_email();//�����û��ֻ������ʽ 
void change_email(char []);//�޸��û�����
int test_long(char []);//�������볤�� 
int testCODE(char[],char[]);// ����ȷ������������ȷ 
void change_pass(char []);//�޸��û����� 
void PIM(char []);//�û�������Ϣ���� 


void change_yue(char []);//������ֵ 
void inquiry_order(char [20]); 
void cancel_order();//ȡ������ 


void admfunction(char []);//����Ա���� 
void admdenglu();//����Ա��½
void examine_order(char []);//����Ա��ѯ����
void tongji_dingdan(char []);//����Աͳ�ƶ���
void px_dingdan(char [20]);//���򳡴ζ�����
void px_rate(char [20]);//���򳡴�������
void px_changci(char [20]);//���򳡴���Ʊ�� 
void px_yingting(char [20]);//����Ӱ����Ʊ�� 
void read_admin();//��ȡ����Ա�ļ���Ϣ 
void  examine_hall(char [20]);//����Ա��ѯӰ����Ϣ 
void read_hall();//Ӱ����Ϣ���뺯�� 
void examine_chang(char [20]);//����Ա��ѯ���п����Ӱ����Ϣ 
void admin_pass(char []);
void admin_email(char []);
int test_email2(char []);//���������ʽ��׼ 
int test_long2(char [10]);//�������볤��
int testCODE2(char [],char []);//����ȷ������������ȷ
void increase_ci(char []);// ��ӳ��� 
void increase_room(char []);// �����Ӱ�� 
int test_number(char numbera[]);//���������Ӱ������λΪ����

int nameuser=0,nameode=0,namecin=0,nameadmin=0,namehall=0;
int i,n;
char userID[20]={'\0'}; 
char admID[20]={'\0'};

int main()
{
	enter(); //���û�ӭ���� 
    return 0;
}







/****************************************�������ҳ��*********************************************/ 


 void enter() 
{
	char step1[10]={'\0'};
    char choose1[10];
	char userpassword[20]={'\0'};
	char choose2[10]; 
	int h=0,q=0;
	int success=1;
	char a;
	printf("\n					    ��ӰƱ����ϵͳ\n");
	printf("****************************************************************************************************************\n						1.�û�\n						2.����Ա\n");//����ѡ�� 
	printf("����������ѡ�\n");
	scanf("%s",step1);//��һ��ѡ�� 
	if(strlen(step1)>1)
	{
		printf("�������ָ���������������룺\n");
		enter();
	}
	if(strcmp(step1,"1")==0)//��ѡ��1�û�ѡ��ʱ 
	{ 
		while(strcmp(choose1,"1")!=0&&strcmp(choose1,"2")!=0)
		{
			printf("****************************************************************************************************************\n						1.ע��\n						2.��¼\n						3.������һ��\n");
	   		scanf("%s",choose1);//�û��ڶ���ѡ�� 
		if(strcmp(choose1,"2")==0) //���û�ѡ���¼ʱ 
		{
	        int h=0;
	        printf("��ӭ������¼���棡\n");
	        FILE *inFile;
	        while(success&&q!=3)
	           {
		            printf("����������ID�˺�:\n"); 
                    scanf("%s",userID); 
	                printf("�������������룺\n");
	  	            scanf("%s",userpassword); 
	                inFile=fopen("userInformation.txt","r");
	                if(inFile==NULL)
	                 {
   		               	printf("δ��ѯ�������˻�����˶Ժ���������\n");
   		               	enter();
                     }
	                while(fscanf(inFile,"%s %s %s %s %s %s %d\n ",buy[h].ID,buy[h].name,buy[h].gender,buy[h].tele,
							buy[h].password,buy[h].mail,&buy[h].balance)!=EOF) 
		                {
		                    if (strcmp(userID,buy[h].ID)==0&&strcmp(userpassword,buy[h].password)==0)
		                       {
				                     printf("�ɹ���¼��\n"); 
			                     success=0;
			                     break;//���ƥ��������ѭ���������� 
                               }
                               h++;
	                    }
	                if(success!=0)
	               {
	               		q++;
	               		printf("��½ʧ�ܣ�������%d�λ��ᣬ��ȷ������ID������\n",3-q);//��ƥ��ʱ�������� 
				   }
	            }
	        fclose(inFile);
	        if(q==3)
	    		enter();
	    	else
	    	{
	    		userfunction();//�û����빦��ҳ�� 
			}
	       
		}
		else if (strcmp(choose1,"1")==0)
		{
			uregister();//�û�ע��
			enter();
		}
		else if (strcmp(choose1,"3")==0)
		{
			enter();
		}
		else
		{
			printf("�������ָ���������������룺\n");
		}
		}
   	}
   	
   	else if(strcmp(step1,"2")==0)//��ѡ��2����Աѡ��ʱ
   	{
   	 	printf("****************************************************************************************************************\n						1.��½\n						2.������һ��\n");
	    scanf("%s",choose2);//����Ա����ѡ�� 
		if(strlen(choose2)>1)
		{
			printf("�������ָ���������������룺\n");
			enter() ;
		}	
		if(strcmp(choose2,"1")==0)
		{
			admdenglu();//����Ա��½ 
		}	
		if(strcmp(choose2,"2")==0)
		{
			printf("��ӭ�´�ʹ��");
			enter();
		}
   	 	exit(0);
	}
	
	else
	{
		printf("�������������������������");
		enter();
	}
} 
//--------------ע��------------ 
void uregister() 
{
	FILE*userInformation=fopen("userInformation.txt","a+");//�ļ�
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
        printf("�봴�������˺�,�˺�Ϊ�����ֺ���ĸ��ϳ��ַ���������Ϊ6λ��10λ��\n");
        scanf("%s",userID);
        if(strlen(userID)<6||strlen(userID)>10) //����˺ŵĳ���
        {
            printf("��������˺Ų�����λ��Ҫ��Ҫ�������´�����\n");
            a=1;
        }
        for (i=0;i<strlen(userID);i++)//����˺��Ƿ������ֺ���ĸ���
        {
            if(isalpha(userID[i]) == 0 && isdigit(userID[i]) == 0)//�Ȳ���Ӣ����ĸ�ֲ������� 
            {
                printf("��������˺ź��зǷ��ַ��������´���\n");
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
		 		printf("�ʻ������ظ�����������ID��\n");
		 		break;
			 }
			 p++;
		 }
        if (a==0&&b==0&&c==0)
            ok=0;
        else
            ok=1;
    }
    
    //����
     printf("����������������\n"); 
     scanf("%s",username);
          
    //�Ա� 
     ok=1;
     while(ok)
     {
     	printf("�����Ա� ������'man'or'woman'��\n");
     	scanf("%s",usergender);
     	if(strcmp(usergender,"man")==0||strcmp(usergender,"woman")==0)
     	{
	     	ok=0;
	     }
	     else
	     printf("�����Ա�������������������"); 
     	
     }
     
     //��ϵ�绰
	ok=1;
	int k,a=0,b=0;
	while(ok) 
	{
		printf("��������ϵ�˵�11λ�绰:\n");
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
			printf("������ϵ�˵绰λ���������������룺\n");
			a=0;
			b=0;
		}
		if(b!=0)
		{
			printf("������ϵ�˵绰���Ƿ��ַ����������룺\n");
			a=0;
			b=0;
		}
	}
    //����
	ok=1;
    while(ok)
    {
        printf("�봴����������\n");
        scanf("%s",userpassword);
        printf("���ٴ�������������\n");
        scanf("%s",userpassword2);
        if(strcmp(userpassword,userpassword2)!=0)
            printf("�����������벻ͬ�������´�������\n");
        else
            ok=0;
    }

	//����
	printf("����������(��ʽ***@***.***):");
	scanf("%s",youxiang);
	pp=test_email2(youxiang);
	while(pp!=1)
	{
		
	    printf("���䲻����Ҫ������������(��ʽ***@***.***):");
		scanf("%s",youxiang);
		pp=test_email2(youxiang);
	}
     //��ֵ 
     ok=1;
     while(ok)
     {
     	 printf("���Ƿ��ֵ�˻���1.��ֵ        2.����ֵ\n"); 
         scanf("%s",ch);
         if(strcmp(ch,"1")==0)
         {
     	       printf("�������ֵ���(������:\n");
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
     	    	printf("������������������\n");
     	    	ok=1;
    	        }
    	     	
    	     }
    	     else
    	        {
     	    	printf("������������������\n");
     	    	ok=1;
    	        }
 	     }
          
            
		else if(strcmp(ch,"2")==0)
            {Ybalance=0;
            ok=0;}
        else
       {
       	printf("������������������\n");
     	    	ok=1;
       } 
             
          
     }
    
   	



    
    printf("��ϲ�����ע��\n");
    system("pause");
    system("CLS");
    
    fprintf(userInformation,"%s %s %s %s %s %s %d\n",userID,userpassword,usergender,telephone,userpassword,youxiang,Ybalance);//д���ļ� 
    fclose(userInformation);
     
}


/******************************************����Ա��½*************************************/

 
void admdenglu()       
{	   
   	int h=0,q=0;
	int success=1;
	char admpassword[20]={'\0'};
	printf("��ӭ��������Ա��¼���棡\n");
    FILE *infile;
	while(success&&q!=3)
	           {
		            printf("����������ID�˺�:\n"); 
                    scanf("%s",admID); 
	                printf("�������������룺\n");
	  	            scanf("%s",admpassword); 
	                infile=fopen("admInformation.txt","r");
	                if(infile==NULL)
	                 {
   		               	printf("δ��ѯ�������˻�����˶Ժ���������\n");
   		               	enter();
                     }
	                while(fscanf(infile,"%s %s %s %s %s",admin[h].ID,admin[h].place,admin[h].name,admin[h].mail,admin[h].password)!=EOF) 
		                {
		                    if (strcmp(admID,admin[h].ID)==0&&strcmp(admpassword,admin[h].password)==0)
		                       {
				                     printf("�ɹ���¼��\n"); 
			                     success=0;
			                     break;//���ƥ��������ѭ���������� 
                               }
                               h++;
	                    }
	                if(success!=0)
	               {
	               		q++;
	               		printf("��½ʧ�ܣ�������%d�λ��ᣬ��ȷ������ID������\n",3-q);//��ƥ��ʱ�������� 
				   }
	            }
	        fclose(infile);
	        if(q==3)
	    		enter();
	    	else
	    	{
	    		admfunction(admID);//�û����빦��ҳ�� 
			}


}
 

/*******************************************�û�����*********************************/

void userfunction()//�û����� 
{ 
    
	int cnumber,fh,a=1;
	char Spage_num[20];
	while(a==1)
	{
		a=0; 
		int page_num,b=1;
		system("pause");
		system("CLS");
		printf("************************************************************************************************\n1.��ѯ\n2.��Ʊ\n3.�û�������Ϣ����\n4.��ֵ\n5.��ѯ����\n6.ȡ������\n7.����\n");
		scanf("%s",Spage_num);
		system("CLS");
		fh=testshu(Spage_num);
		if(fh==1)
		{
			page_num=atoi(Spage_num);
		}
		else
		{
			printf("���������������ȷ����\n");
			userfunction();
		}
		switch(page_num)
		{
			//ѡ���ѯ��ʽ 
			case 1:
			{
				while(b==1)
			    {
			        b=0;
					int chnumber2,fanh;
					char Schnumber2[20];
			        printf("1.����ӰƬ����ѯ\n2.����ӰƬ��+ӰԺ����ѯ\n3.�÷�ӳӰ������3D��2D��ѯ\n4.�÷�ӳ��������Ӣ������ѯ\n5.���ݷ�ӳ��ʼʱ���������г���\n6.���ݳ���Ʊ���������г���\n7.���ݳ�����Ʊ���������г���\n"); 
					scanf("%s",Schnumber2);
					 fanh=testshu(Schnumber2);
					 if(fh==1)
		            {
			               chnumber2=atoi(Schnumber2);
		            }
	 	             else
		            {
		               printf("���������������ȷ����\n");
			            userfunction();
		             }
			        switch(chnumber2)
			        {
	                    case 1:
				        search_fn();//����ӰƬ����ѯ
				        break; 
				        case 2:
                        selectkey();//����ӰƬ��+ӰԺ����ѯ
                        break;
                        case 3:
                        choose_sort();//�÷�ӳӰ������3D��4D��ѯ
                        break;
                        case 4:
						choose_kind(); //�÷�ӳ��������Ӣ������ѯ
						break; 
						case 5:
                        search_time();//���ݷ�ӳ��ʼʱ���������г���
                        break;
						case 6:
				        search_price();//���ݳ���Ʊ���������г���
				        break;
						case 7:
                        search_margin(); //���ݳ�����Ʊ���������г���
                        break;
						default:
                        printf("������������������1-7\n");
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
			printf("������������������1-6\n");
		    userfunction();
			a=1; 
			
		}
	}



} //printf("\n����������������������");
			



/*********************************dingdanA��ȡ����****************************/


void read_order()
{
	i=0;
	FILE *infile;
	infile=fopen("dingdanA.txt","a+");	
	
	if(infile==NULL)
	{
		printf("�޷���ȡ������Ϣ"); 
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






/*********************************������Ϣ��ȡ����****************************/


void read_cin()
{
	i=0;
	FILE *infile;
	infile=fopen("������Ϣ.txt","a+");
	if(infile==NULL){
		printf("�޷���ȡ������Ϣ"); 
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
/***************************userinformation��ȡ����*******************************/ 
void read_user()
{
	i=0;
	FILE *infile;
	infile=fopen("userInformation.txt","a+");	
	
	if(infile==NULL)
	{
		printf("�޷���ȡ�û���Ϣ"); 
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


/**********************************��ȡ����Ա��Ϣ����********************************/

 
void read_admin()
{
	 i=0;
	FILE *infile;
	infile=fopen("admInformation.txt","a+");	
	
	if(infile==NULL)
	{
		printf("�޷���ȡ����Ա��Ϣ"); 
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

/*************************************��ȡӰ����Ϣ*********************************/ 
void read_hall()
{
    i=0;
	FILE *infile;
	infile=fopen("Ӱ����Ϣ.txt","a+");	
	
	if(infile==NULL)
	{
		printf("�޷���ȡӰ����Ϣ"); 
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


/***************************************��ѯ����************************************************/ 

void search_fn()
{
    system("CLS");
    char cho[10] ={'\0'};
	int okk=0,k=0;
	char p[20]={'\0'};//����ӰƬ�� 
	read_cin();
  	printf("�������ѯ�ĵ�Ӱ����\n");
  	scanf("%s",p);
  
    printf("---------------------------------------------------------------------------------------------------------\n");
   	printf("|���κ�|��Ӱ����|����ӰԺ|��ӳӰ��|��Ӱ��ʼʱ��|��Ӱ����ʱ��|��Ӱʱ��|��Ʊ��|Ʊ��|Ӱ������|��������|�ۿ�|\n");
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
	 	printf("δ�鵽�õ�Ӱ�й���Ϣ������������\n");
	 	system("pause");
	    search_fn();
	 }
	else 
	{
	printf("������ҳ�������� 1      ��Ʊ������  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	{
		printf("�������ָ���������������룺\n");
		system("pause");
		search_fn();
	}
	if(strcmp(cho,"1")==0)
	userfunction();
	else if(strcmp(cho,"2")==0)
	goupiao();
	else
	{
		printf("�������������������������");
		system("pause");
		search_fn();
	}
		
    }
}
void selectkey()//���ݵ�Ӱ����ӰԺ��ѯ 
{
    system("CLS");
	char cho[10] ={'\0'};
	int okk=0,k=0;
	char p[20]={'\0'};//����ӰƬ�� 
	char q[20]={'\0'};//����ӰԺ��
	read_cin();
  	printf("�������ѯ�ĵ�Ӱ����\n");
  	scanf("%s",p);
    printf("�������ѯ��ӰԺ����\n");
  	scanf("%s",q);
    printf("---------------------------------------------------------------------------------------------------------\n");
   	printf("|���κ�|��Ӱ����|����ӰԺ|��ӳӰ��|��Ӱ��ʼʱ��|��Ӱ����ʱ��|��Ӱʱ��|��Ʊ��|Ʊ��|Ӱ������|��������|�ۿ�|\n");
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
	 	printf("δ�鵽�õ�Ӱ�й���Ϣ������������\n");
	 	system("pause");
	    selectkey();
	 }
	else 
	{printf("������ҳ�������� 1      ��Ʊ������  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	{
		printf("�������ָ���������������룺\n");
		system("pause");
		selectkey();
	}
	if(strcmp(cho,"1")==0)
	userfunction();
	else if(strcmp(cho,"2")==0)
	goupiao();
	else
	{
		printf("�������������������������");
		system("pause");
		selectkey();
	}
	
	}
}
void choose_sort()//����2D��3Dɸѡ 
{
    system("CLS");
    char cho[10] ={'\0'};
	int testb=0;
	char entera[20];
	char chara[20]="3D",charb[20]="2D";
	read_cin();
	do
	{
		printf("����������Ҫ��ѯ�ĳ���Ӱ������");
	    printf("\n1.3D\n2.2D");
	    scanf("%s",entera);
	    if(strcmp(entera,"1")==0)
	    {
    		printf("---------------------------------------------------------------------------------------------------------\n");
	    	printf("|���κ�|��Ӱ����|����ӰԺ|��ӳӰ��|��Ӱ��ʼʱ��|��Ӱ����ʱ��|��Ӱʱ��|��Ʊ��|Ʊ��|Ӱ������|��������|�ۿ�|\n");
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
	    	printf("|���κ�|��Ӱ����|����ӰԺ|��ӳӰ��|��Ӱ��ʼʱ��|��Ӱ����ʱ��|��Ӱʱ��|��Ʊ��|Ʊ��|Ӱ������|��������|�ۿ�|\n");
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
		printf("�������������������������");
		testb=0;
	    }
	    
    }while(testb==0);
		
	{
	printf("������ҳ�������� 1      ��Ʊ������  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	   {
		printf("�������ָ���������������룺\n");
		system("pause");
		choose_sort();
	    }
	if(strcmp(cho,"1")==0)
	   userfunction();
	else if(strcmp(cho,"2")==0)
	     goupiao();
	else
	  {
		printf("���������������,����������:\n");
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
	char chara[20]="����",charb[20]="Ӣ��";
	do
	{
		printf("����������Ҫ��ѯ��ӰƬ����\n");
	    printf("\n1.����\n2.Ӣ��\n");
	    scanf("%s",entera);
	   if(strcmp(entera,"1")==0)
	    {
    		printf("---------------------------------------------------------------------------------------------------------\n");
	    	printf("|���κ�|��Ӱ����|����ӰԺ|��ӳӰ��|��Ӱ��ʼʱ��|��Ӱ����ʱ��|��Ӱʱ��|��Ʊ��|Ʊ��|Ӱ������|��������|�ۿ�|\n");
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
	    	printf("|���κ�|��Ӱ����|����ӰԺ|��ӳӰ��|��Ӱ��ʼʱ��|��Ӱ����ʱ��|��Ӱʱ��|��Ʊ��|Ʊ��|Ӱ������|��������|�ۿ�|\n");
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
		printf("�������������������������");
		testb=0;
	    }
       }while(testb==0);
	{
	printf("������ҳ�������� 1      ��Ʊ������  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	   {
		printf("�������ָ���������������룺\n");
		system("pause");
		choose_kind();
	    }
	if(strcmp(cho,"1")==0)
	   userfunction();
	else if(strcmp(cho,"2")==0)
	     goupiao();
	else
	  {
		printf("���������������,����������:\n");
		system("pause");
		choose_kind();
	  }
	
	}
	
}

/***************************************������************************************************/ 

void search_price()//����Ʊ���������г���
{
	int ok,i=0,fanhui;
	char cho[10] ={'\0'};
	system("cls"); 
	struct SES cin[20];
	FILE *fp1;
	fp1=fopen("������Ϣ.txt","r");//�򿪶�ȡ�ļ�
	printf("\n             ����Ϊ����Ʊ�۵����򣡣�             \n");
	if(fp1==NULL)//�����ļ��Ƿ�� 
	{
		printf("\n             δ��ѯ������˶Ժ��������룡\n");
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
	//����
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
				cin[n+1]=k;    	//Ʊ����С��������	    
	       	}
		}
	}
		
	int p=0;
	printf("Ʊ���ɵ͵����������£�\n");	
	for (;p<i;p++)
		{	
			printf("\n���κţ�%s\n��Ӱ���ƣ�%s\n����ӰԺ��%s\n��ӳӰ����%d\n��Ӱ��ʼʱ�䣺%s\n��Ӱ����ʱ�䣺%s\n��Ӱʱ����%s\n������Ʊ����%d\n����Ʊ�ۣ�%.2f\n���η�ӳ���ͣ�%s\n��ӳӰ�����ͣ�%s\n�ó����Żݻ��%f\n",
			cin[p].number,cin[p].name,cin[p].place,cin[p].screen,cin[p].start_time,cin[p].end_time,cin[p].totaltime,
				cin[p].margin,cin[p].ticket,cin[p].kind,cin[p].sort,cin[p].discounts);
		}
		 
	fclose(fp1);
	{
	printf("������ҳ�������� 1      ��Ʊ������  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	   {
		printf("�������ָ���������������룺\n");
		system("pause");
		search_price();
	    }
	if(strcmp(cho,"1")==0)
	   userfunction();
	else if(strcmp(cho,"2")==0)
	     goupiao();
	else
	  {
		printf("���������������,����������:\n");
		system("pause");
		choose_kind();
	  }
	
	}
}


void search_margin()//������Ʊ���������г���
{
	int i=0;
	char cho[20];
	system("cls"); 
	struct SES cin[20];
	FILE *fp1;
	fp1=fopen("������Ϣ.txt","r");//�򿪶�ȡ�ļ�
	printf("\n             ����Ϊ������Ʊ�������򣡣�             \n");
	if(fp1==NULL)//�����ļ��Ƿ�� 
	{
		printf("\n             δ��ѯ������˶Ժ��������룡\n");
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
	//����
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
				cin[n+1]=k;    	//��Ʊ����С��������	    
	       	}
		}
	}
		
	int p=0;
	printf("��Ʊ���ɵ͵����������£�\n");	
	for (;p<i;p++)
		{	
			printf("\n���κţ�%s\n��Ӱ���ƣ�%s\n����ӰԺ��%s\n��ӳӰ����%d\n��Ӱ��ʼʱ�䣺%s\n��Ӱ����ʱ�䣺%s\n��Ӱʱ����%s\n������Ʊ����%d\n����Ʊ�ۣ�%.2f\n���η�ӳ���ͣ�%s\n��ӳӰ�����ͣ�%s\n�ó����Żݻ��%f\n",
			cin[p].number,cin[p].name,cin[p].place,cin[p].screen,cin[p].start_time,cin[p].end_time,cin[p].totaltime,
				cin[p].margin,cin[p].ticket,cin[p].kind,cin[p].sort,cin[p].discounts);
		}
		 
	fclose(fp1);
	{
	printf("������ҳ�������� 1      ��Ʊ������  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	   {
		printf("�������ָ���������������룺\n");
		system("pause");
		search_margin();
	    }
	if(strcmp(cho,"1")==0)
	   userfunction();
	else if(strcmp(cho,"2")==0)
	     goupiao();
	else
	  {
		printf("���������������,����������:\n");
		system("pause");
		search_margin();
	  }
	
	}
	
}




void search_time()//���ݿ�ʼʱ���������г���
{
	int i=0;
	char cho[20];
	system("cls"); 
	struct SES cin[20];
	FILE *fp1;
	fp1=fopen("������Ϣ.txt","r");//�򿪶�ȡ�ļ�
	printf("\n ����Ϊ���ݿ�ʼʱ������򣡣�             \n");
	if(fp1==NULL)//�����ļ��Ƿ�� 
	{
		printf("\n             δ��ѯ������˶Ժ��������룡\n");
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
	//����
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
				cin[n+1]=k;    	//��ʼʱ����С��������	    
	       	}
		}
	}
		
	int p=0;
	printf("��ʼʱ���ɵ͵����������£�\n");	
	for (;p<i;p++)
		{	
			printf("\n���κţ�%s\n��Ӱ���ƣ�%s\n����ӰԺ��%s\n��ӳӰ����%d\n��Ӱ��ʼʱ�䣺%s\n��Ӱ����ʱ�䣺%s\n��Ӱʱ����%s\n������Ʊ����%d\n����Ʊ�ۣ�%.2f\n���η�ӳ���ͣ�%s\n��ӳӰ�����ͣ�%s\n�ó����Żݻ��%f\n",
			cin[p].number,cin[p].name,cin[p].place,cin[p].screen,cin[p].start_time,cin[p].end_time,cin[p].totaltime,
				cin[p].margin,cin[p].ticket,cin[p].kind,cin[p].sort,cin[p].discounts);
		}
		 
	fclose(fp1);
	
	{
	printf("������ҳ�������� 1      ��Ʊ������  2\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	   {
		printf("�������ָ���������������룺\n");
		system("pause");
		search_time();
	    }
	if(strcmp(cho,"1")==0)
	   userfunction();
	else if(strcmp(cho,"2")==0)
	     goupiao();
	else
	  {
		printf("���������������,����������:\n");
		system("pause");
		search_time();
	  }
	
	}
}


/*********************************��Ʊ����************************************/ 

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
	/*��ʾ��ѡ��ĳ��ε�������Ϣ*/ 
	do{
	printf("����������Ҫѡ��ĳ���");
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
			printf("\n���κ� ��Ӱ���� ����ӰԺ ��ӳӰ�� ��Ӱ��ʼʱ�� ����ʱ��  ��Ӱʱ�� ������Ʊ�� ����Ʊ�� ��ӳ���� ��ӳӰ������ �����Żݻ\n");
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
 	
	printf("\n\n\n         ��ӰԺ��λ��\n");
	printf("��1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" �~ ");
		else 
			printf(" �� ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
	printf(" \n(�~ �������λ�Ѿ����ˣ���ѡ�� ��������λ)\n");
	while(ok) 
	{
	    printf("\n������Ҫ����ӰƱ��(��๺��3��):\n");
	    scanf("%s",Spiaoshu);
	
		if(strcmp(Spiaoshu,"1")==0||strcmp(Spiaoshu,"2")==0||strcmp(Spiaoshu,"3")==0)
		ok=0;
		else
		printf("����������������������\n");
	}
     piaoshu=atoi(Spiaoshu);
	printf("*****************��ѡ��Ʊ��ʽ*****************\n");
	
	
	ok=1;
	while(ok) 
	{
	    printf("1.����ѡƱ           2.�Ƽ�ѡƱ\n");
	    scanf("%s",Sfangshi);
	
		if(strcmp(Sfangshi,"1")==0||strcmp(Sfangshi,"2")==0)
		ok=0;
		else
		printf("����������������������\n");
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
	printf("         ��ӰԺ��λ��\n");
	printf("��1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j]==1)
			printf(" �~ ");
		else 
			printf(" �� ");
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
		printf("�޷���ȡ������Ϣ"); 
		exit(1);
	}
	
	Jshuliang=test_shuliang(userID);
    if(Jshuliang<5)
	{;} 
    else
    {
    	printf("һ���û�һ����๺������������������Ѵﵽ������޷���������\n");
    	enter();
    }
	     //��ɹ�Ʊ�������µ����ڣ������ɶ��� 
	time_t timer;
   struct tm *tblock;
    timer=time(NULL);
    tblock=localtime(&timer);
    yue = tblock->tm_mon+1;//��
    ri= tblock->tm_mday;//��
    shi = tblock->tm_hour;//ʱ
    check_price(userID,piaoshu,getci); 
    system("pause");
    nameode=nameode+1; 
	fprintf(infile,"%s       %s        %s        %d        %d       %d         %d       %.2f       %s        %s       %s        %d     %s\n",userID,getci,zzz,piaoshu,yue,ri,shi,cin[dijige].ticket,cin[dijige].start_time,cin[dijige].end_time,cin[dijige].place,nameode,cin[dijige].name);	
	system("CLS");
	printf("���������ɣ�\n���Ķ�����Ϣ����\n\n");
	printf("ID����:    %s\n���򳡴κ�:   %s\n��λ����:   %s\n����Ʊ��:  %d\n��Ʊ���ڣ�%d��%d��%dʱ\nƱ�ۣ�  %.2fԪ\n��ʼʱ�䣺 %s    ����ʱ�䣺  %s\nӰԺ����  %s\n�����ţ� %d\n��Ӱ���ƣ�   %s\n",userID,getci,zzz,piaoshu,yue,ri,shi,cin[dijige].ticket,cin[dijige].start_time,cin[dijige].end_time,cin[dijige].place,nameode,cin[dijige].name); 
	printf("��ϲ����ɹ�Ʊ!!!\n");
	change_yupiaoshu(getci,piaoshu);
	fclose(infile);
	printf("������������빦�ܺ���\n");
    userfunction(); 

}




/******************************����Ӱʱ���ͻ����********************************/    

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
	 
	//�����е��ַ���ʱ�䶼��Ϊ������ǰ��λ����λ��ʽ
	for(k=0;k<nameode;k++)//������ʼʱ�� 
	{
		strncpy(start,ode[k].st,2);
	    an[k]=atoi(start);
    	strncpy(start,ode[k].st+3,2); 
    	bn[k]=atoi(start);	
	}
	for(j=0;j<nameode;j++)//��������ʱ�� 
	{
		strncpy(end,ode[j].et,2);
	    ane[j]=atoi(end);
    	strncpy(end,ode[j].et+3,2); 
    	bne[j]=atoi(end);
	}
	for(l=0;l<namecin;l++)//���ο�ʼʱ�� 
	{
		strncpy(ostart,cin[l].start_time,2);
	    af[l]=atoi(ostart);
    	strncpy(ostart,cin[l].start_time+3,2); 
    	bf[l]=atoi(ostart);
	}
	for(m=0;m<namecin;m++)//���ν���ʱ�� 
	{
		strncpy(oend,cin[m].end_time,2);
	    afe[m]=atoi(oend);
    	strncpy(oend,cin[m].end_time+3,2); 
    	bfe[m]=atoi(oend);
	}
	//��������λ�����ϳ�һ�������бȽ�		
	for(y=0;y<namecin;y++)//���ο�ʼʱ�� 
	{
		aaa[y]=af[y]*100+bf[y];	 
	} 

	for(t=0;t<namecin;t++)//���ν���ʱ�� 
	{
		bbb[t]=afe[t]*100+ bfe[t];		
	}
	for(o=0;o<nameode;o++)//������ʼʱ�� 
	{
		ccc[o]=an[o]*100+bn[o];
	}
	for(g=0;g<nameode;g++)//��������ʱ�� 
	{
		ddd[g]=ane[g]*100+bne[g];
	}	
	j=0,i=0;	
    int test_number=1,testnum=0,test_number1=1;
    int time_s,time_e;      
	for(i=0;i<namecin;i++)
	{
      if(strcmp(chang,cin[i].number)==0)//ȥ������Ϣ���ҵ���Ӧ���Σ��ⲿ��Ӱ�Ŀ�ʼʱ����� time_s,����ʱ����time_e)
      {
      	time_s=aaa[i];
      	time_e=bbb[i];	
      }
	}			
	for(j=0;j<nameode;j++)
	{
		if(strcmp(getid,ode[j].yonghu)==0)//�ڶ�����Ϣ���ҵ��û�����һ������ ��ÿһ��������ʼʱ��ccc[j],����ʱ��ddd[j]
	    {
    		if(time_s<ccc[j])//Ҫ���Ŀ�ʼʱ��ȶ����е�С,��ʼʱ���ڶ���֮ǰ 
    		{
				if(time_e<=ccc[j])//Ҫ���Ľ���ʱ��ȶ����е�С
		    	{
	    			test_number=1;
	    		}
	    		else
	    		{
		    		printf("\n�������ӰƬ���ε�ʱ��Ͷ�����Ϊ%d�������ʱ���ͻ����ѡ���Ƿ��������",ode[j].numorder); 
		    		do
		    		{
	                    printf("\n1.��������\n2.ȡ�� ��������ѡ�񳡴κ�\n");
				        scanf("%s",Stestnumcheck);
				        if(testshu(Stestnumcheck))
				        {
        					testnumcheck=atoi(Stestnumcheck);
        				}
        				else
        				{
				        	printf("����������������ȷ����1��2 \n");
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
				printf("\n�������ӰƬ���ε�ʱ��Ͷ�����Ϊ%d�������ʱ���ͻ����ѡ���Ƿ��������",ode[j].numorder); 
    		    do
    		    {
                        printf("\n1.��������\n2.ȡ������������ѡ�񳡴κ�");
				         scanf("%s",Stestnumcheck2);
				        if(testshu(Stestnumcheck2))
				        {
        					testnumcheck2=atoi(Stestnumcheck2);
        				}
        				else
        				{
				        	printf("����������������ȷ����1��2 \n");
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







 

/*************************************�Ƽ���λ����****************************************/
 
int tuijian1(int a[H][L],char getci[20],char zuoweihao[20] )      //�Ƽ�1����λ 
{
//0������λΪ�գ�1������λ�Ѿ�����
int count=0,i,j,x,y,sc,q,ok=1,P=0,I=0,J=0;
char Sq[20];  
int max=100;
      for (int i=0; i<8; i++) {      //������
            for (int j=0; j<8; j++) {  //������
                  if (a[i][j]!=1) {
             P = (i-4)*(i-4)+(j-4)*(j-4);       //������λ�������λ�ľ���
                      if (max > P) {
                           max = P;
                I = i;
                J = j;
            }
         }
      }
}
      
	  printf("\nΪ���Ƽ�����λΪ����%d�� ��%d��\n",I+1,J+1);
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
	  	
	printf("��1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" �~ ");
		else 
			printf(" �� ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
	    
      while(ok)
	  {printf("\n�������Ƿ�ѡ���Ƽ���λ\n     1.ѡ���Ƽ���λ   2.����ѡ����λ \n");
      scanf("%s",Sq);
      if(strcmp(Sq,"1")==0||strcmp(Sq,"2")==0)
      {ok=0;}
	  else
	  printf("�밴�涨����1��2\n");
	  }
	  q=atoi(Sq);
      switch(q)
      {case 1:
      a[I][J]=1;        //ѡ�е���λ�����Ϊ1
	  sc=10*(I+1)+(J+1);
	  return(sc);
	   break;
       case 2:
       a[I][J]=0; 
      return(zizhu1(a)); 
	  break;        //�ص�������Ʊ����  
      }

	 
	  }


int tuijian2(int a[H][L],char getci[20],char zuoweihao[20])    //�Ƽ�2����λ 
{
//0������λΪ�գ�1������λ�Ѿ�����
int count=0,ii,j,x,y,sc,q,ok=1,P=0,I=0,J=0;   
char Sq[20];
int max=100;
  do{
  	
 
      for (int ii=0; ii<8; ii++) {      //������
            for (int j=0; j<8; j++) {  //������
                  if (a[ii][j]!=1) {
             P = (ii-4)*(ii-4)+(j-4)*(j-4);       //������λ�������λ�ľ���
                      if (max > P) {
                           max = P;
                I = ii;
                J = j;
            }
         }
      }
      }
      a[I][J]=1;
   if(a[I][J-1]==0)            //Ѱ�������λ�Աߵ���λ 
   { 
	  a[I][J-1]=1;

    //��������λΪ�գ���ѡ�� 
   printf("\nΪ���Ƽ�����λΪ����%d�� ��%d�� �� ��%d�� ��%d��(����ͼ)\n",I+1,J,I+1,J+1); 
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
	  	
	printf("��1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" �~ ");
		else 
			printf(" �� ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
    sc=1000*(I+1)+100*(J+1)+10*(I+1)+(J+2);
     break;}
     
     if(a[I][J+1]==0)            //Ѱ�������λ�Աߵ���λ 
   { 
	  a[I][J+1]=1;

    //����ұ���λΪ�գ���ѡ�� 
   printf("\nΪ���Ƽ�����λΪ����%d�� ��%d�� �� ��%d�� ��%d��(����ͼ)\n",I+1,J+1,I+1,J+2); 
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
	  	
	printf("��1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" �~ ");
		else 
			printf(" �� ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
    sc=1000*(I+1)+100*(J+1)+10*(I+1)+(J+2);
     break;}
     
   else 
   {a[I][J]=2; }              //����Ա���λ���ˣ�����Ϊ2���ٴν���ѡ�������λ 
   } while(1);
   
      while(ok)
	  {printf("�������Ƿ�ѡ���Ƽ���λ\n     1.ѡ���Ƽ���λ   2.����ѡ����λ \n");
      scanf("%s",Sq);
      if(strcmp(Sq,"1")==0||strcmp(Sq,"2")==0)
      {ok=0;}
	  else
	  printf("�밴�涨����1��2\n");
	  }
	  q=atoi(Sq);
      switch(q)
      {case 1:
	   return(sc);
	  break;         //ѡ�е���λ�����Ϊ1
       case 2: 
	   if(a[I][J-1]==1)
	   a[I][J]=0;
	   a[I][J-1]=0;
	        
	   if(a[I][J+1]==1)
	   a[I][J]=0;
	   a[I][J+1]=0;
      return(zizhu2(a)); 
	  break;        //�ص�������Ʊ����  
      }
   
   
   
   
   
   
} 

 int tuijian3(int a[H][L],char getci[20],char zuoweihao[20])    //�Ƽ�3����λ 
{
//0������λΪ�գ�1������λ�Ѿ�����
int count=0,ii,j,x,y,sc,q,ok=1,P=0,I=0,J=0;   
char Sq[20];
int max=100;
  do{
  	
 
      for (int ii=0; ii<8; ii++) {      //������
            for (int j=0; j<8; j++) {  //������
                  if (a[ii][j]!=1) {
             P = (ii-4)*(ii-4)+(j-4)*(j-4);       //������λ�������λ�ľ���
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
   a[I][J+1]=1;          //����ұߺ����2����λΪ�գ���ѡ��
   a[I][J-1]=1;  
   printf("\nΪ���Ƽ�����λΪ����%d�� ��%d�� ��%d�� ��%d�� �� ��%d�� ��%d��\n",I+1,J,I+1,J+1,I+1,J+2); 
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
	  	
	printf("��1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" �~ ");
		else 
			printf(" �� ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	} 
	 
	 
	 sc=100000*(I+1)+10000*(J)+1000*(I+1)+100*(J+1)+10*(I+1)+(J+2);
	 break;}
      

        

        
  if(a[I][J-1]==0&&a[I][J-2]==0)
   { 
   a[I][J-1]=1;           //������2����λΪ�գ���ѡ�� 
   a[I][J-2]=1;  
   printf("\nΪ���Ƽ�����λΪ����%d�� ��%d�� ��%d�� ��%d�� �� ��%d�� ��%d��\n",I+1,J-1,I+1,J,I+1,J+1); 
     
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
	  	
	printf("��1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" �~ ");
		else 
			printf(" �� ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
	 
	 
	 sc=100000*(I+1)+10000*(J-1)+1000*(I+1)+100*J+10*(I+1)+(J+1);
	 break;}   
	 
	 if(a[I][J+1]==0&&a[I][J+2]==0)
   { 
   a[I][J+1]=1;         //����ұ�2����λΪ�գ���ѡ�� 
   a[I][J+2]=1;  
   printf("\nΪ���Ƽ�����λΪ����%d�� ��%d�� ��%d�� ��%d�� �� ��%d�� ��%d��\n",I+1,J+1,I+1,J+2,I+1,J+3); 
     
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
	  	
	printf("��1   2   3   4   5   6   7   8\n");	
	for(i=0;i<H;i++)
	{
	   for(j=0;j<L;j++)
	   {
		if(a[i][j])
			printf(" �~ ");
		else 
			printf(" �� ");
		count++;
		if(count%8==0)
		printf("\n");
		}
	}
	 
	 
	 
	 sc=100000*(I+1)+10000*(J+1)+1000*(I+1)+100*(J+2)+10*(I+1)+(J+3);
	 break;}
   else 
   {a[I][J]=2; }        //������߶�����������ѡ�� 
   } while(1);
   
   
      while(ok)
	  {printf("�������Ƿ�ѡ���Ƽ���λ\n     1.ѡ���Ƽ���λ   2.����ѡ����λ \n");
      scanf("%s",Sq);
      if(strcmp(Sq,"1")==0||strcmp(Sq,"2")==0)
      {ok=0;}
	  else
	  printf("�밴�涨����1��2\n");
	  }
	  q=atoi(Sq);
      switch(q)
      {case 1:        //ѡ�е���λ�Ѿ������Ϊ1
	  return(sc);
	  break;         //ѡ�е���λ�Ѿ������Ϊ1
      case 2:
      
      if(a[I][J+1]==1&&a[I][J+2]==1)
   { 
   a[I][J]=0;
   a[I][J+1]=0;         //���Ƽ���λ��Ϊ0 
   a[I][J+2]=0;  
     }
     
      if(a[I][J+1]==1&&a[I][J-1]==1)
   { 
     a[I][J]=0;
	 a[I][J+1]=0;          //���Ƽ���λ��Ϊ0 
     a[I][J-1]=0;  
     }
     
     if(a[I][J-1]==1&&a[I][J-2]==1)
   { 
   a[I][J]=0;
   a[I][J-1]=0;           //���Ƽ���λ��Ϊ0 
   a[I][J-2]=0;  
     }
      return(zizhu3(a));
	  break;        //�ص�������Ʊ����  
      }
   
   
} 

/***********************************����ѡƱ����***********************************/

 
int zizhu1(int a[H][L])       //����ѡ1��Ʊ 
{ 
 int x,y,j,sc,hang,lie,ok=1;
 char Shang[20],Slie[20];
 char zuoweihao[20];
   		    
            printf("��ѡ����λ������Ϊ�� ");     //ѡ���һ����λ 
			scanf("%s",Shang); 
		    printf("��ѡ����λ������Ϊ ");
			scanf("%s",Slie) ;	
			if(strcmp(Shang,"1")==0||strcmp(Shang,"2")==0||strcmp(Shang,"3")==0||strcmp(Shang,"4")==0||strcmp(Shang,"5")==0||strcmp(Shang,"6")==0||strcmp(Shang,"7")==0||strcmp(Shang,"8")==0)
			{hang=atoi(Shang);}
			else 
			{printf("����������������������1-8\n");
			zizhu1(a);}
			if(strcmp(Slie,"1")==0||strcmp(Slie,"2")==0||strcmp(Slie,"3")==0||strcmp(Slie,"4")==0||strcmp(Slie,"5")==0||strcmp(Slie,"6")==0||strcmp(Slie,"7")==0||strcmp(Slie,"8")==0)
			{lie=atoi(Slie);}
			else 
			{printf("����������������������1-8\n");
			zizhu1(a);}
	        a[hang-1][lie-1]=1;
	//����Ƿ񰴹涨��������1-8
		  //���벻�����ٴ�ѭ��
	
	//��⺯��
	
		for(i=0;i<H;i++)
		{
			for(j=0;j<L;j++)
			{
				if(a[i][j]==1&&a[i][j+1]==0&&a[i][j+2]==1)
				{printf("������λ�м䲻�ܿ�1����λ�����������룺\n");
				a[hang-1][lie-1]=0;
				zizhu1(a);}
	 
			}
		}	
		sc=hang*10+lie;
       return(sc);		
	
	
}
int zizhu2(int a[H][L])        //����ѡ2��Ʊ 
{ 
  int x,y,j,sc,hang1,lie1,hang2,lie2;
  char Shang1[20],Slie1[20],Shang2[20],Slie2[20];
  char zuoweihao[20];
 
        
			printf("��ѡ���һ����λ������Ϊ�� ");     //ѡ���һ����λ 
			scanf("%s",Shang1); 
		    printf("��ѡ���һ����λ������Ϊ ");
			scanf("%s",Slie1) ;	
			if(strcmp(Shang1,"1")==0||strcmp(Shang1,"2")==0||strcmp(Shang1,"3")==0||strcmp(Shang1,"4")==0||strcmp(Shang1,"5")==0||strcmp(Shang1,"6")==0||strcmp(Shang1,"7")==0||strcmp(Shang1,"8")==0)
			{hang1=atoi(Shang1);}
			else 
			{printf("����������������������1-8\n");
			zizhu2(a);}
			if(strcmp(Slie1,"1")==0||strcmp(Slie1,"2")==0||strcmp(Slie1,"3")==0||strcmp(Slie1,"4")==0||strcmp(Slie1,"5")==0||strcmp(Slie1,"6")==0||strcmp(Slie1,"7")==0||strcmp(Slie1,"8")==0)
			{lie1=atoi(Slie1);}
			else 
			{printf("����������������������1-8\n");
			zizhu2(a);}
			do{
			printf("��ѡ��ڶ�����λ������Ϊ�� ");   //ѡ��ڶ�����λ 
			scanf("%s",Shang2); //������һ����λ��ͬ�� �ٴ����� 
		    printf("��ѡ��ڶ�����λ������Ϊ ");
			scanf("%s",Slie2) ;
			if(strcmp(Shang2,"1")==0||strcmp(Shang2,"2")==0||strcmp(Shang2,"3")==0||strcmp(Shang2,"4")==0||strcmp(Shang2,"5")==0||strcmp(Shang2,"6")==0||strcmp(Shang2,"7")==0||strcmp(Shang2,"8")==0)
			{hang2=atoi(Shang2);}
			else 
			{printf("����������������������1-8\n");
			zizhu2(a);}
			if(strcmp(Slie2,"1")==0||strcmp(Slie2,"2")==0||strcmp(Slie2,"3")==0||strcmp(Slie2,"4")==0||strcmp(Slie2,"5")==0||strcmp(Slie2,"6")==0||strcmp(Slie2,"7")==0||strcmp(Slie2,"8")==0)
			{lie2=atoi(Slie2);}
			else 
			{printf("����������������������1-8\n");
			zizhu2(a);}
				
			} while(hang1==hang2&&lie1==lie2);
			
			a[hang1-1][lie1-1]=1;
            a[hang2-1][lie2-1]=1;
			
			
           //����Ƿ񰴹涨��������1-8
		  //���벻�����ٴ�ѭ��
		
	//��⺯��
	
		for(i=0;i<H;i++)
		{
			for(j=0;j<L;j++)
			{
				if(a[i][j]==1&&a[i][j+1]==0&&a[i][j+2]==1)
				{printf("������λ�м䲻�ܿ�1����λ�����������룺\n");
				a[hang1-1][lie1-1]=0;
	            a[hang2-1][lie2-1]=0;
				zizhu2(a);}
	 
			}
		}
	sc=hang1*1000+lie1*100+hang2*10+lie2;
    return(sc);
				
	   			
} 

int zizhu3(int a[H][L])      //����ѡ3��Ʊ 
{
  int i,j,sc,hang1,lie1,hang2,lie2,hang3,lie3;
  char Shang1[20],Slie1[20],Shang2[20],Slie2[20],Shang3[20],Slie3[20];
  char zuoweihao[20];

  
  	        printf("��ѡ���һ����λ������Ϊ�� ");     //ѡ���һ����λ 
			scanf("%s",Shang1); 
		    printf("��ѡ���һ����λ������Ϊ ");
			scanf("%s",Slie1) ;	
			if(strcmp(Shang1,"1")==0||strcmp(Shang1,"2")==0||strcmp(Shang1,"3")==0||strcmp(Shang1,"4")==0||strcmp(Shang1,"5")==0||strcmp(Shang1,"6")==0||strcmp(Shang1,"7")==0||strcmp(Shang1,"8")==0)
			{hang1=atoi(Shang1);}
			else 
			{printf("����������������������1-8\n");
			zizhu3(a);}
			if(strcmp(Slie1,"1")==0||strcmp(Slie1,"2")==0||strcmp(Slie1,"3")==0||strcmp(Slie1,"4")==0||strcmp(Slie1,"5")==0||strcmp(Slie1,"6")==0||strcmp(Slie1,"7")==0||strcmp(Slie1,"8")==0)
			{lie1=atoi(Slie1);}
			else 
			{printf("����������������������1-8\n");
			zizhu3(a);}
			do{
			printf("��ѡ��ڶ�����λ������Ϊ�� ");   //ѡ��ڶ�����λ 
			scanf("%s",Shang2); //������һ����λ��ͬ�� �ٴ����� 
		    printf("��ѡ��ڶ�����λ������Ϊ ");
			scanf("%s",Slie2) ;
			if(strcmp(Shang2,"1")==0||strcmp(Shang2,"2")==0||strcmp(Shang2,"3")==0||strcmp(Shang2,"4")==0||strcmp(Shang2,"5")==0||strcmp(Shang2,"6")==0||strcmp(Shang2,"7")==0||strcmp(Shang2,"8")==0)
			{hang2=atoi(Shang2);}
			else 
			{printf("����������������������1-8\n");
			zizhu3(a);}
			if(strcmp(Slie2,"1")==0||strcmp(Slie2,"2")==0||strcmp(Slie2,"3")==0||strcmp(Slie2,"4")==0||strcmp(Slie2,"5")==0||strcmp(Slie2,"6")==0||strcmp(Slie2,"7")==0||strcmp(Slie2,"8")==0)
			{lie2=atoi(Slie2);}
			else 
			{printf("����������������������1-8\n");
			zizhu3(a);}
				
			} while(hang1==hang2&&lie1==lie2);
		    
            do{
			printf("��ѡ���������λ������Ϊ�� ");   //ѡ���������λ 
			scanf("%s",Shang3);
		    printf("��ѡ���������λ������Ϊ ");     //������һ����ڶ�����λ��ͬ�� �ٴ�����
			scanf("%s",Slie3) ;
			if(strcmp(Shang3,"1")==0||strcmp(Shang3,"2")==0||strcmp(Shang3,"3")==0||strcmp(Shang3,"4")==0||strcmp(Shang3,"5")==0||strcmp(Shang3,"6")==0||strcmp(Shang3,"7")==0||strcmp(Shang3,"8")==0)
			{hang3=atoi(Shang3);}
			else 
			{printf("����������������������1-8\n");
			zizhu3(a);}
			if(strcmp(Slie3,"1")==0||strcmp(Slie3,"2")==0||strcmp(Slie3,"3")==0||strcmp(Slie3,"4")==0||strcmp(Slie3,"5")==0||strcmp(Slie3,"6")==0||strcmp(Slie3,"7")==0||strcmp(Slie3,"8")==0)
			{lie3=atoi(Slie3);}
			else 
			{printf("����������������������1-8\n");
			zizhu3(a);} 
        	}while(hang1==hang3&&lie1==lie3||hang2==hang3&&lie2==lie3);
			
            //����Ƿ񰴹涨��������1-8 
	        //���벻�����ٴ�ѭ��
			
		
	a[hang1-1][lie1-1]=1;
	a[hang2-1][lie2-1]=1;
	a[hang3-1][lie3-1]=1;
	//����λ��������޸� 	
	//��⺯��	
	
		for(i=0;i<H;i++)
		{
			for(j=0;j<L;j++)
			{
				if(a[i][j]==1&&a[i][j+1]==0&&a[i][j+2]==1)
				{printf("������λ�м䲻�ܿ�1����λ�����������룺\n");
				a[hang1-1][lie1-1]=0;
	            a[hang2-1][lie2-1]=0;
                a[hang3-1][lie3-1]=0;
				zizhu3(a);}
	 
			}
		}
sc=hang1*100000+lie1*10000+hang2*1000+lie2*100+hang3*10+lie3;
return(sc);
	
	
  }
  
  


/*****************************�������볡���Ƿ���ȷ����*****************************/

 
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


/********************************����һ���û�û�г����������*************************************/ 

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


/********************************����һ���û���ͬһ����Ӱ****************************************/ 

int test_same(char getid[20],char moviename[20])
{
      int amount=0,h,f=1,test_num=0; 
	  char Sh[20]; 
    read_order();
	for(i=0;i<nameode;i++)
    {
	    	if(strcmp(moviename,ode[i].movie)==0&&strcmp(getid,ode[i].yonghu)==0)
	    	{
			  printf("���Ѿ��������ͬӰƬ��ӰƱ,��ѡ���Ƿ��������ǰӰƬ\n");	
			  do{
				   printf("1.��������\n2.ȡ�����򣬷�������ѡ�񳡴�\n��ѡ��");
			       scanf("%s",Sh);
			       if(testshu(Sh))
			       {
       				h=atoi(Sh);
       			    }
       			  else
       			    {
			       	printf("������������������1��2\n");
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

/************************************����û�����ֵ����*************************************/ 
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
		printf("�������㣬����г�ֵ");
		change_yu(getid);
		start_yu=user[num].balance; 
	}
	else	
	check_num=1;
	}while(check_num==0);
	totalyu=start_yu-everyprice*piaoshu;
	printf("�����˻���Ʊ���Ѿ����%d",totalyu);
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
				printf("���������˻��ϵ����Ϊ:%d\n",user[j].balance);
				printf("��ѡ����Ҫ��ֵ�Ľ��Ϊ��");
				scanf ("%s",Sadd_yu);
				if(testshu(Sadd_yu)==1)
				{
					add_yu=atoi(Sadd_yu);
					user[j].balance=user[j].balance+add_yu;	
					printf("�����˻�����Ѹ���Ϊ:%d\n",user[j].balance);
				}
				else
				{
					printf("�����������������룺\n");
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
/***********************************�ı���Ʊ��******************************/ 
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
	infile=fopen("������Ϣ.txt","w");
	for(n=0;n<namecin;n++)
	{
		fprintf(infile,"%s   %s   %s   %d   %s   %s   %s   %d   %.2f   %s   %s   %.2f\n",cin[n].number,cin[n].name,cin[n].place,cin[n].screen,cin[n].start_time,cin[n].end_time,
		cin[n].totaltime,cin[n].margin,cin[n].ticket,cin[n].kind,cin[n].sort,cin[n].discounts);
	
	}
    fclose(infile);
} 




/*******************************************�û�������Ϣ����*********************************************/ 


void PIM(char userID[20])//�û�������Ϣ���� 
{
	read_user(); 
	int testnum=0;
	char cho[10] ={'\0'};
	do
	{
        printf("��ѡ����Ҫ�޸ĵ���Ϣ");
	    printf("\n1.�绰\n2.����\n3.����");
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
	     {printf("�������������Ч����������Чѡ�1��2��3��");}
			
		
	}while(testnum==0);
	userfunction();
} 

int test_phone(char phone[])//�����ֻ���Ϊ11λ���� 
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


void change_phone(char userID[20])//�û��޸��ֻ���
{
	int n,a=0,b=2,p,j=0;
	char newphone[11];	
	do
	{
		do
		{
			if(strcmp(userID,user[j].ID)==0)
			{
				printf("ԭ�ֻ���:%s\n",user[j].tele);
				printf("���������ֻ���(������11λ����):");
				scanf("%s",&newphone);
				p=test_phone(newphone);
				while(p==2)
				{
					printf("�ֻ��Ų�����Ҫ������������(������11λ����):");
					scanf("%s",&newphone);
					p=test_phone(newphone);
				}
				strcpy(user[j].tele,newphone);
				printf("�����ֻ����Ѹ���Ϊ:%s\n",user[j].tele);
				a=1;
				b=1;
				break;
			}
			j++;	
		}while(j<nameuser);
		if(a!=1)
		{
			printf("�û�ID�����ڣ�����������:");
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


int test_email(char email[])//���������ʽ��׼ 
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


void change_email(char userID[20])//�û���¼-�û���Ϣ����-�޸���Ϣ-�޸�����
{
 int n,a=0,b=2,p,j=0;
 char newemail[20];
 do
 {
  do
  {
   if(strcmp(userID,user[j].ID)==0)
   {
    printf("ԭ����:%s\n",user[j].mail);
    printf("������������(��ʽ***@***.***):");
    scanf("%s",&newemail);
    p=test_email(newemail);
    while(p!=1)
    {
     printf("���䲻����Ҫ������������(��ʽ***@***.***):");
     scanf("%s",&newemail);
     p=test_email(newemail);
    }
    strcpy(user[j].mail,newemail);
    printf("���������Ѹ���Ϊ:%s\n",user[j].mail);
    a=1;
    b=1;
    break;
   }
   j++; 
  }while(j<nameuser);
  if(a!=1)
  {
   printf("�û�ID�����ڣ�����������:");
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



int test_long(char ID[10])//�������볤��
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


int testCODE(char codeone[],char codetwo[])//����ȷ������������ȷ 
{
	return (strcmp(codeone,codetwo));
}




void change_pass(char userID[20])//�޸����� 
{
	int n,a=0,b=2,m,p,j=0;
	char newpass[10],code2[10]; 
	do
	{
		do
		{
			if(strcmp(userID,user[j].ID)==0)
			{
				printf("ԭ����:%s\n",user[j].password);
				printf("������������(������6-10λ):");
				scanf("%s",&newpass);
				p=test_long(newpass);
					while(p==2)
				{
					printf("���벻����Ҫ������������(������6-10λ):");
					scanf("%s",&newpass);
					p=test_long(newpass);
				}
				printf("ȷ������:");
				scanf("%s",&code2);
				m=testCODE(newpass,code2);
				while(m!=0)
				{
					printf("�������벻һ�£�����������������:");
					scanf("%s",&newpass);
					p=test_long(newpass);
					while(p==2)
					{
						printf("���벻����Ҫ������������:");
						scanf("%s",&newpass);
						p=test_long(newpass);
					}
					printf("�ٴ���ȷ������:");
					scanf("%s",&code2);
					m=testCODE(newpass,code2);
				}
				strcpy(user[j].password,newpass);
				printf("���������Ѹ���Ϊ:%s\n",user[j].password);
				a=1;
				b=1;
				break;
			}
			j++;	
		}while(j<nameuser);
		if(a!=1)
		{
			printf("�û�ID�����ڣ�����������:");
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

/**********************************************��ֵ����**********************************/ 

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
				printf("���������˻��ϵ����Ϊ:%d\n",user[j].balance);
				printf("��ѡ����Ҫ��ֵ�Ľ��Ϊ��");
				scanf ("%s",Sadd_yu);
				if(testshu(Sadd_yu)==1)
				{
					add_yu=atoi(Sadd_yu);
					user[j].balance=user[j].balance+add_yu;	
					printf("�����˻�����Ѹ���Ϊ:%d\n",user[j].balance);
				}
				else
				{
					printf("�����������������룺\n");
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

/****************************************��ѯ��������***********************************/ 

void inquiry_order(char userID[20])
{ 
	read_order();
	int i=0;	
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|����ID|���򳡴κ�|��λ����|����Ʊ��|��������(��)|(��)|(ʱ)|Ʊ��|��ʼʱ��|����ʱ��|ӰԺ|������|��Ӱ����|");
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

/**************************************ȡ����������**********************************/ 

void cancel_order()
{
	
	read_order();
	int j,flag,fanhui,ok=0,test_total=0;
	int ordernum;
	char Sordernum[20];
		FILE *infile;
	printf("��ѡ����Ҫȡ���Ķ����Ķ�����");
	scanf("%s",Sordernum);
	fanhui=testshu(Sordernum); 
	if(fanhui==1)
	{
		ordernum=atoi(Sordernum);
	}
	
	if(ordernum>nameode+1)
	{
	    printf("δ��ѯ�����������ţ����������룺\n");
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
	printf("������ȡ��\n");
	userfunction();}
	
}


void admfunction(char admID[20])//����Ա���� 

{ 
    
	int a=1;
	while(a==1)
	{
		a=0; 
		int page_num,b=1,c=1,d=1,xiugai,fh;
		char Spage_num[20];
		system("pause");
		system("CLS");
		printf("************************************************************************************************\n1.��������\n2.Ӱ������\n3.���ι���\n4.������Ϣ����\n5.����\n");
		scanf("%s",Spage_num);
		system("CLS");
		fh=testshu(Spage_num);
		if(fh==1)
		{
			page_num=atoi(Spage_num);
		}
		else
		{
			printf("���������������ȷ����\n");
			admfunction(admID);
		}
		system("CLS");
		switch(page_num)
		{
			//ѡ���ѯ��ʽ 
			case 1:
			{
				while(b==1)
			    {
			        b=0;
					int admnumber1,fanh;
					char Sadmnumber1[20];
			        printf("1.�鿴�û��������\n2.ͳ���û�������Ϣ\n"); 
					scanf("%s",Sadmnumber1);
					 fanh=testshu(Sadmnumber1);
					 if(fanh==1)
		            {
			               admnumber1=atoi(Sadmnumber1);
		            }
	 	             else
		            {
		               printf("���������������ȷ����\n");
			            admfunction(admID);
		             } 
					
			        switch(admnumber1)
			        {
	                    case 1:
				        examine_order(admID);//�鿴�û��������
				        break; 
				        case 2:
                        tongji_dingdan(admID);//ͳ���û�������Ϣ
                        break;
						default:
                        printf("\n �����������������\n");
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
			        printf("1.Ӱ����ѯ\n2.���Ӱ��\n"); 
					scanf("%s",Sadmnumber2);
					 fanh=testshu(Sadmnumber2);
					 if(fanh==1)
		            {
			               admnumber2=atoi(Sadmnumber2);
		            }
	 	             else
		            {
		               printf("���������������ȷ����\n");
			            admfunction(admID);
		             } 
			        switch(admnumber2)
			        {
	                    case 1:
				        examine_hall(admID);//Ӱ����ѯ
				        break; 
				        case 2:
                        increase_room(admID);//���Ӱ��
                        break;
						default:
                        printf("\n�����������������\n");
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
			        printf("1.���β�ѯ\n2.��ӳ���\n"); 
					scanf("%s",Sadmnumber3);
					 fanh=testshu(Sadmnumber3);
					 if(fanh==1)
		            {
			               admnumber3=atoi(Sadmnumber3);
		            }
	 	             else
		            {
		               printf("���������������ȷ����\n");
		               admfunction(admID);
		             }  
			        switch(admnumber3)
			        {
	                    case 1:
				        examine_chang(admID);//���β�ѯ
				        break; 
				        case 2:
                        increase_ci(admID);//��ӳ���
                        break;
						default:
                        printf("\n�����������������\n");
                        admfunction(admID);
		                d=1;
		            }
	       		break;
    	    }
			case 4:
			{
				int fanh;
				char Sxiugai[20];
				printf("�������޸�����   1.����   2.����\n");
				scanf("%s",Sxiugai);
					 fanh=testshu(Sxiugai);
					 if(fanh==1)
		            {
                        xiugai=atoi(Sxiugai);
		            }
	 	             else
		            {
		               printf("���������������ȷ����\n");
			            admfunction(admID);
		             } 
				if(xiugai==1)
				admin_pass(admID);
				else if(xiugai==2)
				admin_email(admID);
				else
				printf("������������������\n"); 
				admfunction(admID);
	       		break;
			} 
			case 5:
			{
				enter();
			}
			
			default:
			printf("\n���������������ȷ����\n");
			admfunction(admID);
			a=1; 
		}
	}
 } 
}

}



/******************************************����Ա��ѯ����******************************/

void examine_order(char admID[20])//����Ա��ѯ����
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
	printf("|��Ʊ�û�ID|���򳡴κ�|��λ����|����Ʊ��|��������(��)|(��)|(��)|Ʊ��|��ʼʱ��|����ʱ��|ӰԺ|������|��Ӱ����|");
	printf("\n--------------------------------------------------------------------------------------------------------");
	for(i=0;i<nameode;i++)
	{
		if(strcmp(admin[numbera].place,ode[i].yingyuan)==0)
		printf("\n   %s%8s%10s%10d%8d%8d%6d%7.2f%7s%8s%8s%5d   %s\n",ode[i].yonghu,ode[i].chang,ode[i].zuowei,ode[i].duoshao,ode[i].year,ode[i].month,ode[i].day,ode[i].price,ode[i].st,ode[i].et,ode[i].yingyuan,ode[i].numorder,ode[i].movie);
	}	
	 admfunction(admID);
}



/**************************************����Աͳ�ƶ�����Ϣ**********************************/ 

void tongji_dingdan(char admID[20])
{
	char cho[10] ={'\0'};
	printf("��ѡ��Ҫͳ�ƵĶ�����Ϣ\n1.���ζ�����������      2.��������������       3.������Ʊ������         4.Ӱ����Ʊ������\n");
	scanf("%s",cho);
	if(strlen(cho)>1)
	{
		printf("�������ָ���������������룺\n");
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
		printf("�������������������������");
		tongji_dingdan(admID);
	}
	
}


/************���򳡴ζ�����**********/
 
void px_dingdan(char admID[20])
	
{ 
    read_admin();
	read_cin();
	read_order();
	int a,x,s=0,n=0,shu=0,numberb,p=0;
	for(n=0;n<nameadmin;n++)//�Ա�����Ĺ���ԱID 
	{
		if(strcmp(admID,admin[n].ID)==0)//�õ�����Ա�����ӰԺ���� 
		numberb=n;
	}
	for(a=0;a<namecin;a++)
    {
    	if(strcmp(admin[numberb].place,cin[a].place)==0)//�ڶ�����Ϣ��ѭ���õ���ӰԺ���εĶ����� 
    	{
    		 strcpy(geshu[s].chang,cin[a].number);//��������Ϣ�����ڽṹ��
			 for(x=0;x<nameode;x++)
		     {if(strcmp(cin[a].number,ode[x].chang)==0) // �����ζ�Ӧ�Ķ����������ڽṹ�� 
				shu++;}
			geshu[s].num=shu;
			shu=0;
			s++;
    	}
	} 	
	//����	
	int m;
	struct GESHU k; 
	for(m=1;m<=s-1;m++)
	{  
		for(n=0;n<=s-1-m;n++)
		{
	    	if(geshu[n].num<geshu[n+1].num)//�����ǰ С���ں� 
	    	{  
				k=geshu[n];
				geshu[n]=geshu[n+1];
				geshu[n+1]=k;    		    
	       	}
		}
	}       
		//�ɴ�С���򳡴ζ�����	  
  
  printf("�������ӰԺ���ζ����������£�\n\n");
  printf("����    ������\n");
  for (;p<s;p++)
		{	
			
			printf("%s      %d\n",geshu[p].chang,geshu[p].num);
		}
		 
  //��ӡ�ź���Ľṹ�� 
   admfunction(admID);
   	
    	
} 

/*********************���򳡴�������******************/

void px_rate(char admID[20])
	
{ 
    read_admin();
	read_cin();
	read_order();
	int a,x,s=1,n=0,shu=0,numberb,jisuan,p=1;
	for(n=0;n<nameadmin;n++)//�Ա�����Ĺ���ԱID 
	{
		if(strcmp(admID,admin[n].ID)==0)//�õ�����Ա�����ӰԺ���� 
		numberb=n;
	}
	for(a=0;a<namecin;a++)
    {
    	if(strcmp(admin[numberb].place,cin[a].place)==0)//�ڳ�����Ϣ��ѭ���õ���ӰԺ���ε���Ʊ�� 
    	{
    		strcpy(lv[s].chang,cin[a].number);// �����ζ�Ӧ�ĳ��κñ����ڽṹ�� 
    		jisuan=(64-cin[a].margin);
			lv[s].rate=jisuan*100/64 ;
			s++;
    	}
	} 	
		//����
	int m;
	struct LV k; 
	for(m=1;m<=s-1;m++)
	{  
		for(n=1;n<=s-1-m;n++)
		{
	    	if(lv[n].rate<lv[n+1].rate)//�����ǰ С���ں� 
	    	{  
				k=lv[n];
				lv[n]=lv[n+1];
				lv[n+1]=k;    		    
	       	}
		}
	}       
			  
  //�ɴ�С���򳡴������� 
  printf("�������ӰԺ�����������������£�\n\n");
  printf("����      ������\n");
  for (;p<s;p++)
		{	
			
			printf("%s      %.1f%c\n",lv[p].chang,lv[p].rate,'%');
		}
		 
  
   	 //��ӡ�ź���Ľṹ�� 
     admfunction(admID);	
}


/************************���򳡴���Ʊ��**********************/

void px_changci(char admID[20])
	
{ 
    read_admin();
	read_cin();
	read_order();
	int a,x,s=1,n=0,shu=0,numberb,p=1;
	for(n=0;n<nameadmin;n++)//�Ա�����Ĺ���ԱID 
	{
		if(strcmp(admID,admin[n].ID)==0)//�õ�����Ա�����ӰԺ���� 
		numberb=n;
	}
	for(a=0;a<namecin;a++)//�ڳ�����Ϣ��ѭ���õ���ӰԺ���ε���Ʊ��
    {
    	if(strcmp(admin[numberb].place,cin[a].place)==0)//�ҵ���Ӧ��Ӱ�ļ۸� 
    	{
    		strcpy(total[s].chang,cin[a].number);// �����ζ�Ӧ�ĳ��κñ����ڽṹ��
			total[s].money= (64-cin[a].margin)*cin[a].ticket;
			s++;
    	}
	} 	
		//����	
	int m;
	struct TOTAL k; 
	for(m=1;m<=s-1;m++)
	{  
		for(n=1;n<=s-1-m;n++)
		{
	    	if(total[n].money<total[n+1].money)//�����ǰ С���ں� 
	    	{  
				k=total[n];
				total[n]=total[n+1];
				total[n+1]=k;    		    
	       	}
		}
	}       
			  
  //�ɴ�С���򳡴���Ʊ��
  printf("�������ӰԺ������Ʊ���������£�\n\n");
  printf("����      ��Ʊ��\n");
  for (;p<s;p++)
		{	
			
			printf("%s      %.2f\n",total[p].chang,total[p].money);
		}
		 
   //��ӡ�ź���Ľṹ�� 
   	 admfunction(admID);
    	
}

/*****************************����Ӱ����Ʊ��*********************/

 void px_yingting(char admID[20])
	
{ 
    read_admin();
	read_cin();
	read_order();
	int a,x,s=1,n=0,shu=0,numberb,p=1;
	for(n=0;n<nameadmin;n++)//�Ա�����Ĺ���ԱID 
	{
		if(strcmp(admID,admin[n].ID)==0)//�õ�����Ա�����ӰԺ���� 
		numberb=n;
	}
	for(a=0;a<namecin;a++)
    {
    	if(strcmp(admin[numberb].place,cin[a].place)==0)//�ڳ�����Ϣ��ѭ���õ���ӰԺ���ε���Ʊ��
    	{
    		yt[s].ting=cin[a].screen;// �����ζ�Ӧ�ĳ��κñ����ڽṹ��
			yt[s].money= (64-cin[a].margin)*cin[a].ticket;//�ҵ���Ӧ��Ӱ�ļ۸�
			s++;
    	}
	} 	
			//����
	int m;
	struct YT k; 
	for(m=1;m<=s-1;m++)
	{  
		for(n=1;n<=s-1-m;n++)
		{
	    	if(yt[n].money<yt[n+1].money)//�����ǰ С���ں� 
	    	{  
				k=yt[n];
				yt[n]=yt[n+1];
				yt[n+1]=k;    		    
	       	}
		}
	}       
		//�ɴ�С����Ӱ����Ʊ��	  
  
  printf("�������Ӱ����Ʊ���������£�\n\n");
  printf("Ӱ��      ��Ʊ��\n");
  for (;p<s;p++)
		{	
			
			printf("%d��      %.2f\n",yt[p].ting,yt[p].money);
		}
		 
   //��ӡ�ź���Ľṹ�� 
   	 admfunction(admID);
    	
}




/******************************************����Ա��ѯӰ����Ϣ******************************/


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
            printf("|Ӱ�����|����ӰԺ |Ӱ������λ|Ӱ������|");
	        printf("\n---------------------------------------");
		    printf("\n%d          %s      %s          %s", hall[a].ID,hall[a].ying,hall[a].seat,hall[a].kind);
		    for(n=0;n<hall[a].hang;n++)
		    {
		       printf("\n");
			   for(m=0;m<hall[a].lie;m++)
			   {
				  printf(" �~");
			   }
			} 
            printf("\n");
		} 
	}
	 admfunction(admID);
} 



/******************************����Ա���β�ѯ****************************************/ 
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
	printf("|���κ�|��Ӱ����|����ӰԺ|��ӳӰ��|��Ӱ��ʼʱ��|��Ӱ����ʱ��|��Ӱʱ��|��Ʊ��|Ʊ��|Ӱ������|��������|�ۿ�|\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for(a=0;a<namecin;a++)
    {
    	if(strcmp(admin[numberb].place,cin[a].place)==0)
    	printf("%s%12s  %s       %d       %s      %s        %s      %d      %.2f    %s   %s    %.2f\n",cin[a].number,cin[a].name,cin[a].place,cin[a].screen,cin[a].start_time,cin[a].end_time,
        cin[a].totaltime,cin[a].margin,cin[a].ticket,cin[a].kind,cin[a].sort,cin[a].discounts);
    }
     admfunction(admID);
	
}


/*********************************�޸Ĺ���Ա����**************************************/



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
	printf("ԭ����:%s\n",admin[numbere].password);
	printf("������������(������6-10λ):");
	scanf("%s",newpass);
	p=test_long2(newpass);
	while(p==2)
	{
	    printf("���벻����Ҫ������������(������6-10λ):");
	    scanf("%s",newpass);
	    p=test_long2(newpass);
	}
	printf("ȷ������:");
	scanf("%s",code);
	m=testCODE2(newpass,code);
	while(m!=0)
	{
	    printf("�������벻һ�£�����������������:");
	    scanf("%s",&newpass);
	    p=test_long2(newpass);
	    while(p==2)
	    {
            printf("���벻����Ҫ������������:");
	        scanf("%s",&newpass);
            p=test_long2(newpass);
	    }
        printf("�ٴ���ȷ������:");
	    scanf("%s",code);
        m=testCODE2(newpass,code);
	}
	
	strcpy(admin[numbere].password,newpass);
	printf("���������Ѹ���Ϊ:%s\n",admin[numbere].password);
	FILE *outfile;
	outfile=fopen("admInformation.txt","w");
	for(n=0;n<nameadmin;n++)
	{
		fprintf(outfile,"%s   %s   %s   %s   %s\n",admin[n].ID,admin[n].place,admin[n].name,admin[n].mail,admin[n].password);
	}
	fclose(outfile);
	 admfunction(admID);	
} 
 
 
 /************************************�޸Ĺ���Ա����********************************/
 
 
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
	printf("ԭ����:%s\n",admin[numberd].mail);
	printf("������������(��ʽ***@***.***):");
	scanf("%s",newmail);
	p=test_email2(newmail);
	while(p!=1)
	{
		
	    printf("���䲻����Ҫ������������(��ʽ***@***.***):");
		scanf("%s",newmail);
		p=test_email2(newmail);
	}
	strcpy(admin[numberd].mail,newmail);
	printf("���������Ѹ���Ϊ:%s\n",admin[numberd].mail);
	FILE *outfile;
	outfile=fopen("admInformation.txt","w");
	for(n=0;n<nameadmin;n++)
	{
		fprintf(outfile,"%s   %s   %s   %s   %s\n",admin[n].ID,admin[n].place,admin[n].name,admin[n].mail,admin[n].password);
	}
	fclose(outfile);
	 admfunction(admID);	
} 



/********************************������Ϣ����***************************************/


int test_long2(char ID[10])//�������볤��
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


int testCODE2(char codeone[],char codetwo[])//����ȷ������������ȷ 
{
	return (strcmp(codeone,codetwo));
}




int test_email2(char email[])//���������ʽ��׼ 
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

/*******************************��ӳ���*****************************************/

void increase_ci(char admID[20])
{
	read_cin();
	read_admin();
	int n,a,cishu=0,test_a=1,numberc,test_b=1,newscreen,b,nume=0,test_c=1,test_d=1,h;
	char newci[20],newname[20],choosea[20],entera[20],enterd[20];
	float newticket;
	namecin=namecin+1;
	//ȷ������Ա����ӰԺ 
	for(n=0;n<nameadmin;n++)
	{
		if(strcmp(admID,admin[n].ID)==0)
		numberc=n;
	}
	
	do{
	printf("����������ӵĳ��κ�"); 
	scanf("%s",newci);
	for(a=0;a<namecin;a++)
	{
			if(strcmp(cin[a].number,newci)==0&&strcmp(cin[a].place,admin[numberc].place)==0)
				cishu++;									
	}
	
	if(cishu!=0)
	{
		printf("\n������ĳ��κ��Ѿ�����,����������");
	}
	else
	{
		test_a=0;
		break;
	}	
	}while(test_a==1);	 
	strcpy(cin[namecin].number,newci);
	/*�����ε�ӰƬ������*/
	do{
	nume=0;
	printf("�����������������εĵ�Ӱ����");
	scanf("%s",newname);
	if(strcmp(newname,"\0")==0)
	printf("����ӰƬ������Ϊ�գ�����������");
	else
	test_b==0;
	break;
	}while(test_b==1);
	strcpy(cin[namecin].name,newname);
	/*�����ε�����ӰԺ*/
	strcpy(cin[namecin].place,admin[numberc].place);
	/*�����ε�Ӱ��*/
	printf("�������������Ӱ����ţ�1-4��\n");
	scanf("%d",&newscreen);
	cin[namecin].screen=newscreen;
	/*�����εĿ�ʼʱ��,����ʱ�䣬ʱ��*/
	do{
	nume=1;
	printf("��ѡ�������εĿ�ʼʱ��:\n");
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
		printf("��������Ч���֣�1��6��");
		nume=0;	 
	}
	for(b=0;b<namecin-1;b++)
	{
		if(newscreen==cin[b].screen&&strcmp(cin[b].place,admin[numberc].place)==0)
		{
			if(strcmp(cin[namecin].start_time,cin[b].start_time)==0||strcmp(cin[namecin].start_time,cin[b].end_time)==0
			||strcmp(cin[namecin].end_time,cin[b].start_time)==0||strcmp(cin[namecin].end_time,cin[b].end_time)==0)
		    {
    			printf("\n�ó��η�ӳʱ��ͳ��κ�Ϊ %s �ĳ������ʱ��̫������Ƭʱ��Ӧ�ÿ��Ǵ���Ӱ���볡��ɢ����ʱ���,������ѡ��",cin[b].number);
    			nume=0;
    		}
		}
	} 
	}while(nume==0); 
	/*����ó���Ʊ��*/ 
	cin[namecin].margin=64;
	printf("������ó���Ʊ��");
	scanf("%f",&newticket);
	cin[namecin].ticket=newticket;
	
	/*����ó�������*/ 
	do{
	printf("��ѡ��ó�������");
	printf("\n1.���� 2.Ӣ��");
	scanf("%s",entera);
	if(strcmp(entera,"1")==0)
	{
		strcpy(cin[namecin].kind,"����");
		test_c=0;
		break; 
	} 
	else if(strcmp(entera,"2")==0)
	{
		strcpy(cin[namecin].kind,"Ӣ��");
		test_c=0;
		break; 
	}
	else
	{
		printf("��������Ч����"); 
	}
	}while(test_c==1);
	
	
	
	/*����ó��ε�Ӱ����*/ 
	
	do{
	printf("��ѡ��ó��ε�Ӱ����");
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
		printf("��������Ч����"); 
	}
	}while(test_d==1);
	/*�����ۿ�*/ 
	cin[namecin].discounts=1.00;
	//�¼�һ�г��� 
	FILE *outfile;
	outfile=fopen("������Ϣ.txt","a");
		fprintf(outfile,"%s %s %s %d %s %s %s %d %.2f %s %s %.2f\n",cin[namecin].number,cin[namecin].name,cin[namecin].place,cin[namecin].screen,cin[namecin].start_time,cin[namecin].end_time,
		cin[namecin].totaltime,cin[namecin].margin,cin[namecin].ticket,cin[namecin].kind,cin[namecin].sort,cin[namecin].discounts);
	fclose(outfile);
	printf("��ӳ��γɹ�����");	
	admfunction(admID);

		 
} 

/*************************************���Ӱ��*****************************************/

void increase_room(char admID[20])
{
	read_hall();
	read_admin();
	int frequency,counta=0,countb=0,countc=0,newID,a,test_num=1,newhang,newlie,testa,f,n,numberc;
	char newseat[20],choose_num[20];
	namehall=namehall+1;
	//ȷ������Ա����ӰԺ 
	for(n=0;n<nameadmin;n++)
	{
		if(strcmp(admID,admin[n].ID)==0)
		numberc=n;
	}
	if((strcmp(admin[numberc].place,hall[0].ying))==0)
	{
		counta++;
		newID=counta+1;
		hall[namehall].ID=newID;//�µ�Ӱ����� 
		strcpy(hall[namehall].ying,hall[0].ying);//�µ�����ӰԺ 
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
	//����µ�Ӱ��������λ�� 
	do{
		printf("����������ǰ���Ӱ��������λ��");
	    scanf("%s",newseat); 
	    a=test_number(newseat);
	    if(a==1)
	    {
    		test_num=0;
	        break;
    	}
	    else
	    printf("����������"); 
	    test_num=1;
	}while(test_num==1);
	  strcpy(hall[namehall].seat,newseat);
	  //ѡ���µ�Ӱ������ 
	  do{
  		printf("��ѡ��ĳ���Ӱ������");
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
		printf("\n��������ȷѡ��"); 
		testa=1;
		}
  	    }while(testa==1);
	  //����Ӱ�����к��� 
	  printf("��ǰ����Ӱ���У�___��");
	  scanf("%d",&newhang);
	  hall[namehall].hang=newhang; 
      printf("��ǰ����Ӱ���У�___��");
	  scanf("%d",&newlie);
	  hall[namehall].lie=newlie;
	  
     FILE *outfile;
	outfile=fopen("Ӱ����Ϣ.txt","a");
		fprintf(outfile,"%d %s %s %s  %d  %d\n",hall[namehall].ID,hall[namehall].ying,hall[namehall].seat,hall[namehall].kind,hall[namehall].hang,hall[namehall].lie);
	fclose(outfile);
	printf("���Ӱ���ɹ�����");	
	 admfunction(admID);
} 

int test_number(char numbera[])//���������Ӱ������λΪ����
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

 //��֤���� 
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

