#ifndef GRAVITATIONALBODY_H
#define GRAVITATIONALBODY_H

#include "InertBody.hpp"

class GravitationalBody : public InertBody
{
	public:
		Cartesian initialPosition, Cartesian initialVelocity; 
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
		GravitationalBody(const &gravbodCopy);
		operator=(const &gravbodAssignment);
		~GravitationalBody(void);

		Cartesian bodyPos(void);
		Cartesian bodyVel(void);

		void placeBody(int a, int b);
		void placeBody(double aa, double bb);
		void placeBody(Cartesian pos);

		void giveVelocity(int vx, int vy);
		void giveVelocity(double vxx, double vyy);
		void giveVelocity(Cartesian vel);

		void initPosition(int ix, int iy);
		void initPosition(double ixx, double iyy);
		void initPosition(Cartesian ipos);

		void initVelocity(int ivx, int ivy);
		void initVelocity(double ivxx, double ivyy);
		void initVelocity(Cartesian ivel);

		void initPosition(void); // assign current position to initialPosition
		void initVelocity(void); // assign current velocity to initialVelocity
		void beginMotion(void);  // same as initVelocity()
		void haltMotion(void);   // call veloity.atOrigin() and halt motion of body 
};

#endif
