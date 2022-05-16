#include<iostream.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<fstream.h>
#include<stdlib.h>
#include "bg.h"
#include "border.h"

void welcome_screen();
void welcome_screen1();
void menu();
void dwc();
void front();
void operation();
void loading();
char c;
char x=5,z=32;
class structure
{
	public:
	char account_number[15],password[5],dob[12],name[20], gender[10], phone_number[12],email[30],address[30],nationality[15];
	char acno[7],pass[5],aadhar[15],pancard[15];
	int tempotp,otp;
	long int amount,new_amount;
};
class detail
{
	public:
	structure o,i;
	fstream f;
	fstream tmp;
	void new_account()
	{
		clrscr();
		f.open("database.xlsx",ios::out | ios::ate);
		background();
		medium_box();
		gotoxy(25,10);
		textcolor(7);
		cprintf("Enter Name::      ");
		gets(o.name);
		gotoxy(25,12);
		cprintf("Date of Birth::   ");
		cin>>o.dob;
		gotoxy(25,14);
		cprintf("Gender::          ");
		cin>>o.gender;

		clrscr();
		background();
		medium_box();
		textcolor(7);
		gotoxy(25,10);
		cprintf("Nationality::      ");
		cin>>o.nationality;
		gotoxy(25,12);
		cprintf("Address::          ");
		gets(o.address);
		gotoxy(25,14);
		cprintf("Contact Number::   ");
		cin>>o.phone_number;

		clrscr();
		background();
		small_box();
		textcolor(7);
		gotoxy(25,10);
		cprintf("Deposite Amount:: ");
		cin>>o.amount;
		gotoxy(25,12);
		cprintf("Email Id::        ");
		cin>>o.email;

		clrscr();
		loading();
		o.account_number[0]=o.phone_number[2];
		o.account_number[1]=o.phone_number[3];
		o.account_number[2]=o.phone_number[1];
		o.account_number[3]=o.phone_number[7];
		o.account_number[4]=o.phone_number[8];
		o.account_number[5]=o.phone_number[6];
		o.account_number[6]='\0';

		o.password[0]=o.phone_number[0];
		o.password[1]=o.phone_number[4];
		o.password[2]=o.phone_number[5];
		o.password[3]=o.phone_number[9];
		o.password[4]='\0';
		background();
		textcolor(2);
		gotoxy(18,5);
		cprintf("Congratulations ! Your Account is created now...");
		textcolor(7);
		small_box();
		gotoxy(27,10);
		cprintf("Your Account Number:: %s",o.account_number);
		gotoxy(32,12);
		cprintf("Your Password:: %s",o.password);
		gotoxy(78,25);
		f.write((char *) &o,sizeof(o));
		f.close();
		getch();
		front();
	}

	void exist_account()
	{
		clrscr();
		char spw[5];
		char sac[10];
		int t=0;
		background();
		small_box();
		textcolor(7);
		gotoxy(23,10);
		cprintf("Enter Acccount Number:: ");
		cin>>sac;
		gotoxy(28,12);
		cprintf("Enter Password  :: ");
		cin>>spw;
		f.open("database.xlsx",ios::in);
		while(f.read((char *) &i, sizeof(i)))
		{
			if(strcmp(i.account_number,sac)==0 && strcmp(i.password,spw)==0)
			{
				loading();
				operation();
				t++;
			}
		}
		if(t==0)
		{
			clrscr();
			background();
			small_box();
			textcolor(7);
			gotoxy(23,11);
			cprintf("Invalid Account Number and Password!");
			gotoxy(78,25);
			getch();
			front();
		}
		f.close();
	}

	void kyc()
	{
		clrscr();
		char spw[5];
		char sac[10];
		int t=0;
		background();
		small_box();
		textcolor(7);
		gotoxy(23,10);
		cprintf("Enter Acccount Number:: ");
		cin>>sac;
		gotoxy(28,12);
		cprintf("Enter Password  :: ");
		cin>>spw;
		f.open("database.xlsx",ios::in);
		while(f.read((char *) &i, sizeof(i)))
		{
			if(strcmp(i.account_number,sac)==0 && strcmp(i.password,spw)==0)
			{
				loading();
				background();
				small_box();
				textcolor(7);
				gotoxy(23,10);
				cprintf("Enter Aadharcard Number:: ");
				cin>>o.aadhar;
				gotoxy(23,12);
				cprintf("Enter Pancard Number::    ");
				cin>>o.pancard;
				clrscr();
				background();
				small_box();
				textcolor(7);
				o.tempotp=rand()%1000;
				gotoxy(33,10);
				cprintf("Your OTP is:: %d",o.tempotp);
				getch();
				gotoxy(33,12);
				cprintf("Enter OTP:: ");
				cin>>o.otp;
				if(o.tempotp == o.otp)
				{
					loading();
					clrscr();
					background();
					small_box();
					textcolor(7);
					gotoxy(29,11);
					cprintf("KYC Done Successfully...");
					gotoxy(78,25);
					getch();
					front();
				}
				else
				{
					clrscr();
					background();
					small_box();
					textcolor(7);
					gotoxy(23,11);
					cprintf("      You Entered Wrong OTP!");
					gotoxy(78,25);
					getch();
					front();
				}t++;
			}

		}f.close();
		if(t==0)
		{
			clrscr();
			background();
			small_box();
			textcolor(7);
			gotoxy(23,11);
			cprintf("Invalid Account Number and Password!");
			gotoxy(78,25);
			getch();
			front();
		}
	}

	void operation()
	{
		    clrscr();
		    detail s;
		    background();
		    operation_box();
		    gotoxy(32,7);
		    textcolor(4);
		    cprintf("W");
		    textcolor(7);
		    cprintf("ithdrawal Amount");

		    gotoxy(32,9);
		    textcolor(4);
		    cprintf("D");
		    textcolor(7);
		    cprintf("eposit Amount");

		    gotoxy(32,11);
		    textcolor(4);
		    cprintf("C");
		    textcolor(7);
		    cprintf("hange Password");

		    gotoxy(32,13);
		    textcolor(4);
		    cprintf("A");
		    textcolor(7);
		    cprintf("ccount Info");

		    gotoxy(32,15);
		    textcolor(4);
		    cprintf("R");
		    textcolor(7);
		    cprintf("emove Account");

		    gotoxy(32,17);
		    textcolor(4);
		    cprintf("L");
		    textcolor(7);
		    cprintf("ogout Account");
		    gotoxy(78,25);

		    char c;
		    c=getch();
		    if(c=='a'|| c=='A')
		    {
			clrscr();
			account_info();
			getch();
			operation();
		    }
		    else if(c=='r' || c=='R')
		    {
			clrscr();
			delete_account();
			dwc();
		    }

		    else if(c=='c'|| c=='C')
		    {
			clrscr();
			change_password();
		    }
		    else if(c=='d'|| c=='D')
		    {
			clrscr();
			deposite_amount();
		    }
		    else if(c=='w'|| c=='W')
		    {
			clrscr();
			withdraw_amount();
		    }
		    else if(c=='l' || c=='L')
		    {
			clrscr();
			loading();
			front();
		    }
		    else
		    {
			gotoxy(28,21);
			textcolor(4+BLINK);
			cprintf("Please Enter Correct Key!");
			gotoxy(78,25);
			getch();
			operation();
		    }
	}

	void account_info()
	{
		clrscr();
		background();
		operation_box();
		textcolor(7);
		gotoxy(26,7);
		cprintf("Account Number:: %s",i.account_number);
		gotoxy(26,8);
		cprintf("Name::           %s",i.name);
		gotoxy(26,9);
		cprintf("Date of Birth::  %s",i.dob);
		gotoxy(26,10);
		cprintf("Gender::         %s",i.gender);
		gotoxy(26,11);
		cprintf("Nationality::    %s",i.nationality);
		gotoxy(26,12);
		cprintf("Address::        %s",i.address);
		gotoxy(26,13);
		cprintf("Contact Number:: %s",i.phone_number);
		gotoxy(26,14);
		cprintf("Amount::         %d",i.amount);
		gotoxy(26,15);
		cprintf("Email::          %s",i.email);
		gotoxy(26,16);
		cprintf("Password::       %s",i.password);
		gotoxy(78,25);
	}


	void delete_account()
	{
		clrscr();
		background();
		medium_box();
		textcolor(7);
		gotoxy(23,10);
		cprintf("Are You Sure that you want to delete?");
		gotoxy(33,12);
		cprintf("Press Y for Yes");
		gotoxy(33,14);
		cprintf("Press N for No");
		gotoxy(78,25);

		c=getch();
		if(c=='y' || c=='Y')
		{
			f.open("database.xlsx",ios::in);
			tmp.open("tempdatabase.xlsx",ios::out | ios::app);
			while(f.read((char *) &i, sizeof(i)))
			{
			    tmp.write((char *) &i,sizeof(i));
			}
			tmp.close();
			f.close();
			remove("database.xlsx ");
			rename("tempdatabase.xlsx","database.xlsx");
			loading();
			clrscr();
			background();
			small_box();
			textcolor(7);
			gotoxy(25,11);
			cprintf("Account Delete Successfully...");
			gotoxy(78,25);
			getch();
			front();
		}
		else if(c=='n'|| c=='N')
		{
			operation();
		}
		else
		{
			textcolor(7);
			gotoxy(28,19);
			textcolor(4+BLINK);
			cprintf("Please Enter Correct Key!");
			gotoxy(78,25);
			getch();
			delete_account();
		}
	}

	void change_password()
	{
		clrscr();
		background();
		small_box();
		textcolor(7);
		f.open("database.xlsx",ios::in);
		tmp.open("tempdatabase.xlsx",ios::out | ios::app);
		gotoxy(25,10);
		cprintf("Enter old Password:: ");
		cin>>i.pass;
		if(strcmp(i.pass,i.password)==0)
		{
			gotoxy(25,12);
			cprintf("Enter New Password:: ");
			cin>>i.pass;
			strcpy(i.password,i.pass);
			loading();
			clrscr();
			background();
			small_box();
			textcolor(7);
			gotoxy(25,11);
			cprintf("Password Change Successfully...");
			gotoxy(78,25);
		}
		else
		{
			clrscr();
			background();
			small_box();
			textcolor(7);
			gotoxy(27,11);
			cprintf("You Entered Wrong Password!");
			gotoxy(78,25);
			getch();
			operation();
		}
		tmp.write((char *) &i,sizeof(i));
		tmp.close();
		f.close();
		remove("database.xlsx ");
		rename("tempdatabase.xlsx","database.xlsx");
		getch();
		operation();
	}

	void deposite_amount()
	{
		clrscr();
		background();
		small_box();
		textcolor(7);
		i.new_amount=0;
		f.open("database.xlsx",ios::in);
		tmp.open("tempdatabase.xlsx",ios::out | ios::app);
		gotoxy(30,11);
		cprintf("Enter Amount:: ");
		cin>>i.new_amount;
		i.amount+=i.new_amount;
		loading();

		clrscr();
		background();
		small_box();
		textcolor(7);
		gotoxy(25,11);
		cprintf("Amount Deposited Successfully...");
		gotoxy(78,25);
		tmp.write((char *) &i,sizeof(i));
		tmp.close();
		f.close();
		remove("database.xlsx ");
		rename("tempdatabase.xlsx","database.xlsx");
		getch();
		operation();
	}

	void withdraw_amount()
	{
		clrscr();
		background();
		small_box();
		textcolor(7);
		i.new_amount=0;
		f.open("database.xlsx",ios::in);
		tmp.open("tempdatabase.xlsx",ios::out | ios::app);
		gotoxy(30,11);
		cprintf("Enter Amount:: ");
		cin>>i.new_amount;
		i.amount-=i.new_amount;
		loading();

		clrscr();
		background();
		small_box();
		textcolor(7);
		gotoxy(30,11);
		cprintf("Collect Your Cash...");
		gotoxy(78,25);
		tmp.write((char *) &i,sizeof(i));
		tmp.close();
		f.close();
		remove("database.xlsx ");
		rename("tempdatabase.xlsx","database.xlsx");
		getch();
		operation();
	}

	void dwc()
	{
		char c;
		textcolor(7);
		cprintf("\n\nDo you want to continue...\nPress Y for Yes\nPress N for No");
		c=getch();
		if(c=='y')
		{
			operation();
		}
		else if(c=='n' || c=='N')
		{
			front();
		}
		else
		{
			textcolor(7);
			cprintf("\n\nPlease Enter Right Key!");
			getch();
			dwc();
		}
	}

	void close()
	{
		clrscr();
		background();
		small_box();
		char c[]={"Thank You Visit Again..."};
		gotoxy(29,10);
		for(char i=0;i<=strlen(c);i++)
		{
			delay(100);
			cout<<c[i];
		}
		char s[]={"Created By::- Yash Gaur & Nikhil Yadav"};
		gotoxy(22,12);
		for(i=0;i<=strlen(s);i++)
		{
			delay(100);
			cout<<s[i];
		}
		gotoxy(29,17);
		textcolor(2+BLINK);
		cprintf("Press  Enter  To  Exit");
		gotoxy(78,25);
		getch();
	}
};
void main()
{
	int gd= DETECT,gm;
	clrscr();
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	welcome_screen();
	getch();
	closegraph();
	front();
	getch();
}



//----------------------------------FUNCTIONS------------------------------------//
//-------------------------------------------------------------------------------//


void front()
{
	clrscr();
	detail s;
	background();
	medium_box();
	gotoxy(34,10);
	textcolor(4);
	cprintf("E");
	textcolor(7);
	cprintf("xist Account");

	gotoxy(34,14);
	textcolor(4);
	cprintf("A");
	textcolor(7);
	cprintf("ccount  KYC");
	gotoxy(34,12);
	textcolor(4);
	cprintf("N");
	textcolor(7);
	cprintf("ew  Account");
	gotoxy(78,25);

	char c;
	c=getch();
	if(c=='e' || c=='E')
	{
		clrscr();
		s.exist_account();
	}
	else if(c=='n'|| c=='N')
	{
		clrscr();
		s.new_account();
	}
	else if(c=='a'|| c=='A')
	{
		clrscr();
		s.kyc();
	}
	else if(c==27)
	{
		s.close();
		exit(0);
	}
	else
	{
		gotoxy(28,19);
		textcolor(4+BLINK);
		cprintf("Please Enter Correct Key!");
		gotoxy(78,25);
		getch();
		front();
	}
	getch();
}

void loading()
{
	int gd= DETECT,gm;
	clrscr();
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	outtextxy(220,190,"Processing...");
	rectangle(400,220,220,210);
	for(int i=0;i<=180;i++)
	{
		setcolor(3);
		rectangle(400,220,220+i,210);
		delay(20);
	}
	closegraph();
}


void welcome_screen()
{

//------MOVING_SYMBOLS_START-----//

	setcolor(2);
	for(int i=2;i<=595;i=i+10)
	{
		delay(20);
		outtextxy(10+i,30,"");
	}
	for(i=2;i<=380;i=i+10)
	{
		delay(20);
		outtextxy(585,38+i,"");
	}
	for(i=2;i<=640;i=i+10)
	{
		delay(20);
		outtextxy(610-i,420,"");
	}
	for(i=2;i<=380;i=i+10)
	{
		delay(20);
		outtextxy(30,412-i,"");
	}
	setcolor(4);
	settextstyle(7,0,7);
	outtextxy(170,50,"WELCOME");
	setcolor(4);
	settextstyle(7,0,7);
	delay(300);
	outtextxy(270,125,"TO");
	setcolor(4);
	settextstyle(7,0,7);
	delay(600);
	outtextxy(243,210,"SBI");
	setcolor(4);
	settextstyle(7,0,7);
	delay(900);
	outtextxy(210,290,"BANK");
	settextstyle(8,0,1);
	sleep(2);
	outtextxy(100,380,"Created By ::- YASH GAUR & NIKHIL YADAV");
	getch();
}