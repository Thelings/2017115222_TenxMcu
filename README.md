## 单片机课程总结
>单片机是一种集成电路芯片，是采用超大规模集成电路技术把具有数据处理能力的中央处理器cpu、随机存储器ram、只读存储器rom、多种i/o口和中断系统、定时器/计数器等功能（可能还包括显示驱动电路、脉宽调制电路、模拟多路转换器、a/d转换器等电路）集成到一块硅片上构成的一个小而完善的微型计算机系统。

### 一、点亮LED灯。
  首先，首先需要先在单片机上任意找一个i/o口作为输出管脚，脚如：P1_0。在主函数代码开始时需
要先配置看门狗。要想点亮LED，还需要看灯管脚是共阴极还是共阳极。共阴极时单片机是当给一个高
电压引脚上的LED灯亮；共阳极时单片机是当给一个低电压引脚上的LED灯亮。然后再将管脚设置为
CMOS推挽输出。同时看门狗定时器复位始终启用，避免发生看门狗定时器溢出的情况。加上
CLRWDT = 1;，即设置以清除看门狗定时器。只要把设计思路理清即可编写代码。让LED闪烁也显得，
十分简单。只要在一个循环体里面交替地给输出管脚高低电平，即可实现LED灯的闪烁。
