// Flotur.cpp: implementation of the Flotur class.
//
//////////////////////////////////////////////////////////////////////


#include "Flotur.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Flotur::Flotur()
{

}

Flotur::~Flotur()
{

}

void Flotur::setja(GLint sv[], GLint na[], GLint haed, GLfloat upphLitur[], GLfloat endaLitur[]){
	horn[0] = sv[0]; horn[1] = haed; horn[2] = sv[1];
	horn[3] = na[0]; horn[4] = haed; horn[5] = sv[1];
	horn[6] = na[0]; horn[7] = haed; horn[8] = na[1];
	horn[9] = sv[0]; horn[10] = haed; horn[11] = na[1];

	litir[0] = upphLitur[0]; litir[1] = upphLitur[1]; litir[2] = upphLitur[2];
	litir[3] = endaLitur[0]; litir[4] = endaLitur[1]; litir[5] = endaLitur[2];
	litir[6] = upphLitur[0]; litir[7] = upphLitur[1]; litir[8] = upphLitur[2];
	litir[9] = endaLitur[0]; litir[10] = endaLitur[1]; litir[11] = endaLitur[2];
}

void Flotur::teikna(void) {
	glColorPointer(3, GL_FLOAT, 0, litir);
	glVertexPointer(3, GL_INT, 0, horn);
	glDrawArrays(GL_QUADS, 0, 4);
}