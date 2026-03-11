#ifndef STONEEDIT_H
#define STONEEDIT_H

#include <QDialog>

namespace Ui {
class StoneEdit;
}

class StoneEdit : public QDialog
{
    Q_OBJECT

public:
    explicit StoneEdit(QWidget *parent = nullptr);
    ~StoneEdit();
    void setStoneType(QString name);
    QString getStoneType();
    void setHardness(QString hardness);
    QString getHardness();
    void setCarats(QString carats);
    QString getCarats();
    void setCost(QString cost);
    QString getCost();
    void setInput4(QString input4);
    QString getInput4();
    void setInput5(QString input5);
    QString getInput5();

private:
    Ui::StoneEdit *ui;
    void UpdateLabels(QString text);
};

#endif // STONEEDIT_H
