// TerrestrialGravitation.cpp of TerrestrialGravitation Library Project

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

    TerrestrialGravitation is distributed in the hope that it will
    be useful, but WITHOUT ANY WARRANTY; without even the implied
    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with TerrestrialGravitation.  If not, see
	<http://www.gnu.org/licenses/>. */


#define _DEFAULT_TIME 30
#define _DEFAULT_GRSLICES 48
#define _DEFAULT_SLICEWIDTH 10
#define _DEFAULT_SLICEWIDTH_DOUB 10.0
#define _DEFAULT_GRDEPTH 100
#define _DEFAULT_GRDEPTH_DOUB 100.0

#define GSI 9.80665  // Standard gravity on Earth in SI units = 9.80665 m/sec/sec
#define GCGS 980.665 // Standard gravity on Earth in CGS units = 980.665 cm/Sec/sec
#define GMS2 9806650 // Standard gravity on Earth in microns/sec/sec
#define GUS 32.1740  // Standard gravity on Earth in US units = 32.1740 ft/sec/sec
#define GIS2 386.088 // Standard gravity on Earth in inches/sec/sec = 386.088 in/s/s
#define G1000IS2 386088 // Standard gravity on Earth in 1000ths of inches/sec/sec

#include <iostream>
#include <fstream> 
#include "TerrestrialGravitation.hpp"
using namespace std;


TerrestrialGravitation::TerrestrialGravitation(void) {
	numberOfGravBodies = 1;
	gravBody[0].position.atOrigin();
	gravBody[0].velocity.atOrigin();
	gravBody[0].initialPosition.atOrigin();
	gravBody[0].initialVelocity.atOrigin();
	time = _DEFAULT_TIME;
	gInt = (int) GSI;
	gDouble = GSI;
	groundSlices = _DEFAULT_GRSLICES;
	groundInt[0] = _DEFAULT_GRDEPTH;
	groundDouble[0] = _DEFAULT_GRDEPTH_DOUB; }

TerrestrialGravitation::TerrestrialGravitation(unsigned int numGbodies) {
	numberOfGravBodies = numGbodies;
	initBodies();
	time = _DEFAULT_TIME;
	gInt = (int) GSI;
	gDouble = GSI;
	groundSlices = _DEFAULT_GRSLICES;
	initGround(); }

TerrestrialGravitation::TerrestrialGravitation(unsigned int numGbodies, unsigned int grSlices) {
	numberOfGravBodies = numGbodies;
	initBodies();
	time = _DEFAULT_TIME;
	gInt = (int) GSI;
	gDouble = GSI;
	groundSlices = grSlices;;
	initGround(); }

TerrestrialGravitation::TerrestrialGravitation(unsigned int numGbodies, unsigned int grSlices,
			unsigned int t) {
	numberOfGravBodies = numGbodies;
	initBodies();
	time = t;
	gInt = (int) GSI;
	gDouble = GSI;
	groundSlices = grSlices;;
	initGround(); }

TerrestrialGravitation::TerrestrialGravitation(unsigned int numGbodies, unsigned int grSlices,
			unsigned int t, signed int gI) {
	numberOfGravBodies = numGbodies;
	initBodies();
	time = t;
	gInt = gI;
	gDouble = (double) gI;
	groundSlices = grSlices;;
	initGround(); }
	
TerrestrialGravitation::TerrestrialGravitation(unsigned int numGbodies, unsigned int grSlices,
			unsigned int t, signed double gD) {
	numberOfGravBodies = numGbodies;
	initBodies();
	time = t;
	gDouble = gD;
	gInt = (int) round(gD);
	groundSlices = grSlices;;
	initGround(); }

TerrestrialGravitation::TerrestrialGravitation(unsigned int numGbodies, unsigned int grSlices,
			unsigned int t, signed int gI, signed int grdInt) {
	numberOfGravBodies = numGbodies;
	initBodies();
	time = t;
	gInt = gI;
	gDouble = (double) gI;
	groundSlices = grSlices;;
	initGround(grdInt); }

TerrestrialGravitation::TerrestrialGravitation(unsigned int numGbodies, unsigned int grSlices,
			unsigned int t, signed double gD, signed double grdDouble) {
	numberOfGravBodies = numGbodies;
	initBodies();
	time = t;
	gDouble = gD;
	gInt = (int) round(gD);
	groundSlices = grSlices;;
	initGround(grdDouble); }

TerrestrialGravitation::TerrestrialGravitation(unsigned int numGbodies, unsigned int t,
			signed int gI, string fname) {
	numberOfGravBodies = numGbodies;
	initBodies();
	time = t;
	gInt = gI;
	gDouble = (double) gI;
	initGround(fname); }

TerrestrialGravitation::TerrestrialGravitation(unsigned int numGbodies, unsigned int t,
			signed double gD, string fname) {
	numberOfGravBodies = numGbodies;
	initBodies();
	time = t;
	gDouble = gD;
	gInt = (int) round(gD);
	initGround(fname); }

TerrestrialGravitation::TerrestrialGravitation(string fname) { initAllMembers(fname); }

TerrestrialGravitation::TerrestrialGravitation(
		const TerrestrialGravitation &terrgravCopy) {
	position.xx = terrgravCopy.position.xx;
	position.yy = terrgravCopy.position.yy;
	position.concordanceDouble();
	
	velocity.xx = terrgravCopy.velocity.xx;
	velocity.yy = terrgravCopy.velocity.yy;
	velocity.concordanceDouble();
	
	time = terrgravCopy.time;
	_at_rest = ((velocity.xx == velocity.yy) == 0.0F; }

TerrestrialGravitation::operator=(const TerrestrialGravitation &terrgravAssignment) {
	if (this != terrgravAssignment) {
		position.xx = terrgravAssignment.position.xx;
		position.yy = terrgravAssignment.position.yy;
		position.concordanceDouble();
		
		velocity.xx = terrgravAssignment.velocity.xx;
		velocity.yy = terrgravAssignment.velocity.yy;
		velocity.concordanceDouble();
		
		time = terrgravAssignment.time; 
		_at_rest = ((velocity.xx == velocity.yy) == 0.0F); }
	return *this; }


TerrestrialGravitation::~TerrestrialGravitation() {
	delete position;
	delete velocity;
}

int TerrestrialGravitation::X(void) { return position.x; }

double TerrestrialGravitation::XX(void) { return position.xx; }

int TerrestrialGravitation::Y(void) { return position.y; }

double TerrestrialGravitation::YY(void) { return position.yy; }

Cartesian TerrestrialGravitation::Position(void) { return position; }

int TerrestrialGravitation::VX(void) { return velocity.x; }

double TerrestrialGravitation::VXX(void) { return velocity.xx; }

int TerrestrialGravitation::VY(void) { return velocity.y; }

double TerrestrialGravitation::VYY(void) { return velocity.yy; }

Cartesian TerrestrialGravitation::Velocity(void) { return velocity; }

void TerrestrialGravitation::T(int t) {        // Set fineness of time division
	time = t;
	return; }

int TerrestrialGravitation::T(void) { return time; }

void TerrestrialGravitation::initGround(void) {
	for (int i = 0; i < groundWidth; i++) {
		groundInt[i] = _DEFAULT_GRDEPTH;
		groundDouble[i] = _DEFAULT_GRDEPTH_DOUB; }
	return; }

void TerrestrialGravitation::initGround(int grdInt) {
	for (int i = 0; i < groundWidth; i++) {
		groundInt[i] = grdInt;
		_sliceConcordanceInt(i); }
	return; }

void TerrestrialGravitation::initGround(double grdDouble) {
	for (int i = 0; i < groundWidth; i++) {
		groundDouble[i] = grdDouble;
		_sliceConcordanceDouble(i); }
	return; }

void TerrestrialGravitation::initGround(string fname) {
	bool IorD = false;
	string fsline;
	int fsint = 0;
	double fsdouble = 0.0;
	ofstream file;
	file.open(fname, ios::in);
	IorD = (bool) getline(file, fsline); 
	groundSlices = (int) getline(file, fsline);
	for (int i = 0; ((i < groundSlices) && (getline(file, fsline))); i++) {
		if (IorD) {
			fsdouble = (double) fsline;
			groundDouble[i] = fsdouble;
			_sliceConcordanceDouble(i); }
		else {
			fsint = (int) fsline;
			groundInt[i] = fsint;
			_sliceConcordanceInt(i); }
	}
	file.close();
	return; }

void TerrestrialGravitation::initBodies(void) {
	for (int i = 0; i < NumberOfGravBodies; i++) {
		gravBody[i].position.atOrigin();
		gravBody[i].velocity.atOrigin();
		gravBody[i].initialPosition.atOrigin();
		gravBody[i].initialVelocity.atOrigin();}
	return; }

void TerrestrialGravitation::initBodies(Cartesian pos, Cartesian vel,
		Cartesian ipos, Cartesian ivel) {
	for (int i = 0; i < NumberOfGravBodies; i++) {
		gravBody[i].position = pos;
		gravBody[i].velocity = vel;
		gravBody[i].initialPosition = ipos;
		gravBody[i].initialVelocity = ivel; }
	return; }

void TerrestrialGravitation::initBody(int bodyNum, Cartesian pos, Cartesian vel,
		Cartesian ipos, Cartesian ivel) {
	gravBody[bodyNum].position = pos;
	gravBody[bodyNum].velocity = vel;
	gravBody[bodyNum].initialPosition = ipos;
	gravBody[bodyNum].initialVelocity = ivel;
	return; }

void TerrestrialGravitation::initAllMembers(string fname) {
	bool IorD = false;
	string fsline;
	signed int fssint = 0;
	unsigned int fsuint = 0U;
	double fsdouble = 0.0;
	Cartesian pos, vel, ipos, ivel;
	pos.atOrigin();
	vel.atOrigin();
	ipos.atOrigin();
	ivel.atOrigin();
	ofstream file;
	file.open(fname, ios::in);
	IorD = (bool) getline(file, fsline);
	if !(IorD) {
		fsint = (int) getline(file, fsline);
		gInt = fssint; }
	else { // IorD true
		fsdouble = (double) getline(file, fsline);
		gDouble = fsdouble; }
	fsuint = (unsigned int) getline(file, fsline);
	time = fsuint;
	fsuint = (unsigned int) getline(file, fsline);
	groundSlices = fsuint;
	fsuint = (unsigned int) getline(file, fsline);
	numberOfGravBodies = fsuint;
	for (unsigned int i = 0; i < numberOfGravBodies; i++) {
		fsdouble = (double) getline(file, fsline);
		pos.xx = fsdouble;
		fsdouble = (double) getline(file, fsline);
		pos.yy = fsdouble;
		pos.concordanceDouble();

		fsdouble = (double) getline(file, fsline);
		vel.xx = fsdouble;
		fsdouble = (double) getline(file, fsline);
		vel.yy = fsdouble;
		vel.concordanceDouble();

		fsdouble = (double) getline(file, fsline);
		ipos.xx = fsdouble;
		fsdouble = (double) getline(file, fsline);
		ipos.yy = fsdouble;
		ipos.concordanceDouble();

		fsdouble = (double) getline(file, fsline);
		ivel.xx = fsdouble;
		fsdouble = (double) getline(file, fsline);
		ivel.yy = fsdouble;
		ivel.concordanceDouble();

		initBody(i, pos, vel, ipos, ivel); }
	for (int i = 0; ((i < groundSlices) && (getline(file, fsline))); i++) {
		if (IorD) {
			fsdouble = (double) fsline;
			groundDouble[i] = fsdouble;
			_sliceConcordanceDouble(i); }
		else {
			fsint = (int) fsline;
			groundInt[i] = fsint;
			_sliceConcordanceInt(i); }
	}
}

void TerrestrialGravitation::X(int a) {
	position.x = a;
	position.xx = (double) a;
	return; }

void TerrestrialGravitation::Y(int b) {
	position.y = b;
	position.yy = (double) b;
	return; }

void TerrestrialGravitation::XX(double aa) {
	position.xx = aa;
	position.x = (int) aa;
	return; }

void TerrestrialGravitation::YY(double bb) {
	position.yy = bb;
	position.y = (int) bb;
	return;
}

void TerrestrialGravitation::posConcordInt(void) {
	position.xx = (double) position.x;
	position.yy = (double) position.y; 
	return; }

void TerrestrialGravitation::posConcordDoub(void) {
	position.x = (int) position.xx;
	position.y = (int) position.yy;
	return; }

bool TerrestrialGravitation::posConcord(void) {
	bool pass = (position.x == (int) position.xx);
	if (pass) pass = (position.y == (int) position.yy);
	return pass; }

void TerrestrialGravitation::Position(int a, int b) {
	position.x = a;
	position.y = b;
	position.concordanceInt();
	return; }

void TerrestrialGravitation::Position(double aa, double bb) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();
	return; }

void TerrestrialGravitation::Position(Cartesian pos) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	return; }

void TerrestrialGravitation::VX(int vx) {
	velocity.x = vx;
	velocity.xx = (double) vx;
	_at_rest = ((vx == velocity.y) == 0);
	return; }

void TerrestrialGravitation::VY(int vy) {
	velocity.y = vy;
	velocity.yy = (double) vy;
	_at_rest = ((vy == velocity.x) == 0);
	return; }

void TerrestrialGravitation::VXX(double vxx) {
	velocity.xx = vxx;
	velocity.x = (int) vxx;
	_at_rest = ((vxx == velocity.yy) == 0.0F);
	return; }

void TerrestrialGravitation::VYY(double vyy) {
	velocity.yy = vyy;
	velocity.y = (int) vyy;
	_at_rest = ((vyy == velocity.xx) == 0.0F);
	return; }

void TerrestrialGravitation::velConcordInt(void) {
	velocity.xx = (double) velocity.x;
	velocity.yy = (double) velocity.y;
	_at_rest = ((velocity.x == velocity.y) ==0);
	return; }

void TerrestrialGravitation::velConcordDoub(void) {
	velocity.x = (int) velocity.xx;
	velocity.y = (int) velocity.yy;
	_at_rest = ((velocity.xx == velocity.yy) == 0.0F);
	return; }

bool TerrestrialGravitation::velConcord(void) {
	bool pass = (velocity.x == (int) velocity.xx);
	if (pass) pass = (velocity.y == (int) velocity.yy);
	return pass; }

void TerrestrialGravitation::Velocity(int vx, int vy) {
	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();
	_at_rest = ((vx == vy) == 0);
	return; }

void TerrestrialGravitation::Velocity(double vxx, double vyy) {
	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();
	_at_rest = ((vxx == vyy) == 0.0F)
	return; }

void TerrestrialGravitation::Velocity(Cartesian vel) {
	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();
	_at_rest = ((vel.xx == vel.yy) == 0.0F);
	return; }

void TerrestrialGravitation::StartX(int a) {
	X(a);
	XX((double) a);
	return; }

void TerrestrialGravitation::StartY(int y) {
	Y(b);
	YY((double) b);
	return; }

void TerrestrialGravitation::StartXX(double aa) {
	XX(aa);
	X((int) aa);
	return; }

void TerrestrialGravitation::StartYY(double bb) {
	YY(bb);
	Y((int) bb);
	return; }

void TerrestrialGravitation::StartPosition(Cartesian pos) {
	Position(pos);
	return; }

void TerrestrialGravitation::StartVX(int vx) {
	VX(vx);
	_at_rest = ((vx == velocity.y) == 0);
	return; }

void TerrestrialGravitation::StartVY(int vy) {
	VY(vy);
	_at_rest = ((vy == velocity.x) == 0);
	return; }

void TerrestrialGravitation::StartVXX(double vxx) {
	VXX(vxx);
	_at_rest = ((vxx == velocity.yy) == 0.0F);
	return; }

void TerrestrialGravitation::StartVYY(double vyy) {
	VYY(vyy);
	_at_rest = ((vyy == velocity.x) == 0.0F)
	return; }

void TerrestrialGravitation::StartVelocity(Cartesian vel) {
	Velocity(vel);
	_at_rest = ((vel.xx == vel.yy) ==0.0F);
	return; }

void TerrestrialGravitation::BeginMotion(void) { // Begin object motion
	_at_rest = FALSE;
}

void TerrestrialGravitation::PrevPos(void) {     // Move object to previous position
	velocity.yy = velocity.yy + (GG / (double) t);
	position.yy = position.yy - (velocity.yy / (double) t);
	position.xx = position.xx - (velocity.xx / (double) t);
	position.concordanceDouble();
	velocity.concordanceDouble();
	_at_rest = ((velocity.xx == velocity.yy) == 0.0F); }

void TerrestrialGravitation::NextPos(void) {     // Move object to next position
	velocity.yy = velocity.yy - (GG / (double) t);
	position.yy = position.yy + (velocity.yy / (double) t);
	position.xx = position.xx + (velocity.xx / (double) t);
	position.concordanceDouble();
	velocity.concordanceDouble();
	_at_rest = ((velocity.xx == velocity.yy) == 0.0F); }

void TerrestrialGravitation::HaltMotion(void) {  // Halt motion at current position
	_at_rest = TRUE;
	velocity.xx = 0.0F;
	velocity.yy = 0.0F;
	velocity.concordanceDouble();
}

bool TerrestrialGravitation::_sliceConcordance(int slice) {
	bool pass = true;
	int rgds = (int) round(groundDouble[slice]);
	pass = 	(groundInt[slice] == rgds);
	return pass; }

void TerrestrialGravitation::_sliceConcordanceInt(int slice) {
	groundDouble[slice] = (double) groundInt[slice];
	return; }

void TerrestrialGravitation::_sliceConcordance(int slice) {
	int rdgs = (int) round(groundDouble[slice]);
	groundInt[slice] = rgds;
	return; }

bool TerrestrialGravitation::_groundConcordance(void) {
	bool pass = true;
	int rgdi = 0;
	int swd = (int) round(sliceWidthDouble);
	int gdb = (int) round(gDouble);
	pass = (pass && (sliceWidthInt == swd));
	pass = (pass && (gInt == gdb)));
	if (pass) for (int i = 0; i < groundSlices; i++) {
		rgdi = (int) round(groundDouble[i]);
		pass = (pass && (groundInt[i] == rgdi)); }
	return pass; }

void TerrestrialGravitation::_groundConcordanceInt(void) {
	sliceWidthDouble = (double) sliceWidthInt;
	gDouble = (double) gInt;
	for (i = 0; i < groundSlices; i++)
		groundDouble[i] = (double) groundInt[i];
	return; }

void TerrestrialGravitation::_groundConcordanceDouble(void) {
	int rgdi = 0;
	int swd = (int) round(sliceWidthDouble);
	int gdb = (int) round(gDouble);
	sliceWidthInt = swd;
	gInt = gdb;
	for (int i = 0; i < groundSlices; i++) {
		rgdi = (int) round(groundDouble[i]);
		groundInt[i] = rgdi; }
	return; }

