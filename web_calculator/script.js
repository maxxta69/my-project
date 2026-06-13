function appendToDisplay(value) {
    const display = document.getElementById('display');
    display.value += value;
}
 
function clearDisplay() {
    const display = document.getElementById('display');
    display.value = '';
}

function calculate(){
    const display = document.getElementById('display');
    try {
        // const expression = display.value;
        const calc = (expression) => {
            return new Function(`return ${expression}`)();
        };
        const result = calc(display.value);
        display.value = result;
    } catch (error){
        display.value = err;
    }
};

