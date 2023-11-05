#include "runlength.h"
#include <iostream>
#include <cstdint>
#include <fstream>
#include <string> 
#include <sstream>

RunLengthCompression::RunLengthCompression()
{
    // std::cout << "RunLengthCompression object made" << std::endl;
}


void RunLengthCompression::encode(const std::string data_type, std::ifstream& input_file, std::ofstream& output_file)
{
    // TODO: Write function
    if (data_type == "string") 
    {
        // encode_string (input_file, output_file);
    }
    else if (data_type == "int8" || data_type == "int16" || data_type == "int32" || data_type == "int64") 
    {
        // encode_int (data_type, input_file, output_file);
    }

    // String encoding
}

// void RunLengthCompression::decode()
// {
//     // TODO: Write function
// }

//  HELPER FUNCTIONS`
void RunLengthCompression::encode_string(std::ifstream &input_file, std::ofstream &output_file)
{

}

void RunLengthCompression::encode_int(const std::string data_type, std::ifstream &input_file, std::ofstream &output_file)
{

}
