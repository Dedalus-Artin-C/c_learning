#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int num ;
    cin >> num ;
    int result = ~num; 

    std::cout << "Result: " << result << std::endl;
    std::bitset<32> binary(num);
    std::cout << "Binary representation: " << binary << std::endl;
    std::bitset<32> binary_result(result);
    std::cout << "Binary result: " << binary_result << std::endl;

    return 0;
}

