#include <windows.h>
#include <stdlib.h>
#include <glut.h>

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;

bool mouseDown = false;

void Inisialisasi(void)
{
	glClearColor (0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION); 
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display()
{ 
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 2.0, 5.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glScalef(2.0, 2.0, 2.0);
	glutSolidCube(20.0);
	/*glutWireCube(20);*/
	//glutSolidSphere(20, 30,30);
	//glutSolidCone(10,30,30,10);
	//glutWireCone(10,30,30,10);
	glPopMatrix();
    glutSwapBuffers();
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.1f;
		yrot += 0.1f;
	} 
glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			mouseDown = true;
			xdiff = x - yrot;
			ydiff = -y + xrot;
		}
	else
	mouseDown = false;
}
 
void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
 
		glutPostRedisplay();
	}
}

void ukuran(int lebar, int tinggi)
{    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glViewport(0, 0, lebar,tinggi );
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (900, 700);
    glutInitWindowPosition (210, 30);
    glutCreateWindow ("672016157");
    glutDisplayFunc (display);
    glutReshapeFunc(ukuran);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutIdleFunc(display);
	Inisialisasi();
    glutMainLoop ();
    return 0;
}
 
