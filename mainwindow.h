#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

#include <gamewindow.h>
#include <quickbattle.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

private slots:
	void quit();
	void gamelistPressed();
	void startQuickBattle();
	void openMainMenu();

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	//main menu stiff
	QPushButton *gamelistButton;
	Ui::MainWindow *ui;

	//gamelist stuff
	QVBoxLayout *gameListLayout;

	QPushButton *battleButton;

	//game stuff
	GameWindow *currGame;
};
#endif // MAINWINDOW_H
