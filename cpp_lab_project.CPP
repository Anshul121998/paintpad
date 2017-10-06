#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<graphics.h>
union REGS in,out;
void ultimatecheck(int x,int y,int checksp);
void layout();
void pallete();
void palletespecial();
int checkspecial(int x,int y,int cl,int old);
void clean();
int check(int x,int y,int cl,int old);
void callmouse()
{
 in.x.ax=1;
 int86(51,&in,&out);
}
void mouseposi(int &xpos,int &ypos,int &click)
{
 in.x.ax=3;
 int86(51,&in,&out);
 click=out.x.bx;
 xpos=out.x.cx;
 ypos=out.x.dx;
}
void setposi(int &xpos,int &ypos)
{
 in.x.ax=4;
 in.x.cx=xpos;
 in.x.dx=ypos;
 int86(51,&in,&out);
}
void restrictmouseptr(int x1,int y1,int x2,int y2)
{
 in.x.ax=7;
 in.x.cx=x1;
 in.x.dx=x2;
 int86(51,&in,&out);
 in.x.ax=8;
 in.x.cx=y1;
 in.x.dx=y2;
 int86(51,&in,&out);
}
void main()
{
 int x,y,cl,a,b;
 clrscr();
 int gd=DETECT,gm;
 int checkvar=0,checksp=4;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 layout();
 a=getmaxx()/2;
 b=getmaxy()/2;
 setposi(a,b);
 callmouse();
 mouseposi(x,y,cl);
 int cl1=cl;
 while(!kbhit())
 {
  if(cl1+3==cl)
   cl=cl1-3;
  mouseposi(x,y,cl);
  delay(8);
  if(cl1+1==cl)
  {
   if(y>=42&&y<=84)
   {
    checkvar=check(x,y,cl,checkvar);
    continue;
   }
   if(y>=429&&y<=467)
   {
    checksp=checkspecial(x,y,cl,checksp);
    if(checksp==15)
    {
     setfillstyle(SOLID_FILL,WHITE);
     bar(0,80,getmaxx(),429);
    }
    else if(checksp==30)
    {
     setfillstyle(SOLID_FILL,0);
     bar(0,80,getmaxx(),429);
    }
    continue;
   }
   setcolor(checkvar);
   setfillstyle(SOLID_FILL,checkvar);
   ultimatecheck(x,y,checksp);
  }
  if(cl1+2==cl&&y>90&&y<429)
  {
   setcolor(15);
   setfillstyle(SOLID_FILL,15);
   ultimatecheck(x,y,checksp);
  }
 }
 getch();
 clean();
 closegraph();
}
void ultimatecheck(int x,int y,int checksp)
{
   if(checksp==4)
    bar(x,y,x-4,y-4);
   else if(checksp==5&&y>90)
    bar(x,y,x-10,y-10);
   else if(checksp==6&&y>100)
    bar(x,y,x-20,y-20);
   else if(checksp==7&&y>110)
    bar(x,y,x-30,y-30);
   else if(checksp==8&&y>120)
    bar(x,y,x-40,y-40);
   else if(checksp==1&&y>105)
    circle(x,y,25);
   else if(checksp==2&&y>110)
    rectangle(x-30,y-30,x,y);
   else if(checksp==3&&y>90)
    rectangle(x-30,y-10,x,y);
}
void layout()
{
 int maxx=getmaxx(),maxy=getmaxy();
 cout<<"\n    			          PAINT  PAD";
 rectangle(5,5,maxx-5,maxy-5);
 rectangle(0,0,maxx,maxy);
 setfillstyle(SOLID_FILL,WHITE);
 bar(0,40,maxx,maxy-10);
 setfillstyle(SOLID_FILL,7);
 bar(2,42,maxx-2,80);
 bar(2,429,maxx-2,467);
 pallete();
 palletespecial();
 restrictmouseptr(5,42,maxx,maxy-15);
}
void pallete()
{
 setfillstyle(SOLID_FILL,15);
 bar(600-20,46,624-20,76);
 bar(540-20,46,564-20,76);
 bar(480-20,46,504-20,76);
 bar(420-20,46,444-20,76);
 bar(360-20,46,384-20,76);
 bar(300-20,46,324-20,76);
 bar(240-20,46,264-20,76);
 bar(180-20,46,204-20,76);
 bar(120-20,46,144-20,76);
 bar(60-20,46,84-20,76);
 setfillstyle(SOLID_FILL,9);
 bar(602-20,48,622-20,74);
 setfillstyle(SOLID_FILL,12);
 bar(542-20,48,562-20,74);
 setfillstyle(SOLID_FILL,10);
 bar(482-20,48,502-20,74);
 setfillstyle(SOLID_FILL,6);
 bar(422-20,48,442-20,74);
 setfillstyle(SOLID_FILL,5);
 bar(362-20,48,382-20,74);
 setfillstyle(SOLID_FILL,4);
 bar(302-20,48,322-20,74);
 setfillstyle(SOLID_FILL,3);
 bar(242-20,48,262-20,74);
 setfillstyle(SOLID_FILL,2);
 bar(182-20,48,202-20,74);
 setfillstyle(SOLID_FILL,1);
 bar(122-20,48,142-20,74);
 setfillstyle(SOLID_FILL,0);
 bar(62-20,48,82-20,74);
}
void palletespecial()
{
 setfillstyle(SOLID_FILL,0);
 bar(40,433,64,463);
 setfillstyle(SOLID_FILL,15);
 bar(580,433,604,463);
 bar(520,433,544,463);
 bar(460,433,484,463);
 bar(400,433,424,463);
 bar(340,433,364,463);
 bar(280,433,304,463);
 bar(220,433,244,463);
 bar(160,433,184,463);
 bar(100,433,124,463);
 setcolor(0);
 circle(52+60,448,10);
 rectangle(105+60,440,119+60,456);
 rectangle(162+60,442,182+60,454);
 setfillstyle(SOLID_FILL,0);
 bar(290,446,294,450);
 bar(290+60-2,446-2,294+60+2,450+2);
 bar(290+120-4,446-4,294+120+4,450+4);
 bar(290+180-6,446-6,294+180+6,450+6);
 bar(290+240-8,446-8,294+240+8,450+8);
}
int checkspecial(int x,int y,int cl,int old)
{
  if(x>=100&&x<=124&&y>=433&&y<=463)
   return 1;
  else if(x>=160&&x<=184&&y>=433&&y<=463)
   return 2;
  else if(x>=220&&x<=244&&y>=433&&y<=463)
   return 3;
  else if(x>=280&&x<=304&&y>=433&&y<=463)
   return 4;
  else if(x>=340&&x<=364&&y>=433&&y<=463)
   return 5;
  else if(x>=400&&x<=424&&y>=433&&y<=463)
   return 6;
  else if(x>=460&&x<=484&&y>=433&&y<=463)
   return 7;
  else if(x>=520&&x<=544&&y>=433&&y<=463)
   return 8;
  else if(x>=580&&x<=604&&y>=433&&y<=463)
   return 15;
  else if(x>=40&&x<=64&&y>=433&&y<=463)
   return 30;
  return old;
}
int check(int x,int y,int cl,int old)
{
  if(x>=582&&x<=602&&y>=48&&y<=74)
   return 9;
  else if(x>=522&&x<=542&&y>=48&&y<=74)
   return 12;
  else if(x>=462&&x<=482&&y>=48&&y<=74)
   return 10;
  else if(x>=402&&x<=422&&y>=48&&y<=74)
   return 6;
  else if(x>=342&&x<=362&&y>=48&&y<=74)
   return 5;
  else if(x>=282&&x<=302&&y>=48&&y<=74)
   return 4;
  else if(x>=222&&x<=242&&y>=48&&y<=74)
   return 3;
  else if(x>=162&&x<=182&&y>=48&&y<=74)
   return 2;
  else if(x>=102&&x<=122&&y>=48&&y<=74)
   return 1;
  else if(x>=42&&x<=62&&y>=48&&y<=74)
   return 0;
  return old;
}
void clean()
{
 clrscr();
 cleardevice();
}