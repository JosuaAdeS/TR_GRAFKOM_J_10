#include<windows.h>
#include<GL/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

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

void tampil (void)
{
    if(is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

     //depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-10.0,-10.0,10.0);
    glVertex3f(-10.0,10.0,10.0);
    glVertex3f(10.0,10.0,10.0);
    glVertex3f(10.0,-10.0,10.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(-10.0,-10.0,-10.0);
    glVertex3f(-10.0,10.0,-10.0);
    glVertex3f(10.0,10.0,-10.0);
    glVertex3f(10.0,-10.0,-10.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(0,1,1);
    glVertex3f(10.0,10.0,10.0);
    glVertex3f(10.0,-10.0,10.0);
    glVertex3f(10.0,-10.0,-10.0);
    glVertex3f(10.0,10.0,-10.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(-10.0,10.0,10.0);
    glVertex3f(-10.0,-10.0,10.0);
    glVertex3f(-10.0,-10.0,-10.0);
    glVertex3f(-10.0,10.0,-10.0);
    glEnd();
    //atas
//    glBegin(GL_QUADS);
//    glColor3f(0,0.5,1);
//    glVertex3f(-10.0,10.0+10.0,10.0);
//    glVertex3f(10.0,-10.0+20.0,10.0);
//    glVertex3f(10.0,-10.0+20.0,-10.0);
//    glVertex3f(-10.0,10.0+10.0,-10.0);
//    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3f(0,1.5,0);
    glVertex3f(-10.0,-10.0,10.0);
    glVertex3f(10.0,-10.0,10.0);
    glVertex3f(10.0,-10.0,-10.0);
    glVertex3f(-10.0,-10.0,-10.0);
    glEnd();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
    switch (key)
    {
        case 'w' :
        case 'W' :
            glTranslatef(0,0,3);
            break;
        case 'd' :
        case 'D' :
            glTranslatef(3,0,0);
            break;
        case 's' :
        case 'S' :
            glTranslatef(0,0,-3);
            break;
        case 'a' :
        case 'A' :
            glTranslatef(-3,0,0);
            break;
        case '7' :
            glTranslatef(0,3,0);
            break;
        case '9' :
            glTranslatef(0,-3,0);
            break;
        case '2' :
            glRotatef(2,1,0,0);
            break;
        case '8' :
            glRotatef(-2,0,1,0);
            break;
        case '6' :
            glRotatef(2,0,1,0);
            break;
        case '4' :
            glRotatef(-2,1,0,0);
            break;
        case '1' :
            glRotatef(2,0,0,1);
            break;
        case '3' :
            glRotatef(-2,0,0,1);
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
            }
    }
    tampil();
}

void ukuran (int lebar, int tinggi)
{
    if (tinggi == 0) tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0,lebar/tinggi,5.0,500.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}

