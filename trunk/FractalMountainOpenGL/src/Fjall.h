// Fjall.h: interface for the Fjall class.
//
// ***** Aðferðir *****
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

	// ATH. stærð fjallsins verður að vera sett áður en 
	//	það er staðsett

	// setur lengd (jafn)hliða þrýhyrnds grunnflatar fjallsins
	void setjaStaerd(GLdouble strd);

	// staðsetur (x,y,z) sv-horn (m.v. -z sé N) fjalls, og
	//	býr til þrýhyrndan jafnhliða grunnflöt út frá áður
	//	skilgreindri stærð.
	void setjaStad(GLdouble xStad, GLdouble yStad, GLdouble zStad);

	void setjaXstad(GLdouble x);
	void setjaZstad(GLdouble z);

	// setur upplausn fjallsins sem % af hliðarl. grunnflatarins
	void setjaUpplausn(GLdouble upplsn);

	// setur truflun í uppleypingu fjalls (hæð)
	void setjaRask(GLdouble rask);

	// setur margföldunartölu til að skekkja sæði sem er notað
	//	við upphleyping þríhyrningsflata
	void setjaSaedisSkekkju(GLdouble saedisSkekkja);

	// setur upphafs- og endalit (efri og neðri) litabils 1,
	//	RGB gildi á bilinu 0 - 255
	void setjaLitiBil1(GLdouble litur1[3], GLdouble litur2[3]);
	void setjaLitiBil1nedriR(GLdouble litur1);
	void setjaLitiBil1nedriG(GLdouble litur1);
	void setjaLitiBil1nedriB(GLdouble litur1);
	void setjaLitiBil1efriR(GLdouble litur2);
	void setjaLitiBil1efriG(GLdouble litur2);
	void setjaLitiBil1efriB(GLdouble litur2);
	// setur neðri og efri hæðarmörk (y) litabils 1
	void setjaHaedBil1(GLdouble nedri, GLdouble efri);
	void setjaHaedBil1nedri(GLdouble nedri);
	void setjaHaedBil1efri(GLdouble efri);
	// setur fjölda (set)laga á litabili 1
	void setjaLogBil1(int log);
	// setur veldistölu sem hefur áhrif á hve vel jarðvegur(litur)
	//	tollir í halla.  Litur þekur alla fleti ef 0.0,
	//	línulegt samband milli halla flatar og blöndunar berglitar
	//	og jarðvegslitar ef 1.0, eftir því sem veldi hækkar upp frá því
	//	takmarkast jarðvegslitur meir við lárétta fleti.
	void setjaKlisturBil1(GLdouble klistur);
	// setur hallareikning á
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

	// prenta upplýsingar um liti
	void upplBil1();
	void upplBil2();
	void upplBil3();
	void upplBerg();

	// tekur frá pláss fyrir fjallshnit og
	//	liti þeirra, og setur byggingu þess af stað.
	void byggja(void);
	
	void teikna(void);


private:
	// hnit í [i][0..2] eru í x, y, z röð, og punktar i
	// skráðir rangsælis um þríhyrninginn
	GLdouble fjallGrunnur[3][3];
	GLdouble staerd;
	GLdouble upplausn;
	GLdouble raskVeldi;  // veldistala sem ræður truflun í upphleypingu fjalls
	GLdouble saedisSkekking; // marfeldi á sæði notuðu við upphleypingu flata
	int fjoldiFlata;
	int raunFjoldiFlata;
	int dyptEndurkvaemni;

	GLdouble* fletir; // fylki undir öll hnit allra flata
	GLdouble* flataLitir; // fylki undir liti allra hnúta allra flata
	GLdouble* flataNorm;  // fylki normal vektora allra hnúta allra flata

	int nuFlotur;  //teljari sem pudra() notar
	GLdouble maxLitagildi;
	GLdouble hPunktur; // hæð fjallsins

	// 3 litabil á tilteknum hæðarbilum fyrir !lóðrétta fleti,
	//	og eitt litabil á tilteknu hæðarbili fyrir berglit
	GLdouble litabil1a[3];
	GLdouble litabil1aHaed;
	GLdouble litabil1b[3];
	GLdouble litabil1bHaed;
	// veldisttala sem hefur áhrif á hve vel jarðvegur(litur)
	GLdouble litabil1Klistur;  // tollir í halla.
	bool litabil1KlisturOn;  // er hallareikningur virkur?
	int litabil1Log; // fjöldi (set)laga á litabili
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

	// býr til hnit þríh.flata fjalls
	void pudra(GLdouble flotur[3][3]);
	
	// býr til fjóra þríhrningsfleti, hvern í sínu plani skv.
	//	ákv. slembihegðun, innan marka gefins þríhyrningsflatar,
	//	og þrjá lóðrétta þríh.fleti að þeim
	// Ath. skiptir upp flotur[3][3] og skilar niðurstöðu í
	//	flotur?[3][3] og hlid?[3][3]
	void sneida(GLdouble flotur[3][3], 
					GLdouble flotur1[3][3], GLdouble flotur2[3][3],
					GLdouble flotur3[3][3], GLdouble flotur4[3][3],
					GLdouble hlid1[3][3], GLdouble hlid2[3][3], GLdouble hlid3[3][3]);

	// gefur gildi út frá gefnu gildi (truflun)
	GLdouble rask(GLdouble gildi);

	// ákveður hvort gefinn þríhyrningsflötur sé
	//	innan upplausnarmarka
	bool noguFint(GLdouble flotur[3][3]);

	// reiknar út fjölda flata sem koma til með að verða
	// búnir til, svo hægt sé að búa til fylki af réttir stærð
	void finnaFlatafjolda();

	// finnur hallahlutfall flatarins: 1.0 == lóðrétt
	GLdouble finnaHalla(GLdouble flotur[3][3]);

	// finnur lit út frá gefnu hæðargildi (y), og
	//	gefnum þríhyrningsfleti
	//	(finnur lit í litabilum sem hæðarpunkturinn er innan
	//	og blandar litagildum ef punkturinn er innan > 1 litabils)
	// Ath. tekur við haed og skilar lit í litur[3]
	//	sem gildum á bilinu [0.0, 1.0]
	void finnaLit(GLdouble haed, GLdouble flotur[3][3], GLdouble litur[3]);

	// finnur lit lóðrétts (hliðar)flatar út frá gefnu hæðargildi(y).
	//	Ath. tekur við haed og skilar lit í litur[3]
	//	sem gildum á bilinu [0.0, 255.0]
	void finnaBergLit(GLdouble haed, GLdouble litur[3]);

	// finnur normalvektor gefins flatar (á normalformi)
	//	Ath. skilar niðurstöðu í norm[3]
	void finnaNormal(GLdouble flotur[3][3], GLdouble norm[3]);

};

#endif // !defined(AFX_FJALL_H__B5593886_EC2C_11D2_B29C_000000000000__INCLUDED_)
