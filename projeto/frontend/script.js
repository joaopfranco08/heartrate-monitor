//set property: 

document.documentElement.style
    .setProperty('--bpm-value', 65);

document.documentElement.style
    .setProperty('--oxigenacao-value', 98);

//get property

getComputedStyle(document.documentElement)
    .getPropertyValue('--bpm-value'); // returns value

