#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnAstroid, &QPushButton::clicked, this, &MainWindow::onBtnAstroidClicked);
    connect(ui->btnCycloid, &QPushButton::clicked, this, &MainWindow::onBtnCycloidClicked);
    connect(ui->btnHuygens, &QPushButton::clicked, this, &MainWindow::onBtnHuygensClicked);
    connect(ui->btnHypo, &QPushButton::clicked, this, &MainWindow::onBtnHypoClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onBtnAstroidClicked()
{
    // Change the background color
    this->ui->renderArea->setShape(RenderArea::Astroid);
    //this->ui->renderArea->setBackgroundColor(QColorConstants::Red);
}


void MainWindow::onBtnCycloidClicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    //this->ui->renderArea->setBackgroundColor(QColorConstants::Green);
}


void MainWindow::onBtnHuygensClicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    //this->ui->renderArea->setBackgroundColor(QColorConstants::Blue);
}


void MainWindow::onBtnHypoClicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    //this->ui->renderArea->setBackgroundColor(QColorConstants::Yellow);
}

