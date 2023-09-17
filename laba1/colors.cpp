#include "colors.h"
#include "ui_colors.h"
QColor color;
Colors::Colors(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Colors)
{
    ui->setupUi(this);
    colorRectangle = new QLabel(ui->palete);
    colorRectangle->setStyleSheet("QLabel{background-color:rgb(0,0,0);border:0px solid black;}");
    colorRectangle->setMinimumSize(451,31);
    colorRectangle->setMaximumSize(451,31);
    GradientLabel = new QLabel(ui->widget_color);
    GradientLabel->installEventFilter(this);
    ui->horizontalSlider->setRange(0,255);
    ui->horizontalSlider->setRange(0,255);
    ui->horizontalSlider_3->setRange(0,255);
    ui->spinBox_4->hide();
    ui->spinBox_8->hide();
    ui->spinBox_12->hide();
    ui->spinBox->setRange(0,255);
    ui->spinBox_2->setRange(0,255);
    ui->spinBox_3->setRange(0,255);
    ui->spinBox_5->setRange(0,96);
    ui->spinBox_6->setRange(0,100);
    ui->spinBox_7->setRange(0,108);
    ui->spinBox_9->setRange(0,360);
    ui->spinBox_10->setRange(0,100);
    ui->spinBox_11->setRange(0,100);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(setColor()));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), this, SLOT(setColor()));
    connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), this, SLOT(setColor()));

    connect(ui->spinBox, SIGNAL(editingFinished()), this, SLOT(changed_SpinFirst()));
    connect(ui->spinBox_2,SIGNAL(editingFinished()), this, SLOT(changed_SpinSecond()));
    connect(ui->spinBox_3,SIGNAL(editingFinished()), this, SLOT(changed_SpinThird()));
    connect(ui->spinBox_4,SIGNAL(editingFinished()), this, SLOT(changed_SpinFourth()));



    connect(ui->spinBox_5, SIGNAL(editingFinished()), this, SLOT(changed_SpinFirst_center()));
    connect(ui->spinBox_6,SIGNAL(editingFinished()), this, SLOT(changed_SpinSecond_center()));
    connect(ui->spinBox_7,SIGNAL(editingFinished()), this, SLOT(changed_SpinThird_center()));
    connect(ui->spinBox_8,SIGNAL(editingFinished()), this, SLOT(changed_SpinFourth_center()));

    connect(ui->spinBox_9, SIGNAL(editingFinished()), this, SLOT(changed_SpinFirst_right()));
    connect(ui->spinBox_10,SIGNAL(editingFinished()), this, SLOT(changed_SpinSecond_right()));
    connect(ui->spinBox_11,SIGNAL(editingFinished()), this, SLOT(changed_SpinThird_right()));
    connect(ui->spinBox_12,SIGNAL(editingFinished()), this, SLOT(changed_SpinFourth_right()));

}
void Colors::on_comboBox_currentTextChanged(QString text)
{
    ui->spinBox_4->hide();
    if(text=="RGB")
    {
        ui->label->setText("R:");
        ui->label_2->setText("G:");
        ui->label_3->setText("B:");
        ui->label_4->setText("");
        ui->spinBox->setRange(0,255);
         ui->spinBox_2->setRange(0,255);
         ui->spinBox_3->setRange(0,255);
    }
    if(text=="CMYK")
    {
        ui->label->setText("C:");
        ui->label_2->setText("M:");
        ui->label_3->setText("Y:");
        ui->label_4->setText("K");
        ui->spinBox_4->show();
        ui->spinBox->setRange(0,255);
        ui->spinBox_2->setRange(0,255);
        ui->spinBox_3->setRange(0,255);
        ui->spinBox_4->setRange(0,255);
    }
    if(text == "XYZ")
    {
        ui->label->setText("X:");
        ui->label_2->setText("Y:");
        ui->label_3->setText("Z:");
        ui->label_4->setText("");
        ui->spinBox->setRange(0,96);
        ui->spinBox_2->setRange(0,100);
        ui->spinBox_3->setRange(0,108);
    }
    if(text=="HSV")
    {
        ui->label->setText("H:");
        ui->label_2->setText("S:");
        ui->label_3->setText("V:");
        ui->label_4->setText("");
        ui->spinBox->setRange(0,360);
        ui->spinBox_2->setRange(0,100);
        ui->spinBox_3->setRange(0,100);
    }
    setTexteverywhere();
}
void Colors::changed_SpinFirst()
{
    if (ui->comboBox->currentText() == "RGB") {
        color.setRed(ui->spinBox->value());
        color_convertation();
    }

    if (ui->label->text( )== "C:") {
        color.setCmyk(ui->spinBox->value(), color.magenta(), color.yellow(), color.black());
        color_convertation();
    }

    if (ui->label->text()== "H:") {
        color.setHsv(ui->spinBox->value(), color.saturation(), color.value());
        color_convertation();
    }

    if (ui->label->text( )== "X:") {
        setX(ui->spinBox->value());
        color_convertation_from_XYZ();
    }
    setSlider();
    setTexteverywhere();
}
void Colors::changed_SpinSecond()
{
    if (ui->comboBox->currentText() == "RGB") {
        color.setGreen(ui->spinBox_2->value());
        color_convertation();
    }

    if (ui->label_2->text()== "M:") {
        color.setCmyk(color.cyan(), ui->spinBox_2->value(), color.yellow(), color.black());
        color_convertation();
    }

    if (ui->label_2->text() == "S:") {
        color.setHsv(color.hue(), ui->spinBox_2->value(), color.value());
        color_convertation();
    }

    if (ui->comboBox_center->currentText() == "XYZ") {
        setY(ui->spinBox_2->value());
        color_convertation_from_XYZ();
    }
    setSlider();
    setTexteverywhere();
}
void Colors::changed_SpinThird()
{
    if (ui->label_3->text() == "B:") {
        color.setBlue(ui->spinBox_3->value());
        color_convertation();
    }

    if (ui->label_3->text() == "Y:") {
        color.setCmyk(color.cyan(), color.magenta(), ui->spinBox_3->value(), color.black());
        color_convertation();
    }

    if (ui->label_3->text() == "V:") {
        color.setHsv(color.hue(), color.saturation(),ui->spinBox_3->value());
        color_convertation();
    }

    if (ui->label_3->text() == "Z:") {
        setZ(ui->spinBox_3->value());
        color_convertation_from_XYZ();
    }

    setSlider();
    setTexteverywhere();
}
void Colors::changed_SpinFourth()
{
    color.setCmyk(color.cyan(), color.magenta(),color.yellow(), ui->spinBox_4->value());
    color_convertation();
    setSlider();
    setTexteverywhere();
}
void Colors::changed_SpinFirst_center()
{
    if (ui->comboBox_center->currentText() == "XYZ") {
        setX(ui->spinBox_5->value());
        color_convertation_from_XYZ();
    }

    if (ui->comboBox_center->currentText()== "CMYK") {
        color.setCmyk(ui->spinBox_5->value(), color.magenta(), color.yellow(), color.black());
        color_convertation();
    }

    if (ui->label_5->text() == "L:") {
        LAB_L = ui->spinBox_5->value();
        color_convertation_from_LAB();
    }

    if (ui->comboBox_center->currentText()== "HSV") {
        color.setHsv(ui->spinBox_5->value(), color.saturation(), color.value());
        color_convertation();
    }

    if (ui->label_5->text() == "R:") {
        XYZ_X =ui->spinBox_5->value();
        XYZ_Y = ui->spinBox_6->value();
        XYZ_Z = ui->spinBox_7->value();
        color_convertation_from_XYZ();
    }

    if ( ui->comboBox_center->currentText()== "HSL") {
        color.setHsl(ui->spinBox_5->value(),  color.hslSaturation(),color.lightness());
        color_convertation();
    }

    setSlider();
    setTexteverywhere();
}
void Colors::changed_SpinSecond_ctnter()
{
    if ( ui->comboBox_center->currentText()== "XYZ") {
        setY(ui->spinBox_7->value());
        color_convertation_from_XYZ();
    }

    if (ui->label_7->text() == "M:") {
        color.setCmyk(color.cyan(),ui->spinBox_6->value(),  color.yellow(), color.black());
        color_convertation();
    }

    if (ui->label_7->text() == "A:") {
        LAB_A = ui->spinBox_6->value();
        color_convertation_from_LAB();
    }

    if (ui->comboBox_center->currentText() == "HSV") {
        color.setHsv(color.hue(), ui->spinBox_6->value(), color.value());
        color_convertation();
    }

    if (ui->label_7->text() == "G:") {
        color.setGreen(ui->spinBox_6->value());
        color_convertation();
    }

    if (ui->comboBox_center->currentText()== "HSL") {
        color.setHsl(color.hslHue(), ui->spinBox_6->value(), color.lightness() );
        color_convertation();
    }

    setSlider();
    setTexteverywhere();
}
void Colors::changed_SpinThird_center()
{
    if (ui->comboBox_center->currentText()== "XYZ") {
        setZ(ui->spinBox_7->value());
        color_convertation_from_XYZ();
    }

    if ( ui->comboBox_center->currentText()== "LAB") {
        LAB_B = ui->spinBox_7->value();
        color_convertation_from_LAB();
    }

    if (ui->comboBox_center->currentText()== "CMYK") {
        color.setCmyk(color.cyan(), color.magenta(), ui->spinBox_7->value(), color.black());
        color_convertation();
    }
    if (ui->comboBox_center->currentText()== "HSV") {
        color.setHsv(color.hue(), color.saturation(), ui->spinBox_7->value());
        color_convertation();
    }

    if (ui->comboBox_center->currentText() == "RGB") {
        color.setBlue(ui->spinBox_7->value());
        color_convertation();
    }

    if (ui->comboBox_center->currentText()== "HSL") {
        color.setHsl(color.hslHue(),color.hslSaturation(),ui->spinBox_7->value());
        color_convertation();
    }

    setSlider();
    setTexteverywhere();
}
void Colors::changed_SpinFourth_center()
{
    color.setCmyk(color.cyan(), color.magenta(), color.yellow(), ui->spinBox_8->value());
    color_convertation();
    setSlider();
    setTexteverywhere();
}

void Colors::changed_SpinFirst_right()
{
    if (ui->comboBox_3->currentText() == "HLS") {
        color.setHsl(ui->spinBox_9->value(), color.hslSaturation(), color.lightness());
        color_convertation();
    }
    if (ui->comboBox_3->currentText() == "CMYK") {
        color.setCmyk(ui->spinBox_9->value(),color.magenta(),color.yellow(), color.black());
        color_convertation();
    }

    if (ui->comboBox_3->currentText() == "LAB") {
        LAB_L = ui->spinBox_9->value();
        color_convertation_from_LAB();
    }

    if (ui->comboBox_3->currentText() == "HSV") {
        color.setHsv(ui->spinBox_9->value(), color.saturation(), color.value());
        color_convertation();
    }

    if (ui->comboBox_3->currentText() == "RGB") {
        color.setRed(ui->spinBox_9->value());
        color_convertation();
    }

    setSlider();
    setTexteverywhere();
}

void Colors::changed_SpinSecond_right()
{
    if (ui->comboBox_3->currentText() == "HSL") {
        color.setHsl(color.hslHue(), ui->spinBox_10->value(), color.lightness());
        color_convertation();
    }

    if (ui->comboBox_3->currentText() == "CMYK") {
        color.setCmyk(color.cyan(),ui->spinBox_10->value(),color.yellow(), color.black());
        color_convertation();
    }
    if (ui->comboBox_3->currentText() == "LAB") {
        LAB_A = ui->spinBox_10->value();
        color_convertation_from_LAB();
    }

    if (ui->comboBox_3->currentText() == "HSV") {
        color.setHsv(color.hue(),ui->spinBox_10->value(),  color.value());
        color_convertation();
    }

    if (ui->comboBox_3->currentText() == "RGB") {
        color.setGreen(ui->spinBox_10->value());
        color_convertation();
    }

    setSlider();
    setTexteverywhere();
}

void Colors::changed_SpinThird_right()
{
    if (ui->comboBox_3->currentText()== "HSL") {
        color.setHsl(color.hslHue(),color.hslSaturation(), ui->spinBox_11->value());
        color_convertation();
    }

    if (ui->comboBox_3->currentText() == "CMYK") {
        color.setCmyk(color.cyan(),  color.magenta(),ui->spinBox_11->value(), color.black());
        color_convertation();
    }
    if (ui->comboBox_3->currentText() == "LAB") {
        LAB_B = ui->spinBox_11->value();
        color_convertation_from_LAB();
    }

    if (ui->comboBox_3->currentText() == "HSV") {
        color.setHsv(color.hue(), color.saturation(), ui->spinBox_11->value());
        color_convertation();
    }

    if (ui->comboBox_3->currentText() == "RGB") {
        color.setBlue(ui->spinBox_11->value());
        color_convertation();
    }

    setSlider();
    setTexteverywhere();
}

void Colors::changed_SpinFourth_right()
{
    color.setCmyk(color.cyan(), color.magenta(), color.yellow(),ui->spinBox_12->value());
    color_convertation();
    setSlider();
    setTexteverywhere();
}

void Colors::setSlider()
{
    ui->horizontalSlider->setValue(color.red());
    ui->horizontalSlider_2->setValue(color.green());
    ui->horizontalSlider_3->setValue(color.blue());
}
void Colors::color_convertation()
{
    double Rn = F_RGB_XYZ(color.red() / 255.0);
    double Gn = F_RGB_XYZ(color.green() / 255.0);
    double Bn = F_RGB_XYZ(color.blue() / 255.0);

    double XYZ_X1 = 0.412453*Rn + 0.357580 * Gn + 0.180423 * Bn;
    double XYZ_Y1 = 0.212671*Rn + 0.715160 * Gn + 0.072169 * Bn;
    double XYZ_Z1 = 0.019334*Rn + 0.119193 * Gn + 0.950227 * Bn;

    XYZ_X1*=100.0;
    XYZ_Y1*=100.0;
    XYZ_Z1*=100.0;

    setX(XYZ_X1);
    setY(XYZ_Y1);
    setZ(XYZ_Z1);

    double X = XYZ_X1 / 95.047;
    double Y = XYZ_Y1 / 100.0;
    double Z = XYZ_Z1 / 108.883;

    LAB_L = 116 * F_XYZ_LAB(Y) - 16;
    LAB_A = 500 * (F_XYZ_LAB(X) - F_XYZ_LAB(Y));
    LAB_B = 200 * (F_XYZ_LAB(Y) - F_XYZ_LAB(Z));

}
double Colors::F_XYZ_RGB(double x)
{

    if (abs(x)<0.0031308) {
    return 12.92 * x;
    }

    return 1.055 * pow(x, 0.41666) - 0.055;
}

double  Colors::F_RGB_XYZ(double x) {
    if (x>=0.04045) {
    return pow((x+0.055)/1.055, 2.4);
    }
    return x/12.92;
}

double Colors::F_XYZ_LAB(double x) {
    if (x >= 0.008856) {
    return pow(x, 1.0/3.0);
    }
    return 7.787 * x + 16.0 /(double) 116.0;
}
void Colors::color_convertation_from_XYZ() {

    double X = getX();
    double Y = getY();
    double Z = getZ();

    double Rn = 3.2404542 * X - 1.5371385 * Y  - 0.4985314 * Z;
    double Gn = -0.9692660 * X + 1.8760108 * Y  + 0.0415560 * Z;
    double Bn = 0.0556434 * X - 0.2040259 * Y  + 1.0572252 * Z;

    Rn/=100.0;
    Gn/=100.0;
    Bn/=100.0;

    double R = F_XYZ_RGB(Rn);
    double G = F_XYZ_RGB(Gn);
    double B = F_XYZ_RGB(Bn);

    R*=255.0;
    G*=255.0;
    B*=255.0;

    color.setRed(round(R));
    color.setGreen(round(G));
    color.setBlue(round(B));

    LAB_L = 116 * F_XYZ_LAB(X/(double) 100.0)-16;
    LAB_A = 500 * (F_XYZ_LAB(X/95.047)-F_XYZ_LAB(Y/(double) 100.0));
    LAB_B = 200 * (F_XYZ_LAB(Y/(double) 100.0)- F_XYZ_LAB(Z/(double) 108.883));

}

double Colors::F_LAB_XYZ(double x) {
    if (pow(x,3)>=0.008856) {
    return pow(x,3);
    }
    return (x-16.0/116.0)/7.878;
}

void Colors::color_convertation_from_LAB() {
    double XYZ_X1 = F_LAB_XYZ(LAB_A/500.0+(LAB_L+16.0)/116.0) * 95.047;
    double XYZ_Y1 = F_LAB_XYZ((LAB_L+16.0)/116.0) * 100.0;
    double XYZ_Z1 = F_LAB_XYZ((LAB_L+16.0)/116.0-LAB_B/200) * 108.883;

    setX(XYZ_X1);
    setY(XYZ_Y1);
    setZ(XYZ_Z1);

    double Rn = 3.2406 * XYZ_X1 / 100 - 1.5372 * XYZ_Y1 / 100 - 0.4986 * XYZ_Z1 / 100;
    double Gn = -0.9689 * XYZ_X1 / 100 + 1.8758 * XYZ_Y1 / 100 + 0.0415 * XYZ_Z1 / 100;
    double Bn = 0.0557 * XYZ_X1 / 100 - 0.2040 * XYZ_Y1 / 100 + 1.0570 * XYZ_Z1 / 100;

    color.setRed(round(F_XYZ_RGB(Rn)*255));
   color.setGreen(round(F_XYZ_RGB(Gn)*255));
    color.setBlue(round(F_XYZ_RGB(Bn)*255));
}

Colors::~Colors()
{
    delete ui;
}

void Colors::setColor()
{
    color.setRed(ui->horizontalSlider->value());
    color.setGreen(ui->horizontalSlider_2->value());
    color.setBlue(ui->horizontalSlider_3->value());
    color_convertation();
    QString r = QString::number(color.red());
    QString g = QString::number(color.green());
    QString b = QString::number(color.blue());
    colorRectangle->setStyleSheet("QLabel{background-color:rgb("+r+
                                  ","+g+","+b+");}");
    setTexteverywhere();

}


void Colors::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPixmap Grad(GradientLabel->width(), GradientLabel->height());
    QPainter paint(&Grad);
    double radius =200;
    QLinearGradient linearGradient(0,0, radius,0);
    linearGradient.setColorAt(0.0, Qt::red);
    linearGradient.setColorAt(0.35, Qt::yellow);
    linearGradient.setColorAt(0.5, Qt::green);
    linearGradient.setColorAt(0.65, Qt::cyan);
    linearGradient.setColorAt(0.8, Qt::blue);
    linearGradient.setColorAt(1.0, Qt::magenta);
    GradientLabel->setPixmap(Grad);
    GradientLabel->setMinimumSize(200,200);
    GradientLabel->setMaximumSize(200,200);
    paint.setBrush(linearGradient);
    paint.drawRect(0,0,GradientLabel->width()-1,GradientLabel->height()-1);
    GradientLabel->update();
//    QPixmap pix(GradientLabel->width(),GradientLabel->height());
//    QPixmap pix2(GradientLabel->width(),GradientLabel->height());
//    QPainter painter(&pix);
//    QPainter painter2(&pix2);
//    QLinearGradient gradl(0,0,pix.width(),0);
//    gradl.setColorAt(0,Qt::red);
//    gradl.setColorAt(0.18,Qt::yellow);
//    gradl.setColorAt(0.36,Qt::green);
//    gradl.setColorAt(0.54,Qt::blue);
//    gradl.setColorAt(0.8,Qt::darkBlue);
//    gradl.setColorAt(1,Qt::magenta);
//    painter.setBrush(gradl);
//    GradientLabel->setMinimumSize(200,200);
//    GradientLabel->setMaximumSize(200,200);
//    painter.drawRect(0,0,GradientLabel->width(),GradientLabel->height());
//    GradientLabel->setPixmap(pix);
}
double Colors::getY() const
{
    return XYZ_Y;
}

double Colors::getX() const
{
    return XYZ_X;
}

double Colors::getZ() const
{
    return XYZ_Z;
}

void Colors::setX(double x)
{
    XYZ_X = x;
}

void Colors::setY(double x)
{
    XYZ_Y = x;
}

void Colors::setZ(double x)
{
    XYZ_Z = x;
}
void Colors::setTexteverywhere()
{
    if (ui->comboBox->currentText() == "RGB") {
        ui->spinBox->setValue(color.red());
        ui->spinBox_2->setValue(color.green());
        ui->spinBox_3->setValue(color.blue());
    }

    if (ui->comboBox->currentText()  == "HSV") {
        ui->spinBox->setValue(color.hue());
        ui->spinBox_2->setValue(color.saturation());
        ui->spinBox_3->setValue(color.value());
    }

    if (ui->comboBox->currentText() == "XYZ") {

        ui->spinBox->setValue(getX());
        ui->spinBox_2->setValue(getY());
        ui->spinBox_3->setValue(getZ());
    }

    if (ui->comboBox->currentText()  == "CMYK") {

        ui->spinBox->setValue(color.cyan());
        ui->spinBox_2->setValue(color.magenta());
        ui->spinBox_3->setValue(color.yellow());
        ui->spinBox_4->setValue(color.black());
    }

    if (ui->comboBox_center->currentText() == "LAB") {
        ui->spinBox_5->setValue(LAB_L);
        ui->spinBox_6->setValue(LAB_A);
         ui->spinBox_7->setValue(LAB_B);
    }

    if (ui->comboBox_center->currentText()  == "CMYK") {
         ui->spinBox_5->setValue(color.cyan());
         ui->spinBox_6->setValue(color.magenta());
         ui->spinBox_7->setValue(color.yellow());
         ui->spinBox_8->setValue(color.black());
    }

    if (ui->comboBox_center->currentText()  == "XYZ") {
         ui->spinBox_5->setValue(getX());
         ui->spinBox_6->setValue(getY());
         ui->spinBox_7->setValue(getZ());
    }

    if (ui->comboBox_center->currentText()  == "HSV") {
         ui->spinBox_5->setValue(color.hue());
         ui->spinBox_6->setValue(color.saturation());
         ui->spinBox_7->setValue(color.value());
    }

    if (ui->comboBox_center->currentText()  == "RGB") {
         ui->spinBox_5->setValue(color.red());
         ui->spinBox_6->setValue(color.green());
         ui->spinBox_7->setValue(color.blue());
    }

    if (ui->comboBox_center->currentText()  == "HSL") {

         ui->spinBox_5->setValue(color.hslHue());
        ui->spinBox_7->setValue(color.lightness());
        ui->spinBox_6->setValue(color.hslSaturation());
    }

    if (ui->comboBox_3->currentText() == "CMYK") {
        ui->spinBox_9->setValue(color.cyan());
        ui->spinBox_10->setValue(color.magenta());
        ui->spinBox_11->setValue(color.yellow());
        ui->spinBox_12->setValue(color.black());
    }

    if (ui->comboBox_3->currentText()  == "HSL") {

        ui->spinBox_9->setValue(color.hslHue());
        ui->spinBox_11->setValue(color.lightness());
        ui->spinBox_10->setValue(color.hslSaturation());
    }

    if (ui->comboBox_3->currentText() == "LAB") {
        ui->spinBox_9->setValue(LAB_L);
        ui->spinBox_10->setValue(LAB_A);
        ui->spinBox_11->setValue(LAB_B);
    }

    if (ui->comboBox_3->currentText() == "HSV") {
        ui->spinBox_9->setValue(color.hue());
        ui->spinBox_10->setValue(color.saturation());
        ui->spinBox_11->setValue(color.value());
    }

    if (ui->comboBox_3->currentText()  == "RGB") {
        ui->spinBox_9->setValue(color.red());
        ui->spinBox_10->setValue(color.green());
        ui->spinBox_11->setValue(color.blue());
    }
}


void Colors::on_comboBox_center_currentTextChanged(QString text)
{
    ui->spinBox_8->hide();
    if(text == "RGB")
    {
        ui->label_5->setText("R:");
        ui->label_6->setText("G:");
        ui->label_7->setText("B:");
        ui->label_8->setText("");
        ui->spinBox_5->setRange(0,255);
        ui->spinBox_6->setRange(0,255);
        ui->spinBox_7->setRange(0,255);
    }
    if(text == "HSV")
    {
        ui->label_5->setText("H:");
        ui->label_6->setText("S:");
        ui->label_7->setText("V:");
        ui->label_8->setText("");
        ui->spinBox_5->setRange(0,360);
        ui->spinBox_6->setRange(0,100);
        ui->spinBox_7->setRange(0,100);
    }
    if(text == "XYZ")
    {

        ui->label_5->setText("X:");
        ui->label_6->setText("Y:");
        ui->label_7->setText("Z:");
        ui->label_8->setText("");
        ui->spinBox_5->setRange(0,96);
        ui->spinBox_6->setRange(0,100);
        ui->spinBox_7->setRange(0,108);
    }
    if(text == "CMYK")
    {
        ui->label_5->setText("C:");
        ui->label_6->setText("M:");
        ui->label_7->setText("Y:");
        ui->label_8->setText("K");
        ui->spinBox_8->show();
        ui->spinBox_5->setRange(0,255);
        ui->spinBox_6->setRange(0,255);
        ui->spinBox_7->setRange(0,255);
        ui->spinBox_8->setRange(0,255);
    }
    if(text == "LAB")
    {

        ui->label_5->setText("L:");
        ui->label_6->setText("A:");
        ui->label_7->setText("B:");
        ui->label_8->setText("");
        ui->spinBox_5->setRange(0,100);
        ui->spinBox_6->setRange(0,100);
        ui->spinBox_7->setRange(0,100);
    }
    if(text == "HSL")
    {
        ui->label_5->setText("H:");
        ui->label_6->setText("S:");
        ui->label_7->setText("L:");
        ui->label_8->setText("");
        ui->spinBox_5->setRange(0,360);
        ui->spinBox_6->setRange(0,100);
        ui->spinBox_7->setRange(0,100);
    }
    setTexteverywhere();
}


void Colors::on_comboBox_3_currentTextChanged(QString text)
{
    ui->spinBox_12->hide();
    if(text == "RGB")
    {
        ui->label_9->setText("R:");
        ui->label_10->setText("G:");
        ui->label_11->setText("B:");
        ui->label_12->setText("");
        ui->spinBox_9->setRange(0,255);
        ui->spinBox_10->setRange(0,255);
        ui->spinBox_11->setRange(0,255);
    }
    if(text== "HSV")
    {
        ui->label_9->setText("H:");
        ui->label_10->setText("S:");
        ui->label_11->setText("V:");
        ui->label_12->setText("");
        ui->spinBox_9->setRange(0,360);
        ui->spinBox_10->setRange(0,100);
        ui->spinBox_11->setRange(0,100);

    }
    if(text == "HSL")
    {
        ui->label_9->setText("H:");
        ui->label_10->setText("S:");
        ui->label_11->setText("L:");
        ui->label_12->setText("");
        ui->spinBox_9->setRange(0,360);
        ui->spinBox_10->setRange(0,100);
        ui->spinBox_11->setRange(0,100);


    }
    if(text == "XYZ")
    {

        ui->label_9->setText("X:");
        ui->label_10->setText("Y:");
        ui->label_11->setText("Z:");
        ui->label_12->setText("");
        ui->spinBox_9->setRange(0,96);
        ui->spinBox_10->setRange(0,100);
        ui->spinBox_11->setRange(0,108);

    }
    if(text == "CMYK")
    {
        ui->label_9->setText("C:");
        ui->label_10->setText("M:");
        ui->label_11->setText("Y:");
        ui->label_12->setText("K");
        ui->spinBox_12->show();
        ui->spinBox_9->setRange(0,255);
        ui->spinBox_10->setRange(0,255);
        ui->spinBox_11->setRange(0,255);
        ui->spinBox_12->setRange(0,255);
    }
    if(text  == "LAB")
    {

        ui->label_9->setText("L:");
        ui->label_10->setText("A:");
        ui->label_11->setText("B:");
        ui->label_12->setText("");
        ui->spinBox_9->setRange(0,100);
        ui->spinBox_10->setRange(0,100);
        ui->spinBox_11->setRange(0,100);


    }
    setTexteverywhere();
}

bool Colors::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress && watched == GradientLabel) {
        QMouseEvent* cur = dynamic_cast<QMouseEvent*>(event);
        int x = cur->pos().x() + GradientLabel->x();
        int y = cur->pos().y() + GradientLabel->y();
        color = QWidget::grab(QRect(x,y,1,1)).toImage().pixelColor(0,0);
        setTexteverywhere();
        setSlider();
    }

    return false;
}
