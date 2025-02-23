#ifndef ISM_VECTOR_TCC
#define ISM_VECTOR_TCC
#include "ism_vector.h"

namespace insomnia {

// vector::iterator

template <class Tp>
vector<Tp>::iterator::iterator()
  : _container(nullptr), _index(0) {}

template <class Tp>
vector<Tp>::iterator::iterator(const vector<Tp> *container, const size_t &index)
  : _container(container), _index(index) {}

template <class Tp>
vector<Tp>::iterator::iterator(const iterator &) = default;

template <class Tp>
typename vector<Tp>::iterator&
  vector<Tp>::iterator::operator=(const iterator &) = default;

template <class Tp>
typename vector<Tp>::iterator
  vector<Tp>::iterator::operator+(const differnce_type &diff) const {
  if(diff < 0) return *this - (-diff);
  if(_index + diff > _container->size())
    throw index_out_of_bound{};
  return iterator{_container, _index + diff};
}

template <class Tp>
typename vector<Tp>::iterator
  vector<Tp>::iterator::operator-(const differnce_type &diff) const {
  if(diff < 0) return *this + (-diff);
  if(_index < diff)
    throw index_out_of_bound{};
  return {_container, _index - diff};
}

template <class Tp>
typename vector<Tp>::iterator::differnce_type
  vector<Tp>::iterator::operator-(const iterator &other) const {
  if(_container != other._container)
    throw invalid_iterator{};
  return static_cast<differnce_type>(_index) - static_cast<differnce_type>(other._index);
}

template <class Tp>
typename vector<Tp>::iterator&
  vector<Tp>::iterator::operator+=(const differnce_type &diff) {
  if(diff < 0) return *this -= -diff;
  if(_index + diff > _container->size())
    throw index_out_of_bound{};
  _index += diff;
  return *this;
}

template <class Tp>
typename vector<Tp>::iterator&
  vector<Tp>::iterator::operator-=(const differnce_type &diff) {
  if(diff < 0) return *this += -diff;
  if(_index < diff)
    throw index_out_of_bound{};
  _index -= diff;
  return *this;
}

template <class Tp>
typename vector<Tp>::iterator&
  vector<Tp>::iterator::operator++() {
  return *this += 1;
}

template <class Tp>
typename vector<Tp>::iterator
  vector<Tp>::iterator::operator++(int) {
  iterator tmp = *this;
  *this += 1;
  return tmp;
}

template <class Tp>
typename vector<Tp>::iterator&
  vector<Tp>::iterator::operator--() {
  return *this -= 1;
}

template <class Tp>
typename vector<Tp>::iterator
  vector<Tp>::iterator::operator--(int) {
  iterator tmp = *this;
  *this -= 1;
  return tmp;
}

template <class Tp>
bool vector<Tp>::iterator::operator==(const iterator &other) const {
  return _container == other._container && _index == other._index;
}

template <class Tp>
bool vector<Tp>::iterator::operator==(const const_iterator &other) const {
  return _container == other._container && _index == other._index;
}

template <class Tp>
bool vector<Tp>::iterator::operator!=(const iterator &other) const {
  return _container != other._container || _index != other._index;
}

template <class Tp>
bool vector<Tp>::iterator::operator!=(const const_iterator &other) const {
  return _container != other._container || _index != other._index;
}

template <class Tp>
Tp& vector<Tp>::iterator::operator*() const {
  return _container->_data[_index];
}

template <class Tp>
Tp* vector<Tp>::iterator::operator->() const {
  return _container->_data + _index;
}



// vector::const_iterator

template <class Tp>
vector<Tp>::const_iterator::const_iterator()
  : _container(nullptr), _index(0) {}

template <class Tp>
vector<Tp>::const_iterator::const_iterator(const vector<Tp> *container, const size_t &index)
  : _container(container), _index(index) {}

template <class Tp>
vector<Tp>::const_iterator::const_iterator(const const_iterator &) = default;

template <class Tp>
vector<Tp>::const_iterator::const_iterator(const iterator &other)
  : _container(other._container), _index(other._index) {}

template <class Tp>
typename vector<Tp>::const_iterator&
  vector<Tp>::const_iterator::operator=(const const_iterator &) = default;

template <class Tp>
typename vector<Tp>::const_iterator
  vector<Tp>::const_iterator::operator+(const differnce_type &diff) const {
  if(diff < 0) return *this - (-diff);
  if(_index + diff > _container->size())
    throw index_out_of_bound{};
  return {_container, _index + diff};
}

template <class Tp>
typename vector<Tp>::const_iterator
  vector<Tp>::const_iterator::operator-(const differnce_type &diff) const {
  if(diff < 0) return *this + (-diff);
  if(_index < diff)
    throw index_out_of_bound{};
  return {_container, _index - diff};
}

template <class Tp>
typename vector<Tp>::const_iterator::differnce_type
  vector<Tp>::const_iterator::operator-(const const_iterator &other) const {
  if(_container != other._container)
    throw invalid_iterator{};
  return static_cast<differnce_type>(_index) - static_cast<differnce_type>(other._index);
}

template <class Tp>
typename vector<Tp>::const_iterator&
  vector<Tp>::const_iterator::operator+=(const differnce_type &diff) {
  if(diff < 0) return *this -= -diff;
  if(_index + diff > _container->size())
    throw index_out_of_bound{};
  _index += diff;
  return *this;
}

template <class Tp>
typename vector<Tp>::const_iterator&
  vector<Tp>::const_iterator::operator-=(const differnce_type &diff) {
  if(diff < 0) return *this += -diff;
  if(_index < diff)
    throw index_out_of_bound{};
  _index -= diff;
  return *this;
}

template <class Tp>
typename vector<Tp>::const_iterator&
  vector<Tp>::const_iterator::operator++() {
  return *this += 1;
}

template <class Tp>
typename vector<Tp>::const_iterator
  vector<Tp>::const_iterator::operator++(int) {
  iterator tmp = *this;
  *this += 1;
  return tmp;
}

template <class Tp>
typename vector<Tp>::const_iterator&
  vector<Tp>::const_iterator::operator--() {
  return *this -= 1;
}

template <class Tp>
typename vector<Tp>::const_iterator
  vector<Tp>::const_iterator::operator--(int) {
  iterator tmp = *this;
  *this -= 1;
  return tmp;
}

template <class Tp>
bool vector<Tp>::const_iterator::operator==(const const_iterator &other) const {
  return _container == other._container && _index == other._index;
}

template <class Tp>
bool vector<Tp>::const_iterator::operator==(const iterator &other) const {
  return _container == other._container && _index == other._index;
}

template <class Tp>
bool vector<Tp>::const_iterator::operator!=(const const_iterator &other) const {
  return _container != other._container || _index != other._index;
}

template <class Tp>
bool vector<Tp>::const_iterator::operator!=(const iterator &other) const {
  return _container != other._container || _index != other._index;
}

template <class Tp>
const Tp& vector<Tp>::const_iterator::operator*() const {
  return _container->_data[_index];
}

template <class Tp>
const Tp* vector<Tp>::const_iterator::operator->() const {
  return _container->_data + _index;
}




// vector

template <class Tp>
vector<Tp>::vector()
  : _data(nullptr), _size(0), _capacity(0) {}

template <class Tp>
vector<Tp>::vector(const vector &other): vector() {
  if(other.empty()) return;
  _size = other._size;
  _capacity = other._capacity;
  _data = static_cast<Tp*>(operator new(_capacity * sizeof(Tp)));
  for(size_t i = 0; i < _size; ++i)
    new(_data + i) Tp(other._data[i]);
}

template <class Tp>
vector<Tp>::vector(vector &&other) noexcept: vector() {
  if(other.empty()) return;
  _size = other._size;
  _capacity = other._capacity;
  _data = other._data;
  other._size = 0;
  other._capacity = 0;
  other._data = nullptr;
}

template <class Tp>
vector<Tp>::~vector() {
  clear();
  operator delete(_data);
  _data = nullptr;
  _capacity = 0;
}

template <class Tp>
vector<Tp>& vector<Tp>::operator=(const vector &other) {
  if(this == &other) return *this;
  clear();
  reserve(other._capacity);
  for(size_t i = 0; i < other._size; ++i)
    new(_data + i) Tp(other._data[i]);
  _size = other._size;
  return *this;
}

template <class Tp>
vector<Tp>& vector<Tp>::operator=(vector &&other) {
  if(this == other) return *this;
  clear();
  operator delete(_data);
  _data = other._data;
  _size = other._size;
  _capacity = other._capacity;
  other._data = nullptr;
  other._size = 0;
  other._capacity = 0;
  return *this;
}

template <class Tp>
Tp& vector<Tp>::at(const size_t &pos) {
  if(pos >= _size)
    throw index_out_of_bound{};
  return _data[pos];
}

template <class Tp>
const Tp& vector<Tp>::at(const size_t &pos) const {
  if(pos >= _size)
    throw index_out_of_bound{};
  return _data[pos];
}

template <class Tp>
Tp& vector<Tp>::operator[](const size_t &pos) {
  if(pos >= _size)
    throw index_out_of_bound{};
  return _data[pos];
}

template <class Tp>
const Tp& vector<Tp>::operator[](const size_t &pos) const {
  if(pos >= _size)
    throw index_out_of_bound{};
  return _data[pos];
}

template <class Tp>
const Tp& vector<Tp>::front() const {
  if(empty())
    throw container_is_empty{};
  return _data[0];
}

template <class Tp>
const Tp& vector<Tp>::back() const {
  if(empty())
    throw container_is_empty{};
  return _data[_size - 1];
}

template <class Tp>
typename vector<Tp>::iterator
  vector<Tp>::begin() const {
  return iterator{this, 0};
}

template <class Tp>
typename vector<Tp>::iterator
  vector<Tp>::end() const {
  return iterator{this, _size};
}

template <class Tp>
typename vector<Tp>::const_iterator
  vector<Tp>::cbegin() const {
  return const_iterator{this, 0};
}

template <class Tp>
typename vector<Tp>::const_iterator
  vector<Tp>::cend() const {
  return const_iterator{this, _size};
}

template <class Tp>
typename vector<Tp>::iterator
  vector<Tp>::insert(const iterator &iter, const Tp &value) {
  if(iter._container != this)
    throw invalid_iterator{};
  return insert(iter._index, value);
}

template <class Tp>
typename vector<Tp>::iterator
  vector<Tp>::insert(const size_t &index, const Tp &value) {
  if(index > _size)
    throw index_out_of_bound{};
  if(_size == _capacity)
    reserve(_capacity * 2);
  ++_size;
  for(size_t i = _size - 1; i > index; --i)
    new(_data + i) Tp(std::move(_data[i - 1]));
  new(_data + index) Tp(value);
  return iterator{this, index};
}

template <class Tp>
typename vector<Tp>::iterator vector<Tp>::erase(const iterator &iter) {
  if(iter._container != this)
    throw invalid_iterator{};
  return erase(iter._index);
}

template <class Tp>
typename vector<Tp>::iterator vector<Tp>::erase(const size_t &index) {
  if(index >= _size)
    throw index_out_of_bound{};
  --_size;
  _data[index].~Tp();
  for(size_t i = index; i < _size; ++i)
    new(_data + i) Tp(std::move(_data[i + 1]));
  return {this, index};
}

template <class Tp>
void vector<Tp>::push_back(const Tp &value) {
  if(_size == _capacity) reserve(_capacity * 2 + 1);
  new(_data + _size) Tp(value);
  ++_size;
}

template <class Tp>
void vector<Tp>::push_back(Tp &&value) {
  if(_size == _capacity) reserve(_capacity * 2 + 1);
  new(_data + _size) Tp(value);
  ++_size;
}

template <class Tp>
void vector<Tp>::pop_back() {
  if(empty())
    throw container_is_empty{};
  --_size;
  _data[_size].~Tp();
}

template <class Tp>
bool vector<Tp>::empty() const {
  return !_data;
}

template <class Tp>
size_t vector<Tp>::size() const {
  return _size;
}

template <class Tp>
void vector<Tp>::clear() {
  for(size_t i = 0; i < _size; ++i)
    _data[i].~Tp();
  _size = 0;
}

template <class Tp>
void vector<Tp>::reserve(const size_t &capacity) {
  if(_capacity >= capacity) return;
  Tp *new_data = static_cast<Tp*>(operator new(capacity * sizeof(Tp)));
  for(size_t i = 0; i < _size; ++i)
    new(new_data + i) Tp(std::move(_data[i]));
  operator delete(_data);
  _data = new_data;
  _capacity = capacity;
}

}




#endif // ISM_VECTOR_TCC