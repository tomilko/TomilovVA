#include "graphpainter.h"

#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include <QtCore/qmath.h>
#include <QObject>

double pi = 3.1415;
double angl = pi / 8;

int xp;
int yp;

QBrush ver_color = QBrush(QColor(107, 179, 255));
QBrush color = QBrush(QColor(130, 230, 254));
QBrush num_color = QBrush(QColor(255, 255, 255));
QPen border_pen = QPen(QColor(0, 0, 0));

QString font_type = "segoe ui";
int font_type_size = 28;
int area_r = 300;
int ver_radius = 40;
int edge_leng = 30;

graph_painter::graph_painter() {}

void graph_painter::new_matrix() { graph_matrix = m_pivot->adj_matrix; }
void graph_painter::draw(QPainter *painter, QPaintEvent *event) { draw_graph(painter, event); }

void graph_painter::draw_graph(QPainter *painter, QPaintEvent* event)
{
    int ver_count = graph_matrix[0].size();
    area_r = qMax(painter->window().width() / 4, 100);

    yp = painter->window().height() / 2;
    xp = painter->window().width() / 2;

    painter->fillRect(event->rect(), color);
    painter->setBrush(ver_color);
    painter->setPen(border_pen);
    painter->setFont(QFont(font_type, font_type_size * 0.8));

    border_pen.setWidth(5);

    for (int i = 0; i < ver_count; i++)
    {
        double polarAngle = pi * 3 / 2 + pi * 2 / ver_count * i;

        int xc = cos(polarAngle) * area_r + xp;
        int yc = sin(polarAngle) * area_r + yp;

        int p1 = xc - 20;
        int p2 = yc - font_type_size / 2;
        int p3 = 40;
        int p4 = font_type_size;

        QString text; text.setNum(i + 1);
        painter->drawEllipse(QRectF(xc - ver_radius, yc - ver_radius, 2 * ver_radius, 2 * ver_radius));
        painter->drawText(QRect(p1, p2, p3, p4), Qt::AlignCenter, text);

        for (int k = 0; k < ver_count; k++)
        {
            if (graph_matrix[i][k] != 0)
            {
                double a2 = pi * 3 / 2 + pi * 2 / ver_count * k;
                double xp2 = cos(a2) * area_r + xp;
                double yp2 = sin(a2) * area_r + yp;
                double l = sqrt((xp2 - xc) * (xp2 - xc) + (yp2 - yc) * (yp2 - yc));

                int xl1 = (xp2 - xc) / l * ver_radius + xc;
                int yl1 = (yp2 - yc) / l * ver_radius + yc;
                int xl2 = xp2 - (xp2 - xc) / l * ver_radius;
                int yl2 = yp2 - (yp2 - yc) / l * ver_radius;

                painter->drawLine(xl1, yl1, xl2, yl2);

                double edge_angle;

                if (xp2 == xl2 && yl2 < yp2) edge_angle = pi * 3 / 2;
                else if (yp2 == yl2 && xl2 < xp2) edge_angle = pi;
                else if (xp2 == xl2 && yl2 > yp2) edge_angle = pi / 2;
                else if (yp2 == yl2 && xl2 > xp2) edge_angle = 0;
                else if (xl2 > xp2 && yl2 < yp2) edge_angle = atan((yp2 - yl2) / (xp2 - xl2)) + pi * 2;
                else if (xl2 < xp2 && yl2 < yp2) edge_angle = atan((yp2 - yl2) / (xp2 - xl2)) + pi;
                else if (xl2 < xp2 && yl2 > yp2) edge_angle = atan((yp2 - yl2) / (xp2 - xl2)) + pi;
                else if (xl2 > xp2 && yl2 > yp2) edge_angle = atan((yp2 - yl2) / (xp2 - xl2));

                int xs1 = cos(edge_angle + angl) * edge_leng + xl2;
                int ys1 = sin(edge_angle + angl) * edge_leng + yl2;
                int xs2 = cos(edge_angle - angl) * edge_leng + xl2;
                int ys2 = sin(edge_angle - angl) * edge_leng + yl2;

                painter->drawLine(xl2, yl2, xs1, ys1);
                painter->drawLine(xl2, yl2, xs2, ys2);

                int txt_w = 40;
                int txt_h = font_type_size + 5;
                int line_half_x = (xl2 + xl1) / 2;
                int line_half_y = (yl2 + yl1) / 2;

                QString mark_txt = QString::number(graph_matrix[i][k]);

                if (graph_matrix[i][k] != graph_matrix[k][i] && graph_matrix[i][k] != 0 && i != k
                        && graph_matrix[k][i] != 0)
                {
                    txt_w += 36;
                    mark_txt += "; " + QString::number(graph_matrix[k][i]);
                }

                painter->setBrush(num_color);
                painter->drawRect(line_half_x - txt_w / 2, line_half_y - txt_h / 2, txt_w, txt_h);

                painter->setBrush(ver_color);
                painter->drawText(QRect(line_half_x - txt_w / 2, line_half_y - txt_h / 2, txt_w, txt_h), Qt::AlignCenter, mark_txt);
            }
        }
    }
}

void graph_painter::new_pivot(pivot *pivot)
{
    if (pivot != nullptr)
    {
        m_pivot = pivot;
        new_matrix();
    }
}
