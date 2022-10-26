const printArray = document.querySelector('.printArray');
const btn = document.querySelector('.btn');
let output=new Array(30).fill("");
var count=1;

function fizzbuzz() {
    while(count!=0){
    if(count%3==0){
        output[count-1]+='Fizz';
        console.log(output);
    }  
    if(count%5==0)
    output[count-1]+='Buzz'; 
    else if(count%3!=0)
        output[count-1]= count;
        
    if(count ===30){
        count=-1;
        printArray.textContent=output;
    }   
        count++;       
    }
}

btn.addEventListener('click',fizzbuzz);
