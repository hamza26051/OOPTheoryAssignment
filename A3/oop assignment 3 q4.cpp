#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h> 
#include <unistd.h>

using namespace std;

class Flyable {
public:
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};

class Scannable {
public:
    virtual void scanArea(float radius) = 0;
};
class Drone{
	protected:
	float Latitude;
	float Longitude;
	float Altitude;
	float Speed;
	
	public:
		Drone(float la, float lo, float alt, float spe){
			Latitude=la;
			Longitude=lo;
			Altitude=alt;
			Speed=spe;
		}
		void adjustAltitude(float alti){
			Altitude+=alti;
			cout<<"the altitude now is "<<Altitude<<endl;
		}
		void setSpeed(float spee){
			Speed+= spee;
			cout<<"the speed now is"<<Speed<<endl;
		}
	
};

class ReconDrone: public Flyable, public Scannable, public Drone{
	float CameraResolution;
		float maxFlightTime;
		public:
				ReconDrone(float resolution, float maxtime, float la, float lo, float alt, float spe):Drone(la,lo,alt,spe){
					CameraResolution=resolution;
					maxFlightTime=maxtime;
				}
			void land()override{
				cout<<"the plane is now taking off"<<endl;
			}
			void takeoff()override{
				cout<<"the plane is now landing"<<endl;
			}
			void navigateTo(float latitude, float longitude, float altitude)override{
				Latitude=latitude;
				Longitude=longitude;
				Altitude=altitude;
				
				cout<<"changing the direction of the plane..."<<endl;
				sleep(5);
				cout<<"The latitude now is:"<<Latitude<<"\nLongitude is:"<<Longitude<<"\nand the altitude is:"<<Altitude<<endl;
				if (Altitude>1000){
					cout<<"error communicating with the drone"<<endl;
					exit(1);
				}
			}
			void scanArea(float radius)override{
				cout<<"scanning!.....";
				sleep(5);
			int objectsDetected = rand() % 10;
			cout<<"Number of objects detected is:"<<objectsDetected<<endl;
			for (int i=0;i<objectsDetected;i++){
				float objectLatitude;
				float objectLongitude;
				objectLatitude= Latitude + rand()% static_cast<int>(radius);
				objectLongitude= Longitude+rand()% static_cast<int>(radius);
				sleep(2);
				cout<<"Latitude of the detected object"<<i<<"is:"<<objectLatitude<<endl;
				cout<<"Longitude of the detected object"<<i<<"is:"<<objectLongitude<<endl;
			}
			if (objectsDetected>=9){
				cout<<"Error, signals lost!....";
				exit(1);
			}
			}
};

int main(){
	ReconDrone recon1(500.0, 16,89,55, 700,350);
	recon1.takeoff();
	recon1.navigateTo(65,76,900);
	recon1.scanArea(10);
return 0;
}


