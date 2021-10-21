/*
 * Class Activity - CCC101
 * Group Members: Piscos, Magsalay, Lumapay
 * Section: BSCA B182
 * Date: 10/20/21 18:15:00 GMT +08:00
 * @Author: Piscode
 */

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int volts = 5;
    int current = 1;
    int resistance = volts / current;

    int light_switch = 0;

    int led_1 = false; // off
    int led_2 = false; // off
    int led_3 = false; // off

    char response;
    char response_LED2 = 0;
    char response_LED3 = 0;

    do
    {
        printf("[INFO]---------------------------------------------------------------------------------\n");
        printf("| When a switch is closed, current flows through it.                                  |\n");
        printf("| Now, choose a number below to know the LED status based on the switch inputs.       |\n");
        printf("---------------------------------------------------------------------------------------\n");
        printf("-------------------------\n");
        printf("| Type '1' for Switch 1 |\n");
        printf("| Type '2' for Switch 2 |\n");
        printf("| Type '3' for Switch 3 |\n");
        printf("-------------------------\n");

        printf("Enter choice: ");
        scanf("%d", &light_switch);
        switch (light_switch)
        {
            case 1:
                led_1 = true;
                printf("\n[OUTCOME]---------------------------------------------------------------------------------------------\n");
                printf("| When SWITCH 1 is closed, the current can flow from one end of the power supply (+5V) to the other. |\n");
                printf("| Because of this, there is a current flow, LED 1 will light.                                        |\n");
                printf("------------------------------------------------------------------------------------------------------\n");
            break;
            case 2:
                led_3 = true;
                printf("\n[OUTCOME]--------------------------------------------------------------------------------------------------\n");
                printf("| When SWITCH 2 is closed, the current will flow through the closed paths and not through the open paths. |\n");
                printf("| Thus, the LED 3 will emit light.                                                                        |\n");
                printf("-----------------------------------------------------------------------------------------------------------\n");
            break;
            case 3:
                printf("\n[OUTCOME]-----------------------------------------------------------------------------------------\n");
                printf("| (~) SWITCH 2 and 3 are wired in the same line connected from the power supply (+5V).           |\n");
                printf("| When SWITCH 3 is closed, Switch 2 remains open resulting in a broken circuit.                  |\n");
                printf("| As a result, the current stops flowing through the circuit, and the LED 2 will not light.      |\n");
                printf("--------------------------------------------------------------------------------------------------\n");

                if (!led_2)
                {
                    printf("In order to prevent an interruption of the current flow, you will need to close (Turn on) Switch 2 first. (Y/N)\n > ");
                    scanf(" %c", &response_LED3);

                    if (response_LED3 == 'y' || response_LED3 == 'Y')
                    {
                        led_3 = true;
                    }

                    if (led_3)
                    {
                        printf("Would you like to close (Turn on) Switch 3 as well? (Y/N)\n > ");
                        scanf(" %c", &response_LED2);

                        if (response_LED2 == 'y' || response_LED2 == 'Y')
                            led_2 = true;
                    }
                }
            break;
            default: printf("It seems you have entered an invalid Switch.\n > ");
        }

        printf("Turn on more lights? (Y/N)\n > ");
        scanf(" %c", &response);
    } while (response == 'y' || response == 'Y');

    if (led_1)
        printf("\nLED 1 has been switched on.\n  State: Running [Volts = %d, Current = %d, Resistance = %d]\n\n", volts, current, resistance);
    else
        printf("\nLED 1 remains off.\n\n");

    if (led_2)
        printf(" LED 2 has been switched on.\n  State: Running [Volts = %d, Current = %d, Resistance = %d]\n\n", volts, current, resistance);
    else
        printf(" LED 2 remains off.\n\n");

    if (led_3)
        printf(" LED 3 has been switched on.\n  State: Running [Volts = %d, Current = %d, Resistance = %d]\n\n", volts, current, resistance);
    else
        printf(" LED 3 remains off.\n\n");

    return 0;
}