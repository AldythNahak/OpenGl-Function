#include <GL/glut.h>

int windowWidth = 700, 
	windowHeight = 700;

void balok(int x, int y, int z, int panjang, int tinggi, int lebar) {
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x  + panjang, y, z);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(x, y, z - lebar);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y, z - lebar);
	glEnd();
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x, y + tinggi, z - lebar);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z);
	glVertex3f(x + panjang, y, z);
	glVertex3f(x + panjang, y, z - lebar);
	glVertex3f(x, y, z - lebar);
	glEnd();
	
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x, y, z - lebar);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(x + panjang, y, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y, z - lebar);
	glEnd();
}

void kursi(int x, int y, int z) {
	balok(x, y, z, 1, 4, 1);
	balok(x + 5, y, z, 1, 4, 1);
	balok(x, y, z - 5, 1, 4, 1);
	balok(x + 5, y, z - 5, 1, 4, 1);
	balok(x, y + 4, z, 6, 1, 6);
}

void init() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(255.0, 255.0, 255.0, 255.0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
}

int z = 0;
 
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	/*for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			kursi(i * 10, 0, j * -10);		
		}
	}*/

	//glColor3f(1.0, 0.0, 0.0);
	//glutSolidCube(5);
	//glutWireCube(5);
	//glutSolidSphere(5, 100, 100);
	//glutWireSphere(5, 20, 20);
	//glutSolidCone(5, 10, 50, 2);
	//glutWireCone(5, 10, 50, 2);
	//glutSolidTorus(5, 10, 5, 5);

	//glutSolidTeapot(2);
	//glutWireTeapot(2);
	
	//glutSolidSphere(2, 4, 2);
	glColor4f(1.0, 0.0, 0.0, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, z);
	glVertex3f(0, 1, z);
	glVertex3f(1, 1, z);
	glVertex3f(1, 0, z);
	glEnd();

	glColor4f(0.0, 1.0, 0.0, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, z + 2);
	glVertex3f(0, 1, z + 2);
	glVertex3f(1, 1, z + 2);
	glVertex3f(1, 0, z + 2);
	glEnd();

	glColor4f(0.0, 0.0, 1.0, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, z + 4);
	glVertex3f(0, 1, z + 4);
	glVertex3f(1, 1, z + 4);
	glVertex3f(1, 0, z + 4);
	glEnd();
	z--;

	glutSwapBuffers();
}
 
void reshape(int width, int height) {
	if(height == 0)height = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, width / height, 1.0, 400.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
   switch (key) {
			 //gerak ke kiri
		case 'a':
		case 'A':
			glTranslatef(-1.0, 0.0, 0.0);
			break;
			 //gerak ke kanan
		case 'd':
		case 'D':
			glTranslatef(1.0, 0.0, 0.0);
			break;
			 //gerak ke depan
		case 'w':
		case 'W':
			glTranslatef(0.0, 0.0, 1.0);
			break;
			 //gerak ke belakang
		case 's':
		case 'S':
			glTranslatef(0.0, 0.0, -1.0);
			break;
			 //gerak ke atas
		case 'q':
		case 'Q':
			glTranslatef(0.0, 1.0, 0.0);
			break;
			 //gerak ke bawah
		case 'e':
		case 'E':
			glTranslatef(0.0, -1.0, 0.0);
			break;
			 //rotate ke kiri
		case 'j':
		case 'J':
			glRotatef(1.0, 0.0, -5.0, 0.0);
			break;
			//rotate ke kanan
		case 'l':
		case 'L':
			glRotatef(1.0, 0.0, 5.0, 0.0);
			break;
			//rotate ke samping kanan
		case 'i':
		case 'I':
			glRotatef(1.0, 0.0, 0.0, -5.0);
			break;
			//rotate ke samping kiri
		case 'k':
		case 'K':
			glRotatef(1.0, 0.0, 0.0, 5.0);
			break;
			//rotate ke atas
		case 'o':
		case 'O':
			glRotatef(1.0, -5.0, 0.0, 0.0);
			break;
			//rotate ke bawah
		case 'u':
		case 'U':
			glRotatef(1.0, 5.0, 0.0, 0.0);
			break;
   }
   glutPostRedisplay(); 
}

void timer(int value) {
	glutPostRedisplay();         
	glutTimerFunc(200, timer, 0);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2);
	glutCreateWindow("Latihan 3D");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
}