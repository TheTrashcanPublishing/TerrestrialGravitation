#ifndef INERTBODY_H
#define INERTBODY_H

class InertBody
{
	public:
		Cartesian position, Cartesian velocity;
		InertBody(void);
		InertBody(int a, int b);
		InertBody(double aa, double bb);
		InertBody(Cartesian pos);
		InertBody(int a, int b, int vx, int vy);
		InertBody(double aa, double bb, double vxx, double vyy);
		InertBody(Cartesian pos, Cartesian vel);
		InertBody(const InertBody &bodyCopy);
		operator=(const InertBody &bodyAssignment);
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
		void XX_YY(double aa, double bb);
		void XX(double aa);
		void YY(double bb);
		void Position(Cartesian pos);

		// Read current velocity
		int VX(void);
		int VY(void);
		double VXX(void);
		double VYY(void);
		Cartesian Velocity(void);
		bool AtRest(void);

		//Set current velocity	
		void VX(int vx);
		void VY(int vy);
		void VX_VY(int vx, int vy);
		void VXX_VYY(double vxx, double vyy);
		void VXX(double vxx);
		void VYY(double vyy);
		void Velocity(Cartesian vel);

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
		
	protected:
		bool _at_rest;
};

#endif
