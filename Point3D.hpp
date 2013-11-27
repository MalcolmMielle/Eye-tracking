#ifndef POINT3D_HPP
#define POINT3D_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>

class Point3D{
	protected : 
	float x;
	float y;
	float z;
	public : 
	Point3D() : x(0),y(0),z(0) {}
	Point3D(float xx, float yy, float zz) : x(xx), y(yy), z(zz){}
	
	void setX(float xx){x=xx;}
	void setY(float yy){y=yy;}
	void setZ(float zz){z=zz;}
	
	float getX() const {return x;}
	float getY() const {return y;}
	float getZ() const {return z;}
	
	void move(float xx, float yy, float zz){
		x=x+xx;
		y=y+yy;
		z=z+zz;
	}
	
	void operator=(const Point3D& p){
		setX(p.getX());
		setY(p.getY());
		setZ(p.getZ());
	}
	
	bool operator==(const Point3D& p){
		std::cout<<p.getX() <<" " <<getX() <<std::endl;
		if(p.getX()==getX() && p.getY()==getY() && p.getZ()==getZ())
		{
			return true;
		}
		return false;
	}
	
};


struct AddP{
	Point3D operator()(const Point3D& x,const Point3D& y){
		return Point3D(x.getX()+ y.getX(),x.getY()+y.getY(),x.getZ()+y.getZ());
	}
};

#endif
