//set property: 

document.documentElement.style
    .setProperty('--progress-value-bpm', 65);

//get property

getComputedStyle(document.documentElement)
    .getPropertyValue('--my-variable-name'); // returns value

  