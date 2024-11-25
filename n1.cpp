#include <iostream>
using namespace std;

char* CopyString(const char* str) {
    if (str == nullptr) {
        return nullptr;
    }
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    char* copy = new char[length + 1];
    for (size_t i = 0; i < length; ++i) {
        copy[i] = str[i];
    }
    copy[length] = '\0';
    return copy;
}
char* ConcatinateStrings(const char* a, const char* b) {
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    size_t length_a = 0, length_b = 0;
    while (a && a[length_a] != '\0') {
        length_a++;
    }
    while (b && b[length_b] != '\0') {
        length_b++;
    }
    char* concatenated = new char[length_a + length_b + 1];
    for (size_t i = 0; i < length_a; ++i) {
        concatenated[i] = a[i];
    }

    for (size_t i = 0; i < length_b; ++i) {
        concatenated[length_a + i] = b[i];
    }
    concatenated[length_a + length_b] = '\0';
    return concatenated;
}
int main() {
    const char* original = "Test1 ";
    const char* world = "Test2";
    char* copiedString = CopyString(original);
    cout << "Copied String: " << copiedString << endl;
    char* concatenatedString = ConcatinateStrings(copiedString, world);
    cout << "Concatenated String: " << concatenatedString << endl;
    delete[] copiedString;
    delete[] concatenatedString;
    return 0;
}
