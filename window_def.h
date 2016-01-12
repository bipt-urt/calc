//Author:qiuguanglei
void loading();
void menu();
void side();
void quantity();

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
