#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H

#include <GL/glew.h>
#include <vector>
#include "Vertex.h"
class BufferManager {
public:
    BufferManager();
    ~BufferManager();

    void SetupBuffersWithEBO(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
    void SetupBuffersWithoutEBO(const std::vector<float>& vertices);
    void BindVAO() const;
    void UnbindVAO() const;

    GLuint GetVAO() const { return VAO; }
    GLuint GetVBO() const { return VBO; }

private:
    GLuint VAO, VBO, EBO;
    bool hasEBO;
};

#endif // BUFFER_MANAGER_H
