#pragma once

namespace containers {

template<typename T>
class vector
{
private:

	T* ptr_;
	size_t size_;
	size_t capacity_;

public:
	
	vector(size_t capacity = 16) 
	{
		if(capacity > 0) {
			ptr_ = new T[capacity];
			this->capacity_ = capacity;
			this->size_ = 0;
		}
	}

	size_t size() { return size_; }
	size_t capacity() { return capacity_; }
	bool IsEmpty() { return size_ == 0; }

	T& Get(size_t index)
	{
		return ptr_[index];
	}

	void Set(size_t index, T&& element)
	{
		ptr_[index] = element;
	}

	void Clear()
	{
		for(size_t i = 0; i < capacity_ ; ++i) {
			ptr_[i] = NULL;
		}
		size_ = 0;
	}

	void Push_Back(const T& element)
	{
		Add(element);
	}

	void Push_Back(T&& element)
	{
		Add(element);
	}

	void Add(const T& element)
	{
		if (size_ + 1 >= capacity_) {
			// double the capacity
			capacity_ *= 2;
			T* newptr = new T[capacity_];
			for (size_t i = 0; i < size_; ++i) {
				newptr[i] = ptr_[i];
			}
			delete[] ptr_;
			ptr_ = newptr;
		}
		ptr_[size_++] = element;
	}

	void Add(T&& element)
	{
		if(size_ + 1 >= capacity_) {
			// double the capacity
			capacity_ *= 2;
			T* newptr = new T[capacity_];
			for(size_t i = 0; i < capacity_; ++i) {
				newptr[i] = ptr_[i];
			}
			delete[] ptr_;
			ptr_ = newptr;
		}
		ptr_[size_++] = element;
	}

	void Pop_Back()
	{
		ptr_[size_--] = NULL;
	}

	T RemoveAt(size_t index)
	{
		if(index < 0 || index >= size_)
			return NULL;
		
		T data = ptr_[index];
		T* newptr = new T[size_ - 1];

		for(size_t i = 0, j = 0; i < size_; ++i, ++j) {
			if( i == index) {
				j--;
				continue;
			}
			newptr[j] = ptr_[i];
		}
		delete[] ptr_;
		ptr_ = newptr;
		capacity_ = --size_;
		return data;
	}

	bool Remove(T& element)
	{
		for(size_t i = 0; i < size_; ++i) {
			if(&ptr_[i] == &element) {
				RemoveAt(i);
				return true;
			}
		}
		return false;
	}
};

} // namespace containers
