#include "BufferManager.h"
#include <iostream>
BufferManager::BufferManager(GLfloat vertices[], GLuint numOfvertices, GLuint vertexSize) {


    // Create VBO(Vertex buffer object) and VAO (Vertex Array object)
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    std::cout << sizeof(vertices) << "which are:" << vertices << std::endl;
    
    glBufferData(GL_ARRAY_BUFFER, numOfvertices * vertexSize, vertices, GL_STATIC_DRAW);//To check

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, (void*)0);
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertexSize, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


}
void BufferManager::BindVAO(){

    glBindVertexArray(VAO);

}

BufferManager::~BufferManager() {

    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);

}