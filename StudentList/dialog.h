#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include "student.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog, protected Student
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    Student newMember;
    Ui::Dialog *ui;
signals:
    void signalAdded(int isAded);
public slots:
    void on_addMember_clicked();
    void slotAdded();

private:
};

#endif // DIALOG_H
