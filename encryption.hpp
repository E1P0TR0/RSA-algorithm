#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <iostream>

class Encryption
{
    private:
        std::string message;
        std::string encryptMessage;
        std::string privateKey;
        int shift;
    public:
        Encryption(std::string _msg, std::string _pkey) : message(_msg), privateKey(_pkey) {} 
        // Encryption(std::string _msg, int _shift) : message(_msg), shift(_shift) { encryptMessage = ""; } 

        void caesarCipher() 
        {
            for(auto &letter : message)
            {
                if(isupper(letter))
                    encryptMessage += char(int(letter - 65 + shift) % 26 + 65);
                else    
                    encryptMessage += char(int(letter - 97 + shift) % 26 + 97);
            }
        }
        // setters and getters
        std::string get_message() const { return message; } 
        std::string get_encryptMessage() const { return encryptMessage; }
        //bool validKey()
};

#endif /*ENCRYPTION_HPP*/