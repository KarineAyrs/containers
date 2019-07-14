#pragma once
#include "GroupContainer.h"

// Абстрактный класс: ассциативная таблица
class AbstractTable: public GroupContainer
{
public:
    // конструктор
    AbstractTable(MemoryManager &mem): GroupContainer(mem) {}

    // деструктор
    virtual ~AbstractTable() {}

    // Добавление элемента в контейнер, с сответствующим ключом.
    // В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
    virtual int insertByKey(void *key, size_t keySize, void *elem, size_t elemSize) = 0;

    // Удаление элемента с сответствующим ключом из контейнера.
    virtual void removeByKey(void *key, size_t keySize) = 0;

    // Функция возвращает указатель на итератор, указывающий на найденный в контейнере элемент с сответствующим ключом.
    // Если элемент не найден, возвращается нулевой указатель.
    virtual Iterator* findByKey(void *key, size_t keySize) = 0;

    // доступ к элементу с ключом key
    virtual void* at(void *key, size_t keySize, size_t &valueSize) = 0;

    // хэш функция
    virtual size_t hash_function(void *key, size_t keySize) = 0;
};
