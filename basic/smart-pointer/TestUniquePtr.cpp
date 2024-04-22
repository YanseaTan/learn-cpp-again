/**
 * @Author: Yansea
 * @Date:   2024-04-22
 * @Last Modified by:   Yansea
 * @Last Modified time: 2024-04-22
 */
#include <iostream>
#include <memory>

using namespace std;


int main(int argc, char const *argv[])
{
    cout << "test unique_ptr" << endl;

    int *p = new int();
    *p = 2;
    cout << p << endl;
    delete p;
    p = nullptr;
    cout << p << endl;

    unique_ptr<int> uptr = make_unique<int>(2);
    cout << *uptr << endl;
    *uptr = 1;
    cout << *uptr << endl;

    unique_ptr<int[]> uptr2 = make_unique<int[]>(10);
    for (int i=0; i<10; ++i)
    {
        uptr2[i] = i * i;
    }
    for (int i=0; i<10; ++i)
    {
        cout << uptr2[i] << endl;
    }

    return 0;
}
