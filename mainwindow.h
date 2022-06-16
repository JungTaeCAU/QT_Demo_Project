#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



    void InsertFlagItem(const QString &, const QString &);

    void insertNewIncludeDirectory(const QString &);

    void addSource(const QString &);

    void addSource(const QString &target, const QString &sources);

    void PrepareCMakeListsVariables();

private slots:
    void on_actionExport_triggered();

    void on_flagsAddBtn_clicked();

    void on_flagsRemoveBtn_clicked();

    void on_addIncludeBtn_clicked();

    void on_includeList_itemChanged(QListWidgetItem *item);

    void on_addSourceBtn_clicked();

    void on_removeSourceBtn_clicked();

    void currentTabChanged(int index);

private:
    Ui::MainWindow *ui;
    QString cmakeListsResult;
};
#endif // MAINWINDOW_H
