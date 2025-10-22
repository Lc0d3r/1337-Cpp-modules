#include "Serializer.hpp"

int main()
{
    Data data;
    data.value = 42;

    Serializer serializer;

    // Serialize the pointer to Data
    uintptr_t raw = serializer.serialize(&data);

    // Deserialize back to Data pointer
    Data* deserializedData = serializer.deserialize(raw);

    // Verify that the deserialized pointer points to the same data
    if (deserializedData == &data)
    {
        std::cout << "Serialization and Deserialization successful!" << std::endl;
        std::cout << "Data value: " << deserializedData->value << std::endl;
    }
    else
    {
        std::cout << "Serialization and Deserialization failed!" << std::endl;
    }

    return 0;
}