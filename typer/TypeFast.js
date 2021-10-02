var input = document.getElementById("inpt");
const wordD = [
  "Extravaganza",
  "Enticing",
  "Wondrous",
  "Stunning",
  "Elegant",
  "Breath-taking",
  "Ravishing",
  "maverick",
  "meticulous",
  "novice",
  "oblivious",
  "obsequious",
  "parody",
  "refurbish",
];
var score = 0;
var df = 1;
var timer = 1000;
var k = 10;
var i = 0;
var highscore = 0;
var fun = document.querySelector(".fun");
var button = document.getElementById("btn1");
button.addEventListener("click", () => {
  location.reload();
});
const toggler = () => {
  var action = document.querySelector(".action");
  action.classList.toggle("active");
};
const Activate = (q) => {
  var b = 0;
  if (q == 0) {
    fun.style.visibility = "hidden";
  }
  if (q == 1) {
    fun.style.visibility = "visible";
    document.querySelector(".mainer1").style.opacity = 0.6;
  }
};
const sleep = (milliseconds) => {
  return new Promise((resolve) => setTimeout(resolve, milliseconds));
};
const option = () => {
  var x = document.getElementById("diff").selectedIndex;
  var t = document.getElementsByTagName("option")[x].value;
  var time = 0;
  if (t == 1) {
    time = 1000;
  }
  if (t == 2) {
    time = 600;
  }
  if (t == 3) {
    time = 400;
  }
  df = t;
  console.log(timer, "option=", t);
  return time;
};
timer = option();
const words = async () => {
  alert("Start the Game?");
  for (i; i <= wordD.length; i++) {
    if (i === wordD.length) {
      Activate(1);
    }
    document.querySelector(".word").innerHTML = wordD[i];
    input.addEventListener("keypress", (event) => {
      if (event.code === "Enter") {
        console.log("Working!");
        if (inpt.value === wordD[i]) {
          console.log("correct!");
          if (df == 1) {
            score++;
          }
          if (df == 2) {
            score += 2;
          }
          if (df == 3) {
            score += 3;
          }
          if (highscore < score) {
            highscore = score;
          }
          document.querySelector(".HighScore").innerHTML =
            "High-Score:" + highscore;
          document.querySelector(".h11").innerHTML = "";
          document.querySelector(".score").innerHTML = "score:" + score;
          input.disabled = true;
        }
        input.value = "";
      }
    });
    input.disabled = false;
    timer = option();
    while (k) {
      document.querySelector(".timer").innerHTML = "Time left: " + k--;
      await sleep(timer);
    }
    k = 10;
  }
};
words();
