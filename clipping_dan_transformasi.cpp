#include <gl/glut.h>

void d() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);	
	glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef(300.0, 0.0, 0.0);
	glScalef(1.5, 1.0, 1.0);
	glRotatef(30.0, 0, 0, 1);
	float	Ax = 300.0,
			Ay = 200.0,
			Bx = 500.0,
			By = 500.0,
			Cx = 200.0,
			Cy = 600.0,
			Dx = 500.0,
			Dy = 100.0;

	glBegin(GL_LINES);
		glColor3d(255, 0, 0); //garis AB warna merah
		glVertex2f(Ax, Ay); //titik A
		glVertex2f(Bx, By); //titik B
		
		glColor3d(0, 0, 255); //garis CD warna biru
		glVertex2f(Cx, Cy); //titik C
		glVertex2f(Dx, Dy); //titik D
	glEnd();
	
	float mAB, cAB, mCD, cCD, x, y;
	mAB = (By - Ay) / (Bx - Ax);
	cAB = Ay - (mAB * Ax);

	mCD = (Dy - Cy) / (Dx - Cx);
	cCD = Cy - (mCD * Cx);

	x = (cCD - cAB) / (mAB - mCD);
	y = (mAB * x) + cAB;

	glPointSize(10);
	glBegin(GL_POINTS); //titik perpotongan
		glColor3d(0, 255, 0);
		glVertex2f(x, y);
	glEnd();
	
	
	/*glBegin(GL_LINES);
		glColor3d(0, 0, 255); //garis warna biru
		glVertex2f(Cx, Cy); //titik A
		glVertex2f(x, y); //titik B
		
		glColor3d(0, 0, 0); //garis warna hitam
		glVertex2f(x, y); //titik C
		glVertex2f(Dx, Dy); //titik D
	glEnd();*/

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