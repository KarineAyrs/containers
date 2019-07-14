#pragma once
#include "GroupContainer.h"

// Абстрактный класс: двунаправленный список
class AbstractList2: public GroupContainer
{
public:
    // конструктор
    AbstractList2(MemoryManager &mem): GroupContainer(mem) {}

    // деструктор
    virtual ~AbstractList2() {}

    // Добавление элемента в конец контейнера.
    // В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
    virtual int push_back(void *elem, size_t elemSize) = 0;

    // Добавление элемента в начало контейнера.
    // В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
    virtual int push_front(void *elem, size_t elemSize) = 0;

    // Удаление элемента из конца контейнера.
    virtual void pop_back() = 0;

    // Удаление элемента из начала контейнера.
    virtual void pop_front() = 0;

    // Функция явно возвращает указатель на элемент, находящийся в начале контейнера.
    // и не явно возвращает размер данных
    virtual void* front(size_t &size) = 0;

    // Функция явно возвращает указатель на элемент, находящийся в конеце контейнера.
    // и не явно возвращает размер данных
    virtual void* back(size_t &size) = 0;

    // Добавление элемента в позицию, на которую указывает итератор iter.
    // В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
    virtual int insert(Iterator *iter, void *elem, size_t elemSize) = 0;
};
