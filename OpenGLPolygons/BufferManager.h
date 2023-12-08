#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include "Vertex.h"
class BufferManager
{

private:
	GLuint VAO;
	GLuint VBO;

public:
	BufferManager(Vertex vertices[], GLuint numOfvertices);
	~BufferManager();
	void BindVAO();
};

