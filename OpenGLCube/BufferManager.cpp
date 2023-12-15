#include "BufferManager.h"


BufferManager::BufferManager() : VAO(0), VBO(0), EBO(0), hasEBO(false) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
}

BufferManager::~BufferManager() {
    if (hasEBO) {
        glDeleteBuffers(1, &EBO);
    }
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

void BufferManager::SetupBuffersWithEBO(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices) {
    hasEBO = true;
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void BufferManager::SetupBuffersWithoutEBO(const std::vector<float>& vertices) {
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void BufferManager::BindVAO() const {
    glBindVertexArray(VAO);
}

void BufferManager::UnbindVAO() const {
    glBindVertexArray(0);
}
