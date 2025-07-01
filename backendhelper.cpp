#include "backendhelper.h"

BackendHelper::BackendHelper(QObject *parent)
    : QObject{parent}
{}

void BackendHelper::setupDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("AppDatabase.db");
    bool isDatabaseOpen = db.open();
    if(isDatabaseOpen) {

        QSqlQuery query;
        query.prepare("CREATE TABLE firstTable (ID INT PRIMARY KEY, Name TEXT, Age INT);");
        query.exec();

        query.prepare("CREATE TABLE secondTable (ID INT, Name TEXT, Age INT, Phone TEXT);");
        query.exec();

    } else {
        qApp->quit();
    }
}

QVariantList BackendHelper::fetchItemsFromDatabase()
{
    QVariantList newItemsList;
    QSqlQuery query;
    query.prepare("SELECT * from firstTable ORDER BY Name ASC, Age ASC, ID Desc;");
    query.exec();  // Already run
    // we got the result
    // now loop over result array and print
    while(query.next()) {
        int _id = query.value(0).toInt();
        QString _name = query.value(1).toString();
        int _age = query.value(2).toInt();

        QVariantMap itemMap;
        itemMap["_id"] = _id;
        itemMap["name"] = _name;
        itemMap["age"] = _age;

        newItemsList.append(itemMap);
        qDebug() << "The id is " << _id << " and name is " << _name << " and age is " << _age;
    }

    return newItemsList;
}

void BackendHelper::saveItemToDatabase(int _id, QString _name,  int _age)
{
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO firstTable VALUES (:id, :name, :age);");
    query.bindValue(":name", _name);
    query.bindValue(":id", _id);
    query.bindValue(":age", _age);
    bool success = query.exec();
    if(success) {
        qDebug() << "Item saved successfully";
    }
}

void BackendHelper::updateItemInDatabase(int _id, QString _updatedName, int _updatedAge)
{
    QSqlQuery query;
    query.prepare("UPDATE firstTable SET Name = :updatedName, Age = :updatedAge WHERE ID = :id");
    query.bindValue(":updatedName", _updatedName);
    query.bindValue(":id", _id);
    query.bindValue(":updatedAge", _updatedAge);
    bool success = query.exec();
    if(success) {
        qDebug() << "Item updated successfully";
    }
}

void BackendHelper::deleteItemInDatabase(int _id)
{
    QSqlQuery query;
    if(_id > 0) {
        query.prepare("DELETE FROM firstTable WHERE ID = :id");
        query.bindValue(":id", _id);
    } else {
        query.prepare("DELETE FROM firstTable");
    }
    bool success = query.exec();
    if(success) {
        qDebug() << "Item deleted successfully";
    }
}
