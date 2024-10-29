/*
 * ARM CMSDK APB UART emulation - picowallet edition (slight modification of the original driver)
 * The original implementation is available in include/hw/char/cmsdk-apb-uart.h.
 *
 * Copyright (c) 2017 Linaro Limited
 * Written by Peter Maydell
 * Modified for Ph0wn 2024 by Romain Malmain.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 or
 *  (at your option) any later version.
 */

#ifndef CMSDK_APB_UART_PHOWN_H
#define CMSDK_APB_UART_PHOWN_H

#include "hw/sysbus.h"
#include "chardev/char-fe.h"
#include "qom/object.h"

#define TYPE_CMSDK_APB_UART_PHOWN "cmsdk-apb-uart-phown"
OBJECT_DECLARE_SIMPLE_TYPE(CMSDKAPBUARTPHOWN, CMSDK_APB_UART_PHOWN)

struct CMSDKAPBUARTPHOWN {
    /*< private >*/
    SysBusDevice parent_obj;

    /*< public >*/
    MemoryRegion iomem;
    CharBackend chr;
    qemu_irq txint;
    qemu_irq rxint;
    qemu_irq txovrint;
    qemu_irq rxovrint;
    qemu_irq uartint;
    guint watch_tag;
    uint32_t pclk_frq;
    uint32_t ctr;

    uint32_t state;
    uint32_t ctrl;
    uint32_t intstatus;
    uint32_t bauddiv;
    /* This UART has no FIFO, only a 1-character buffer for each of Tx and Rx */
    uint8_t txbuf;
    uint8_t rxbuf;
};

#endif
