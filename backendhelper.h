#ifndef BACKENDHELPER_H
#define BACKENDHELPER_H

#include <QObject>
#include <QQmlEngine>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QGuiApplication>

class BackendHelper : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit BackendHelper(QObject *parent = nullptr);

    static Q_INVOKABLE void setupDatabase();
    Q_INVOKABLE QVariantList fetchItemsFromDatabase();
    Q_INVOKABLE void saveItemToDatabase(int _id, QString _name, int _age);
    Q_INVOKABLE void updateItemInDatabase(int _id, QString _updatedName, int _updatedAge);
    Q_INVOKABLE void deleteItemInDatabase(int _id = 0);
signals:
};

#endif // BACKENDHELPER_H
