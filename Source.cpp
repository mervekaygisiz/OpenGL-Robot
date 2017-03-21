#include <GL/glut.h>
#include <math.h>
#include "RgbImage.h"

#define BASE_HEIGHT 4.0/2  // robotun gövde boyutu uzunluðu
#define BASE_RADIUS 1.0/2  // robotun gövdesinin geniþliði
#define HEAD_HEIGHT 1.25/2 // robotun kafasýnýn uzunluðu
#define HEAD_RADIUS 0.75/2  // kafasýnýn geniþliði
#define NECK_HEIGHT 0.5/2  // þuan anlaþýlamadý deðiþiklik olmuyor ?????????????????????????????
#define EYE_LEVEL 0.75/2   // göz noktalarýnýn yüzüne göre yüksekliði
#define NOSE_LENGTH 0.5/2  // burnunun yüksekliðe göre konumu
#define LOWER_ARM_HEIGHT 2.0/2  //kolun üst kýsmýnýn uzunluðu
#define LOWER_ARM_WIDTH 0.5/2   //kolun üst kýsmýnýn geniþliði
#define UPPER_ARM_HEIGHT 1.25/2  // kolun alt kýsmýnýn uzunluðu
#define UPPER_ARM_WIDTH 0.5/2   //kolun alt kýsmýnýn geniþliði
#define ARM_TRANSLATION 0.22/2  // kollarýn vücuda yakýnlýðý
#define alpha 0.0
#define pi 3.14159265
static GLfloat theta[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
static GLint axis = 0;
GLUquadricObj *p;
GLfloat x = 0.0;
GLfloat y = 0.0;
GLfloat xpos = 0.0;
GLfloat ypos = 0.0;
GLfloat zpos = 0.0;
GLfloat ambient[3];
GLfloat diffuse[3];
GLfloat specular[3];
GLfloat shiness[] = { 50.0f };
float width = 800; //penceerenin boyutlarý
float height = 600;
char* file1 = "./background.bmp";
char* file2 = "./kar.bmp";
char* file3 = "./ytu.bmp";
GLuint texture[3];
void base(void);
void head(void);
void neck(void);
void upper_rarm(void);
void upper_larm(void);
void lower_rarm(void);
void lower_larm(void);
void init(void);
void display(void);
void reshape(int width, int height);
void keyboard(unsigned char, int, int);
void processSpecialKeys(int, int, int);
void jump(void);
void lsphere(void);
void init1(void);
void loadTextureFromFile(char, int);


void base(void) {
	double angle, angleInc;
	int i;
	angle = pi / 180;
	angleInc = angle;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix();

	ambient[0] = 1.0; ambient[1] = 1.0; ambient[2] = 1.0;
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);


	
	//glRotatef(-90.0, 1.0, 0.0, 0.0); // silindir x eksenine dik olacak þekilde yerleþtirilecek
	//gluQuadricDrawStyle(p, GLU_FILL);  
	//gluCylinder(p, BASE_RADIUS, BASE_RADIUS, BASE_HEIGHT, 20, 20); // silndir oluþturmak için. koni istesek 
	//base_radiuslardan birini 0.0 yapardýk mesela

	glTranslatef(0.0, 2.0, 0.0); //1.25 yükseklik
	glutSolidSphere(1.0, 20, 16);  // 0.75 kürenin büyüklüðü
								   //glFlush();




	glPushMatrix();
	glTranslatef(0.0, BASE_RADIUS - 0.60, 1.0);
	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 0.0;
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glColor3d(1.0, 0.0, 0.0);
	gluQuadricDrawStyle(p, GLU_FILL);
	gluSphere(p, 0.125, 6, 6);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-0.0, BASE_RADIUS - 0.30, 0.9);
	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 0.0;
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);


	gluQuadricDrawStyle(p, GLU_FILL);
	gluSphere(p, 0.125, 6, 6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.0, BASE_RADIUS, 0.88);
	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 0.0;
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);


	gluQuadricDrawStyle(p, GLU_FILL);
	gluSphere(p, 0.125, 6, 6);
	glPopMatrix();



	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

}


void neck(void) {
	glPushMatrix();

	ambient[0] = 1.0; ambient[1] = 0.0; ambient[2] = 0.0;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, BASE_HEIGHT + 0.9, 0.0);  //boyun oluþturmak için
	glRotatef(-90.0, 1.0, 0.0, 0.0);  // boynu x eksenine dik açýda yerleþtirdik
	gluQuadricDrawStyle(p, GLU_FILL);
	gluCylinder(p, HEAD_RADIUS + 0.25, HEAD_RADIUS + 0.25, HEAD_HEIGHT - 0.4, 8, 6); //boyun için çizilen silindirin boyutlarý

	glPushMatrix();

	ambient[0] = 1.0; ambient[1] = 0.0; ambient[2] = 0.0;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	//glTranslatef(-0.25, BASE_HEIGHT + 0.9, 0.0);  //boyun oluþturmak için
	glRotatef(-90.0, 1.0, 0.0, 0.0);  // boynu x eksenine dik açýda yerleþtirdik
									  //------------------------------------------------------------------------------------------
	glTranslatef(-0.35, 0.5 * LOWER_ARM_HEIGHT - 0.4, ARM_TRANSLATION - 0.7);
	glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT / 2, LOWER_ARM_WIDTH);
	glutSolidCube(1.0);

	glPopMatrix();
	glPopMatrix();
}

void head(void) {
	glPushMatrix();

	ambient[0] = 1.0; ambient[1] = 1.0; ambient[2] = 1.0;
	diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glRotatef(-90.0, 1.0, 0.0, 0.0);
	//gluQuadricDrawStyle(p, GLU_FILL);
	//gluCylinder(p, HEAD_RADIUS, HEAD_RADIUS, HEAD_HEIGHT, 20, 20);

	glTranslatef(0.0, 0.0, 1.25); //1.25 yükseklik
	glutSolidSphere(0.60, 20, 16);  // 0.75 kürenin büyüklüðü



	glPushMatrix();
	glTranslatef(0.25, -HEAD_RADIUS - 0.12, EYE_LEVEL - 0.1); // 0.25 sað gözün konumu eye_level göz noktasýnýn yüksekliði

	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 0.0;  // sað göz rengi
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	gluQuadricDrawStyle(p, GLU_FILL);
	gluSphere(p, 0.125, 6, 6); // göz büyüklüðü
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.25, -HEAD_RADIUS - 0.12, EYE_LEVEL - 0.1);
	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 0.0;  // sað göz boyutu
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);


	gluQuadricDrawStyle(p, GLU_FILL);
	gluSphere(p, 0.125, 6, 6);  // sol göz boyutu
	glPopMatrix();

	glPushMatrix();
	ambient[0] = 1.0; ambient[1] = 0.5; ambient[2] = 0.0;  // burun rengi
	diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
	glTranslatef(0.0, -HEAD_RADIUS - 0.2, NOSE_LENGTH - 0.2); // burun yeri
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluQuadricDrawStyle(p, GLU_FILL);
	gluCylinder(p, 0.125, 0, NOSE_LENGTH, 8, 6);  //burun þekli
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();

	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 0.0;  // þapka rengi þapkanýn silimdiri
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 1.70, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0); // silindir x eksenine dik olacak þekilde yerleþtirilecek
	gluQuadricDrawStyle(p, GLU_FILL);
	gluCylinder(p, HEAD_RADIUS + 0.2, HEAD_RADIUS + 0.2, HEAD_HEIGHT - 0.5, 20, 20); // silndir oluþturmak için. koni istesek 


	glPopMatrix();

	//00000000000000000000000000000000000000000000000000000000000000000000000000000000
	double i, resolution = 0.1;
	double height = 1;
	double radius = 0.45;
	

	glPushMatrix();

	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 0.0;  // þapka rengi þapkanýn kare kýsmý
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 1.8, 0.0);
	//glRotatef(-90.0, 1.0, 0.0, 0.0); // silindir x eksenine dik olacak þekilde yerleþtirilecek
	//glTranslatef(0, -0.5, 0);

	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(0, height, 0);  /* center */

	
	int j = 2 * pi;
	for (i = j; i >= 0; i -= resolution)

	{
		glTexCoord2f(0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f);
		glVertex3f(radius * cos(i), height, radius * sin(i));
	}
	/* close the loop back to 0 degrees */
	glTexCoord2f(0.5, 0.5);
	glVertex3f(radius, height, 0);
	glEnd();

	

	/* bottom triangle: note: for is in reverse order */
	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(0, 0, 0);  /* center */
	for (i = 0; i <= 2 * pi; i += resolution)
	{
		glTexCoord2f(0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f);
		glVertex3f(radius * cos(i), 0, radius * sin(i));
	}
	glEnd();

	/* middle tube */
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= 2 * pi; i += resolution)
	{
		const float tc = (i / (float)(2 * pi));
		glTexCoord2f(tc, 0.0);
		glVertex3f(radius * cos(i), 0, radius * sin(i));
		glTexCoord2f(tc, 1.0);
		glVertex3f(radius * cos(i), height, radius * sin(i));
	}
	/* close the loop back to zero degrees */
	glTexCoord2f(0.0, 0.0);
	glVertex3f(radius, 0, 0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(radius, height, 0);
	glEnd();

	glPopMatrix();
	


	//0000000000000000000000000000000000000000000000000000000000000000000000000000000000000
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix();  //þakpasýna disk eklendi
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluDisk(p, 0.0, HEAD_RADIUS + 0.2, 20, 20);
	glTranslatef(0.0, 0.0, HEAD_HEIGHT + 1.2);
	gluDisk(p, 0.0, HEAD_RADIUS + 0.2, 20, 20);


	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void lower_rarm(void) {
	glPushMatrix();

	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;      //sað üst kolun rengi
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, LOWER_ARM_HEIGHT - 1.25, ARM_TRANSLATION + 0.50);
	glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

void lower_larm(void) {
	glPushMatrix();

	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;      //sol üst kolun rengi
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, LOWER_ARM_HEIGHT - 1.25, -ARM_TRANSLATION - 0.50);
	glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

void upper_rarm(void) {
	glPushMatrix();

	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 1.0;
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, UPPER_ARM_HEIGHT - 1.1, ARM_TRANSLATION + 0.50);
	glScalef(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT, UPPER_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

void upper_larm(void) {
	glPushMatrix();

	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 1.0;
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, UPPER_ARM_HEIGHT - 1.1, -ARM_TRANSLATION - 0.50);
	glScalef(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT, UPPER_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

void rbacak(void) {
	glPushMatrix();

	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, UPPER_ARM_HEIGHT, ARM_TRANSLATION + 0.15);
	glScalef(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT + 0.6, UPPER_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

void lbacak(void) {
	glPushMatrix();

	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, UPPER_ARM_HEIGHT, -ARM_TRANSLATION - 0.15);
	glScalef(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT + 0.6, UPPER_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}


void init1(void) {
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat white_light[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat lmodel_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void lsphere(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidSphere(1.0, 20, 50);  // tepedeki güneþi oluþturmak için 20 çokgenin kenar sayýsýnýn sýklýðý
	glFlush();
}

void loadTextureFromFile(char *filename, int i)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );


	glGenTextures(1, &texture[i]);					// Create The Texture
	glBindTexture(GL_TEXTURE_2D, texture[i]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Typical Texture Generation Using Data From The Bitmap

	glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

}



void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.3, 5.0, 12.0, 0.0, 1.25, 0.0, 0.0, 1.0, 0.0); // tüm ekranýn 3 boyutlu bakýþ açýsý

	glPushMatrix();
	ambient[0] = 0.4; ambient[1] = 0.5; ambient[2] = 0.0;  //günes rengi
	diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);


	glTranslatef(-4.5, 5.75, 0.0);
	lsphere();
	glPopMatrix();

	/*glPushMatrix();
	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(3.0, 0.5, 1.0);
	glutSolidCube(1.0);
	glPopMatrix*/

	glPushMatrix();
	ambient[0] = 0.0; ambient[1] = 0.6; ambient[2] = 0.6;
	diffuse[0] = 0.0; diffuse[1] = 1.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(-4.0, 0.7, 3.5);
	glutSolidCone(1.0, 1.5, 20, 15);//-----------------------koni

	glTranslatef(-0.25, 0.7, -0.75);
	glutSolidCone(1.1, 1.5, 20, 15);//-----------------------koni

	glTranslatef(-0.25, 0.7, -0.75);
	glutSolidCone(1.3, 1.5, 20, 15);//-----------------------koni

	glTranslatef(-0.25, 0.7, -0.75);
	glutSolidCone(1.5, 1.5, 20, 15);//-----------------------koni

	glTranslatef(-0.10, 0.7, -0.75);
	glutSolidCone(1.9, 1.5, 20, 15);//-----------------------koni

	glPopMatrix();

	glPushMatrix();
	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(-4.25, -1.0, -0.5);
	glRotatef(-90.0, 1.0, 0.0, 0.0); // silindir x eksenine dik olacak þekilde yerleþtirilecek
	gluQuadricDrawStyle(p, GLU_FILL);  
	gluCylinder(p, HEAD_RADIUS, HEAD_RADIUS, BASE_HEIGHT, 20, 20); // silndir oluþturmak için. koni istesek 

	glPopMatrix();
/*
	glPushMatrix();
	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(-3.0, 0.5, -3.0);
	glutSolidTeapot(1.0);
	glPopMatrix();
*/

	glPushMatrix(); //--------------------------ev-----------------------------

	ambient[0] = 0.9; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
	

	// house

	glTranslatef(4, 0, 0);
	
	glutSolidCube(3.5);                 // building

	glTranslatef(0.1, 1.75, 0);
	glPushMatrix(); // roof

	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glRotatef(-90, 1, 0, 0);
	
	glutSolidCone(2.4, 1, 16, 8);
	glPopMatrix();

	glTranslatef(1.5, .5, -.75);
	glPushMatrix();                   // chimney
	glScalef(2, 3.5, 1);
	
	glutSolidCube(.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.6, -1.6, 2.3);
	glutSolidCube(1);

	glPopMatrix();


	glPopMatrix();














	//--------------------background-----------------------------------

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();

	ambient[0] = 1.0; ambient[1] = 1.0; ambient[2] = 1.0;
	diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 6.0, 0.0);
	//glRotatef(derece, 0.0, 1.0, 0.0);
	glScalef(0.4, 0.3, 0.25);



	glBegin(GL_POLYGON);

	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.0, 24.0, -10.0); //arkayüz
	glTexCoord2f(1.0f, 1.0f); glVertex3f(24.0, 24.0, -10.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(24.0, -24.0, -10.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.0, -24.0, -10.0);

	glEnd();


	glPopMatrix();
	glDisable(GL_TEXTURE_2D);


	//----------------ground----------------------------------------

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);

	glPushMatrix();

	ambient[0] = 1.0; ambient[1] = 1.0; ambient[2] = 1.0;
	diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glScalef(4.0, 3.0, 1.12);

	glBegin(GL_POLYGON);  // zeminin koordinatlarý
	glTexCoord2f(0.0f, 1.0f);     glVertex3f(5.0, 0.0, 5.0);
	glTexCoord2f(1.0f, 1.0f);     glVertex3f(5.0, 0.0, -5.0);
	glTexCoord2f(1.0f, 0.0f);     glVertex3f(-5.0, 0.0, -5.0);
	glTexCoord2f(0.0f, 0.0f);     glVertex3f(-5.0, 0.0, 5.0);


	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	glTranslatef(xpos, ypos, zpos);
	glRotatef(theta[0], 0.0, 1.0, 0.0);
	base();
	neck();

	glPushMatrix();
	glTranslatef(0.0, BASE_HEIGHT + HEAD_HEIGHT / 2, 0.0);
	glRotatef(theta[2], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	head();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 1.5, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[7], 0.0, 0.0, 1.0);
	lbacak();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 1.5, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[8], 0.0, 0.0, 1.0);
	rbacak();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
	glRotatef(200.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[4], 0.0, 0.0, 1.0);
	lower_rarm();
	glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
	glRotatef(0.0, 0.0, 0.0, 180.0);
	glRotatef(theta[6], 0.0, 0.0, 1.0);
	upper_rarm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
	glRotatef(160.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[3], 0.0, 0.0, 1.0);
	lower_larm();
	glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
	glRotatef(0.0, 0.0, 0.0, 180.0);
	glRotatef(theta[5], 0.0, 0.0, 1.0);
	upper_larm();
	glPopMatrix();


	glFlush();
	glutSwapBuffers();
}

bool firstWalk = true;
bool firstRun = true;
bool midAir = false;
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1': // kosma ileri
		if (firstRun) {
			theta[7] = 30;
			theta[8] = -30;
			theta[4] = 20;
			theta[3] = -20;
			firstRun = false;
			firstWalk = true;
		}
		xpos -= cos(90 * pi / 180 + theta[0] * pi / 180)*1.5;
		zpos += sin(90 * pi / 180 + theta[0] * pi / 180)*1.5;
		if (xpos > 5)
			xpos = 5;
		if (zpos > 5)
			zpos = 5;
		if (xpos < -5)
			xpos = -5;
		if (zpos < -5)
			zpos = -5;
		theta[7] = -1 * theta[7];
		theta[8] = -1 * theta[8];
		theta[4] = -1 * theta[4];
		theta[3] = -1 * theta[3];
		break;
	case '2': // kosma geri
		if (firstRun) {
			theta[7] = 30;
			theta[8] = -30;
			theta[4] = 20;
			theta[3] = -20;
			firstRun = false;
			firstWalk = true;
		}
		xpos -= -1 * cos(90 * pi / 180 + theta[0] * pi / 180)*1.5;
		zpos += -1 * sin(90 * pi / 180 + theta[0] * pi / 180)*1.5;
		if (xpos > 5)
			xpos = 5;
		if (zpos > 5)
			zpos = 5;
		if (xpos < -5)
			xpos = -5;
		if (zpos < -5)
			zpos = -5;
		theta[7] = -1 * theta[7];
		theta[8] = -1 * theta[8];
		theta[4] = -1 * theta[4];
		theta[3] = -1 * theta[3];
		break;
	case '3': // dairesel sacma bir hareket
		if (firstWalk) {
			theta[7] = 15;
			theta[8] = -15;
			firstWalk = false;
			firstRun = true;
		}
		xpos -= cos(90 * pi / 180 + theta[0] * pi / 180) / 2;
		zpos += sin(90 * pi / 180 + theta[0] * pi / 180) / 2;
		if (xpos > 5)
			xpos = 5;
		if (zpos > 5)
			zpos = 5;
		if (xpos < -5)
			xpos = -5;
		if (zpos < -5)
			zpos = -5;
		theta[7] = -1 * theta[7];
		theta[8] = -1 * theta[8];
		theta[0] += 10;
		break;
	case '4': // dairesel sacma bir hareket
		if (firstWalk) {
			theta[7] = 15;
			theta[8] = -15;
			firstWalk = false;
			firstRun = true;
		}
		xpos -= cos(90 * pi / 180 + theta[0] * pi / 180) / 2;
		zpos += sin(90 * pi / 180 + theta[0] * pi / 180) / 2;
		if (xpos > 5)
			xpos = 5;
		if (zpos > 5)
			zpos = 5;
		if (xpos < -5)
			xpos = -5;
		if (zpos < -5)
			zpos = -5;
		theta[7] = -1 * theta[7];
		theta[8] = -1 * theta[8];
		theta[0] -= 10;
		break;
	case 'w': // walking animation forward
		if (firstWalk) {
			theta[7] = 15;
			theta[8] = -15;
			firstWalk = false;
			firstRun = true;
		}
		xpos -= cos(90 * pi / 180 + theta[0] * pi / 180) / 2;
		zpos += sin(90 * pi / 180 + theta[0] * pi / 180) / 2;
		if (xpos > 5)
			xpos = 5;
		if (zpos > 5)
			zpos = 5;
		if (xpos < -5)
			xpos = -5;
		if (zpos < -5)
			zpos = -5;
		theta[7] = -1 * theta[7];
		theta[8] = -1 * theta[8];
		break;
	case 's': // walking backward animation
		if (firstWalk) {
			theta[7] = 15;
			theta[8] = -15;
			firstWalk = false;
			firstRun = true;
		}
		xpos -= -1 * cos(90 * pi / 180 + theta[0] * pi / 180) / 2;
		zpos += -1 * sin(90 * pi / 180 + theta[0] * pi / 180) / 2;
		if (xpos > 5)
			xpos = 5;
		if (zpos > 5)
			zpos = 5;
		if (xpos < -5)
			xpos = -5;
		if (zpos < -5)
			zpos = -5;
		theta[7] = -1 * theta[7];
		theta[8] = -1 * theta[8];
		break;
	case ' ': //  jumping animation
		if (midAir) {
			ypos -= 1.0; // down 1
			theta[3] = 0;
			theta[4] = 0;
			midAir = false;
		}
		else {
			ypos += 1.0; // up 1
			theta[3] = 180;
			theta[4] = 180;
			midAir = true;
		}
		// forward 1
		xpos -= cos(90 * pi / 180 + theta[0] * pi / 180) / 4;
		zpos += sin(90 * pi / 180 + theta[0] * pi / 180) / 4;
		if (xpos > 5)
			xpos = 5;
		if (zpos > 5)
			zpos = 5;
		if (xpos < -5)
			xpos = -5;
		if (zpos < -5)
			zpos = -5;
		break;
	case 'a': theta[1] += 5.0;
		if (theta[1] > 90.0)  //kafa saða
			theta[1] = 90.0;
		break;

	case 'z': theta[1] -= 5.0; //kafa sola
		if (theta[1] < -90.0)
			theta[1] = -90.0;
		break;

	case 'o': theta[2] += 5.0; //kafa aþaðý
		if (theta[2] > 45.0)
			theta[2] = 45.0;
		break;

	case 'p': theta[2] -= 5.0;  //kafa yukarý
		if (theta[2] < -45.0)
			theta[2] = -45.0;
		break;

	case 'k': theta[3] -= 5.0; break;    //sol kol yukarý
	case 'l': theta[3] += 5.0; break;    // sol kol aþaðý

	case 'h': theta[4] -= 5.0; break;   //sað kol yukarý
	case 'j': theta[4] += 5.0; break;   //sað kol aþaðý

	case 'n': theta[5] -= 5.0; break;   // sol kol aþaðýsý yukarý
	case 'm': theta[5] += 5.0; break;  // sol kol aþaðýsý aþaðý

	case 'v': theta[6] -= 5.0; break;  //sað kol aþaðýsý yukarý
	case 'b': theta[6] += 5.0; break;  //sað kol aþaðýsý aþaðý

	case '7': if (theta[7] >= -25.0) {
		theta[7] -= 5.0;  // sol bacak
		firstWalk = true;
		firstRun = true;
	}

			  break;
	case '8': if (theta[7] <= 25.0) {
		theta[7] += 5.0;  // sol bacak
		firstWalk = true;
		firstRun = true;
	}

			  break;

	case '9': if (theta[8] >= -25.0) {
		theta[8] -= 5.0;  // sag bacak
		firstWalk = true;
		firstRun = true;
	}
			  break;
	case '0': if (theta[8] <= 25.0) {
		theta[8] += 5.0;  // sag bacak
		firstWalk = true;
		firstRun = true;
	}
			  break;

	case 'e': theta[0] = theta[1] = theta[2] = theta[3] = theta[4] = theta[5] = theta[6] = theta[7] = theta[8] = xpos = ypos = zpos = 0.0;
		break;  //robotu ilk açýlýþ konumuna ve haline döndürür 

	case 'r': theta[0] = theta[1] = theta[2] = theta[3] = theta[4] = theta[5] = theta[6] = theta[7] = theta[8] = 0.0;
		break;  //robotu ilk haline döndürür kollar yön vs ama düzlemdeki yeri deðiþmez

	case 'q': exit(0); break;  // uygulamadan çýk
	}
	glutPostRedisplay();
}


void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		xpos -= cos(90 * pi / 180 + theta[0] * pi / 180);
		zpos += sin(90 * pi / 180 + theta[0] * pi / 180);
		if (xpos > 5)
			xpos = 5;
		if (zpos > 5)
			zpos = 5;
		if (xpos < -5)
			xpos = -5;
		if (zpos < -5)
			zpos = -5;
		break;
	case GLUT_KEY_DOWN:
		xpos += cos(90 * pi / 180 + theta[0] * pi / 180);
		zpos -= sin(90 * pi / 180 + theta[0] * pi / 180);
		if (xpos > 5)
			xpos = 5;
		if (zpos > 5)
			zpos = 5;
		if (xpos < -5)
			xpos = -5;
		if (zpos < -5)
			zpos = -5;
		break;
	case GLUT_KEY_LEFT: theta[0] -= 5.0; break;
	case GLUT_KEY_RIGHT: theta[0] += 5.0; break;
	case GLUT_KEY_PAGE_UP: ypos += 1.0; break;
	case GLUT_KEY_PAGE_DOWN: ypos -= 1.0; break;
	}
	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (GLfloat)w / (GLfloat)h, 0.5, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init(void) {
	GLfloat lightIntensity[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat light_position[] = { 2.0f, 6.0f, 3.0f, 0.0f };

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	p = gluNewQuadric();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Robot");
	init();
	init1();

	loadTextureFromFile(file1, 0);
	loadTextureFromFile(file2, 1);
	//loadTextureFromFile(file3, 2);

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();
	return 0;
}