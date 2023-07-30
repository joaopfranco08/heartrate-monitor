function randomBeatValue() {
    return new Promise((resolve) => {
        let t = Math.floor(Math.random() * (100 - 1 + 1)) + 1
        setTimeout(() => console.log(t), 2000);
    });
}
async function process(arrayOfPromises) {
    console.time(`process`);
    let responses = await Promise.all(arrayOfPromises);
    for (let r of responses) { }
    console.timeEnd(`process`);
    return;
}
async function handler() {
    let arrayOfPromises = [
        randomBeatValue(),
        randomBeatValue(),
        randomBeatValue(),
        randomBeatValue(),
        randomBeatValue(),
    ];

    await process(arrayOfPromises);
    console.log(`processing is complete`);
}
handler();