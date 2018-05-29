// InertBody.cpp for TerrestrialGravitation Project

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


#include "InertBody.hpp"

#define _DEFAULT_TIME 30 // Default time slices is 30 evaluations per second


InertBody::InertBody(void) {
	position.atOrigin();
	velocity.atOrigin();
	initialPosition.atOrigin();
	_at_rest = TRUE;
	_n = 0; _t = _DEFAULT_TIME; }

InertBody::InertBody(int a, int b) {
	position.x = a;
	position.y = b;
	position.concordanceInt();
	
	velocity.atOrigin();
	Position();
	_at_rest = TRUE;
	_n = 0; _t = _DEFAULT_TIME; }

InertBody::InertBody(double aa, double bb) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();
	
	velocity.atOrigin();
	Position();
	_at_rest = TRUE;
	_n = 0; _t = _DEFAULT_TIME; }

InertBody::InertBody(Cartesian pos) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	
	velocity.atOrigin();
	Position();
	_at_rest = TRUE;
	_n = 0; _t = _DEFAULT_TIME; }

InertBody::InertBody(int a, int b, int vx, int vy) {
	position.x = a;
	position.y = b;
	position.concordanceInt();
	
	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	Position();
	_n = 0; _t = _DEFAULT_TIME; }

InertBody::InertBody(double aa, double bb, double vxx, double vyy) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();
	
	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	Position();
	_n = 0; _t = _DEFAULT_TIME; }

InertBody::InertBody(Cartesian pos, Cartesian vel) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	
	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	Position();
	_n = 0; _t = _DEFAULT_TIME; }

InertBody::InertBody(int a, int b, int vx, int vy, int time) {
	position.x = a;
	position.y = b;
	position.concordanceInt();
	
	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	Position();
	_n = 0; _t = time; }

InertBody::InertBody(double aa, double bb, double vxx, double vyy, int time) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();
	
	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	Position();
	_n = 0; _t = time; }

InertBody::InertBody(Cartesian pos, Cartesian vel, int time) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	
	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	Position();
	_n = 0; _t = time; }

InertBody::InertBody(int a, int b, int vx, int vy, int ix, int iy) {
	position.x = a;
	position.y = b;
	position.concordanceInt();
	
	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();
	
	initialPosition.x = ix;
	initialPosition.y = iy;
	initialPosition.concordanceInt();
	
	Cartesian Zero.atOrigin;
	_at_rest = (velocity == Zero);
	_n = 0; _t = _DEFAULT_TIME; }

InertBody::InertBody(double aa, double bb, double vxx, double vyy, double ixx, double iyy) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();
	
	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();

	initialPosition.xx = ixx;
	initialPosition.yy = iyy;
	initialPosition.concordanceDouble();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	_n = 0; _t = _DEFAULT_TIME; }

InertBody::InertBody(Cartesian pos, Cartesian vel, Cartesian ipos) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	
	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();

	initialPosition.xx = ipos.xx;
	initialPosition.yy = ipos.yy;
	initialPosition.concordanceDouble();
	
	Cartesian Zero.atOrigin;
	_at_rest = (velocity == Zero);
	_n = 0; _t = _DEFAULT_TIME; }

InertBody::InertBody(int a, int b, int vx, int vy, int ix, int iy int time) {
	position.x = a;
	position.y = b;
	position.concordanceInt();
	
	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();

	initialPosition.x = ix;
	initialPosition.y = iy;
	initialPosition.concordanceInt();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	_n = 0; _t = time; }

InertBody::InertBody(double aa, double bb, double vxx, double vyy, double ixx, double iyy,
		int time) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();
	
	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();

	initialPosition.xx = ixx;
	initialPosition.yy = iyy;
	initialPosition.concordanceDouble();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	_n = 0; _t = time; }

InertBody::InertBody(Cartesian pos, Cartesian vel, Cartesian ipos, int time) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	
	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();

	initialPosition.xx = ipos.xx;
	initialPosition.yy = ipos.yy;
	initialPosition.concordanceDouble();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	_n = 0; _t = time; }

InertBody::InertBody(const InertBody &bodyCopy) {
	position.xx = bodyCopy.position.xx;
	position.yy = bodyCopy.position.yy;
	position.concordanceDouble();
	
	velocity.xx = bodyCopy.velocity.xx;
	velocity.yy = bodyCopy.velocity.yy;
	velocity.concordanceDouble();
	
	initialPosition.xx = bodyCopy.initialPosition.xx;
	initialPosition.yy = bodyCopy.initialPosition.yy;
	initialPosition.concordanceDouble();
	
	Catesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	_n = bodyCopy._n;
	_t = bodyCopy._t; }

InertBody::operator=(const InertBody &bodyAssignment) {
	if !(this == bodyAssignment) {
		position.xx = bodyAssignment.position.xx;
		position.yy = bodyAssignment.position.yy;
		position.concordanceDouble();
		
		velocity.xx = bodyAssignment.velocity.xx;
		velocity.yy = bodyAssignment.velocity.yy;
		velocity.concordanceDouble();

		initialPosition.xx = bodyAssignment.initialPosition.xx;
		initialPosition.yy = bodyAssignment.initialPosition.yy;
		initialPosition.concordanceDouble();
		
		Cartesian Zero.atOrigin();
		_at_rest = (velocity == Zero);
		_n = bodyAssignment._n;
		_t = bodyAssignment._t; }
	return *this; }

InertBody::~InertBody(void) {
	delete position;
	delete velocity;
	delete initialPosition; }


// Read current position
int InertBody::X(void) { return position.x; }

int InertBody::Y(void) { return position.y; }

double InertBody::XX(void) { return position.xx; }

double InertBody::YY(void) { return postion.yy; }

Cartesian InertBody::Position(void) { return position; }


//Set current position		
void InertBody::X(int a) {
	position.x = a;
	position.concordanceInt();
	return; }

void InertBody::Y(int b) {
	position.y = b;
	postion.concordanceInt();
	return; }

void InertBody::X_Y(int a, int b) {
	position.x = a;
	position.y = b;
	position.concordanceInt();
	return; }

void InertBody::XX_YY(double aa, double bb) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();
	return; }

void InertBody::XX(double aa) {
	position.xx = aa;
	position.concordanceDouble();
	return; }

void InertBody::YY(double bb) {
	position.yy = bb;
	position.concordanceDouble();
	return; }

void InertBody::Position(Cartesian pos) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	return; }

// Sets initial position to current position
void InertBody::Position(void) {
	initialPosition.xx = position.xx;
	initialPosition.yy = position.yy;
	initialPosition.concordanceDouble();
	return; }


// Read current velocity
int InertBody::VX(void) { return velocity.x; }

int InertBody::VY(void) { return velocity.y; }

double InertBody::VXX(void) { return velocity.xx; }

double InertBody::VYY(void) { return velocity.yy; }

Cartesian InertBody::Velocity(void) { return velocity; }

bool InertBody::AtRest(void) {
	bool BodyIsAtRest;
	Catesian Zero;
	Zero.atOrigin();
	BodyIsAtRest = (velocity == Zero);
	_at_rest = BodyIsAtRest;
	return BodyIsAtRest; }


//Set current velocity	
void InertBody::VX(int vx) {
	velocity.x = vx;
	velocity.concordanceInt();
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void InertBody::VY(int vy) {
	velocity.y = vy;
	velocity.concordanceInt();
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void InertBody::VX_VY(int vx, int vy) {
	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void InertBody::VXX_VYY(double vxx, double vyy) {
	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();
	Certesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void InertBody::VXX(double vxx) {
	velocity.xx = vxx;
	velocity.concordanceDouble();
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void InertBody::VYY(double vyy) {
	velocity.yy = vyy;
	velocity.concordanceDouble();
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void InertBody::Velocity(Cartesian vel) {
	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }


// Read initial position
int InertBody::initX(void) { return initialPosition.x; }

int InertBody::initY(void) { return initialPosition.y; }

double InertBody::initXX(void) { return initialPosition.xx; }

double InertBody::initYY(void) { return initialPosition.yy; }

Cartesian InertBody::initPosition(void) { return initialPosition; }


// Set initial position
void InertBody::initX(int ix) {
	initialPosition.x = ix;
	initialPosition.concordanceInt();
	return; }

void InertBody::initXX(double ixx) {
	initialPosition.xx = ixx;
	initialPosition.concordanceDouble();
	return; }

void InertBody::initY(int iy) {
	initialPosition.y = iy;
	initialPosition.concordanceInt();
	return; }

void InertBody::initYY(double iyy) {
	initialPosition.yy = iyy;
	initialPosition.concordanceDouble();
	return; }


void InertBody::initX_Y(int ix, int iy) {
	initialPosition.x = ix;
	initialPosition.y = iy;
	initialPosition.concordanceInt();
	return; }

void InertBody::initXX_YY(double ixx, double iyy) {
	initialPosition.xx = ixx;
	initialPosition.yy = iyy;
	initialPosition.concordanceDouble();
	return; }

void InertBody::initPosition(Cartesian ipos) {
	initialPosition.xx = ipos.xx;
	initialPosition.yy = ipos.yy;
	initialPosition.concordanceDouble();
	return; }


 // assigns current position to initial position
void InertBody::initPosition(void) {
	position.xx = initialPosition.xx;
	position.yy = initialPosition.yy;
	position.concordanceDouble();
	return; }


 // current position and initial position switch places
void InertBody::posCurInitJux(void) {
	Cartesian jux.atOrigin();
	jux.xx = position.xx;
	jux.yy = position.yy;

	position.xx = initialPosition.xx;
	position.yy = initialPosition.yy;
	position.concordanceDouble();
	
	initialPosition.xx = jux.xx;
	initialPosition.yy = jux.yy;
	initialPosition.concordanceDouble();
	
	delete jux;
	return; }


// Read next position
int InertBody::nextX(void) {
	_n++;
	if (!position.concordance()) position.concordanceInt();
	if (!velocity.concordance()) velocity.concordanceInt();
	double tt = (double) _n / (double) _t;
	position.xx = initialPosition.xx + (velocity.xx * tt); 
	position.concordanceDouble(); }
	return position.x; }

int InertBody::nextY(void) {
	_n++;
	if (!position.concordance()) position.concordanceInt();
	if (!velocity.concordance()) velocity.concordanceInt();
	double tt = (double) _n / (double) _t;
	position.yy = initialPosition.yy + (velocity.yy * tt); 
	position.concordanceDouble();
	return position.y; }

double InertBody::nextXX(void) {
	_n++;
	double tt = (double) _n / (double) _t;
	position.xx = initialPosition.xx + (velocity.xx * tt);
	position.concordanceDouble();
	return position.xx; }

double InertBody::nextYY(void) {
	_n++;
	double tt = (double) _n / (double) _t;
	position.yy = initialPosition.yy + (velocity.yy * tt);
	position.concordanceDouble();
	return position.yy; }

Cartesian InertBody::nextPosition(void) {
	_n++;
	double tt = (double) _n / (double) _t;
	position.xx = initialPosition.xx + (velocity.xx * tt);
	position.yy = initialPosition.yy + (velocity.yy * tt);
	position.concordanceDouble();
	return position; }


// Read previous position
int InertBody::prevX(void) {
	_n--;
	if (!position.concordance()) position.concordanceInt();
	if (!velocity.concordance()) velocity.concordanceInt();
	double tt = (double) _n / (double) _t;
	position.xx = initialPosition.xx + (velocity.xx * tt);
	position.concordanceDouble();
	return position.x; }

int InertBody::prevY(void) {
	_n--;
	if (!position.concordance()) position.concordanceInt();
	if (!velocity.concordance()) velocity.concordanceInt();
	double tt = (double) _n / (double) _t;
	position.yy = initialPosition.yy + (velocity.yy * tt);
	position.concordanceDouble();
	return position.y; }

double InertBody::prevXX(void) {
	_n--;
	double tt = (double) _n / (double) _t;
	position.xx = initialPosition.xx + (velocity.xx * tt);
	position.concordanceDouble();
	return position.xx; }

double InertBody::prevYY(void) {
	_n--;
	double tt = (double) _n / (double) _t;
	position.yy = initialPosition.yy + (velocity.yy * tt);
	position.concordanceDouble();
	return position.yy; }

Cartesian InertBody::prevPosition(void) {
	n--;
	double tt = (double) _n / (double) _t;
	position.xx = initialPosition.xx + (velocity.xx * tt);
	position.yy = initialPosition.yy + (velocity.yy * tt);
	position.concordanceDouble();
	return position; }


// Timeslice size and number of slices
void InertBody::TimeSlice(int time) {
	_t = time;
	return; }

void InertBody::NumberOfSlices(int num) {
	_n = num;
	return; }

int InertBody::TimeSlice(void) { return _t; }

int InertBody::NumberOfSlices(void) { return _n }
