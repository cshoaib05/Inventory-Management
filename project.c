#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <conio.h>

struct Products
{
	char name[30];
	char size[5];
	char age[10];
	int rate;
	int quantity;
	struct Products *next,*prev;
};


struct Products *insert(struct Products *h)
{
	struct Products *p,*temp;
	FILE *fp;
	p=(struct Products *)malloc(sizeof(struct Products));
	if(p==NULL)
	{
		printf("\nNOT ENOUGH MEMORY\n");
		return h;
	}
	printf("\nENTER THE DETAILS::\n");
	printf("\nENTER THE NAME OF ITEM:\t");
	scanf("%s",p->name);
	printf("\nENTER THE SIZE:\t");
	scanf("%s",p->size);
	printf("\nENTER THE AGE:\t");
	scanf("%s",&p->age);
	printf("\nENTER THE PRICE: ");
	scanf("%d",&p->rate);
	printf("\nENTER THE QUANTITY:\t");
	scanf("%d",&p->quantity);
	p->next=p->prev=NULL;
	if(h==NULL)
	{
		h=p;
	}
	else
	{
		temp=h;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		if(temp->next==NULL)
		{
			temp->next=p;
			p->prev=temp;
		}
	}
	printf("\n\tPRODUCT SUCCESSFULLY ADDED TO INVENTORY\n");
	fp=fopen("STOCK DETAILS.txt","a");
	fprintf(fp,"\nNAME OF PRODUCT:%s\nSIZE:%s\nAGE:%s\nPRICE:%d\nQUANTITY:%d\n",p->name,p->size,p->age,p->rate,p->quantity);
	fclose(fp);
	getch();
	system("cls");
return h;
}



struct Products *increase(struct Products *h)
{
	FILE *fp;
	char a[30];
	char b[5];
	int q,amount,c,d;
	struct Products *temp;
	if(displayAll(h)==0)
	{
		return h;
	}
	printf("\nENTER PRODUCT NAME:\t");
	scanf("%s",a);
	printf("\nENTER THE SIZE:\t");
	scanf("%s",b);
	temp=h;
	while(temp!=NULL)
	{
		c=strcmp(a,temp->name);
		d=strcmp(b,temp->size);
		if(c==0 && d==0)
		{
			printf("\nENTER NUMBER OF QUANTITY TO INCREASE:\t");
			scanf("%d",&q);
			printf("\nAMOUNT BOUGHT EACH:\t");
			scanf("%d",&amount);
			temp->rate=amount;
			temp->quantity=temp->quantity+q;
			break;
		}
		temp=temp->next;
	}

	if(c!=0||d!=0)
	{
		printf("\n\t::ITEM NOT FOUND::\n");
	}
	else
	{
		fp=fopen("STOCK DETAILS.txt","a");
		fprintf(fp,"\nNAME OF PRODUCT:%s\nSIZE:%s\nAGE:%s\nPRICE:%d\nQUANTITY:%d\n",temp->name,temp->size,temp->age,temp->rate,temp->quantity);
		fclose(fp);
	}
	getch();
	return h;
}



struct Products *sell(struct Products *h)
{
	FILE *fp;
	char a[30];
	char b[5];
	int q,d,e,sold,amount,profit,c;
	struct Products *temp;
	if(displayAll(h)==0)
	{
		return h;
	}
	printf("\nENTER PRODUCT NAME SOLD:\t");
	scanf("%s",a);
	printf("\nENTER THE SIZE OF PRODUCT:\t");
	scanf("%s",b);
	temp=h;
	while(temp!=NULL)
	{	
		c=strcmp(a,temp->name);
		d=strcmp(b,temp->size);
		if(c==0 && d==0)
		{
			printf("\nENTER NUMBER OF QUANTITY SOLD:\t");
			scanf("%d",&q);
			if(temp->quantity-q<0)
			{
				printf("\nNOT ENOUGH STOCK LEFT:\t");
			}
			else
			{	
				printf("\nAMOUNT SOLD EACH:\t");
				scanf("%d",&amount);
				profit=(amount-temp->rate)*q;
				temp->quantity=temp->quantity-q;
			}
			break;
		}
		temp=temp->next;
	}
	if(c!=0 || d!=0)
	{
		printf("\nITEM NOT FOUND\n");
	}
	else
	{
		fp=fopen("SOLD.txt","a");
		fprintf(fp,"\nNAME OF PRODUCT:%s\nSIZE:%s\nAGE:%s\nPRICE:%d\nQUANTITY:%d\nPROFIT:%d\n",temp->name,temp->size,temp->age,amount,temp->quantity,profit);
		fclose(fp);
	}
	getch();
	return h;
}



int displayAll(struct Products *h)
{
	FILE *fp;
	struct Products *temp;
	char ch;	
	{
	fp=fopen("STOCK DETAILS.txt","r");
	ch = fgetc(fp);
	if(ch==EOF)
	{
		printf("\nNO PRODUCTS AVAILABLE\n");
		getch();
		system("cls");
		return 0;
	}
	printf("\n\nPRODUCTS AVAILABLE\n");
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fp);
	}
	fclose(fp);
	}
	getch();
return 1;
}


void displayQnty(struct Products *h)
{
	struct Products *temp;
	temp=h;
	if(temp==NULL)
	{
		printf("\nEMPTY STOCK\n");
		return h;
	}
	else		
	{
		while(temp!=NULL)
		{
			printf("\nNAME::%s\nQUANTITY::%d\n",temp->name,temp->quantity);
			temp=temp->next;
		}	
	}
	getch();
}

void sold(struct Products *h)
{
	FILE *fp;
	struct Products *temp;
	char ch;	
	{
	fp=fopen("SOLD.txt","r");
	ch = fgetc(fp);
	if(ch==EOF)
	{
		printf("\nNO TRANSACTIONS AVAILABLE\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n\nPRODUCTS SOLD\n");
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fp);
	}
	fclose(fp);
	}
	getch();
return;
}



void displaySize(struct Products *h)
{
	struct Products *temp;
	temp=h;
	if(temp==NULL)
	{
		printf("\nEMPTY STOCK\n");
		return h;
	}
	else		
	{
		while(temp!=NULL)
		{
			printf("\nNAME::%s\nSIZE::%s\n",temp->name,temp->size);
			temp=temp->next;
		}	
	}
	getch();
}


void displayRate(struct Products *h)
{
	struct Products *temp;
	temp=h;
	if(temp==NULL)
	{
		printf("\nEMPTY STOCK\n");
		return h;
	}
	else		
	{
		while(temp!=NULL)
		{
			printf("\nNAME::%s\nPRICE::%d\n",temp->name,temp->rate);
			temp=temp->next;
		}	
	}
	getch();
}


void displayAge(struct Products *h)
{
	struct Products *temp;
	temp=h;
	if(temp==NULL)
	{
		printf("\nEMPTY STOCK\n");
		return h;
	}
	else		
	{
		while(temp!=NULL)
		{
			printf("\nNAME::%s\nAGE::%s\n",temp->name,temp->age);
			temp=temp->next;
		}	
	}
	getch();
}

void clearAll(struct Products *s)
{
	FILE *fp;
	system("cls");
	fp=fopen("STOCK DETAILS.txt","w");
	fclose(fp);
	printf("\nTRANSACTION CLEARED\n");
	getch();
}

void clearSold(struct Products *s)
{
	FILE *fp;
	system("cls");
	fp=fopen("SOLD.txt","w");
	fclose(fp);
	printf("\nTRANSACTION CLEARED\n");
	getch();
}


void main()
{
	struct Products *s;
	int a,i;
	s=NULL;
	while(1)
	{
	printf("\t\t\t\t:::::MENU:::::");
	printf("\n1.ADD NEW PRODUCT\n2.INCREASE STOCK PRODUCT\n3.SELL PRODUCT\n4.DISPLAY RECENTS TRANSACTION\n5.DISPLAY ALL TRANSACTION\n6.DISPLAY SOLD TRANSACTIONS\n7.CLEAR SOLD TRANSACTIONS\n8.CLEAR ALL TRANSACTIONS\n9.EXIT");
	printf("\n\n\t\t\tENTER YOUR CHOICE::  ");
	scanf("%d",&a);
	switch(a)
	{
		case 1:			system("cls");
						s=insert(s);
						
						break;
		case 2:			system("cls");
						s=increase(s);
						
						break;
		case 3:			system("cls");
						s=sell(s);
						
						break;
		case 4:			system("cls");
						printf("\n1.DISPLAY STOCK QUANTITY\n2.DISPLAY RATES\n3.DISPLAY AS AGES\n4.DISPLAY AS SIZES\n");
						scanf("%d",&i);
						{
							if (i==1)
							{	
								system("cls");
								displayQnty(s);
							}
							else
							{
								if (i==2)
								{
									system("cls");
									displayRate(s);
								}
								else
								{
									if (i==3)
									{	
										system("cls");
										displayAge(s);
									}
									else
									{
										if (i==4)
										{	
											system("cls");
											displaySize(s);
										}
											else
											{
												printf("\nINVALID OPTION\n");
											}
										}
									}
								}
							}
							
						break;
		case 5:
				system("cls");
				displayAll(s);
				
				break;
		case 6:
				system("cls");
				sold(s);
				break;
		case 7:
				system("cls");
				clearSold(s);
				break;
		case 8:
				clearAll(s);
				break;
		case 9:
					return;
	}

	}

}