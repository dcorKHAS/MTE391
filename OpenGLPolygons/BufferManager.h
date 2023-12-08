#pragma once
#include <SDL.h>
#include <GL/glew.h>
class BufferManager
{

private:
	GLuint VAO;
	GLuint VBO;

public:
	BufferManager(GLfloat vertices[], GLuint numOfvertices, GLuint vertexSize);
	~BufferManager();
	void BindVAO();
};

