/*
 *  Animate and show Lorenz Attractions in 3D with smooth HSV colors.
 *  Includes encapsulated data structure for lorenz event and controls to
 * experiment.
 *
 *  Key bindings:
 *  SPACE  Play / Pause Animation
 *  < >    Slow down / Speed up animation
 *  a      Toggle Axes
 *  r      Randomize Initial Position
 *  + -    Manually Adjust Rho
 *  arrows Change View Angle
 *  0      Reset View Angle
 *  ESC    Exit
 *
 */
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef USEGLEW
#include <GL/glew.h>
#endif
 //  OpenGL with prototypes for glext
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
// Tell Xcode IDE to not gripe about OpenGL deprecation
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#else
#include <GL/glut.h>
#endif
//  Default resolution
//  For Retina displays compile with -DRES=2
#ifndef RES
#define RES 1
#endif

//  Globals
int th = 0;       // Azimuth of view angle
int ph = 0;       // Elevation of view angle
int axes = 0;     //  Display axes
int animate = 1;  // Toggle Animation

int rhoMin = 5;                 // Animation Minimum Rho
int rhoMax = 28;                // Animation Maximum Rho
float direction = 1.0f;         // Animation Direction
double animationSpeed = 0.001;  // Base speed of animation dRho/second
clock_t lastTime;               // For Delta Time in Animation

double w = 1;          // W variable
double dim = 90;       // Dimension of orthogonal box
double randomDim = 5;  // Domain of random initial position

/*  Lorenz Parameters  */
#define NUM_POINTS 100000
#define DT 0.0001

// Struct to hold Lorenz Attractor data
typedef struct {
	double vertices[NUM_POINTS][3];
	double colors[NUM_POINTS][3];
	double s, b, r;
	double dt;
	double x, y, z;                          // Current position
	double initial_x, initial_y, initial_z;  // Initial position
} LorenzData;

LorenzData* lorenzData;

/*
 *  HSV to RGB Conversion, Credit ChatGPT : For smooth interpolation of color
 * through the line
 */
void HSVtoRGB(float h, float s, float v, float* r, float* g, float* b) {
	int i;
	float f, p, q, t;
	if (s == 0) {
		*r = *g = *b = v;
		return;
	}
	h /= 60;
	i = floor(h);
	f = h - i;
	p = v * (1 - s);
	q = v * (1 - s * f);
	t = v * (1 - s * (1 - f));
	switch (i) {
	case 0:
		*r = v;
		*g = t;
		*b = p;
		break;
	case 1:
		*r = q;
		*g = v;
		*b = p;
		break;
	case 2:
		*r = p;
		*g = v;
		*b = t;
		break;
	case 3:
		*r = p;
		*g = q;
		*b = v;
		break;
	case 4:
		*r = t;
		*g = p;
		*b = v;
		break;
	default:
		*r = v;
		*g = p;
		*b = q;
		break;
	}
}

/*
 *  Get random value to generate random position, stack overflow with c lib
 */
double getRandomValue(double min, double max) {
	return min + (rand() / (RAND_MAX / (max - min)));
}

/*
 *  Generate Points for Lorenz Attractor on to the struct of its data
 */
void generateLorenzAttractor(LorenzData* data) {
	// Reset with proper initial values if regenerated.
	data->x = data->initial_x;
	data->y = data->initial_y;
	data->z = data->initial_z;

	for (int i = 0; i < NUM_POINTS; i++) {  // TODO COMMENT
		double dx = data->s * (data->y - data->x);
		double dy = data->x * (data->r - data->z) - data->y;
		double dz = data->x * data->y - data->b * data->z;

		data->x += data->dt * dx;
		data->y += data->dt * dy;
		data->z += data->dt * dz;

		data->vertices[i][0] = data->x;
		data->vertices[i][1] = data->y;
		data->vertices[i][2] = data->z;

		// Assign color based on i/NUM_POINTS value using HSV to RGB conversion
		// float h = (120.0f * (float)i / NUM_POINTS);
		float h = fmod(((360.0f * (float)i / NUM_POINTS) + 180.0f), 360.0f);
		float r, g, b;
		HSVtoRGB(h, 1.0f, 1.0f, &r, &g, &b);
		data->colors[i][0] = r;
		data->colors[i][1] = g;
		data->colors[i][2] = b;

		// // Color based on position for better visualization
		// data->colors[i][0] = (dx - data->x) / 50.0 + 0.5;
		// data->colors[i][1] = (dy - data->y) / 50.0 + 0.5;
		// data->colors[i][2] = (dz - data->z) / 50.0 + 0.5;

		// // Prevent colors from going out of range
		// data->colors[i][0] = data->colors[i][0] < 0 ? 0 : (data->colors[i][0] > 1
		// ? 1 : data->colors[i][0]); data->colors[i][1] = data->colors[i][1] < 0 ?
		// 0 : (data->colors[i][1] > 1 ? 1 : data->colors[i][1]); data->colors[i][2]
		// = data->colors[i][2] < 0 ? 0 : (data->colors[i][2] > 1 ? 1 :
		// data->colors[i][2]);

		// Print debug info
		if (i % 1000 == 0) {
			// printf("%5d %8.3f %8.3f %8.3f\n", i + 1, data->x, data->y, data->z);
		}
	}
}

/*
 *  Renders the data in the lorenzData struct
 */
static void renderLorenzAttractor(LorenzData* data) {
	glPushMatrix();
	glBegin(GL_LINE_STRIP);

	for (int i = 0; i < NUM_POINTS; ++i) {
		double* color = data->colors[i];
		double* vertex = data->vertices[i];

		// Set the color for each vertex
		glColor3f(color[0], color[1], color[2]);

		// Set the vertex position
		glVertex3f(vertex[0], vertex[1], vertex[2]);
	}

	glEnd();
	glPopMatrix();
}


void animateRho() {
	clock_t currentTime = clock();
	float deltaTime = (float)(currentTime - lastTime) / CLOCKS_PER_SEC;
	lastTime = currentTime;

	lorenzData->r += direction * animationSpeed * deltaTime * 1000;

	// Switch Directions Depending on Bounds and Rho
	if (lorenzData->r >= rhoMax) {
		direction = -1;
	}
	else if (lorenzData->r <= rhoMin) {
		direction = 1;
	}

	generateLorenzAttractor(lorenzData);
	glutPostRedisplay();
}

/*
 *  Convenience routine to output raster text
 *  Use VARARGS to make this more flexible
 */
#define LEN 8192  // Maximum length of text string
void Print(const char* format, ...) {
	char buf[LEN];
	char* ch = buf;
	va_list args;
	//  Turn the parameters into a character string
	va_start(args, format);
	vsnprintf(buf, LEN, format, args);
	va_end(args);
	//  Display the characters one at a time at the current raster position
	while (*ch) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *ch++);
}

/*
 *  Print message to stderr and exit
 */
void Fatal(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(1);
}

/*
 *  Check for OpenGL errors
 */
void ErrCheck(const char* where) {
	int err = glGetError();
	if (err) fprintf(stderr, "ERROR: %s [%s]\n", gluErrorString(err), where);
}

/*
 *  Display the scene
 */
void display() {
	// Handle Rho Animation
	if (animate) animateRho();

	//  Erase the window and the depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//  Enable Z-buffering in OpenGL
	glEnable(GL_DEPTH_TEST);
	//  Reset previous transforms
	glLoadIdentity();
	// Translate to move perspective to appropriate spot
	glTranslatef(0.0, 0.0, -dim);
	//  Set view angle
	glRotated(ph, 1, 0, 0);
	glRotated(th, 0, 1, 0);
	//  Draw 10 pixel yellow points
	glColor3f(1, 1, 0);
	glPointSize(1);

	renderLorenzAttractor(lorenzData);
	//  Draw axes and text in white

	glColor3f(1, 1, 1);
	if (axes) {
		glBegin(GL_LINES);

		double axisLength = dim / 6.5;

		glVertex3d(0, 0, 0);
		glVertex3d(axisLength, 0, 0);
		glVertex3d(0, 0, 0);
		glVertex3d(0, axisLength, 0);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 0, axisLength);
		glEnd();
		//  Label axes
		glRasterPos3d(axisLength, 0, 0);
		Print("X");
		glRasterPos3d(0, axisLength, 0);
		Print("Y");
		glRasterPos3d(0, 0, axisLength);
		Print("Z");
	}

	//  Display parameters
	glWindowPos2i(5, 5);
	Print("View Angle=%d,%d RHO=%.2f", th, ph, (lorenzData->r));
	if (animate) {
		Print(" - Pause (Space)");
	}
	else {
		Print(" - Play (Space)");
	}

	//  Flush and swap
	ErrCheck("display");
	glFlush();
	glutSwapBuffers();
}

/*
 *  GLUT calls this routine when a key is pressed
 */
void key(unsigned char ch, int x, int y) {
	//  Exit on ESC
	if (ch == 27) {
		exit(0);
	}
	// Reset View Angle
	else if (ch == '0') {
		th = ph = 0;
	}
	// Show / Hide Axis
	else if (ch == 'a' || ch == 'A') {
		axes = 1 - axes;
	}
	// Increase Rho
	else if (ch == '=' || ch == '+') {
		lorenzData->r += 1;
		generateLorenzAttractor(lorenzData);
	}
	// Decrease Rho
	else if (ch == '-' || ch == '-') {
		lorenzData->r -= 1;
		generateLorenzAttractor(lorenzData);
	}
	// Play Animation
	else if (ch == ' ') {
		animate = 1 - animate;
	}
	// Speed Up Animation
	else if (ch == '.' || ch == '>') {
		animationSpeed *= 1.1;
		printf("Increasing Animation Speed\n");
	}
	// Slow Down Animation
	else if (ch == ',' || ch == '<') {
		animationSpeed *= 0.9;
		printf("Decreasing Animation Speed\n");
	}
	// Randomize Location
	else if (ch == 'R' || ch == 'r') {  // Enter key
		lorenzData->initial_x = getRandomValue(-randomDim, randomDim);
		lorenzData->initial_y = getRandomValue(-randomDim, randomDim);
		lorenzData->initial_z = getRandomValue(-randomDim, randomDim);

		printf("Randomizing Initial Position to (%.2f, %.2f, %.2f)\n",
			lorenzData->initial_x, lorenzData->initial_y, lorenzData->initial_z);

		generateLorenzAttractor(lorenzData);
	}

	// Tell GLUT it is necessary to redisplay the scene
	glutPostRedisplay();
}

/*
 *  GLUT calls this routine when an arrow key is pressed
 */
void special(int key, int x, int y) {
	//  Right arrow key - increase azimuth by 5 degrees
	if (key == GLUT_KEY_RIGHT) th += 5;
	//  Left arrow key - decrease azimuth by 5 degrees
	else if (key == GLUT_KEY_LEFT)
		th -= 5;
	//  Up arrow key - increase elevation by 5 degrees
	else if (key == GLUT_KEY_UP)
		ph += 5;
	//  Down arrow key - decrease elevation by 5 degrees
	else if (key == GLUT_KEY_DOWN)
		ph -= 5;
	//  Keep angles to +/-360 degrees
	th %= 360;
	ph %= 360;
	//  Tell GLUT it is necessary to redisplay the scene
	glutPostRedisplay();
}

/*
 *  GLUT calls this routine when the window is resized
 */
void reshape(int width, int height) {
	//  Set the viewport to the entire window
	glViewport(0, 0, RES * width, RES * height);
	//  Tell OpenGL we want to manipulate the projection matrix
	glMatrixMode(GL_PROJECTION);
	//  Undo previous transformations
	glLoadIdentity();
	//  Orthogonal projection box adjusted for the
	//  aspect ratio of the window
	double asp = (height > 0) ? (double)width / height : 1;
	// glOrtho(-asp * dim, +asp * dim, -dim, +dim, -dim, +dim);

	gluPerspective(45.0, asp, 0.1, 1000.0);  // Field of view angle, aspect ratio,
	// near and far clipping planes

//  Switch to manipulating the model matrix
	glMatrixMode(GL_MODELVIEW);
	//  Undo previous transformations
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
	if (button == 3) {  // Scroll up
		dim -= 1;
	}
	else if (button == 4) {  // Scroll down
		dim += 1;
	}
	if (dim < 1) dim = 1;  // Prevent zooming out too much
	reshape(glutGet(GLUT_WINDOW_WIDTH),
		glutGet(GLUT_WINDOW_HEIGHT));  // Update the projection
	glutPostRedisplay();
}

/*
 *  Start up GLUT and tell it what to do
 */
int main(int argc, char* argv[]) {
	// Allocate memory for lorenzData
	lorenzData = (LorenzData*)malloc(sizeof(LorenzData));
	lorenzData->s = 10.0;
	lorenzData->b = 2.6666;
	lorenzData->r = 28.0;
	lorenzData->dt = DT;
	lorenzData->initial_x = 1.0;
	lorenzData->initial_y = 1.0;
	lorenzData->initial_z = 1.0;

	//  Initialize GLUT and process user parameters
	glutInit(&argc, argv);
	//  Request double buffered, true color window
	// glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	//  Request 500 x 500 pixel window
	glutInitWindowSize(500, 500);
	//  Create the window
	glutCreateWindow("Lorenz Attractor");

#ifdef USEGLEW
	//  Initialize GLEW
	if (glewInit() != GLEW_OK) Fatal("Error initializing GLEW\n");
#endif

	// Generate the lorenz attractor on startup
	generateLorenzAttractor(lorenzData);

	//  Tell GLUT to call "display" when the scene should be drawn
	glutDisplayFunc(display);
	//  Tell GLUT to call "reshape" when the window is resized
	glutReshapeFunc(reshape);
	//  Tell GLUT to call "special" when an arrow key is pressed
	glutSpecialFunc(special);
	//  Tell GLUT to call "key" when a key is pressed
	glutKeyboardFunc(key);
	// Call for mouse scrolling input
	glutMouseFunc(mouse);
	//  Pass control to GLUT so it can interact with the user
	glutMainLoop();

	free(lorenzData);

	//  Return code
	return 0;
}
