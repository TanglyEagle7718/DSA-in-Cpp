cmake_minimum_required(VERSION 3.16)
project(DSAInCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(ArrayList)
add_subdirectory(SinglyLinkedList)
add_subdirectory(DoublyLinkedList)
add_subdirectory(CircularLinkedList)
add_subdirectory(StackArray)
add_subdirectory(QueueArray)
add_subdirectory(BinarySearchTree)
add_subdirectory(Heap)
