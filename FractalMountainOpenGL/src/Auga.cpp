// Auga.cpp: implementation of the Auga class.
//
//////////////////////////////////////////////////////////////////////


#include "Auga.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Auga::Auga()
{
	xzHorn = -PI / 2;
	xyHorn = 0.0;
	xzDX = cos(xzHorn);
	xzDZ = sin(xzHorn);
	xyDY = sin(xyHorn);

	yStada = 1.0;
	yMagn = 0.3;
}

Auga::~Auga()
{

}

void Auga::setja(GLdouble x, GLdouble z) {
	xStada = x;
	zStada = z;

}

void Auga::setjaMus(int x, int y) {
	preMusX = x;
	preMusY = y;
}
 
void Auga::horfa(void) {
	gluLookAt(xStada, yStada, zStada, 
		xStada+xzDX, yStada+xyDY, zStada+xzDZ, 
		0.0, 1.0, 0.0);
}

void Auga::smella(int button, int state, int x, int y) {
	 if (state == GLUT_DOWN) {
		preMusX = x;
		preMusY = y;
	 }
}

void Auga::snua(int x, int y) {
	xzHorn += ((x - preMusX) / PI40);
	xyHornTemp = xyHorn + ((preMusY - y) / PI40);
	// -halftPI < xyHorn < halftPI
	if(fabs(xyHornTemp) < halftPI)
		xyHorn = xyHornTemp;
	preMusX = x;
	preMusY = y;
	xzDX = cos(xzHorn);
	xzDZ = sin(xzHorn);
	xyDY = sin(xyHorn); 
	glutPostRedisplay();
}

void Auga::hreyfa(int key, int x, int y, bool nordurSudur, bool austurVestur) {
	if(!austurVestur)
		preXstada = xStada;
	if(!nordurSudur)
		preZstada = zStada;
	if(glutGetModifiers() == GLUT_ACTIVE_SHIFT) {
		zMagn = xzDZ / 2;
		xMagn = xzDX / 2;
	}
	else {
		zMagn = xzDZ / 4;
		xMagn = xzDX / 4;
	}
	switch(key) {
	case GLUT_KEY_UP:
		if(!nordurSudur)
			zStada += zMagn;
		else
			zStada = preZstada;
		if(!austurVestur)
			xStada += xMagn;
		else
			xStada = preXstada;
		break;
	case GLUT_KEY_DOWN:
		if(!nordurSudur)
			zStada -= zMagn;
		else
			zStada = preZstada;
		if(!austurVestur)
			xStada -= xMagn;
		else
			xStada = preXstada;
		break;
	case GLUT_KEY_RIGHT:
		if(!nordurSudur)
			zStada += xMagn;
		else
			zStada = preZstada;
		if(!austurVestur)
			xStada += (-zMagn);
		else
			xStada = preXstada;
		break; 
	case GLUT_KEY_LEFT:
		if(!nordurSudur)
			zStada += (-xMagn);
		else
			zStada = preZstada;
		if(!austurVestur)
			xStada += zMagn;
		else
			xStada = preXstada;
		break;
	case GLUT_KEY_PAGE_UP:
		yStada += yMagn;
		break;
	case GLUT_KEY_PAGE_DOWN:
		yStada -= yMagn;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void Auga::bokHreyfa(char key, int x, int y) {
	if(glutGetModifiers() == GLUT_ACTIVE_SHIFT) {
		zMagn = xzDZ / 2;
		xMagn = xzDX / 2;
	}
	else {
		zMagn = xzDZ / 4;
		xMagn = xzDX / 4;
	}
	switch(key) {
	case 'w':
			zStada += zMagn;
			xStada += xMagn;
		break;
	case 's':
			zStada -= zMagn;
			xStada -= xMagn;
		break;
	case 'd':
			zStada += xMagn;
			xStada += (-zMagn);

		break; 
	case 'a':
			zStada += (-xMagn);
			xStada += zMagn;
		break;
	case 'e':
		yStada += yMagn;
		break;
	case 'q':
		yStada -= yMagn;
		break;
	default:
		break;
	}
	glutPostRedisplay();	
}

GLdouble Auga::faXstodu() {
	return xStada;
}

GLdouble Auga::faZstodu() {
	return zStada;
}