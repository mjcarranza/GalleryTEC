#include "CompressionAlgorithm.h"

CompressionAlgorithm::CompressionAlgorithm(){}
/**
 * Estructura Nodo
 */
struct Node{
    int index;
    string data;
    Node *next;
};
/**
 * Función para crear nodo
 * @param head
 * @param index
 * @param data
 */
void st_Node(Node *head, int index, string data){
    head->index = index;
    head->data = data;
    head->next = nullptr;
}
/**
 * Función para insertar un nodo
 * @param head
 * @param index
 * @param data
 */
void insert_Node(Node *head, int index, string data){
    Node *new_Node = new Node;
    new_Node->index = index;
    new_Node->data = data;
    new_Node->next = nullptr;

    Node *curr = head;
    while (curr != nullptr)
    {
        if (curr->next == nullptr)
        {
            curr->next = new_Node;
            return;
        }
        curr = curr->next;
    }
}
/**
 * Función para buscar un nodo
 * @param head
 * @param data
 * @return
 */
Node *search_Node(Node *head, string data)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        if (data.compare(curr->data) == 0)
            return curr;
        else
            curr = curr->next;
    }
    return nullptr;
}
/**
 * Función para buscar un nodo
 * @param head
 * @param index
 * @return
 */
Node *search_Node(Node *head, int index)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        if (index == curr->index)
            return curr;
        else
            curr = curr->next;
    }
    return nullptr;
}
/**
 * Función para separar las cadenas para codificar en LZ78
 * @param str
 * @param delimiter
 * @return
 */
vector <string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while (getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}
/**
 * Función para la compresión de datos
 * @param input Entrada de datos como cadena de texto
 * @return Retorna los datos descomprimidos en formato LZ78
 */
string CompressionAlgorithm::LZ78Compress(string input){
    Node *dictionary = new Node;
    string word, result;
    int length, last_seen, index = 1;

    length = (int)input.length();
    word = input[0];
    st_Node(dictionary, 1, word);
    result += "0," + word;

    for (int i = 1; i < length; i++)
    {
        string data;
        data = input[i];

        re_check:
        Node *search = search_Node(dictionary, data);

        if (search)
        {
            i++;
            data += input[i];
            last_seen = search->index;
            goto re_check;
        }
        else
        {
            char zero;
            if (input[i] == ' ')
                zero = '0';
            else
                zero = input[i];

            if ((int)data.length() < 2)
                result += " " + to_string(0) + "," + zero;
            else
                result += " " + to_string(last_seen) + "," + zero;

            index++;
            if (i != length)
                insert_Node(dictionary, index, data);
        }
    }

    return result;
}
/**
 * Función para la descompresión de datos
 * @param input Entrada de datos como cadena de texto
 * @return Retorna los datos descomprimidos en formato LZ78
 */
string CompressionAlgorithm::LZ78Decompress(string input){
    Node *dictionary = new Node;
    string result;

    vector <string> s_input = split(input, ' ');
    int zz = 2;
    for (int i = 0; i < s_input.size(); i++)
    {
        vector <string> ss_input = split(s_input[i], ',');

        if (i == 0)
        {
            st_Node(dictionary, 1, ss_input[1]);
            result += ss_input[1];
        }
        else
        {
            Node *serched;
            string get_search = ss_input[1];
            serched = search_Node(dictionary, stoi(ss_input[0]));
            if (serched)
            {
                result += serched->data + get_search;
                get_search = serched->data + split(s_input[i], ',')[1];
                insert_Node(dictionary, zz, get_search);
            }
            else
            {
                if (stoi(ss_input[0]) == 0)
                    insert_Node(dictionary, zz, get_search);
                else
                    insert_Node(dictionary, zz, get_search);

                result += get_search;
            }
            zz++;
        }
    }

    if (result[(int)result.length() - 1] == '0')
        result = result.substr(0, result.size() - 1);

    return result;
}