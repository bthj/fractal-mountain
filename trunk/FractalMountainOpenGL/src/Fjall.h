// Fjall.h: interface for the Fjall class.
//
// ***** A�fer�ir *****
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FJALL_H__B5593886_EC2C_11D2_B29C_000000000000__INCLUDED_)
#define AFX_FJALL_H__B5593886_EC2C_11D2_B29C_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define halftPI 1.570796326795

class Fjall  
{
public:
	Fjall();
	virtual ~Fjall();

	// ATH. st�r� fjallsins ver�ur a� vera sett ��ur en 
	//	�a� er sta�sett

	// setur lengd (jafn)hli�a �r�hyrnds grunnflatar fjallsins
	void setjaStaerd(GLdouble strd);

	// sta�setur (x,y,z) sv-horn (m.v. -z s� N) fjalls, og
	//	b�r til �r�hyrndan jafnhli�a grunnfl�t �t fr� ��ur
	//	skilgreindri st�r�.
	void setjaStad(GLdouble xStad, GLdouble yStad, GLdouble zStad);

	void setjaXstad(GLdouble x);
	void setjaZstad(GLdouble z);

	// setur upplausn fjallsins sem % af hli�arl. grunnflatarins
	void setjaUpplausn(GLdouble upplsn);

	// setur truflun � uppleypingu fjalls (h��)
	void setjaRask(GLdouble rask);

	// setur margf�ldunart�lu til a� skekkja s��i sem er nota�
	//	vi� upphleyping �r�hyrningsflata
	void setjaSaedisSkekkju(GLdouble saedisSkekkja);

	// setur upphafs- og endalit (efri og ne�ri) litabils 1,
	//	RGB gildi � bilinu 0 - 255
	void setjaLitiBil1(GLdouble litur1[3], GLdouble litur2[3]);
	void setjaLitiBil1nedriR(GLdouble litur1);
	void setjaLitiBil1nedriG(GLdouble litur1);
	void setjaLitiBil1nedriB(GLdouble litur1);
	void setjaLitiBil1efriR(GLdouble litur2);
	void setjaLitiBil1efriG(GLdouble litur2);
	void setjaLitiBil1efriB(GLdouble litur2);
	// setur ne�ri og efri h��arm�rk (y) litabils 1
	void setjaHaedBil1(GLdouble nedri, GLdouble efri);
	void setjaHaedBil1nedri(GLdouble nedri);
	void setjaHaedBil1efri(GLdouble efri);
	// setur fj�lda (set)laga � litabili 1
	void setjaLogBil1(int log);
	// setur veldist�lu sem hefur �hrif � hve vel jar�vegur(litur)
	//	tollir � halla.  Litur �ekur alla fleti ef 0.0,
	//	l�nulegt samband milli halla flatar og bl�ndunar berglitar
	//	og jar�vegslitar ef 1.0, eftir �v� sem veldi h�kkar upp fr� �v�
	//	takmarkast jar�vegslitur meir vi� l�r�tta fleti.
	void setjaKlisturBil1(GLdouble klistur);
	// setur hallareikning �
	void setjaKlisturBil1A();
	// tekur hallareikning af
	void setjaKlisturBil1Af();

	void setjaLitiBil2(GLdouble litur1[3], GLdouble litur2[3]);
	void setjaLitiBil2nedriR(GLdouble litur1);
	void setjaLitiBil2nedriG(GLdouble litur1);
	void setjaLitiBil2nedriB(GLdouble litur1);
	void setjaLitiBil2efriR(GLdouble litur2);
	void setjaLitiBil2efriG(GLdouble litur2);
	void setjaLitiBil2efriB(GLdouble litur2);
	void setjaHaedBil2(GLdouble nedri, GLdouble efri);
	void setjaHaedBil2nedri(GLdouble nedri);
	void setjaHaedBil2efri(GLdouble efri);
	void setjaLogBil2(int log);
	void setjaKlisturBil2(GLdouble klistur);
	void setjaKlisturBil2A();
	void setjaKlisturBil2Af();

	void setjaLitiBil3(GLdouble litur1[3], GLdouble litur2[3]);
	void setjaLitiBil3nedriR(GLdouble litur1);
	void setjaLitiBil3nedriG(GLdouble litur1);
	void setjaLitiBil3nedriB(GLdouble litur1);
	void setjaLitiBil3efriR(GLdouble litur2);
	void setjaLitiBil3efriG(GLdouble litur2);
	void setjaLitiBil3efriB(GLdouble litur2);
	void setjaHaedBil3(GLdouble nedri, GLdouble efri);
	void setjaHaedBil3nedri(GLdouble nedri);
	void setjaHaedBil3efri(GLdouble efri);
	void setjaLogBil3(int log);
	void setjaKlisturBil3(GLdouble klistur);
	void setjaKlisturBil3A();
	void setjaKlisturBil3Af();

	void setjaLitiBerg(GLdouble litur1[3], GLdouble litur2[3]);
	void setjaLitiBergnedriR(GLdouble litur1);
	void setjaLitiBergnedriG(GLdouble litur1);
	void setjaLitiBergnedriB(GLdouble litur1);
	void setjaLitiBergefriR(GLdouble litur2);
	void setjaLitiBergefriG(GLdouble litur2);
	void setjaLitiBergefriB(GLdouble litur2);
	void setjaHaedBerg(GLdouble nedri, GLdouble efri);
	void setjaHaedBergnedri(GLdouble nedri);
	void setjaHaedBergefri(GLdouble efri);
	void setjaLogBerg(int log);

	// prenta uppl�singar um liti
	void upplBil1();
	void upplBil2();
	void upplBil3();
	void upplBerg();

	// tekur fr� pl�ss fyrir fjallshnit og
	//	liti �eirra, og setur byggingu �ess af sta�.
	void byggja(void);
	
	void teikna(void);


private:
	// hnit � [i][0..2] eru � x, y, z r��, og punktar i
	// skr��ir rangs�lis um �r�hyrninginn
	GLdouble fjallGrunnur[3][3];
	GLdouble staerd;
	GLdouble upplausn;
	GLdouble raskVeldi;  // veldistala sem r��ur truflun � upphleypingu fjalls
	GLdouble saedisSkekking; // marfeldi � s��i notu�u vi� upphleypingu flata
	int fjoldiFlata;
	int raunFjoldiFlata;
	int dyptEndurkvaemni;

	GLdouble* fletir; // fylki undir �ll hnit allra flata
	GLdouble* flataLitir; // fylki undir liti allra hn�ta allra flata
	GLdouble* flataNorm;  // fylki normal vektora allra hn�ta allra flata

	int nuFlotur;  //teljari sem pudra() notar
	GLdouble maxLitagildi;
	GLdouble hPunktur; // h�� fjallsins

	// 3 litabil � tilteknum h��arbilum fyrir !l��r�tta fleti,
	//	og eitt litabil � tilteknu h��arbili fyrir berglit
	GLdouble litabil1a[3];
	GLdouble litabil1aHaed;
	GLdouble litabil1b[3];
	GLdouble litabil1bHaed;
	// veldisttala sem hefur �hrif � hve vel jar�vegur(litur)
	GLdouble litabil1Klistur;  // tollir � halla.
	bool litabil1KlisturOn;  // er hallareikningur virkur?
	int litabil1Log; // fj�ldi (set)laga � litabili
	GLdouble litabil2a[3];
	GLdouble litabil2aHaed;
	GLdouble litabil2b[3];
	GLdouble litabil2bHaed;
	GLdouble litabil2Klistur;
	bool litabil2KlisturOn;
	int litabil2Log;
	GLdouble litabil3a[3];
	GLdouble litabil3aHaed;
	GLdouble litabil3b[3];
	GLdouble litabil3bHaed;
	GLdouble litabil3Klistur;
	bool litabil3KlisturOn;
	int litabil3Log;
	GLdouble bergLiturA[3];
	GLdouble bergLiturAhaed;
	GLdouble bergLiturB[3];
	GLdouble bergLiturBhaed;
	int bergLiturLog;

	// b�r til hnit �r�h.flata fjalls
	void pudra(GLdouble flotur[3][3]);
	
	// b�r til fj�ra �r�hrningsfleti, hvern � s�nu plani skv.
	//	�kv. slembiheg�un, innan marka gefins �r�hyrningsflatar,
	//	og �rj� l��r�tta �r�h.fleti a� �eim
	// Ath. skiptir upp flotur[3][3] og skilar ni�urst��u �
	//	flotur?[3][3] og hlid?[3][3]
	void sneida(GLdouble flotur[3][3], 
					GLdouble flotur1[3][3], GLdouble flotur2[3][3],
					GLdouble flotur3[3][3], GLdouble flotur4[3][3],
					GLdouble hlid1[3][3], GLdouble hlid2[3][3], GLdouble hlid3[3][3]);

	// gefur gildi �t fr� gefnu gildi (truflun)
	GLdouble rask(GLdouble gildi);

	// �kve�ur hvort gefinn �r�hyrningsfl�tur s�
	//	innan upplausnarmarka
	bool noguFint(GLdouble flotur[3][3]);

	// reiknar �t fj�lda flata sem koma til me� a� ver�a
	// b�nir til, svo h�gt s� a� b�a til fylki af r�ttir st�r�
	void finnaFlatafjolda();

	// finnur hallahlutfall flatarins: 1.0 == l��r�tt
	GLdouble finnaHalla(GLdouble flotur[3][3]);

	// finnur lit �t fr� gefnu h��argildi (y), og
	//	gefnum �r�hyrningsfleti
	//	(finnur lit � litabilum sem h��arpunkturinn er innan
	//	og blandar litagildum ef punkturinn er innan > 1 litabils)
	// Ath. tekur vi� haed og skilar lit � litur[3]
	//	sem gildum � bilinu [0.0, 1.0]
	void finnaLit(GLdouble haed, GLdouble flotur[3][3], GLdouble litur[3]);

	// finnur lit l��r�tts (hli�ar)flatar �t fr� gefnu h��argildi(y).
	//	Ath. tekur vi� haed og skilar lit � litur[3]
	//	sem gildum � bilinu [0.0, 255.0]
	void finnaBergLit(GLdouble haed, GLdouble litur[3]);

	// finnur normalvektor gefins flatar (� normalformi)
	//	Ath. skilar ni�urst��u � norm[3]
	void finnaNormal(GLdouble flotur[3][3], GLdouble norm[3]);

};

#endif // !defined(AFX_FJALL_H__B5593886_EC2C_11D2_B29C_000000000000__INCLUDED_)
