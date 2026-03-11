#include <QDoubleValidator>
#include "stoneedit.h"
#include "ui_stoneedit.h"

void StoneEdit::UpdateLabels(QString text){
    if (text=="Ruby"){
        ui->label4->setText("Rarity Level");
        ui->input4->clear();
        ui->input4->addItems({"Low","Medium","High","Very High"});
        ui->label5->setText("Flourescence");
    }else if (text=="Amethyst"){
        ui->label4->setText("Transparensy Level");
        ui->input4->clear();
        ui->input4->addItems({"Transparent","Opaque","Translucent"});
        ui->label5->setText("Shade");
    }else if (text=="Sapphire"){
        ui->label4->setText("Rarity Level");
        ui->input4->clear();
        ui->input4->addItems({"Low","Medium","High","Very High"});
        ui->label5->setText("Shade");
    }
}

StoneEdit::StoneEdit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StoneEdit)
{
    ui->setupUi(this);
    QDoubleValidator* validator = new QDoubleValidator(0.01, 1000000.0, 2, this);
    validator->setNotation(QDoubleValidator::StandardNotation);
    ui->input1->setValidator(validator);
    ui->input2->setValidator(validator);
    ui->input3->setValidator(validator);
    ui->input->addItems({"Ruby","Amethyst","Sapphire"});
    UpdateLabels(ui->input->currentText());
    connect(ui->input, &QComboBox::currentTextChanged,this,[=](const QString &text){
        UpdateLabels(text);
    });

}

StoneEdit::~StoneEdit()
{
    delete ui;
}

void StoneEdit::setStoneType(QString name)
{
    ui->input->setCurrentText(name);
}

QString StoneEdit::getStoneType()
{
    return ui->input->currentText();
}

void StoneEdit::setHardness(QString hardness)
{
    ui->input1->setText(hardness);
}

QString StoneEdit::getHardness()
{
    return ui->input1->text();
}

void StoneEdit::setCarats(QString carats)
{
    ui->input2->setText(carats);
}

QString StoneEdit::getCarats()
{
    return ui->input2->text();
}

void StoneEdit::setCost(QString cost)
{
    ui->input3->setText(cost);
}

QString StoneEdit::getCost()
{
    return ui->input3->text();
}

void StoneEdit::setInput4(QString input4)
{
    ui->input4->setCurrentText(input4);
}

QString StoneEdit::getInput4()
{
    return ui->input4->currentText();
}

void StoneEdit::setInput5(QString input5)
{
    ui->input5->setText(input5);
}

QString StoneEdit::getInput5()
{
    return ui->input5->text();
}