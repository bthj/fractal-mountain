#include <GL/glut.h>
#include "GL/gl.h"
#include "GL/glu.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Auga.h"
#include "Flotur.h"
#include "Fjall.h"
#include "Sol.h"
#include <time.h>

#define PI 3.14159265359

Flotur flotur;
Flotur himinn;
Auga auga;
Fjall fjall;
Sol* sol;

GLdouble bergLiturA[3], bergLiturB[3];
GLdouble litabil1A[3], litabil1B[3];
GLdouble litabil2A[3], litabil2B[3];
GLdouble litabil3A[3], litabil3B[3];

// GLdouble xStada, zStada; // geymsla fyrir stï¿½ï¿½u auga

// nÃºmer valmynda
int mAdal,
	mStadsetning, mStadsetningX, mStadsetningZ,
	mStaerd, mUpplausn, mRask, mHending,
	mSol, mSolAtt, mSolHaed, 
	m1Litur,
	m1NedriMork, m1EfriMork, m1NedriLitur, m1EfriLitur,
	 m1NedriLiturR, m1NedriLiturG, m1NedriLiturB,
	 m1EfriLiturR, m1EfriLiturG, m1EfriLiturB,
	m1Setlog, m1Hallathol,
	m2Litur,
	m2NedriMork, m2EfriMork, m2NedriLitur, m2EfriLitur,
	 m2NedriLiturR, m2NedriLiturG, m2NedriLiturB,
	 m2EfriLiturR, m2EfriLiturG, m2EfriLiturB,
	m2Setlog, m2Hallathol,
	m3Litur,
	m3NedriMork, m3EfriMork, m3NedriLitur, m3EfriLitur,
	 m3NedriLiturR, m3NedriLiturG, m3NedriLiturB,
	 m3EfriLiturR, m3EfriLiturG, m3EfriLiturB,
	m3Setlog, m3Hallathol,
	mBergLitur,
	mBergNedriMork, mBergEfriMork, mBergNedriLitur, mBergEfriLitur,
	 mBergNedriLiturR, mBergNedriLiturG, mBergNedriLiturB,
	 mBergEfriLiturR, mBergEfriLiturG, mBergEfriLiturB,
	mBergSetlog,
	mLitauppl;

int teikning;  // geymsla fyrir teikniham

// valmyndafï¿½ll
void menuAdal(int value) {
	if(value == 1) {
		teikning = GL_LINE;
		glEnable(GL_CULL_FACE);
		glutChangeToMenuEntry(1, "Gegnheilt", 2);
	}
	else if(value == 2) {
		teikning = GL_FILL;
		glDisable(GL_CULL_FACE);
		glutChangeToMenuEntry(1, "VÃ­ramÃ³del", 1);
	}
	glutPostRedisplay();
}
void menuStadsetning(int value) {
	if(glutGetMenu() == mStadsetningX)
		fjall.setjaXstad((GLdouble)value);
	else if(glutGetMenu() == mStadsetningZ)
		fjall.setjaZstad((GLdouble)-value);
	fjall.byggja();
	glutPostRedisplay();
}
void menuStaerd(int value) {
	fjall.setjaStaerd((GLdouble)value);
	fjall.byggja();
	glutPostRedisplay();
}
void menuUpplausn(int value) {
	if((value <= 100) && (value >= 1))
		fjall.setjaUpplausn((GLdouble)value / 100.0);
	else if(value == 105)
		fjall.setjaUpplausn(0.005);
	else if(value == 104)
		fjall.setjaUpplausn(0.004);
	else if(value == 103)
		fjall.setjaUpplausn(0.003);
	else if(value == 102)
		fjall.setjaUpplausn(0.002);
	else if(value == 101)
		fjall.setjaUpplausn(0.001);
	fjall.byggja();
	glutPostRedisplay();
}
void menuRask(int value) {
	fjall.setjaRask((GLdouble)value / 10.0);
	fjall.byggja();
	glutPostRedisplay();
}
void menuHending(int value) {
	fjall.setjaSaedisSkekkju((GLdouble)value / 10.0);
	fjall.byggja();
	glutPostRedisplay();
}
void menuSol(int value) {
	if(value == 1) {
		sol->slokkva();
		glutChangeToMenuEntry(1, "verÃ°i ljÃ³s", 2);
	}
	else if(value == 2) {
		sol->kveikja();
		glutChangeToMenuEntry(1, "sÃ³lmyrkvi", 1);
	}
	glutPostRedisplay();
}
void menuSolAtt(int value) {
	switch(value) {
	case 1:
		sol->setjaAtt(value);
		break;
	case 2:
		sol->setjaAtt(value);
		break;
	case 3:
		sol->setjaAtt(value);
		break;
	case 4:
		sol->setjaAtt(value);
		break;
	case 5:
		sol->setjaAtt(value);
		break;
	case 6:
		sol->setjaAtt(value);
		break;
	case 7:
		sol->setjaAtt(value);
		break;
	case 8:
		sol->setjaAtt(value);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void menuSolHaed(int value) {
	sol->setjaHaed( ((GLdouble)value * PI) / 180.0 );
	glutPostRedisplay();
}
void menuNedriMork(int value) {
	int nuMynd = glutGetMenu();
	if(nuMynd == m1NedriMork) 
		fjall.setjaHaedBil1nedri((GLdouble)value);
	else if(nuMynd == m2NedriMork) 
		fjall.setjaHaedBil2nedri((GLdouble)value);
	else if(nuMynd == m3NedriMork) 
		fjall.setjaHaedBil3nedri((GLdouble)value);
	else if(nuMynd == mBergNedriMork) 
		fjall.setjaHaedBergnedri((GLdouble)value);
	fjall.byggja();
	glutPostRedisplay();
}
void menuEfriMork(int value) {
	int nuMynd = glutGetMenu();
	if(nuMynd == m1EfriMork) 
		fjall.setjaHaedBil1efri((GLdouble)value);
	else if(nuMynd == m2EfriMork) 
		fjall.setjaHaedBil2efri((GLdouble)value);
	else if(nuMynd == m3EfriMork) 
		fjall.setjaHaedBil3efri((GLdouble)value);
	else if(nuMynd == mBergEfriMork) 
		fjall.setjaHaedBergefri((GLdouble)value);
	fjall.byggja();
	glutPostRedisplay();
}
void menuNedriLiturR(int value) {
	int nuMynd = glutGetMenu();
	if(nuMynd == m1NedriLiturR)
		fjall.setjaLitiBil1nedriR(value);
	else if(nuMynd == m2NedriLiturR)
		fjall.setjaLitiBil2nedriR(value);
	else if(nuMynd == m3NedriLiturR)
		fjall.setjaLitiBil3nedriR(value);
	else if(nuMynd == mBergNedriLiturR)
		fjall.setjaLitiBergnedriR(value);
	fjall.byggja();
	glutPostRedisplay();
}
void menuEfriLiturR(int value) {
	int nuMynd = glutGetMenu();
	if(nuMynd == m1EfriLiturR)
		fjall.setjaLitiBil1efriR(value);
	else if(nuMynd == m2EfriLiturR)
		fjall.setjaLitiBil2efriR(value);
	else if(nuMynd == m3EfriLiturR)
		fjall.setjaLitiBil3efriR(value);
	else if(nuMynd == mBergEfriLiturR)
		fjall.setjaLitiBergefriR(value);
	fjall.byggja();
	glutPostRedisplay();
}
void menuNedriLiturG(int value) {
	int nuMynd = glutGetMenu();
	if(nuMynd == m1NedriLiturG)
		fjall.setjaLitiBil1nedriG(value);
	else if(nuMynd == m2NedriLiturG)
		fjall.setjaLitiBil2nedriG(value);
	else if(nuMynd == m3NedriLiturG)
		fjall.setjaLitiBil3nedriG(value);
	else if(nuMynd == mBergNedriLiturG)
		fjall.setjaLitiBergnedriG(value);
	fjall.byggja();
	glutPostRedisplay();
}
void menuEfriLiturG(int value) {
	int nuMynd = glutGetMenu();
	if(nuMynd == m1EfriLiturG)
		fjall.setjaLitiBil1efriG(value);
	else if(nuMynd == m2EfriLiturG)
		fjall.setjaLitiBil2efriG(value);
	else if(nuMynd == m3EfriLiturG)
		fjall.setjaLitiBil3efriG(value);
	else if(nuMynd == mBergEfriLiturG)
		fjall.setjaLitiBergefriG(value);
	fjall.byggja();
	glutPostRedisplay();
}
void menuNedriLiturB(int value) {
	int nuMynd = glutGetMenu();
	if(nuMynd == m1NedriLiturB)
		fjall.setjaLitiBil1nedriB(value);
	else if(nuMynd == m2NedriLiturB)
		fjall.setjaLitiBil2nedriB(value);
	else if(nuMynd == m3NedriLiturB)
		fjall.setjaLitiBil3nedriB(value);
	else if(nuMynd == mBergNedriLiturB)
		fjall.setjaLitiBergnedriB(value);
	fjall.byggja();
	glutPostRedisplay();
}
void menuEfriLiturB(int value) {
	int nuMynd = glutGetMenu();
	if(nuMynd == m1EfriLiturB)
		fjall.setjaLitiBil1efriB(value);
	else if(nuMynd == m2EfriLiturB)
		fjall.setjaLitiBil2efriB(value);
	else if(nuMynd == m3EfriLiturB)
		fjall.setjaLitiBil3efriB(value);
	else if(nuMynd == mBergEfriLiturB)
		fjall.setjaLitiBergefriB(value);
	fjall.byggja();
	glutPostRedisplay();
}
void menuSetlog(int value) {
	int nuMynd = glutGetMenu();
	if(nuMynd == m1Setlog) 
		fjall.setjaLogBil1(value);
	else if(nuMynd == m2Setlog) 
		fjall.setjaLogBil2(value);
	else if(nuMynd == m3Setlog) 
		fjall.setjaLogBil3(value);
	else if(nuMynd == mBergSetlog) 
		fjall.setjaLogBerg(value);
	fjall.byggja();
	glutPostRedisplay();
}
void menuHallathol(int value) {
	int nuMynd = glutGetMenu();
	if(nuMynd == m1Hallathol) {
		if(value == 111) {
			fjall.setjaKlisturBil1A();
			glutChangeToMenuEntry(1, "Taka af", 110);
		}
		else if(value == 110) {
			fjall.setjaKlisturBil1Af();
			glutChangeToMenuEntry(1, "Setja Ã¡", 111);
		}
		else {
			fjall.setjaKlisturBil1((GLdouble)value / 10.0);
			glutChangeToMenuEntry(1, "Taka af", 110);
		}
	}
	else if(nuMynd == m2Hallathol) {
		if(value == 111) {
			fjall.setjaKlisturBil2A();
			glutChangeToMenuEntry(1, "Taka af", 110);
		}
		else if(value == 110) {
			fjall.setjaKlisturBil2Af();
			glutChangeToMenuEntry(1, "Setja Ã¡", 111);
		}
		else {
			fjall.setjaKlisturBil2((GLdouble)value / 10.0);
			glutChangeToMenuEntry(1, "Taka af", 110);
		}
	}
	else if(nuMynd == m3Hallathol) {
		if(value == 111) {
			fjall.setjaKlisturBil3A();
			glutChangeToMenuEntry(1, "Taka af", 110);
		}
		else if(value == 110) {
			fjall.setjaKlisturBil3Af();
			glutChangeToMenuEntry(1, "Setja Ã¡", 111);
		}
		else {
			fjall.setjaKlisturBil3((GLdouble)value / 10.0);
			glutChangeToMenuEntry(1, "Taka af", 110);
		}
	}
	fjall.byggja();
	glutPostRedisplay();
}
void menuLitauppl(int value) {
	if(value == 1)
		fjall.upplBil1();
	else if(value == 2)
		fjall.upplBil2();
	else if(value == 3)
		fjall.upplBil3();
	else if(value == 4)
		fjall.upplBerg
		();
}
void menuEkkert(int value) {

}

// valmyndafï¿½ll enda


void init(void) {
	printf("orvatakkar til ad hreyfa i xz-plani (eda a,d,s,w) (shift til ad fara hradar),\n"
			"pageUp og pageDown til ad fara upp og nidur (eda q og e),\n"
			"hreyfa mus med vinstri takka nidri til ad hreyfa auga,\n"
			"og haegri smella til af fa stillingarmoguleika\n"
			"##############################################\n");

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	teikning = GL_FILL;
	
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	GLint svHorn[2] = {0, 0};
	GLint naHorn[2] = {50, -50};
	GLfloat floturLitur1[3] = {0.0, 0.0, 1.0};
	GLfloat floturLitur2[3] = {0.0, 1.0, 0.0};
	flotur.setja(svHorn, naHorn, 0, floturLitur1, floturLitur2);
	himinn.setja(svHorn, naHorn, 30, floturLitur2, floturLitur1);
	
	fjall.setjaStaerd(10.0);
	fjall.setjaStad(0.0, 0.0, 0.0);
	fjall.setjaUpplausn(0.05);

	bergLiturA[0] = 115.0/2.0; bergLiturA[1] = 112.0/2.0; bergLiturA[2] = 99.0/2.0;
	bergLiturB[0] = 162.0/2.0; bergLiturB[1] = 160.0/2.0; bergLiturB[2] = 145.0/2.0;

	litabil1A[0] = 99.0; litabil1A[1] = 133.0; litabil1A[2] = 40.0;
	litabil1B[0] = 135.0; litabil1B[1] = 139.0; litabil1B[2] = 29.0;
	litabil3A[0] = 255.0; litabil3A[1] = 255.0; litabil3A[2] = 255.0;
	litabil3B[0] = 255.0; litabil3B[1] = 255.0; litabil3B[2] = 255.0;
	litabil2A[0] = 115.0; litabil2A[1] = 112.0; litabil2A[2] = 99.0;
	litabil2B[0] = 162.0; litabil2B[1] = 160.0; litabil2B[2] = 145.0;
	fjall.setjaLitiBerg(bergLiturA, bergLiturB);
	fjall.setjaHaedBerg(0.0, 10.0);
	fjall.setjaLogBerg(30);
	fjall.setjaLitiBil1(litabil1A, litabil1B);
	fjall.setjaHaedBil1(0.0, 5.0);
	fjall.setjaLitiBil2(litabil2A, litabil2B);
	fjall.setjaHaedBil2(3.0, 8.0);
	fjall.setjaLogBil2(10);
	fjall.setjaKlisturBil2(1.0);
	fjall.setjaLitiBil3(litabil3A, litabil3B);
	fjall.setjaHaedBil3(5.0, 10.0);
	fjall.setjaLogBil3(1);
	fjall.setjaKlisturBil3(0.3);

	fjall.setjaRask(0.8);
	fjall.setjaSaedisSkekkju(1.0);

	fjall.byggja();

	auga.setja(0.0, 10.0);

	sol = new Sol();
	sol->setjaHaed(PI / 4.0);
	sol->setjaAtt(1);
 
}

void mouse(int button, int state, int x, int y) {

	auga.smella(button, state, x, y);
}

void motion( int x, int y ) {
	auga.snua(x, y);
	if((x >= 800))
		glutWarpPointer(x%800, y);
	if(x < 0)
		glutWarpPointer(800+x, y);
}

void hreyfa(int key, int x, int y) {
//	xStada = auga.faXstodu();
//	zStada = auga.faZstodu();
	auga.hreyfa(key, x, y, false, false);
}

void bokHreyfa(unsigned char key, int x, int y) {
//	xStada = auga.faXstodu();
//	zStada = auga.faZstodu();
	auga.bokHreyfa(key, x, y);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glPushMatrix();	
		auga.horfa();

		glPushMatrix();
			sol->setjaStad();
		glPopMatrix();

		glPolygonMode(GL_FRONT_AND_BACK, teikning);
		fjall.teikna();

//			glDisable(GL_LIGHTING);
		glDisableClientState(GL_NORMAL_ARRAY);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		flotur.teikna();
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		himinn.teikna();
		glEnableClientState(GL_NORMAL_ARRAY);
//			glEnable(GL_LIGHTING);

	glPopMatrix();
	glutSwapBuffers();
}



void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(45.0, (GLfloat) w/(GLfloat) h, 0.1, 300.0);
	glMatrixMode(GL_MODELVIEW);
}



int main (int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_ALPHA);
	glutInitWindowSize(800, 340); // 2,35:1
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rannsóknartól til að finna sannleiksgildi þeirrar staðhæfingar að fjöll mjókki upp.");


// ------------valmyndir

	char* buffer;
	int i;

	mLitauppl = glutCreateMenu(menuLitauppl);
		glutAddMenuEntry("Litur 1", 1);
		glutAddMenuEntry("Litur 2", 2);
		glutAddMenuEntry("Litur 3", 3);
		glutAddMenuEntry("Berglitur", 4);

	mBergSetlog = glutCreateMenu(menuSetlog);
		for(i = 1; i <= 40; i++) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
			mBergNedriLiturR = glutCreateMenu(menuNedriLiturR);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			mBergNedriLiturG = glutCreateMenu(menuNedriLiturG);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);

			mBergNedriLiturB = glutCreateMenu(menuNedriLiturB);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);

		mBergNedriLitur = glutCreateMenu(menuEkkert);
			glutAddSubMenu("R", mBergNedriLiturR);
			glutAddSubMenu("G", mBergNedriLiturG);
			glutAddSubMenu("B", mBergNedriLiturB);

			mBergEfriLiturR = glutCreateMenu(menuEfriLiturR);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			mBergEfriLiturG = glutCreateMenu(menuEfriLiturG);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			mBergEfriLiturB = glutCreateMenu(menuEfriLiturB);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
		mBergEfriLitur = glutCreateMenu(menuEkkert);
			glutAddSubMenu("R", mBergEfriLiturR);
			glutAddSubMenu("G", mBergEfriLiturG);
			glutAddSubMenu("B", mBergEfriLiturB);
		mBergEfriMork = glutCreateMenu(menuEfriMork);
			for(i = 0; i <= 15; i++) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
			for(i = 20; i <= 100; i +=10) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
		mBergNedriMork = glutCreateMenu(menuNedriMork);
			for(i = 0; i <= 15; i++) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
			for(i = 20; i <= 100; i +=10) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
	mBergLitur = glutCreateMenu(menuEkkert);
		glutAddSubMenu("Neðri mörk", mBergNedriMork);
		glutAddSubMenu("Efri mörk", mBergEfriMork);
		glutAddSubMenu("Neðri litur", mBergNedriLitur);
		glutAddSubMenu("Efri litur", mBergEfriLitur);
		glutAddSubMenu("Fjöldi setlaga", mBergSetlog);

	m3Hallathol = glutCreateMenu(menuHallathol);
		glutAddMenuEntry("Setja á", 111);
		for(i = 0; i <= 9; i++) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
		for(i = 10; i <= 100; i +=10) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
	m3Setlog = glutCreateMenu(menuSetlog);
		for(i = 1; i <= 40; i++) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
			m3NedriLiturR = glutCreateMenu(menuNedriLiturR);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			m3NedriLiturG = glutCreateMenu(menuNedriLiturG);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			m3NedriLiturB = glutCreateMenu(menuNedriLiturB);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
		m3NedriLitur = glutCreateMenu(menuEkkert);
			glutAddSubMenu("R", m3NedriLiturR);
			glutAddSubMenu("G", m3NedriLiturG);
			glutAddSubMenu("B", m3NedriLiturB);

			m3EfriLiturR = glutCreateMenu(menuEfriLiturR);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			m3EfriLiturG = glutCreateMenu(menuEfriLiturG);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			m3EfriLiturB = glutCreateMenu(menuEfriLiturB);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
		m3EfriLitur = glutCreateMenu(menuEkkert);
			glutAddSubMenu("R", m3EfriLiturR);
			glutAddSubMenu("G", m3EfriLiturG);
			glutAddSubMenu("B", m3EfriLiturB);
		m3EfriMork = glutCreateMenu(menuEfriMork);
			for(i = 0; i <= 15; i++) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
			for(i = 20; i <= 100; i +=10) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
		m3NedriMork = glutCreateMenu(menuNedriMork);
			for(i = 0; i <= 15; i++) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
			for(i = 20; i <= 100; i +=10) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
	m3Litur = glutCreateMenu(menuEkkert);
		glutAddSubMenu("Neðri mörk", m3NedriMork);
		glutAddSubMenu("Efri mörk", m3EfriMork);
		glutAddSubMenu("Neðri litur", m3NedriLitur);
		glutAddSubMenu("Efri litur", m3EfriLitur);
		glutAddSubMenu("Fjöldi setlaga", m3Setlog);
		glutAddSubMenu("Hallaþol", m3Hallathol);


	m2Hallathol = glutCreateMenu(menuHallathol);
		glutAddMenuEntry("Setja á", 111);
		for(i = 0; i <= 9; i++) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
		for(i = 10; i <= 100; i +=10) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
	m2Setlog = glutCreateMenu(menuSetlog);
		for(i = 1; i <= 40; i++) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
			m2NedriLiturR = glutCreateMenu(menuNedriLiturR);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			m2NedriLiturG = glutCreateMenu(menuNedriLiturG);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			m2NedriLiturB = glutCreateMenu(menuNedriLiturB);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);

		m2NedriLitur = glutCreateMenu(menuEkkert);
			glutAddSubMenu("R", m2NedriLiturR);
			glutAddSubMenu("G", m2NedriLiturG);
			glutAddSubMenu("B", m2NedriLiturB);

			m2EfriLiturR = glutCreateMenu(menuEfriLiturR);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			m2EfriLiturG = glutCreateMenu(menuEfriLiturG);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			m2EfriLiturB = glutCreateMenu(menuEfriLiturB);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
		m2EfriLitur = glutCreateMenu(menuEkkert);
			glutAddSubMenu("R", m2EfriLiturR);
			glutAddSubMenu("G", m2EfriLiturG);
			glutAddSubMenu("B", m2EfriLiturB);
		m2EfriMork = glutCreateMenu(menuEfriMork);
			for(i = 0; i <= 15; i++) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
			for(i = 20; i <= 100; i +=10) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
		m2NedriMork = glutCreateMenu(menuNedriMork);
			for(i = 0; i <= 15; i++) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
			for(i = 20; i <= 100; i +=10) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
	m2Litur = glutCreateMenu(menuEkkert);
		glutAddSubMenu("Neðri mörk", m2NedriMork);
		glutAddSubMenu("Efri mörk", m2EfriMork);
		glutAddSubMenu("Neðri litur", m2NedriLitur);
		glutAddSubMenu("Efri litur", m2EfriLitur);
		glutAddSubMenu("Fjöldi setlaga", m2Setlog);
		glutAddSubMenu("Hallaþol", m2Hallathol);



	m1Hallathol = glutCreateMenu(menuHallathol);
		glutAddMenuEntry("Setja á", 111);
		for(i = 0; i <= 9; i++) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
		for(i = 10; i <= 100; i +=10) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}

	m1Setlog = glutCreateMenu(menuSetlog);
		for(i = 1; i <= 40; i++) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
			m1NedriLiturR = glutCreateMenu(menuNedriLiturR);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			m1NedriLiturG = glutCreateMenu(menuNedriLiturG);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			m1NedriLiturB = glutCreateMenu(menuNedriLiturB);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);

		m1NedriLitur = glutCreateMenu(menuEkkert);

			glutAddSubMenu("R", m1NedriLiturR);
			glutAddSubMenu("G", m1NedriLiturG);
			glutAddSubMenu("B", m1NedriLiturB);

			m1EfriLiturR = glutCreateMenu(menuEfriLiturR);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);

			m1EfriLiturG = glutCreateMenu(menuEfriLiturG);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
			m1EfriLiturB = glutCreateMenu(menuEfriLiturB);
				for(i = 0; i <= 250; i +=10) {
					buffer = new char[1];
					sprintf(buffer,"%d",i);
					glutAddMenuEntry(buffer, i);
				}
				glutAddMenuEntry("255", 255);
		m1EfriLitur = glutCreateMenu(menuEkkert);
			glutAddSubMenu("R", m1EfriLiturR);
			glutAddSubMenu("G", m1EfriLiturG);
			glutAddSubMenu("B", m1EfriLiturB);
		m1EfriMork = glutCreateMenu(menuEfriMork);
			for(i = 0; i <= 15; i++) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
			for(i = 20; i <= 100; i +=10) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
		m1NedriMork = glutCreateMenu(menuNedriMork);
			for(i = 0; i <= 15; i++) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}
			for(i = 20; i <= 100; i +=10) {
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}

	m1Litur = glutCreateMenu(menuEkkert);
		glutAddSubMenu("Neðri mörk", m1NedriMork);
		glutAddSubMenu("Efri mörk", m1EfriMork);
		glutAddSubMenu("Neðri litur", m1NedriLitur);
		glutAddSubMenu("Efri litur", m1EfriLitur);
		glutAddSubMenu("Fjöldi setlaga", m1Setlog);
		glutAddSubMenu("Hallaþol", m1Hallathol);

		mSolAtt = glutCreateMenu(menuSolAtt);
			glutAddMenuEntry("Norður", 1);
			glutAddMenuEntry("NorðAustur", 2);
			glutAddMenuEntry("NorðVestur", 3);
			glutAddMenuEntry("Suður", 4);
			glutAddMenuEntry("SuðAustur", 5);
			glutAddMenuEntry("SuðVestur", 6);
			glutAddMenuEntry("Austur", 7);
			glutAddMenuEntry("Vestur", 8);
		mSolHaed = glutCreateMenu(menuSolHaed);
			for(i = 0; i <= 90; i += 10) {				
				buffer = new char[1];
				sprintf(buffer,"%d",i);
				glutAddMenuEntry(buffer, i);
			}			
	mSol = glutCreateMenu(menuSol);
		glutAddMenuEntry("Sólmyrkvi", 1);
		glutAddSubMenu("Átt", mSolAtt);
		glutAddSubMenu("Hæðargráða", mSolHaed);

	mHending = glutCreateMenu(menuHending);
		for(i = 0; i <= 10; i++) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
		for(i = 20; i <= 100; i += 10) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
	mRask = glutCreateMenu(menuRask);
		for(i = 0; i <= 10; i++) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
	mUpplausn = glutCreateMenu(menuUpplausn);
		for(i = 60; i >= 20; i -= 10) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
		for(i = 10; i >= 1; i--) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
		glutAddMenuEntry("0,5", 105);
		glutAddMenuEntry("0,4", 104);
		glutAddMenuEntry("0,3", 103);
		glutAddMenuEntry("0,2", 102);
		glutAddMenuEntry("0,1", 101);
	mStaerd = glutCreateMenu(menuStaerd);
		glutAddMenuEntry("5", 5);
		for(i = 10; i <= 100; i += 10) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
	mStadsetningZ = glutCreateMenu(menuStadsetning);
		for(i = 0; i <= 100; i += 10) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
	mStadsetningX = glutCreateMenu(menuStadsetning);
		for(i = 0; i <= 100; i += 10) {
			buffer = new char[1];
			sprintf(buffer,"%d",i);
			glutAddMenuEntry(buffer, i);
		}
	mStadsetning = glutCreateMenu(menuStadsetning);
		glutAddSubMenu("X", mStadsetningX);
		glutAddSubMenu("Z", mStadsetningZ);

	mAdal = glutCreateMenu(menuAdal);
		glutAddMenuEntry("Víramódel", 1);

		glutAddSubMenu("Staðsetning", mStadsetning);
		glutAddSubMenu("Stærð", mStaerd);
		glutAddSubMenu("Upplausn (% af stærð)", mUpplausn);
		glutAddSubMenu("Rask (hæð)", mRask);
		glutAddSubMenu("Hending", mHending);
		glutAddSubMenu("Sól", mSol);
		glutAddSubMenu("Litabil 1", m1Litur);
		glutAddSubMenu("Litabil 2", m2Litur);
		glutAddSubMenu("Litabil 3", m3Litur);
		glutAddSubMenu("Berglitur", mBergLitur);
		glutAddSubMenu("Litaupplýsingar", mLitauppl);
		glutAddMenuEntry("Loka valmynd", 2);

		glutAttachMenu(GLUT_RIGHT_BUTTON);


// ------------valmyndir enda


	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSetCursor(GLUT_CURSOR_NONE);
	glutSpecialFunc(hreyfa);
	glutKeyboardFunc(bokHreyfa);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutMainLoop();

	return 0;
}
