#ifndef LZ78_COMPRESSIONALGORITHM_H
#define LZ78_COMPRESSIONALGORITHM_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/**
 * Clase para Compresion de datos utilizando el algoritmo LZ78
 */
class CompressionAlgorithm {
public:
    // Constructor
    CompressionAlgorithm();
    // Métodos
    string LZ78Compress(string input);
    string LZ78Decompress(string input);
};


#endif //LZ78_COMPRESSIONALGORITHM_H
