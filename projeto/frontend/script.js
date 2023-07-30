//set property:


document.documentElement.style
    .setProperty('--oxigenacao-value', 98);

//get property

getComputedStyle(document.documentElement)
    .getPropertyValue('--bpm-value'); // returns value

const canvas = document.getElementById('myChart');
canvas.height = 75;

const labels = [
    ' ',
    ' ',
    ' ',
    ' ',
];

const data = {
    labels: labels,
    datasets: [{
        label: 'Test',
        backgroundColor: 'rgb(255, 99, 132)',
        borderColor: 'rgb(255, 99, 132)',
        data: [0, 10, 5, 4],
    }]
};

const config = {
    type: 'line',
    data: data,
    options: {pointStyle: false}
};

const myChart = new Chart(
    canvas,
    config
);

// function to update the chart 
function addData(chart, label, data) {
    chart.data.labels.push(label);
    chart.data.datasets.forEach((dataset) => {
        dataset.data.push(data);
    });
    chart.update();
}

// random bpm value generator
function randomBeatValue() {
    return new Promise((resolve) => {
        let t = Math.floor(Math.random() * (100 - 1 + 1)) + 1
        setTimeout(() => resolve(t), 2000);
    });
}

// randomly add new data
setInterval(async function () {
    const newLabel = ' '//(Math.random() + 1).toString(36).substring(7);
    const newData = await randomBeatValue();

    document.documentElement.style
    .setProperty('--bpm-value', newData);
    addData(myChart, newLabel, newData);

}, 100);
