#define   ACCEL_XOUT_H    0x3B    // 59
#define   ACCEL_XOUT_L    0x3C    // 60
#define   ACCEL_YOUT_H    0x3D    // 61
#define   ACCEL_YOUT_L    0x3E    // 62
#define   ACCEL_ZOUT_H    0x3F    // 63
#define   ACCEL_ZOUT_L    0x40    // 64
#define   TEMP_OUT_H      0x41    // 65
#define   TEMP_OUT_L      0x42    // 65
#define   GYRO_XOUT_H     0x43    // 67
#define   GYRO_XOUT_L     0x44    // 68
#define   GYRO_YOUT_H     0x45    // 69
#define   GYRO_YOUT_L     0x46    // 70
#define   GYRO_ZOUT_H     0x47    // 71
#define   GYRO_ZOUT_L     0x48    // 92
#define   ADDR_MPU6050     0x68   // 104
#include <Wire.h>
void mpu6050()
{
  Wire.begin();
  delay(10);
  Wire.beginTransmission(ADDR_MPU6050);
  Wire.write(0x1b);
  Wire.write(0b11000);
  Wire.endTransmission();


  Wire.beginTransmission(ADDR_MPU6050);
  Wire.write(0x6b);
  Wire.write(0x01);
  Wire.endTransmission();

}
int16_t getData_mpu6050(int8_t diachi)
{

  Wire.beginTransmission(ADDR_MPU6050);
  Wire.write(diachi);
  Wire.endTransmission();
  Wire.requestFrom(ADDR_MPU6050, 2);
  return (Wire.read() << 8) | Wire.read();
}

int16_t get_accx()
{
  return getData_mpu6050(ACCEL_XOUT_H);
}
int16_t get_accy()
{
  return getData_mpu6050(ACCEL_YOUT_H);
}
int16_t get_accz()
{
  return getData_mpu6050(ACCEL_ZOUT_H);
}
int16_t get_gyrox()
{
  return getData_mpu6050(GYRO_XOUT_H );
}
int16_t get_gyroy()
{
  return getData_mpu6050(GYRO_YOUT_H );
}

int16_t get_gyroz()
{
  return getData_mpu6050(GYRO_ZOUT_H );
}
