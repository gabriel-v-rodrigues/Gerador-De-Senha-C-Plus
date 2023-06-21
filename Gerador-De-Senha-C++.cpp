#include <iostream>
#include <string>
#include <random>

std::string GeneratePassword(int passwordLength)
{
    const std::string allowedCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*?+-";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, allowedCharacters.length() - 1);

    std::string password;
    for (int i = 0; i < passwordLength; i++)
    {
        password += allowedCharacters[distribution(generator)];
    }

    return password;
}

int main()
{
    std::cout << "Quantos caracteres deseja em sua senha? : ";

    int passwordLength;
    std::cin >> passwordLength;

    std::string password = GeneratePassword(passwordLength);

    std::cout << "Senha gerada: " << std::endl << password << std::endl;

    system("pause");

    return 0;
}