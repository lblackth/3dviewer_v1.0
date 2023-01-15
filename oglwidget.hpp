#ifndef OGLWIDGET_HPP
#define OGLWIDGET_HPP

#define GL_SILENCE_DEPRECATION

#include <QOpenGLWidget>

extern "C"
{
    #include "viewer.h"
}

class OGLwidget : public QOpenGLWidget
{
    Q_OBJECT
private:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void ortho();
    void transform();
    void draw();

    t_info copy;
public:
    OGLwidget(QWidget *parrent = nullptr);

    void obj_upload();
    void updateFrame();

    const char  *fileName;
    t_info      orig;
    double      rot[3] = {0,0,0};
    double      trans[3] = {0,0,0};
    double      scale = 1;

signals:
    void countTrigger(size_t v, size_t f);
};

#endif // OGLWIDGET_H
