#!/usr/bin/python3

# script baseado no codigo disponibilizado em:
# Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
# Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/

import sys
from time import sleep

LED_NUMBER_VERMELHO = "20"
LED_PATH_VERMELHO = f"/sys/class/gpio/gpio{LED_NUMBER_VERMELHO}/"

LED_NUMBER_AMARELO = "16"
LED_PATH_AMARELO = f"/sys/class/gpio/gpio{LED_NUMBER_AMARELO}/"

LED_NUMBER_VERDE = "21"
LED_PATH_VERDE = f"/sys/class/gpio/gpio{LED_NUMBER_VERDE}/"

SYSFS_DIR = "/sys/class/gpio/"

contador = 0

def writeLED ( filename, value, path ):
        "Esta funcao escreve o valor 'value' no arquivo 'path+filename'"
        fo = open( path + filename,"w")
        fo.write(value)
        fo.close()
        return

print("Habilitando a gpio")
#HABILITA GPIO VERMELHO
writeLED (filename="export", value=LED_NUMBER_VERMELHO, path=SYSFS_DIR)
writeLED (filename="export", value=LED_NUMBER_AMARELO, path=SYSFS_DIR)
writeLED (filename="export", value=LED_NUMBER_VERDE, path=SYSFS_DIR)
sleep(0.1)
writeLED (filename="direction", value="out", path = LED_PATH_VERMELHO)
writeLED (filename="direction", value="out", path = LED_PATH_AMARELO)
writeLED (filename="direction", value="out", path = LED_PATH_VERDE)

while contador <= 5:
	# LIGA LED VERMELHO
	writeLED (filename=f"value", value="1", path = LED_PATH_VERMELHO)
	sleep(2)
	writeLED (filename=f"value", value="0", path = LED_PATH_VERMELHO)

#
	# LIGA LED AMARELO
	writeLED (filename=f"value", value="1", path = LED_PATH_AMARELO)
	sleep(1)
	writeLED (filename=f"value", value="0", path = LED_PATH_AMARELO)

	# LIGA LED VERDE
	writeLED (filename=f"value", value="1", path = LED_PATH_VERDE)
	sleep(1)
	writeLED (filename=f"value", value="0", path = LED_PATH_VERDE)

	contador += 1

writeLED (filename="unexport", value=LED_NUMBER_VERMELHO, path=SYSFS_DIR)
writeLED (filename="unexport", value=LED_NUMBER_AMARELO, path=SYSFS_DIR)
writeLED (filename="unexport", value=LED_NUMBER_VERDE, path=SYSFS_DIR)

