#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22   // GPIO do servomotor
#define LED_R 12       // Canal vermelho do LED RGB
#define LED_G 13       // Canal verde do LED RGB
#define LED_B 14       // Canal azul do LED RGB

// Configuração do PWM para 50Hz
void setup_pwm(uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(gpio);

    pwm_set_clkdiv(slice_num, 125.0);  // Ajusta a frequência para 50Hz
    pwm_set_wrap(slice_num, 19999);    // PWM com período de 20ms
    pwm_set_enabled(slice_num, true);
}

// Função para definir o ângulo do servo
void set_servo_angle(uint gpio, uint pulse_width_us) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    uint16_t level = (pulse_width_us * 19999) / 20000;  // Conversão correta para 50Hz
    pwm_set_gpio_level(gpio, level);
}

// Função para alterar a cor do LED RGB
void set_led_color(bool red, bool green, bool blue) {
    gpio_put(LED_R, red);
    gpio_put(LED_G, green);
    gpio_put(LED_B, blue);
}

// Configuração dos LEDs como saída
void setup_leds() {
    gpio_init(LED_R);
    gpio_init(LED_G);
    gpio_init(LED_B);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);
}

int main() {
    stdio_init_all();
    
    setup_pwm(SERVO_PIN);
    setup_leds();

    while (true) {
        // Ajustar servo para 180° e acender LED azul
        set_servo_angle(SERVO_PIN, 2400);
        set_led_color(0, 0, 1); // Azul
        sleep_ms(5000);

        // Ajustar servo para 90° e apagar LED
        set_servo_angle(SERVO_PIN, 1470);
        set_led_color(0, 0, 0); // Apagado
        sleep_ms(5000);

        // Ajustar servo para 0° e acender LED vermelho
        set_servo_angle(SERVO_PIN, 500);
        set_led_color(1, 0, 0); // Vermelho
        sleep_ms(5000);

        // Movimento suave de 0° a 180° e vice-versa com LED verde
        for (uint pulse = 500; pulse <= 2400; pulse += 5) {
            set_servo_angle(SERVO_PIN, pulse);
            set_led_color(0, 1, 0); // Verde
            sleep_ms(10);
        }
        for (uint pulse = 2400; pulse >= 500; pulse -= 5) {
            set_servo_angle(SERVO_PIN, pulse);
            set_led_color(0, 1, 0); // Verde
            sleep_ms(10);
        }
    }

    return 0;
}
