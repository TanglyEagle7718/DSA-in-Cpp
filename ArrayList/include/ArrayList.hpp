#pragma once

#include <cstddef>
#include <stdexcept>
#include <cstdint>
#include <memory>

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
    void resize();
    void set(std::size_t index, const T& value);
    void remove(std::size_t index);
    void clear();
    bool contains(const T& value) const;
private:
    static const std::size_t initSize = 8;
    static constexpr char OUT_OF_BOUNDS_ERROR[] = "Index out of bounds";

    std::size_t backingSize;
    std::size_t trueSize;
    std::unique_ptr<T[]> backingArr;
};

template <typename T>
ArrayList<T>::ArrayList() {
    backingSize = initSize;
    trueSize = 0;
    backingArr = std::make_unique<T[]>(backingSize);
}

template <typename T>
std::size_t ArrayList<T>::size() const {
    return trueSize;
}

template <typename T>
bool ArrayList<T>::is_empty() const {
    return (trueSize == 0) ? true : false;
}

template <typename T>
void ArrayList<T>::resize() {
    size_t newBackingSize = 2 * backingSize;
    if (newBackingSize < backingSize) throw std::logic_error("Array has too many elements");
    auto newBackingArr = std::make_unique<T[]>(newBackingSize);
    for (size_t i = 0 ; i < trueSize ; i++) { // this func only called when trueSize == backingSize
        newBackingArr[i] = backingArr[i];
    }
    backingSize = newBackingSize;
    backingArr = std::move(newBackingArr);
}

template <typename T>
void ArrayList<T>::add(const T& value) {
    if (trueSize == backingSize) {
        resize();
    }
    backingArr[trueSize] = value;
    ++trueSize;
}

template <typename T>
T& ArrayList<T>::get(std::size_t index) {
    if (index >= trueSize) throw std::logic_error(OUT_OF_BOUNDS_ERROR);

    return backingArr[index];
}

template <typename T>
const T& ArrayList<T>::get(std::size_t index) const {
    if (index >= trueSize) throw std::logic_error(OUT_OF_BOUNDS_ERROR);
    return backingArr[index];
}

template <typename T>
void ArrayList<T>::set(std::size_t index, const T& value) {
    if (index >= trueSize) throw std::logic_error(OUT_OF_BOUNDS_ERROR);
    backingArr[index] = value;
}

template <typename T>
void ArrayList<T>::remove(std::size_t index) {
    if (index >= trueSize) throw std::logic_error(OUT_OF_BOUNDS_ERROR);
    
    for (size_t i = index; i < trueSize - 1 ; ++i) {
        backingArr[i] = backingArr[i+1];
    }
    std::string a = "hi";
    trueSize--;
}

template <typename T>
void ArrayList<T>::clear() {
    backingSize = initSize;
    trueSize = 0;
    backingArr = std::make_unique<T[]>(backingSize);
}

template <typename T>
bool ArrayList<T>::contains(const T& value) const {
    
    for (size_t i = 0 ; i < trueSize ; i++) {
        if (backingArr[i] == value) {
            return true;
        }
    }
    return false;
}

} // namespace dsa
