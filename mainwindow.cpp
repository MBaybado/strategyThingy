#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
	QMainWindow(parent),
	gamelistButton(new QPushButton),
	ui(new Ui::MainWindow),
	gameListLayout(new QVBoxLayout),
	battleButton(new QPushButton)
{
	ui->setupUi(this);

	//SETUP MAIN MENU
	gamelistButton->setText("Games");
	ui->mainLayout->addWidget(gamelistButton);

	ui->mainLayout->addLayout(gameListLayout);

	connect(gamelistButton, SIGNAL(pressed()), this, SLOT(gamelistPressed()));
	connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(quit()));

	//SETUP GAMELIST MENU
	battleButton->setText("Battle thing");
	battleButton->setVisible(false);

	gameListLayout->addWidget(battleButton);
	gameListLayout->setEnabled(false);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::quit()
{
	this->close();
}

void MainWindow::gamelistPressed()
{
	//turn off main menu
	gamelistButton->setVisible(false);

	//turn on gamelist menu
	gameListLayout->setEnabled(true);
	battleButton->setVisible(true);
	battleButton->setEnabled(true);

	connect(battleButton, SIGNAL(pressed()), this, SLOT(startQuickBattle()));
}

void MainWindow::startQuickBattle()
{
	//HAHA POLYMORPHISM!!!!
	currGame = new quickBattle();
	currGame->show();
	connect(currGame, SIGNAL(openMainMenu()), this, SLOT(openMainMenu()));
	this->hide();
}

void MainWindow::openMainMenu()
{
	this->show();
}
