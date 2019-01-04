var five = require("johnny-five");
var board = new five.Board();

board.on("ready", function() {
  var power = new five.Led(13);
  let device=this;
  let cmd={};
  cmd.on=function(){power.on(); return "on";};
  cmd.off=function(){power.off(); return "off";};
  this.repl.inject(cmd);
});