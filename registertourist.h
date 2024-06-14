#ifndef REGISTERTOURIST_H
#define REGISTERTOURIST_H

#include <QDialog>

namespace Ui {
class RegisterTourist;
}

class RegisterTourist : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterTourist(QWidget *parent = nullptr);
    ~RegisterTourist();

private:
    Ui::RegisterTourist *ui;
};

#endif // REGISTERTOURIST_H
