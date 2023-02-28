#ifndef __stepper_motor_74hc_unl2x03_h__
#define __stepper_motor_74hc_unl2x03_h__

#include "gpio.h"
#include <unistd.h>

#define LE_GPIO 0       // latch enable input (active LOW)
#define MR_GPIO 0       // conditional reset input (active LOW)

#define DATA_GPIO 26    // data input

#define A0_GPIO 22      // address input
#define A1_GPIO 23      // address input
#define A2_GPIO 24      // address input

#define USLEEP_TIME 10

typedef enum motor_t {
    MOTOR_VERTICAL = 0,
    MOTOR_HORIZONTAL = 1
} MOTOR;


// A0 A1 A2 = Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7
// L  L  L  = H  L  L  L  L  L  L  L
// H  L  L  = L  H  L  L  L  L  L  L
// L  H  L  = L  L  H  L  L  L  L  L
// H  H  L  = L  L  L  H  L  L  L  L
// L  L  H  = L  L  L  L  H  L  L  L
// H  L  H  = L  L  L  L  L  H  L  L
// L  H  H  = L  L  L  L  L  L  H  L
// H  H  H  = L  L  L  L  L  L  L  H

int stepm_74hc_gpio_init();
int stepm_74hc_gpio_deinit();
int motor_clockwise(MOTOR motor);
int motor_unclockwise(MOTOR motor);

int stepm_74hc_disable(MOTOR motor);

int stepm_74hc_init_motors(unsigned motor_count, unsigned gpio_a, unsigned gpio_b, unsigned gpio_c, unsigned gpio_data_in);

int stepm_74hc_init_pawls(unsigned motor, unsigned gpio_margin_A, unsigned gpio_margin_B);

int stepm_74hc_rotate(unsigned motor, int direction, unsigned steps_count);

int stepm_74hc_calibrate(unsigned motor);

int stepm_74hc_get_max_position(unsigned motor);
int stepm_74hc_get_cur_position(unsigned motor);

void stepm_74hc_done();


#endif // __stepper_motor_74hc_unl2x03_h__
