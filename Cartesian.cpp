#include "Cartesian.h"

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
	x = (int) xx;
	y = (int) yy; }

Cartesian Cartesian::operator=(const Cartesian &carteassignment) {
	if (cartesianassignment != this) {
		xx = cartesianassignment.xx;
		yy = cartesianassignment.yy;
		x = (int) xx;
		y = (int) yy;
	}
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

Cartesian::~Cartesian() {
}

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

void Cartesian::XX(double aa) {
	xx = aa;
	concordanceDouble();
	return; }

void Cartesian::YY(double bb) {
	yy = bb;
	concordanceDouble();
	return; }

void Cartesian::Position(Cartesian pos) {
	xx = pos.xx;
	yy = pos.yy;
	concordanceDouble();
	return; }

double Cartesian::distanceDouble(void) {
	double dd = sqrt((xx * xx) + (yy * yy));
	return dd; }

int Cartesian::distanceInt(void) {
	double dd = distanceDouble();
	int d = (int) dd;
	return d; }

double Cartesian::distance(void) {
	double dd = distanceDouble(void);
	return dd; }

double Castesian::distance(double aa, double bb) {
	double ee = aa - xx;
	double ff = bb - yy;
	double dd = sqrt((ee * ee) + (ff * ff));
	return dd; }

int Cartesian::distance(int a, int b) {
	double aa = (double) a;
	double bb = (double) b;
	double dd = distance(aa, bb);
	int d = (int) dd;
	return d; }

double Cartesian::distanceDouble(Cartesian carte) {
	double ee = catre.xx - xx;
	double ff = carte.yy - yy;
	double dd = sqrt((ee * ee) + (ff * ff));
	return dd; }

int Cartesian::distanceInt(Cartesian carte) {
	double dd = distanceDouble(carte);
	int d = (int) d;
	return d; }

double Cartesian::distance(Catesian carte) {
	double dd = distanceDouble(carte);
	return dd; }

double Cartesian::angleDouble(void) {
	double aa = arctan(yy / xx));
	return aa; }

int Cartesian::angleInt(void) {
	double aa = angleDouble();
	int a = (int) aa;
	return a; }

double Cartesian::angle(void) {
	double aa = angleDouble(void);
	return aa; }

double Castesian::angle(double ww, double zz) {
	double ee = ww - xx;
	double ff = zz - yy;
	double aa = actan(ff / ee);
	return aa; }

int Cartesian::angle(int w, int z) {
	double ww = (double) w;
	double zz = (double) z;
	double aa = angle(ww, zz);
	int a = (int) aa;
	return a; }

double Cartesian::angleDouble(Cartesian carte) {
	double ee = catre.xx - xx;
	double ff = carte.yy - yy;
	double aa = arctan(ff / ee);
	return aa; }

int Cartesian::angleInt(Cartesian carte) {
	double aa = angleDouble(carte);
	int a = (int) aa;
	return a; }

double Cartesian::angle(Catesian carte) {
	double aa = angleDouble(carte);
	return aa; }

bool Cartesian::concordance(void) {
	int a = (int) xx;
	int b = (int) yy;
	double aa = (double) x;
	double bb = (double) y;
	bool pass = ((a == x) && (b == y));
	if (pass) pass = ((aa == xx) && (bb == yy));
	return pass; }

void Cartesian::concordanceDouble(void) {
	x = (int) xx;
	y = (int) yy;
	return; }

void Cartesian::concordanceInt(void) {
	xx = (double) x;
	yy = (double) y;
	return; }

Cartesian Cartesian::atOrigin(void) {
	xx = yy = 0.0F;
	x = y = 0;
	return *this; }

