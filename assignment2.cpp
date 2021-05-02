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
    //Draw Body
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glTranslatef(1.0, 1.0, -2.0);
    glPushMatrix();
    glScalef(1.0, 2.0, 0.5);
    glutWireCube(2.0);
    glPopMatrix();

    // Draw Head
    glPushMatrix();
    glTranslatef(-1.0, 3.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutWireSphere(0.5, 10, 8);
    glPopMatrix();

    //Draw right Hip 
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.5, -3.0, 0.0);
    glRotatef((GLfloat)rightHip, 1.0, 0.0, 0.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 1.0, 0.5);
    glutWireCube(2);
    glPopMatrix();


    //Draw right Knee 
    glTranslatef(0.0, -2.0, 0.0);
    glRotatef((GLfloat)rightKnee, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, 0.0);
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


    //Draw left Hip 
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.8, -3.0, 0.0);
    glRotatef((GLfloat)leftHip, 1.0, 0.0, 0.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 1.0, 0.5);
    glutWireCube(2);
    glPopMatrix();

    //Draw left Knee 
    glTranslatef(0.0, -2.0, 0.0);
    glRotatef((GLfloat)leftKnee, 1.0, 0.0, 0.0);
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

    //Draw right Shoulder
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.5, 1.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    glutWireCube(2);
    glPopMatrix();


    //Draw right Elbow
    glTranslatef(1.0, 0.0, 0.0);
    glTranslatef(-1.0, -2.0, 0.0);
    glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    glutWireCube(2);
    glPopMatrix();


    //Draw left Shoulder
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2.5, 1.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    glutWireCube(2);
    glPopMatrix();


    //Draw left Elbow
    glTranslatef(1.0, 0.0, 0.0);
    glTranslatef(-1.0, -2.0, 0.0);
    glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    glutWireCube(2);
    glPopMatrix();



   /* //Draw finger flang 4
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.0, -0.2, -0.2);
    glRotatef((GLfloat)fingerBase3, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();


    //Draw finger flang 4 
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp3, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    //Draw finger flang 5
    glPopMatrix();
    glTranslatef(1.0, -0.2, -0.4);
    glRotatef((GLfloat)fingerBase4, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();


    //Draw finger flang 5 
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp4, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix(); */

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

        shoulder = (shoulder + 5) % 360;
        glutPostRedisplay();
        break;
    case 'S':
        shoulder = (shoulder - 5) % 360;
        glutPostRedisplay();
        break;
    case 'e':
            elbow = (elbow + 5) % 360;
        glutPostRedisplay();
        break;
    case 'E':
            elbow = (elbow - 5) % 360;
        glutPostRedisplay();
        break;
    case 'f':
            rightHip = (rightHip + 5) % 360;
        glutPostRedisplay();
        break;
    case 'F':
            rightHip = (rightHip - 5) % 360;
        glutPostRedisplay();
        break;
    case 'g':
            rightKnee = (rightKnee + 5) % 360;
        glutPostRedisplay();
        break;
    case 'G':
            rightKnee = (rightKnee - 5) % 360;
        glutPostRedisplay();
        break;

    case '1':
            leftHip = (leftHip + 5) % 360;
        glutPostRedisplay();
        break;
    case '!':
            leftHip = (leftHip - 5) % 360;
        glutPostRedisplay();
        break;
    case '2':
            leftKnee = (leftKnee + 5) % 360;
        glutPostRedisplay();
        break;
    case '@':
            leftKnee = (leftKnee - 5) % 360;
        glutPostRedisplay();
        break;

   /* case '3':
        if (fingerBase2 == 30)
            break;
        else
            fingerBase2 = (fingerBase2 + 5) % 360;
        glutPostRedisplay();
        break;
    case '#':
        if (fingerBase2 == 0)
            break;
        else
            fingerBase2 = (fingerBase2 - 5) % 360;
        glutPostRedisplay();
        break;

    case '4':
        if (fingerUp2 == 140)
            break;
        else
            fingerUp2 = (fingerUp2 + 5) % 360;
        glutPostRedisplay();
        break;
    case '$':
        if (fingerUp2 == 0)
            break;
        else
            fingerUp2 = (fingerUp2 - 5) % 360;
        glutPostRedisplay();
        break;

    case '5':
        if (fingerBase3 == 30)
            break;
        else
            fingerBase3 = (fingerBase3 + 5) % 360;
        glutPostRedisplay();
        break;
    case '%':
        if (fingerBase3 == 0)
            break;
        else
            fingerBase3 = (fingerBase3 - 5) % 360;
        glutPostRedisplay();
        break;

    case '6':
        if (fingerUp3 == 140)
            break;
        else
            fingerUp3 = (fingerUp3 + 5) % 360;
        glutPostRedisplay();
        break;
    case '^':
        if (fingerUp3 == 0)
            break;
        else
            fingerUp3 = (fingerUp3 - 5) % 360;
        glutPostRedisplay();
        break;

    case '7':
        if (fingerBase4 == 30)
            break;
        else
            fingerBase4 = (fingerBase4 + 5) % 360;
        glutPostRedisplay();
        break;
    case '&':
        if (fingerBase4 == 0)
            break;
        else
            fingerBase4 = (fingerBase4 - 5) % 360;
        glutPostRedisplay();
        break;

    case '8':
        if (fingerUp4 == 140)
            break;
        else
            fingerUp4 = (fingerUp4 + 5) % 360;
        glutPostRedisplay();
        break;
    case '*':
        if (fingerUp4 == 0)
            break;
        else
            fingerUp4 = (fingerUp4 - 5) % 360;
        glutPostRedisplay();
        break;*/



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