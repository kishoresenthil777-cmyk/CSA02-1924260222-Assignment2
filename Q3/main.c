
#include <stdio.h>

/* Each bit of one byte stores the ON/OFF state of one device. */

enum {
    LIGHT = 0,
    FAN = 1,
    AC = 2,
    HEATER = 3,
    PUMP = 4
};

/* TODO 1: Switch ON a device */
unsigned char switch_on(unsigned char reg, int dev)
{
    return reg | (1u << dev);
}

/* TODO 2: Switch OFF a device */
unsigned char switch_off(unsigned char reg, int dev)
{
    return reg & ~(1u << dev);
}

/* TODO 3: Toggle a device */
unsigned char toggle(unsigned char reg, int dev)
{
    return reg ^ (1u << dev);
}

/* TODO 4: Check whether a device is ON */
int is_on(unsigned char reg, int dev)
{
    return (reg & (1u << dev)) != 0;
}

/* Display all 8 bits */
void show(unsigned char reg)
{
    for (int bit = 7; bit >= 0; bit--)
    {
        putchar(((reg >> bit) & 1u) ? '1' : '0');
    }

    putchar('\n');
}

/* Count the number of devices that are ON */
int count_on(unsigned char reg)
{
    int count = 0;

    for (int bit = 0; bit < 8; bit++)
    {
        if ((reg >> bit) & 1u)
        {
            count++;
        }
    }

    return count;
}

int main(void)
{
    unsigned char reg = 0;

    printf("SMART HOME DEVICE CONTROLLER\n");
    printf("----------------------------\n");

    printf("Initial register: ");
    show(reg);

    /* Switch ON LIGHT */
    reg = switch_on(reg, LIGHT);
    printf("After switching ON LIGHT: ");
    show(reg);

    /* Switch ON AC */
    reg = switch_on(reg, AC);
    printf("After switching ON AC: ");
    show(reg);

    /* Original assignment output */
    printf("\nRegister before toggle: ");
    show(reg);

    /* Toggle FAN */
    reg = toggle(reg, FAN);

    /* Switch OFF LIGHT */
    reg = switch_off(reg, LIGHT);

    printf("Register after toggle and OFF: ");
    show(reg);

    printf("\nAC is %s\n", is_on(reg, AC) ? "ON" : "OFF");
    printf("PUMP is %s\n", is_on(reg, PUMP) ? "ON" : "OFF");

    printf("Total devices ON: %d\n", count_on(reg));

    return 0;
}
