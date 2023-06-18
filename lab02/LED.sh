#!/bin/bash

# script baseado no código disponibilizado em:
# Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
# Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/

# Usar uma variavel facilita alteracoes futuras na porta usada

# Barbara Tong

# Definindo as portas
LED_GPIO_AMARELO=16 
LED_GPIO_VERMELHO=20 
LED_GPIO_VERDE=21

# funcoes Bash
function setLED
{                                      
	echo $1 >> "/sys/class/gpio/gpio$LED_GPIO_AMARELO/value" # $1 eh o primeiro argumento passado para a funcao
	echo $2 >> "/sys/class/gpio/gpio$LED_GPIO_VERMELHO/value" # $2 eh o segundo argumento passado para a funcao
	echo $3 >> "/sys/class/gpio/gpio$LED_GPIO_VERDE/value" # $3 eh o segundo argumento passado para a funcao
}

# Inicio do programa
if [ $# -ne 1 ]; then                  # se nao houver exatamente um argumento passado ao programa
	echo "Nenhum comando passado. Uso: ./LED.sh command,"
	echo "onde comando pode ser: setup, on, off, status e close"
	echo -e " ex.: ./LED.sh setup, e em seguinda, ./LED.sh on"
	exit 2                         # erro que indica numero invalido de argumentos
fi

# echo "Os comandos passados foram: $1 $2 $3"

# Criando o export para os leds
echo "Habilitando a GPIO numero $LED_GPIO_AMARELO"
echo $LED_GPIO_AMARELO >> "/sys/class/gpio$LED_GPIO_AMARELO/export"
sleep 1 # esperar 1 segundo para garantir que a gpio foi exportada

echo "Habilitando a GPIO numero $LED_GPIO_VERMELHO"
echo $LED_GPIO_VERMELHO >> "/sys/class/gpio$LED_GPIO_VERMELHO/export"
sleep 1 # esperar 1 segundo para garantir que a gpio foi exportada

echo "Habilitando a GPIO numero $LED_GPIO_VERDE"
echo $LED_GPIO_VERDE >> "/sys/class/gpio$LED_GPIO_VERDE/export"
sleep 1 # esperar 1 segundo para garantir que a gpio foi exportada


#  Contador para o while
counter = 0

while [$counter -le 5];
	do
		# Ligando os leds na ordem 
		setLED 2 # Led vermelho on
		sleep 2
		setLED 0

		setLED 3 # Led verde on
		sleep 1
		setLED 0

		setLED 1 # Led amarelo on
		sleep 1
		setLED 0

		echo "Contador: $counter";

		counter++
	done

# finalizando o programa
echo "Desabilitando a GPIO numero $LED_GPIO_AMARELO"
echo $LED_GPIO_AMARELO >> "/sys/class/gpio$LED_GPIO_AMARELO/unexport"
sleep 1 # para garantir q vai fazer o unexport
echo "Desabilitando a GPIO numero $LED_GPIO_VERMELHO"
echo $LED_GPIO_VERMELHO >> "/sys/class/gpio$LED_GPIO_VERMELHO/unexport"
sleep 1 # para garantir q vai fazer o unexport
echo "Desabilitando a GPIO numero $LED_GPIO_VERDE"
echo $LED_GPIO_VERDE >> "/sys/class/gpio$LED_GPIO_VERDE/unexport"
sleep 1

echo "Programa finalizado."