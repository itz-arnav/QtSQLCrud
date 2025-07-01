/****************************************************************************
** Meta object code from reading C++ file 'backendhelper.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../backendhelper.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backendhelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13BackendHelperE_t {};
} // unnamed namespace

template <> constexpr inline auto BackendHelper::qt_create_metaobjectdata<qt_meta_tag_ZN13BackendHelperE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "BackendHelper",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "setupDatabase",
        "",
        "fetchItemsFromDatabase",
        "QVariantList",
        "saveItemToDatabase",
        "_id",
        "_name",
        "_age",
        "updateItemInDatabase",
        "_updatedName",
        "_updatedAge",
        "deleteItemInDatabase"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'setupDatabase'
        QtMocHelpers::MethodData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'fetchItemsFromDatabase'
        QtMocHelpers::MethodData<QVariantList()>(7, 6, QMC::AccessPublic, 0x80000000 | 8),
        // Method 'saveItemToDatabase'
        QtMocHelpers::MethodData<void(int, QString, int)>(9, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 10 }, { QMetaType::QString, 11 }, { QMetaType::Int, 12 },
        }}),
        // Method 'updateItemInDatabase'
        QtMocHelpers::MethodData<void(int, QString, int)>(13, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 10 }, { QMetaType::QString, 14 }, { QMetaType::Int, 15 },
        }}),
        // Method 'deleteItemInDatabase'
        QtMocHelpers::MethodData<void(int)>(16, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Method 'deleteItemInDatabase'
        QtMocHelpers::MethodData<void()>(16, 6, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<BackendHelper, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject BackendHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13BackendHelperE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13BackendHelperE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13BackendHelperE_t>.metaTypes,
    nullptr
} };

void BackendHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BackendHelper *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->setupDatabase(); break;
        case 1: { QVariantList _r = _t->fetchItemsFromDatabase();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->saveItemToDatabase((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 3: _t->updateItemInDatabase((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 4: _t->deleteItemInDatabase((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->deleteItemInDatabase(); break;
        default: ;
        }
    }
}

const QMetaObject *BackendHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackendHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13BackendHelperE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BackendHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
