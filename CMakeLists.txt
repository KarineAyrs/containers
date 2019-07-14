cmake_minimum_required(VERSION 3.12)
project(clionprojects)

set(CMAKE_CXX_STANDARD 14)

add_executable(clionprojects main.cpp
        AssociativeTable.h
        AssociativeTable.cpp
        Container.h
        ContainerTest.h
        ContainerTest.cpp
        DoubleLinkedList.cpp
        DoubleLinkedList.h
        GroupContainer.h
        List2Abstract.h
        Mem.h
        MemoryManager.h
        TableAbstract.h)

