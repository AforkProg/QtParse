#include "parseByName.h"
#include <qmessagebox.h>
#include <string>
#include <fstream>
#include <regex>
#include <filesystem>
#include <thread>
#include <mutex>
#include <qprocess.h>
using namespace std;
namespace fs = filesystem;
parseByName::parseByName(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.start, &QPushButton::clicked, [&]()
	{
		prepareParse();
	});
}

parseByName::~parseByName()
{
}
mutex mtx;
void parse(string name, vector<string> paths)
{
	for (int a = 0; a < paths.size(); a++)
	{
		string log;
		ifstream doc(paths[a]);
		if (doc.is_open())
		{
			while (getline(doc, log))
			{
				cmatch result;
				regex regular("([\\d]+)""(,)""([\\d]+)""(,)""([\\d]+)""(,)" + name);
				if (regex_search(log.c_str(), result, regular))
				{
					lock_guard<mutex> guard(mtx);
					ofstream dock;
					dock.open("resultsName.txt", std::ios::app);
					if (dock.is_open())
					{
						dock << log << endl;
					}
				}
			}
		}
	}
}

void parseByName::prepareParse()
{
	ui.results->clear();
	if (ui.doc->isChecked() || ui.folder->isChecked())
	{
		if (ui.path->toPlainText().isEmpty() || ui.name->toPlainText().isEmpty())
		{
			QMessageBox::information(this, "Error", "Looks like you did not put name or path, try again!");
		}
		else
		{
			std::string name = ui.name->toPlainText().toStdString();
			if (ui.doc->isChecked())
			{
				string path = ui.path->toPlainText().toStdString();
				ifstream doc(path);
				string log;
				if (doc.is_open())
				{
					while (getline(doc, log))
					{
						cmatch result;
						regex regular("([\\d]+)""(,)""([\\d]+)""(,)""([\\d]+)""(,)" + name);
						if (regex_search(log.c_str(), result, regular))
						{
							ui.results->append(QString::fromStdString(log));
							if (ui.saveText->isChecked())
							{
								ofstream dock;
								dock.open("resultsName.txt", std::ios::app);
								if (dock.is_open())
								{
									dock << log << endl;
								}
							}
						}
					}
					if (ui.results->toPlainText().isEmpty())
						QMessageBox::information(this, "Error", "Logs were not found");
				}
				else
					QMessageBox::information(this, "Error", "Looks like you did not push wrong path, try again!");
			}
			if (ui.folder->isChecked())
			{
				vector<string> allLogs;
				int counter = 0;
				string name = ui.name->toPlainText().toStdString();
				string path = ui.path->toPlainText().toStdString();
				try
				{
					for (auto& p : fs::directory_iterator(path))
					{
						counter++;
						allLogs.push_back(p.path().string());
					}
				}
				catch (const std::exception&)
				{
					QMessageBox::information(this, "Error", "Ooops, lol");
					qApp->quit();
					QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
				}
				vector<string> firstThread;
				vector<string> secondThread;
				vector<string> thirdThread;
				vector<string> fourthThread;
				if (allLogs.size() == 1)
				{
					for (int a = 0; a < counter; a++)
					{
						firstThread.push_back(allLogs[a]);
					}
					ofstream dock("resultsName.txt");
					std::thread first(parse, name, firstThread);
					first.join();
					fstream doc("resultsName.txt");
					string log;
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
						remove("resultName.txt");
					}
				}
				else if (allLogs.size() == 2)
				{
					counter /= 2;
					for (int a = 0; a < counter; a++)
					{
						firstThread.push_back(allLogs[a]);
					}
					for (int a = counter; a < 2 * counter; a++)
					{
						secondThread.push_back(allLogs[a]);
					}
					ofstream dock("resultsName.txt");
					std::thread first(parse, name, firstThread);
					std::thread second(parse, name, secondThread);
					first.join();
					second.join();
					fstream doc("resultsName.txt");
					string log;
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
						remove("resultsName.txt");
					}
				}
				else if (allLogs.size() == 3)
				{
					counter /= 3;
					for (int a = 0; a < counter; a++)
					{
						firstThread.push_back(allLogs[a]);
					}
					for (int a = counter; a < 2 * counter; a++)
					{
						secondThread.push_back(allLogs[a]);
					}
					for (int a = counter * 2; a < 3 * counter; a++)
					{
						thirdThread.push_back(allLogs[a]);
					}
				
					ofstream dock("resultsName.txt");
					std::thread first(parse, name, firstThread);
					std::thread second(parse, name, secondThread);
					std::thread third(parse, name, thirdThread);
					first.join();
					second.join();
					third.join();
					fstream doc("resultsName.txt");
					string log;
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
						remove("resultsName.txt");
					}
				}
				else
				{
					counter /= 4;
					for (int a = 0; a < counter; a++)
					{
						firstThread.push_back(allLogs[a]);
					}
					for (int a = counter; a < 2 * counter; a++)
					{
						secondThread.push_back(allLogs[a]);
					}
					for (int a = counter * 2; a < 3 * counter; a++)
					{
						thirdThread.push_back(allLogs[a]);
					}
					for (int a = counter * 3; a < allLogs.size(); a++)
					{
						fourthThread.push_back(allLogs[a]);
					}
					ofstream dock("resultsName.txt");
					std::thread first(parse, name, firstThread);
					std::thread second(parse, name, secondThread);
					std::thread third(parse, name, thirdThread);
					std::thread fourth(parse, name, fourthThread);
					first.join();
					second.join();
					third.join();
					fourth.join();
					fstream doc("resultsName.txt");
					string log;
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
						remove("resultsName.txt");
					}
				}
				if (ui.results->toPlainText().isEmpty())
				{
					QMessageBox::information(this, "Error", "Logs were not found");
				}
			}
		}
	}
	else
	{
		QMessageBox::information(this, "Error", "Looks like you did not push button, try again!");
	}
}
