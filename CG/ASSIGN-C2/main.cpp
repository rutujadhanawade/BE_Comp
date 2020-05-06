#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


#include <math.h>

//const double PI = 3.141592654;

int frameNumber = 0;



void drawBoat() {
   
   
    glColor3f(0.3,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-2.0f,0);
    glVertex2f(1.5f,0);
    glVertex2f(2,1);
    glVertex2f(-2.5f,1);
    glEnd();

    
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0,1);
    glVertex2f(0.8f,1);
glVertex2f(0,2);
    glVertex2f(0.8f,2);
    
    
    glEnd();

    glColor3f(0.1,0,0);
    glBegin(GL_LINES);
    glVertex2f(-2.25f,0.5f);
    glVertex2f(1.75,0.5f);
    glEnd();
    glLineWidth(2);  // Reset the line width to be 1 pixel.

    glEnd();
}


void display() {

    glClear(GL_COLOR_BUFFER_BIT); // Fills the scene with blue.
    glLoadIdentity();

   
    glColor3f(0.7, 0.7, 1);
    glBegin(GL_POLYGON);
    glVertex2f(0,-1);
    glVertex2f(7,-1);
    glVertex2f(7,0);
    glVertex2f(0,0);
    glEnd();
    

    glPushMatrix();
    glTranslated(-3 + 13*(frameNumber % 300) / 300.0, 0, 0);
    glScaled(0.3,0.3,1);
    drawBoat();
    glPopMatrix();
    
    glutSwapBuffers();

}

//This function is set as the glutTimerFunc to drive the animation
 
void doFrame(int v) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}


void init() {
    glClearColor(0, 0, 0.4, 1);
        // The next three lines set up the coordinates system.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 7, -1, 4, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Boat Animation");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(200,doFrame,0);

    glutMainLoop();
    return 0;
}
