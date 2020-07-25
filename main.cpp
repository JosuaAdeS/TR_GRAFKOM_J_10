#include<windows.h>
#include<GL/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x,int y);

bool mouseDown = false;

float xrot = 0.0f;
float yrot = 0.0f;

float xdiff = 0.0f;
float ydiff = 0.0f;

float scale = 1.0f;
float xmovement = 0.0f;
float ymovement = 0.0f;
float zmovement = 0.0f;

int is_depth;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1300,700);
    glutInitWindowPosition(50,0);
    glutCreateWindow("Josua Ade Saputra - 672018272");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}

void init(void){
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
}

void bangunan(void)
{
//dinding luar
    //depan
    glBegin(GL_POLYGON);
    glColor3ub(255,0,255);
    glVertex3f(-170,80,120);
    glVertex3f(-20,100,120);
    glVertex3f(170,100,120);
    glVertex3f(170,20,120);
    glVertex3f(70,-20,120);
    glVertex3f(-170,-20,120);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-170,80,120);
    glVertex3f(-170,-20,120);
    glVertex3f(-170,-20,-120);
    glVertex3f(-170,80,-120);
    glEnd();

    //belakang kanan
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-170,-20,-120);
    glVertex3f(-170,80,-120);
    glVertex3f(30,100,-170);
    glVertex3f(30,-20,-170);
    glEnd();
    //belakang kiri
    glBegin(GL_POLYGON);
    glColor3ub(255,100,0);
    glVertex3f(30,100,-170);
    glVertex3f(30,-20,-170);
    glVertex3f(240,-20,-120);
    glVertex3f(240,100,-120);
    glEnd();

    //kiri belakang
    glBegin(GL_POLYGON);
    glColor3ub(255,100,100);
    glVertex3f(240,-20,-120);
    glVertex3f(240,100,-120);
    glVertex3f(232,100,-30);
    glVertex3f(232,-20,-30);
    glEnd();
    //kiri depan
    glBegin(GL_POLYGON);
    glColor3ub(100,100,100);
    glVertex3f(170,100,120);
    glVertex3f(170,20,120);
    glVertex3f(232,-20,-30);
    glVertex3f(232,100,-30);
    glEnd();

//dalam bangunan ada 3 gedung utama
//gedung kanan
    //atas
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f(-150,70,100);
    glVertex3f(-150,70,-100);
    glVertex3f(0,70,-100);
    glVertex3f(0,70,100);
    glEnd();

//gedung depan
    //atas
    glBegin(GL_QUADS);
    glColor3ub(0,255,0);
    glVertex3f(0.5,100,100);
    glVertex3f(0.5,100,40);
    glVertex3f(80,100,40);
    glVertex3f(150,100,100);

    glVertex3f(80,100,40);
    glVertex3f(150,100,100);
    glVertex3f(150,100,0);
    glVertex3f(80,100,0);
    glEnd();

//gedung belakang
    glBegin(GL_QUADS);
    glColor3ub(0,255,100);
    glVertex3f(30,100,-170);
    glVertex3f(30,-20,-170);
    glVertex3f(15,-20,-81);
    glVertex3f(15,100,-81);

    glVertex3f(239,-20,-119);
    glVertex3f(239,100,-119);
    glVertex3f(231,100,-30);
    glVertex3f(231,-20,-30);

    glVertex3f(15,-20,-81);
    glVertex3f(15,100,-81);
    glVertex3f(231,100,-30);
    glVertex3f(231,-20,-30);

    glColor3ub(0,100,255);
    glVertex3f(239,100,-119);
    glVertex3f(231,100,-30);
    glVertex3f(15,100,-81);
    glVertex3f(30,100,-170);

    glEnd();

}

void tampil (void)
{
    if(is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f); // Rotating horizontal
	glRotatef(yrot, 0.0f, 1.0f, 0.0f); // Rotating vertical
	glScalef(scale, scale, scale); // Scalling
	glTranslatef(xmovement, ymovement, zmovement); // Translate / Movement

    bangunan();

    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key,int x,int y)
{
    switch (key){
	case 'a':
		xmovement -= 0.5f;
		break;
	case 'w':
		ymovement += 0.5f;
		break;
	case 'd':
		xmovement += 0.5f;
		break;
	case 's':
		ymovement -= 0.5f;
		break;
	case '1':
		scale += 0.2f;
		break;
	case '2':
		scale -= 0.2f;
		break;
    case '5' :
            if(is_depth)
            {
                is_depth =0;
                glDisable(GL_DEPTH_TEST);
            }
            else
            {
                is_depth =1;
                glEnable(GL_DEPTH_TEST);
            }break;
	case 27:
		exit(1);
		break;
	}
    tampil();
}


void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x-yrot;
        ydiff = -y+xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x,int y)
{
    if(mouseDown)
    {
        yrot = x-xdiff;
        xrot = y+ydiff;
        glutPostRedisplay();
    }
}

void ukuran (int lebar, int tinggi)
{
    if (tinggi == 0) tinggi=1;
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0f, 1.0f * lebar / tinggi, 1.0f, 4000.0f);
	glTranslatef(0, 0.0, -2000.0);
	glScalef(4, 4, 4);

	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, 1300, 700);
}
