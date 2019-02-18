// Cartesian.cpp for TerrestrialGravitation Library Project

// Designed and Coded by Ray Arias for The Trashcan Software and
// Media Publication as part of TerrestricalGravitation,
// a software library intended for inclusion with the supplemental
// paper 2D Terrestrial (Nonturbulent) Gravitational Motion.


/*  This file is Copyright © 2018 Raymond Arias, Jr. for
    The Trashcan Software and Media Publication and is released
	under the conditions of the GNU General Public License.
    This file is part of TerrestrialGravitation by Ray Arias.

    TerrestrialGravitation is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version.

    TerrestrialGravitation is distributed in the hope that it will be
    useful, but WITHOUT ANY WARRANTY; without even the implied
    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with TerrestrialGravitation.  If not, see
	<http://www.gnu.org/licenses/>. */


#include "Cartesian.hpp"

#define PI  3.14159265358979323846264338327950288L // value of pi to 36 places
#define DEGPI 180.0                                // Degrees in angle of pi radians

Cartesian::Cartesian() {
	atOrigin(); }

Cartesian::Cartesian(int a, int b) {
	x = a;
	y = b;
	xx = (double) a;
	yy = (double) b; }

Cartesian::Cartesian(const Cartesian &cartecopy) {
	xx = cartecopy.xx;
	yy = cartecopy.yy;
	x = (int) round(xx);
	y = (int) round(yy); }

Cartesian Cartesian::operator=(const Cartesian &carteassignment) {
	if (cartesianassignment != this) {
		xx = cartesianassignment.xx;
		yy = cartesianassignment.yy;
		x = (int) round(xx);
		y = (int) round(yy);
	}
	return *this; }

Cartesian Cartesian::operator-(const Cartesian &carteNegative) {
	xx = -carteNegative.xx;
	yy = -carteNegative.yy;
	concordanceDouble();
	return *this; }

Cartesian Cartesian::operator+(const Cartesian &carte1, const Cartesian &carte2) {
	xx = carte1.xx + carte2.xx;
	yy = carte1.yy + carte2.yy;
	concordanceDouble();
	return *this; }

Cartesian Cartesian::operator-(const Cartesian &carte1, const Cartesian &carte2) {
	xx = carte1.xx - carte2.xx;
	yy = carte1.yy - carte2.yy;
	concordanceDouble();
	return *this; }

// Complex product
Cartesian Cartesian::operator*(const Cartesian &carte1, const Cartesian &carte2) {
	xx = (carte1.xx * carte2.xx) - (carte1.yy * carte2.yy);
	yy = (carte1.xx * carte2.yy) + (carte1.yy * carte2.xx);
	concordanceDouble();
	return *this; }

// Complex quotient
Cartesian Cartesian::operator/(const Cartesian &carte1, const Cartesian &carte2) {
	double a, b, c, d, qr, qi;
	 a = b = c = d = qr = qi = 0.0;
	 a = carte1.xx;        b = carte1.yy;
	 c = carte2.xx;        d = carte2.yy;
	qr = ((a * c) + (b * d)) / ((c * c) + (d * d));
	qi = ((b * c) - (a * d)) / ((c * c) + (d * d));
	xx = qr;              yy = qi;
	concordanceDouble();
	return *this; }

bool Cartesian::operator==(const Cartesian &carteEqual1, const Cartesian &carteEqual2) {
	bool equality = false;
	if (carteEqual1.concordance())
		if (carteEqual2.concordance())
			if (carteEqual1.xx == carteEqual2.xx)
				if (carteEqual1.yy == carteEqual2.yy) equality = true;
	return equality; }

bool Cartesian::operator!=(const Cartesian &carteUnequal1, const Cartesian &carteUnequal2) {
	bool inequality = false;
	if !(carteUnequal1.concordance()) inequality = true;
	else if !(carteUnequal2.concordance()) inequality = true;
	else if (carteUnequal1.xx != carteUnequal2.xx) inequality = true;
	else if (carteUnequal1.yy != carteUnequal2.yy) inequality = true;
	return inequality; }

Cartesian::~Cartesian() { }

int Cartesian::X(void) { return x; }

int Cartesian::Y(void) { return y; }

Cartesian Cartesian::Position(void) {
	if !(concordance(*this)) concordanceDouble();
	return *this; }

void Cartesian::X(int a) {
	x = a;
	concordanceInt();
	return; }

void Cartesian::Y(int b) {
	y = b;
	concordanceInt();
	return; }

void Cartesian::XY(int a, int b) {
	x = a;
	y = b;
	concordanceInt();
	return; }

void Cartesian::XX(double aa) {
	xx = aa;
	concordanceDouble();
	return; }

void Cartesian::YY(double bb) {
	yy = bb;
	concordanceDouble();
	return; }

void Cartesian::XXYY(double aa, double bb) {
	xx = aa;
	yy = bb;
	concordanceDouble();
	return; }

void Cartesian::Position(Cartesian pos) {
	xx = pos.xx;
	yy = pos.yy;
	concordanceDouble();
	return; }

void Cartesian::invertX(void) {
	xx = -xx;
	concordanceDouble();
	return; }

void Cartesian::invertY(void) {
	yy = -yy;
	concordanceDouble();
	return; }

void Cartesian::invertXY(void) {
	xx = -xx;
	yy = -yy;
	concordanceDouble();
	return; }

int Cartesian::invert(int a) { return -a; }

double Cartesian::invert(double aa) { return -aa; }

void Cartesian::transpose(void) {
	double zz = 0.0;
	zz = xx;
	xx = yy;
	yy = zz;
	concordanceDouble();
	return; }

Cartesian Cartesian::transpose(Cartesian carte) {
	double zz = 0.0;
	zz = carte.xx;
	carte.xx = carte.yy;
	carte.yy = zz;
	carte.concordanceDouble();
	return carte; }

double Cartesian::distanceDouble(void) {
	double dd = sqrt((xx * xx) + (yy * yy));
	if ((xx < 0) && (yy > 0)) dd = -dd;
	else if ((xx >0) && (yy < 0)) dd = -dd;
	return dd; }

int Cartesian::distanceInt(void) {
	double dd = distanceDouble();
	int d = (int) dd;
	return d; }

double Cartesian::distance(void) {
	double dd = sqrt((xx * xx) + (yy * yy));
	if ((xx < 0) && (yy > 0)) dd = -dd;
	else if ((xx < 0) && (yy < 0)) dd = -dd;
	return dd; }

double Castesian::distance(double aa, double bb) {
	double ee = aa - xx;
	double ff = bb - yy;
	double dd = sqrt((ee * ee) + (ff * ff));
	if ((ee < 0) && (ff > 0)) dd = -dd;
	else if ((ee > 0) && (ff < 0)) dd = -dd; 
	return dd; }

double Castesian::distanceDouble(double aa, double bb) {
	double ee = aa - xx;
	double ff = bb - yy;
	double dd = sqrt((ee * ee) + (ff * ff));
	if ((ee < 0) && (ff > 0)) dd = -dd;
	else if ((ee > 0) && (ff < 0)) dd = -dd; 	
	return dd; }

int Cartesian::distance(int a, int b) {
	double aa = (double) a;
	double bb = (double) b;
	double dd = distance(aa, bb);
	int d = (int) dd;
	return d; }

int Cartesian::distanceInt(int a, int b) {
	double aa = (double) a;
	double bb = (double) b;
	double dd = distance(aa, bb);
	int d = (int) dd;
	return d; }

double Cartesian::distanceDouble(Cartesian carte) {
	double ee = catre.xx - xx;
	double ff = carte.yy - yy;
	double dd = sqrt((ee * ee) + (ff * ff));
	if ((ee < 0) && (ff > 0)) dd = -dd;
	else if ((ee > 0) && (ff < 0)) dd = -dd;
	return dd; }

int Cartesian::distanceInt(Cartesian carte) {
	double dd = distanceDouble(carte);
	int d = (int) d;
	return d; }

double Cartesian::distance(Cartesian carte) {
	double ee = catre.xx - xx;
	double ff = carte.yy - yy;
	double dd = sqrt((ee * ee) + (ff * ff));
	if ((ee < 0) && (ff > 0)) dd = -dd;
	else if ((ee > 0) && (ff < 0)) dd = -dd;
	return dd; }

double Cartesian::angleDouble(void) {
	double aa = 0.0;
	if (quadrant() > 0) {
		aa = atan(yy / xx);
		if (quadrant() == 2) aa = aa + PI;
		else if (quadrant() == 3) aa = aa + PI;
		else if (quadrant() == 4) aa = aa + (2.0 * PI); }
	else if (quadrant() == -2) aa = (0.5 * PI);
	else if (quadrant() == -3) aa = PI;
	else if (quadrant() == -4) aa = (1.5 * PI);
	return aa; }

int Cartesian::angleInt(void) {
	double aa = 0.0;
	if (quadrant() > 0) {
		aa = atan(yy / xx);
		if (quadrant() == 2) aa = aa + PI;
		else if (quadrant() == 3) aa = aa + PI;
		else if (quadrant() == 4) aa = aa + (2.0 * PI); }
	else if (quadrant() == -2) aa = (0.5 * PI);
	else if (quadrant() == -3) aa = PI;
	else if (quadrant() == -4) aa = (1.5 * PI);
	aa = (DEGPI / PI) * aa;
	int a = (int) aa;
	return a; }

double Cartesian::angle(void) {
	double aa = 0.0;
	if (quadrant() > 0) aa = atan(yy / xx);
	if (quadrant() == 2) aa = aa + PI;
	if (quadrant() == 3) aa = aa + PI;
	if (quadrant() == 4) aa = aa + (2.0 * PI);
	if (quadrant() == -2) aa = (0.5 * PI);
	if (quadrant() == -3) aa = PI;
	if (quadrant() == -4) aa = (1.5 * PI);
	return aa; }

double Castesian::angle(double ww, double zz) {
	double ee = ww - xx;
	double ff = zz - yy;
	double aa = 0.0;
	if (quadrant(ee, ff) > 0) aa = atan(ff / ee);
	else if (quadrant(ee, ff) == 2) aa = aa + PI;
	else if (quadrant(ee, ff) == 3) aa = aa + PI;
	else if (quadrant(ee, ff) == 4) aa = aa + (2.0 * PI);
	else if (quadrant(ee, ff) == -2) aa = (0.5 * PI);
	else if (quadrant(ee, ff) == -3) aa = PI;
	else if (quadrant(ee, ff) == -4) aa = (1.5 * PI);
	return aa; }

double Castesian::angleDouble(double ww, double zz) {
	double ee = ww - xx;
	double ff = zz - yy;
	double aa = 0.0;
	if (quadrant(ee, ff) > 0) aa = atan(ff / ee);
	else if (quadrant(ee, ff) == 2) aa = aa + PI;
	else if (quadrant(ee, ff) == 3) aa = aa + PI;
	else if (quadrant(ee, ff) == 4) aa = aa + (2.0 * PI);
	else if (quadrant(ee, ff) == -2) aa = (0.5 * PI);
	else if (quadrant(ee, ff) == -3) aa = PI;
	else if (quadrant(ee, ff) == -4) aa = (1.5 * PI);
	return aa; }	

int Cartesian::angle(int w, int z) {
	double ww = (double) w;
	double zz = (double) z;
	double ee = ww - xx;
	double ff = zz - yy;
	double aa = 0.0;
	if (quadrant(ee, ff) > 0) aa = atan(ff / ee);
	else if (quadrant(ee, ff) == 2) aa = aa + PI;
	else if (quadrant(ee, ff) == 3) aa = aa + PI;
	else if (quadrant(ee, ff) == 4) aa = aa + (2.0 * PI);
	else if (quadrant(ee, ff) == -2) aa = (0.5 * PI);
	else if (quadrant(ee, ff) == -3) aa = PI;
	else if (quadrant(ee, ff) == -4) aa = (1.5 * PI);
	aa = (DEGPI / PI) * aa;
	int a = (int) aa;
	return a; }

int Cartesian::angleInt(int w, int z) {
	double ww = (double) w;
	double zz = (double) z;
	double ee = ww - xx;
	double ff = zz - yy;
	double aa = 0.0;
	if (quadrant(ee, ff) > 0) aa = atan(ff / ee);
	else if (quadrant(ee, ff) == 2) aa = aa + PI;
	else if (quadrant(ee, ff) == 3) aa = aa + PI;
	else if (quadrant(ee, ff) == 4) aa = aa + (2.0 * PI);
	else if (quadrant(ee, ff) == -2) aa = (0.5 * PI);
	else if (quadrant(ee, ff) == -3) aa = PI;
	else if (quadrant(ee, ff) == -4) aa = (1.5 * PI);
	aa = (DEGPI / PI) * aa;
	int a = (int) aa;
	return a; }

double Cartesian::angleDouble(Cartesian carte) {
	double ee = catre.xx - xx;
	double ff = carte.yy - yy;
	double aa = 0.0;
	if (quadrant(ee, ff) > 0) aa = atan(ff / ee);
	else if (quadrant(ee, ff) == 2) aa = aa + PI;
	else if (quadrant(ee, ff) == 3) aa = aa + PI;
	else if (quadrant(ee, ff) == 4) aa = aa + (2.0 * PI);
	else if (quadrant(ee, ff) == -2) aa = (0.5 * PI);
	else if (quadrant(ee, ff) == -3) aa = PI;
	else if (quadrant(ee, ff) == -4) aa = (1.5 * PI);
	return aa; }

int Cartesian::angleInt(Cartesian carte) {
	double ee = carte.xx - xx;
	double ff = carte.yy - yy;
	double aa = 0.0;
	if (quadrant(ee, ff) > 0) aa = atan(ff / ee);
	else if (quadrant(ee, ff) == 2) aa = aa + PI;
	else if (quadrant(ee, ff) == 3) aa = aa + PI;
	else if (quadrant(ee, ff) == 4) aa = aa + (2.0 * PI);
	else if (quadrant(ee, ff) == -2) aa = (0.5 * PI);
	else if (quadrant(ee, ff) == -3) aa = PI;
	else if (quadrant(ee, ff) == -4) aa = (1.5 * PI);
	aa = (DEGPI / PI) * aa;
	int a = (int) aa;
	return a; }

double Cartesian::angle(Catesian carte) {
	double ee = catre.xx - xx;
	double ff = carte.yy - yy;
	double aa = 0.0;
	if (quadrant(ee, ff) > 0) aa = atan(ff / ee);
	else if (quadrant(ee, ff) == 2) aa = aa + PI;
	else if (quadrant(ee, ff) == 3) aa = aa + PI;
	else if (quadrant(ee, ff) == 4) aa = aa + (2.0 * PI);
	else if (quadrant(ee, ff) == -2) aa = (0.5 * PI);
	else if (quadrant(ee, ff) == -3) aa = PI;
	else if (quadrant(ee, ff) == -4) aa = (1.5 * PI);
	return aa; }

int Cartesian::quadrant(void) {
	int q = 0;
	if ((xx > 0.0) && (yy > 0.0)) q = 1;
	else if ((xx < 0.0) && (yy > 0.0)) q = 2;
	else if ((xx < 0.0) && (yy < 0.0)) q = 3;
	else if ((xx > 0.0) && (yy < 0.0)) q = 4;
	else if ((xx > 0.0) && (yy == 0.0)) q = -1;
	else if ((xx == 0.0) && (yy > 0.0)) q = -2;
	else if ((xx < 0.0) && (yy == 0.0)) q = -3;
	else if ((xx == 0.0) && (yy < 0.0)) q = -4;
	return q; }

int Cartesian::quadrant(int w, int z) {
	int q = 0;
	if ((w > 0) && (z > 0)) q = 1;
	else if ((w < 0) && (z > 0)) q = 2;
	else if ((w < 0) && (z < 0)) q = 3;
	else if ((w > 0) && (z < 0)) q = 4;
	else if ((w > 0) && (z == 0)) q = -1;
	else if ((ww == 0) && (zz > 0)) q = -2;
	else if ((ww < 0) && (zz == 0)) q = -3;
	else if ((ww == 0) && (zz < 0)) q = -4;
	return q; }

int Cartesian::quadrant(double ww, double zz) {
	int q = 0;
	if ((ww > 0.0) && (zz > 0.0)) q = 1;
	else if ((ww < 0.0) && (zz > 0.0)) q = 2;
	else if ((ww < 0.0) && (zz < 0.0)) q = 3;
	else if ((ww > 0.0) && (zz < 0.0)) q = 4;
	else if ((ww > 0.0) && (zz == 0.0)) q = -1;
	else if ((ww == 0.0) && (zz > 0.0)) q = -2;
	else if ((ww < 0.0) && (zz == 0.0)) q = -3;
	else if ((ww == 0.0) && (zz < 0.0)) q = -4;
	return q; }

int Cartesian::rectangularX(int r, int thetaDeg) {
	int w = 0;
	double ww = 0.0;
	double rr = (double) r;
	double theta = (((double) thetaDeg) / DEGPI) * PI;
	w = rr * cos(theta);
	w = (int) round(xx);
	return w; }

double Cartesian::rectagularXX(double rr, double thetaRad) {
	double ww = rr * cos(thetaRad);
	return ww; }

int Cartesian::rectangularY(int r, int thetaDeg) {
	int z = 0;
	double zz = 0.0;
	double rr = (double) r;
	double theta = (((double) thetaDeg) / DEGPI) * PI;
	zz = rr * sin(theta);
	z = (int) round(zz);
	return z; }

double Cartesian::rectangularYY(double rr, double thetaRad) {
	double zz = rr * sin(thetaRad);
	return zz; }

Cartesian Cartesian::rectangularC(int r, int thetaDeg) {
	Cartesian point;
	double ww = 0.0;
	double zz = 0.0;
	double rr = (double) r;
	double theta = (((double) thetaDeg) / DEGPI) * PI;
	ww = rr * cos(theta);
	zz = rr * sin(theta);
	point.xx = ww;
	point.yy = zz;
	point.concordanceDouble();
	return point; }

Cartesian Cartesian::rectangularC(double rr, double thetaRad) {
	Cartesian point;
	double ww = rr * cos(thetaRad);
	double zz = rr * sin(thetaRad);
	point.xx = ww;
	point.yy = zz;
	point.concordanceDouble();
	return point; }

void Cartesian::rectangular(int r, int thetaDeg) {
	double ww = 0.0;
	double zz = 0.0;
	double rr = (double) r;
	double theta = (((double) thetaDeg) / DEGPI) * PI;
	ww = rr * cos(theta);
	zz = rr * sin(theta);
	xx = ww;  yy = zz;
	concordanceDouble();
	return; }

void Cartesian::rectangular(double rr, double thetaRad) {
	double ww = rr * cos(thetaRad);
	double zz = rr * sin(thetaRad);
	xx = ww;  yy = zz;
	concordanceDouble();
	return; }

bool Cartesian::concordance(void) {
	int a = (int) round(xx);
	int b = (int) round(yy);
	double aa = (double) x;
	double bb = (double) y;
	bool pass = ((a == x) && (b == y));
	if (pass) pass = ((aa == round(xx)) && (bb == round(yy)));
	return pass; }

void Cartesian::concordanceDouble(void) {
	x = (int) round(xx);
	y = (int) round(yy);
	return; }

void Cartesian::concordanceInt(void) {
	xx = (double) x;
	yy = (double) y;
	return; }

Cartesian Cartesian::atOrigin(void) {
	xx = yy = 0.0;
	x = y = 0;
	return *this; }

// Geometric vector dot product
double Cartesian::DotProduct(const Cartesian &carte) {
	double mag1, mag2, ang, dot;
	mag1 = mag2 = ang = dot = 0.0;
	mag1 = distanceDouble();
	mag2 = carte.distanceDouble();
	ang = angleDouble(carte);
	dot = mag1 * mag2 * cos(ang);
	return dot; }

