function appendToDisplay(value) {
    const display = document.getElementById('display');
    display.value += value;
}
 
function clearDisplay() {
    const display = document.getElementById('display');
    display.value = '';
}
 
function calculate() {
    const display = document.getElementById('display');
    try {
        const result = eval(display.value);
        display.value = result;
    } catch (error) {
        display.value = 'Er';
    }
}