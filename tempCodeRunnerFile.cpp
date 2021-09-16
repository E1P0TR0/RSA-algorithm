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