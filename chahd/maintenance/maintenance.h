#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class maintenance
{
private:
    int id,cout,degre;
    QString datee,des;
public:
    maintenance();
    maintenance(int,QString,QString,int,int);

    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprime(int);
    bool modifier();
    bool reset();
    int getid();
    void setid(int);

    /*Recherche*/
    QSqlQueryModel *afficher_id(QString ch);
    QSqlQueryModel *afficher_cout(QString ch);
    QSqlQueryModel *afficher_degre(QString ch);
};

#endif // MAINTENANCE_H
