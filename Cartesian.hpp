#ifndef CARTESIAN_H
#define CARTESIAN_H

#include <cmath>

class Cartesian
{
	public:
		int x, y;
		double xx, yy;
		Cartesian();
		Cartesian(int a, b);
		Cartesian(double aa, bb);
		Cartesian(const Cartesian &cartecopy);
		operator=(const Cartesian &carteassignment);
		operator+(const Cartesian &carte1, const Cartesian &carte2);
		operator-(const Cartesian &carte1, const Cartesian &carte2);
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
		
		// Calculate distance from current position to...
		int distanceInt(void);            // origin
		double distanceDouble(void);
		double distance (void);           // same as distanceDouble(void)
		int distance(int a, int b);       // point given by (a, b)
		double distance(double aa, double bb); 
		int distanceInt(Cartesian carte); // point given by carte
		double distanceDouble(Cartesian carte);
		double distance(Cartesian carte);

		// Calculate the degree angle from current position to...
		int angleInt(void);               // origin
		double angleDouble(void);
		double angle(void);               // same as angleDouble(void)
		int angle(int w, int z);          // point given by (w, z)
		double angle(double ww, double zz);
		int angleInt(Cartesian carte);    // point given by carte
		double angleDouble(Cartesian carte);
		double angle(Cartesian carte);
		
		// Check or force concordance between int coordinates and double coorindates
		bool concordance(void); // Check concordance, return TRUE if concordant
		void concordanceInt(void); // Force concordance, doubles must agree w/ ints
		void concordanceDouble(void); // Force concordance, ints must agree w/ doubles
		
		Cartesian atOrigin(void); // Assign to be at origin (0, 0) and return
};


#endif
