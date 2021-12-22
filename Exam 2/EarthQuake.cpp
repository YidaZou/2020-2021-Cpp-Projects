/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>       /* fabs */
#include <limits>

#include "EarthQuake.h"

using namespace std;

// QuakeDataSegment constructors
/* TODO */
QuakeDataSegment::QuakeDataSegment() :
	waveAmplitude(0),
	latitude(0),
	longitude(0),
	depth(0)

{}

/* TODO */
QuakeDataSegment::QuakeDataSegment(double wa, double lat, double longi, double dep) :
	waveAmplitude(wa),
	latitude(lat),
	longitude(longi),
	depth(dep)

{}

// overloaded output operator for QuakeDataSegment
ostream &operator<< (ostream &os, const QuakeDataSegment &x) //remember x is an alias
{
	os << "waveAmplitude: " <<  x.getWaveAmplitude() << endl;
	os << "latitude: " <<  x.getLatitude() << endl;
	os << "longitude: " <<  x.getLongitude() << endl;
	os << "depth: " <<  x.getDepth() << endl;
	return os;
}

// EarthQuake constructor
EarthQuake::EarthQuake() :
	lengthOfQuake(0),
	// this is used so you don't have to pass the size
	maxAmplitude(numeric_limits<double>::max()),
	minAmplitude(numeric_limits<double>::min()),

	sWaveIndex(0),

	localGpsLatitude(30.6), localGpsLongitude(-96.3),
	// College Station TX coordinates

	earthquakeGpsLatitude(0.0),  // - if South
	earthquakeGpsLongitude(0.0), // - if West

	distanceFromQuake(0),

	movedLatLong(false),
	movedDepth(false)
{}

// getters
int EarthQuake::getLengthOfQuake() const { return lengthOfQuake;	}
double EarthQuake::getMaxAmplitude() const { return maxAmplitude; }
double EarthQuake::getMinAmplitude() const { return minAmplitude; }
unsigned int EarthQuake::getSWaveIndex() const { return sWaveIndex; }
string EarthQuake::getEarthquakeLocation() const
{ return to_string(earthquakeGpsLongitude) + " " + to_string(earthquakeGpsLatitude); }
bool EarthQuake::getChangeInLatLong() const { return movedLatLong; }
bool EarthQuake::getChangeInDepth() const { return movedDepth; }
unsigned int EarthQuake::getDistanceFromQuake() const { return distanceFromQuake; }

void EarthQuake::setDistanceFromQuake()
{
	int R = 6371; // radius = 6371 kilometers
	double x = earthquakeGpsLatitude * M_PI/180; // in radians
	double y = localGpsLatitude * M_PI/180;
	double deltaX = (localGpsLongitude -earthquakeGpsLongitude) * M_PI/180;
	double deltaY = (localGpsLatitude -earthquakeGpsLatitude) * M_PI/180;

	double a = sin(deltaY/2) * sin(deltaY/2) +
			  cos(x) * cos(y) *
			  sin(deltaX/2) * sin(deltaX/2);
	distanceFromQuake = (2 * R * atan2(sqrt(a), sqrt(1-a))); // in meters
}

void EarthQuake::displayDataSegment(QuakeDataSegment * dS) const
{
	for (unsigned int i = 0; i < lengthOfQuake; i++)
	{
		// using overloaded QuakeDataSegment
		cout << "******************" << endl;
		cout << "at second " << (i + 1) << endl;
		cout << dS[i] << endl;
	}
}

// functions for setting and loading data
void EarthQuake::loadEarthquakeData(QuakeDataSegment*& dS, string file)
{
	// TODO
	if(file.find(".txt") == string::npos){
		throw std::invalid_argument("not .txt file");
	}
	ifstream ifs (file);
	if (!ifs.is_open()) {
    throw std::invalid_argument("unable to open file");
  }
	lengthOfQuake = 0;
	string line;
	double w,lt,lg,d;
	while(!ifs.eof()){
		getline(ifs,line);
		if(line==""){
			break;
		}
    istringstream numbers(line);
		resizeArray(dS);
		numbers >>w>>lt>>lg>>d;
		dS[lengthOfQuake-1] = {w,lt,lg,d};
	}
}

void EarthQuake::resizeArray(QuakeDataSegment*& segarr)
{
	// TODO
	QuakeDataSegment* newA = new QuakeDataSegment[lengthOfQuake+1];
	for(unsigned int i=0; i<lengthOfQuake; i++){
		newA[i] = segarr[i];
	}
	delete[] segarr;
	segarr=newA;
	lengthOfQuake++;
}


void EarthQuake::setMaxAmplitude(QuakeDataSegment* segarr)
{
	// TODO
	maxAmplitude = fabs(segarr[0].getWaveAmplitude());
	for(unsigned int i=1;i<lengthOfQuake;i++){
		if(fabs(segarr[i].getWaveAmplitude())>maxAmplitude){
			maxAmplitude=fabs(segarr[i].getWaveAmplitude());
		}
	}
}

void EarthQuake::setMinAmplitude(QuakeDataSegment* segarr)
{
	// TODO
	minAmplitude = fabs(segarr[0].getWaveAmplitude());
	for(unsigned int i=1;i<lengthOfQuake;i++){
		if(fabs(segarr[i].getWaveAmplitude())<minAmplitude){
			minAmplitude=fabs(segarr[i].getWaveAmplitude());
		}
	}
}

void EarthQuake::setSWaveIndex(QuakeDataSegment* segarr)
{
	// TODO
	for(unsigned int i=1;i<lengthOfQuake;i++){
		if(segarr[i-1].getWaveAmplitude()*4<=segarr[i].getWaveAmplitude()){
			sWaveIndex=i;
			break;
		}
	}
}

void EarthQuake::setEarthquakeLocation(QuakeDataSegment* segarr)
{
	// TODO
	earthquakeGpsLatitude = segarr[0].getLatitude();
	earthquakeGpsLongitude = segarr[0].getLongitude();
}

void EarthQuake::setChangeInLatLong(QuakeDataSegment* segarr)
{
	// set default from [0] for lat and long, see if it changes
	movedLatLong = false;
	double defaultLat = segarr[0].getLatitude();
	double defaultLong = segarr[0].getLongitude();
	for(unsigned int i=1;i<lengthOfQuake;i++){
		if(defaultLat!=segarr[i].getLatitude() || defaultLong!=segarr[i].getLongitude()){
			//cout<<"i: "<<i<<" !!!Diff-- Lat: "<<segarr[i].getLatitude()<<" Long: "<<segarr[i].getLongitude();
			movedLatLong = true;
			break;
		}
	}
}

void EarthQuake::setChangeInDepth(QuakeDataSegment* segarr)
{
	// set default from [0] for depth, see if it changes
	movedDepth = false;
	double defaultDepth = segarr[0].getDepth();
	for(unsigned int i=1;i<lengthOfQuake;i++){
		if(defaultDepth!=segarr[i].getDepth()){
			movedDepth = true;
			break;
		}
	}
}

ostream &operator << (ostream &os, const EarthQuake &x)
{
	os << "Max amp: " << x.getMaxAmplitude() << endl;
	os << "Min amp: " << x.getMinAmplitude() << endl;
	os << "Length of Quake: " << x.getLengthOfQuake() << endl;
	os << "S wave arrival (in seconds): " << x.getSWaveIndex() << endl;
	os << "Location of Quake: " << x.getEarthquakeLocation() << endl;
	os << "Distance from Quake: " << x.getDistanceFromQuake() << "km " << endl;
	os << "Did quake lat/long move? (0/1): " << x.getChangeInLatLong() << endl;
	os << "Did quake depth move? (0/1): " << x.getChangeInDepth() << endl;
	return os;
}
