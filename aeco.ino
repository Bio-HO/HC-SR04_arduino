void setup() {
  // put your setup code here, to run once:
  pinMode(4,INPUT); //echo
  pinMode(3,OUTPUT);  //trig
  Serial.begin(9600); //啟動序列埠，鮑率=9600
  digitalWrite(3,LOW);  //先將trig設為低電位
}

void loop() {
  // put your main code here, to run repeatedly:
  double dure,far;

  //對trig輸出一段高電位(20us)，讓HC-SR04做一次測量
  digitalWrite(3,HIGH); 
  delayMicroseconds(20);
  digitalWrite(3,LOW);

  dure=pulseIn(4,HIGH); //讀取echo收到的高電位長度(單位為us)
  
  far=dure/58;  //收到的高電位長度/58=距離(cm)

  //輸出距離資料
  //HC-SR04最遠能量到400公分，再遠就是錯誤資料
  if(far<400){
    Serial.println(far);
  }
  delay(10);  //等一會再做下一次量測
}
