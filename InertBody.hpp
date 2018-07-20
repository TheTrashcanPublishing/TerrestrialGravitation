// InertBody .hpp for TerrestrialGravitation Library Project

// Designed and Coded by Ray Arias for The Trashcan Software and
// Media Publication as part of TerrestricalGravitation,
// a software library intended for inclusion with the supplemental
// paper 2D Terrestrial (Nonturbulent) Gravitational Motion.

// The class InertBody is an encapsulator class for objects of
// class Cartesian as well as a superclass of class GravitationBody.


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


#ifndef INERTBODY_H
#define INERTBODY_H

#include <cmath>

class InertBody
{
	public:
		Cartesian position, Cartesian velocity, Cartesian initialPosition;
		// Cartesian position is InertBody object's position as (x, y) and (xx, yy)
		// Cartesian velocity is InertBody object's velocity as (x, y) and (xx, yy)
		// Cartesian initialPosition is Inertbody object's initial position as (x, y)
		// and (xx, yy)

		InertBody(void);
		InertBody(int a, int b);
		InertBody(double aa, double bb);
		InertBody(Cartesian pos);
		InertBody(int a, int b, int time);
		InertBody(double aa, double bb, int time);
		InertBody(Cartesian pos, int time);		
		InertBody(int a, int b, int vx, int vy);
		InertBody(double aa, double bb, double vxx, double vyy);
		InertBody(Cartesian pos, Cartesian vel);
		InertBody(int a, int b, int vx, int vy, int time);
		InertBody(double aa, bouble bb, double vxx, double vyy, int time);
		InertBody(Cartesian pos, Cartesian vel, int time);
		InertBody(int a, int b, int vx, int vy, int ix, int iy);
		InertBody(double aa, double bb, double vxx, double vyy, double ixx, double iyy);
		InertBody(Cartesian pos, Cartesian vel, Cartesian ipos);
		InertBody(int a, int b, int vx, int vy, int ix, int iy, int time);
		InertBody(double aa, double bb, double vxx, double vyy, double ixx, double iyy, int time);
		InertBody(Cartesian pos, Cartesian vel, Cartesian ipos, int time);
		InertBody(const InertBody &bodyCopy);
		operator=(const InertBody &bodyAssignment);
		bool operator==(const InertBody &bodyEqual1, const InertBody &bodyEqual2);
		bool operator!=(const InertBody &bodyUnequal1, const InertBody &bodyUnequal2);
		~InertBody(void);
		
		// Read current position
		int X(void);
		int Y(void);
		double XX(void);
		double YY(void);
		Cartesian Position(void);

		//Set current position		
		void X(int a);
		void Y(int b);
		void X_Y(int a, int b);
		void XX(double aa);
		void YY(double bb);		
		void XX_YY(double aa, double bb);
		void Position(Cartesian pos);

		// Read current velocity
		int VX(void);
		int VY(void);
		double VXX(void);
		double VYY(void);
		Cartesian Velocity(void);
		bool AtRest(void);

		// Set current velocity	
		void VX(int vx);
		void VY(int vy);
		void VX_VY(int vx, int vy);
		void VXX(double vxx);
		void VYY(double vyy);
		void VXX_VYY(double vxx, double vyy);
		void Velocity(Cartesian vel);
		
		// Read initial position
		int initX(void);
		int initY(void);
		double initXX(void);
		double initYY(void);
		Cartesian initPosition(void);

		// Set initial position
		void initX(int ix);
		void initY(int iy);
		void initX_Y(int ix, int iy);
		void initXX(double ixx);
		void initYY(double iyy);
		void initXX_YY(double ixx, double iyy);
		void initPosition(Cartesian ipos);

		// Current and initial position exchange
		void Position(void);      // assigns initial position to current position
		void initPosition(void);  // assigns current position to initial position
		void posCurInitJux(void); // current position and initial position switch places 

		// Read next position
		int nextX(void);
		int nextY(void);
		double nextXX(void);
		double nextYY(void);
		Cartesian nextPosition(void);

		// Read previous position
		int prevX(void);
		int prevY(void);
		double prevXX(void);
		double prevYY(void);
		Cartesian prevPosition(void);

		int TimeSlice(void);          // returns current _t
		int NumberOfSlices(void);     // returns current _n
		void TimeSlice(int time);     // assign time slices per second (_t) to nextPos/prevPos
		void NumberOfSlices(int num); // assign number of time slices (_n) that have passed

		
	protected:
		bool _at_rest, int _n, int _t;
		// bool _at_rest is set to TRUE if velocity = Zero.atOrigin(), reset to FALSE otherwise
		// int _n number of time increments since motion began
		// int _t size of time increments expressed as time_increment = 1 / _t
};

#endif
