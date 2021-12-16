//
// Created by Lenovo on 2021/12/13.
//

#include <iostream>
using namespace std;

class BigMemoryPool {
public:
    static const int PoolSize = 4096;
    BigMemoryPool() : pool_(new char[PoolSize]) {}

    ~BigMemoryPool()
    {
        if(pool_ != nullptr)
            delete[] pool_;
    }

    BigMemoryPool(const BigMemoryPool& other) : pool_(new char[PoolSize])
    {
//        cout << &other << endl;
        cout << "copy big memory pool" << endl;
        memcpy(pool_, other.pool_, PoolSize);
    }

    BigMemoryPool(BigMemoryPool&& other)
    {
        cout << "move big memory pool" << endl;
        pool_ = other.pool_;
        other.pool_ = nullptr;
    }

    BigMemoryPool& operator=(BigMemoryPool&& other)
    {
        cout << "move(operator=) big memory pool." << endl;
        if(pool_ != nullptr)
        {
            delete[] pool_;
        }
        pool_ = other.pool_;
        other.pool_ = nullptr;
        return *this;

    }

private:
    char* pool_;
};

BigMemoryPool get_pool(const BigMemoryPool& pool)
{
//    cout << "get_pool" << &pool << endl;
    return pool;
}

BigMemoryPool make_pool()
{
    BigMemoryPool pool;
    return get_pool(pool);
}

int main()
{
    BigMemoryPool my_pool;
    my_pool = make_pool();
}



