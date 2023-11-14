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
    connect(ui->btnLine, &QPushButton::clicked, this, &MainWindow::onBtnLineClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onBtnAstroidClicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
}


void MainWindow::onBtnCycloidClicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
}


void MainWindow::onBtnHuygensClicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
}

void MainWindow::onBtnHypoClicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
}

void MainWindow::onBtnLineClicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);
}
