#include "parseQt.h"

parseQt::parseQt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	connect(ui.nameButton, &QPushButton::clicked, [&]()
	{
		pushName();
	});
	connect(ui.timeButton, &QPushButton::clicked, [&]()
	{
		pushTime();
	});
}

void parseQt::pushTime()
{
	timeWindow.show();
	
}

void parseQt::pushName()
{
	nameWindow.show();
}
