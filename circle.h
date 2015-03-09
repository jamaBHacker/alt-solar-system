#ifndef CIRCLE_H
#define CIRCLE_H

#include "include.h"

const double PI = 3.1415926535897;

typedef struct
{
 
    float X;
 
    float Y;
 
} CIRCLE;
 
CIRCLE circle;


float findPointOnCircleX(float radius,float origin, float angleInDegs)
{

	return origin + radius * cos( PI * ( angleInDegs  / 180.0 ) );
}


float findPointOnCircleY(float radius,float origin, float angleInDegs)
{

	return origin + radius * sin( PI * ( angleInDegs  / 180.0 ) );
}

void createcircle(int radius, int x, int y, int z)
{
	glBegin(GL_LINES);

		for(int i= 0; i < 180; i++)
		{
			circle.X = radius * cos( (float)i ) + x;
			circle.Y = radius * sin( (float)i ) + y;
			glVertex3f(circle.X + y,circle.Y - x, z);
    
			circle.X = radius * cos( (float)i + 0.1) - x;
			circle.Y = radius * sin(i + 0.1) + y;
			glVertex3f(circle.X + y, circle.Y - x, z);
		}

    glEnd();

}


#endif
