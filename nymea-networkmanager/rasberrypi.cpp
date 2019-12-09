#include "rasberrypi.h"
#include "loggingcategories.h"

#include <ctype.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <iostream>
#include <iomanip>
#include <cstdint>



static char * trimWhiteSpace(char *string)
{
    if (string == NULL)
    {
        return NULL;
    }

    while (isspace(*string))
    {
        string++;
    }

    if (*string == '\0')
    {
        return string;
    }

    char *end = string;

    while (*end)
    {
        ++end;
    }
    --end;

    while ((end > string) && isspace(*end))
    {
        end--;
    }

    *(end + 1) = 0;
    return string;
}


QString RasberryPI::getSerialNumber() {

    uint32_t serial = 0;

    FILE *fp = fopen("/proc/cpuinfo", "r");

    if (fp == NULL)
    {
        perror("/proc/cpuinfo");
        exit(EXIT_FAILURE);
    }

    char entry[80];

    while (fgets(entry, sizeof(entry), fp) != NULL)
    {
        char* saveptr = NULL;

        char *key = trimWhiteSpace(strtok_r(entry, ":", &saveptr));
        char *value = trimWhiteSpace(strtok_r(NULL, ":", &saveptr));

        if (strcasecmp("Serial", key) == 0)
        {
            serial = strtoul(value, NULL, 16);
        }
    }

    fclose(fp);

	//printf("serial: %016" PRIx32 "\n", serial);
    qCDebug(dcNymeaService()) << "PushButton agent registered.";

    QString hexadecimal;
    hexadecimal.setNum(serial,16); 
    return hexadecimal;
}
