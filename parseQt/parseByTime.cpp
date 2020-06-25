#include "parseByTime.h"
#include <qmessagebox.h>
#include <vector>
#include <fstream>
#include <thread>
#include <string>
#include <regex>
#include <QApplication>
#include <QProcess>
#include <filesystem>
#include <mutex>
using namespace std;
namespace fs = filesystem;

parseByTime::parseByTime(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.startParse, &QPushButton::clicked, [&]()
	{
		prepareParse();
	});
}

parseByTime::~parseByTime()
{
}
mutex mtx2;
void parse(long unixStart, long unixEnd, vector<string> paths)
{
	for (int a = 0; a < paths.size(); a++)
	{
		string log;
		ifstream doc(paths[a]);
		if (doc.is_open())
		{
			string tempStart;
			string tempEnd;
			int counter = 0;
			while (getline(doc, log))
			{
				counter = 0;
				for (int a = 0; ; a++)
				{
					counter++;
					if (log[a] == ',')
						break;
					tempStart.push_back(log[a]);
				}
				for (int a = counter + 1; ; a++)
				{
					if (log[a] == ',')
						break;
					tempEnd.push_back(log[a]);
				}
				if (unixStart < stol(tempStart) && unixEnd > stol(tempEnd))
				{
					lock_guard<mutex> guard(mtx2);
					ofstream dock;
					dock.open("resultsTime.txt", std::ios::app);
					if (dock.is_open())
					{
						dock << log << endl;
					}
				}
				tempStart.clear();
				tempEnd.clear();
			}
		}
	}
}
void parseByTime::prepareParse()
{
	if (ui.folder->isChecked() || ui.doc->isChecked())
	{
		
		if (ui.Sec1->toPlainText().isEmpty() || ui.min1->toPlainText().isEmpty() || ui.hour1->toPlainText().isEmpty() || ui.day1->toPlainText().isEmpty() || ui.mon1->toPlainText().isEmpty()
			|| ui.year1->toPlainText().isEmpty() || ui.Sec1_2->toPlainText().isEmpty() || ui.min1_2->toPlainText().isEmpty() || ui.hour1_2->toPlainText().isEmpty() || ui.day1_2->toPlainText().isEmpty()
			|| ui.mon1_2->toPlainText().isEmpty() || ui.year1_2->toPlainText().isEmpty())
		{
			QMessageBox::information(this, "Error", "Looks like you did not put time, try again!");
		}

		else
		{
			if (ui.doc->isChecked())
			{
				string temp = ui.path->toPlainText().toStdString();
				string string;
				ifstream path(temp);
				if (!path.is_open())
				{
					QMessageBox::information(this, "Error", "Looks like you put wrong path, try again");
					qApp->quit();
					QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
				}
				else
				{
					ui.results->clear(); 
					vector<long> startTime;
					vector<long> endTime;
					{
						try
						{
							startTime.push_back(stol(ui.Sec1->toPlainText().toStdString()));
							startTime.push_back(stol(ui.min1->toPlainText().toStdString()));
							startTime.push_back(stol(ui.hour1->toPlainText().toStdString()));
							startTime.push_back(stol(ui.day1->toPlainText().toStdString()));
							startTime.push_back(stol(ui.mon1->toPlainText().toStdString()));
							startTime.push_back(stol(ui.year1->toPlainText().toStdString()));

							endTime.push_back(stol(ui.Sec1_2->toPlainText().toStdString()));
							endTime.push_back(stol(ui.min1_2->toPlainText().toStdString()));
							endTime.push_back(stol(ui.hour1_2->toPlainText().toStdString()));
							endTime.push_back(stol(ui.day1_2->toPlainText().toStdString()));
							endTime.push_back(stol(ui.mon1_2->toPlainText().toStdString()));
							endTime.push_back(stol(ui.year1_2->toPlainText().toStdString()));
						}
						catch (const std::exception&)
						{
							QMessageBox::information(this, "Error", "Ooops, lol");
							qApp->quit();
							QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
						}

					}
					long unixStart = ((startTime[5] - 1970) * 31536000 + startTime[4] * 2678400 + startTime[3] * 86400 + startTime[2] * 3600 + startTime[1] * 60 + startTime[0]);
					long unixEnd = ((endTime[5] - 1970) * 31536000 + endTime[4] * 2678400 + endTime[3] * 86400 + endTime[2] * 3600 + endTime[1] * 60 + endTime[0]);
					if (startTime[0] < 0 || startTime[1] < 0 || startTime[2] < 0 || startTime[3] < 0 || startTime[4] < 0 || startTime[5] < 1970 ||
						endTime[0] < 0 || endTime[1] < 0 || endTime[2] < 0 || endTime[3] < 0 || endTime[4] < 0 || endTime[5] < 1970 ||
						startTime[0] > 59 || startTime[1] > 59 || startTime[2] > 23 || startTime[3] > 31 || startTime[4] > 12 || startTime[5] > 2100 ||
						endTime[0] > 59 || endTime[1] > 59 || endTime[2] > 23 || endTime[3] > 31 || endTime[4] > 12 || endTime[5] > 2100)
					{
						QMessageBox::information(this, "Error", "Looks like you put wrong time");
						qApp->quit();
						QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
					}
					if (unixStart > unixEnd)
					{
						QMessageBox::information(this, "Error", "Are you sure that start time bigger than end time?");
						qApp->quit();
						QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
					}
					std::string path = ui.path->toPlainText().toStdString();
					ifstream doc(path);
					std::string log;
					std::string startTemp;
					std::string endTemp;
					int counter = 0;
					if (doc.is_open())
					{
						while (getline(doc, log))
						{
							counter = 0;
							for (int a = 0; ; a++)
							{
								counter++;
								if (log[a] == ',')
									break;
								startTemp.push_back(log[a]);
							}
							for (int a = counter + 1; ; a++)
							{
								if (log[a] == ',')
									break;
								endTemp.push_back(log[a]);
							}
							if (unixStart < stol(startTemp) && unixEnd > stol(endTemp))
							{
								ui.results->append(QString::fromStdString(log));
								if (ui.saveText->isChecked())
								{
									ofstream dock;
									dock.open("resultsTime.txt", std::ios::app);
									if (dock.is_open())
									{
										dock << log << endl;
									}
								}
							}
							startTemp.clear();
							endTemp.clear();
						}
					}
				}
				if (ui.results->toPlainText().isEmpty())
				{
					QMessageBox::information(this, "Error", "Logs were not found");
				}
			}
			if (ui.folder->isChecked())
			{
				{
					ui.results->clear();
					vector<long> startTime;
					vector<long> endTime;
					try
					{
						startTime.push_back(stol(ui.Sec1->toPlainText().toStdString()));
						startTime.push_back(stol(ui.min1->toPlainText().toStdString()));
						startTime.push_back(stol(ui.hour1->toPlainText().toStdString()));
						startTime.push_back(stol(ui.day1->toPlainText().toStdString()));
						startTime.push_back(stol(ui.mon1->toPlainText().toStdString()));
						startTime.push_back(stol(ui.year1->toPlainText().toStdString()));

						endTime.push_back(stol(ui.Sec1_2->toPlainText().toStdString()));
						endTime.push_back(stol(ui.min1_2->toPlainText().toStdString()));
						endTime.push_back(stol(ui.hour1_2->toPlainText().toStdString()));
						endTime.push_back(stol(ui.day1_2->toPlainText().toStdString()));
						endTime.push_back(stol(ui.mon1_2->toPlainText().toStdString()));
						endTime.push_back(stol(ui.year1_2->toPlainText().toStdString()));
					}
					catch (const std::exception&)
					{
						QMessageBox::information(this, "Error", "Ooops, lol");
						qApp->quit();
						QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
					}
					long unixStart = ((startTime[5] - 1970) * 31536000 + startTime[4] * 2678400 + startTime[3] * 86400 + startTime[2] * 3600 + startTime[1] * 60 + startTime[0]);
					long unixEnd = ((endTime[5] - 1970) * 31536000 + endTime[4] * 2678400 + endTime[3] * 86400 + endTime[2] * 3600 + endTime[1] * 60 + endTime[0]);
					if (startTime[0] < 0 || startTime[1] < 0 || startTime[2] < 0 || startTime[3] < 0 || startTime[4] < 0 || startTime[5] < 1970 ||
						endTime[0] < 0 || endTime[1] < 0 || endTime[2] < 0 || endTime[3] < 0 || endTime[4] < 0 || endTime[5] < 1970 ||
						startTime[0] > 59 || startTime[1] > 59 || startTime[2] > 23 || startTime[3] > 31 || startTime[4] > 12 || startTime[5] > 2100 ||
						endTime[0] > 59 || endTime[1] > 59 || endTime[2] > 23 || endTime[3] > 31 || endTime[4] > 12 || endTime[5] > 2100)
					{
						QMessageBox::information(this, "Error", "Looks like you put wrong time");
						qApp->quit();
						QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
					}
					if (unixStart > unixEnd)
					{
						QMessageBox::information(this, "Error", "Are you sure that start time bigger than end time?");
						qApp->quit();
						QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
					}
					vector<std::string> allLogs;
					int counter = 0;
					std::string path = ui.path->toPlainText().toStdString();
					for (auto& p : fs::directory_iterator(path))
					{
						counter++;
						allLogs.push_back(p.path().string());
					}
					vector<std::string> firstT;
					vector<std::string> secondT;
					vector<std::string> thirdT;
					vector<std::string> fourthT;
					if (allLogs.size() == 1)
					{
						for (int a = 0; a < counter; a++)
						{
							firstT.push_back(allLogs[a]);
						}
						std::thread first(parse, unixStart, unixEnd, firstT);
						first.join();
						fstream doc("resultsTime.txt");
						std::string log;
						if (doc.is_open())
						{
							while (getline(doc, log))
							{
								ui.results->append(QString::fromStdString(log));
							}
						}
						doc.close();
						if (ui.saveText->isChecked())
						{

						}
						else
						{
							remove("resultsTime.txt");
						}
					}
					else if (allLogs.size() == 2)
					{
						counter /= 2;
						for (int a = 0; a < counter; a++)
							firstT.push_back(allLogs[a]);
						for (int a = counter; a < allLogs.size(); a++)
							secondT.push_back(allLogs[a]);
						std::thread first(parse, unixStart, unixEnd, firstT);
						std::thread second(parse, unixStart, unixEnd, secondT);
						first.join();
						second.join();
						fstream doc("resultsTime.txt");
						std::string log;
						if (doc.is_open())
						{
							while (getline(doc, log))
							{
								ui.results->append(QString::fromStdString(log));
							}
						}
						doc.close();
						if (ui.saveText->isChecked())
						{

						}
						else
						{
							remove("resultsTime.txt");
						}
					}
					else if (allLogs.size() == 3)
					{
						counter /= 3;
						for (int a = 0; a < counter; a++)
							firstT.push_back(allLogs[a]);
						for (int a = counter; a < counter * 2; a++)
							secondT.push_back(allLogs[a]);
						for (int a = counter * 2; a < allLogs.size(); a++)
							thirdT.push_back(allLogs[a]);
						std::thread first(parse, unixStart, unixEnd, firstT);
						std::thread second(parse, unixStart, unixEnd, secondT);
						std::thread third(parse, unixStart, unixEnd, thirdT);
						first.join();
						second.join();
						third.join();
						fstream doc("resultsTime.txt");
						std::string log;
						if (doc.is_open())
						{
							while (getline(doc, log))
							{
								ui.results->append(QString::fromStdString(log));
							}
						}
						doc.close();
						if (ui.saveText->isChecked())
						{

						}
						else
						{
							remove("resultsTime.txt");
						}
					}
					else
					{
						counter /= 4;
						for (int a = 0; a < counter; a++)
							firstT.push_back(allLogs[a]);
						for (int a = counter; a < counter * 2; a++)
							secondT.push_back(allLogs[a]);
						for (int a = counter * 2; a < counter * 3; a++)
							thirdT.push_back(allLogs[a]);
						for (int a = counter * 3; a < allLogs.size(); a++)
							fourthT.push_back(allLogs[a]);
						std::thread first(parse, unixStart, unixEnd, firstT);
						std::thread second(parse, unixStart, unixEnd, secondT);
						std::thread third(parse, unixStart, unixEnd, thirdT);
						std::thread fourth(parse, unixStart, unixEnd, fourthT);
						first.join();
						second.join();
						third.join();
						fourth.join();
						fstream doc("resultsTime.txt");
						std::string log;
						if (doc.is_open())
						{
							while (getline(doc, log))
							{
								ui.results->append(QString::fromStdString(log));
							}
						}
						doc.close();
						if (ui.saveText->isChecked())
						{

						}
						else
						{
							remove("resultsTime.txt");
						}
					}
				}
			}
		}
	}
	else
	{
		QMessageBox::information(this, "Error", "Looks like you did not push button, try again!");
	}
}
