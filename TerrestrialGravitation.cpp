

#include "TerrestrialGravitation.h"

#define _DEFAULT_TIME 30
#define GSI 9.80665  // Standard gravity on Earth in SI units = 9.80665 m/sec/sec
#define GCGS 980.665 // Standard gravity on Earth in CGS units = 980.665 cm/Sec/sec
#define GMS2 9806650 // Standard gravity on Earth in microns/sec/sec
#define GUS 32.1740  // Standard gravity on Earth in US units = 32.1740 ft/sec/sec
#define GIS2 386.088 // Standard gravity on Earth in inches/sec/sec = 386.088 in/s/s
#define G1000IS2 386088 // Standard gravity on Earth in 1000ths of inches/sec/sec


TerrestrialGravitation::TerrestrialGravitation() {
	position.xx = velocity.xx = 0.0F;
	position.yy = velocity.yy = 0.0F;
	position.x = velocity.x = 0;
	position.y = velocity.y = 0;
	time = _DEFAULT_TIME;
	_at_rest = TRUE; }

TerrestrialGravitation::TerrestrialGravitation(int a, int b) {
	position.x = a;
	position.y = b;
	position.xx = (double) a;
	position.yy = (double) b;
	
	velocity.xx = velocity.yy = 0.0F;
	velocity.x = velocity.y = 0;
	
	time = _DEFAULT_TIME;
	_at_rest = TRUE; }

TerrestrialGravitation::TerrestrialGravitation(int a, int b, int t) {
	position.x = a;
	position.y = b;
	position.xx = (double) a;
	position.yy = (double) b;
	
	velocity.xx = velocity.yy = 0.0F;
	velocity.x = velocity.y = 0;
	
	time = t;
	_at_rest = TRUE; }

TerrestrialGravitation::TerrestrialGravitation(double aa, double bb,
		double vxx, double vyy) {
	position.xx = aa;
	position.yy = bb;
	position.x = (int) aa;
	position.y = (int) bb;
	
	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.x = (int) vxx;
	velocity.y = (int) vyy; 
	
	time = _DEFAULT_TIME;
	_at_rest = ((vxx == vyy) == 0.0F); }
	


TerrestrialGravitation::TerrestrialGravitation(double aa, double bb,
		double vxx, double vyy, int t) {
	position.xx = aa;
	position.yy = bb;
	position.x = (int) aa;
	position.y = (int) bb;
	
	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.x = (int) vxx;
	velocity.y = (int) vyy; 
	
	time = t;
	_at_rest = ((vxx == vyy) == 0.0F); }
	
TerrestrialGravitation::TerrestrialGravitation(int a, int b, int vx, int vy) {
	position.x = a;
	position.y = b;
	position.xx = (double) a;
	position.yy = (double) b;
	
	velocity.x = vx;
	velocity.y = vy;
	velocity.xx = (double) vx;
	velocity.yy = (double) vy;
	
	time = _DEFAULT_TIME;
	_at_rest = ((vxx == vyy) == 0.0F); }

TerrestrialGravitation::TerrestrialGravitation(int a, int b, int vx, int vy, int t) {
	position.x = a;
	position.y = b;
	position.xx = (double) a;
	position.yy = (double) b;
	
	velocity.x = vx;
	velocity.y = vy;
	velocity.xx = (double) vx;
	velocity.yy = (double) vy;
	
	time = t;
	_at_rest = ((vx == vy) == 0); }

TerrestrialGravitation::TerrestrialGravitation(Cartesian pos) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	
	velocity.xx = velocity.yy = 0.0F;
	velocity.x = velocity.y = 0;
	
	time = _DEFAULT_TIME;
	_at_rest = TRUE; }

TerrestrialGravitation::TerrestrialGravitation(Cartesian pos, int t) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	
	velocity.xx = velocity.yy = 0.0F;
	velocity.x = velocity.y = 0;
	
	time = t;
	_at_rest = TRUE; }


TerrestrialGravitation::TerrestrialGravitation(Cartesian pos, Cartesian vel) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	
	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();
	
	time = _DEFAULT_TIME;
	_at_rest = ((vel.xx == vel.yy) == 0.0F); }

TerrestrialGravitation::TerrestrialGravitation(Cartesian pos, Cartesian vel, int t) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	
	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();
	
	time = t;
	_at_rest = ((vel.xx == vel.yy) == 0.0F); }

TerrestrialGravitation::TerrestrialGravitation(
		const TerrestrialGravitation &terrgravCopy) {
	position.xx = terrgravCopy.position.xx;
	position.yy = terrgravCopy.position.yy;
	position.concordanceDouble();
	
	velocity.xx = terrgravCopy.velocity.xx;
	velocity.yy = terrgravCopy.velocity.yy;
	velocity.concordanceDouble();
	
	time = terrgravCopy.time;
	_at_rest = ((velocity.xx == velocity.yy) == 0.0F; }

TerrestrialGravitation::operator=(const TerrestrialGravitation &terrgravAssignment) {
	if (this != terrgravAssignment) {
		position.xx = terrgravAssignment.position.xx;
		position.yy = terrgravAssignment.position.yy;
		position.concordanceDouble();
		
		velocity.xx = terrgravAssignment.velocity.xx;
		velocity.yy = terrgravAssignment.velocity.yy;
		velocity.concordanceDouble();
		
		time = terrgravAssignment.time; 
		_at_rest = ((velocity.xx == velocity.yy) == 0.0F); }
	return *this; }


TerrestrialGravitation::~TerrestrialGravitation() {
	delete position;
	delete velocity;
}

int TerrestrialGravitation::X(void) { return position.x; }

double TerrestrialGravitation::XX(void) { return position.xx; }

int TerrestrialGravitation::Y(void) { return position.y; }

double TerrestrialGravitation::YY(void) { return position.yy; }

Cartesian TerrestrialGravitation::Position(void) { return position; }

int TerrestrialGravitation::VX(void) { return velocity.x; }

double TerrestrialGravitation::VXX(void) { return velocity.xx; }

int TerrestrialGravitation::VY(void) { return velocity.y; }

double TerrestrialGravitation::VYY(void) { return velocity.yy; }

Cartesian TerrestrialGravitation::Velocity(void) { return velocity; }

void TerrestrialGravitation::T(int t) {        // Set fineness of time division
	time = t;
	return; }

int TerrestrialGravitation::T(void) { return time; }

void TerrestrialGravitation::X(int a) {
	position.x = a;
	position.xx = (double) a;
	return; }

void TerrestrialGravitation::Y(int b) {
	position.y = b;
	position.yy = (double) b;
	return; }

void TerrestrialGravitation::XX(double aa) {
	position.xx = aa;
	position.x = (int) aa;
	return; }

void TerrestrialGravitation::YY(double bb) {
	position.yy = bb;
	position.y = (int) bb;
	return;
}

void TerrestrialGravitation::posConcordInt(void) {
	position.xx = (double) position.x;
	position.yy = (double) position.y; 
	return; }

void TerrestrialGravitation::posConcordDoub(void) {
	position.x = (int) position.xx;
	position.y = (int) position.yy;
	return; }

bool TerrestrialGravitation::posConcord(void) {
	bool pass = (position.x == (int) position.xx);
	if (pass) pass = (position.y == (int) position.yy);
	return pass; }

void TerrestrialGravitation::Position(int a, int b) {
	position.x = a;
	position.y = b;
	position.concordanceInt();
	return; }

void TerrestrialGravitation::Position(double aa, double bb) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();
	return; }

void TerrestrialGravitation::Position(Cartesian pos) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	return; }

void TerrestrialGravitation::VX(int vx) {
	velocity.x = vx;
	velocity.xx = (double) vx;
	_at_rest = ((vx == velocity.y) == 0);
	return; }

void TerrestrialGravitation::VY(int vy) {
	velocity.y = vy;
	velocity.yy = (double) vy;
	_at_rest = ((vy == velocity.x) == 0);
	return; }

void TerrestrialGravitation::VXX(double vxx) {
	velocity.xx = vxx;
	velocity.x = (int) vxx;
	_at_rest = ((vxx == velocity.yy) == 0.0F);
	return; }

void TerrestrialGravitation::VYY(double vyy) {
	velocity.yy = vyy;
	velocity.y = (int) vyy;
	_at_rest = ((vyy == velocity.xx) == 0.0F);
	return; }

void TerrestrialGravitation::velConcordInt(void) {
	velocity.xx = (double) velocity.x;
	velocity.yy = (double) velocity.y;
	_at_rest = ((velocity.x == velocity.y) ==0);
	return; }

void TerrestrialGravitation::velConcordDoub(void) {
	velocity.x = (int) velocity.xx;
	velocity.y = (int) velocity.yy;
	_at_rest = ((velocity.xx == velocity.yy) == 0.0F);
	return; }

bool TerrestrialGravitation::velConcord(void) {
	bool pass = (velocity.x == (int) velocity.xx);
	if (pass) pass = (velocity.y == (int) velocity.yy);
	return pass; }

void TerrestrialGravitation::Velocity(int vx, int vy) {
	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();
	_at_rest = ((vx == vy) == 0);
	return; }

void TerrestrialGravitation::Velocity(double vxx, double vyy) {
	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();
	_at_rest = ((vxx == vyy) == 0.0F)
	return; }

void TerrestrialGravitation::Velocity(Cartesian vel) {
	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();
	_at_rest = ((vel.xx == vel.yy) == 0.0F);
	return; }

void TerrestrialGravitation::StartX(int a) {
	X(a);
	XX((double) a);
	return; }

void TerrestrialGravitation::StartY(int y) {
	Y(b);
	YY((double) b);
	return; }

void TerrestrialGravitation::StartXX(double aa) {
	XX(aa);
	X((int) aa);
	return; }

void TerrestrialGravitation::StartYY(double bb) {
	YY(bb);
	Y((int) bb);
	return; }

void TerrestrialGravitation::StartPosition(Cartesian pos) {
	Position(pos);
	return; }

void TerrestrialGravitation::StartVX(int vx) {
	VX(vx);
	_at_rest = ((vx == velocity.y) == 0);
	return; }

void TerrestrialGravitation::StartVY(int vy) {
	VY(vy);
	_at_rest = ((vy == velocity.x) == 0);
	return; }

void TerrestrialGravitation::StartVXX(double vxx) {
	VXX(vxx);
	_at_rest = ((vxx == velocity.yy) == 0.0F);
	return; }

void TerrestrialGravitation::StartVYY(double vyy) {
	VYY(vyy);
	_at_rest = ((vyy == velocity.x) == 0.0F)
	return; }

void TerrestrialGravitation::StartVelocity(Cartesian vel) {
	Velocity(vel);
	_at_rest = ((vel.xx == vel.yy) ==0.0F);
	return; }

void TerrestrialGravitation::BeginMotion(void) { // Begin object motion
	_at_rest = FALSE;
}

void TerrestrialGravitation::PrevPos(void) {     // Move object to previous position
	velocity.yy = velocity.yy + (GG / (double) t);
	position.yy = position.yy - (velocity.yy / (double) t);
	position.xx = position.xx - (velocity.xx / (double) t);
	position.concordanceDouble();
	velocity.concordanceDouble();
	_at_rest = ((velocity.xx == velocity.yy) == 0.0F); }

void TerrestrialGravitation::NextPos(void) {     // Move object to next position
	velocity.yy = velocity.yy - (GG / (double) t);
	position.yy = position.yy + (velocity.yy / (double) t);
	position.xx = position.xx + (velocity.xx / (double) t);
	position.concordanceDouble();
	velocity.concordanceDouble();
	_at_rest = ((velocity.xx == velocity.yy) == 0.0F); }

void TerrestrialGravitation::HaltMotion(void) {  // Halt motion at current position
	_at_rest = TRUE;
	velocity.xx = 0.0F;
	velocity.yy = 0.0F;
	velocity.concordanceDouble();
}

