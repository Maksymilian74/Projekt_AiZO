#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<typename T>
class DynamicArray {
private:
    T* array; // Wskaźnik do tablicy dynamicznej
    int size; // Rozmiar tablicy

public:
    DynamicArray();
    explicit DynamicArray(int size); // Konstruktor

    ~DynamicArray(); // Destruktor

    int getSize() const; // Zwraca rozmiar tablicy

    T& operator[](int index); // Przeciążenie operatora dostępu do elementu po indeksie
    const T& operator[](int index) const; // Przeciążenie operatora dostępu do elementu po indeksie dla stałego obiektu
};

#endif


