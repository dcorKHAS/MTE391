#include "BufferManager.h"
#include <iostream>
#include "Vertex.h"
BufferManager::BufferManager(Vertex vertices[], GLuint numOfvertices) {

    GLuint vertexSize = sizeof(Vertex);
    // Create VBO(Vertex buffer object) and VAO (Vertex Array object)
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    std::cout << sizeof(vertices) << "which are:" << vertices << std::endl;
    
    glBufferData(GL_ARRAY_BUFFER, (GLfloat)numOfvertices * (GLfloat)vertexSize, vertices, GL_STATIC_DRAW);//To check

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertexSize, (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);


}
void BufferManager::BindVAO(){

    glBindVertexArray(VAO);

}

BufferManager::~BufferManager() {

    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);

}