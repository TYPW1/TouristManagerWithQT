#include "findtourist.h"
#include "ui_findtourist.h"

FindTourist::FindTourist(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindTourist)
{
    ui->setupUi(this);
}

FindTourist::~FindTourist()
{
    delete ui;
}
