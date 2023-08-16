const { SerialPort, ReadlineParser } = require('serialport')

const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 7071 });


wss.on('connection', function connection(ws) {
    ws.on("close", () => {
        console.log("Client disconnected");
    });
    ws.onerror = function () {
        console.log("Some Error occurred");
    }
});


// Create a port
const arduino = new SerialPort({
  path: 'COM3',
  baudRate: 9600,
})

const parser = new ReadlineParser()

arduino.pipe(parser)

parser.on("data", (line) => {
    console.log(line)
})
