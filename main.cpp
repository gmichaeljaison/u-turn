#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>

void pl_1_lost(int x1,int y1);
void pl_2_lost(int x2,int y2);
int function1(int &in1,int &speed,char &d1,int &x1,int &y1);
int function2(int &in2,int &speed,char &d2,int &x2,int &y2);
int extreme_check(int x,int y);

void main_menu();

void main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"w:\\compiler\\tcpp\\bgi");
	main_menu();
	closegraph();
}

void main_menu()
{
	int speed,x1=1,y1=240,x2=638,y2=240,in1,in2;
	int ch;
	char d1='r',d2='l',s[1];
	cleardevice();
	setbkcolor(0);
	do{
		cleardevice();
		settextstyle(4,0,4);
		setcolor(12);
		outtextxy(20,20,"1.slow");
		outtextxy(20,60,"2.medium");
		outtextxy(20,100,"3.fast");
		outtextxy(20,180,"4.exit");
		outtextxy(20,140,"CHOOSE SPEED: ");
		ch=getch();
	}while(ch<49 || ch>52);
	ch-=48;
	sprintf(s,"%d",ch);
	if(ch!=4)
	{
		outtextxy(300,140,s);
		getch();
		if(ch==1)
			speed=8;
		if(ch==2)
			speed=5;
		if(ch==3)
			speed=2;
	}
	if(ch==4)
	{
		closegraph();
		exit(0);
	}
	cleardevice();
	setcolor(9);
	line(0,0,639,0);
	line(0,479,639,479);
	line(0,0,0,479);
	line(639,0,639,479);
	do{
		getch();
		in1=getch();
	  }while(in1!=13);
	if(in1==13)
	while(1)
	{
		in2=function1(in1,speed,d1,x1,y1);
		in1=function2(in2,speed,d2,x2,y2);
	}
}

void pl_1_lost(int x1,int y1)
{
	int c;
	if(getpixel(x1,y1)==14||extreme_check(x1,y1)==1||getpixel(x1,y1)==13)
	{
		while(c=getch()!=13);
		cleardevice();
		settextstyle(4,0,4);
		setcolor(13);
		outtextxy(20,20,"WON");
		setcolor(14);
		outtextxy(20,120,"LOST");
		c=getch();
		while(c!=13)
			c=getch();
		if(c==13)
		{
			main_menu();
		}
	}
}

void pl_2_lost(int x2,int y2)
{
	int c;
	if(getpixel(x2,y2)==13||extreme_check(x2,y2)==1||getpixel(x2,y2)==14)
	{
		while(c=getch() !=13);
		cleardevice();
		settextstyle(4,0,4);
		setcolor(14);
		outtextxy(20,20,"WON");
		setcolor(13);
		outtextxy(20,120,"LOST");
		c=getch();
		while(c!=13)
			c=getch();
		if(c==13)
		{
			main_menu();
		}
	}
}

int extreme_check(int x,int y)
{
	if(getpixel(x,y)==9)
		return 1;
	else
		return 0;
}

int function1(int &in1,int &speed,char &d1,int &x1,int &y1)
{
	static int snd=256;
	if(in1!=0)
	{
		if(in1==115 && d1!='u') d1='d';
		if(in1==119 && d1!='d') d1='u';
		if(in1==97 && d1!='r') d1='l';
		if(in1==100 && d1!='l') d1='r';
	}
	switch(d1)
	{
		case 'r' :putpixel(x1++,y1,14);
			  if(kbhit())
			  {
				if(in1==0)
					in1=getch();
				if(in1==119)
					d1='u';
				if(in1==115)
					d1='d';
				if(in1<=80)
				{
					pl_1_lost(x1,y1);
					return in1;
				}
			  }
			  pl_1_lost(x1,y1);
			  break;
		case 'l' :putpixel(x1--,y1,14);
			  if(kbhit())
			  {
				if(in1==0)
					in1=getch();
				if(in1==119)
					d1='u';
				if(in1==115)
					d1='d';
				if(in1<=80)
				{
					pl_1_lost(x1,y1);
					return in1;
				}
			  }
			  pl_1_lost(x1,y1);
			  break;
		case 'u' :putpixel(x1,y1--,14);
			  if(kbhit())
			  {
				if(in1==0)
					in1=getch();
				if(in1==97)
					d1='l';
				if(in1==100)
					d1='r';
				if(in1<=80)
				{
					pl_1_lost(x1,y1);
					return in1;
				}
			  }
			  pl_1_lost(x1,y1);
			  break;
		case 'd' :putpixel(x1,y1++,14);
			  if(kbhit())
			  {
				if(in1==0)
					in1=getch();
				if(in1==97)
					d1='l';
				if(in1==100)
					d1='r';
				if(in1<=80)
				{
					pl_1_lost(x1,y1);
					return in1;
				}
			  }
			  pl_1_lost(x1,y1);
	}
	if(snd==412)
		snd=256;
	//sound(snd++);
	delay(speed);
	nosound();
	return 0;
}

int function2(int &in2,int &speed,char &d2,int &x2,int &y2)
{
	int d;
	static int snd=256;
	if(in2!=0)
	{
		if(in2==80 && d2!='u') d2='d';
		if(in2==72 && d2!='d') d2='u';
		if(in2==75 && d2!='r') d2='l';
		if(in2==77 && d2!='l') d2='r';
	}
	switch(d2)
	{
		case 'r' :putpixel(x2++,y2,13);
			  if(kbhit())
			  {
				if(in2==0)
					in2=getch();
				if(in2==72)
					d2='u';
				if(in2==80)
					d2='d';
				if(in2>80)
				{
					pl_2_lost(x2,y2);
					return in2;
				}
			  }
			  pl_2_lost(x2,y2);
			  break;
		case 'l' :putpixel(x2--,y2,13);
			  if(kbhit())
			  {
				if(in2==0)
					in2=getch();
				if(in2==72)
					d2='u';
				if(in2==80)
					d2='d';
				if(in2>80)
				{
					pl_2_lost(x2,y2);
					return in2;
				}
			  }
			  pl_2_lost(x2,y2);
			  break;
		case 'u' :putpixel(x2,y2--,13);
			  if(kbhit())
			  {
				if(in2==0)
					in2=getch();
				if(in2==75)
					d2='l';
				if(in2==77)
					d2='r';
				if(in2>80)
				{
					pl_2_lost(x2,y2);
					return in2;
				}
			  }
			  pl_2_lost(x2,y2);
			  break;
		case 'd' :putpixel(x2,y2++,13);
			  if(kbhit())
			  {
				if(in2==0)
					in2=getch();
				if(in2==75)
					d2='l';
				if(in2==77)
					d2='r';
				if(in2>80)
				{
					pl_2_lost(x2,y2);
					return in2;
				}
			  }
			  pl_2_lost(x2,y2);
	}
	if(snd==412)
		snd=256;
	//sound(snd++);
	delay(speed);
	nosound
	();
	return 0;
}
