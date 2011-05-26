// Sol.h: interface for the Sol class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOL_H__6BC739D1_F0F4_11D2_B2A2_000000000000__INCLUDED_)
#define AFX_SOL_H__6BC739D1_F0F4_11D2_B2A2_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265359

class Sol  
{
public:
	Sol();
	virtual ~Sol();

	// tekur við gráðu í radíönum
	void setjaHaed(GLdouble gradur);

	// setur sólarátt, tekur við: 1,2,3,4,5,6,7,8 ,
	// þar sem röðin stendur fyrir: N,NA,NV,S,SA,SV,A,V
	void setjaAtt(int att);

	// glLightfv(...) með GL_POSITION
	void setjaStad();

	void kveikja();
	void slokkva();

private:
	GLfloat sol_hnit[4];
	GLfloat sol_diffuse[4];
	GLfloat sol_ambient[4];
	//GLfloat sol_diffuse[] = {0.8, 0.8, 0.8, 1.0};
	//GLfloat sol_ambient[] = {0.2, 0.2.0, 0.2, 1.0};
	GLfloat global_ambient[4];

	GLdouble haedarGrada;

};

#endif // !defined(AFX_SOL_H__6BC739D1_F0F4_11D2_B2A2_000000000000__INCLUDED_)
