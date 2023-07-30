function setCanvas(elementId, chartLabels, chartData, chartConfig) {
    const canvas = document.getElementById(elementId);
    canvas.height = 75;

    const labels = chartLabels;

    const data = chartData;

    const config = chartConfig;

    const chart = new Chart(
        canvas,
        config
    );

    function updateData(chart, label, data) {
        chart.data.labels.push(label);
        chart.data.datasets.forEach((dataset) => {
            dataset.data.push(data);
        });
        chart.update();
    }

}

class RealTimeChart {
    constructor(elementId, chartLabels, chartData, chartConfig) {

        this.canvas = document.getElementById(elementId);
    
        this.labels = chartLabels;

        this.data = chartData;

        this.config = chartConfig;

        this.canvas.height = 75;

    }

    setChart() {
        return new Chart(
            this.canvas,
            this.config
        );
    }

    updateData(chart) {
        chart.data.labels.push(label);
        chart.data.datasets.forEach((dataset) => {
            dataset.data.push(data);
        });
        chart.update();
    }
}