// GravitationalBody.hpp for TerrestrialGravitation Library Project

// Designed and Coded by Ray Arias for The Trashcan Software and
// Media Publication as part of TerrestricalGravitation,
// a software library intended for inclusion with the supplemental
// paper 2D Terrestrial (Nonturbulent) Gravitational Motion.

// The class GravitationalBody is a subclass of class InertBody.
// The class GravitationalBody inherits all members of class
// InertBody and also has Cartesian InitialPosition and Cartesian
// InitialVelocity as variable members.
 

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


#ifndef GRAVITATIONALBODY_H
#define GRAVITATIONALBODY_H

#include "InertBody.hpp"

class GravitationalBody : protected InertBody
{
	public:
		Cartesian initialVelocity; // public variable member
		
		// constructors
		GravitationalBody(void);
		GravitationalBody(int a, int b);
		GravitationalBody(double aa, double bb);
		GravitationalBody(Cartesian pos);
		GravitationalBody(int a, int b, int vx, int vy);
		GravitationalBody(double aa, double bb, double vxx, double vyy);
		GravitationalBody(Cartesian pos, Cartesian vel);
		GravitationalBody(int a, int b, int vx, int vy, int ix, int iy);
		GravitationalBody(double aa, double bb, double vxx, double vyy,
			double ixx, double iyy);
		GravitationalBody(Cartesian pos, Cartesian vel, Cartesian ipos);
		GravitationalBody(int a, int b, int vx, int vy, int ix, int iy, int ivx, int ivy);
		GravitationalBody(double aa, double bb, double vxx, double vyy,
			double ixx, double iyy, double ivxx, double ivyy);
		GravitationalBody(Cartesian pos, Cartesian vel, Cartesian ipos, Cartesian ivel);
		GravitationalBody(int a, int b, int vx, int vy, int ix, int iy, int ivx, int ivy,
			int grnd);
		GravitationalBody(double aa, double bb, double vxx, double vyy,
			double ixx, double iyy, double ivxx, double ivyy, double ggrnd);
		GravitationalBody(Cartesian pos, Cartesian vel, Cartesian ipos, Cartesian ivel,
		    double ggrnd);
		GravitationalBody(int a, int b, int vx, int vy, int ix, int iy, int ivx, int ivy,
			int grnd, int agv);
		GravitationalBody(double aa, double bb, double vxx, double vyy,
			double ixx, double iyy, double ivxx, double ivyy, double ggrnd, double aagv);
		GravitationalBody(Cartesian pos, Cartesian vel, Cartesian ipos, Cartesian ivel,
		    double ggrnd, double aagv);
		GravitationalBody(int a, int b, int vx, int vy, int ix, int iy, int ivx, int ivy,
			int grnd, int agv, int epsln100);
		GravitationalBody(double aa, double bb, double vxx, double vyy,
			double ixx, double iyy, double ivxx, double ivyy, double ggrnd, double aagv
			double epsilon);
		GravitationalBody(Cartesian pos, Cartesian vel, Cartesian ipos, Cartesian ivel,
		    double ggrnd, double aagv, double epsilon);
		GravitationalBody(const GravitationBody &gravbodCopy);
		operator=(const GravitationalBody &gravbodAssignment);
		~GravitationalBody(void);

		// read current position and current velocity of object
		Cartesian bodyPos(void);
		Cartesian bodyVel(void);

		// assign current position of object
		void placeBody(int a, int b);
		void placeBody(double aa, double bb);
		void placeBody(Cartesian pos);

		// assign current velocity of object
		void giveVelocity(int vx, int vy);
		void giveVelocity(double vxx, double vyy);
		void giveVelocity(Cartesian vel);

		// assign initial position of object
		void initPosition(int ix, int iy);
		void initPosition(double ixx, double iyy);
		void initPosition(Cartesian ipos);

		// assign initial velocity of object
		void initVelocity(int ivx, int ivy);
		void initVelocity(double ivxx, double ivyy);
		void initVelocity(Cartesian ivel);

		void initPosition(void); // assign current position to initialPosition
		void initVelocity(void); // assign current velocity to initialVelocity
		void beginMotion(void);  // same as initVelocity()
		void haltMotion(void);   // call veloity.atOrigin() and halt motion of body

		// Read next velocity
		int nextVX(void);
		int nextVY(void);
		double nextVXX(void);
		double nextVYY(void);
		Cartesian nextVelocity(void);

		// Read previous velocity
		int prevVX(void);
		int prevVY(void);
		double prevVXX(void);
		double prevVYY(void);
		Cartesian prevVelocity(void);

		// Read next position (overloading for y and yy only)
		int nextY(void);
		double nextYY(void);
		Cartesian nextPosition(void);

		// Read previous position (overloading for y and yy only)
		int prevY(void);
		double prevYY(void);
		Cartesian prevPosition(void);

	protected:
		int _ground, double _gground, long int _accgrav, double _aaccgrav; // protected
		int _cor100, double _ccor, bool _groundOn, bool _gravOn;    // variable members
		// int _ground and double _gground are horizontal y/yy-level ground
		// long int _accgrav and double _aacgrav are acceleration of gravity
		// int _cor100 is percentage of coefficient of restitution (bouceback from ground)
		// double _ccor is same expressed as pure decimal
		// _groundOn switches the horizonal ground on (or off)
		// _gravOn switches the gravity on (or off)
		
		void _G(long int ag);      // assign acceleration of gravity in int
		void _GG(double aag); // assign acceleration of gravity in double
		void _GMS2(void);     // assign acceleration of gravity to micron/sec/sec
		void _GGSI(void);     // assign acceleration of gravity to SI units
		void _GGCGS(void);    // assign acceleration of gravity to CGS units
		void _GGUS(void);     // assign acceeleration of gravity to standard US units
		void _GGIS2(void);    // assign acceleration of gravity to inches/sec/sec
		void _G1000IS2(void); // acceleration of gravity to 1000ths of inches/sec/sec
		void _GroundInt(int grd);               // assign ground level in int
		void _GroundDouble(double ggrd);        // assign ground level in double
		void _CoeffRestn100(int epsln100);      // assign coefficient of restitution in
		                                        // int perccent
		void _CoeffRestnDouble(double epsilon); // assign coefficient of restitution
		                                        // in double
		void _GroundOn(void);     // turn the ground level on
		void _GroundOff(void);    // turn the ground level off
		void _GravOn(void);       // turn gravity on
		void _GravOff(void);      // turn gravity off
		
		// concordance of ground, accleration of gravity, and coefficient of restitution
		bool _concordance(void);         // returns TRUE if ints and doubles agree,
										 // FALSE otherwise
		void _concordanceInt(void);      // forces concordance of doubles with ints
		void _concordanceDouble(void);   // forces concordance of ints with doubles		
};

#endif
