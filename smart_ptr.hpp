#ifndef SHARED_PTR_HPP
#define SHARED_PTR_HPP

namespace detail{
    template <typename T>
    class smart_ptr {
    public:
        smart_ptr(T * ptr) {
            obj = ptr;
            count = new int;
            *count = 1;
        }

        smart_ptr(smart_ptr<T> & other) {
            obj = other.obj;
            count = other.count;
            ++(*count);
        }

        smart_ptr<T> & operator=(smart_ptr<T> & other) {
            if (*count > 0) {
                remove();
            }
            if (this != &other) {
                obj = other.obj;
                count = other.count;
                ++(*count);
            }
            return *this;
        }

        ~smart_ptr() {
            remove();
        }

        T& operator*() {
            return *obj;
        }
        T* operator->() {
            return obj;
        }

    //protected:
        void remove() {
            --(*count);
            if (count == 0) {
                delete obj;
                delete count;
                obj = NULL;
                count = NULL;
            }
        }
        T * obj;
        int * count;
    };
}

#endif // SHARED_PTR_HPP
