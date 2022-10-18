function scoreChecker(score) {
  let result;

  if(score >= 90){
    result = "Congratulations! you got an A.";
  } else if(score >= 80){
    result = "You got a B.";
  } else if(score >= 70){
    result = "You got a C.";
  } else if(score >= 60){
    result = "You got a D.";
  } else {
    result = "You got a E.";
  }


  return result;
}

console.log(scoreChecker(80))
