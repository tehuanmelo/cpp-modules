/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:21:15 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/17 16:52:33 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array() : arraySize(0) {
    this->array = new T[arraySize];
};

template<typename T>
Array<T>::Array(unsigned int size) : arraySize(size) {
    this->array = new T[arraySize];
};

template<typename T>
Array<T>::Array(const Array& copy) {
    this->array = NULL;
    *this = copy;
};

template<typename T>
Array<T>& Array<T>::operator=(const Array& copy) {
    if (this == &copy)
        return *this;
    if (this->array)
        delete [] this->array;
    this->arraySize = copy.arraySize;
    this->array = new T[this->arraySize];
    for (size_t i = 0; i < copy.arraySize; i++) {
        this->array[i] = copy.array[i];
    }
    return *this;
};

template<typename T>
Array<T>::~Array() {
    delete [] this->array;
};

template<typename T>
int Array<T>::getSize() const { return this->arraySize; };

template<typename T>
void Array<T>::printArrayAddress() const {
    std::cout << this->array << std::endl;
}

template<typename T>
void Array<T>::setIndex(unsigned int index, T value) {
    if (index >= this->arraySize)
        throw std::out_of_range("Index out of range");
    this->array[index] = value;
}

template<typename T>
void Array<T>::printArray() const {
    for (size_t i = 0; i < this->arraySize; i++) {
        if (i == this->arraySize - 1) {
            std::cout << this->array[i] << std::endl;
            return;
        }
        std::cout << this->array[i] << " ";
    } 
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= this->arraySize)
        throw std::out_of_range("Index out of range");
    return this->array[index];
}