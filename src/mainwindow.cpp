#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutwindow.h"

/**
 * {@inheritDoc}
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * {@inheritDoc}
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * {@inheritDoc}
 */
void MainWindow::on_actionMittelpunktsquadrik_triggered()
{
    this->setCoefficients(
                // a, b, c
                1.0, 1.0, 1.0,
                // f, g, h
                0.0, 0.0, 0.0,
                // p, q, r
                0.0, 0.0, 0.0,
                // d
                -1.0);
}

/**
 * {@inheritDoc}
 */
void MainWindow::on_actionKegeliger_Typ_triggered()
{

}

/**
 * {@inheritDoc}
 */
void MainWindow::on_actionParabolischer_Typ_triggered()
{

}

/**
 * {@inheritDoc}
 */
void MainWindow::on_actionEllipsoid_triggered()
{
    this->setCoefficients(
                // a, b, c
                1.0, 1.0, 1.0,
                // f, g, h
                0.0, 0.0, 0.0,
                // p, q, r
                0.0, 0.0, 0.0,
                // d
                -1.0);
}

/**
 * {@inheritDoc}
 */
void MainWindow::on_actionHyperboloidEinschalig_triggered()
{
    this->setCoefficients(
                // a, b, c
                1.0, -1.0, 1.0,
                // f, g, h
                0.0, 0.0, 0.0,
                // p, q, r
                0.0, 0.0, 0.0,
                // d
                -1.0);
}

/**
 * {@inheritDoc}
 */
void MainWindow::on_actionHyperboloidZweischalig_triggered()
{
    this->setCoefficients(
                // a, b, c
                1.0, -1.0, 1.0,
                // f, g, h
                0.0, 0.0, 0.0,
                // p, q, r
                0.0, 0.0, 0.0,
                // d
                1.0);
}

/**
 * {@inheritDoc}
 */
void MainWindow::on_actionParaboloidElliptisch_triggered()
{
    this->setCoefficients(
                // a, b, c
                1.0, 0.0, 1.0,
                // f, g, h
                0.0, 0.0, 0.0,
                // p, q, r
                0.0, -0.5, 0.0,
                // d
                0.0);
}

/**
 * {@inheritDoc}
 */
void MainWindow::on_actionParaboloidHyperbolisch_triggered()
{
    this->setCoefficients(
                // a, b, c
                1.0, 0.0, -1.0,
                // f, g, h
                0.0, 0.0, 0.0,
                // p, q, r
                0.0, -0.5, 0.0,
                // d
                0.0);
}

/**
 * {@inheritDoc}
 */
void MainWindow::on_actionBeenden_triggered()
{
    QApplication::quit();
}

/**
 * {@inheritDoc}
 */
void MainWindow::on_actionInfo_triggered()
{
    about = new AboutWindow(this);
    about->show();
}

/**
 * {@inheritDoc}
 */
void MainWindow::setCoefficients(//
        double a, double b, double c,   //
        double f, double g, double h,   //
        double p, double q, double r,   //
        double d)                       //
{

}

/**
 * {@inheritDoc}
 */
void MainWindow::updateEquation(void)
{
    QString e = "NAN";
/*
    if (q->getA() != 0.0f) {
        //e.append(q->getA());
        e.append("x<sup>2</sup>");
    }
    if (q->getB() != 0.0f) {
        //e.append(q->getB());
        e.append(" + y<sup>2</sup>");
    }
    if (q->getC() != 0.0f) {
        //e.append(q->getC());
        e.append(" + z<sup>2</sup>");
    }
    if (q->getF() != 0.0f) {
        //e.append(q->getF() * 2);
        e.append(" + yz");
    }
    if (q->getG() != 0.0f) {
        //e.append(q->getG() * 2);
        e.append(" + zx");
    }
    if (q->getH() != 0.0f) {
        //e.append(q->getH() * 2);
        e.append(" + xy");
    }
    if (q->getP() != 0.0f) {
        //e.append(q->getP());
        e.append(" + x");
    }
    if (q->getQ() != 0.0f) {
        //e.append(q->getQ());
        e.append(" + y");
    }
    if (q->getR() != 0.0f) {
        //e.append(q->getR());
        e.append(" + z");
    }
    if (q->getD() != 0.0f) {
        //e.append(q->getD());
        e.append(" + d");
    }
    if (e.isEmpty() || (q->getA() == 0 & q->getB() == 0 & q->getC() == 0)) {
        e.clear();
        e.append("NaN");
    } else {
        e.append(" = 0");
        if (e.startsWith(" ")) {
            e.remove(0,3);
        }
    }
*/
    ui->equation->setText(e);

}
/**
 * {@inheritDoc}
 */
void MainWindow::setHomography(//
        float h11, float h12, float h13, //
        float h21, float h22, float h23, //
        float h31, float h32, float h33, //
        float h41, float h42, float h43, float h44) //
{
    ui->doubleSpinBox_11->setValue(h11);
    ui->doubleSpinBox_12->setValue(h12);
    ui->doubleSpinBox_13->setValue(h13);

    ui->doubleSpinBox_21->setValue(h21);
    ui->doubleSpinBox_22->setValue(h22);
    ui->doubleSpinBox_23->setValue(h23);

    ui->doubleSpinBox_31->setValue(h31);
    ui->doubleSpinBox_32->setValue(h32);
    ui->doubleSpinBox_33->setValue(h33);

    ui->doubleSpinBox_31->setValue(h41);
    ui->doubleSpinBox_32->setValue(h42);
    ui->doubleSpinBox_33->setValue(h43);
    ui->doubleSpinBox_33->setValue(h44);
    //
    this->updateEquation();
}
