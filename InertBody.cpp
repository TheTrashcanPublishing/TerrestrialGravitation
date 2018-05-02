#include "InertBody.h"


InertBody::InertBody(void) {
	position.atOrigin();
	velocity.atOrigin();
	_at_rest = TRUE; }

InertBody::InertBody(int a, int b) {
	position.x = a;
	position.y = b;
	position.concordanceInt();
	
	velocity.atOrigin();
	_at_rest = TRUE; }

InertBody::InertBody(double aa, double bb) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();
	
	velocity.atOrigin();
	_at_rest = TRUE; }

InertBody::InertBody(Cartesian pos) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	
	velocity.atOrigin();
	_at_rest = TRUE; }

InertBody::InertBody(int a, int b, int vx, int vy) {
	position.x = a;
	position.y = b;
	position.concordanceInt();
	
	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();
	
	Cartesian Zero;
	Zero.atOrigin();
	_at_rest = (velocity == Zero); }

InertBody::InertBody(double aa, double bb, double vxx, double vyy) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();
	
	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();
	
	Cartesian Zero;
	Zero.atOrigin();
	_at_rest = (velocity == Zero); }

InertBody::InertBody(Cartesian pos, Cartesian vel) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	
	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();
	
	Cartesian Zero;
	Zero.atOrigin();
	_at_rest = (velocity == Zero); }

InertBody::InertBody(const InertBody &bodyCopy) {
	position.xx = bodyCopy.position.xx;
	position.yy = bodyCopy.position.yy;
	position.concordanceDouble();
	
	velocity.xx = bodyCopy.velocity.xx;
	velocity.yy = bodyCopy.velocity.yy;
	velocity.concordanceDouble();
	
	Catesian Zero;
	Zero.atOrigin();
	_at_rest = (velocity == Zero); }

InertBody::operator=(const InertBody &bodyAssignment) {
	if !(this == bodyAssignment) {
		position.xx = bodyAssignment.position.xx;
		position.yy = bodyAssignment.position.yy;
		position.concordanceDouble();
		
		velocity.xx = bodyAssignment.velocity.xx;
		velocity.yy = bodyAssignment.velocity.yy;
		velocity.concordanceDouble();
		
		Cartesian Zero;
		Zero.atOrigin();
		_at_rest = (velocity == Zero); }
	return *this; }

InertBody::~InertBody(void) {
	delete position;
	delete velocity; }


// Read current position
int InertBody::X(void) { return position.x; }

int InertBody::Y(void) { return position.y; }

double InertBody::XX(void) { return position.xx; }

double InertBody::YY(void) { return postion.yy; }

Cartesian InertBody::Position(void) { return position; }


//Set current position		
void InertBody::X(int a) {
	position.x = a;
	position.concordanceInt();
	return; }

void InertBody::Y(int b) {
	position.y = b;
	postion.concordanceInt();
	return; }

void InertBody::X_Y(int a, int b) {
	position.x = a;
	position.y = b;
	position.concordanceInt();
	return; }

void InertBody::XX_YY(double aa, double bb) {
	position.xx = aa;
	position.yy = bb;
	position.concordanceDouble();
	return; }

void InertBody::XX(double aa) {
	position.xx = aa;
	position.concordanceDouble();
	return; }

void InertBody::YY(double bb) {
	position.yy = bb;
	position.concordanceDouble();
	return; }

void InertBody::Position(Cartesian pos) {
	position.xx = pos.xx;
	position.yy = pos.yy;
	position.concordanceDouble();
	return; }


// Read current velocity
int InertBody::VX(void) { return velocity.x; }

int InertBody::VY(void) { return velocity.y; }

double InertBody::VXX(void) { return velocity.xx; }

double InertBody::VYY(void) { return velocity.yy; }

Cartesian InertBody::Velocity(void) { return velocity; }

bool InertBody::AtRest(void) {
	bool BodyIsAtRest;
	Catesian Zero;
	Zero.atOrigin();
	BodyIsAtRest = (velocity == Zero);
	_at_rest = BodyIsAtRest;
	return BodyIsAtRest; }


//Set current velocity	
void InertBody::VX(int vx) {
	velocity.x = vx;
	velocity.concordanceInt();
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void InertBody::VY(int vy) {
	velocity.y = vy;
	velocity.concordanceInt();
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void InertBody::VX_VY(int vx, int vy) {
	velocity.x = vx;
	velocity.y = vy;
	velocity.concordanceInt();
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void InertBody::VXX_VYY(double vxx, double vyy) {
	velocity.xx = vxx;
	velocity.yy = vyy;
	velocity.concordanceDouble();
	Certesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void InertBody::VXX(double vxx) {
	velocity.xx = vxx;
	velocity.concordanceDouble();
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void InertBody::VYY(double vyy) {
	velocity.yy = vyy;
	velocity.concordanceDouble();
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }

void InertBody::Velocity(Cartesian vel) {
	velocity.xx = vel.xx;
	velocity.yy = vel.yy;
	velocity.concordanceDouble();
	Cartesian Zero.atOrigin();
	_at_rest = (velocity == Zero);
	return; }


// Read next position
int InertBody::nextX(void) {
	position.x = position.x + velocity.x;
	position.concordanceInt();
	return position.x; }

int InertBody::nextY(void) {
	position.y = position.y + velocity.y;
	position.concordanceInt();
	return position.y; }

double InertBody::nextXX(void) {
	position.xx = position.xx + velocity.xx;
	position.concordanceDouble();
	return position.xx; }

double InertBody::nextYY(void) {
	position.yy = position.yy + velocity.yy;
	position.concordanceDouble();
	return position.yy; }

Cartesian InertBody::nextPosition(void) {
	position.xx = position.xx + velocity.xx;
	position.yy = position.yy + velocity.yy;
	position.concordanceDouble();
	return position; }


// Read previous position
int InertBody::prevX(void) {
	position.x = position.x - velocity.x;
	position.concordanceInt();
	return position.x; }

int InertBody::prevY(void) {
	position.y = position.y - velocity.y;
	position.concordanceInt();
	return position.y; }

double InertBody::prevXX(void) {
	position.xx = position.xx - velocity.xx;
	position.concordanceDouble();
	return position.xx; }

double InertBody::prevYY(void) {
	position.yy = position.yy - velocity.yy;
	position.concordanceDouble();
	return position.yy; }

Cartesian InertBody::prevPosition(void) {
	position.xx = position.xx - velocity.xx;
	position.yy = position.yy - velocity.yy;
	position.concordanceDouble();
	return position; }

