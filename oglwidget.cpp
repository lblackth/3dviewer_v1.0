#include "mainwindow.h"

OGLwidget::OGLwidget(QWidget* parent) : QOpenGLWidget(parent) {;}


void OGLwidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
}

void OGLwidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void OGLwidget::paintGL()
{
    ortho();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if(copy.vertexes) {
        transform();
        draw();
        info_dup(&orig, &copy);
    }
}

void OGLwidget::draw()
{
    glVertexPointer(3, GL_DOUBLE, 0, copy.vertexes);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawElements(GL_LINES, copy.f_amount * 2, GL_UNSIGNED_INT, copy.facets);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void OGLwidget::obj_upload()
{
    if (parse(fileName, &orig))
    {
        emit countTrigger(orig.v_amount, orig.f_amount);
        info_dup(&orig, &copy);
        updateFrame();
    }
}

void OGLwidget::ortho()
{
    double d1 = orig.minMax[1] - orig.minMax[0];
    double d2 = orig.minMax[3] - orig.minMax[2];
    double d3 = orig.minMax[5] - orig.minMax[4];

    double d = d1;
    if (d2 > d1)
        d = d2;
    if (d3 > d2)
        d = d3;
    double fov = 60.0 * M_PI / 180;
    double near = 5 * (orig.minMax[3] / (2 * tan(fov / 2)));
    double cX = (orig.minMax[1] + orig.minMax[0]) / 2;
    double cY = (orig.minMax[3] + orig.minMax[2]) / 2;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(cX - d * 0.6, cX + d * 0.6, cY - d * 0.6, cY + d * 0.6, near, 3000);
    glTranslated(0, 0, -near * 3);

}

void OGLwidget::updateFrame()
{
    update();
}

void OGLwidget::transform()
{
    if (rot[0])
        ft_ox_rotate(copy.vertexes, copy.v_amount, rot[0]);
    if (rot[1])
        ft_oy_rotate(copy.vertexes, copy.v_amount, rot[1]);
    if (rot[2])
        ft_oz_rotate(copy.vertexes, copy.v_amount, rot[2]);
    if (trans[0])
        ft_translate(copy.vertexes, copy.v_amount, 0, trans[0]);
    if (trans[1])
        ft_translate(copy.vertexes, copy.v_amount, 1, trans[1]);
    if (trans[2])
        ft_translate(copy.vertexes, copy.v_amount, 2, trans[2]);
    if (scale != 1)
        ft_scale(copy.vertexes, copy.v_amount, scale);
}
