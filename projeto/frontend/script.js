var hostURL = "ws://localhost:7071";
webSocket = new WebSocket(hostURL);

const labels = [
    ' ',
    ' ',
    ' ',
    ' ',
];

const labels2 = [
    ' ',
    ' ',
    ' ',
    ' ',
];

const dataBpm = {
    labels: labels,
    datasets: [{
        label: 'bpm',
        backgroundColor: 'rgb(255, 99, 132)',
        borderColor: 'rgb(255, 99, 132)',
        data: [0, 0, 0, 0],
        fill: false
    }]
};

const dataOxigen = {
    labels: labels2,
    datasets: [{
        label: '% Oxigênio',
        backgroundColor: 'rgb(75, 192, 192)',
        borderColor: 'rgb(75, 192, 192)',
        data: [0, 0, 0, 0],
        fill: false
    }]
};

const configBpm = {
    type: 'line',
    data: dataBpm,
    options: {pointStyle: false}
};

const configOx = {
    type: 'line',
    data: dataOxigen,
    options: {pointStyle: false}
};

const updateChartData = async(chart, value, label, range) => {
    await range(value)
    document.documentElement.style
    .setProperty('--bpm-value', value);
        document.documentElement.style
    .setProperty('--bpm-value', value);
    chart.updateData(label, value)
}

// random bpm value generator
function randomBeatValue() {
    return new Promise((resolve) => {
        let t = Math.floor(Math.random() * (100 - 1 + 1)) + 1
        setTimeout(() => resolve(t), 2000);
    });
}

function checkHeartBeatRange(bpm) {
    return new Promise((resolve) => {
        if (bpm < 50) {
            resolve(document.documentElement.style
                .setProperty('--bpm-flag', 'green'));
        } else {
            resolve(document.documentElement.style
                .setProperty('--bpm-flag', 'red'));
        }
    })
}


class RealTimeChart {
    constructor(elementId, chartLabels, chartData, chartConfig) {

        this.canvas = document.getElementById(elementId);
    
        this.labels = chartLabels;

        this.data = chartData;

        this.config = chartConfig;

        this.canvas.height = 75;

        this.chart = new Chart(
            this.canvas,
            this.config
        );

    }

    getChart() {
        return this.chart;
    }

    updateData(label, data) {
        this.chart.data.labels.push(label);
        this.chart.data.datasets.forEach((dataset) => {
            dataset.data.push(data);
        });
        this.chart.update();
    }
}

// const oxChart= new RealTimeChart('oxigenacao-chart', ['', '', ''], dataOxigen, configOx)

const bpmChart= new RealTimeChart('bpm-chart', ['', '', ''], dataBpm, configBpm)
// randomly add new data


webSocket.onopen = function(){}
webSocket.onmessage = function(msg){
    updateChartData(bpmChart, msg.data,' ',checkHeartBeatRange)
    console.log(msg.data)
}
webSocket.onclose = function(){}


// randomly add new data

