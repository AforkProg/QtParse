#pragma once

#include <QWidget>
#include "ui_parseByName.h"
#include <vector>
#include <string>
using namespace std;

class parseByName : public QWidget
{
	Q_OBJECT

public:
	parseByName(QWidget *parent = Q_NULLPTR);
	~parseByName();

private:
	Ui::parseByName ui;
	void prepareParse();
};
