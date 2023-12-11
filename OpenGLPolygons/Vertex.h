#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Vertex
{
public:
	glm::vec3 position;
	glm::vec3 color;

	Vertex(glm::vec3 pos, glm::vec3 col ) : position(pos), color(col){}
};

