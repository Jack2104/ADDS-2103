#include <iostream>
#include <vector>
#include <limits>

#include "Node.h"
#include "LinkedList.h"

using namespace std;



vector<int> split_to_ints(string input,string valid) {
    size_t startPos = 0;
    size_t endPos;
    size_t subStringLength;
    vector <int> result;
    do {
        endPos = input.find_first_not_of(valid, startPos);

        // if not found in string...
        if (endPos == string::npos) {
        subStringLength = input.length();
    }
    // otherwise,
    else {
        subStringLength = endPos - startPos;
        }
        result.push_back(stoi(input.substr(startPos, subStringLength)));
        startPos = input.find_first_of(valid, endPos);
    }
    while (endPos != string::npos);
    return result;
}

int main(void) {
    // take-in inputs -- note this code assumes for a valid input format!
    string user_input;
    getline(cin, user_input);

    // cut out the numbers from user_input & place into vector of ints
    string numeric_characters = "-0123456789";
    vector<int> numeric_inputs = split_to_ints(user_input, numeric_characters);

    // copy all (but last 2) digits from vector into a c-array (to be passed into
    // LinkedList constructor)
    int array_size = numeric_inputs.size()-2;
    int * input_array = new int[array_size];

    for(unsigned int i = 0; i < (numeric_inputs.size()-2); i++) {
        input_array[i] = numeric_inputs[i];
    }
    // then, copy the last 2 digits from user_input (ie the parameters) into a
    //parameter array
    int param_array[2] = {
        numeric_inputs.at(numeric_inputs.size()-2),
        numeric_inputs.at(numeric_inputs.size()-1)
    };

    // finally, copy the letter code into a new variable
    string commandCode;

    for(unsigned int i = 0; i < user_input.length(); i++) {
        if(isalpha(user_input[i])) {
            commandCode.push_back(user_input[i]);
        }
    }

    // create list based on input data & array size
    LinkedList submissionList(input_array, array_size);

    // run function on the list depending on letter code, using the parameters
    if (commandCode == "I") {
        submissionList.insertPosition(param_array[0], param_array[1]);
    } else if (commandCode ==" D") {
        if (!submissionList.deletePosition(param_array[0])) {
            cout << "ERROR ";
        }
    } else if (commandCode == "S") {
        int got = submissionList.search(param_array[0]);
        if (got == -1) {
            cout << "ERROR ";
        } else {
            std::cout << got << " ";
        }
    } else if (commandCode == "G") {
        int got = submissionList.get(param_array[0]);

        if (got == numeric_limits<int>::max()) {
            cout << "ERROR ";
        } else {
            std::cout << got << " ";
        }
    } else {
        cout << "invalid command" << endl;
        return 0;
    }

    submissionList.printList();
    return 0;
}



/*
int main() {
    int* input_array1 = new int[4];
    input_array1[0] = 5;
    input_array1[1] = 2;
    input_array1[2] = 7;
    input_array1[3] = 10;

    LinkedList list1 = LinkedList(input_array1, 4);
    list1.insertPosition(3, 9);
    list1.printList();

    int* input_array2 = new int[4];
    input_array2[0] = 3;
    input_array2[1] = 4;
    input_array2[2] = 2;
    input_array2[3] = 1;

    LinkedList list2 = LinkedList(input_array2, 4);
    list2.deletePosition(3);
    list2.printList();

    int* input_array3 = new int[4];
    input_array3[0] = 45;
    input_array3[1] = 20;
    input_array3[2] = 2;
    input_array3[3] = 10;

    LinkedList list3 = LinkedList(input_array3, 4);
    std::cout << list3.get(5) << std::endl;
    list3.printList();

    int* input_array4 = new int[4];
    input_array4[0] = 45;
    input_array4[1] = 20;
    input_array4[2] = 2;
    input_array4[3] = 10;

    LinkedList list4 = LinkedList(input_array4, 4);
    std::cout << list4.search(200) << " ";
    list4.printList();
}
*/