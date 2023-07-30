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