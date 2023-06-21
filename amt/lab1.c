#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
int n,x1,x2,y1,y2;
int endpoints[8][4];
void draw_pixel(int x,int y)
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void draw_line(int x1,int y1,int x2,int y2)
{
	int x,y,dx,dy,incx,incy,i,p,inc1,inc2;
	x=x1;
	y=y1;
	dx=x2-x1;
	dy=y2-y1;
	if(dx<0)dx=-dx;
	if(dy<0)dy=-dy;
	incx=1;
	incy=1;
	if(x2<x1)
	incx=-1;
	if(y2<y1)
	incy=-1;
	if(dx>dy)
	{
	draw_pixel(x,y);
	p=2*dy-dx;
	inc1=2*(dy-dx);
	inc2=2*dy;
	for(i=0;i<dx;i++)
	{
	if(p>=0)
	{
	y+=incy;
	p+=inc1;
	}
	else
	p+=inc2;
	x+=incx;
	draw_pixel(x,y);
	}
	}
	else
	{
	draw_pixel(x,y);
	p=2*dx-dy;
	inc1=2*(dx-dy);
	inc2=2*dx;
	for(i=0;i<dy;i++)
	{
	if(p>=0)
	{
	x+=incx;
	p+=inc1;
	}
	else
	p+=inc2;
	y+=incy;
	draw_pixel(x,y);
	}
	}
}
void bresnham()
	{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	for(i=0;i<n;i++)
	{
	x1=endpoints[i][0];
	y1=endpoints[i][1];
	x2=endpoints[i][2];
	y2=endpoints[i][3];
	draw_line(x1,y1,x2,y2);
	}
	glFlush();
}
void myinit()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,600,0,600);
glMatrixMode(GL_MODELVIEW);
}
void main(int argc,char**argv)
{
int i;
printf("Enter the no of lines\n:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the endpoints of the line %d :\n",i);
scanf("%d%d%d%d",&endpoints[i][0],&endpoints[i][1],&endpoints[i][2],&endpoints[i][3]);
}
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100,100);
glutInitWindowSize(600,600);
glutCreateWindow("bresnham");
glutDisplayFunc(bresnham);
myinit();
glutMainLoop();
}
