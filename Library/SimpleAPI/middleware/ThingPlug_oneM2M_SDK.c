/**
 * @file ThingPlug_oneM2M_SDK.c
 *
 * @brief Simple ThingPlug_oneM2M_SDK application
 *
 * Copyright (C) 2016. SK Telecom, All Rights Reserved.
 * Written 2016, by SK Telecom
 */

#include "MA.h"
#include "NTPClient.h"
#include "wizSystem.h"
/**
 * @brief main
 * @param[in] argc
 * @param[in] argv
 */
int ThingPlug_oneM2M_SDK(void) {
	while(1) {
		tskEthernetManager(NULL);
		int rc = 1;
		int loop_cnt = 10;
		while(loop_cnt--) {
			osDelay(200);
			rc = NTPSocket();
			if( rc == -1 ) continue;
			rc = setTime();
			if( rc != 0 ) continue;
			else break;
		}

		osDelay(2000);
		MARun();
	}
    return 0;
}

