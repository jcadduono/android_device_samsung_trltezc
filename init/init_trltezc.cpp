/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
	char bootloader[PROP_VALUE_MAX];

	UNUSED(msm_id);
	UNUSED(msm_ver);
	UNUSED(board_type);

	property_get("ro.bootloader", bootloader);

	if (strstr(bootloader, "N9106W")) {
		/* trltezn */
		property_set("ro.product.model", "SM-N9106W");
		property_set("ro.product.name", "trltezn");
	} else if (strstr(bootloader, "N9108V")) {
		/* trltezm */
		property_set("ro.product.model", "SM-N9108V");
		property_set("ro.product.name", "trltezm");
	} else if (strstr(bootloader, "N9108W")) {
		/* trltezm */
		property_set("ro.product.model", "SM-N9108W");
		property_set("ro.product.name", "trltezm");
	} else if (strstr(bootloader, "N9109W")) {
		/* trlteke */
		property_set("ro.product.model", "SM-N9109W");
		property_set("ro.product.name", "trlteke");
	} else {
		/* all other variants become trltezc */
		property_set("ro.product.model", "SM-N9100");
		property_set("ro.product.name", "trltezc");
	}
	property_set("ro.product.device", "trlte");
}
