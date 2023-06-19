// Barbara Tong

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

// cria funcao que escreve o valor 0 ou 1 no arquivo de cada led
void writeGPIO(char filename[], char value[])
{
    FILE *fp;                   // cria um ponteiro fp
    fp = fopen(filename, "w+"); // abre o arquivo para escrita
    fprintf(fp, "%s", value);   // grava o valor no arquivo
    fclose(fp);                 // fecha o arquivo
}

int main(int argc, char *argv[])
{
//contador
    int counter = 0 printf("Habilitando a gpio\n");

//criando o export para cada entrada do gpio
    writeGPIO(GPIO_SYSFS_AMARELO "export", GPIO_AMARELO);
    usleep(100000); // aguarda 100ms
    writeGPIO(GPIO_PATH_AMARELO "direction", "out");
    usleep(100000); // aguarda 100ms

    writeGPIO(GPIO_SYSFS_VERMELHO "export", GPIO_VERMELHO);
    usleep(100000); // aguarda 100ms
    writeGPIO(GPIO_PATH_VERMELHO "direction", "out");
    usleep(100000); // aguarda 100ms

    writeGPIO(GPIO_SYSFS_VERDE "export", GPIO_VERDE);
    usleep(100000); // aguarda 100ms
    writeGPIO(GPIO_PATH_VERDE "direction", "out");
    usleep(100000); // aguarda 100ms

    while (counter <= 5)
    {

        printf("Acendendo o LED Vermelho\n");
        writeGPIO(GPIO_PATH_VERMELHO "value", "1");
        sleep(2); // aguarda 2 segundos
        writeGPIO(GPIO_PATH_VERMELHO "value", "0");

        printf("Acendendo o LED Amarelo\n");
        writeGPIO(GPIO_PATH_AMARELO "value", "1");
        sleep(1); // aguarda 1 segundos
        writeGPIO(GPIO_PATH_AMARELO "value", "0");

        printf("Acendendo o LED Verde\n");
        writeGPIO(GPIO_PATH_VERDE "value", "1");
        sleep(1); // aguarda 1 segundos
        writeGPIO(GPIO_PATH_VERDE "value", "0");

        counter++
    }
    writeGPIO(GPIO_SYSFS_VERMELHO "unexport", GPIO_VERMELHO);
    writeGPIO(GPIO_SYSFS_AMARELO "unexport", GPIO_AMARELO);
    writeGPIO(GPIO_SYSFS_VERDE "unexport", GPIO_VERDE);

    return 0;
}
