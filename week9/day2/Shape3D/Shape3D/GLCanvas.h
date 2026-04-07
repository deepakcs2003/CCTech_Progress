#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QMouseEvent>
#include "Shape.h"
#include "DataClass.h"

class GLCanvas : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
    Q_OBJECT

public:
    enum class Mode { NONE, DRAW, EDIT };        // mode type
    enum class ShapeType { NONE, RECT, SQUARE, CIRCLE }; // shape type

    GLCanvas(QWidget* parent = nullptr);
    ~GLCanvas();

    void setShapeType(ShapeType t); // choose shape
    void setMode(Mode m);           // change mode
    void clearCanvas();             // clear all
    void toggle3DView();            // toggle 3D
    std::vector<float> getMeshData() const;
    void loadMeshData(const std::vector<float>& data);


protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int, int) override;

    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;

private:
    void buildShader(); 
    //void draw(const std::vector<float>& pts, GLenum type,
    //    float r, float g, float b); 

        void draw2D(const std::vector<float>& pts, GLenum type,
        float r, float g, float b); 

        void draw3D(const std::vector<float>& pts, GLenum type,
        float r, float g, float b); 

    //void draw(const std::vector<float>& pts, GLenum type,
    //float r, float g, float b); 


    Shape* shape = nullptr;
    DataClass trigulationDS;
    ShapeType shapeType = ShapeType::NONE; 
    Mode mode = Mode::NONE;   
    std::vector<float> loadedMesh;

    bool loadingStl=false;
    bool drawing = false;            
    bool show3D = false;             

    int selected = -1;              
    float tol = 12.0f;               
    QPoint start;                  

    GLuint vao = 0, vbo = 0, prog = 0;
    GLint colorLoc = -1;               
};