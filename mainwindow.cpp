#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

enum StoneRoles {
    TypeRole = Qt::UserRole + 1,
    HardnessRole,
    CaratsRole,
    CostRole,
    Input4Role,
    Input5Role
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isValidInput(StoneEdit& dialog) {
    bool okH, okC, okW;
    double h = dialog.getHardness().toDouble(&okH);
    double c = dialog.getCost().toDouble(&okC);
    double w = dialog.getCarats().toDouble(&okW);

    if (!okH || !okC || !okW || h <= 0 || c <= 0 || w <= 0) {
        return false;
    }
    return true;
}

void MainWindow::updateSummary()
{
    ui->label->setText(QString("Count: %1 | Karats: %2 kr | Cost: %3 $")
                           .arg(ui->list->count())
                           .arg(necklace.GetTotalWeight())
                           .arg(necklace.GetTotalCost()));
}

Rarity stringToRarity(QString str) {
    if (str == "Low") return Rarity::LOW;
    if (str == "Medium") return Rarity::MEDIUM;
    if (str == "High") return Rarity::HIGH;
    return Rarity::VERY_HIGH;
}

Transparensy stringToTransparensy(QString str) {
    if (str == "Transparent") return Transparensy::TRANSPARENT;
    if (str == "Opaque") return Transparensy::OPAQUE;
    return Transparensy::TRANSLUCENT;
}

void MainWindow::on_addButton_clicked() {
    StoneEdit dialog(this);
    if(dialog.exec() == QDialog::Accepted) {
        if (!isValidInput(dialog)) {
            QMessageBox::warning(this, "Error", "Please, enter the correct values!");
            return;
        }
        double hardness = dialog.getHardness().toDouble();
        double cost     = dialog.getCost().toDouble();
        double carats   = dialog.getCarats().toDouble();

        QString stoneType = dialog.getStoneType();
        std::shared_ptr<AbstractStone> stone = nullptr;

        if (stoneType == "Ruby") {
            stone = StoneFactory::CreateRuby(
                hardness,
                cost,
                carats,
                stringToRarity(dialog.getInput4()),
                dialog.getInput5().toStdString()
                );
        }
        else if (stoneType == "Sapphire") {
            stone = StoneFactory::CreateSapphire(
                hardness,
                cost,
                carats,
                stringToRarity(dialog.getInput4()),
                dialog.getInput5().toStdString()
                );
        }
        else if (stoneType == "Amethyst") {
            stone = StoneFactory::CreateAmethyst(
                hardness,
                cost,
                carats,
                stringToTransparensy(dialog.getInput4()),
                dialog.getInput5().toStdString()
                );
        }

        if (stone) {
            necklace.AddStone(stone);
            QListWidgetItem* item = new QListWidgetItem(ui->list);
            item->setData(TypeRole, stoneType);
            item->setData(HardnessRole, dialog.getHardness());
            item->setData(CaratsRole, dialog.getCarats());
            item->setData(CostRole, dialog.getCost());
            item->setData(Input4Role, dialog.getInput4());
            item->setData(Input5Role, dialog.getInput5());

            item->setText(QString("%1-%2kr-%3$/kr")
                              .arg(stoneType)
                              .arg(carats)
                              .arg(cost));

            updateSummary();
        }
    }
}

void MainWindow::on_deleteButton_clicked()
{
    int currentRow = ui->list->currentRow();

    if (currentRow != -1) {
        necklace.RemoveStoneAt(currentRow);

        delete ui->list->takeItem(currentRow);

        updateSummary();
    }
}

void MainWindow::on_editButton_clicked()
{
    int currentRow = ui->list->currentRow();
    QListWidgetItem* item = ui->list->currentItem();
    if(!item || currentRow == -1) return;

    StoneEdit dialog(this);
    dialog.setStoneType(item->data(TypeRole).toString());
    dialog.setHardness(item->data(HardnessRole).toString());
    dialog.setCarats(item->data(CaratsRole).toString());
    dialog.setCost(item->data(CostRole).toString());
    dialog.setInput4(item->data(Input4Role).toString());
    dialog.setInput5(item->data(Input5Role).toString());

    if(dialog.exec() == QDialog::Accepted)
    {
        if (!isValidInput(dialog)) {
            QMessageBox::warning(this, "Error", "Changes didn't saved:Incorrect values");
            return;
        }
        double hardness = dialog.getHardness().toDouble();
        double cost     = dialog.getCost().toDouble();
        double carats   = dialog.getCarats().toDouble();
        QString type    = dialog.getStoneType();

        std::shared_ptr<AbstractStone> newStone = nullptr;

        if (type == "Ruby") {
            newStone = StoneFactory::CreateRuby(
                hardness, cost, carats,
                stringToRarity(dialog.getInput4()),
                dialog.getInput5().toStdString()
                );
        }
        else if (type == "Sapphire") {
            newStone = StoneFactory::CreateSapphire(
                hardness, cost, carats,
                stringToRarity(dialog.getInput4()),
                dialog.getInput5().toStdString()
                );
        }
        else if (type == "Amethyst") {
            newStone = StoneFactory::CreateAmethyst(
                hardness, cost, carats,
                stringToTransparensy(dialog.getInput4()),
                dialog.getInput5().toStdString()
                );
        }

        if (newStone) {
            necklace.ReplaceStoneAt(currentRow, newStone);

            item->setData(TypeRole, type);
            item->setData(HardnessRole, dialog.getHardness());
            item->setData(CaratsRole, dialog.getCarats());
            item->setData(CostRole, dialog.getCost());
            item->setData(Input4Role, dialog.getInput4());
            item->setData(Input5Role, dialog.getInput5());

            item->setText(QString("%1-%2kr-%3$/kr")
                              .arg(type)
                              .arg(carats)
                              .arg(cost));

            updateSummary();
        }
    }
}