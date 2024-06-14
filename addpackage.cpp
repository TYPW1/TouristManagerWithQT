#include "addpackage.h"
#include "ui_addpackage.h"

static QString dbPath = QDir::currentPath() + "/Database/MyTouristManager.db"; // Static variable for the database path

AddPackage::AddPackage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPackage)
{
    ui->setupUi(this);

    // Ensure the slot is connected only once
    static bool isConnected = false;
    if (!isConnected) {
        connect(ui->btnSave, &QPushButton::clicked, this, &AddPackage::on_btnSave_clicked);
        qDebug() << "Slot connected";
        isConnected = true;
    }
}

AddPackage::~AddPackage()
{
    delete ui;
}

void AddPackage::on_btnSave_clicked()
{
    QString packageName = ui->txtPackageName->text();
    QString packageDescription = ui->txtDescription->toPlainText();
    QString amount = ui->txtAmount->text();

    qDebug() << "Package Name : " << packageName << " Package Description : " << packageDescription << " Amount : " << amount;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(dbPath);

    if (QFile::exists(dbPath)) {
        qDebug() << "Database file exists";
    } else {
        qDebug() << "Database file doesn't exist";
        return;
    }

    if (!database.open()) {
        qDebug() << "Error: Unable to open Database";
        return;
    } else {
        qDebug() << "Database opened successfully";
    }

    QSqlQuery query(database);
    query.prepare("INSERT INTO package (PackageName, PackageDescription, Amount) VALUES (:packageName, :packageDescription, :amount)");
    query.bindValue(":packageName", packageName);
    query.bindValue(":packageDescription", packageDescription);
    query.bindValue(":amount", amount);

    if (!query.exec()) {
        qDebug() << "Insert error: " << query.lastError().text();
    } else {
        qDebug() << "Package inserted successfully";
    }

    database.close();
}
