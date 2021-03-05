/*!
 * \file
 * \brief Statistics implementation file
 * \author Dawid Babula
 * \email dbabula@adventurous.pl
 *
 * \par Copyright (C) Dawid Babula, 2021
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#define DEBUG_APP_ID    "STAT"
#define DEBUG_ENABLED   DEBUG_STAT_ENABLED
#define DEBUG_LEVEL     DEBUG_STAT_LEVEL

#include "stat.h"
#include "system.h"
#include "debug.h"


static void stat_main(void)
{
    uint16_t stack_size = SYSTEM_get_stack_size();
    uint16_t stack_left = SYSTEM_get_stack_left();
    uint16_t usage = ((stack_size - stack_left)*100)/stack_size;

    (void) usage;

    DEBUG(DL_ERROR, "Stack size %dB Left: %dB Usage %d%%\n",
            stack_size, stack_left, usage);
}

void STAT_initialize(void)
{
    SYSTEM_register_task(stat_main, 5000);
}
