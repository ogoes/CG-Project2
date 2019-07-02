#include <GL/glut.h>

GLsizei HEIGHT = 800;
GLsizei WIDTH = 800;

double spin = 0.0;
double step = 0.1;

int mode = 0;
int reverse = 0;

int init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //define a cor de fundo
    glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade

}


void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3.0, 3.0, -3.0, 3.0, 1, 50.0);
    //limpa o buffer

    //define que a matrix é a de modelo
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity();



    // Primeira projeção (canto superior esquerdo)
    gluLookAt(0.0, 3.0, 0.0,
              0.0, 0.0, 0.0,
              0.0, 0.0, -1.0);
    glViewport(0, HEIGHT / 2.f, WIDTH / 2.f, HEIGHT / 2.f);

    // desenha um pote de cha
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(2.0f);


    // Segunda projeção (canto superior direito)
    glLoadIdentity();
    gluLookAt(5.0, 0.0, 0.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glViewport(HEIGHT / 2.f, HEIGHT / 2.f, WIDTH / 2.f, HEIGHT / 2.f);

    // desenha um pote de cha
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(2.0f);

    // Terceira projeção (canto inferior esquerdo)
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 2.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    glViewport(0, 0, WIDTH / 2.f, HEIGHT / 2.f);

    // desenha um pote de cha
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(2.0f);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    gluPerspective(70, 1.0, 1.0, 50.0); 

    // Quarta projeção (canto inferior direito)
    gluLookAt(0.0, 0.0, 2.5,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity();
    glViewport(WIDTH / 2.f, 0, WIDTH / 2.f, HEIGHT / 2.f);
    glRotatef(spin, 0.0, 0.0, 1.0);
    glRotatef(45, 1.0, 0.0, 0.0);

    // desenha um pote de cha
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(1.0f);

    glFlush();
}

void specialsKeys (int key, int x, int y) {
  if (key == GLUT_KEY_LEFT) {
    spin += 10.0;

  } else if (key == GLUT_KEY_RIGHT) {
      spin -= 10.0;      
  } else if (key == GLUT_KEY_UP) {
      step += 0.1;      
  } else if (key == GLUT_KEY_DOWN) {
      step -= 0.1;      
  }

  glutPostRedisplay();

}

void keyboardKeys (unsigned char key, int x, int y) {
  if (key == 'S' || key == 's') {
    mode = (mode + 1) % 2;
  } else if (key == 'R' || key == 'r') {
    reverse = (reverse + 1) % 2;
  }
}

void Timer(int value) {
  if (mode == 0) {
    if (reverse == 0)
      spin += step;
    else
      spin -= step;
  }

  glutPostRedisplay();
  glutTimerFunc(1, Timer, 1);
}

int main(int argc, char** argv){

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(200,0);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutCreateWindow("Projeto bonus 2");

  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboardKeys);
  glutSpecialFunc(specialsKeys);
  glutTimerFunc(1, Timer, 1);
  glutMainLoop();
  return 0;

}
