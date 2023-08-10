# -*- coding:utf-8 -*- 
#sistemas embarcados biomed grupo 7
import serial
import time
import os




# inicar server
# exibir template
# ler arduino
def ler_gravar(port = "COM3", baud_rate = 115200,nome_arquivo "arquivo.txt"):
	ser = serial.Serial (port, baud_rate)

	try: 
		with open (nome_arquivo, 'w') as arquivo_saida: #criar txt
		while True: # loop leitura serial
			if ser.in_waiting > 0 : 
				dados_recebidos = ser.readline().decode('utf-8').strip()
				
				# gravar arquivo de texto
				arquivo_saida.write(f"{dados_recebidos}\n")
				arquivo_saida.flush()
				
				
				time.sleep(0.1) # tempo evitar overwrite

	raise Exception ("erro no arquivo ou serial")
		




