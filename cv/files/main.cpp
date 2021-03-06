//Include the standard C++ headers
#include <stdlib.h>
#include <stdio.h>
//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>


#include "vertexShader.h"
#include "fragmentShader.h"
#include "vertexObject.h"

#include "koule/sphere.h"

struct Tmp{
    float x, y, px, py, difX, difY;
};

Tmp tmp;
struct Eye{
    int key, div, old;
} e;


glm::vec3 eye=glm::vec3(-3.5,0,0);
glm::vec3 target= glm::vec3(0.1f, 0.3f, 0.0f);
glm::vec3 up=glm::vec3(0,1,0);

static void moveUp(){
    eye.y-=0.1;
    std::cout<< eye.x << " "<< eye.y<< " "<< eye.z<<std::endl;

}

static void moveDown(){
    eye.y+=0.1;
    std::cout<< eye.x << " "<< eye.y<< " "<< eye.z<<std::endl;

}

static void moveLeft(){
    eye.z+=0.1;
    std::cout<< eye.x << " "<< eye.y<< " "<< eye.z<<std::endl;

}

static void moveRight(){
    eye.z-=0.1;
    std::cout<< eye.x << " "<< eye.y<< " "<< eye.z<<std::endl;
}






static void error_callback(int error, const char* description){ fputs(description, stderr); }

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
//    printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
    //std::cout<< (char)key<<std::endl;

    switch ((char)key){
        case 'W':
            moveUp();
            break;
        case 'S':
            moveDown();
            break;
        case 'A':
            moveLeft();
            break;
        case 'D':
            moveRight();
            break;
    }

    e.key=key;

}

static void window_focus_callback(GLFWwindow* window, int focused){ printf("window_focus_callback \n"); }

static void window_iconify_callback(GLFWwindow* window, int iconified){ printf("window_iconify_callback \n"); }

static void window_size_callback(GLFWwindow* window, int width, int height){
    printf("resize %d, %d \n", width, height);
    glViewport(0, 0, width, height);
}

static void cursor_callback(GLFWwindow *window, double x, double y){ printf("cursor_callback %f %f \n", x, y ); }

static void pokus(GLFWwindow *window, double x, double y){
    tmp.difX=x-tmp.x;
    tmp.difY=y-tmp.y;
    tmp.x=x;
    tmp.y=y;
    };


static void button_callback(GLFWwindow* window, int button, int action, int mode){
    if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}


//
////GLM test
//
//// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
//glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 100.0f);
//
//// Camera matrix
//glm::mat4 View = glm::lookAt(
//        glm::vec3(10, 10, 10), // Camera is at (4,3,-3), in World Space
//        glm::vec3(0, 0, 0), // and looks at the origin
//        glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
//);
//// Model matrix : an identity matrix (model will be at the origin)
//glm::mat4 Model = glm::mat4(1.0f);
//
//




int main()
{
    /*
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "ZPG", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Sets the key callback
    glfwSetKeyCallback(window, key_callback);

    glfwSetCursorPosCallback(window, cursor_callback);

    glfwSetMouseButtonCallback(window, button_callback);

    glfwSetWindowFocusCallback(window, window_focus_callback);

    glfwSetWindowIconifyCallback(window, window_iconify_callback);

    glfwSetWindowSizeCallback(window, window_size_callback);


    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    float ratio = width / (float)height;
    glViewport(0, 0, width, height);


    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);


    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();


        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
     */




   glm::mat4 M = glm::mat4(1.0f);
   glm::mat4 M2 = glm::mat4(2.0f);
/*
    M = glm::rotate(glm::mat4(1.0f),rotationx,glm::vec3(0.0f, 1.0f, 0.0f));
    M = glm::rotate(M, angle, glm::vec3(1.0f, 0.0f, 0.0f));
    M = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, myView));
    M = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));


    // ... create shader
    Glint modelMatrixID = glGetUniformLocation(programID, "modelMatrix");
//Render
    glUseProgram(programID);
    glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE,  glm::value_ptr(M));
//location, count, transpose, *value

*/



    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        exit(EXIT_FAILURE);
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
    window = glfwCreateWindow(800, 600, "ZPG", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
// start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();
// get version info
    printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
    printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
    printf("Vendor %s\n", glGetString(GL_VENDOR));
    printf("Renderer %s\n", glGetString(GL_RENDERER));
    printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    printf("GLM %s\n", glGetString(GLM_VERSION));
    int major, minor, revision;
    glfwGetVersion(&major, &minor, &revision);
    printf("Using GLFW %i.%i.%i\n", major, minor, revision);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    float ratio = width / (float)height;
    glViewport(0, 0, width, height);


    auto* fs = new FragmentShader();
    auto* vs = new VertexShader();
    auto* vo = new VertexObject(0,0);
    auto* cam = new Camera(nullptr);


    vo->CreateBufferObject();
    vo->CreateArrayObject();


    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, fs->GetShader());
    glAttachShader(shaderProgram, vs->GetShader());
    glLinkProgram(shaderProgram);

    GLint status;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
        auto *strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(shaderProgram, infoLogLength, nullptr, strInfoLog);
        fprintf(stderr, "Linker failure: %s\n", strInfoLog);
        delete[] strInfoLog;
    }
    float angleHor = 0.5;
    float angleVert=0.5;


    tmp.difY=tmp.difX=1;
    glm::mat4 projMat =glm::mat4(1.0f);
    projMat =glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

    while (!glfwWindowShouldClose(window))
    {
        //M = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.5f));
        M2 = glm::rotate(M2, angleVert, glm::vec3(1.0f, 0.3f, 0.0f));
        glm::mat4 viewMat = glm::mat4(1.0f);
//        viewMat=glm::lookAt(eye,glm::vec3(0,0,0),glm::vec3(0,1,0));
        viewMat=glm::lookAt(eye, eye + target, up);



        glfwSetCursorPosCallback(window, pokus);


        target.x=cos(glm::radians(tmp.difX));
        target.z=sin(glm::radians(tmp.difX));
        target.y=sin(glm::radians(tmp.difY));
//        std::cout<< tmp.difX << " "<< tmp.difY<< "\t | \t"<<target.x << " "<< target.y<< " "<< target.z << std::endl;

        glfwSetKeyCallback(window, key_callback);

        ///target dat na mys a eye na sipky
        ///u pohybu kamery si ukladat zmenu posunu, ne aktualni pozici


//        cam->getCamera();

        //angle += 0.001;
        GLint modelmatrixID2 =  glGetUniformLocation(shaderProgram, "modelMatrix");

        GLint viewMatrixID = glGetUniformLocation(shaderProgram, "viewMatrix");
        GLint modelMatrixID = glGetUniformLocation(shaderProgram, "modelMatrix");
        GLint projectionMatrixID = glGetUniformLocation(shaderProgram, "projectionMatrix");

        if (modelMatrixID<0){
            std::cout<< "o kurwa"<<std::endl;
            return 1;
        }
        if (projectionMatrixID<0) {
            std::cout << "o kurwa projekcni" << std::endl;
            return 2;
        }

        vec4 ex_worldPosition;
        vec3 ex_worldNormal;
        vec4 out_Color;
        gl_Position = (ProjectionMatrix * ViewMatrix * ModelMatrix) * vec4(in_Position,1.0f);
        ex_worldPosition= ModelMatrix* vec4(in_Position,1.0f);
        ex_worldNormal= NormalMatrix* in_Normal; //příště




        glUseProgram(shaderProgram);
        glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, glm::value_ptr(M));
        glUniformMatrix4fv(viewMatrixID, 1, GL_FALSE, glm::value_ptr(viewMat));
        glUniformMatrix4fv(projectionMatrixID, 1, GL_FALSE, glm::value_ptr(projMat));



        // clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(vo->GetVAO());
        // draw triangles
        glDrawArrays(GL_TRIANGLES, 0, 3); //mode,first,count
        // update other events like input handling
        glfwPollEvents();
        // put the stuff we’ve been drawing onto the display
        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);


}