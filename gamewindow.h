#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

///these are for the GUI
/// might need to make custom classes for them later
#include <QHBoxLayout>
#include <QGridLayout>

#include "sprite.qml"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
	Q_OBJECT

signals:
	void openMainMenu();

private slots:
	void quit();
	void mainMenu();

public:
	GameWindow(QWidget *parent = 0);
	~GameWindow();

private:
	QHBoxLayout *hudBar;
	QGridLayout *gameGrid;
	Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
