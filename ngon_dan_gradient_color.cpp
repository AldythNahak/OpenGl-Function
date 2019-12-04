#include <gl/glut.h>
#include <math.h>

void d() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glColor3d(255, 0, 0);
		glVertex2f(200 + 30 * cos(2 * (3.14159265) * 1 / 4), 200 + 30 * sin(2 * (3.14159265) * 1 / 4));
		glColor3d(0, 255, 0);
		glVertex2f(200 + 30 * cos(2 * (3.14159265) * 2 / 4), 200 + 30 * sin(2 * (3.14159265) * 2 / 4));
		glColor3d(0, 0, 255);
		glVertex2f(200 + 30 * cos(2 * (3.14159265) * 3 / 4), 200 + 30 * sin(2 * (3.14159265) * 3 / 4));
		glColor3d(255, 255, 255);
		glVertex2f(200 + 30 * cos(2 * (3.14159265) * 4 / 4), 200 + 30 * sin(2 * (3.14159265) * 4 / 4));
	glEnd();

	
	/*int segi = 100;
	int R = 100;
	double tambah = -10.0 / (double)segi;
	glBegin(GL_POLYGON);
		for (int i = 1; i <= (segi / 2 + 1); i++) {
			glVertex2f(200 + R * cos(2 * (3.14159265) * i / segi + tambah), 200 + R * sin(2 * (3.14159265) * i / segi + tambah));
		}
	glEnd();
	*/
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);          		        // inisialisasi  toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   	// set modus display
	glutInitWindowSize(800, 600);    				//set ukuran window
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 800) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 600) / 2);				//set inisialisasi posisi window
 	glutCreateWindow("my first attempt");			//judul window
	glutDisplayFunc(d);     	                       
	glutMainLoop(); 		     	           
}