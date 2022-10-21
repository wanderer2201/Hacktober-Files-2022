const textBox = document.querySelector("#textBox");
document.querySelector("#textBox").focus();
const output = document.querySelector("#output");

textBox.addEventListener('keydown', (event) => output.textContent = `You pressed "${event.key}".`);
