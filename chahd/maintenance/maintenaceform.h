#ifndef MAINTENACEFORM_H
#define MAINTENACEFORM_H

#include <QWidget>
#include "maintenance.h"

QT_BEGIN_NAMESPACE
namespace Ui { class maintenaceform; }
QT_END_NAMESPACE

class maintenaceform : public QWidget
{
    Q_OBJECT

public:
    maintenaceform(QWidget *parent = nullptr);
    ~maintenaceform();

private slots:
    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_res_clicked();

    void on_recherche_clicked();

private:
    Ui::maintenaceform *ui;
    maintenance ma;
};
#endif // MAINTENACEFORM_H
