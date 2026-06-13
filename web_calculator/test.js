const calculate = (expression) => {
  return new Function(`return ${expression}`)();
};

console.log(calculate(1 + 3));