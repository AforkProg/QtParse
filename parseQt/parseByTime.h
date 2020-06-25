#pragma once

#include <QWidget>
#include "ui_parseByTime.h"
#include <vector>
#include <string>
#include <cstdio>
#include "qthread.h"
#include "qmutex.h"
class parseByTime : public QWidget
{
	Q_OBJECT

public:
	parseByTime(QWidget *parent = Q_NULLPTR);
	~parseByTime();


private:
	Ui::parseByTime ui;
	void prepareParse();
};
