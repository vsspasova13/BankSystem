//#pragma once 
//#include <utility>
//#include <stdexcept>
//
//template <class T>
//class Polymorphic_Ptr {
//	T* data = nullptr;
//
//	void copyFrom(const Polymorphic_Ptr<T>& other);
//	void moveFrom(Polymorphic_Ptr<T>&& other);
//	void free();
//
//public:
//	Polymorphic_Ptr() = default;
//	Polymorphic_Ptr(T* data);
//	Polymorphic_Ptr(const Polymorphic_Ptr<T>& other);
//	Polymorphic_Ptr(Polymorphic_Ptr<T>&& other) noexcept;
//
//	Polymorphic_Ptr<T>& operator=(const Polymorphic_Ptr<T>& other);
//	Polymorphic_Ptr<T>& operator=(Polymorphic_Ptr<T>&& other) noexcept;
//
//	~Polymorphic_Ptr();
//
//	T* operator->();
//	const T* operator->() const;
//
//	T& operator*();
//	const T& operator*() const;
//
//	operator bool() const;
//	void reset(T* data);
//
//	T* get();
//	const T* get() const;
//};
//
//
//template<class T>
//void Polymorphic_Ptr<T>::copyFrom(const Polymorphic_Ptr<T>& other)
//{
//	data = other.data->clone();
//}
//
//template<class T>
//void Polymorphic_Ptr<T>::moveFrom(Polymorphic_Ptr<T>&& other)
//{
//	data = other.data;
//	other.data = nullptr;
//}
//
//template<class T>
//void Polymorphic_Ptr<T>::free()
//{
//	delete data;
//}
//
//template<class T>
//Polymorphic_Ptr<T>::Polymorphic_Ptr(T* data) : data(data)
//{
//}
//
//template<class T>
//inline Polymorphic_Ptr<T>::Polymorphic_Ptr(const Polymorphic_Ptr<T>& other)
//{
//	copyFrom(other);
//}
//
//template<class T>
//Polymorphic_Ptr<T>::Polymorphic_Ptr(Polymorphic_Ptr<T>&& other) noexcept
//{
//	moveFrom(std::move(other));
//}
//
//template<class T>
//Polymorphic_Ptr<T>& Polymorphic_Ptr<T>::operator=(const Polymorphic_Ptr<T>& other)
//{
//	if (this != &other) {
//		free();
//		copyFrom(other);
//	}
//	return *this;
//}
//
//template<class T>
//Polymorphic_Ptr<T>& Polymorphic_Ptr<T>::operator=(Polymorphic_Ptr<T>&& other) noexcept
//{
//	if (this != &other) {
//		free();
//		moveFrom(std::move(other));
//	}
//	return *this;
//}
//
//template<class T>
//Polymorphic_Ptr<T>::~Polymorphic_Ptr()
//{
//	free();
//}
//
//template<class T>
//T* Polymorphic_Ptr<T>::operator->()
//{
//	return data;
//}
//
//template<class T>
//const T* Polymorphic_Ptr<T>::operator->() const
//{
//	return data;
//}
//
//template<class T>
//T& Polymorphic_Ptr<T>::operator*()
//{
//	if (data == nullptr) {
//		throw std::runtime_error("ptr is nullptr");
//	}
//	return *data;
//}
//
//template<class T>
//const T& Polymorphic_Ptr<T>::operator*() const
//{
//	if (data == nullptr) {
//		throw std::runtime_error("ptr is nullptr");
//	}
//	return *data;
//}
//
//template<class T>
//Polymorphic_Ptr<T>::operator bool() const
//{
//	return data != nullptr;
//}
//
//template<class T>
//void Polymorphic_Ptr<T>::reset(T* data)
//{
//	if (this->data != data) {
//		free();
//		this->data = data;
//	}
//}
//
//template<class T>
//T* Polymorphic_Ptr<T>::get()
//{
//	return data;
//}
//
//template<class T>
//const T* Polymorphic_Ptr<T>::get() const
//{
//	return data;
//}
#pragma once

template <typename T>
class Polymorphic_Ptr {
    T* ptr;
public:
    explicit Polymorphic_Ptr(T* p = nullptr) : ptr(p) {}
    ~Polymorphic_Ptr() { delete ptr; }

    // Copy constructor
    Polymorphic_Ptr(const Polymorphic_Ptr& other) : ptr(other.ptr ? other.ptr->clone() : nullptr) {}

    // Copy assignment
    Polymorphic_Ptr& operator=(const Polymorphic_Ptr& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr ? other.ptr->clone() : nullptr;
        }
        return *this;
    }

    // Move constructor
    Polymorphic_Ptr(Polymorphic_Ptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Move assignment
    Polymorphic_Ptr& operator=(Polymorphic_Ptr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T* operator->() { return ptr; }
    const T* operator->() const { return ptr; }
    T& operator*() { return *ptr; }
    const T& operator*() const { return *ptr; }

    T* get() const { return ptr; }
    T* release() { T* oldPtr = ptr; ptr = nullptr; return oldPtr; }
};

template <typename T>
bool operator==(const Polymorphic_Ptr<T>& lhs, const Polymorphic_Ptr<T>& rhs) {
    return lhs.get() == rhs.get();
}

template <typename T>
bool operator!=(const Polymorphic_Ptr<T>& lhs, const Polymorphic_Ptr<T>& rhs) {
    return !(lhs == rhs);
}
