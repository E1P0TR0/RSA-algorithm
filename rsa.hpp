#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>

class RSA
{
    private:
    //Variables
        int p; // p
        int q; // q
        int x; // n
        int y; // o(n)
        int e; // ! 1 < e < y 
        int d; // d
        std::string msg; // mensaje ingresado
        std::string msg_encrypt_s; // mensaje encriptado string
        std::vector<int> msg_encrypt; // mensaje encriptado
        std::string msg_decrypt; // mensaje desencriptado
    public:
    //Constructor
        RSA()                               // Proceso y calculo de algoritmo RSA
        { 
            srand(time(NULL));
            msg = "";
            msg_encrypt = {};
            msg_decrypt = "";
            msg_encrypt_s = "";
            p == q == x == y == e == d == 0;
            //TODO : EN FUNCIONES APARTE
            // while(_n <= 126)                                // Se evalua que el producto de primos sea mayor 
            // {                                               // para reglas del algoritmo
            //     set_p(get_prime()); 
            //     set_q(get_prime());
            //     _n = p * q;
            // }
            // set_x(); 
            // set_y();
            // set_e(get_coprime());
            // set_d(get_d());
        }
    //Funciones
        bool is_prime(int n)                                // validar primo
        {
            if(n <= 1)
                return false;
            for(int i = 2; i < n / 2; i++)
                if(n % i == 0)
                    return false;
            return true;
        }
        int get_prime()                                     // retorna primo de x - y rango
        {
            int r;
            while(1)
            {
                r = rand() % 100 + 1;// * 1- 100;
                if(is_prime(r) && r != p)
                    return r;
            }
        }
        int mcd(int _n1, int _n2)                           // calcula el mcd de dos números
        {
            if (_n2 == 0) 
                return _n1;
            return mcd(_n2, _n1 % _n2);
        }
        int get_coprime()                                   // valida y retorna coprimo de 0(n) 
        {
            for(int i = 2;; i++)
            {
                if(is_prime(i))
                    if(mcd(i, y) == 1)
                        return i;
                continue;
            }
        }   
        int ret_d()                                         // calculo de variable d,  Extended Euclidean Algorithm
        {
            int _i = 0;
            double _d = 0.0;
            for(int i = 1; ; i++)
            {
                _d = ((y * i) + 1) / (double)e;
                _i = ((y * i) + 1) / e;
                if((_d - _i) == 0)
                    return _i;
            }
        }
    // Proceso RSA //? PODEMOS METER TODAS ESTAS FUNC A ENCRIPTAR (OPC)
        void generate_primes() // 1
        {
            int _n = 0;
            while(_n <= 126)                                // Se evalua que el producto de primos sea mayor 
            {                                               // para reglas del algoritmo
                set_p(get_prime()); 
                set_q(get_prime());
                _n = p * q;
            } 
        }
        void generate_x() { x = p * q; } // 2
        void generate_y() { y = (p - 1) * (q - 1); } // 3
        void genetare_e() { set_e(get_coprime()); } // 4
        void generate_d() { set_d(ret_d()); } // 5
    // Importantes
        int do_pow(int _l, int _e, int _n)                  // calculo de potencia y modulo para las llaves
        {
            int r = 1;
            while(--_e >= 0)
            {
                r *= _l;    
                r %= _n;
            }
            return r;
        }
        void encrypt()                                      // encriptación con llave pública
        {
            for(auto &letter : msg)
                msg_encrypt.push_back(do_pow((int)letter, e, x));
        }
        void decrypt()                                      // desencriptación con llave privada
        {
            for(auto &letter : msg_encrypt)
                msg_decrypt.push_back(do_pow((int)letter, d, x));
        }
    //Setters and getters
        void set_msg(std::string _msg) { msg = _msg; }
        void set_msg_encrypt(std::vector<int> _msg) { msg_encrypt = _msg; }
        void set_p(int _p) { p = _p; }
        void set_q(int _q) { q = _q; }
        void set_x(int _x) { x = _x; } // n                    
        void set_y(int _y) { y = _y; } // o(n)
        void set_e(int _e) { e = _e; }
        void set_d(int _d) { d = _d; }
    //Impresion de datos
        void print_values() 
        {
            std::cout << "\np-> " << p;
            std::cout << "\nq-> " << q;
            std::cout << "\nn-> " << x;
            std::cout << "\no(n)-> " << y;
            std::cout << "\ne-> " << e;
            std::cout << "\nd-> " << d;
        }
        void print_keys()
        {
            std::cout << "\nLlave publica : (" << x << ", " << e << ")";
            std::cout << "\nLlave privada : (" << x << ", " << d << ")";
        }
    // retorno de valores necesarios
        std::string get_msgOriginal() const { return msg; }
        std::string get_msgEncrypt()
        {
            for(auto v : msg_encrypt)
            {
                msg_encrypt_s += std::to_string(v);
                msg_encrypt_s.push_back('-');
            }
            msg_encrypt_s.pop_back();
            return msg_encrypt_s;
        }
        std::string get_msgDecrypt() const { return msg_decrypt; }
        int get_n() const { return x; }
        int get_d() const { return d; } //!

    //! LECTURA APARTE DE ARCHIVO
    void set_msgAndPKey(std::string line)
    {
        std::string number;
        std::stringstream ss(line);
        std::vector<int> _msg_encrypt{};
        while(std::getline(ss, number, '-')) //* read encrypt and keys
            _msg_encrypt.push_back(std::stoi(number));
        set_d(_msg_encrypt[_msg_encrypt.size() - 1]);
        _msg_encrypt.pop_back();
        set_x(_msg_encrypt[_msg_encrypt.size() - 1]);
        _msg_encrypt.pop_back();
        set_msg_encrypt(_msg_encrypt);
    }

    //* publica (n,e) ENCRIPTAR ->  M^e mod n
    //* privada (n,d) DESENCRIPTAR -> M^d mod n

    //? TABLAS ASCII
    //! N >= 126
};

// TODO: LEER ARCHIVO
/*#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

void main()
{
    FILE* archivo;//tipo de dato FILE
    long medida;//tamanio del archivo
    char* texto;//donde van las palabras
    string nombrearchivo;
    cout << "Ingrese el nombre del documento con la extension.txt"; cin >> nombrearchivo;
    archivo = fopen(nombrearchivo, "r");  //Aqui abrimos el archivo documento.txt .
    // Las siguientes tres lineas nos permiten conocer la cantidad de texto
    // que tiene el archivo y guardamos este dato en la variable "medida"
    // este dato se necesita para la funcion fread
    fseek(archivo, 0, SEEK_END);
    medida = ftell(archivo);
    rewind(archivo);
    // La siguiente linea asigna de forma automatica la memoria del archivo completo
    texto = (char*)malloc(sizeof(char) * medida);
    // Ahora por fin almacenamos el texto del archivo en la variable texto
    fread(texto, medida + 1, 1, archivo);
    fclose(archivo); // Cerramos el archivo y se libera la memoria
    system("pause");
    return 0;
}*/