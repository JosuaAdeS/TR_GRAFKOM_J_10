#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
<<<<<<< HEAD

=======
>>>>>>> f3f6ff1a39d31fb84f8f69032fcfdb4557f0dedb
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
    glutCreateWindow("TR_Grafkom_kelompok_10");
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
    glLineWidth(4);
}
void dinding_depan()
{
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    //horizontal
    for (int i=0;i<7;i++){
        glVertex3f(-170,20+(i*10),120);
        glVertex3f(170,20+(i*10),120);
    }
    for (int i=0;i<5;i++){
        glVertex3f(-170,20-(i*10),120);
        glVertex3f(70,20-(i*10),120);
    }
    for (int i=0;i<3;i++){
        glVertex3f(170,80+(i*10),120);
        glVertex3f(-20,80+(i*10),120);
    }
    //vertical
    for (int i=0;i<25;i++){
        glVertex3f(-170+(i*10),20,120);
        glVertex3f(-170+(i*10),-20,120);
    }
    for (int i=0;i<35;i++){
        glVertex3f(-170+(i*10),80,120);
        glVertex3f(-170+(i*10),20,120);
    }
    for (int i=0;i<20;i++){
        glVertex3f(-20+(i*10),80,120);
        glVertex3f(-20+(i*10),100,120);
    }
    glEnd();
    //segitiga
    glBegin(GL_TRIANGLES);
    glColor3ub(255,255,255);
    for (int h=0;h<6;h++){
        for (int i=0;i<34;i++){
            glVertex3f(-160+(i*10),80-(h*10),120);
            glVertex3f(-160+(i*10),70-(h*10),120);
            glVertex3f(-170+(i*10),70-(h*10),120);
        }
    }
    for (int h=0;h<4;h++){
        for (int i=0;i<24;i++){
            glVertex3f(-160+(i*10),20-(h*10),120);
            glVertex3f(-160+(i*10),10-(h*10),120);
            glVertex3f(-170+(i*10),10-(h*10),120);
        }
    }
    for (int h=0;h<2;h++){
        for (int i=0;i<19;i++){
            glColor3ub(255,255,255);
            glVertex3f(-10+(i*10),100-(h*10),120);
            glVertex3f(-10+(i*10),90-(h*10),120);
            glVertex3f(-20+(i*10),90-(h*10),120);
        }
    }

    glEnd();
    //perpotongan garis
    float ax[15];
    float ay [2] = {80,100};
    float Mab[15],Cab[15],px[15],py[15];
    float cx=-170, cy=80, dx=-20, dy=100,Mcd,Ccd;

        for (int i=0;i<15;i++){
            ax[i] = -170+(i*10);
        }
    //rumus gradien
    for (int i=0;i<15;i++){
        Mab[i]=(ay[1]-ay[0])/(ax[i]+0.1-ax[i]);
    }
    Mcd=(dy-cy)/(dx-cx);

    for (int i=0;i<15;i++){
        Cab[i]=ay[0]-(ax[i]*Mab[i]);
    }
    Ccd=cy-(cx*Mcd);

    for (int i=0;i<15;i++){
        px[i]=(Ccd-Cab[i])/(Mab[i]-Mcd);
        py[i]=(Mab[i]*px[i])+Cab[i];
    }
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    for (int i=0;i<15;i++){
        glVertex3f(px[i],py[i],120);
        glVertex3f(ax[i],ay[0],120);
    }
    glVertex3f(px[7],py[7],120);
    glVertex3f(-20,90,120);

    glVertex3f(px[0],py[0],120);
    glVertex3f(-20,100,120);
    glEnd();

    //part2
    float ax1[15];
    float ay1[2] = {20,-20};
    float Mab1[15],Cab1[15],px1[15],py1[15];
    float cx1=70, cy1=-20, dx1=170, dy1=20,Mcd1,Ccd1;

        for (int i=0;i<11;i++){
            ax1[i] = 70+(i*10);
        }
    //rumus gradien
    for (int i=0;i<11;i++){
        Mab1[i]=(ay1[1]-ay1[0])/(ax1[i]+0.1-ax1[i]);
    }
    Mcd1=(dy1-cy1)/(dx1-cx1);

    for (int i=0;i<11;i++){
        Cab1[i]=ay1[0]-(ax1[i]*Mab1[i]);
    }
    Ccd1=cy1-(cx1*Mcd1);

    for (int i=0;i<11;i++){
        px1[i]=(Ccd1-Cab1[i])/(Mab1[i]-Mcd1);
        py1[i]=(Mab1[i]*px1[i])+Cab1[i];
    }
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    for (int i=0;i<11;i++){
        glVertex3f(px1[i],py1[i],120);
        glVertex3f(ax1[i],ay1[0],120);
    }
    glVertex3f(px1[0],py1[0],120);
    glVertex3f(170,20,120);
    glVertex3f(px1[3]-5,py1[3]-2,120);
    glVertex3f(70,-10,120);
    glVertex3f(px1[5],py1[5],120);
    glVertex3f(70,0,120);
    glVertex3f(px1[7]+4,py1[7]+2,120);
    glVertex3f(70,10,120);
<<<<<<< HEAD
    glEnd();

    //segitiga
     glBegin(GL_TRIANGLES);
    glColor3ub(255,255,255);
        for (int i=7;i>=0;i--){
            glVertex3f(80+(i*10),20,120);
            glVertex3f(80+(i*10),10,120);
            glVertex3f(70+(i*10),10,120);
        }
        for (int i=4;i>=0;i--){
            glVertex3f(80+(i*10),10,120);
            glVertex3f(80+(i*10),0,120);
            glVertex3f(70+(i*10),0,120);
        }
        for (int i=2;i>=0;i--){
            glVertex3f(80+(i*10),0,120);
            glVertex3f(80+(i*10),-10,120);
            glVertex3f(70+(i*10),-10,120);
        }
        for (int i=6;i<15;i++){
            glVertex3f(-160+(i*10),90,120);
            glVertex3f(-160+(i*10),80,120);
            glVertex3f(-170+(i*10),80,120);
        }

    glEnd();

=======
    glEnd();

    //segitiga
     glBegin(GL_TRIANGLES);
    glColor3ub(255,255,255);
        for (int i=7;i>=0;i--){
            glVertex3f(80+(i*10),20,120);
            glVertex3f(80+(i*10),10,120);
            glVertex3f(70+(i*10),10,120);
        }
        for (int i=4;i>=0;i--){
            glVertex3f(80+(i*10),10,120);
            glVertex3f(80+(i*10),0,120);
            glVertex3f(70+(i*10),0,120);
        }
        for (int i=2;i>=0;i--){
            glVertex3f(80+(i*10),0,120);
            glVertex3f(80+(i*10),-10,120);
            glVertex3f(70+(i*10),-10,120);
        }
        for (int i=6;i<15;i++){
            glVertex3f(-160+(i*10),90,120);
            glVertex3f(-160+(i*10),80,120);
            glVertex3f(-170+(i*10),80,120);
        }

    glEnd();

>>>>>>> f3f6ff1a39d31fb84f8f69032fcfdb4557f0dedb
}
void dinding_kanan()
{

    //kanan
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> f3f6ff1a39d31fb84f8f69032fcfdb4557f0dedb
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    //horizontal
    for (int i=0;i<25;i++){
        glVertex3f(-170,-20,(-120+(i*10)));
        glVertex3f(-170,80,(-120+(i*10)));
    }
    //vertical
    for (int i=0;i<11;i++){
        glVertex3f(-170,-20+(i*10),120);
        glVertex3f(-170,-20+(i*10),-120);
    }
    glEnd();
    //segitiga
    glBegin(GL_TRIANGLES);
    glColor3ub(255,255,255);
    for (int h=0;h<10;h++){
        for (int i=0;i<24;i++){
            glVertex3f(-170,80-(h*10),-110+(i*10));
            glVertex3f(-170,70-(h*10),-110+(i*10));
            glVertex3f(-170,70-(h*10),-120+(i*10));
        }
    }
<<<<<<< HEAD
=======
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-170,80,120);
    glVertex3f(-170,-20,120);
    glVertex3f(-170,-20,-120);
    glVertex3f(-170,80,-120);
>>>>>>> c9cf18913089d5ec8fa8172b18590e1e577fcf59
=======
>>>>>>> f3f6ff1a39d31fb84f8f69032fcfdb4557f0dedb
    glEnd();
}
void dinding ()
{
    dinding_depan();
    dinding_kanan();

    //belakang kanan
    glBegin(GL_POLYGON);
    glColor3ub(0,255,255);
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

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    //horizontal
    for (int i=0;i<25;i++){
        glVertex3f(-170,-20,(-120+(i*10)));
        glVertex3f(-170,80,(-120+(i*10)));
    }
    //vertical
    for (int i=0;i<11;i++){
        glVertex3f(-170,-20+(i*10),120);
        glVertex3f(-170,-20+(i*10),-120);
    }
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(255,255,255);
    for (int h=0;h<10;h++){
        for (int i=0;i<24;i++){
            glVertex3f(-170,80-(h*10),-110+(i*10));
            glVertex3f(-170,70-(h*10),-110+(i*10));
            glVertex3f(-170,70-(h*10),-120+(i*10));
        }
    }
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

}
void bangunan_atas (void)
{
//dalam bangunan ada 3 gedung utama
//gedung kanan
    //atas
    glBegin(GL_POLYGON);
    glColor3ub(221,225,202);
    glVertex3f(-150,70,100);
    glVertex3f(-150,70,-100);
    glVertex3f(0,70,-100);
    glVertex3f(0,70,100);
    //depan
    glVertex3f(-150,70,100);
    glVertex3f(0,70,100);
    glVertex3f(0,-20,100);
    glVertex3f(-150,-20,100);
    //kanan
    glVertex3f(-150,70,100);
    glVertex3f(-150,-20,100);
    glVertex3f(-150,-20,-100);
    glVertex3f(-150,70,-100);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(180,180,180);
    glVertex3f(-150,70,-100);
    glVertex3f(-150,-20,-100);
    glVertex3f(0,-20,-100);
    glVertex3f(0,70,-100);
    //kiri
    glVertex3f(0,70,-100);
    glVertex3f(0,-20,-100);
    glVertex3f(0,-20,0);
    glVertex3f(0,70,0);
    glEnd();

//gedung depan
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(100,105,105);
    glVertex3f(150,-20,100);
    glVertex3f(-150,-20,100);
    glVertex3f(0,-20,0);
    glVertex3f(150,-20,0);

    glVertex3f(-150,-20,100);
    glVertex3f(0,-20,0);
    glVertex3f(0,-20,-100);
    glVertex3f(-150,-20,-100);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3ub(221,225,202);
    glVertex3f(0,100,100);
    glVertex3f(0,100,40);
    glVertex3f(80,100,40);
    glVertex3f(150,100,100);

    glVertex3f(80,100,40);
    glVertex3f(150,100,100);
    glVertex3f(150,100,0);
    glVertex3f(80,100,0);
    glEnd();
    //abu2
    glBegin(GL_QUADS);
    glColor3ub(180,180,180);
    glVertex3f(150,100,0);
    glVertex3f(80,100,0);
    glVertex3f(80,-20,0);
    glVertex3f(150,-20,0);

    glVertex3f(0,70,0);
    glVertex3f(80,70,0);
    glVertex3f(80,-20,0);
    glVertex3f(0,-20,0);

    glVertex3f(0,100,40);
    glVertex3f(80,100,40);
    glVertex3f(80,70,40);
    glVertex3f(0,70,40);

    glVertex3f(80,100,40);
    glVertex3f(80,100,0);
    glVertex3f(80,70,0);
    glVertex3f(80,70,40);

    glVertex3f(0,100,40);
    glVertex3f(0,100,100);
    glVertex3f(0,70,100);
    glVertex3f(0,70,40);

    //putih
    glColor3ub(221,225,202);
    glVertex3f(0,100,100);
    glVertex3f(0,-20,100);
    glVertex3f(150,-20,100);
    glVertex3f(150,100,100);

    glVertex3f(80,70,40);
    glVertex3f(80,70,0);
    glVertex3f(0,70,0);
    glVertex3f(0,70,40);

    glVertex3f(150,-20,100);
    glVertex3f(150,100,100);
    glVertex3f(150,100,0);
    glVertex3f(150,-20,0);

    glVertex3f(150,-20,100);
    glVertex3f(150,100,100);
    glVertex3f(150,100,0);
    glVertex3f(150,-20,0);
    glEnd();

//gedung belakang
    //depan kiri kanan
    glBegin(GL_QUADS);
    glColor3ub(221,225,202);
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
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex3f(30,100,-170);
    glVertex3f(135,100,-144);
    glVertex3f(130,100,-110);
    glVertex3f(77,100,-123);

    glVertex3f(30,100,-170);
    glVertex3f(77,100,-123);
    glVertex3f(72,100,-90);
    glVertex3f(15,100,-81);

    glVertex3f(72,100,-90);
    glVertex3f(15,100,-81);
    glVertex3f(231,100,-30);
    glVertex3f(180,100,-65);

    glVertex3f(231,100,-30);
    glVertex3f(180,100,-65);
    glVertex3f(188,100,-131);
    glVertex3f(239,100,-119);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex3f(30,-20,-170);
    glVertex3f(135,-20,-144);
    glVertex3f(130,-20,-110);
    glVertex3f(77,-20,-123);

    glVertex3f(30,-20,-170);
    glVertex3f(77,-20,-123);
    glVertex3f(72,-20,-90);
    glVertex3f(15,-20,-81);

    glVertex3f(72,-20,-90);
    glVertex3f(15,-20,-81);
    glVertex3f(231,-20,-30);
    glVertex3f(180,-20,-65);

    glVertex3f(231,-20,-30);
    glVertex3f(180,-20,-65);
    glVertex3f(188,-20,-131);
    glVertex3f(239,-20,-119);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex3f(239,100,-119);
    glVertex3f(239,-20,-119);
    glVertex3f(188,-20,-131);
    glVertex3f(188,100,-131);

    glVertex3f(135,100,-144);
    glVertex3f(135,-20,-144);
    glVertex3f(30,-20,-169.5);
    glVertex3f(30,100,-169.5);
    glEnd();

    //dalam abu2
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(221,225,202);
    glVertex3f(180,100,-65);
    glVertex3f(180,-20,-65);
    glVertex3f(188,-20,-131);
    glVertex3f(188,100,-131);
    //kanan
    glVertex3f(77,-20,-123);
    glVertex3f(77,100,-123);
    glVertex3f(72,100,-90);
    glVertex3f(72,-20,-90);

    glVertex3f(130,100,-110);
    glVertex3f(130,-20,-110);
    glVertex3f(135,-20,-144);
    glVertex3f(135,100,-144);
    glEnd();
    //dalam putih
    //depan
    glBegin(GL_QUADS);
    glColor3ub(180,180,180);
    glVertex3f(180,100,-65);
    glVertex3f(180,-20,-65);
    glVertex3f(72,-20,-90);
    glVertex3f(72,100,-90);
    //belakang
    glVertex3f(130,100,-110);
    glVertex3f(130,-20,-110);
    glVertex3f(77,-20,-123);
    glVertex3f(77,100,-123);

    glEnd();
}
void tanah()
{
    glBegin(GL_QUADS);
    glColor3ub(212,175,55);
    glVertex3f(-200,-60,-230);
    glVertex3f(-200,-60,200);
    glVertex3f(260,-60,200);
    glVertex3f(260,-60,-230);
    glEnd();
<<<<<<< HEAD
<<<<<<< HEAD


=======
>>>>>>> c9cf18913089d5ec8fa8172b18590e1e577fcf59
=======


>>>>>>> f3f6ff1a39d31fb84f8f69032fcfdb4557f0dedb
}
void bangunan_bawah (void)
{
    glBegin(GL_QUADS);
    glColor3ub(180,180,180);
    glVertex3f(-150,-20,-100);
    glVertex3f(-150,-60,-100);
    glVertex3f(-90,-60,-100);
    glVertex3f(-90,-20,-100);

    glVertex3f(-150,-20,30);
    glVertex3f(-150,-60,30);
    glVertex3f(-90,-60,30);
    glVertex3f(-90,-20,30);

    glColor3ub(180,180,180);
    glVertex3f(-150,-20,-100);
    glVertex3f(-150,-60,-100);
    glVertex3f(-150,-60,30);
    glVertex3f(-150,-20,30);

    glVertex3f(-90,-20,-100);
    glVertex3f(-90,-60,-100);
    glVertex3f(-90,-60,30);
    glVertex3f(-90,-20,30);
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

	dinding();
	tanah();
    bangunan_atas();
    bangunan_bawah();

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
