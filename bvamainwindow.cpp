#include "bvamainwindow.h"
#include "ui_bvamainwindow.h"

double prevNum;

BVAMainWindow::BVAMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BVAMainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(QSize(241, 350));

    connect(ui->bvaPushButton0, SIGNAL(clicked()), this, SLOT(bvaDigitsButtons()));
    connect(ui->bvaPushButton1, SIGNAL(clicked()), this, SLOT(bvaDigitsButtons()));
    connect(ui->bvaPushButton2, SIGNAL(clicked()), this, SLOT(bvaDigitsButtons()));
    connect(ui->bvaPushButton3, SIGNAL(clicked()), this, SLOT(bvaDigitsButtons()));
    connect(ui->bvaPushButton4, SIGNAL(clicked()), this, SLOT(bvaDigitsButtons()));
    connect(ui->bvaPushButton5, SIGNAL(clicked()), this, SLOT(bvaDigitsButtons()));
    connect(ui->bvaPushButton6, SIGNAL(clicked()), this, SLOT(bvaDigitsButtons()));
    connect(ui->bvaPushButton7, SIGNAL(clicked()), this, SLOT(bvaDigitsButtons()));
    connect(ui->bvaPushButton8, SIGNAL(clicked()), this, SLOT(bvaDigitsButtons()));
    connect(ui->bvaPushButton9, SIGNAL(clicked()), this, SLOT(bvaDigitsButtons()));
    connect(ui->bvaPushButtonPlusSlashMinus, SIGNAL(clicked()), this, SLOT(bvaOperations()));
    connect(ui->bvaPushButtonPercent, SIGNAL(clicked()), this, SLOT(bvaOperations()));
    connect(ui->bvaPushButtonPlus, SIGNAL(clicked()), this, SLOT(bvaMathOperations()));
    connect(ui->bvaPushButtonMinus, SIGNAL(clicked()), this, SLOT(bvaMathOperations()));
    connect(ui->bvaPushButtonDivide, SIGNAL(clicked()), this, SLOT(bvaMathOperations()));
    connect(ui->bvaPushButtonMultiply, SIGNAL(clicked()), this, SLOT(bvaMathOperations()));

    ui->bvaPushButtonDivide->setCheckable(true);
    ui->bvaPushButtonMultiply->setCheckable(true);
    ui->bvaPushButtonPlus->setCheckable(true);
    ui->bvaPushButtonMinus->setCheckable(true);
}

BVAMainWindow::~BVAMainWindow()
{
    delete ui;
}

void BVAMainWindow::bvaDigitsButtons()
{
    QPushButton *button = (QPushButton*)sender();
    QString allStringNumbers;

    if(ui->bvaLabel->text().contains(".") && button->text() == "0"){
        allStringNumbers = ui->bvaLabel->text() + button->text();
    }
    else{
        allStringNumbers = QString::number((ui->bvaLabel->text() + button->text()).toDouble(), 'g', 12);
    }

    ui->bvaLabel->setText(allStringNumbers);
}

void BVAMainWindow::on_bvaPushButtonDot_clicked()
{
    if(!ui->bvaLabel->text().contains(".")){
        ui->bvaLabel->setText(ui->bvaLabel->text() + ".");
    }
}

void BVAMainWindow::bvaOperations()
{
    QPushButton *button = (QPushButton*)sender();

    double allNumbers = (ui->bvaLabel->text().toDouble());;

    if(button->text() == "+/-"){
        allNumbers *= -1;
    }
    else if(button->text() == "%"){
        allNumbers *= 0.01;
    }

    QString allStringNumbers = QString::number(allNumbers, 'g', 12);
    ui->bvaLabel->setText(allStringNumbers);
}

void BVAMainWindow::bvaMathOperations()
{
    QPushButton *button = (QPushButton*)sender();
    prevNum = ui->bvaLabel->text().toDouble();

    button->setChecked(true);
    ui->bvaLabel->setText("");
}


void BVAMainWindow::on_bvaPushButtonEquailty_clicked()
{
    double currentNum = ui->bvaLabel->text().toDouble();
    QString allStringNumbers;

    if(ui->bvaPushButtonPlus->isChecked()){
        allStringNumbers = QString::number(currentNum + prevNum, 'g', 12);
        ui->bvaPushButtonPlus->setChecked(false);
    }
    else if(ui->bvaPushButtonMinus->isChecked()){
        allStringNumbers = QString::number(prevNum - currentNum, 'g', 12);
        ui->bvaPushButtonMinus->setChecked(false);
    }
    else if(ui->bvaPushButtonDivide->isChecked()){
        allStringNumbers = currentNum == 0 ? "0" : QString::number(prevNum / currentNum, 'g', 12);
        ui->bvaPushButtonDivide->setChecked(false);
    }
    else if(ui->bvaPushButtonMultiply->isChecked()){
        allStringNumbers = QString::number(prevNum * currentNum, 'g', 12);
        ui->bvaPushButtonMultiply->setChecked(false);
    }
    ui->bvaLabel->setText(allStringNumbers);
}


void BVAMainWindow::on_bvaPushButtonAC_clicked()
{
    ui->bvaLabel->setText("0");

    ui->bvaPushButtonPlus->setChecked(false);
    ui->bvaPushButtonMinus->setChecked(false);
    ui->bvaPushButtonDivide->setChecked(false);
    ui->bvaPushButtonMultiply->setChecked(false);
}

