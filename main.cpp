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
    glutInitWindowSize(1350,700);
    glutInitWindowPosition(0,0);
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
    glLineWidth(6.0f);
}

void bangunan(void)
{
    //belakang
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(-60.0,-30.0,-100.0);
    glVertex3f(-60.0,50.0,-100.0);
    glVertex3f(30.0,50.0,-100.0);
    glVertex3f(30.0,-30.0,-100.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-60.0,-30.0,55.0);
    glVertex3f(-60.0,50.0,55.0);
    glVertex3f(0.0,50.0,70.0);
    glVertex3f(0.0,-30.0,70.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(0.0,-30.0,70.0);
    glVertex3f(0.0,50.0,70.0);
    glVertex3f(30.0,50.0,55.0);
    glVertex3f(30.0,-30.0,55.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.9765,0.9176,0.7647);
    glVertex3f(30.0,50.0,55.0);
    glVertex3f(30.0,-30.0,55.0);
    glVertex3f(55.0,-30.0,-22.0);
    glVertex3f(55.0,50.0,-22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5,1,0.5);
    glVertex3f(55.0,50.0,-22.0);
    glVertex3f(55.0,-30.0,-22.0);
    glVertex3f(30.0,-30.0,-100.0);
    glVertex3f(30.0,50.0,-100.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.9765,0.9176,0.7647);
    glVertex3f(-60.0,50.0,55.0);
    glVertex3f(-60.0,-30.0,55.0);
    glVertex3f(-70.0,-30.0,-22.0);
    glVertex3f(-70.0,50.0,-22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,1);
    glVertex3f(-70.0,50.0,-22.0);
    glVertex3f(-70.0,-30.0,-22.0);
    glVertex3f(-60.0,-30.0,-100.0);
    glVertex3f(-60.0,50.0,-100.0);
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
		yrot += 1.0f;
		break;
	case 'd':
		yrot -= 1.0f;
		break;
	case 'w':
		xrot += 1.0f;
		break;
	case 's':
		xrot -= 1.0f;
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
    gluPerspective(80.0,lebar/tinggi,5.0,500.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
