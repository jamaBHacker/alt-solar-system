#include "include.h"


#ifndef PARTICLES_H
#define PARTICLES_H
  

const int ParticleCount = 500;

typedef struct
{
double Xpos;
double Ypos;
double Zpos;
double Xmov;
double Zmov;
double Red;
double Green;
double Blue;
double Direction;
double Acceleration;
double Deceleration;
double Scalez;
bool Visible;

} PARTICLES;


PARTICLES Particle[ParticleCount];

void glCreateParticles (void) 
{
	int i;
	for (i = 1; i < ParticleCount; i++)
	{
		Particle[i].Xpos = 0;
		Particle[i].Ypos = -5;
		Particle[i].Zpos = -5;
		Particle[i].Xmov = (((((((2 - 1 + 1) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1) * 0.005) - (((((((2 - 1 + 1) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1) * 0.005);
		Particle[i].Zmov = (((((((2 - 1 + 1) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1) * 0.005) - (((((((2 - 1 + 1) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1) * 0.005);
		Particle[i].Red = 1;
		Particle[i].Green = 1;
		Particle[i].Blue = 1;
		Particle[i].Scalez = 0.25;
		Particle[i].Direction = 0;
		Particle[i].Acceleration = ((((((8 - 5 + 2) * rand()%11) + 5) - 1 + 1) * rand()%11) + 1) * 0.02;
		Particle[i].Deceleration = 0.0025;
		}
}


void glUpdateParticles (void) 
{
	int i;
	for (i = 1; i < ParticleCount; i++)
	{

		glColor3f (Particle[i].Red, Particle[i].Green, 
		Particle[i].Blue);

		Particle[i].Ypos = Particle[i].Ypos + Particle[i].Acceleration - Particle[i].Deceleration;
		Particle[i].Deceleration = Particle[i].Deceleration + 0.0025;

		Particle[i].Xpos = Particle[i].Xpos + Particle[i].Xmov;
		Particle[i].Zpos = Particle[i].Zpos + Particle[i].Zmov;

		Particle[i].Direction = Particle[i].Direction + ((((((int)(0.5 - 0.1 + 0.1) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1);

			if (Particle[i].Ypos < -5)
			{
				Particle[i].Xpos = 0;
				Particle[i].Ypos = -5;
				Particle[i].Zpos = -5;
				Particle[i].Red = 1;
				Particle[i].Green = 1;
				Particle[i].Blue = 1;
				Particle[i].Direction = 0;
				Particle[i].Acceleration = ((((((8 - 5 + 2) * rand()%11) + 5) - 1 + 1) * rand()%11) + 1) * 0.02;
				Particle[i].Deceleration = 0.0025;
			}

			}
}

void glDrawParticles (void) {
	int i;
	for (i = 1; i < ParticleCount; i++)
	{
		glPushMatrix();

			glTranslatef (Particle[i].Xpos, Particle[i].Ypos, Particle[i].Zpos);
			glRotatef (Particle[i].Direction - 90, 0, 0, 1);
   
			glScalef (Particle[i].Scalez, Particle[i].Scalez, Particle[i].Scalez);
   
			glDisable (GL_DEPTH_TEST);
			glEnable (GL_BLEND);
        
			glBlendFunc (GL_DST_COLOR, GL_ZERO);
			glBindTexture (GL_TEXTURE_2D, texture[0]);

			glBegin (GL_QUADS);
			glTexCoord2d (0, 0);
			glVertex3f (-1, -1, 0);
			glTexCoord2d (1, 0);
			glVertex3f (1, -1, 0);
			glTexCoord2d (1, 1);
			glVertex3f (1, 1, 0);
			glTexCoord2d (0, 1);
			glVertex3f (-1, 1, 0);
			glEnd();
    
			glBlendFunc (GL_ONE, GL_ONE);
			glBindTexture (GL_TEXTURE_2D, texture[1]);
    
			glBegin (GL_QUADS);
			glTexCoord2d (0, 0);
			glVertex3f (-1, -1, 0);
			glTexCoord2d (1, 0);
			glVertex3f (1, -1, 0);
			glTexCoord2d (1, 1);
			glVertex3f (1, 1, 0);
			glTexCoord2d (0, 1);
			glVertex3f (-1, 1, 0);
			glEnd();
        
			glEnable(GL_DEPTH_TEST);

		glPopMatrix();

	}
}


#endif
