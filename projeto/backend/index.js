const { SerialPort, ReadlineParser } = require('serialport')

const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 7071 });


// Create a port
const arduino = new SerialPort({
    path: 'COM3',
    baudRate: 9600,
  })
  
const parser = new ReadlineParser()

arduino.pipe(parser)

wss.on('connection', function connection(ws) {
    console.log('Client connected')
 
    ws.on("close", () => {
        console.log("Client disconnected");
    });
    ws.onerror = function () {
        console.log("Some Error occurred");
    }
    
    ws.on("message", (msg) => {
        var buf = Buffer.from(msg);
        console.log(buf.toString());
    });

    parser.on("data", (line) => {
        ws.send(line)
        console.log(line)
    })
});







