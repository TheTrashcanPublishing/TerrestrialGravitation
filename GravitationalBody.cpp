// GravitationalBody.cpp for TerrestrialGravitation Library Project


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


#include "GravitationalBody.hpp"

#define GSI 9.80665      // Standard gravity on Earth in SI units = 9.80665 m/sec/sec
#define GCGS 980.665     // Standard gravity on Earth in CGS units = 980.665 cm/sec/sec
#define GMS2 9 806 650   // Standard gravity on Earth in microns/sec/sec
#define GUS 32.1740      // Standard gravity on Earth in US units = 32.1740 ft/sec/sec
#define GIS2 386.088     // Standard gravity on Earth in inches/sec/sec = 386.088 in/s/s
#define G1000IS2 386 088 // Standard gravity on Earth in 1000ths of inches/sec/sec


GravitationalBody::GravitationalBody(void) {
	position.x  = position.y  = 0;
	position.xx = position.yy = 0.0;

	velocity.x  = velocity.y  = 0;
	velocity.xx = velocity.yy = 0.0;
	_at_rest = true;
	
	initialPosition.x  = initialPosition.y  = 0;
	initialPosition.xx = initialPosition.yy = 0.0;
	
	initialVelocity.x  = initialVelocity.y  = 0;
	initialVelocity.xx = initialVelocity.yy = 0.0;

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor = 0;             _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;  }

GravitationalBody::GravitationalBody(int a, int b) {
	position.x = a;
	position.y = b;
	position.concordanceInt();

	velocity.x  = velocity.y  = 0;
	velocity.xx = velocity.yy = 0.0;
	_at_rest = true;
	
	initialPosition.x  = initialPosition.y  = 0;
	initialPosition.xx = initialPosition.yy = 0.0;
	
	initialVelocity.x  = initialVelocity.y  = 0;
	initialVelocity.xx = initialVelocity.yy = 0.0;

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor100 = 0;          _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(double aa, double bb) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();

	velocity.x  = velocity.y  = 0;
	velocity.xx = velocity.yy = 0.0;
	_at_rest = true;
	
	initialPosition.x  = initialPosition.y  = 0;
	initialPosition.xx = initialPosition.yy = 0.0;
	
	initialVelocity.x  = initialVelocity.y  = 0;
	initialVelocity.xx = initialVelocity.yy = 0.0;

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor100 = 0;          _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(Cartesian pos) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();

	velocity.x  = velocity.y  = 0;
	velocity.xx = velocity.yy = 0.0;
	_at_rest = true;
	
	initialPosition.x  = initialPosition.y  = 0;
	initialPosition.xx = initialPosition.yy = 0.0;
	
	initialVelocity.x  = initialVelocity.y  = 0;
	initialVelocity.xx = initialVelocity.yy = 0.0;

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor100 = 0;          _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(int a, int b, int vx, int vy) {
	position.x = a;
	position.y = b;
	position.concordanceInt();

	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.x  = initialPosition.y  = 0;
	initialPosition.xx = initialPosition.yy = 0.0;
	
	initialVelocity.x  = initialVelocity.y  = 0;
	initialVelocity.xx = initialVelocity.yy = 0.0;

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor100 = 0;          _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(double aa, double bb, double vxx, double vyy) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();

	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.x  = initialPosition.y  = 0;
	initialPosition.xx = initialPosition.yy = 0.0;
	
	initialVelocity.x  = initialVelocity.y  = 0;
	initialVelocity.xx = initialVelocity.yy = 0.0;

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor100 = 0;          _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(Cartesian pos, Cartesian vel) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();

	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.x  = initialPosition.y  = 0;
	initialPosition.xx = initialPosition.yy = 0.0;
	
	initialVelocity.x  = initialVelocity.y  = 0;
	initialVelocity.xx = initialVelocity.yy = 0.0;

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor100 = 0;          _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(int a, int b, int vx, int vy, int ix, int iy) {
	position.x = a
	position.y = b;
	position.concordanceInt();

	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.x = ix;
	initialPosition.y = iy;
	initialPosition.concordanceInt();
	
	initialVelocity.x  = initialVelocity.y  = 0;
	initialVelocity.xx = initialVelocity.yy = 0.0;

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor100 = 0;          _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(double aa, double bb, double vxx, double vyy,
		double ixx, double iyy) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();

	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.xx = ixx;
	initialPosition.yy = iyy;
	initialPosition.concordanceDouble();
	
	initialVelocity.x  = initialVelocity.y  = 0;
	initialVelocity.xx = initialVelocity.yy = 0.0;

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor100 = 0;          _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(Cartesian pos, Cartesian vel, Cartesian ipos) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();

	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.xx = ipos.xx;
	initialPosition.yy = ipos.yy;
	initialPosition.concordanceDouble();
	
	initialVelocity.x  = initialVelocity.y  = 0;
	initialVelocity.xx = initialVelocity.yy = 0.0;

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor100 = 0;          _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(int a, int b, int vx, int vy, int ix, int iy,
		int ivx, int ivy) {
	position.x = a;
	position.y = b;
	position.concordanceInt();

	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.x = ix;
	initialPosition.y = iy;
	initialPosition.concordanceInt();
	
	initialVelocity.x = ivx
	initialVelocity.y = ivy;
	initialVelocity.concordanceInt();

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor100 = 0;          _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(double aa, double bb, double vxx, double vyy,
		double ixx, double iyy, double ivxx, double ivyy) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();

	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.xx = ixx;
	initialPosition.yy = iyy;
	initialPosition.concordanceDouble();
	
	initialVelocity.xx = ivxx;
	initialVelocity.yy = ivyy;
	initialVelocity.concordanceDouble();

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor100 = 0;          _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(Cartesian pos, Cartesian vel,
		Cartesian ipos, Cartesian ivel) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();

	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.xx = ipos.xx;
	initialPosition.yy = ipos.yy;
	initialPosition.concordanceDouble();
	
	initialVelocity.xx = ivel.xx;
	initialVelocity.yy = ivel.yy;
	initialVelocity.concordanceDouble();

	_ground = 0;       _gground = 0.0;
	_accgrav = 0L;    _aaccgrav = 0.0;
	_cor100 = 0;          _ccor = 0.0;
	_groundOn = false;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(int a, int b, int vx, int vy, int ix, int iy,
		int ivx, int ivy, int grnd) {
	position.x = a;
	position.y = b;
	position.concordanceInt();

	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.x = ix;
	initialPosition.y = iy;
	initialPosition.concordanceInt();
	
	initialVelocity.x = ivx
	initialVelocity.y = ivy;
	initialVelocity.concordanceInt();
	
	_ground = grnd;
	_accgrav = 0L;
	_cor100 = 0;
	_concordanceInt();
	_groundOn = true;
	_gravOn = false;   }

GravitationBody::GravitationalBody(double aa, double bb, double vxx, double vyy,
		double ixx, double iyy, double ivxx, double ivyy, double ggrnd) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();

	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.xx = ixx;
	initialPosition.yy = iyy;
	initialPosition.concordanceDouble();
	
	initialVelocity.xx = ivxx;
	initialVelocity.yy = ivyy;
	initialVelocity.concordanceDouble();

	_gground = ggrnd;
	_aaccgrav = 0.0;
	_ccor = 0.0;
	_concordanceDounble();
	_groundOn = true;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(Cartesian pos, Cartesian vel, Cartesian ipos,
		Cartesian ivel, double ggrnd) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();

	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.xx = ipos.xx;
	initialPosition.yy = ipos.yy;
	initialPosition.concordanceDouble();
	
	initialVelocity.xx = ivel.xx;
	initialVelocity.yy = ivel.yy;
	initialVelocity.concordanceDouble();

	_gground = ggrnd;
	_aaccgrav = 0.0;
	_ccor = 0.0;
	_concordanceDouble();
	_groundOn = true;
	_gravOn = false;   }

GravitationalBody::GravitationalBody(int a, int b, int vx, int vy, int ix, int iy,
		int ivx, int ivy, int grnd, long int agv) {
	position.x = a;
	position.y = b;
	position.concordanceInt();

	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.x = ix;
	initialPosition.y = iy;
	initialPosition.concordanceInt();
	
	initialVelocity.x = ivx
	initialVelocity.y = ivy;
	initialVelocity.concordanceInt();
	
	_ground = grnd;
	_accgrav = agv;
	_cor100 = 0;
	_concordanceInt();
	_groundOn = true;
	_gravOn = true;   }

GravitationalBody::GravitationalBody(double aa, double bb, double vxx, double vyy,
		double ixx, double iyy, double ivxx, double ivyy, double ggrnd, double aagv) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();

	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.xx = ixx;
	initialPosition.yy = iyy;
	initialPosition.concordanceDouble();
	
	initialVelocity.xx = ivxx;
	initialVelocity.yy = ivyy;
	initialVelocity.concordanceDouble();

	_gground = ggrnd;
	_aaccgrav = aagv;
	_ccor = 0.0;
	_concordanceDouble();
	_groundOn = true;
	_gravOn = true;   }

GravitationalBody::GravitationalBody(Cartesian pos, Cartesian vel, Cartesian ipos,
		Cartesian ivel, double ggrnd, double aagv) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();

	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.xx = ipos.xx;
	initialPosition.yy = ipos.yy;
	initialPosition.concordanceDouble();
	
	initialVelocity.xx = ivel.xx;
	initialVelocity.yy = ivel.yy;
	initialVelocity.concordanceDouble();

	_gground = ggrnd;
	_aaccgrav = aagv;
	_ccor = 0.0;
	_concordanceDouble();
	_groundOn = true;
	_gravOn = true;   }

GravitationalBody::GravitationalBody(int a, int b, int vx, int vy, int ix, int iy,
		int ivx, int ivy, int grnd, long int agv, int epsln100) {
	position.x = a;
	position.y = b;
	position.concordanceInt();

	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.x = ix;
	initialPosition.y = iy;
	initialPosition.concordanceInt();
	
	initialVelocity.x = ivx
	initialVelocity.y = ivy;
	initialVelocity.concordanceInt();
	
	_ground = grnd;
	_accgrav = agv;
	_cor100 = epsln100;
	_concordanceInt();
	_groundOn = true;
	_gravOn = true;   }
		
GravitationalBody::GravitationalBody(double aa, double bb, double vxx, double vyy,
		double ixx, double iyy, double ivxx, double ivyy, double ggrnd, double aagv,
		double epsilon) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();

	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.xx = ixx;
	initialPosition.yy = iyy;
	initialPosition.concordanceDouble();
	
	initialVelocity.xx = ivxx;
	initialVelocity.yy = ivyy;
	initialVelocity.concordanceDouble();

	_gground = ggrnd;
	_aaccgrav = aagv;
	_ccor = epsilon;
	_concordanceDouble();
	_groundOn = true;
	_gravOn = true;   }

GravitationalBody::GravitationalBody(Cartesian pos, Cartesian vel, Cartesian ipos, Cartesian ivel,
		double ggrnd, double aagv, double epsilon) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();

	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.xx = ipos.xx;
	initialPosition.yy = ipos.yy;
	initialPosition.concordanceDouble();
	
	initialVelocity.xx = ivel.xx;
	initialVelocity.yy = ivel.yy;
	initialVelocity.concordanceDouble();

	_gground = ggrnd;
	_aaccgrav = aagv;
	_ccor = epsilon;
	_concordanceDouble();
	_groundOn = true;
	_gravOn = true; }
	   
GravitationalBody::GravitationalBody(const GravitationalBody &gravbodCopy) {
	position.xx = gravbodCopy.position.xx;
	position.yy = gravbodCopy.position.yy;
	position.concordanceDouble();

	velocity.xx = gravbodCopy.velocity.xx;
	velocity.yy = gravbodCopy.velocity.yy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	
	initialPosition.xx = gravbodCopy.initialPosition.xx;
	initialPosition.yy = gravbodCopy.initialPosition.yy;
	initialPosition.concordanceDouble();
	
	initialVelocity.xx = gravbodCopy.initialVelocity.xx;
	initialVelocity.yy = gravbodCopy.initialVelocity.yy;
	initialVelocity.concordanceDouble();
	
	_gground = gravbodCopy._gground;
	_aaccgrav = gravbodCopy._aaccgrav;
	_ccor = gravbodCopy._ccor;
	_concordanceDouble();
	_groundOn = gravbodCopy._groundOn;
	_gravOn = gravbodCopy._gravOn;  }

GravitationalBody GravitationalBody::operator=(const GravitationalBody &gravbodAssignment) {
	if (this != &gravbodAssignment) {
		position.xx = gravbodAssignment.position.xx;
		position.yy = gravbodAssignment.position.yy;
		position.concordanceDouble();

		velocity.xx = gravbodAssignment.velocity.xx;
		velocity.yy = gravbodAssignment.velocity.yy;
		velocity.concordanceDouble();

		Cartesian Zero.atOrigin();
		_at_rest = (velocity == Zero);

		initialPosition.xx = gravbodAssignment.initialPosition.xx;
		initialPosition.yy = gravbodAssignment.initialPosition.yy;
		initialPosition.concordanceDouble();

		initialVelocity.xx = gravbodAssignment.initialVelocity.xx;
		initialVelocity.yy = gravbodAssignment.initialVelocity.yy;
		initialVelocity.concordanceDouble();

		_gground = gravbodAssignment._gground;
		_aaccgrav = gravbodAssignment._aaccgrav;
		_ccor = gravbodAssignment._ccor;
		_concordanceDouble();
		_groundOn = gravbodAssignment._groundOn;
		_gravOn = gravbodAssignment._gravOn;  }

	return *this; }

bool GravitationalBody::operator==(const GravitationalBody &gravbodEqual1,
		const GravitationalBody &gravbodEqual2) {
	bool concordcheck = false;
	bool equality = false;
	if (gravbodEqual1.position.concordance())
		if (gravbodEqual2.position.concordance())
			if (gravbodEqual1.velocity.concordance())
				if (gravbodEqual2.velocity.concordance())
					if (gravbodEqual1.initialPosition.concordance())
						if (gravbodEqual2.initialPosition.concordance())
							if (gravbodEqual1.initialVelocity.concordance())
								if (gravbodEqual2.initialVelocity.concordance())
									concordcheck = true;
	if (concordcheck)
		if (gravbodEqual1.position == gravbodEqual2.position)
			if (gravbodEqual1.velocity == gravbodEqual2.velocity)
				if (gravbodEqual1.initialPosition == gravbodEqual2.initialPosition)
					if (gravbodEqual1.initialVelocity == gravbodEqual2.initialVelocity)
						equality = true;
	return equality; }

bool GravitationalBody::operator!=(const GravitationalBody &gravbodUnequal1,
		const GravitationalBody &gravbodUnequal2) {
	bool concordcheck = true;
	bool inequality = false;
	if !(gravbodUnequal1.position.concordance()) concordcheck = false;
	else if !(gravbodUnequal2.position.concordance()) concordcheck = false;
	else if !(gravbodUnequal1.velocity.concordance()) concordcheck = false;
	else if !(gravbodUnequal2.velocity.concordance()) concordcheck = false;
	else if !(gravbodUnequal1.initialPosition.concordance()) concordcheck = false;
	else if !(gravbodUnequal2.initialPosition.concordance()) concordcheck = false;
	else if !(gravbodUnequal1.initialVelocity.concordance()) concordcheck = false;
	else if !(gravbodUnequal2.initialVelocity.concordance()) concordcheck = false;
	if (concordcheck) {
		if (gravbodUnequal1.position != gravbodUnequal2.position) inequality = true;
		else if (gravbodUnequal1.velocity != gravbodUnequal2.velocity) inequality = true;
		else if (gravbodUnequal1.initialPosition != gravbodUnequal2.initialPosition)
			inequality = true;
		else if (gravbodUnequal1.initialVelocity != gravbodUnequal2.initialVelocity)
			inequality = true; }
	else inequality = true;
	return inequality; }

GravitationalBody::~GravitationalBody(void) {
	delete position;
	delete velocity;
	delete initialPosition;
	delete initialVelocity; }

Cartesian GravitationalBody::bodyPos(void) { return position; }

Cartesian GravitationalBody::bodyVel(void) { return velocity; }

void GravitationalBody::placeBody(int a, int b) {
	position.x = a;
	position.y = b;
	position.concordanceInt();
	return;}

void GravitationalBody::placeBody(double aa, double bb) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();
	return;}

void GravitationalBody::placeBody(Cartesian pos) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	return; }

void GravitationalBody::giveVelocity(int vx, int vy) {
	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity = Zero);
	return; }

void GravitationalBody::giveVelocity(double vxx, double vyy) {
	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero); 
	return; }
	
void GravitationalBody::giveVelocity(Cartesian vel) {
	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();
	
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void GravitationalBody::initPosition(int ix, int iy) {
	initialPosition.x = ix;
	initialPosition.y = iy;
	initialPosition.concordanceInt();
	return; }

void GravitationalBody::initPosition(double ixx, double iyy) {
	initialPosition.xx = ixx;
	initialPosition.yy = iyy;
	initialPosition.concordanceDouble();
	return; }

void GravitationalBody::initPosition(Cartesian ipos) {
	initialPosition.xx = ipos.xx;
	initialPosition.yy = ipos.yy;
	initialPosition.concordanceDouble();
	return; }

void GravitationalBody::initVelocity(int ivx, int ivy) {
	initialVelocity.x = ivx;
	initialVelocity.y = ivy;
	initialVelocity.concordanceInt();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void GravitationalBody::initVelocity(double ivxx, double ivyy) {
	initialVelocity.xx = ivxx;
	InitialVelocity.yy = ivyy;
	initialVelocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void GravitationalBody::initVelocity(Cartesian ivel) {
	initialVelocity.xx = ivel.xx;
	initialVelocity.yy = ivel.yy;
	initialVelocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void GravitationalBody::initPosition(void) {
	position.xx = initialPosition.xx;
	position.yy = initialPosition.yy;
	position.concordanceDouble();

	velocity.x  = velocity.y  = 0;
	velocity.xx = velocity.yy = 0.0;
	_at_rest = TRUE;
	return; }

void GravitationalBody::initVelocity(void) {
	velocity.xx = initialVelocity.xx;
	velocity.yy = initialVelocity.yy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void GravitationalBody::beginMotion(void) {
	velocity.xx = initialVelocity.xx;
	velocity.yy = initialVelocity.yy;
	velocity.concordanceDouble();

	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void GravitationalBody::haltMotion(void) {
	velocity.x  = velocity.y  = 0;
	velocity.xx = velocity.yy = 0.0;
	_at_rest = TRUE;
	return; }

void GravitationalBody::_G(long int ag) {
	_accgrav = ag;
	_concordanceInt();
	return; }

void GravitationalBody::_G(double aag) {
	_aaccgrav = aag;
	_concordanceDouble();
	return; }

void GravitationalBody::_GMS2(void) {
	_accgrav = GMS2;
	_concordanceInt();
	return; }

void GravitationalBody::_GGSI(void) {
	_aaccgrav = GGSI;
	_concordanceDouble();
	return; }

void GravitationalBody::_GGCGS(void) {
	_aaccgrav = GGCGS;
	_concordanceDouble();
	return; }

void GravitationalBody::_GGUS(void) {
	_aaccgrav = GGUS;
	_concordanceDouble();
	return; }

void GravitationalBody::_GGIS2(void) {
	_aaccgrav = GGIS2;
	_concordanceDouble();
	return; }

void GravitationalBody::_G1000IS2(void) {
	_accgrav = _G1000IS2
	_concordanceInt();
	return; }

void GravitationalBody::_GroundInt(int grd) {
	_ground = grd;
	_concordanceInt();
	return; }

void GravitationalBody::_GroundDouble(double ggrd) {
	_gground = ggrd;
	_concordanceDouble();
	return; }

void GravitationalBody::_CoeffRestn100(int epsln100) {
	_cor100 = epsln100;
	_concordanceInt();
	return; }

void GravitationalBody::_CoeffRestnDouble(double epsilon) {
	_ccor = epsilon;
	_concordanceDouble();
	return; }

void GravitationalBody::_GroundOn(void) {
	_groundOn = true;
	return; }

void GravitationalBody::_GroundOff(void) {
	_groundOn = false;
	return; }

void GravitationalBody::_GravOn(void) {
	_gravOn = true;
	return; }

void GravitationalBody::_GravOff(void) {
	_gravOn = false;
	return; }

bool GravitationalBody::_concordance(void) {
	bool pass = (_ground == (int) round(_gground));
	if (!pass) return pass;
	else pass = (_accgrav == (int) round(_aaccgrav));
	if (!pass) return pass;
	else pass = (_cor100 == (int) round(_ccor * 100.0));
	return pass; }

void GravitationalBody::_concordanceInt(void) {
	_gground = (double) _ground;
	_aaccgrav = (double) _accgrav;
	_ccor = ((double) _cor100) / 100.0;
	return; }

void GravitationalBody::_concordanceDouble(void) {
	_ground = (int) round(_gground);
	_accgrav = (long int) round(_aacgrav);
	_cor100 = (int) round(_ccor * 100.0);
	return; }


// Read next velocity
int GravitationalBody::nextVX(void) {
	velocity.x = velocity.x + 0;
	velocity.concordanceInt();
	return velocity.x; }

int GravitationalBody::nextVY(void) {
	if (_gravOn) {
		_n++;
		velocity.y = (int) ((double) initialVelocity.y -
			((double) (_accgrav * _n)  / (double) _t)); }
	else velocity.y = velocity.y + 0.0;
	if (_groundOn && (position.y <= _ground))
		velocity.y = (int) -(((double) _cor100 / 100.0) * (double) velocity.y); 
	velocity.concordanceInt();
	return velocity.y; }

double GravitationalBody::nextVXX(void) {
	velocity.xx = velocity.xx + 0.0;
	velocity.concordanceDouble();
	return velocity.xx; }

double GravitationalBody::nextVYY(void) {
	if (_groundOn && (position.yy <= _gground)) velocity.yy = -(_ccor * velocity.yy);
	if (_gravOn) {
		_n++;
		velocity.yy = initialVelocity.yy - (_aaccgrav * (double) _n / (double) _t); }
	else velocity.yy = velocity.yy + 0.0;
	velocity.concordanceDouble();
	return velocity.yy; }

Cartesian GravitationalBody::nextVelocity(void) {
	velocity.xx = velocity.xx + 0.0;
	if (_groundOn && (position.yy <= _gground)) velocity.yy = -(_ccor * velocity.yy);
	if (_gravOn) {
		_n++;
		velocity.yy = (double) initialVelocity.yy - (_aaccgrav * (double) _n / (double) _t); }
	else velocity.yy = velocity.yy + 0.0;
	velocity.concordanceDouble();
	return velocity; }

// Read previous velocity
int GravitationalBody::prevVX(void) {
	velocity.x = velocity.x - 0;
	velocity.concordanceInt();
	return velocity.x; }

int GravitationalBody::prevVY(void) {
	if (_groundOn && (position.y <= _ground))
		velocity.y = (int) -((double) velocity.y / ((double) _cor100 / 100.0));
	if (_gravOn) {
		_n--;
		velocity.y = (int) ((double) Initialvelocity.y +
			((double) (_accgrav * _n) / (double) _t)); }
	else velocity.y = velocity.y - 0;
	velocity.concordanceInt();
	return velocity.y; }

double GravitationalBody::prevVXX(void) {
	velocity.xx = velocity.xx - 0.0;
	velocity.concordanceDouble();
	return velocity.xx; }

double GravitationalBody::prevVYY(void) {
	if (_groundOn && (position.yy <= _gground)) velocity.yy = -(velocity.yy / _ccor);
	if (_gravOn) {
		_n--;
		velocity.yy = initialVelocity.yy + (_aaccgrav * (double) _n / (double) _t); }
	else velocity.yy = velocity.yy - 0.0;
	velocity.concordanceDouble();
	return velocity.yy; }

Cartesian GravitationalBody::prevVelocity(void) {
	velocity.xx = velocity.xx - 0.0;
	if (_groundOn && (position.yy <= _gground)) velocity.yy = -(velocity.yy / _ccor);
	if (_gravOn) {
		_n--;
		velocity.yy = initialVelocity.yy + (_aaccgrav * (double) _n / (double) _t); }
	else velocity.yy = velocity.yy - 0.0;
	velocity.concordanceDouble();
	return velocity; }


// Read next position (overloading for y and yy only)
int GravitationalBody::nextY(void) {
	if (_gravOn) {
		_n++;
		position.y = (int) ((double)initalPosition.y +
			((double) initialVelocity.y * (double) _n / (double) _t) -
			((double) (_n * _n) / (double) (_t * _t))); }
	else position.y = (int) ((double) position.y +
		((double) initialVelocity.y * (double) _n / (double) _t));
	if (_groundOn && (position.y <= _ground))
		velocity.y = (int) -(((double) _cor100 / 100.0) * (double) velocity.y); 
	position.concordanceInt();
	return position.y }

double GravitationalBody::nextYY(void) {
	if (_gravOn) {
		_n++;
		position.yy = initialPosition.yy + (initialVelocity.yy * (double) _n / (double) _t) -
			(_aaccgrav * (double) (_n * _n) / (double) (_t * _t)) }
	else position.yy = initialPosition.yy + (initialVelocity.yy * (double) _n / (double) _t);
	if (_groundOn && (position.yy <= _gground)) velocity.yy = -(velocity.yy / _ccor);
	position.concordanceDouble();
	return position.yy; }

Cartesian GravitationalBody::nextPosition(void) {
	position.xx = initialPosition.xx + (initialVelocity.xx * (double) _n / (double) _t);
	if (_gravOn) {
		_n++;
		position.yy = initialPosition.yy + (initialVelocity.yy * (double) _n / (double) _t) -
			(_aaccgrav * (double) (_n * _n) / (double) (_t * _t)) }
	else position.yy = initialPosition.yy + (initialVelocity.yy * (double) _n / (double) _t);
	if (_groundOn && (position.yy <= _gground)) velocity.yy = -(velocity.yy / _ccor);
	position.concordanceDouble();
	return position; }


// Read previous position (overloading for y and yy only)
int GravitationalBody::prevY(void) {
	if (_gravOn) {
		_n--;
		position.y = (int) ((double)initalPosition.y -
			((double) initialVelocity.y * (double) _n / (double) _t) +
			((double) (_n * _n) / (double) (_t * _t))); }
	else position.y = (int) ((double) position.y -
		((double) initialVelocity.y * (double) _n / (double) _t));
	if (_groundOn && (position.y <= _ground))
		velocity.y = (int) -(((double) _cor100 / 100.0) * (double) velocity.y); 
	position.concordanceInt();
	return position.y }

double GravitationalBody::prevYY(void) {
	if (_gravOn) {
		_n--;
		position.yy = initialPosition.yy - (initialVelocity.yy * (double) _n / (double) _t) +
			(_aaccgrav * (double) (_n * _n) / (double) (_t * _t)) }
	else position.yy = initialPosition.yy - (initialVelocity.yy * (double) _n / (double) _t);
	if (_groundOn && (position.yy <= _gground)) velocity.yy = -(velocity.yy / _ccor);
	position.concordanceDouble();
	return position.yy; }

Cartesian GravitationalBody::prevPosition(void) {
	position.xx = initialPosition.xx - (initialVelocity.xx * (double) _n / (double) _t);
	if (_gravOn) {
		_n--;
		position.yy = initialPosition.yy - (initialVelocity.yy * (double) _n / (double) _t) +
			(_aaccgrav * (double) (_n * _n) / (double) (_t * _t)) }
	else position.yy = initialPosition.yy - (initialVelocity.yy * (double) _n / (double) _t);
	if (_groundOn && (position.yy <= _gground)) velocity.yy = -(velocity.yy / _ccor);
	position.concordanceDouble();
	return position; }

