//Author:qiuguanglei,@DGideas
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void loading();
void menu();
void side();
void quantity();
void exam();
void addtion();
void subtraction();
void multiplication();
void division();
void mix();
void judge();
void spf(int); //sprintf判断

IMAGE welcome;
IMAGE confine;
IMAGE amount;
IMAGE board;
IMAGE right;
IMAGE error;

int choice,limit,n,i,a,b,c,key,correct=0;
char s[10];

void main()
{
    initgraph(820, 512);
    HWND hwnd=GetHWnd();
    SetWindowText(hwnd, "小学算术测试");
    loading();
    while(1)
    {
        menu();
        if(choice==5250)
            closegraph();
        side();
        quantity();
        exam();
        judge();
    }
    closegraph();
    return;
}

void loading()
{
    settextstyle(30,0,_T("华文楷体"));
    loadimage(&welcome,"images/welcome.jpg");
    loadimage(&confine,"images/confine.jpg");
    loadimage(&amount,"images/amount.jpg");
    loadimage(&board,"images/board.jpg");
    loadimage(&right,"images/right.jpg");
    loadimage(&error,"images/error.jpg");
}

void menu()
{
    putimage(0,0,&welcome);
    MOUSEMSG m;
	while(true)
	{
		m=GetMouseMsg();
		if(m.x>240&&m.x<460&&m.y>180&&m.y<230&&m.uMsg==WM_LBUTTONDOWN)
		{
			choice=1;
			break;
		}
		else if(m.x>240&&m.x<460&&m.y>250&&m.y<300&&m.uMsg==WM_LBUTTONDOWN)
		{
			choice=2;
			break;
		}
		else if(m.x>240&&m.x<460&&m.y>320&&m.y<370&&m.uMsg==WM_LBUTTONDOWN)
		{
			choice=3;
			break;
		}
		else if(m.x>240&&m.x<460&&m.y>390&&m.y<440&&m.uMsg==WM_LBUTTONDOWN)
		{
			choice=4;
			break;
		}
		else if(m.x>580&&m.x<740&&m.y>290&&m.y<330&&m.uMsg==WM_LBUTTONDOWN)
		{
			choice=5;
			break;
		}
		else if(m.x>0&&m.x<130&&m.y>440&&m.y<510&&m.uMsg==WM_LBUTTONDOWN)
		{
			choice=5250;
			break;
		}
	}
}

void side()
{
	putimage(0,0,&confine);
	MOUSEMSG m;
	while(true)
	{
		m=GetMouseMsg();
		if(m.x>220&&m.x<490&&m.y>150&&m.y<210&&m.uMsg==WM_LBUTTONDOWN)
		{
			limit=10;
			break;
		}
		else if(m.x>220&&m.x<490&&m.y>240&&m.y<300&&m.uMsg==WM_LBUTTONDOWN)
		{
			limit=20;
			break;
		}
		else if(m.x>220&&m.x<490&&m.y>330&&m.y<390&&m.uMsg==WM_LBUTTONDOWN)
		{
			limit=50;
			break;
		}
		else if(m.x>220&&m.x<490&&m.y>420&&m.y<480&&m.uMsg==WM_LBUTTONDOWN)
		{
			limit=100;
			break;
		}
	}
}

void quantity()
{
	putimage(0,0,&amount);
	MOUSEMSG m;
	while(true)
	{
		m=GetMouseMsg();
		if(m.x>220&&m.x<490&&m.y>150&&m.y<210&&m.uMsg==WM_LBUTTONDOWN)
		{
			n=10;
			break;
		}
		else if(m.x>220&&m.x<490&&m.y>240&&m.y<300&&m.uMsg==WM_LBUTTONDOWN)
		{
			n=20;
			break;
		}
		else if(m.x>220&&m.x<490&&m.y>330&&m.y<390&&m.uMsg==WM_LBUTTONDOWN)
		{
			n=50;
			break;
		}
		else if(m.x>220&&m.x<490&&m.y>420&&m.y<480&&m.uMsg==WM_LBUTTONDOWN)
		{
			n=100;
			break;
		}
	}
}

void exam()
{
	switch(choice)
	{
		case 1:
			addtion();
			break;
		case 2:
			subtraction();
			break;
		case 3:
			multiplication();
			break;
		case 4:
			division();
			break;
		case 5:
			mix();
			break;
	}
}

void addtion()
{
	correct=0;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		putimage(0,0,&board);
		a=rand()%limit+1;
		b=rand()%limit+1;
		key=a+b;
		sprintf(s,"%d＋%d＝？",a,b);
		outtextxy(200,120,s);
		InputBox(s,10,"告诉本王你的答案");
		c=0;
		sscanf(s,"%d",&c);
		if(c==key)
		{
			correct++;
			putimage(0,0,&right);
			sprintf(s,"%d＋%d＝%d",a,b,key);
			outtextxy(200,120,s);
			sprintf(s,"你给出的答案为：%d",c);
			outtextxy(200,170,s);
			sprintf(s,"答对啦~");
			outtextxy(200,270,s);
			sprintf(s,"（任意键继续）");
			outtextxy(200,320,s);
		}
		else
		{
			putimage(0,0,&error);
			sprintf(s,"%d＋%d＝%d",a,b,key);
			outtextxy(200,120,s);
			sprintf(s,"你给出的答案为：%d",c);
			outtextxy(200,170,s);
			sprintf(s,"不对哦~");
			outtextxy(200,270,s);
			sprintf(s,"（任意键继续）");
			outtextxy(200,320,s);
		}
		getch();
	}
}

void subtraction()
{
	correct=0;
	int max,min;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		putimage(0,0,&board);
		a=rand()%limit+1;
		b=rand()%limit+1;
		(a<b)?(max=b,min=a):(max=a,min=b);
		key=max-min;
		sprintf(s,"%d－%d＝？",max,min);
		outtextxy(200,120,s);
		InputBox(s,10,"告诉本王你的答案");
		c=0;
		sscanf(s,"%d",&c);
		if(c==key)
		{
			correct++;
			putimage(0,0,&right);
			sprintf(s,"%d－%d＝%d",max,min,key);
			outtextxy(200,120,s);
			sprintf(s,"你给出的答案为：%d",c);
			outtextxy(200,170,s);
			sprintf(s,"答对啦~");
			outtextxy(200,270,s);
			sprintf(s,"（任意键继续）");
			outtextxy(200,320,s);
		}
		else
		{
			putimage(0,0,&error);
			sprintf(s,"%d－%d＝%d",max,min,key);
			outtextxy(200,120,s);
			sprintf(s,"你给出的答案为：%d",c);
			outtextxy(200,170,s);
			sprintf(s,"不对哦~");
			outtextxy(200,270,s);
			sprintf(s,"（任意键继续）");
			outtextxy(200,320,s);
		}
		getch();
	}
}

void multiplication()
{
	correct=0;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		putimage(0,0,&board);
		a=rand()%limit+1;
		b=rand()%limit+1;
		key=a*b;
		sprintf(s,"%d×%d＝？",a,b);
		outtextxy(200,120,s);
		InputBox(s,10,"告诉本王你的答案");
		c=0;
		sscanf(s,"%d",&c);
		if(c==key)
		{
			correct++;
			putimage(0,0,&right);
			sprintf(s,"%d×%d＝%d",a,b,key);
			outtextxy(200,120,s);
			sprintf(s,"你给出的答案为：%d",c);
			outtextxy(200,170,s);
			sprintf(s,"答对啦~");
			outtextxy(200,270,s);
			sprintf(s,"（任意键继续）");
			outtextxy(200,320,s);
		}
		else
		{
			putimage(0,0,&error);
			sprintf(s,"%d×%d＝%d",a,b,key);
			outtextxy(200,120,s);
			sprintf(s,"你给出的答案为：%d",c);
			outtextxy(200,170,s);
			sprintf(s,"不对哦~");
			outtextxy(200,270,s);
			sprintf(s,"（任意键继续）");
			outtextxy(200,320,s);
		}
		getch();
	}
}

void division()
{
	correct=0;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		putimage(0,0,&board);
		a=rand()%limit+1;
		b=rand()%limit+1;
		key=b;
		b=a;
		a=b*key;
		sprintf(s,"%d÷%d＝？",a,b);
		outtextxy(200,120,s);
		InputBox(s,10,"告诉本王你的答案");
		c=0;
		sscanf(s,"%d",&c);
		if(c==key)
		{
			correct++;
			putimage(0,0,&right);
			sprintf(s,"%d÷%d＝%d",a,b,key);
			outtextxy(200,120,s);
			sprintf(s,"你给出的答案为：%d",c);
			outtextxy(200,170,s);
			sprintf(s,"答对啦~");
			outtextxy(200,270,s);
			sprintf(s,"（任意键继续）");
			outtextxy(200,320,s);
		}
		else
		{
			putimage(0,0,&error);
			sprintf(s,"%d÷%d＝%d",a,b,key);
			outtextxy(200,120,s);
			sprintf(s,"你给出的答案为：%d",c);
			outtextxy(200,170,s);
			sprintf(s,"不对哦~");
			outtextxy(200,270,s);
			sprintf(s,"（任意键继续）");
			outtextxy(200,320,s);
		}
		getch();
	}
}

void mix()
{
	correct=0;
	int d,e,f,flag,t,key;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		putimage(0,0,&board);
		a=rand()%limit+1;
		b=rand()%limit+1;
		c=rand()%limit+1;
		d=rand()%limit+1;
		e=rand()%limit+1;
		(a%2==0)?flag=0:flag=2;
		if(flag==0)
			(a+b*c>e)?flag=0:flag=1;
		if(flag==0)
		{
			key=a+b*c-e;
			sprintf(s,"%d＋%d×%d－%d÷%d＝？",a,b,c,d*e,d);
			outtextxy(200,120,s);
			InputBox(s,10,"告诉本王你的答案");
			f=0;
			sscanf(s,"%d",&f);
			(f==key)?t=1:t=0;
		}
		if(flag==1)
		{
			key=e-(a+b*c);
			sprintf(s,"%d÷%d－(%d＋%d×%d)＝？",d*e,d,a,b,c);
			outtextxy(200,120,s);
			InputBox(s,10,"告诉本王你的答案");
			f=0;
			sscanf(s,"%d",&f);
			(f==key)?t=1:t=0;
		}
		if(flag==2)
			(b>c*d)?flag=2:flag=3;
		if(flag==2)
		{
			b=b-(b-c*d)%e;
			key=a+(b-c*d)/e;
			sprintf(s,"%d＋(%d－%d×%d)÷%d＝？",a,b,c,d,e);
			outtextxy(200,120,s);
			InputBox(s,10,"告诉本王你的答案");
			f=0;
			sscanf(s,"%d",&f);
			(f==key)?t=1:t=0;
		}
		if(flag==3)
		{
			b=b+(c*d-b)%e;
			key=a+(c*d-b)/e;
			sprintf(s,"%d＋(%d×%d－%d)÷%d＝？",a,c,d,b,e);
			outtextxy(200,120,s);
			InputBox(s,10,"告诉本王你的答案");
			f=0;
			sscanf(s,"%d",&f);
			(f==key)?t=1:t=0;
		}
		if(t==1)
		{
			correct++;
			putimage(0,0,&right);
			if(flag==0)
				sprintf(s,"%d＋%d×%d－%d÷%d＝%d",a,b,c,d*e,d,key);
			if(flag==1)
				sprintf(s,"%d÷%d－(%d＋%d×%d)＝%d",d*e,d,a,b,c,key);
			if(flag==2)
				sprintf(s,"%d＋(%d－%d×%d)÷%d＝%d",a,b,c,d,e,key);
			if(flag==3)
				sprintf(s,"%d＋(%d×%d－%d)÷%d＝%d",a,c,d,b,e,key);
			outtextxy(200,120,s);
			sprintf(s,"你给出的答案为：%d",f);
			outtextxy(200,170,s);
			sprintf(s,"答对啦~");
			outtextxy(200,270,s);
			sprintf(s,"（任意键继续）");
			outtextxy(200,320,s);
		}
		else
		{
			putimage(0,0,&error);
			if(flag==0)
				sprintf(s,"%d＋%d×%d－%d÷%d＝%d",a,b,c,d*e,d,key);
			if(flag==1)
				sprintf(s,"%d÷%d－(%d＋%d×%d)＝%d",d*e,d,a,b,c,key);
			if(flag==2)
				sprintf(s,"%d＋(%d－%d×%d)÷%d＝%d",a,b,c,d,e,key);
			if(flag==3)
				sprintf(s,"%d＋(%d×%d－%d)÷%d＝%d",a,c,d,b,e,key);
			outtextxy(200,120,s);
			sprintf(s,"你给出的答案为：%d",f);
			outtextxy(200,170,s);
			sprintf(s,"不对哦~");
			outtextxy(200,270,s);
			sprintf(s,"（任意键继续）");
			outtextxy(200,320,s);
		}
	getch();
	}
}

void judge()
{
	int z;
	putimage(0,0,&board);
	sprintf(s,"做对%d道题，一共%d道题",correct,n);
	outtextxy(200,120,s);
	z=correct*100/n;
	sprintf(s,"得分：%d ",z);
	outtextxy(200,170,s);
	if(z==100)
	{
		sprintf(s,"优秀！");
		outtextxy(200,270,s);
		sprintf(s,"你真是太厉害了！");
		outtextxy(200,320,s);
	}
	if(z>89&&z<100)
	{
		sprintf(s,"优！");
		outtextxy(200,270,s);
		sprintf(s,"还差一点就完美了哦~");
		outtextxy(200,320,s);
	}
	if(z>79&&z<90)
	{
		sprintf(s,"良");
		outtextxy(200,270,s);
		sprintf(s,"还不错，再加把劲~");
		outtextxy(200,320,s);
	}
	if(z>59&&z<80)
	{
		sprintf(s,"达标");
		outtextxy(200,270,s);
		sprintf(s,"你应该能做得更好，对么");
		outtextxy(200,320,s);
	}
	if(z<60)
	{
		sprintf(s,"待达标");
		outtextxy(200,270,s);
		sprintf(s,"我想你老爸该打你屁屁了");
		outtextxy(200,320,s);
	}
	getch();
}
