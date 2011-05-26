// Auga.h: interface for the Auga class.
//
//  ***** AÐFERÐIR *****
// void setja(x, y)  --> staðsetur auga í xz-plani
// void horfa()  --> setur sjónarhorn eftir sjónarhornsgögnum augans
// void snua(x, y) --> snyr auganu með músarhreyfingu
// void smella(button, x, y) --> setur staðsten. músarb. við músarsmell
// void hreyfa(key, x,  y, nordurSudur, austurVestur) --> hreyfir augað 
//		eftir örvalyklaslætti, skilyrt eftir hvort rekist var á
//		norður-, suður-, austur- eða vesturvegg
// GLdouble faXstodu() --> skilar x stöðu auga
// GLdouble faZstodu() --> skilar z stöðu auga
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUGA_H__95E480A3_D3D3_11D2_B282_000000000000__INCLUDED_)
#define AFX_AUGA_H__95E480A3_D3D3_11D2_B282_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define halftPI 1.570796326795
#define PI 3.14159265359
#define PI40 125.6637061436

class Auga  
{
public:
	Auga();
	virtual ~Auga();

	void setja(GLdouble x, GLdouble z);
	void setjaMus(int x, int y);
	void horfa(void);
	void smella(int button, int state, int x, int y);
	void snua(int x, int y);
	void hreyfa(int key, int x, int y, bool nordurSudur, bool austurVestur);
	void bokHreyfa(char key, int x, int y);
	GLdouble faXstodu();
	GLdouble faZstodu();

private:
	GLdouble xStada, zStada;  // xz staðsetning auga
	GLdouble yStada; // y stada auga
	GLdouble preXstada, preZstada;  // geymir síðustu xz stöðu
	GLdouble xzHorn;  // sjónarhorn í xz-plani
	GLdouble xzDX, xzDZ; // sjónarhorns vektor í xz-plani
	GLdouble xyHorn;  // sjónarhorn í xy-plani
	GLdouble xyHornTemp;
	GLdouble xyDY; // sjónarhorns vektor í xy-plani
	int preMusX, preMusY;  // xy skjágildi músar við síðustu hreyfingu
	GLdouble xMagn, zMagn; // skrefastærð auga í xz-plani
	GLdouble yMagn; // skrefastærð í y

};

#endif // !defined(AFX_AUGA_H__95E480A3_D3D3_11D2_B282_000000000000__INCLUDED_)
