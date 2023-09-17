#ifndef COLORS_H
#define COLORS_H

#include <QMainWindow>
#include <QColor>
#include <QLabel>
#include <QPainter>
#include <QColor>
#include <QtWidgets>
QT_BEGIN_NAMESPACE
namespace Ui { class Colors; }
QT_END_NAMESPACE

class Colors : public QMainWindow
{
    Q_OBJECT

public:
    Colors(QWidget *parent = nullptr);
    ~Colors();
private:
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);

    double F_XYZ_RGB(double x);
    double  F_RGB_XYZ(double x) ;
    double F_XYZ_LAB(double x);
    void color_convertation_from_XYZ();
    void color_convertation();
    void setTexteverywhere();
    double F_LAB_XYZ(double x);
    void setSlider();
    void color_convertation_from_LAB();
private slots:
    void changed_SpinFirst();
    void on_comboBox_currentTextChanged(QString text);
    void on_comboBox_center_currentTextChanged(QString text);
    void setColor();
    void on_comboBox_3_currentTextChanged( QString text);
    void changed_SpinSecond();
    void changed_SpinThird();
    void changed_SpinFourth();
    void changed_SpinFirst_center();
    void changed_SpinSecond_ctnter();
    void changed_SpinThird_center();
    void changed_SpinFourth_center();
    void changed_SpinFirst_right();
    void changed_SpinSecond_right();
    void changed_SpinThird_right();
    void changed_SpinFourth_right();

private:
    Ui::Colors *ui;
    QLabel *GradientLabel;

    double XYZ_X = 0;
    double XYZ_Y = 0;
    double XYZ_Z = 0;

    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double);
    void setY(double);
    void setZ(double);

    double LAB_L = 0;
    double LAB_A = 0;
    double LAB_B = 0;
    QPalette* myPalette;
    QLabel *colorRectangle;

};
#endif // COLORS_H
