#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::GameWindow)
{
	ui->setupUi(this);
	hudBar = ui->hudLayout;
	gameGrid = ui->mainGridLayout;

	connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(quit()));
	connect(ui->actionMain_Menu, SIGNAL(triggered()), this, SLOT(mainMenu()));
}

GameWindow::~GameWindow()
{
	this->close();
}

void GameWindow::quit()
{
	openMainMenu();
	this->close();
}

void GameWindow::mainMenu()
{
	emit(openMainMenu());
}
