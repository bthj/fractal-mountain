// Fjall.cpp: implementation of the Fjall class.
//
//////////////////////////////////////////////////////////////////////


#include "Fjall.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Fjall::Fjall() 
{
	litabil1a[0] = 128.0; litabil1a[1] = 128.0; litabil1a[2] = 128.0;
	litabil1aHaed = 100000.0;
	litabil1b[0] = 128.0; litabil1b[1] = 128.0; litabil1b[2] = 128.0; 
	litabil1bHaed = -1.0;
	litabil1Log = 1;
	litabil2a[0] = 128.0; litabil2a[1] = 128.0; litabil2a[2] = 128.0;
	litabil2aHaed = 100000.0;
	litabil2b[0] = 128.0; litabil2b[1] = 128.0; litabil2b[2] = 128.0; 
	litabil2bHaed = -1.0;
	litabil2Log = 1;
	litabil3a[0] = 128.0; litabil3a[1] = 128.0; litabil3a[2] = 128.0; 
	litabil3aHaed = 100000.0;
	litabil3b[0] = 128.0; litabil3b[1] = 128.0; litabil3b[2] = 128.0; 
	litabil3bHaed = -1.0;
	litabil3Log = 1;
	bergLiturA[0] = 128.0; bergLiturA[1] = 128.0; bergLiturA[2] = 128.0; 
	bergLiturAhaed = 100000.0;
	bergLiturB[0] = 128.0; bergLiturB[1] = 128.0; bergLiturB[2] = 128.0; 
	bergLiturBhaed = -1.0;
	bergLiturLog = 1;

	raskVeldi = 0.8;
	saedisSkekking = 1.0;

	maxLitagildi = 255.0;
}


Fjall::~Fjall()
{

}

void Fjall::setjaStaerd(GLdouble strd) {
	staerd = strd;
	setjaStad(fjallGrunnur[0][0],fjallGrunnur[0][1],fjallGrunnur[0][2]);
}

void Fjall::setjaStad(GLdouble xStad, GLdouble yStad, GLdouble zStad) {
	fjallGrunnur[0][0] = xStad;
	fjallGrunnur[0][1] = yStad;
	fjallGrunnur[0][2] = zStad;

	fjallGrunnur[1][0] = xStad + staerd;
	fjallGrunnur[1][1] = yStad;
	fjallGrunnur[1][2] = zStad;

	fjallGrunnur[2][0] = fjallGrunnur[0][0] + (staerd / 2.0);
	fjallGrunnur[2][1] = yStad;
	fjallGrunnur[2][2] = zStad - (tan(PI/3.0) * (staerd / 2.0));
}
void Fjall::setjaXstad(GLdouble x) {
	setjaStad(x, fjallGrunnur[0][1], fjallGrunnur[0][2]);
}
void Fjall::setjaZstad(GLdouble z) {
	setjaStad(fjallGrunnur[0][0], fjallGrunnur[0][1], z);
}

void Fjall::setjaUpplausn(GLdouble upplsn) {
	upplausn = staerd * upplsn;
}

void Fjall::setjaRask(GLdouble rask) {
	raskVeldi = rask;
}

void Fjall::setjaSaedisSkekkju(GLdouble saedisSkekkja) {
	saedisSkekking = saedisSkekkja;
}

void Fjall::setjaLitiBil1(GLdouble litur1[3], GLdouble litur2[3]) {
	litabil1a[0] = litur1[0];
	litabil1a[1] = litur1[1];
	litabil1a[2] = litur1[2];

	litabil1b[0] = litur2[0];
	litabil1b[1] = litur2[1];
	litabil1b[2] = litur2[2];
}
void Fjall::setjaLitiBil1nedriR(GLdouble litur1) {
	litabil1a[0] = litur1;
}
void Fjall::setjaLitiBil1nedriG(GLdouble litur1) {
	litabil1a[1] = litur1;
}
void Fjall::setjaLitiBil1nedriB(GLdouble litur1) {
	litabil1a[2] = litur1;
}
void Fjall::setjaLitiBil1efriR(GLdouble litur2) {
	litabil1b[0] = litur2;
}
void Fjall::setjaLitiBil1efriG(GLdouble litur2) {
	litabil1b[1] = litur2;
}
void Fjall::setjaLitiBil1efriB(GLdouble litur2) {
	litabil1b[2] = litur2;
}
void Fjall::setjaHaedBil1(GLdouble nedri, GLdouble efri) {
	litabil1aHaed = nedri;
	litabil1bHaed = efri;
}
void Fjall::setjaHaedBil1nedri(GLdouble nedri) {
	litabil1aHaed = nedri;
}
void Fjall::setjaHaedBil1efri(GLdouble efri) {
	litabil1bHaed = efri;
}
void Fjall::setjaLogBil1(int log) {
	litabil1Log = log;
}
void Fjall::setjaKlisturBil1(GLdouble klistur) {
	litabil1Klistur = klistur;
	litabil1KlisturOn = true;
}
void Fjall::setjaKlisturBil1A() {
	litabil1KlisturOn = true;
}
void Fjall::setjaKlisturBil1Af() {
	litabil1KlisturOn = false;
}

void Fjall::setjaLitiBil2(GLdouble litur1[3], GLdouble litur2[3]) {
	litabil2a[0] = litur1[0];
	litabil2a[1] = litur1[1];
	litabil2a[2] = litur1[2];

	litabil2b[0] = litur2[0];
	litabil2b[1] = litur2[1];
	litabil2b[2] = litur2[2];
}
void Fjall::setjaLitiBil2nedriR(GLdouble litur1) {
	litabil2a[0] = litur1;
}
void Fjall::setjaLitiBil2nedriG(GLdouble litur1) {
	litabil2a[1] = litur1;
}
void Fjall::setjaLitiBil2nedriB(GLdouble litur1) {
	litabil2a[2] = litur1;
}
void Fjall::setjaLitiBil2efriR(GLdouble litur2) {
	litabil2b[0] = litur2;
}
void Fjall::setjaLitiBil2efriG(GLdouble litur2) {
	litabil2b[1] = litur2;
}
void Fjall::setjaLitiBil2efriB(GLdouble litur2) {
	litabil2b[2] = litur2;
}
void Fjall::setjaHaedBil2(GLdouble nedri, GLdouble efri) {
	litabil2aHaed = nedri;
	litabil2bHaed = efri;
}
void Fjall::setjaHaedBil2nedri(GLdouble nedri) {
	litabil2aHaed = nedri;
}
void Fjall::setjaHaedBil2efri(GLdouble efri) {
	litabil2bHaed = efri;
}
void Fjall::setjaLogBil2(int log) {
	litabil2Log = log;
}
void Fjall::setjaKlisturBil2(GLdouble klistur) {
	litabil2Klistur = klistur;
	litabil2KlisturOn = true;
}
void Fjall::setjaKlisturBil2A() {
	litabil2KlisturOn = true;
}
void Fjall::setjaKlisturBil2Af() {
	litabil2KlisturOn = false;
}

void Fjall::setjaLitiBil3(GLdouble litur1[3], GLdouble litur2[3]) {
	litabil3a[0] = litur1[0];
	litabil3a[1] = litur1[1];
	litabil3a[2] = litur1[2];

	litabil3b[0] = litur2[0];
	litabil3b[1] = litur2[1];
	litabil3b[2] = litur2[2];
}
void Fjall::setjaLitiBil3nedriR(GLdouble litur1) {
	litabil3a[0] = litur1;
}
void Fjall::setjaLitiBil3nedriG(GLdouble litur1) {
	litabil3a[1] = litur1;
}
void Fjall::setjaLitiBil3nedriB(GLdouble litur1) {
	litabil3a[2] = litur1;
}
void Fjall::setjaLitiBil3efriR(GLdouble litur2) {
	litabil3b[0] = litur2;
}
void Fjall::setjaLitiBil3efriG(GLdouble litur2) {
	litabil3b[1] = litur2;
}
void Fjall::setjaLitiBil3efriB(GLdouble litur2) {
	litabil3b[2] = litur2;
}
void Fjall::setjaHaedBil3(GLdouble nedri, GLdouble efri) {
	litabil3aHaed = nedri;
	litabil3bHaed = efri;
}
void Fjall::setjaHaedBil3nedri(GLdouble nedri) {
	litabil3aHaed = nedri;
}
void Fjall::setjaHaedBil3efri(GLdouble efri) {
	litabil3bHaed = efri;
}
void Fjall::setjaLogBil3(int log) {
	litabil3Log = log;
}
void Fjall::setjaKlisturBil3(GLdouble klistur) {
	litabil3Klistur = klistur;
	litabil3KlisturOn = true;
}
void Fjall::setjaKlisturBil3A() {
	litabil3KlisturOn = true;
}
void Fjall::setjaKlisturBil3Af() {
	litabil3KlisturOn = false;
}

void Fjall::setjaLitiBerg(GLdouble litur1[3], GLdouble litur2[3]) {
	bergLiturA[0] = litur1[0];
	bergLiturA[1] = litur1[1];
	bergLiturA[2] = litur1[2];

	bergLiturB[0] = litur2[0];
	bergLiturB[1] = litur2[1];
	bergLiturB[2] = litur2[2];
}
void Fjall::setjaLitiBergnedriR(GLdouble litur1) {
	bergLiturA[0] = litur1;
}
void Fjall::setjaLitiBergnedriG(GLdouble litur1) {
	bergLiturA[1] = litur1;
}
void Fjall::setjaLitiBergnedriB(GLdouble litur1) {
	bergLiturA[2] = litur1;
}
void Fjall::setjaLitiBergefriR(GLdouble litur2) {
	bergLiturB[0] = litur2;
}
void Fjall::setjaLitiBergefriG(GLdouble litur2) {
	bergLiturB[1] = litur2;
}
void Fjall::setjaLitiBergefriB(GLdouble litur2) {
	bergLiturB[2] = litur2;
}
void Fjall::setjaHaedBerg(GLdouble nedri, GLdouble efri) {
	bergLiturAhaed = nedri;
	bergLiturBhaed = efri;
}
void Fjall::setjaHaedBergnedri(GLdouble nedri) {
	bergLiturAhaed = nedri;
}
void Fjall::setjaHaedBergefri(GLdouble efri) {
	bergLiturBhaed = efri;
}
void Fjall::setjaLogBerg(int log) {
	bergLiturLog = log;
}

void Fjall::byggja(void) {
		raunFjoldiFlata = 0;

	finnaFlatafjolda();
	delete [] fletir;
	// [fjoldiFlata][3][3] fylki
	fletir = new GLdouble[(fjoldiFlata*9)];
	delete [] flataLitir;
	flataLitir = new GLdouble[(fjoldiFlata*9)];
	delete [] flataNorm;
	flataNorm = new GLdouble[(fjoldiFlata*9)];

	nuFlotur = 0;
	hPunktur = fjallGrunnur[0][1];
	pudra(fjallGrunnur);

		printf("---------------\n");
		printf("Fjoldi flata: %d\n", raunFjoldiFlata);
		printf("Fjoldi reikn. flata: %d\n", fjoldiFlata);
		printf("Upplysingar um stadsetn. hnuta taka %d baeti, \n"
			"\tog uppl. um liti theirra annad eins\n", fjoldiFlata*9*4);
		printf("Dypt endurkvaemni: %d\n", dyptEndurkvaemni);
		printf("Haed fjalls: %f\n", hPunktur);
		printf("Rask: %f\n", raskVeldi);
		printf("Hending: %f\n", saedisSkekking);
		printf("---------------\n");
}

void Fjall::teikna(void) {
	glVertexPointer(3, GL_DOUBLE, 0, fletir);
	glColorPointer(3, GL_DOUBLE, 0, flataLitir);
	glNormalPointer(GL_DOUBLE, 0, flataNorm);
	glDrawArrays(GL_TRIANGLES, 0, (fjoldiFlata*3));
}


void Fjall::pudra(GLdouble flotur[3][3]) {
	int nuFloturinn = 0;
	GLdouble litur[3];
	GLdouble norm[3];
	if (noguFint(flotur)) {
		nuFloturinn = nuFlotur * 9;
		fletir[nuFloturinn] = flotur[0][0];
		fletir[nuFloturinn+1] = flotur[0][1];
		fletir[nuFloturinn+2] = flotur[0][2];
		fletir[nuFloturinn+3] = flotur[1][0];
		fletir[nuFloturinn+4] = flotur[1][1];
		fletir[nuFloturinn+5] = flotur[1][2];
		fletir[nuFloturinn+6] = flotur[2][0];
		fletir[nuFloturinn+7] = flotur[2][1];
		fletir[nuFloturinn+8] = flotur[2][2];
		// finn hæsta punkt fjallsins
		if(flotur[0][1] > hPunktur)
			hPunktur = flotur[0][1];
		if(flotur[1][1] > hPunktur)
			hPunktur = flotur[1][1];
		if(flotur[2][1] > hPunktur)
			hPunktur = flotur[2][1];
		// finn út lit allra punkta flatar
		finnaLit(flotur[0][1], flotur, litur);
		flataLitir[nuFloturinn] = litur[0];
		flataLitir[nuFloturinn+1] = litur[1];
		flataLitir[nuFloturinn+2] = litur[2];
		finnaLit(flotur[1][1], flotur, litur);
		flataLitir[nuFloturinn+3] = litur[0];
		flataLitir[nuFloturinn+4] = litur[1];
		flataLitir[nuFloturinn+5] = litur[2];
		finnaLit(flotur[2][1], flotur, litur);
		flataLitir[nuFloturinn+6] = litur[0];
		flataLitir[nuFloturinn+7] = litur[1];
		flataLitir[nuFloturinn+8] = litur[2];
		// finn út normalvektor allra punkta flatar
		finnaNormal(flotur, norm);
		flataNorm[nuFloturinn] = norm[0];
		flataNorm[nuFloturinn+1] = norm[1];
		flataNorm[nuFloturinn+2] = norm[2];
		flataNorm[nuFloturinn+3] = norm[0];
		flataNorm[nuFloturinn+4] = norm[1];
		flataNorm[nuFloturinn+5] = norm[2];
		flataNorm[nuFloturinn+6] = norm[0];
		flataNorm[nuFloturinn+7] = norm[1];
		flataNorm[nuFloturinn+8] = norm[2];
		nuFlotur++;
			raunFjoldiFlata++;
	}
	else {
		GLdouble flotur1[3][3];
		GLdouble flotur2[3][3];
		GLdouble flotur3[3][3];
		GLdouble flotur4[3][3];
		GLdouble hlid1[3][3];
		GLdouble hlid2[3][3];
		GLdouble hlid3[3][3];

		sneida(flotur, flotur1, flotur2, flotur3, flotur4,
					hlid1, hlid2, hlid3);

		nuFloturinn = nuFlotur * 9;
		fletir[nuFloturinn] = hlid1[0][0];
		fletir[nuFloturinn+1] = hlid1[0][1];
		fletir[nuFloturinn+2] = hlid1[0][2];
		fletir[nuFloturinn+3] = hlid1[1][0];
		fletir[nuFloturinn+4] = hlid1[1][1];
		fletir[nuFloturinn+5] = hlid1[1][2];
		fletir[nuFloturinn+6] = hlid1[2][0];
		fletir[nuFloturinn+7] = hlid1[2][1];
		fletir[nuFloturinn+8] = hlid1[2][2];
		// finn út lit allra punkta flatar
		finnaLit(hlid1[0][1], flotur, litur);
		flataLitir[nuFloturinn] = litur[0];
		flataLitir[nuFloturinn+1] = litur[1];
		flataLitir[nuFloturinn+2] = litur[2];
		finnaLit(hlid1[1][1], flotur, litur);
		flataLitir[nuFloturinn+3] = litur[0];
		flataLitir[nuFloturinn+4] = litur[1];
		flataLitir[nuFloturinn+5] = litur[2];
		finnaLit(hlid1[2][1], flotur, litur);
		flataLitir[nuFloturinn+6] = litur[0];
		flataLitir[nuFloturinn+7] = litur[1];
		flataLitir[nuFloturinn+8] = litur[2];
		// finn út normalvektor allra punkta flatar
		finnaNormal(hlid1, norm);
		flataNorm[nuFloturinn] = norm[0];
		flataNorm[nuFloturinn+1] = norm[1];
		flataNorm[nuFloturinn+2] = norm[2];
		flataNorm[nuFloturinn+3] = norm[0];
		flataNorm[nuFloturinn+4] = norm[1];
		flataNorm[nuFloturinn+5] = norm[2];
		flataNorm[nuFloturinn+6] = norm[0];
		flataNorm[nuFloturinn+7] = norm[1];
		flataNorm[nuFloturinn+8] = norm[2];
		nuFlotur++;
			raunFjoldiFlata++;

		nuFloturinn = nuFlotur * 9;
		fletir[nuFloturinn] = hlid2[0][0];
		fletir[nuFloturinn+1] = hlid2[0][1];
		fletir[nuFloturinn+2] = hlid2[0][2];
		fletir[nuFloturinn+3] = hlid2[1][0];
		fletir[nuFloturinn+4] = hlid2[1][1];
		fletir[nuFloturinn+5] = hlid2[1][2];
		fletir[nuFloturinn+6] = hlid2[2][0];
		fletir[nuFloturinn+7] = hlid2[2][1];
		fletir[nuFloturinn+8] = hlid2[2][2];
		// finn út lit allra punkta flatar
		finnaLit(hlid2[0][1], flotur, litur);
		flataLitir[nuFloturinn] = litur[0];
		flataLitir[nuFloturinn+1] = litur[1];
		flataLitir[nuFloturinn+2] = litur[2];
		finnaLit(hlid2[1][1], flotur, litur);
		flataLitir[nuFloturinn+3] = litur[0];
		flataLitir[nuFloturinn+4] = litur[1];
		flataLitir[nuFloturinn+5] = litur[2];
		finnaLit(hlid2[2][1], flotur, litur);
		flataLitir[nuFloturinn+6] = litur[0];
		flataLitir[nuFloturinn+7] = litur[1];
		flataLitir[nuFloturinn+8] = litur[2];
		// finn út normalvektor allra punkta flatar
		finnaNormal(hlid2, norm);
		flataNorm[nuFloturinn] = norm[0];
		flataNorm[nuFloturinn+1] = norm[1];
		flataNorm[nuFloturinn+2] = norm[2];
		flataNorm[nuFloturinn+3] = norm[0];
		flataNorm[nuFloturinn+4] = norm[1];
		flataNorm[nuFloturinn+5] = norm[2];
		flataNorm[nuFloturinn+6] = norm[0];
		flataNorm[nuFloturinn+7] = norm[1];
		flataNorm[nuFloturinn+8] = norm[2];
		nuFlotur++;
			raunFjoldiFlata++;

		nuFloturinn = nuFlotur * 9;
		fletir[nuFloturinn] = hlid3[0][0];
		fletir[nuFloturinn+1] = hlid3[0][1];
		fletir[nuFloturinn+2] = hlid3[0][2];
		fletir[nuFloturinn+3] = hlid3[1][0];
		fletir[nuFloturinn+4] = hlid3[1][1];
		fletir[nuFloturinn+5] = hlid3[1][2];
		fletir[nuFloturinn+6] = hlid3[2][0];
		fletir[nuFloturinn+7] = hlid3[2][1];
		fletir[nuFloturinn+8] = hlid3[2][2];
		// finn út lit allra punkta flatar
		finnaLit(hlid3[0][1], flotur, litur);
		flataLitir[nuFloturinn] = litur[0];
		flataLitir[nuFloturinn+1] = litur[1];
		flataLitir[nuFloturinn+2] = litur[2];
		finnaLit(hlid3[1][1], flotur, litur);
		flataLitir[nuFloturinn+3] = litur[0];
		flataLitir[nuFloturinn+4] = litur[1];
		flataLitir[nuFloturinn+5] = litur[2];
		finnaLit(hlid3[2][1], flotur, litur);
		flataLitir[nuFloturinn+6] = litur[0];
		flataLitir[nuFloturinn+7] = litur[1];
		flataLitir[nuFloturinn+8] = litur[2];
		// finn út normalvektor allra punkta flatar
		finnaNormal(hlid3, norm);
		flataNorm[nuFloturinn] = norm[0];
		flataNorm[nuFloturinn+1] = norm[1];
		flataNorm[nuFloturinn+2] = norm[2];
		flataNorm[nuFloturinn+3] = norm[0];
		flataNorm[nuFloturinn+4] = norm[1];
		flataNorm[nuFloturinn+5] = norm[2];
		flataNorm[nuFloturinn+6] = norm[0];
		flataNorm[nuFloturinn+7] = norm[1];
		flataNorm[nuFloturinn+8] = norm[2];
		nuFlotur++;
			raunFjoldiFlata++;

		pudra(flotur1);
		pudra(flotur2);
		pudra(flotur3);
		pudra(flotur4);
	}
}


void Fjall::sneida(GLdouble flotur[3][3], 
				GLdouble flotur1[3][3], GLdouble flotur2[3][3],
				GLdouble flotur3[3][3], GLdouble flotur4[3][3],
				GLdouble hlid1[3][3], GLdouble hlid2[3][3], GLdouble hlid3[3][3]) 
{
	// miðpunktar á örmum þríhyrningsflatar
	GLdouble v1v2[3];
	GLdouble v2v3[3];
	GLdouble v3v1[3];

	// staðsetning miðpunktanna reiknuð út
	v1v2[0] = ((flotur[0][0] + flotur[1][0]) / 2.0);
	v1v2[2] = ((flotur[0][2] + flotur[1][2]) / 2.0);
		srand( (unsigned)abs((int)((v1v2[0]+v1v2[2])/2.0)*saedisSkekking) );
		// ef ekki þetta auka kall á rand, þá hækkar fjallið ekki
		//	...veit ekki alveg af hverju :-/
		// ...þarf ekki ef srand köllum er sleppt...
		rand();
	v1v2[1] = ((flotur[0][1] + flotur[1][1]) / 2.0) +
		( rask(sqrt(pow(flotur[1][0]-flotur[0][0], 2.0) +
			pow(flotur[1][2]-flotur[0][2], 2.0))) * 
		((double)rand() / (double)RAND_MAX) );

	v2v3[0] = ((flotur[1][0] + flotur[2][0]) / 2.0);
	v2v3[2] = ((flotur[1][2] + flotur[2][2]) / 2.0);
		srand( (unsigned)abs((int)((v2v3[0]+v2v3[2])/2.0)*saedisSkekking) );
		rand();
	v2v3[1] = ((flotur[1][1] + flotur[2][1]) / 2.0) +
		( rask(sqrt(pow(flotur[2][0]-flotur[1][0], 2.0) +
			pow(flotur[2][2]-flotur[1][2], 2.0))) * 
		((double)rand() / (double)RAND_MAX) );

	v3v1[0] = ((flotur[2][0] + flotur[0][0]) / 2.0);
	v3v1[2] = ((flotur[2][2] + flotur[0][2]) / 2.0);
		srand( (unsigned)abs((int)((v3v1[0]+v3v1[2])/2.0)*saedisSkekking) );
		rand();
	v3v1[1] = ((flotur[2][1] + flotur[0][1]) / 2.0) +
		( rask(sqrt(pow(flotur[0][0]-flotur[2][0], 2.0) +
			pow(flotur[0][2]-flotur[2][2], 2.0))) * 
		((double)rand() / (double)RAND_MAX) );

	// fjórir nýir fletir og þrjár lóðréttar hliðar að þeim sett
	flotur1[0][0] = flotur[0][0];
	flotur1[0][1] = flotur[0][1];
	flotur1[0][2] = flotur[0][2];
	flotur1[1][0] = v1v2[0];
	flotur1[1][1] = v1v2[1];
	flotur1[1][2] = v1v2[2];
	flotur1[2][0] = v3v1[0];
	flotur1[2][1] = v3v1[1];
	flotur1[2][2] = v3v1[2];

	flotur2[0][0] = v3v1[0];
	flotur2[0][1] = v3v1[1];
	flotur2[0][2] = v3v1[2];
	flotur2[1][0] = v1v2[0];
	flotur2[1][1] = v1v2[1];
	flotur2[1][2] = v1v2[2];
	flotur2[2][0] = v2v3[0];
	flotur2[2][1] = v2v3[1];
	flotur2[2][2] = v2v3[2];

	flotur3[0][0] = v1v2[0];
	flotur3[0][1] = v1v2[1];
	flotur3[0][2] = v1v2[2];
	flotur3[1][0] = flotur[1][0];
	flotur3[1][1] = flotur[1][1];
	flotur3[1][2] = flotur[1][2];
	flotur3[2][0] = v2v3[0];
	flotur3[2][1] = v2v3[1];
	flotur3[2][2] = v2v3[2];

	flotur4[0][0] = v3v1[0];
	flotur4[0][1] = v3v1[1];
	flotur4[0][2] = v3v1[2];
	flotur4[1][0] = v2v3[0];
	flotur4[1][1] = v2v3[1];
	flotur4[1][2] = v2v3[2];
	flotur4[2][0] = flotur[2][0];
	flotur4[2][1] = flotur[2][1];
	flotur4[2][2] = flotur[2][2];

	hlid1[0][0] = flotur[0][0];
	hlid1[0][1] = flotur[0][1];
	hlid1[0][2] = flotur[0][2];
	hlid1[1][0] = flotur[1][0];
	hlid1[1][1] = flotur[1][1];
	hlid1[1][2] = flotur[1][2];
	hlid1[2][0] = v1v2[0];
	hlid1[2][1] = v1v2[1];
	hlid1[2][2] = v1v2[2];

	hlid2[0][0] = flotur[1][0];
	hlid2[0][1] = flotur[1][1];
	hlid2[0][2] = flotur[1][2];
	hlid2[1][0] = flotur[2][0];
	hlid2[1][1] = flotur[2][1];
	hlid2[1][2] = flotur[2][2];
	hlid2[2][0] = v2v3[0];
	hlid2[2][1] = v2v3[1];
	hlid2[2][2] = v2v3[2];

	hlid3[0][0] = flotur[2][0];
	hlid3[0][1] = flotur[2][1];
	hlid3[0][2] = flotur[2][2];
	hlid3[1][0] = flotur[0][0];
	hlid3[1][1] = flotur[0][1];
	hlid3[1][2] = flotur[0][2];
	hlid3[2][0] = v3v1[0];
	hlid3[2][1] = v3v1[1];
	hlid3[2][2] = v3v1[2];
}

GLdouble Fjall::rask(GLdouble gildi) {
	return pow(gildi, raskVeldi);
}

bool Fjall::noguFint(GLdouble flotur[3][3]) {
	// er hlið þríhyrningsflatar, varpað í xz-plan,
	//	lengri en upplausnarþröskuldur?
	if( sqrt(pow(flotur[1][0]-flotur[0][0], 2.0) + 
			pow(flotur[1][2]-flotur[0][2], 2.0)) > upplausn )
		return false;
	else
		return true;
}

void Fjall::finnaFlatafjolda() {
	nuFlotur = 0;

	dyptEndurkvaemni = 0;
	//	n = fjöldi helmingana á grunnfleti, eða 
	//			dýpt endurkvæmni

	// fjöldi lóðréttra (burðar) þríhyrninga:
	//	f(0) = 3
	//	f(n) = 4^n * 3 + f(n-1)
	int fn = 0;
	for(GLdouble i = staerd; i > upplausn; i /= 2.0) {
		fn = (pow(4, dyptEndurkvaemni) * 3) + fn;
		dyptEndurkvaemni++;
	}

	// fjöldi (annarra) liggjandi þrýhyrninga:
	//	4^(n+1)
	int lagFletir = pow(4, dyptEndurkvaemni);

	// þríhyrningsfletir alls:
	fjoldiFlata = fn + lagFletir;
}

GLdouble Fjall::finnaHalla(GLdouble flotur[3][3]) {
	GLdouble laVektor[] = {1.0, 0.0, 0.0};
	GLdouble hallaVektor[3];
	GLdouble halli;
	GLdouble maxHnutur[3], minHnutur[3];

	if(flotur[0][1] < flotur[1][1]) {
		if(flotur[1][1] < flotur[2][1]) {
			maxHnutur[0] = flotur[2][0];
			maxHnutur[1] = flotur[2][1];
			maxHnutur[2] = flotur[2][2];
		}
		else {
			maxHnutur[0] = flotur[1][0];
			maxHnutur[1] = flotur[1][1];
			maxHnutur[2] = flotur[1][2];
		}
	}
	else {
		if(flotur[0][1] < flotur[2][1]) {
			maxHnutur[0] = flotur[2][0];
			maxHnutur[1] = flotur[2][1];
			maxHnutur[2] = flotur[2][2];
		}
		else {
			maxHnutur[0] = flotur[0][0];
			maxHnutur[1] = flotur[0][1];
			maxHnutur[2] = flotur[0][2];
		}
	}

	if(flotur[0][1] > flotur[1][1]) {
		if(flotur[1][1] > flotur[2][1]) {
			minHnutur[0] = flotur[2][0];
			minHnutur[1] = flotur[2][1];
			minHnutur[2] = flotur[2][2];
		}
		else {
			minHnutur[0] = flotur[1][0];
			minHnutur[1] = flotur[1][1];
			minHnutur[2] = flotur[1][2];
		}
	}
	else {
		if(flotur[0][1] > flotur[2][1]) {
			minHnutur[0] = flotur[2][0];
			minHnutur[1] = flotur[2][1];
			minHnutur[2] = flotur[2][2];
		}
		else {
			minHnutur[0] = flotur[0][0];
			minHnutur[1] = flotur[0][1];
			minHnutur[2] = flotur[0][2];
		}
	}

	hallaVektor[0] = fabs(maxHnutur[0] - minHnutur[0]);
	hallaVektor[1] = fabs(maxHnutur[1] - minHnutur[1]);
	hallaVektor[2] = fabs(maxHnutur[2] - minHnutur[2]);

	halli = acos(
					( (laVektor[0]*hallaVektor[0]) + 
						(laVektor[1]*hallaVektor[1]) + 
						(laVektor[2]*hallaVektor[2])
					)
					/
					( sqrt( (hallaVektor[0]*hallaVektor[0]) + 
							(hallaVektor[1]*hallaVektor[1]) + 
							(hallaVektor[2]*hallaVektor[2]) 
						)
						* 
						sqrt( (laVektor[0]*laVektor[0]) + 
								(laVektor[1]*laVektor[1]) + 
								(laVektor[2]*laVektor[2])
						) 
					)
				);

	if(halli < 0.0)
		halli = halftPI;

	return halli / halftPI;

}

void Fjall::finnaLit(GLdouble haed, GLdouble flotur[3][3], GLdouble litur[3]) {
	litur[0] = 0.0; litur[1] = 0.0; litur[2] = 0.0;
	GLdouble litur1[3] = {0.0,0.0,0.0};
	GLdouble litur2[3] = {0.0,0.0,0.0};
	GLdouble litur3[3] = {0.0,0.0,0.0};
	GLdouble bergLitur[3];

	if( !((haed >= litabil1aHaed) && (haed <= litabil1bHaed)) &&
		!((haed >= litabil2aHaed) && (haed <= litabil2bHaed)) &&
		!((haed >= litabil3aHaed) && (haed <= litabil3bHaed)) ) {
		// flötur fellur ekki innan neins litabils
		finnaBergLit(haed, bergLitur);
		litur[0] = bergLitur[0];
		litur[1] = bergLitur[1];
		litur[2] = bergLitur[2];
	}
	else {
		GLdouble hlutfallA, hlutfallB;
		GLdouble locA, locB;
		GLdouble locBilLengd;
		int lagNr;
		GLdouble hallaHlutf = finnaHalla(flotur);
		GLdouble tmpHallaHlutf;

		// er punktur innan litabil1?
		if( (haed >= litabil1aHaed) && (haed <= litabil1bHaed) ) {
			locB = litabil1aHaed;
			locBilLengd = (litabil1bHaed - litabil1aHaed) / (GLdouble)litabil1Log;
			lagNr = 0;
			// finn innan hvaða lags punktur er
			for(int i = 0; i < litabil1Log; i++) {
				locA = locB;
				locB += locBilLengd;
				if( (haed >= locA) && (haed <= locB) ) {
					lagNr = i + 1;
					break;
				}
			}

			hlutfallA =  (locB-haed) / (locB-locA);
			hlutfallB =  (haed-locA) / (locB-locA);

			if(lagNr % 2) {
				litur1[0] += (hlutfallA * litabil1a[0]);
				litur1[1] += (hlutfallA * litabil1a[1]);
				litur1[2] += (hlutfallA * litabil1a[2]);

				litur1[0] += (hlutfallB * litabil1b[0]);
				litur1[1] += (hlutfallB * litabil1b[1]);
				litur1[2] += (hlutfallB * litabil1b[2]);
			}
			else {
				litur1[0] += (hlutfallB * litabil1a[0]);
				litur1[1] += (hlutfallB * litabil1a[1]);
				litur1[2] += (hlutfallB * litabil1a[2]);

				litur1[0] += (hlutfallA * litabil1b[0]);
				litur1[1] += (hlutfallA * litabil1b[1]);
				litur1[2] += (hlutfallA * litabil1b[2]);
			}
			if(litabil1KlisturOn) {
				finnaBergLit(haed, bergLitur);
				tmpHallaHlutf = pow((1.0 - hallaHlutf), litabil1Klistur);

				litur1[0] *= tmpHallaHlutf;
				litur1[1] *= tmpHallaHlutf;
				litur1[2] *= tmpHallaHlutf;
				bergLitur[0] *= (1.0 - tmpHallaHlutf);
				bergLitur[1] *= (1.0 - tmpHallaHlutf);
				bergLitur[2] *= (1.0 - tmpHallaHlutf);
				litur1[0] = litur1[0] + bergLitur[0];
				litur1[1] = litur1[1] + bergLitur[1];
				litur1[2] = litur1[2] + bergLitur[2];
			}
		}
		// er punktur innan litabil2?
		if( (haed >= litabil2aHaed) && (haed <= litabil2bHaed) ) {
			locB = litabil2aHaed;
			locBilLengd = (litabil2bHaed - litabil2aHaed) / (GLdouble)litabil2Log;
			lagNr = 0;
			for(int i = 0; i < litabil2Log; i++) {
				locA = locB;
				locB += locBilLengd;
				if( (haed >= locA) && (haed <= locB) ) {
					lagNr = i + 1;
					break;
				}
			}

			hlutfallA =  (locB-haed) / (locB-locA);
			hlutfallB =  (haed-locA) / (locB-locA);

			if(lagNr % 2) {
				litur2[0] += (hlutfallA * litabil2a[0]);
				litur2[1] += (hlutfallA * litabil2a[1]);
				litur2[2] += (hlutfallA * litabil2a[2]);
				
				litur2[0] += (hlutfallB * litabil2b[0]);
				litur2[1] += (hlutfallB * litabil2b[1]);
				litur2[2] += (hlutfallB * litabil2b[2]);
			}
			else {
				litur2[0] += (hlutfallB * litabil2a[0]);
				litur2[1] += (hlutfallB * litabil2a[1]);
				litur2[2] += (hlutfallB * litabil2a[2]);
				
				litur2[0] += (hlutfallA * litabil2b[0]);
				litur2[1] += (hlutfallA * litabil2b[1]);
				litur2[2] += (hlutfallA * litabil2b[2]);
			}
			if(litabil2KlisturOn) {
				finnaBergLit(haed, bergLitur);
				tmpHallaHlutf = pow((1.0 - hallaHlutf), litabil2Klistur);

				litur2[0] *= tmpHallaHlutf;
				litur2[1] *= tmpHallaHlutf;
				litur2[2] *= tmpHallaHlutf;
				bergLitur[0] *= (1.0 - tmpHallaHlutf);
				bergLitur[1] *= (1.0 - tmpHallaHlutf);
				bergLitur[2] *= (1.0 - tmpHallaHlutf);
				litur2[0] = litur2[0] + bergLitur[0];
				litur2[1] = litur2[1] + bergLitur[1];
				litur2[2] = litur2[2] + bergLitur[2];
			}

		}
		// er punktur innan litabil3?
		if( (haed >= litabil3aHaed) && (haed <= litabil3bHaed) ) {
			locB = litabil3aHaed;
			locBilLengd = (litabil3bHaed - litabil3aHaed) / (GLdouble)litabil3Log;
			lagNr = 0;
			for(int i = 0; i < litabil3Log; i++) {
				locA = locB;
				locB += locBilLengd;
				if( (haed >= locA) && (haed <= locB) ) {
					lagNr = i + 1;
					break;
				}
			}

			hlutfallA =  (locB-haed) / (locB-locA);
			hlutfallB =  (haed-locA) / (locB-locA);

			if(lagNr % 2) {
				litur3[0] += (hlutfallA * litabil3a[0]);
				litur3[1] += (hlutfallA * litabil3a[1]);
				litur3[2] += (hlutfallA * litabil3a[2]);

				litur3[0] += (hlutfallB * litabil3b[0]);
				litur3[1] += (hlutfallB * litabil3b[1]);
				litur3[2] += (hlutfallB * litabil3b[2]);
			}
			else {
				litur3[0] += (hlutfallB * litabil3a[0]);
				litur3[1] += (hlutfallB * litabil3a[1]);
				litur3[2] += (hlutfallB * litabil3a[2]);

				litur3[0] += (hlutfallA * litabil3b[0]);
				litur3[1] += (hlutfallA * litabil3b[1]);
				litur3[2] += (hlutfallA * litabil3b[2]);

			}
			if(litabil3KlisturOn) {
				finnaBergLit(haed, bergLitur);
				tmpHallaHlutf = pow((1.0 - hallaHlutf), litabil3Klistur);

				litur3[0] *= tmpHallaHlutf;
				litur3[1] *= tmpHallaHlutf;
				litur3[2] *= tmpHallaHlutf;
				bergLitur[0] *= (1.0 - tmpHallaHlutf);
				bergLitur[1] *= (1.0 - tmpHallaHlutf);
				bergLitur[2] *= (1.0 - tmpHallaHlutf);
				litur3[0] = litur3[0] + bergLitur[0];
				litur3[1] = litur3[1] + bergLitur[1];
				litur3[2] = litur3[2] + bergLitur[2];
			}
		}

		// ef litabilin skarast...
		if( (haed >= litabil2aHaed) && (haed <= litabil1bHaed) ) {
			hlutfallA =  (litabil1bHaed-haed) / (litabil1bHaed-litabil2aHaed);
			hlutfallB =  (haed-litabil2aHaed) / (litabil1bHaed-litabil2aHaed);

			litur1[0] = (hlutfallA * litur1[0]);
			litur1[1] = (hlutfallA * litur1[1]);
			litur1[2] = (hlutfallA * litur1[2]);

			litur2[0] = (hlutfallB * litur2[0]);
			litur2[1] = (hlutfallB * litur2[1]);
			litur2[2] = (hlutfallB * litur2[2]);	
		}
		if( (haed >= litabil3aHaed) && (haed <= litabil2bHaed) ) {

			hlutfallA =  (litabil2bHaed-haed) / (litabil2bHaed-litabil3aHaed);
			hlutfallB =  (haed-litabil3aHaed) / (litabil2bHaed-litabil3aHaed);

			litur2[0] = (hlutfallA * litur2[0]);
			litur2[1] = (hlutfallA * litur2[1]);
			litur2[2] = (hlutfallA * litur2[2]);

			litur3[0] = (hlutfallB * litur3[0]);
			litur3[1] = (hlutfallB * litur3[1]);
			litur3[2] = (hlutfallB * litur3[2]);	
		}
		if( (haed >= litabil3aHaed) && (haed <= litabil1bHaed) ) {

			hlutfallA =  (litabil1bHaed-haed) / (litabil1bHaed-litabil3aHaed);
			hlutfallB =  (haed-litabil3aHaed) / (litabil1bHaed-litabil3aHaed);

			litur1[0] = (hlutfallA * litur1[0]);
			litur1[1] = (hlutfallA * litur1[1]);
			litur1[2] = (hlutfallA * litur1[2]);

			litur3[0] = (hlutfallB * litur3[0]);
			litur3[1] = (hlutfallB * litur3[1]);
			litur3[2] = (hlutfallB * litur3[2]);
		}

		// legg litagildi saman
		litur[0] = litur1[0] + litur2[0] + litur3[0];
		litur[1] = litur1[1] + litur2[1] + litur3[1];
		litur[2] = litur1[2] + litur2[2] + litur3[2];
	}
	// klemmi litagildi innan bilsins [0.0, 0.1] (í réttum hlutf.)
	if(maxLitagildi > 255.01)
		printf("%f;", maxLitagildi);
	litur[0] /= maxLitagildi;
	litur[1] /= maxLitagildi;
	litur[2] /= maxLitagildi;
}

void Fjall::finnaBergLit(GLdouble haed, GLdouble litur[3]) {
	litur[0] = 0.0; litur[1] = 0.0; litur[2] = 0.0;

	if( !((haed >= bergLiturAhaed) && (haed <= bergLiturBhaed)) ) {
		// flötur fellur ekki innan berglitabils
		litur[0] = 128.0; litur[1] = 128.0; litur[2] = 128.0;
	}
	else { // flötur er innan berglitabils
		GLdouble hlutfallA, hlutfallB;
		GLdouble locA, locB;
		GLdouble locBilLengd;
		int lagNr;

		locB = bergLiturAhaed;
		locBilLengd = (bergLiturBhaed - bergLiturAhaed) / (GLdouble)bergLiturLog;
		lagNr = 0;
		// finn innan hvaða lags punktur er
		for(int i = 0; i < bergLiturLog; i++) {
			locA = locB;
			locB += locBilLengd;
			if( (haed >= locA) && (haed <= locB) ) {
				lagNr = i + 1;
				break;
			}
		}

		hlutfallA =  (locB-haed) / (locB-locA);
		hlutfallB =  (haed-locA) / (locB-locA);

		if(lagNr % 2) {
			litur[0] += (hlutfallA * bergLiturA[0]);
			litur[1] += (hlutfallA * bergLiturA[1]);
			litur[2] += (hlutfallA * bergLiturA[2]);

			litur[0] += (hlutfallB * bergLiturB[0]);
			litur[1] += (hlutfallB * bergLiturB[1]);
			litur[2] += (hlutfallB * bergLiturB[2]);
		}
		else {
			litur[0] += (hlutfallB * bergLiturA[0]);
			litur[1] += (hlutfallB * bergLiturA[1]);
			litur[2] += (hlutfallB * bergLiturA[2]);

			litur[0] += (hlutfallA * bergLiturB[0]);
			litur[1] += (hlutfallA * bergLiturB[1]);
			litur[2] += (hlutfallA * bergLiturB[2]);
		}
	}
}

void Fjall::finnaNormal(GLdouble flotur[3][3], GLdouble norm[3]) {
	GLdouble v1[3], v2[3];

	for(int i=0; i < 3; i++) {
		v1[i] = flotur[0][i] - flotur[1][i];
		v2[i] = flotur[1][i] - flotur[2][i];
	}

	norm[0] = (v1[1]*v2[2]) - (v1[2]*v2[1]);
	norm[1] = (v1[2]*v2[0]) - (v1[0]*v2[2]);
	norm[2] = (v1[0]*v2[1]) - (v1[1]*v2[0]);
	
	GLdouble d = sqrt((norm[0]*norm[0])+(norm[1]*norm[1])+(norm[2]*norm[2]));
	norm[0] /= d; norm[1] /= d; norm[2] /= d;
}

void Fjall::upplBil1() {
	printf("Litabil 1:\n"
			"\tNedri mork: %f, Efri mork: %f\n"
			"\tNedri litur: R: %f, G: %f, B: %f\n" 
			"\tEfri litur: R: %f, G: %f, B: %f\n"
			"\tFjoldi setlaga: %d\n"
			"\tHallathol: %f\n", 
			litabil1aHaed, litabil1bHaed,
			litabil1a[0], litabil1a[1], litabil1a[2], 
			litabil1b[0], litabil1b[1], litabil1b[2], 
			litabil1Log, litabil1Klistur);
}
void Fjall::upplBil2() {
	printf("Litabil 2:\n"
			"\tNedri mork: %f, Efri mork: %f\n"
			"\tNedri litur: R: %f, G: %f, B: %f\n" 
			"\tEfri litur: R: %f, G: %f, B: %f\n"
			"\tFjoldi setlaga: %d\n"
			"\tHallathol: %f\n", 
			litabil2aHaed, litabil2bHaed,
			litabil2a[0], litabil2a[1], litabil2a[2], 
			litabil2b[0], litabil2b[1], litabil2b[2], 
			litabil2Log, litabil2Klistur);
}
void Fjall::upplBil3() {
	printf("Litabil 3:\n"
			"\tNedri mork: %f, Efri mork: %f\n"
			"\tNedri litur: R: %f, G: %f, B: %f\n" 
			"\tEfri litur: R: %f, G: %f, B: %f\n"
			"\tFjoldi setlaga: %d\n"
			"\tHallathol: %f\n", 
			litabil3aHaed, litabil3bHaed,
			litabil3a[0], litabil3a[1], litabil3a[2], 
			litabil3b[0], litabil3b[1], litabil3b[2], 
			litabil3Log, litabil3Klistur);
}
void Fjall::upplBerg() {
	printf("Berglitur:\n"
			"\tNedri mork: %f, Efri mork: %f\n"
			"\tNedri litur: R: %f, G: %f, B: %f\n" 
			"\tEfri litur: R: %f, G: %f, B: %f\n"
			"\tFjoldi setlaga: %d\n",
			bergLiturAhaed, bergLiturBhaed,
			bergLiturA[0], bergLiturA[1], bergLiturA[2], 
			bergLiturB[0], bergLiturB[1], bergLiturB[2], 
			bergLiturLog);
}