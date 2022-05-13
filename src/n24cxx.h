
/*
 * This is a C library for the ON Semiconductor N24C02, N24C04, N24C08, N24C16 I2C Serial EEPROM chips.
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
 */

#include <stdlib.h>
#include "n24cxx-defs.h"

typedef enum{
   n24cxxAddress_0 = N24Cxx_ADDRESS_7_BITS_0,
   n24cxxAddress_1 = N24Cxx_ADDRESS_7_BITS_1,
   n24cxxAddress_2 = N24Cxx_ADDRESS_7_BITS_2,
   n24cxxAddress_3 = N24Cxx_ADDRESS_7_BITS_3,
   n24cxxAddress_4 = N24Cxx_ADDRESS_7_BITS_4,
   n24cxxAddress_5 = N24Cxx_ADDRESS_7_BITS_5,
   n24cxxAddress_6 = N24Cxx_ADDRESS_7_BITS_6,
   n24cxxAddress_7 = N24Cxx_ADDRESS_7_BITS_7,

}n24cxx_address_e;

typedef enum
{
    n24c02 = 2048,
    n24c04 = 4096,
    n24c08 = 8192,
    n24c16 = 16384,

}n24cxx_type_e;

typedef struct 
{
    n24cxx_type_e type;
    void* ctx;
    n24cxx_address_e address;
}n24cxx_series_t;

typedef enum
{
    n24cxx_status_undefined            = 0,
    n24cxx_status_error                = 0b00000010,
    n24cxx_status_ok                   = 0b00000100,
    n24cxx_status_error_null_ptr       = 0b00001010,
    n24cxx_status_error_invalid_length = 0b00010010,
    n24cxx_status_error_comms          = 0b00100010,
    n24cxx_status_device_not_found     = 0b01000010,
    n24cxx_status_function_not_impl    = 0b10000010,

}n24cxx_status_e;

typedef uint32_t n24cxx_status_t;


/**
 * @brief Write a single byte to the specified EEPROM address.
 * 
 * @param dev the n24cxxSeries_t structure for the device.
 * @param address the EEPROM address to write too.
 * @param value  the value to write to the address, a single byte.
 * @return n24cxxStatus_t the status of the operation.
 */
n24cxx_status_t n24cxx_write(n24cxx_series_t *dev, N24Cxx_addr address, uint8_t value);

/**
 * @brief Write an array of data to the specified EEPROM address. The function takes care of managing the required number of page writes.
 * 
 * @param dev the n24cxxSeries_t structure for the device.
 * @param address the EEPROM address to write too.
 * @param value the value to write to the address, an array of bytes.
 * @param length the number of bytes to write.
 * @return n24cxxStatus_t the status of the operation.
 */
n24cxx_status_t n24cxx_write_page(n24cxx_series_t *dev, N24Cxx_addr address, uint8_t *value, size_t length);

/**
 * @brief Read a single byte to the specified EEPROM address.
 * 
 * @param dev the n24cxxSeries_t structure for the device
 * @param address the EEPROM address to read from.
 * @param value the location to read the data into.
 * @return n24cxxStatus_t the status of the operation.
 */
n24cxx_status_t n24cxx_read(n24cxx_series_t *dev, N24Cxx_addr address, uint8_t *value);

/**
 * @brief Read an array of data from the specified EEPROM address. The function takes care of managing the required number of page reads.
 * 
 * @param dev the n24cxxSeries_t structure for the device
 * @param address the EEPROM address to read from.
 * @param value the location to read the data into.
 * @param length the number of bytes to read.
 * @return n24cxxStatus_t 
 */
n24cxx_status_t n24cxx_read_page(n24cxx_series_t *dev, N24Cxx_addr address, uint8_t *value, size_t length);

/**
 * @brief Returns the size of the specified chip;
 * 
 * @param type 
 * @return size_t 
 */
size_t n24cxx_get_size(n24cxx_type_e type);

// These function implement the platform specific functionality required by this library.
// __attribute__((weak)) implementations of these functions are provided so that this
// library can compile. Any program making use of this library must provide implementations
// of these function that perform the required actions on the specific platform.

n24cxx_status_t n24cxx_read_impl(struct max1726x_t *dev, N24Cxx_addr address, uint8_t *data, size_t length);
n24cxx_status_t n24cxx_write_impl(struct max1726x_t *dev, N24Cxx_addr address, uint8_t *data, size_t length);

