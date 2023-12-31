#!/bin/sh
echo "Content-type: text/html"
echo ""
cat << 'EOF'
<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Monitor caríaco - UFABC</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-9ndCyUaIbzAi2FUVXJi0CjmCapSmO7SnpJef0486qhLnuZ2cdeRhO02iuK6FUUVM" crossorigin="anonymous">
    <link rel="stylesheet" href="styles.css">
</head>

<body>
    <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
        <div class="container">
            <a class="navbar-brand" href="#">UFABC</a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse"
                data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false"
                aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarSupportedContent">
                <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                    <li class="nav-item">
                        <a class="nav-link active" aria-current="page" href="#">Home</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link active" aria-current="page" href="#">Documentação</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="https://github.com/barbaractong/ESZB026-17-7-2022C/tree/fc-monitor">Github</a>
                    </li>
                </ul>
            </div>
        </div>
    </nav>

    <div class="container my-5">
        <div class="row">
            <div class="col-12">
                <h1>Monitor Sinais Vitais</h1>
                <p>Este projeto consiste na criação de um monitor de frequência cardíaca e oxímetro que utiliza um sistema de emissão e recepção de luz infravermelha para medir os sinais vitais do usuário de forma não invasiva. O dispositivo tem como objetivo fornecer informações precisas e em tempo real sobre a frequência cardíaca e os níveis de oxigenação do sangue, permitindo que os usuários monitorem sua saúde de maneira eficiente e conveniente.</p>
            </div>
        </div>

        <div class="row">
            <div class="col-2">
                <button type="button" class="btn btn-primary">Iniciar coleta</button>
            </div>

            <div class="col-2">
                <button type="button" class="btn btn-primary">Finalizar coleta</button>
            </div>

            <div class="col-2">
                <button type="button" class="btn btn-primary">Gerar relatório</button>
            </div>
        </div>
        <br>
        <div class="row">
            <div class="col-12">
                <h2>
                    <label for="bpm">Frequência cardíaca - BPM</label>
                </h2>
            </div>
        </div>
        <div class="mt-2 row px-0 center">
            <div class="col-2 progress-bar-container">
                <div class="progress-bar-bpm bpm">
                    <progress id="bpm" min="0" max="100" value="92"></progress>
                </div>
            </div>
            <div class="col-10">
                <canvas id="bpm-chart"></canvas>
              </div>
        </div>
        <div class="row">
            <div class="col-12">
                <h2>
                    <label for="oxigenacao">Oxigenação sanguínea</label>
                </h2>
            </div>
        </div>
        <div class="mt-2 row px-0 center">
            <div class="col-2 progress-bar-container">
                <div class="progress-bar-oxigenacao oxigenacao">
                    <progress id="oxigenacao" min="0" max="100" value="92"></progress>
                </div>
            </div>
            <div class="col-10">
                <canvas id="oxigenacao-chart"></canvas>
              </div>
        </div>
    </div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-geWF76RCwLtnZ8qwWowPQNguL3RmwHVBC9FhGdlKrxdiJJigb/j/68SIy3Te4Bkz"
        crossorigin="anonymous"></script>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <script src="./script.js"></script>
</body>
</html>
EOF