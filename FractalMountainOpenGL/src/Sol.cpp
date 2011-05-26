// Sol.cpp: implementation of the Sol class.
//
//////////////////////////////////////////////////////////////////////

#include "Sol.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Sol::Sol()
{
	sol_hnit[0] = 0.0;
	sol_hnit[1] = 1000.0;
	sol_hnit[2] = -1000.0;
	sol_hnit[3] = 1.0;
	
	sol_diffuse[0] = 0.725;
	sol_diffuse[1] = 0.706;
	sol_diffuse[2] = 0.647;
	sol_diffuse[3] = 1.0;

	sol_ambient[0] = 0.725/1.3;
	sol_ambient[1] = 0.706/1.3;
	sol_ambient[2] = 0.647/1.3;
	sol_ambient[3] = 1.0;

	global_ambient[0] = 0.0;
	global_ambient[1] = 0.0;
	global_ambient[2] = 0.0;
	global_ambient[3] = 1.0;

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
//	glLightfv(GL_LIGHT0, GL_POSITION, sol_hnit);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, sol_diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, sol_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	haedarGrada = PI / 4.0;
}

Sol::~Sol()
{

}


void Sol::setjaHaed(GLdouble gradur) {
	GLdouble xzLengd = sqrt((sol_hnit[0]*sol_hnit[0])+(sol_hnit[2]*sol_hnit[2]));

	sol_hnit[1] = tan(gradur) * xzLengd;

	haedarGrada = gradur;
}

void Sol::setjaAtt(int att) {

	switch(att) {
	case 1:
		sol_hnit[0] = 0.0;
		sol_hnit[2] = -1000.0;
		break;
	case 2:
		sol_hnit[0] = 1000.0;
		sol_hnit[2] = -1000.0;
		break;
	case 3:
		sol_hnit[0] = -1000.0;
		sol_hnit[2] = -1000.0;
		break;
	case 4:
		sol_hnit[0] = 0.0;
		sol_hnit[2] = 1000.0;
		break;
	case 5:
		sol_hnit[0] = 1000.0;
		sol_hnit[2] = 1000.0;
		break;
	case 6:
		sol_hnit[0] = -1000.0;
		sol_hnit[2] = 1000.0;
		break;
	case 7:
		sol_hnit[0] = 1000.0;
		sol_hnit[2] = 0.0;
		break;
	case 8:
		sol_hnit[0] = -1000.0;
		sol_hnit[2] = 0.0;
		break;
	default:
		sol_hnit[0] = 0.0;
		sol_hnit[2] = 1000.0;
		break;
	}
	setjaHaed(haedarGrada);
}

void Sol::setjaStad() {
	glLightfv(GL_LIGHT0, GL_POSITION, sol_hnit);
}

void Sol::kveikja() {
	glEnable(GL_LIGHTING);
}
void Sol::slokkva() {
	glDisable(GL_LIGHTING);
}
