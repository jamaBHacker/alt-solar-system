#ifndef RENDER_H
#define RENDER_H


#include "include.h"
#include "circle.h"
#include "particles.h"
#include "collision.h"


void display (void) {
    
	char *message = "Jamal";

	//drawText(message);

    glClearDepth(1);
    
    glClearColor (0.0,0.0,0.0,1.0);
    
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
	glPushMatrix(); //sun and orbit
		glLoadIdentity();
		 gluLookAt(	eyex, 1.0f, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
		glTranslatef(0,0,-10);
		createcircle(2, 0, 0, -10);
		glRotatef(angle,1,yRotationAngle,1);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		gluQuadricTexture(quad,1);
		gluSphere(quad, 0.6, 50, 20);
	glPopMatrix();

	glPushMatrix();//1st ring and planet from the sun
		glLoadIdentity();
		 gluLookAt(	eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
		createcircle(1, 0, 0, -10);
		glTranslatef(findPointOnCircleX(1,0,A), findPointOnCircleY(1,0,A), -10);
		glRotatef(angle,1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture[7]);
		gluQuadricTexture(quad,1);
		gluSphere(quad, 0.3, 50, 20);
	glPopMatrix();

	glPushMatrix();//2nd ring and planet from the sun
		glLoadIdentity();
		 gluLookAt(	eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy, upz);
		createcircle(2, 0, 0, -10);
		glTranslatef(findPointOnCircleX(2,0,E), findPointOnCircleY(2,0,E), -10);
		glRotatef(angle,1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture[9]);
		gluQuadricTexture(quad,1);
		gluSphere(quad, 0.3, 50, 20);
	glPopMatrix();

	glPushMatrix();//3rd ring and planet from the sun
		glLoadIdentity();
		 gluLookAt(	eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
		createcircle(3, 0, 0, -10);
		glTranslatef(findPointOnCircleX(3,0,A), findPointOnCircleY(3,0,A), -10);
		glRotatef(angle,1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture[6]);
		gluQuadricTexture(quad,1);
		gluSphere(quad, 0.3, 50, 20);
	glPopMatrix();

	glPushMatrix();//4th ring and planet from the sun
		glLoadIdentity();
		 gluLookAt(	eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
		createcircle(4, 0, 0, -10);
		glTranslatef(findPointOnCircleX(4,0,B),findPointOnCircleY(4,0,B),-10);
		glRotatef(angle,1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		gluQuadricTexture(quad,1);
		gluSphere(quad, 0.3, 50, 20);
	glPopMatrix();

	glPushMatrix();//5th ring and planet from the sun
		glLoadIdentity();
		gluLookAt(	eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
		createcircle(5, 0, 0, -10);
		glTranslatef(findPointOnCircleX(5,0,C),findPointOnCircleY(5,0,C),-10);
		glRotatef(angle,1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		gluQuadricTexture(quad,1);
		gluSphere(quad, 0.3, 50, 20);


	glPushMatrix();//last ring and planet from the sun
		glLoadIdentity();
		gluLookAt(eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
		createcircle(6, 0, 0, -10);
		glTranslatef(findPointOnCircleX(6,0,D),findPointOnCircleY(6,0,D),-10);
		glRotatef(angle,1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		gluQuadricTexture(quad,1);
		gluSphere(quad, 0.3, 50, 20);
	glPopMatrix();

	glPushMatrix();//moving astroid
		glLoadIdentity();
		gluLookAt(	eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
		glTranslatef(xLocation,yLocation,-10);
		glRotatef(angle,1,yRotationAngle,0);
		glBindTexture(GL_TEXTURE_2D, texture[8]);
		gluQuadricTexture(quad,1);
		gluSphere(quad, 0.5, 50, 20);
	glPopMatrix();

	//detect collision with planet on 5th ring
		if( detectCollision(xLocation, yLocation, -10, 0.5, findPointOnCircleX(5,0,C), findPointOnCircleY(5,0,C), -10, 0.3) )
		{	
			glPushMatrix();
				glLoadIdentity();
				gluLookAt(eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
				glTranslatef(3,3,-10);
				glLoadIdentity();  
				glTranslatef (0,0,-10);
				glUpdateParticles();
				glDrawParticles();
			glPopMatrix();

		}


		//detect collision with planet on 2nd ring
		if( detectCollision(xLocation, yLocation, -10, 0.5, findPointOnCircleX(2,0,E), findPointOnCircleY(2,0,E), -10, 0.3) )
		{	
			glPushMatrix();
				glLoadIdentity();
				gluLookAt(eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
				glTranslatef(3,3,-10);
				glLoadIdentity();  
				glTranslatef (0,0,-10);
				glUpdateParticles();
				glDrawParticles();
			glPopMatrix();

		}

		//detect collision with planet on 3rd ring
		if( detectCollision(xLocation, yLocation, -10, 0.5, findPointOnCircleX(3,0,A), findPointOnCircleY(3,0,A), -10, 0.3) )
		{	
			glPushMatrix();
				glLoadIdentity();
				gluLookAt(eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
				glTranslatef(3,3,-10);
				glLoadIdentity();  
				glTranslatef (0,0,-10);
				glUpdateParticles();
				glDrawParticles();
			glPopMatrix();

		}
		//detect collision with planet on the 6th ring
		if( detectCollision(xLocation, yLocation, -10, 0.5, findPointOnCircleX(6,0,D), findPointOnCircleY(6,0,D), -10, 0.3 ) )
		{	
			glPushMatrix();
				glLoadIdentity();
				gluLookAt(eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
				glTranslatef(3,3,-10);
				glLoadIdentity();  
				glTranslatef (0,0,-10);
				glUpdateParticles();
				glDrawParticles();
			glPopMatrix();

		}

		//detect collision with planet on the 4th ring
		if( detectCollision(xLocation, yLocation, -10, 0.5, findPointOnCircleX(4,0,B), findPointOnCircleY(4,0,B), -10, 0.3 ) )
		{	
			glPushMatrix();
				glLoadIdentity();
				gluLookAt(eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
				glTranslatef(3,3,-10);
				glLoadIdentity();  
				glTranslatef (0,0,-10);
				glUpdateParticles();
				glDrawParticles();
			glPopMatrix();

		}

		//detect collision with planet on the 1st ring
		if( detectCollision(xLocation, yLocation, -10, 0.5, findPointOnCircleX(1,0,A), findPointOnCircleY(1,0,A), -10, 0.3 ) )
		{	
			glPushMatrix();
				glLoadIdentity();
				gluLookAt(eyex, eyey, eyez, eyex+lx, 1.0f, eyez+lz, upx, upy,  upz);
				glTranslatef(3,3,-10);
				glLoadIdentity();  
				glTranslatef (0,0,-10);
				glUpdateParticles();
				glDrawParticles();
			glPopMatrix();

		}

	glPopMatrix();
	
	A = A + 0.1;//control speed of 1st planet orbit
	B = B + 0.3;//control speed of 4th planet orbit
	C = C + 0.05;//control speed of 5th planet orbit
	D = D + 1;//control speed of 2nd planet orbit
	E = E + 0.2;//control speed of 1st planet orbit
	F = F + 0.5;//control speed of 1st planet orbit
    
    glutSwapBuffers();

	if (movingUp) // If we are moving up  
		yLocation += 0.005f; // Move up along our yLocation  
	else  // Otherwise  
		yLocation -= 0.005f; // Move down along our yLocation  
  
	if (yLocation > 5.0f) // If we have gone up too far  
		movingUp = false; // Reverse our direction so we are moving down  
	else if (yLocation < -5.0f) // Else if we have gone down too far  
		movingUp = true; // Reverse our direction so we are moving up  

	if (movingSide) // If we are moving right 
		xLocation += 0.005f; // Move up along our xLocation  
	else  // Otherwise  
		xLocation -= 0.005f; // Move down along our xLocation  
  
	if (xLocation > 7.0f) //If we have gone up too far  
		movingSide = false; // Reverse our direction so we are moving down  
	else if (xLocation < -7.0f) // Else if we have gone down too far  
		movingSide = true; // Reverse our direction so we are moving up  
  
	yRotationAngle += 0.005f; // Increment our rotation value  

	if (yRotationAngle > 360.0f) // If we have rotated beyond 360 degrees (a full rotation)  
		yRotationAngle -= 360.0f; // Subtract 360 degrees off of our rotation  
    
    angle++;
}

void init (void) 
{

	glEnable(GL_DEPTH_TEST);
    
	glEnable( GL_TEXTURE_2D );

    glEnable(GL_POINT_SMOOTH);
	//glDepthFunc(GL_LEQUAL);

	glCreateParticles();

	quad = gluNewQuadric();
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
    
	texture[0] = LoadTexture( "texture.bmp", 256, 256 );
	texture[1] = LoadTexture( "mars.bmp", 480, 480 );
	texture[2] = LoadTexture( "earth2.bmp", 500, 322);
	texture[3] = LoadTexture( "earth3.bmp", 225, 225);
	texture[4] = LoadTexture( "particle.bmp", 256, 256);
	texture[5] = LoadTexture( "particle_mask.bmp", 256, 256);
	texture[6] = LoadTexture( "jupiter.bmp", 256, 256);
	texture[7] = LoadTexture( "ss.bmp", 1920, 1200);
	texture[8] = LoadTexture( "comet.bmp", 225, 225);
	texture[9] = LoadTexture( "jamal.bmp", 300, 225);
}

void reshape (int w, int h) 
{
	GLfloat nRange = 7;

	// Prevent a divide by zero
	if(h == 0)
		h = 1;

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();


	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
		glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w,-nRange*1.5f, nRange*1.5f);
	else
		glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange,-nRange*1.5f, nRange*1.5f);
    
    gluPerspective (0.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

}


#endif
