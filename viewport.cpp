#include <gl/glut.h>

void d() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 600.0); //world window
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, 400, 300); //viewport 1
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex2f(200, 200);
		glVertex2f(200, 300);
		glVertex2f(300, 300);
		glVertex2f(300, 200);
	glEnd();

	glViewport(400, 300, 400, 300); //viewport 2
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex2f(200, 200);
		glVertex2f(200, 300);
		glVertex2f(300, 300);
		glVertex2f(300, 200);
	glEnd();

	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 800) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 600) / 2);
 	glutCreateWindow("my first attempt");
	glutDisplayFunc(d);     	                       
	glutMainLoop(); 		     	           
}