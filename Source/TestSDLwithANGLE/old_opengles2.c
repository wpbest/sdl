#include <GLES2/gl2.h>
#include <SDL.h>

typedef struct _myData {
    SDL_Window *window;
    SDL_GLContext context;
} myData;

const GLchar vertex [] =
"#version 100\n"
"precision mediump float;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(0.0, 0.0, 0.0, 1.0);\n"
"   gl_PointSize = 128.0;\n"
"}\0";

const GLchar fragment [] =
"#version 100\n"
"precision mediump float;\n"
"void main()\n"
"{\n"
"   gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
"}\0";

GLuint loadShader(GLuint program, GLenum type, const GLchar *shaderSrc) {
    GLuint shader;
    shader = glCreateShader(type);
    glShaderSource(shader, 1, &shaderSrc, NULL);
    glCompileShader(shader);
    glAttachShader(program, shader);
    return 0;
}

int sdlInit(myData *data) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    data->window = SDL_CreateWindow("Demo", 0, 0, 512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    data->context = SDL_GL_CreateContext(data->window);

    return 0;
}

int glInit(myData *data) {
    GLuint programObject;
    programObject = glCreateProgram();
    loadShader(programObject, GL_VERTEX_SHADER, vertex);
    loadShader(programObject, GL_FRAGMENT_SHADER, fragment);
    glLinkProgram(programObject);
    glUseProgram(programObject);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glViewport(0, 0, 512, 512);

    return 0;
}

int loopFunc(myData *data) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return 1;
        }
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_POINTS, 0, 1);
    SDL_GL_SwapWindow(data->window);

    return 0;
}

void sdlQuit(myData *data) {
    SDL_GL_DeleteContext(data->context);
    SDL_DestroyWindow(data->window);
    SDL_Quit();
    return;
}

int main() {
    myData data;

    sdlInit(&data);

    glInit(&data);

    while (!loopFunc(&data));

    sdlQuit(&data);

    return 0;
}
