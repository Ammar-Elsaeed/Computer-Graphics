#include <stdlib.h>
#include <GL/glut.h>


static int shoulder = 0, elbow = 0, rightHip = 0, rightKnee = 0;
static int leftHip = 0, leftKnee = 0, fingerBase2 = 0, fingerUp2 = 0, fingerBase3 = 0, fingerUp3 = 0, fingerBase4 = 0, fingerUp4 = 0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);
    //Draw Body
    glPushMatrix(); //original push

    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glTranslatef(1.0, 1.0, -2.0);

    glPushMatrix(); //1
    glScalef(1.0, 2.0, 0.5);
    glutWireCube(2.0);
    glPopMatrix();//1

    // Draw Head
    glPushMatrix();//2

    glTranslatef(-1.0, 3.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();//3
    glScalef(1.0, 1.0, 1.0);
    glutWireSphere(0.5, 10, 8);
    glPopMatrix();//3

    glPopMatrix();//2

    //Draw right Hip 
   
    glPushMatrix();
    glTranslatef(0.5, -3.0, 0.0);
    glTranslatef(0.15, 0.0, 0.0);
    glTranslatef(0.0, 1.0, 0.0);
    glRotatef((GLfloat)rightHip, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -1.0, 0.0);

    glPushMatrix();
    glScalef(0.3, 1.0, 0.5);
    glutWireCube(2);
    glPopMatrix();


    //Draw right Knee 
    glTranslatef(0.0 , -2.0 , 0.0);
    glTranslatef(0.0, 1.0, 0.0);
    glRotatef((GLfloat)rightKnee, 1.0, 0.0, 0.0);
    glTranslatef(0.0 ,-1.0 , 0.0);

    glPushMatrix();
    glScalef(0.3, 1.0, 0.5);
    glutWireCube(2);
    glPopMatrix();

    //Draw right Foot 
    glTranslatef(0.0, -1.2, 0.0);
    glTranslatef(0.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.5, 0.2, 1.2);
    glutSolidCube(2);
    glPopMatrix();

    glPopMatrix();

    //Draw left Hip 
   
    glPushMatrix();
    glTranslatef(-0.8, -3.0, 0.0);
    glTranslatef(0.15, 0.0, 0.0);
    glTranslatef(0.0, 1.0, 0.0);
    glRotatef((GLfloat)leftHip, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -1.0, 0.0);
    
    glPushMatrix();
    glScalef(0.3, 1.0, 0.5);
    glutWireCube(2);
    glPopMatrix();

    //Draw left Knee 
    glTranslatef(0.0, -2.0, 0.0);
    glTranslatef(0.0, 1.0, 0.0);
    glRotatef((GLfloat)leftKnee, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -1.0, 0.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 1.0, 0.5);
    glutWireCube(2);
    glPopMatrix();

    //Draw left Foot 
    glTranslatef(0.0, -1.2, 0.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.5, 0.2, 1.2);
    glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();

    //Draw right Shoulder

    glPushMatrix();
    glTranslatef(0.5, 1.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glTranslatef(-1.5, 1.0, 0.0);
    glRotatef((GLfloat)shoulder, 1.0, 0.0, 0.0);
    glTranslatef(1.5, -1.0, 0.0);

    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    glutWireCube(2);
    glPopMatrix();


    //Draw right Elbow
    glTranslatef(1.0, 0.0, 0.0);
    glTranslatef(-1.0, -2.0, 0.0);
    glTranslatef(1.5, 1.0, 0.0);
    glRotatef((GLfloat)elbow,1, 0.0, 0);
    glTranslatef(-1.5, -1.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    glutWireCube(2);
    glPopMatrix();

    glPopMatrix();

    //Draw left Shoulder
    
    glPushMatrix();
    //why??
    glTranslatef(-2.5, 1.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glTranslatef(-1.5, 1.0, 0.0);
    glRotatef((GLfloat)shoulder, 1.0, 0.0, 0.0);
    glTranslatef(1.5, -1.0, 0.0);
    //just why ?
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    glutWireCube(2);
    glPopMatrix();


    //Draw left Elbow
    glTranslatef(1.0, 0.0, 0.0);
    glTranslatef(-1.0, -2.0, 0.0);
    glTranslatef(1.5, 1.0, 0.0);
    glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
    glTranslatef(-1.5, -1.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    glutWireCube(2);
    glPopMatrix();



   
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 's':
        if (shoulder == -175)
            break;
        shoulder = (shoulder - 5) ;
        glutPostRedisplay();
        break;
    case 'S':
        if (shoulder == 85)
            break;
        else 
        shoulder = (shoulder + 5) ;
        glutPostRedisplay();
        break;


    case 'e':
        if (elbow == -145)
            break;
        else
           elbow = (elbow - 5) ;
        glutPostRedisplay();
        break;
    case 'E':
        if (elbow == 0)
            break;
        else
            elbow = (elbow + 5) ;
        glutPostRedisplay();
        break;


    case '3':
        if (rightHip == -65)
            break;
        else
            rightHip = (rightHip - 5) ;
        glutPostRedisplay();
        break;
    case '#':
        if (rightHip == 65)
            break;
        else
            rightHip = (rightHip + 5) ;
        glutPostRedisplay();
        break;


    case '4':
        if (rightKnee == 0)
            break;
        else
            rightKnee = (rightKnee - 5) ;
        glutPostRedisplay();
        break;
    case '$':
        if (rightKnee == 135)
            break;
        else
            rightKnee = (rightKnee + 5) ;
        glutPostRedisplay();
        break;


    case '1':
        if (leftHip == -65)
            break;
        else
            leftHip = (leftHip - 5) ;
        glutPostRedisplay();
        break;
    case '!':
        if (leftHip == 65)
            break;
        else
            leftHip = (leftHip + 5) ;
        glutPostRedisplay();
        break;


    case '2':
        if (leftKnee == 0)
            break;
        else
            leftKnee = (leftKnee - 5) ;
        glutPostRedisplay();
        break;
    case '@':
        if (leftKnee == 135)
            break;
        else
            leftKnee = (leftKnee + 5) ;
        glutPostRedisplay();
        break;

   


    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}


static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}