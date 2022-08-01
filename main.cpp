#include <iostream>
#include "square/code.h"
#include "GLFW/glfw3.h"
using namespace std;

int main()
{
	cout << "Hello, what's up?";
	cout << second::square(3, 2);
	GLFWwindow *window;
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
    window = glfwCreateWindow(300, 300, "Gears", NULL, NULL);
    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();


    return 0;
}
