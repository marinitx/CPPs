#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "Marinita";

    std::cout << "Original Data pointer: " << &data << std::endl;
    std::cout << "Original Data id: " << data.id << ", name: " << data.name << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << ptr << std::endl;
    std::cout << "Deserialized Data id: " << ptr->id << ", name: " << ptr->name << std::endl;

    if (ptr == &data)
        std::cout << "SUCCESS: Pointers match!" << std::endl;
    else
        std::cout << "FAIL: Pointers do not match!" << std::endl;

    return 0;
}
