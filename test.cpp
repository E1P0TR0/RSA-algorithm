#include <iostream>
#include <time.h>
#include "rsa.hpp"
#include  "file.hpp"


int main()
{
    // Encryption e("MENSAJE", 3);
    // e.encrypt();
    // std::cout << "Mensaje: " << e.get_message() << std::endl;
    // std::cout << "Mensaje encriptado: " << e.get_encryptMessage();
    
    srand(time(NULL));
    // RSA r("Bienvenidos");
    // r.get_values();
    // r.get_msgOriginal();
    // r.get_msgEncrypt();
    // r.get_msgDecrypt();
    // r.get_Keys();
    
    //* encripta y escribe en el archivo la llave privada
    File f("file_2.txt");
    std::string s = f.read_file();

    RSA rsa; 
    rsa.set_msg(s);
    rsa.generate_primes();
    rsa.generate_x();
    rsa.generate_y();
    rsa.genetare_e();
    rsa.generate_d();
    rsa.encrypt();
    f.write_file(rsa.get_msgEncrypt(), rsa.get_n(), rsa.get_d());
    
    // //* proceso inverso
    // File f("file_2.txt");
    // std::string s = f.read_file();
    // // 481-173

    // int _x = 481, _d = 173;
    // RSA rsa;
    // rsa.set_msgAndPKey(s);
    // if(_x == rsa.get_n() && _d == rsa.get_d())
    // {
    //     rsa.decrypt();
    //     std::cout << rsa.get_msgDecrypt();
    // }
    // else
    //     std::cout << "Llave incorrecta!\n";

    //! tiles, ñ, apostrofe(’)

    // TODO: REVISAR FUNC. Y SUSPUESTO ERRORES

    return 0;
}

