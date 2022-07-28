/*
 * This is a register map for the ON Semiconductor N24C02, N24C04, N24C08, N24C16 I2C Serial EEPROM chips.
 * Copyright (C) 2021  eResearch, James Cook University
 * Author: NigelB
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * 
 * 
 * Excluded from this copyright notice is the cited material from the following sources:
 * 
 * N24Cxx_Datasheet:
 *     name: The N24C02 is a EEPROM Serial 2-Kb I2C, US 8-lead Package device organized internally as 16 pages of 16 bytes each.
 *     url: https://www.onsemi.com/products/timing-logic-memory/memory/eeprom-memory/n24c02
 *     pdf: https://www.onsemi.com/pdf/datasheet/n24c02-d.pdf
 * 
 * Which remains the property of Maxim Integrated Products, Inc.
 */

#ifndef __N24Cxx_DEFS_H__
#define __N24Cxx_DEFS_H__

#include "stdint.h"

#define N24Cxx_ADDRESS_7_BITS_0   0x50
#define N24Cxx_ADDRESS_7_BITS_1   0x51
#define N24Cxx_ADDRESS_7_BITS_2   0x52
#define N24Cxx_ADDRESS_7_BITS_3   0x53
#define N24Cxx_ADDRESS_7_BITS_4   0x54
#define N24Cxx_ADDRESS_7_BITS_5   0x55
#define N24Cxx_ADDRESS_7_BITS_6   0x56
#define N24Cxx_ADDRESS_7_BITS_7   0x58


#define N24Cxx_PAGE_SIZE          16
#define N24Cxx_WRITE_TIME_MS       4


typedef uint8_t N24Cxx_addr;


#endif
