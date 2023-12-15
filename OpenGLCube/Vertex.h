#pragma once
#include <glm/glm.hpp>
struct Vertex {
	glm::vec3 position;
	glm::vec3 color;
	//normal
	glm::vec3 normal;
	//texture coordinates
	glm::vec2 texCoords;
	//constructor with default values
	Vertex(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3 normal = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2 texCoords = glm::vec2(0.0f, 0.0f)) {
		this->position = position;
		this->color = color;
		this->normal = normal;
		this->texCoords = texCoords;
	}

};

