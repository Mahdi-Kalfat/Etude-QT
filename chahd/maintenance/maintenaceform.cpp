#include "maintenaceform.h"
#include "ui_maintenaceform.h"

maintenaceform::maintenaceform(QWidget *parent):
    QWidget(parent),
        ui(new Ui::maintenaceform)
{
    ui->setupUi(this);
    ui->id->setPlaceholderText("Donner l'identifiant");
    ui->description->setPlaceholderText("Donner La description");
    ui->cout->setPlaceholderText("Donner le cout");
    ui->degre->setPlaceholderText("Donner le degre");
    ui->dell->setPlaceholderText("Donner l'id a supprimer");
    ui->lineEdit_recherche->setPlaceholderText("Donner ce que vous cherchez");


    QRegularExpression description("[A-Za-z1-9]*");
    QValidator* validator_description = new QRegularExpressionValidator(description, this);
    ui->description->setValidator(validator_description);

    ui->id->setValidator(new QIntValidator(9, 99999, this));
    ui->cout->setValidator(new QIntValidator(9, 99999, this));
    ui->degre->setValidator(new QIntValidator(9, 99, this));


    ui->tableView->setModel(ma.afficher());
}

maintenaceform::~maintenaceform()
{
    delete ui;
}


void maintenaceform::on_ajouter_clicked()
{
    int id=ui->id->text().toInt();
    QString datee=ui->dateEdit->text();
    QString des=ui->description->text();
    int cout=ui->cout->text().toInt();
    int degre=ui->degre->text().toInt();


      ui->id->setText("");
      ui->description->setText("");
      ui->cout->setText("");
      ui->degre->setText("");

    maintenance ma(id,datee,des,cout,degre);
    ma.Ajouter();
    ui->tableView->setModel(ma.afficher());

}

void maintenaceform::on_modifier_clicked()
{
    int id=ui->id->text().toInt();
    QString datee=ui->dateEdit->text();
    QString des=ui->description->text();
    int cout=ui->cout->text().toInt();
    int degre=ui->degre->text().toInt();


      ui->id->setText("");
      ui->description->setText("");
      ui->cout->setText("");
      ui->degre->setText("");



    maintenance ma(id,datee,des,cout,degre);
    ma.modifier();
    ui->tableView->setModel(ma.afficher());

}

void maintenaceform::on_pushButton_4_clicked()
{
    maintenance maS;
    maS.setid(ui->dell->text().toInt());
    maS.Supprime(maS.getid());
    ui->tableView->setModel(maS.afficher());
    ui->dell->setText("");
}

void maintenaceform::on_pushButton_3_clicked()
{
    ui->tableView->setModel(ma.afficher());
}

void maintenaceform::on_res_clicked()
{
    ma.reset();
    ui->tableView->setModel(ma.afficher());
}

void maintenaceform::on_recherche_clicked()
{
    QString val=ui->lineEdit_recherche->text();
    QString option=ui->check_rech->currentText();
    if((val!="")&&(option=="​🔍  Identifiant"))
{        ui->tableView->setModel(ma.afficher_id(val));}
    else if((val!="")&&(option=="​🔍​ Cout"))
    {
         ui->tableView->setModel(ma.afficher_cout(val));
    }
    else if((val!="")&&(option=="​🔍​ Degre"))
    {
         ui->tableView->setModel(ma.afficher_degre(val));
    }
    ui->lineEdit_recherche->setText("");
}
