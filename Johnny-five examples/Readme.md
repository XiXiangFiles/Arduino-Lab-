# 進階程式設計 arduino Lab 
### 環境設定 Johnny-five Setup
> Linux
* Nodejs 6.x LTS 、8.x LTS 或以上版本
```shell=
## Install Nodejs steps
sudo apt-get updgate
sudo apt-get dist-upgrade
sudo curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
sudo apt-get install -y nodejs
## install Arduino
wget https://www.arduino.cc/download_handler.php
tar -xvf arduino
tar -xvf arduino-1.8.8-linux64.tar.xz arduino-1.8.8
cd arduino-1.8.8-linux64/arduino-1.8.8
sudo ./arduino
```
### REPL 使用方法
* REPL 指的是可以利用「指令」的方式對Arduino 控制
    * 輸入 on() 13 pin將會進行高電位輸出
    * 輸入 off()13 pin將會進行低電位輸出
````js
let five = require("johnny-five");
let board = new five.Board();
board.on("ready", function() {
  let power = new five.Led(13);
  let device=this;
  let cmd={};
  cmd.on=function(){power.on(); return "on";};
  cmd.off=function(){power.off(); return "off";};
  this.repl.inject(cmd);
});
````
### Relay 使用方法
* Realy 有「常開」、「常關」等兩個模式，可透過輸入高低電位進行控制，原理如下
    * on() --> 指的是當8 pin 高電位時，常關將通電
    * off()---> 指的是當8 pin 低電位時，常開將通電
![](https://i.imgur.com/1bAx4zJ.png)

> 線路圖如下
> ![](https://i.imgur.com/KSGkrdx.png)


````js 
let five = require("johnny-five");
let board = new five.Board();
board.on("ready", function() {
  let power = new five.Led(8);
  let device=this;
  let cmd={};
  cmd.on=function(){power.on(); return "on";};
  cmd.off=function(){power.off(); return "off";};
  this.repl.inject(cmd);
});
````
### Servo 使用方法
* Servo 是一個能夠控制轉0~180度的馬達，可透過Servo 模組進行控制
* method 「to」方法能夠用來控制轉幾度
    * 如第六行to(degree); degree指的是轉幾度
    * 第7行「sweep」方法指的是利用「to」進行鐘擺實作 
> 線路圖如下
> ![](https://i.imgur.com/86hgXRw.png)
````js
let five = require("johnny-five");
let readline = require("readline");
five.Board().on("ready", function() {
  let servo = new five.Servo(9);
  let cmd={};
  cmd.to=function(degree){servo.to(degree); return `to ${degree}`;};
  cmd.sweep=function(){
    let degree = 0;
    let flag=true;
    setInterval(function(){
      if (degree == 180 && flag == true) { flag = false}';
      if(degree == 0 && flag == false){flag = true};
      flag ==true ? servo.to(degree++) :servo.to(degree--);
      console.log(degree);},1)}
  cmd.close=function(){process.exit()};
  this.repl.inject(cmd);
});
````
### Lottery Machine 實作
* 利用Servo、Motor、Relay搭配「REPL」技術進行實做
    * REPL
        * 實做ready、start兩個方法
        * ready--> 使Servo 轉向10度，使骰子機站立
        * start--> 使Servo 轉向95度之後，馬達啟動，在特定時間後停止，Servo旋轉至150度將骰子倒出
    * Servo
        * 使用「to」方法進行Servo控制
    * Relay
        * 透過高低電位差控制Relay，高電位使「常關」開，低電位使「常開」開
    * Motor
        * 搭配Relay 進行控制，接腳在常關上，當輸出高電位時可直接啟動
> 線路圖如下
![](https://i.imgur.com/OtjzmP8.png)

````js
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
`````

