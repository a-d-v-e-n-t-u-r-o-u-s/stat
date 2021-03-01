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
}

void STAT_initialize(void)
{
    int8_t ret = SYSTEM_register_task(stat_main, 1000);

    (void) ret;
    ASSERT(ret == 0);
}
