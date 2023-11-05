#include "FrameOfReference.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits>

void FrameOfReference::encode(std::string datatype,std::ifstream& input_file, std::ofstream& output_file) {
    int i = 0;
    if (datatype.compare("int32") == 0) {
        int line;
        int frame = 10;
        int type = 32;
        int special = std::numeric_limits<int>::max();
        int diff = 0;

        output_file << frame << std::endl;
        while (input_file >> line) {
            diff = line-frame;
            if (diff >= type | 0 - diff >= type) {
                output_file << special << std::endl;

                output_file << line << std::endl;
                frame = line;
            } else {
                output_file << diff << std::endl;
            }
        }
    } else if (datatype.compare("int16") == 0 | datatype.compare("int8") == 0) {
        short int line;
        short int frame = 10;
        short int type = 8;
        if (datatype.compare("int16") == 0) {
            type = 16;
        }
        short int special = std::numeric_limits<short int>::max();
        short int diff = 0;

        output_file << frame << std::endl;
        while (input_file >> line) {
            diff = line-frame;
            if (diff >= type | 0 - diff >= type) {
                output_file << special << std::endl;

                output_file << line << std::endl;
                frame = line;
            } else {
                output_file << diff << std::endl;
            }
        }
    } else if (datatype.compare("int64") == 0) {
        long int line;
        long int frame = 10;
        long int type = 128;
        long int special = std::numeric_limits<long int>::max();
        long int diff = 0;

        output_file << frame << std::endl;
        while (input_file >> line) {
            diff = line-frame;
            if (diff >= type | 0 - diff >= type) {
                output_file << special << std::endl;

                output_file << line << std::endl;
                frame = line;
            } else {
                output_file << diff << std::endl;
            }
        }
    } 
}

void FrameOfReference::decode(std::string datatype,std::ifstream& inputFile) {
    if (datatype.compare("int32") == 0) {
        int line;
        int frame = 0;
        int special = std::numeric_limits<int>::max();
        int diff = 0;

        inputFile >> line;
        frame = line;
        while (inputFile >> line) {
            if (line == special) {
                inputFile >> line;
                std::cout << line << std::endl;
                frame = line;
            } else{
                diff = line + frame;
                std::cout << diff << std::endl;
            }
        }
    } else if (datatype.compare("int16") == 0 | datatype.compare("int8") == 0 ) {
        short int line;
        short int frame = 0;
        short int special = std::numeric_limits<short int>::max();
        short int diff = 0;

        inputFile >> line;
        frame = line;
        while (inputFile >> line) {
            if (line == special) {
                inputFile >> line;
                std::cout << line << std::endl;
                frame = line;
            } else{
                diff = line + frame;
                std::cout << diff << std::endl;
            }
        }
    } else if (datatype.compare("int64") == 0) {
        long int line;
        long int frame = 0;
        long int special = std::numeric_limits<long int>::max();
        long int diff = 0;

        inputFile >> line;
        frame = line;
        while (inputFile >> line) {
            if (line == special) {
                inputFile >> line;
                std::cout << line << std::endl;
                frame = line;
            } else{
                diff = line + frame;
                std::cout << diff << std::endl;
            }
        }
    } 
}