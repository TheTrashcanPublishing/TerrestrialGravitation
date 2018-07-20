// TerrestrialGravitation.hpp for TerrestrialGravitation Library Project

// For use in anything requiring terrestrial gravitational motion.
// Class TerrestrialGravitation is a wrapper class for GravitationalBody
// objects. 

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


#ifndef TERRESTRIALGRAVITATION_H
#define TERRESTRIALGRAVITATION_H

class TerrestrialGravitation
{
	public:
		unsigned int numberOfGravBodies;
		GravitationalBody[] gravBody[numberofGravBodies];
		unsigned int groundSlices, sliceWidthInt;
		unsigned double sliceWidthDouble;
		signed int [] groundInt[groundSlices];
		signed double [] groundDouble [groundSlices];
		unsigned int time, signed int gInt, signed double gDouble;
		TerrestrialGravitation(void);
		TerrestrialGravitation(unsigned int numGbodies);
		TerrestrialGravitation(unsigned int numGbodies, unsigned int grSlices);
		TerrestrialGravitation(unsigned int numGbodies, unsigned int grSlices, unsigned int t);
		TerrestrialGravitation(unsigned int numGbodies, unsigned int grSlices, unsigned int t,
			signed int gI);
		TerrestrialGravitation(unsigned int numGbodies, unsigned int grSlices, unsigned int t,
			signed double gD);
		TerrestrialGravitation(unsigned int numGbodies, unsigned int grSlices, unsigned int t,
			signed int gI, signed int grdInt);
		TerrestrialGravitation(unsigned int numGbodies, unsigned int grSlices, unsigned int t,
			signed double gD, signed double grdDouble);
		TerrestrialGravitation(unsigned int numGbodies, unsigned int t, signed int gI,
			string fname);
		TerrestrialGravitation(unsigned int numGbodies, unsigned int t, signed double gD,
			string fname);
		TerrestrialGravitation(string fname);
		TerrestrialGravitation();
		TerrestrialGravitation();
		TerrestrialGravitation(const TerrestrialGravitation &terrgravCopy);
		operator=(const TerrestrialGravitation &terrgravAssignment);
		~TerrestrialGravitation();
		
		void T(unsigned int t);
		int T(void);
		
		void initGround(void);
		void initGround(unsigned int grdInt);
		void initGround(unsigned double grdDouble);
		void initGround(string fname);
		
		void initBodies(void);
		void initBodies(Cartesian pos, Cartesian vel, Cartesian ipos, Cartesian ivel);
		void initBody(unsigned int bodyNum, Cartesian pos, Cartesian vel, Cartesian ipos,
			Cartesian ivel);
		
		void initAllMembers(string fname);
		
		// Read current position of TerrestrialGravitation object
		int X(void);
		int Y(void);
		double XX(void);
		double YY(void);
		Cartesian Position(void);
		
		// Read current velocity of TerrestrialGravitation object
		int VX(void);
		int VY(void);
		double VXX(void);
		double VYY(void);
		Cartesian Velocity(void);
		
        void T(int t); // Set fineness of time division

		// Set current position of TerrestrialGravitation object
		void X(int a);
		void Y(int b);
		void XX(double aa);
		void YY(double bb);
		void Position(int a, int b);
		void Position(double aa, double bb);
		void Position(Cartesian pos);
		
		// Set current velocity of TerrestrialGravitation object
		void VX(int vx);
		void VY(int vy);
		void VXX(double vxx);
		void VYY(double vyy);
		void Velocity(int vx, int vy);
		void Velocity(double vxx, double vyy);
		void Velocity(Cartesian vel);
		
		// Set starting position of TerrestrianGravitation object
		void StartX(int a);
		void StartY(int b);
		void StartXX(double aa);
		void StartYY(double bb);
		void StartPosition(Cartesian pos);
		
		// Set starting velocity of TerrestrialGravitation object
		void StartVX(int vx);
		void StartVY(int vy);
		void StartVXX(double vxx);
		void StartVYY(double vyy);
		void StartVelocity(Cartesian vel);
		
		void PlaceGround(int b);
		void PlaceGround(double bb);

		void BeginMotion(void); // Begin object motion
		void PrevPos(void);     // Move object to previous position
		void NextPos(void);     // Move object to next position
		void HaltMotion(void);  // Halt motion at current position

protected:
		bool _sliceConcordance(int slice);
		void _sliceConcordanceInt(int slice;
		void _sliceConcordanceDouble(int slice);
	
		bool _groundConcordance(void);
		void _groundConcordanceInt(void);
		void _groundConcordanceDouble(void);
		
};

#endif
