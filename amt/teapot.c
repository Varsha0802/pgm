#include<GL/glut.h>
#include<stdio.h>

GLfloat a[]={0.7,0.7,0.7,1.0},d[]={0.8,0.8,0.8,1.0},s[]={1,1,1,1},li[]={0.7,0.7,0.7,1},lp[]={2,6,3,0};
const GLfloat sh[]={50};

void i(){
	glMaterialfv(GL_FRONT,GL_AMBIENT,a);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,d);
	glMaterialfv(GL_FRONT,GL_SPECULAR,s);
	glMaterialfv(GL_FRONT,GL_SHININESS,sh);
	glLightfv(GL_LIGHT0,GL_POSITION,lp);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,li);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2,2,-2,2,-10,10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2,1,2,0,0.2,0.2,0,1,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void tp(){
	
	glPushMatrix();
	glTranslated(0.3,0,0.4);
	glRotated(90,1,1,0);
	glutSolidTeapot(0.2);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0.6,0,0);
	//glRotated(20,0,1,0);
	glutSolidTeapot(0.1);
	glPopMatrix();
}

void tt(){
	GLfloat d[]={0.1,0.3,0.6,1.0};
	glMaterialfv(GL_FRONT,GL_DIFFUSE,d);
	glPushMatrix();
	glTranslated(0.0,-0.3,0.0);
	glScaled(7,0.5,7);
	glutSolidCube(0.2);
	glPopMatrix();
}

void fl(){
	
	glPushMatrix();
	glTranslated(0.5,-0.7,0.5);
	glScaled(0.5,7,0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}

void ll(){
	glPushMatrix();
	glTranslated(-0.5,-0.7,0.5);
	glScaled(0.5,7,0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}

void rl(){
	glPushMatrix();
	glTranslated(0.5,-0.7,-0.5);
	glScaled(0.5,7,0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}

void bl(){
	
	glPushMatrix();
	glTranslated(-0.5,-0.7,-0.5);
	glScaled(0.5,7,0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}

void lw(){
	GLfloat d[]={0.5,0.3,0.5,1.0};
	glMaterialfv(GL_FRONT,GL_DIFFUSE,d);
	glPushMatrix();
	glTranslated(-1,0,0);
	glScaled(0.1,10,10);
	glutSolidCube(0.2);
	glPopMatrix();
}

void bf(){
	GLfloat d[]={0.6,0.6,0.1,1.0};
	glMaterialfv(GL_FRONT,GL_DIFFUSE,d);
	
	glPushMatrix();
	glTranslated(0,-1,0);
	glScaled(10,0.1,10);
	glutSolidCube(0.2);
	glPopMatrix();
}

void rw(){
	GLfloat d[]={0.5,0.0,0.1,1.0};
	glMaterialfv(GL_FRONT,GL_DIFFUSE,d);
	glPushMatrix();
	glTranslated(0,0,-1);
	glScaled(10,10,0.1);
	glutSolidCube(0.2);
	glPopMatrix();
}
void draw_text(float x,float y,float z,char*s)
{
	int i;
	glRasterPos3f(x,y,z);
	for(i=0;s[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
}
void disp(){
	i();
	tp();
	tt();
	fl();
	ll();
	rl();
	bl();
	bf();
	rw();
	lw();
	draw_text(-1,-1,-1,"Teapot");
	glFlush();
}

void main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(600,600);
	glutCreateWindow("Shaded Scene/1BI20CS165");
	glutDisplayFunc(disp);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearColor(1,1,1,0);
	glViewport(0,0,400,400);
	glutMainLoop();
}



