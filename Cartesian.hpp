// Cartesian.hpp for TerrestrialGravitation Library Project

// Designed and Coded by Ray Arias for The Trashcan Software and
// Media Publication as part of TerrestricalGravitation,
// a software library intended for inclusion with the supplemental
// paper 2D Terrestrial (Nonturbulent) Gravitational Motion.

// class Cartesian is an freely accessible encapsulated class
// class InertBody, but also can be used independently in other
// programs.


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


#ifndef CARTESIAN_H
#define CARTESIAN_H

#include <cmath>

class Cartesian
{
	public:
		int x, y;
		double xx, yy;
		Cartesian(void);
		Cartesian(int a, b);
		Cartesian(double aa, bb);
		Cartesian(const Cartesian &cartecopy);
		operator=(const Cartesian &carteassignment);
		operator-(const Cartesian &cartenegative);
		operator+(const Cartesian &carte1, const Cartesian &carte2);
		operator-(const Cartesian &carte1, const Cartesian &carte2);
		operator*(const Cartesian &carte1, const Cartesian &carte2); // complex product
		operator/(const Cartesian &carte1, const Cartesian &carte2); // complex quotient
		bool operator==(const Cartesian &carteEqual1, const Cartesian &carteEqual2);
		bool operator!=(const Cartesian &carteUnequal1, const Cartesian &carteUnequal2);
		~Cartesian();
		
		// Read current position
		int X(void);
		int Y(void);
		double XX(void);
		double YY(void);
		Cartesian Position(void);

		//Set current position		
		void X(int a);
		void Y(int b);
		void XY(int a, int b);
		void XXYY(double aa, double bb);
		void XX(double aa);
		void YY(double bb);
		void Position(Cartesian pos);

		// Invert x coordinate, y coordinate, both coordinates, or input number
		void invertX(void);
		void invertY(void);
		void invertXY(void);
		int invert(int a);
		double invert(double aa);
		
		// Calculate distance from current position to...
		int distanceInt(void);            // origin
		double distanceDouble(void);
		double distance (void);           // same as distanceDouble(void)
		int distance(int a, int b);       // point given by (a, b)
		int distanceInt(int a, int b);
		double distance(double aa, double bb);
		double distanceDouble(double aa double bb);
		int distanceInt(Cartesian carte); // point given by carte
		double distanceDouble(Cartesian carte);
		double distance(Cartesian carte);

		// Calculate the degree angle from current position to...
		int angleInt(void);               // origin
		double angleDouble(void);
		double angle(void);               // same as angleDouble(void)
		int angle(int w, int z);          // point given by (w, z)
		int angleInt(int w, int z);
		double angle(double ww, double zz);
		double angleDouble(double ww, double zz);
		int angleInt(Cartesian carte);    // point given by carte
		double angleDouble(Cartesian carte);
		double angle(Cartesian carte)
		int quadrant(void);            // gives quardrant object (xx, yy) is in as
		                               // 1 for Quadrant I			2 for Quadrant II
		                               // 3 for Quadrant III		4 for Quadrant IV
		                               // -1 for positive x-axis	-2 for positive y-axis
									   // -3 for negative x-axis	-4 for negative y-axis
									   // 0 for origin
		int quadrant(int w, int z);         // same as above but coordinates given by (w, z)
		int quadrant(double ww, double zz); // same as above but coordinates given by (ww, zz)
		
		
		// Convert polar coordinates to rectangular (Cartesian) coordinates
		int rectangularX(int r, int thetaDeg);
		double rectagularXX(double rr, double thetaRad);
		int rectangularY(int r, int thetaDeg);
		double rectangularYY(double rr, double thetaRad);
		
		Cartesian rectangularC(int r, int thetaDeg);        // These functions return an
		Cartesian rectangularC(double rr, double thetaRad); // external Cartesian object
		                                                    // with (x, y) coordinates.
		void rectangular(int r, int thetaDeg);       // These functions set the current
		void rectangular(double rr, double ThetaRad) // Cartesian object to the (x, y)
		                                             // coordinates.
		
		
		// Check or force concordance between int coordinates and double coorindates
		bool concordance(void); // Check concordance, return TRUE if concordant
		void concordanceInt(void); // Force concordance, doubles must agree w/ ints
		void concordanceDouble(void); // Force concordance, ints must agree w/ doubles
		
		Cartesian atOrigin(void); // Assign to be at origin (0, 0) and return
		double DotProduct(const Cartesian &carte);
				// geometric vector dot product
};


#endif
