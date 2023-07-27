#!/bin/bash
ARQUIVODADOS1=/home/pi/ESZB026-17-7-2022C/lab07/dados_1.txt
ARQUIVODADOS2=/home/pi/ESZB026-17-7-2022C/lab07/dados_2.txt
ARQUIVODADOS=/home/pi/ESZB026-17-7-2022C/lab07/dados.txt
echo "Content-type: text/html"
echo ""
echo '<HTML><HEAD><meta charset="UTF-8">'
echo '<TITLE>Pagina CGI gerando figura</TITLE></HEAD>'
echo '<BODY style="background-color:#FFFFE0"><H1>Página teste CGI e figuras.</H1>'
echo 'Estou no diretório '
echo ', logado como o usuário '
echo '.<br>'
echo '<h2>DADOS:</h2>'
echo '<pre>'
cat $ARQUIVODADOS
echo '</pre>'
echo '<br>'
echo '<br>'
echo '<h2>IMAGENS:</h2>'
echo 'Referenciando a imagem como "/cgi-bin/imagem.cgi":<br>'
echo '<img src="/cgi-bin/imagem.cgi">'
echo '<br>'
echo '.<br>'
echo '<h2>DADOS:</h2>'
echo '<pre>'
cat $ARQUIVODADOS1
echo '</pre>'
echo '<br>'
echo '<br>'
echo '<h2>IMAGENS:</h2>'
echo 'Referenciando a imagem como "/cgi-bin/imagem.cgi":<br>'
echo '<img src="/cgi-bin/imagem_1.cgi">'
echo '<br>'
echo 'Referenciando a imagem como "imagem.cgi":<br>'
echo '<br>'
echo '<h2>DADOS:</h2>'
echo '<pre>'
cat $ARQUIVODADOS2
echo '</pre>'
echo '<br>'
echo '<br>'
echo '<h2>IMAGENS:</h2>'
echo 'Referenciando a imagem como "/cgi-bin/imagem.cgi":<br>'
echo '<img src="/cgi-bin/imagem_2.cgi">'
echo '<br>'
echo '</HTML>'

