// Flotur.h: interface for the Flotur class.
//
// Smíði: sv og na GLint[2] hnit sem staðsetja horn á hornalínu
//	flatarins í xz-plani, upphLitur og endaLitur GLfloat[3] gildi
// sem gefa upphafs og endalit flatarins.
//
// ***** AÐGERÐIR *****
// void teikna(); --> teiknar flötinn
// void setja(sv[], na[], upphLitur[], endaLitur[]) -->
//   sv og na GLint[2] hnit sem staðsetja horn á hornalínu
//	 flatarins í xz-plani, upphLitur og endaLitur GLfloat[3] gildi
//   sem gefa upphafs og endalit flatarins.
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLOTUR_H__95E480A4_D3D3_11D2_B282_000000000000__INCLUDED_)
#define AFX_FLOTUR_H__95E480A4_D3D3_11D2_B282_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <GL/glut.h>

class Flotur  
{
public:
	Flotur();
	virtual ~Flotur();

	void setja(GLint sv[], GLint na[], GLint haed, GLfloat upphLitur[], GLfloat endaLitur[]);
	void teikna(void);

private:
	GLint horn[12];
	GLfloat litir[12];

};

#endif // !defined(AFX_FLOTUR_H__95E480A4_D3D3_11D2_B282_000000000000__INCLUDED_)
