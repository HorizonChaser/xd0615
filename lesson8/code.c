//使用内建的ADC, 从Analog引脚读取电压, 并输出到串口

void setup() {
  //使用9600的波特率来初始化串口
  Serial.begin(9600);
}

void loop() {
  
  //读取电压, 这实际上是开始一次ADC转换
  //在基于ATMega芯片的板子上, 这一步大概需要100微秒
  //不同芯片内建的ADC精度不一样, 对于使用ATMega168/328的Uno,
  //分辨率是10bit, 也就是0~1023的范围, 闭区间
  //可以使用analogReference()来修改参考电压
  //对于Uno, 内建的参考源有
  //DEFAULT(5V/3.3V), INTERNAL(1.1V/2.56V), INTERNAL1V1(1.1V), INTERNAL2V56(2.56V)
  //也可以用外置的AREF设定参考电压, 范围0~5V
  //在比较新的板子上(Zero, Due, MKR系列), 可以使用analogReadResolution()设置ADC的精度
  
  int sensorValue = analogRead(A0);
  
  //将读取值映射到0~5V的真实电压范围中
  float voltage = sensorValue * (5.0 / 1023.0);
  
  //串口输出电压值
  Serial.println(voltage);
}