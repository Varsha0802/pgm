#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#define BLACK 0
GLfloat triangle[3][3]={{100.0,250.0,175.0},{100.0,100.0,300.0},{1.0,1.0,1.0}};
GLfloat rotate[3][3]={{0},{0},{0}};
GLfloat result[3][3]={{0},{0},{0}};
GLfloat arbitrary_x=0,arbitrary_y=0;
float rotation_angle=0;
void multiply()
{
	int i,j,k;
	for(i=0;i<3;i++)		
	{
		for(j=0;j<3;j++)
		{
			result[i][j]=0;
			for(k=0;k<3;k++)
			{
				result[i][j]=result[i][j]+rotate[i][k]*triangle[k][j];
			}
		}
	}
}
void rotat()
{
	GLfloat m,n;
	m=arbitrary_x*(1-cos(rotation_angle))+arbitrary_y*(sin(rotation_angle));
	n=arbitrary_y*(1-cos(rotation_angle))-arbitrary_x*(sin(rotation_angle));
	rotate[0][0]=cos(rotation_angle);
	rotate[0][1]=-sin(rotation_angle);
	rotate[0][2]=m;
	rotate[1][0]=sin(rotation_angle);
	rotate[1][1]=cos(rotation_angle);
	rotate[1][2]=n;
	rotate[2][0]=0;
	rotate[2][1]=0;
	rotate[2][2]=1;
	multiply();
}
void drawtriangle()
{
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(triangle[0][0],triangle[1][0]);
	glVertex2f(triangle[0][1],triangle[1][1]);
	glVertex2f(triangle[0][2],triangle[1][2]);
	glEnd();
	glFlush();
}
void drawrotatetriangle()
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(result[0][0],result[1][0]);
	glVertex2f(result[0][1],result[1][1]);
	glVertex2f(result[0][2],result[1][2]);
	glEnd();
	glFlush();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawtriangle();
	drawrotatetriangle();
	glFlush();
}
void myinit()
{
	glColor3f(1.0,0.0,0.0);
	glClearColor(1.0,1.0,1.0,1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,900,-500,900);
}
int main(int argc,char**argv)
{
	int ch;;
	printf("enter your choice:\n1.rotate over origin \n2.rotate over fixed poinrs\n: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("Enter the angle: ");
		scanf("%f",&rotation_angle);
		rotation_angle=(3.14*rotation_angle)/180;
		rotat();
		break;
		case 2:printf("enter the points: ");
		scanf("%f%f",&arbitrary_x,&arbitrary_y);
		printf("enter the angle: ");
		scanf("%f",&rotation_angle);
		rotat();
		break;
	}
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("rotate triangle");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}
