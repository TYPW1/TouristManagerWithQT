#ifndef FINDTOURIST_H
#define FINDTOURIST_H

#include <QDialog>

namespace Ui {
class FindTourist;
}

class FindTourist : public QDialog
{
    Q_OBJECT

public:
    explicit FindTourist(QWidget *parent = nullptr);
    ~FindTourist();

private:
    Ui::FindTourist *ui;
};

#endif // FINDTOURIST_H
