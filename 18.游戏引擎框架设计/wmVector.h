#ifndef _WM_VECTOR_H_
#define _WM_VECTOR_H_

#include <vector>
#include <algorithm>
#include "wmDefine.h"

NS_WM_BEGIN

// 重写vector 为了方便addChild()和removeChild()的++_reference和--_reference操作

template <class T>
class vector
{ // 组合

    // 迭代器
public:
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

    using reverse_iterator = typename std::vector<T>::reverse_iterator;
    using const_reverse_iterator = typename std::vector<T>::const_reverse_iterator;

    iterator begin() { return _data.begin(); }
    const_iterator begin() const { return _data.begin(); }

    iterator end() { return _data.end(); }
    const_iterator end() const { return _data.end(); }

    const_iterator cbegin() { return _data.cbegin(); }
    const_iterator cend() const { return _data.cend(); }

    reverse_iterator rbegin() { return _data.rbegin(); }
    const_reverse_iterator rbegin() const { return _data.rbegin(); }

    reverse_iterator rend() { return _data.rend(); }
    const_reverse_iterator rend() const { return _data.rend(); }

    const_reverse_iterator crbegin() const { return _data.crbegin(); }
    const_reverse_iterator crend() const { return _data.crend(); }

    const_iterator find(T object) const
    {
        return std::find(_data.begin(), _data.end(), object);
    }
    iterator find(T object)
    {
        return std::find(_data.begin(), _data.end(), object);
    }

    iterator erase(iterator pos)
    {
        (*pos)->release();
        return _data.erase(pos);
    }
    iterator erase(iterator first, iterator last)
    {
        for (auto it = first; it != last; ++it)
        {
            (*it)->release();
        }
        return _data.erase(first, last);
    }
    iterator erase(ssize_t index)
    {
        auto it = std::next(begin(), index);
        (*it)->release();
        return _data.erase(it);
    }

public:
    // 构造函数
    vector<T>() : _data()
    {
    }
    vector<T>(ssize_t capacity) : _data()
    {
        reserve(capacity);
    }
    vector<T>(std::initializer_list<T> list)
    {
        for (auto &e : list)
        {
            push_back(e);
        }
    }
    virtual ~vector<T>()
    {
        clear();
    }
    // 拷贝构造
    vector<T>(const vector<T> &other) : _data(other._data)
    {
        addRefForAllObjects(_data);
    }
    // 移动构造
    vector<T>(vector<T> &&other) : _data(std::move(other._data))
    {
    }
    vector<T> &operator=(const vector<T> &other)
    {
        if (this != &other)
        {
            clear();
            _data = other._data;
            addRefForAllObjects(_data);
        }
        return *this;
    }
    vector<T> &operator=(vector<T> &&other)
    {
        if (this != &other)
        {
            clear();
            _data = std::move(other._data);
        }
        return *this;
    }
    void reserve(ssize_t size)
    {
        _data.reserve(size);
    }
    ssize_t capacity()
    {
        return _data.capacity();
    }
    ssize_t size()
    {
        return _data.size();
    }
    bool empty()
    {
        return _data.empty();
    }
    ssize_t max_size()
    {
        return _data.max_size();
    }
    T at(ssize_t index)
    {
        return _data[index];
    }
    T front()
    {
        return _data.front();
    }
    T back()
    {
        return _data.back();
    }
    bool contains(T object)
    {
        return (std::find(_data.begin(), _data.end(), object) != _data.end());
    }
    bool equals(const vector<T> &other)
    {
        ssize_t s = this->size();
        for (ssize_t i = 0; i < s; i++)
        {
            if (this->at(i) != other.at(i))
            {
                return false;
            }
        }
        return true;
    }
    void push_back(T object)
    {
        _data.push_back(object);
        object->retain();
    }
    void push_back(const vector<T> &other)
    {
        for (const auto &obj : other)
        {
            _data.psuh_back(obj);
            obj.retain();
        }
    }
    void insert(ssize_t index, T object)
    {
        _data.insert(std::begin(_data) + index, object);
        object->retain();
    }
    void pop_back()
    {
        auto last = _data.back();
        _data.pop_back();
        last->release();
    }
    void clear()
    {
        for (auto it : _data)
        {
            it->release();
        }
        _data.clear();
    }
    ssize_t getIndex(T object)
    {
        auto it = std::find(_data.begin(), _data.end(), object);
        if (it != _data.end())
        {
            return it - _data.begin();
        }
        return -1;
    }
    void swap(T object1, T object2)
    {
        ssize_t idx1 = getIndex(object1);
        ssize_t idx2 = getIndex(object2);
        std::swap(_data[idx1], _data[idx2]);
    }
    void swap(ssize_t idx1, ssize_t idx2)
    {
        std::swap(_data[idx1], _data[idx2]);
    }
    void replace(ssize_t index, T object)
    {
        _data[index]->release();
        _data[index] = object;
        object->retain();
    }
    void reverse()
    {
        std::reverse(std::begin(_data), std::end(_data));
    }

protected:
    void addRefForAllObjects(std::vector<T> &data)
    {
        for (const auto &obj : data)
        {
            obj->retain();
        }
    }
    std::vector<T> _data;
};

NS_WM_END

#endif