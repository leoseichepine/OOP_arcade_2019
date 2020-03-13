/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SoLoader
*/

#ifndef SOLOADER_HPP_
#define SOLOADER_HPP_

#include "dlfcn.h"

template <typename T>
class SoLoader {
    public:
        SoLoader(const std::string &filename)
        {
            this->_lib = dlopen(filename.c_str(), RTLD_LAZY);
            if (this->_lib == nullptr)
                throw std::exception();
            T *(*func)() = reinterpret_cast<T *(*)()>(dlsym(this->_lib, "entry"));
            if (func == nullptr)
                throw std::exception();
            this->_instance = func();
        }
        ~SoLoader() {
            if (this->_instance != nullptr)
                delete this->_instance;
            if (this->_lib != nullptr)
                dlclose(this->_lib);
        }
        T *operator ->() {
            return (this->_instance);
        }
    private:
        void *_lib = nullptr;
        T *_instance = nullptr;
};

#endif /* !SOLOADER_HPP_ */