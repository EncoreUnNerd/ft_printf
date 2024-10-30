#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret_orig;
    int ret_ft;

    // Test des conversions simples
    ret_orig = printf("Test char : %c\n", 'A');
    ret_ft = ft_printf("Test char : %c\n", 'A');
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    ret_orig = printf("Test string : %s\n", "Hello, World!");
    ret_ft = ft_printf("Test string : %s\n", "Hello, World!");
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    ret_orig = printf("Test pointer : %p\n", (void*)0x1234abcd);
    ret_ft = ft_printf("Test pointer : %p\n", (void*)0x1234abcd);
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    ret_orig = printf("Test decimal : %d\n", 42);
    ret_ft = ft_printf("Test decimal : %d\n", 42);
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    ret_orig = printf("Test integer : %i\n", -42);
    ret_ft = ft_printf("Test integer : %i\n", -42);
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    ret_orig = printf("Test unsigned : %u\n", 12345);
    ret_ft = ft_printf("Test unsigned : %u\n", 12345);
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    ret_orig = printf("Test hexadecimal (lowercase) : %x\n", 0xabcd1234);
    ret_ft = ft_printf("Test hexadecimal (lowercase) : %x\n", 0xabcd1234);
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    ret_orig = printf("Test hexadecimal (uppercase) : %X\n", 0xabcd1234);
    ret_ft = ft_printf("Test hexadecimal (uppercase) : %X\n", 0xabcd1234);
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    ret_orig = printf("Test pourcentage : %%\n");
    ret_ft = ft_printf("Test pourcentage : %%\n");
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    // Test des cas spéciaux
    ret_orig = printf("Test valeur 0 : %d\n", 0);
    ret_ft = ft_printf("Test valeur 0 : %d\n", 0);
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    ret_orig = printf("Test plus petit int : %d\n", -2147483648);
    ret_ft = ft_printf("Test plus petit int : %d\n", -2147483648);
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    ret_orig = printf("Test chaine vide : \"%s\"\n", "");
    ret_ft = ft_printf("Test chaine vide : \"%s\"\n", "");
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    ret_orig = printf("Test pointeur NULL : %p\n", NULL);
    ret_ft = ft_printf("Test pointeur NULL : %p\n", NULL);
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    // Test avec plusieurs arguments et conversions
    ret_orig = printf("Mix : char: %c, string: %s, int: %d, hex: %x\n", 'Z', "test", 123, 0xabc);
    ret_ft = ft_printf("Mix : char: %c, string: %s, int: %d, hex: %x\n", 'Z', "test", 123, 0xabc);
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    // Test de combinaisons de conversions
    ret_orig = printf("Double int : %d %d\n", 42, -42);
    ret_ft = ft_printf("Double int : %d %d\n", 42, -42);
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    ret_orig = printf("Triple hex : %x %x %x\n", 0x123, 0x456, 0x789);
    ret_ft = ft_printf("Triple hex : %x %x %x\n", 0x123, 0x456, 0x789);
    printf("Retour (printf): %d | Retour (ft_printf): %d\n", ret_orig, ret_ft);

    return 0;
}
