#include "BigNumCalc.h"

#include <iostream>

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> numList;
    
    for (auto &c: numString) {
        int num = c - '0'; // Convert char to int using ASCII. Will only work for numbers 0-9
        numList.push_back(num);
    }

    return numList;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;

    // Add preceding zeroes to the number with less digits
    if (num1.size() < num2.size()) {
        num1.insert(num1.begin(), num2.size() - num1.size(), 0);
    } else if (num1.size() > num2.size()) {
        num2.insert(num2.begin(), num1.size() - num2.size(), 0);
    }

    int carry = 0;

    for (auto it1 = num1.rbegin(), it2 = num2.rbegin(); it1 != num1.rend(); ++it1, ++it2) {
        int sum = *it1 + *it2 + carry;
        carry = sum / 10; // Will never be > 2 as sum is at max 18 (9+9). Will round down to fit in int (if decimal)

        result.push_front(sum % 10);
    }

    if (carry) {
        result.push_front(carry);
    }

    return result;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;

    // Add preceding zeroes to the number with less digits
    if (num1.size() < num2.size()) {
        num1.insert(num1.begin(), num2.size() - num1.size(), 0);
    } else if (num1.size() > num2.size()) {
        num2.insert(num2.begin(), num1.size() - num2.size(), 0);
    }

    int borrow = 0;

    for (auto it1 = num1.rbegin(), it2 = num2.rbegin(); it1 != num1.rend(); ++it1, ++it2) {
        int difference = *it1 - *it2 - borrow;
        borrow = (difference < 0) ? 1 : 0;

        result.push_front((difference + 10) % 10);
    }

    // Remove leading zeroes from the result
    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }

    return result;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int carry = 0;

    for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
        int product = *it * num2.front() + carry;
        carry = product / 10; // Will round down to fit in int (if decimal)
        result.push_front(product % 10);
    }

    if (carry) {
        result.push_front(carry);
    }

    return result;
}
