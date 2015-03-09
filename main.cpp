
#include "particles.h"
#include "circle.h"
#include "TextureLoader.h"
#include "menu.h"
#include "render.h"
#include "keyboard.h"


void drawText(const char * message)
{
	/* raster pos sets the current raster position
	 * mapped via the modelview and projection matrices
	 */
	glRasterPos2f((GLfloat)0, (GLfloat)0);

	/*
	 * write using bitmap and stroke chars
	 */
	while (*message) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *message);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*message++);
	}
}



int main (int argc, char **argv) 
{
    
    glutInit (&argc, argv);
    
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize (width, height);
    
    glutInitWindowPosition (0, 0);
    
	main_window = glutCreateWindow ("Solar System X By Jamal Butcher");

	glutFullScreen();
    
    init();
    
    glutDisplayFunc (display);
    
    glutIdleFunc (display);
    
    glutReshapeFunc (reshape);

	glutSpecialFunc(processSpecialKeys);

	glutCreateMenu(menu);

	createMenu();

    glutMainLoop();
    
    return 0;
}

