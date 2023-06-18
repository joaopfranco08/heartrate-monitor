// Barbara Tong
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

// define variaveis para os leds
#define GPIO_AMARELO "16"
#define GPIO_PATH_AMARELO "/sys/class/gpio/gpio16/"
#define GPIO_SYSFS_AMARELO "/sys/class/gpio/"

#define GPIO_VERMELHO "20"
#define GPIO_PATH_VERMELHO "/sys/class/gpio/gpio20/"
#define GPIO_SYSFS_VERMELHO "/sys/class/gpio/"

#define GPIO_VERDE "21"
#define GPIO_PATH_VERDE "/sys/class/gpio/gpio21/"
#define GPIO_SYSFS_VERDE "/sys/class/gpio/"

// define funcao que escreve 0 ou 1 para ligar o led
void writeGPIO(string path, string filename, string value)
{
    fstream fs;
    fs.open((path + filename).c_str(), fstream::out);
    fs << value;
    fs.close();
}

int main(int argc, char *argv[])
{
    // contador
    int counter = 0

    cout << "Habilitando a gpio" << endl;
    writeGPIO(string(GPIO_SYSFS_AMARELO), "export", GPIO_AMARELO);
    usleep(100000);
    writeGPIO(string(GPIO_PATH_AMARELO), "direction", "out");

    writeGPIO(string(GPIO_SYSFS_VERMELHO), "export", GPIO_VERMELHO);
    usleep(100000);
    writeGPIO(string(GPIO_PATH_VERMELHO), "direction", "out");

    writeGPIO(string(GPIO_SYSFS_VERDE), "export", GPIO_VERDE);
    usleep(100000);
    writeGPIO(string(GPIO_PATH_VERDE), "direction", "out");

    while (counter <= 5)
    {
        cout << "Acendendo o LED Vermelho" << endl;
        writeGPIO(string(GPIO_PATH_VERMELHO), "value", "1");
        sleep(2)
        writeGPIO(string(GPIO_PATH_VERMELHO), "value", "0");

        cout << "Acendendo o LED Amarelo" << endl;
        writeGPIO(string(GPIO_PATH_AMARELO), "value", "1");
        sleep(1)
        writeGPIO(string(GPIO_PATH_AMARELO), "value", "0");

        cout << "Acendendo o LED Verde" << endl;
        writeGPIO(string(GPIO_PATH_VERDE), "value", "1");
        sleep(1)
        writeGPIO(string(GPIO_PATH_VERDE), "value", "0");

        counter++
    }

    writeGPIO(string(GPIO_SYSFS_AMARELO), "unexport", GPIO_AMARELO);
    writeGPIO(string(GPIO_SYSFS_VERMELHO), "unexport", GPIO_VERMELHO);
    writeGPIO(string(GPIO_SYSFS_VERDE), "unexport", GPIO_VERDE);
    
    return 0;
}