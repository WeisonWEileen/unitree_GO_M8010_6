#include "serialPort/SerialPort.h"
#include <unistd.h>

int main() {

  SerialPort serial("/dev/ttyUSB0");
  MotorCmd cmd;
  MotorData data;

  while (true) {
    cmd.motorType = MotorType::GO_M8010_6;
    cmd.id = 0;
    cmd.mode = 1;
    cmd.K_P = 1;
    // cmd.K_P = 7;  这个值对应最大k_P
    cmd.K_W = 0.03;
    // 调3.14的coef就好对应0度位置
    cmd.Pos = -5.1;
    // cmd.Pos = -5.1 - 3.14 * 2;
    // cmd.Pos = - 3.14 * 7 / 12 * 6.33;
    cmd.W = 0.0;
    cmd.T = 0.0;
    serial.sendRecv(&cmd, &data);

    // if(data.correct == true)
    // {
    //   std::cout <<  std::endl;
    //   std::cout <<  "motor.Pos: "    << data.Pos    << " rad" << std::endl;
    //   std::cout <<  "motor.Temp: "   << data.Temp   << " ℃"  << std::endl;
    //   std::cout <<  "motor.W: "      << data.W      << " rad/s"<<std::endl;
    //   std::cout <<  "motor.T: "      << data.T      << " N.m" << std::endl;
    //   std::cout <<  "motor.MError: " << data.MError <<  std::endl;
    //   std::cout <<  std::endl;
    // }
    // uint8_t *p = (uint8_t *)cmd.get_motor_send_data();
    // for (int i = 0; i < 17; i++)
      // printf("0X%02X ", *p++);

    data.get_motor_recv_data();
    printf("position: %f\n", data.Pos);

    usleep(200);
  }
}
