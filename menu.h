#include "include.h"
#include "render.h"
#include "keyboard.h"



enum MENU_TYPE
{
        MENU_OPTION1,
        MENU_OPTION2,
        MENU_OPTION3,
        MENU_OPTION4,
		MENU_OPTION5,
		MENU_OPTION6,
		MENU_OPTION7,
		MENU_OPTION8,
		MENU_OPTION9,
		MENU_OPTION10,
		MENU_OPTION11,
        MENU_OPTION12,
        MENU_OPTION13,
        MENU_OPTION14,
		MENU_OPTION15,
		MENU_OPTION16,
		MENU_OPTION17,
		MENU_OPTION18,
};

void menu(int x)
{

	switch (x)
        {

        case MENU_OPTION1:
			eyex++;
			break;
        case MENU_OPTION2:
			eyey++;
        case MENU_OPTION3:
			eyez++;
			break;
        case MENU_OPTION4:
			upx++;
			break;
		case MENU_OPTION5:
			upy++;
			break;
		case MENU_OPTION6:
			upz++;
			break;
		case MENU_OPTION7:
			upz++;
			break;
		case MENU_OPTION8:
			eyex--;
			break;
		case MENU_OPTION9:
			eyey--;
			break;
		case MENU_OPTION10:
			eyez--;
			break;
		case MENU_OPTION11:
			upy--;
			break;
		case MENU_OPTION12:
			upy--;
			break;
		case MENU_OPTION13:
			upy--;
			break;
		case MENU_OPTION14:
			angle2=0.0;lx=0.0f,lz=-1.0f;eyex=-0.0f,eyez=-9.0f, eyey = 1.0f;upx = 0.0, upy = 1.0, upz = 0.0;
			break;
        case MENU_OPTION15:
			exit(0);
			break;
        case MENU_OPTION16:

		case MENU_OPTION17:

		case MENU_OPTION18:

        default:
                break;
        }

}

void createMenu()
{
		glutAddMenuEntry("Increment eyex", MENU_OPTION1);

		glutAddMenuEntry("Increment eyey",MENU_OPTION2);

		glutAddMenuEntry("Increment eyez",MENU_OPTION3);

		glutAddMenuEntry("Increment upx",MENU_OPTION4);

		glutAddMenuEntry("Increment upy",MENU_OPTION5);

		glutAddMenuEntry("Increment upz",MENU_OPTION7);

		glutAddMenuEntry("Decrement eyex", MENU_OPTION8);

		glutAddMenuEntry("Decrement eyey",MENU_OPTION9);

		glutAddMenuEntry("Decrement eyez",MENU_OPTION10);

		glutAddMenuEntry("Decrement upx",MENU_OPTION11);

		glutAddMenuEntry("Decrement upy",MENU_OPTION12);

		glutAddMenuEntry("Decrement upz",MENU_OPTION13);

		glutAddMenuEntry("Reset",MENU_OPTION14);

		glutAddMenuEntry("Exit",MENU_OPTION15);

		glutAttachMenu(GLUT_RIGHT_BUTTON);


}
