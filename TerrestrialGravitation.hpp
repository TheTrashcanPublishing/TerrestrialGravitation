// TerrestrialGravitation Class for Use in Anything Requiring
// Terrestrial Gravitational Motion

#ifndef TERRESTRIALGRAVITATION_H
#define TERRESTRIALGRAVITATION_H

class TerrestrialGravitation
{
	public:
		int numberOfGravBodies;
		InertBody gravBodies[numberofGravBodies];
		int time, bool at_rest;
		int groundInt, double groundDouble, int gInt, double gDouble;
		TerrestrialGravitation();
		TerrestrialGravitation(int a, int b);
		TerrestrialGravitation(int a, int b, int t);
		TerrestrialGravitation(double aa, double bb);
		TerrestrialGravitation(double aa, double bb, int t);
		TerrestrialGravitation(int a, int b, int vx, int vy);
		TerrestrialGravitation(int a, int b, int vx, int vy, int t);
		TerrestrialGravitation(double aa, double bb, double vxx, double vyy);
		TerrestrialGravitation(double aa, double bb, double vxx, double vyy, int t);
		TerrestrialGravitation(Cartesian pos);
		TerrestrialGravitation(Cartesian pos, int t);
		TerrestrialGravitation(Cartesian pos, Cartesian vel);
		TerrestrialGravitation(Cartesian pos, Cartesian vel, int t);
		TerrestrialGravitation(const TerrestrialGravitation &terrgravCopy);
		operator=(const TerrestrialGravitation &terrgravAssignment);
		~TerrestrialGravitation();
		
		void T(int t);
		int T(void);
		
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
		
	private:
		bool _at_rest;
};

#endif
