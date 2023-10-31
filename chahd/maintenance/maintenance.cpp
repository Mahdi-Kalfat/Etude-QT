#include "maintenance.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>

maintenance::maintenance()
{
    id= 0;
    datee="";
    des="";
    cout=0;
    degre=0;
}
maintenance::maintenance(int id,QString datee,QString des,int cout,int degre)
{
    this->id=id;
    this-> datee= datee;
    this->des= des;
    this->cout=cout;
    this->degre=degre;
}

int maintenance::getid(){
    return id;
}
void maintenance::setid(int id){
    this->id=id;
}

bool maintenance::Ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString cout_string=QString::number(cout);
    QString degre_string=QString::number(degre);

         query.prepare("INSERT INTO maint (id,datee,des,cout,degre) "
                       "VALUES (:id,:datee,:des,:cout,:degre)");
         query.bindValue(":id",id_string);
         query.bindValue(":datee",datee);
         query.bindValue(":des",des);
         query.bindValue(":cout",cout_string);
         query.bindValue(":degre",degre_string);

      return query.exec();

}
QSqlQueryModel *maintenance::afficher()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM maint");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Cout"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Degre"));

        return model;
}
bool maintenance::Supprime(int id)
{
    QSqlQuery query;
        query.prepare("delete from maint where id=:id");
        query.bindValue(0, id);
    return query.exec();
}
bool maintenance::modifier()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString cout_string=QString::number(cout);
    QString degre_string=QString::number(degre);

query.prepare("UPDATE maint SET datee=:datee,des=:des,cout=:cout,degre=:degre WHERE id=:id;");

query.bindValue(":id",id_string);
query.bindValue(":datee",datee);
query.bindValue(":des",des);
query.bindValue(":cout",cout_string);
query.bindValue(":degre",degre_string);

 return query.exec();
}

bool maintenance::reset()
{
   QSqlQuery query;
        query.prepare("delete maint");
        query.bindValue(0, id);
     return query.exec();
}
// ## Recherche ## //

QSqlQueryModel *maintenance::afficher_id(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM maint where id= '"+ch+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Cout"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Degre"));


    return model;
}
QSqlQueryModel *maintenance::afficher_cout(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM maint where cout= '"+ch+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Cout"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Degre"));


    return model;
}
QSqlQueryModel *maintenance::afficher_degre(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM maint where degre= '"+ch+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Cout"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Degre"));

    return model;
}
