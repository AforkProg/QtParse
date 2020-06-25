#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_parseQt.h"
#include "parseByName.h"
#include "parseByTime.h"
class parseQt : public QMainWindow
{
    Q_OBJECT

public:
    parseQt(QWidget *parent = Q_NULLPTR);

private:
    Ui::parseQtClass ui;
	parseByName nameWindow;
	parseByTime timeWindow;
	void pushTime();
	void pushName();
};
