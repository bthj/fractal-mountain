// Auga.h: interface for the Auga class.
//
//  ***** A�FER�IR *****
// void setja(x, y)  --> sta�setur auga � xz-plani
// void horfa()  --> setur sj�narhorn eftir sj�narhornsg�gnum augans
// void snua(x, y) --> snyr auganu me� m�sarhreyfingu
// void smella(button, x, y) --> setur sta�sten. m�sarb. vi� m�sarsmell
// void hreyfa(key, x,  y, nordurSudur, austurVestur) --> hreyfir auga� 
//		eftir �rvalyklasl�tti, skilyrt eftir hvort rekist var �
//		nor�ur-, su�ur-, austur- e�a vesturvegg
// GLdouble faXstodu() --> skilar x st��u auga
// GLdouble faZstodu() --> skilar z st��u auga
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
	GLdouble xStada, zStada;  // xz sta�setning auga
	GLdouble yStada; // y stada auga
	GLdouble preXstada, preZstada;  // geymir s��ustu xz st��u
	GLdouble xzHorn;  // sj�narhorn � xz-plani
	GLdouble xzDX, xzDZ; // sj�narhorns vektor � xz-plani
	GLdouble xyHorn;  // sj�narhorn � xy-plani
	GLdouble xyHornTemp;
	GLdouble xyDY; // sj�narhorns vektor � xy-plani
	int preMusX, preMusY;  // xy skj�gildi m�sar vi� s��ustu hreyfingu
	GLdouble xMagn, zMagn; // skrefast�r� auga � xz-plani
	GLdouble yMagn; // skrefast�r� � y

};

#endif // !defined(AFX_AUGA_H__95E480A3_D3D3_11D2_B282_000000000000__INCLUDED_)
