#ifndef COLLISION_H
#define COLLISION_H

#include "include.h"



bool detectCollision(int x1, int y1, int z1,int radius1, int x2, int y2, int z2, int radius2)
{
    int xd, yd, zd, distance;
     
    //2d
    //#ifdef 2d_collision
        //xd = x2-x1;
        //yd = y2-y1; 
        //Distance = sqrt(float(xd*xd + yd*yd));
   //#endif
     
    //3d
	//#ifdef 3d_collision
        xd = x2-x1;
        yd = y2-y1;
        zd = z2-z1;
        distance = sqrt(float(xd*xd + yd*yd + zd*zd));
    //endif*/
     
    if( radius1 + radius2 >= distance)
        return true; //collision
    return false;    //no collision    
}


#endif
