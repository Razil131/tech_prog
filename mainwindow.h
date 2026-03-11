#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stoneedit.h"
#include "Necklace.hpp"
#include "StoneFactory.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    Rarity stringToRarity(QString str);

    Transparensy stringToTransparensy(QString str);

    bool isValidInput(StoneEdit& dialog);

private slots:
    void updateSummary();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_editButton_clicked();
private:
    Ui::MainWindow *ui;
    Necklace necklace;
};
#endif
