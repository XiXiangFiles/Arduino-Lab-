let five = require("johnny-five");
let readline = require("readline");

let rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

five.Board().on("ready", function() {
  let servo = new five.Servo(9);
  let cmd={};
  cmd.to=function(degree){servo.to(degree); return `to ${degree}`;};
  cmd.sweep=function(){
    let degree = 0;
    let flag=true;
    setInterval(function(){
      if(degree == 180 && flag == true){ flag = false;}
      if(degree == 0 && flag == false){ flag = true ;};
      flag ==true ? servo.to(degree++) :servo.to(degree--);
    },1)}
  cmd.close=function(){process.exit()};
  this.repl.inject(cmd);
});
