#pragma once

#define _NORTHWALL = 50;
#define _SOUTHWALL = -50;
#define _WESTWALL = -50;
#define _EASTWALL = 50;
#define _FLOOR = 0;
#define _CEILING = 100;


class LocationCoordinates {
	private:
		float xPosition;
		float yPosition;
		float zPosition;
	public:
		LocationCoordinates(){
			xPosition = 0;
			yPosition = 0;
			zPosition = 0;
		}
		LocationCoordinates(float x, float y){
			xPosition = x;
			yPosition = y;
			zPosition = 0;
		}
		LocationCoordinates(float x, float y, float z){
			xPosition = x;
			yPosition = y;
			zPosition = z;
		}
		void setXPosition(float x){
			xPosition = x;
		}
		void setYPosition(float y){
			yPosition = y;
		}
		void setZPosition(float z){
			zPosition = z;
		}
		float getXPosition(){
			return xPosition;
		}
		float getYPosition(){
			return yPosition;
		}
		float getZPosition(){
			return zPosition;
		}
		void updatePosition(float x, float y, float z){
			xPosition += x;
			yPosition += y;
			zPosition +=z;
		}
};