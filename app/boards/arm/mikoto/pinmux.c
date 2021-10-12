/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <drivers/gpio.h>
#include <sys/sys_io.h>
#include <devicetree.h>

static int pinmux_mikoto_init(const struct device *port) {
    ARG_UNUSED(port);

#if CONFIG_BOARD_MIKOTO_520
    const struct device *p0 = device_get_binding("GPIO_0");
    const struct device *p1 = device_get_binding("GPIO_1");
#if CONFIG_BOARD_MIKOTO_CHARGER
    // 100mA
    gpio_pin_configure(p0, 26, GPIO_OUTPUT);
    gpio_pin_set(p0, 26, 0);
    gpio_pin_configure(p1, 15, GPIO_INPUT);
    // 250mA
    // gpio_pin_configure(p0, 26, GPIO_INPUT);
    // gpio_pin_configure(p1, 15, GPIO_OUTPUT);
    // gpio_pin_set(p1, 15, 0);
    // 250mA
    // gpio_pin_configure(p0, 26, GPIO_OUTPUT);
    // gpio_pin_set(p0, 26, 0);
    // gpio_pin_configure(p1, 15, GPIO_OUTPUT);
    // gpio_pin_set(p1, 15, 0);
#else
    gpio_pin_configure(p0, 26, GPIO_INPUT);
    gpio_pin_configure(p1, 15, GPIO_INPUT);
#endif
#endif
    return 0;
}

SYS_INIT(pinmux_mikoto_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
