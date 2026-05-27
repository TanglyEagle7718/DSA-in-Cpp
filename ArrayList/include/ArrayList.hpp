#pragma once

#include <cstddef>
#include <stdexcept>

namespace dsa {

template <typename T>
class ArrayList {
public:
    ArrayList();

    std::size_t size() const;
    bool is_empty() const;

    void add(const T& value);
    T& get(std::size_t index);
    const T& get(std::size_t index) const;
    void set(std::size_t index, const T& value);
    void remove(std::size_t index);
    void clear();
    bool contains(const T& value) const;
};

template <typename T>
ArrayList<T>::ArrayList() {
    throw std::logic_error("TODO: implement ArrayList::ArrayList");
}

template <typename T>
std::size_t ArrayList<T>::size() const {
    throw std::logic_error("TODO: implement ArrayList::size");
}

template <typename T>
bool ArrayList<T>::is_empty() const {
    throw std::logic_error("TODO: implement ArrayList::is_empty");
}

template <typename T>
void ArrayList<T>::add(const T& value) {
    (void)value;
    throw std::logic_error("TODO: implement ArrayList::add");
}

template <typename T>
T& ArrayList<T>::get(std::size_t index) {
    (void)index;
    throw std::logic_error("TODO: implement ArrayList::get");
}

template <typename T>
const T& ArrayList<T>::get(std::size_t index) const {
    (void)index;
    throw std::logic_error("TODO: implement ArrayList::get const");
}

template <typename T>
void ArrayList<T>::set(std::size_t index, const T& value) {
    (void)index;
    (void)value;
    throw std::logic_error("TODO: implement ArrayList::set");
}

template <typename T>
void ArrayList<T>::remove(std::size_t index) {
    (void)index;
    throw std::logic_error("TODO: implement ArrayList::remove");
}

template <typename T>
void ArrayList<T>::clear() {
    throw std::logic_error("TODO: implement ArrayList::clear");
}

template <typename T>
bool ArrayList<T>::contains(const T& value) const {
    (void)value;
    throw std::logic_error("TODO: implement ArrayList::contains");
}

} // namespace dsa
