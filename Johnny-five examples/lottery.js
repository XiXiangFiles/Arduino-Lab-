let five = require("johnny-five");
five.Board().on("ready", function() {
  let servo = new five.Servo(9);
  var power = new five.Led(8);
  let cmd={};
  cmd.ready=function(){
    power.off();
    servo.to(10);
    return true;
  }
  cmd.start=function(){
    servo.to(95);
    setTimeout(()=>{power.on();},1000);
    setTimeout(()=>{power.off();},2500);
    setTimeout(()=>{servo.to(150)},4000);
    return true;
  }
  cmd.close=function(){process.exit()};
  this.repl.inject(cmd);
});
