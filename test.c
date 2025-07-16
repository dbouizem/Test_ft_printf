#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

// Supposons que ft_printf est déclaré dans ft_printf.h
int ft_printf(const char *format, ...);

// Couleurs pour l'affichage
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int test_count = 0;
int passed_tests = 0;

void print_test_header(const char *section) {
    printf("\n" BLUE "=== %s ===" RESET "\n", section);
}

void compare_outputs(const char *test_name, const char *format, ...) {
    va_list args1, args2;
    char buffer1[1000], buffer2[1000];
    int ret1, ret2;

    test_count++;

    // Test avec ft_printf
    va_start(args1, format);
    ret1 = ft_printf(format, args1);
    va_end(args1);

    // Test avec printf pour comparaison
    va_start(args2, format);
    ret2 = printf(format, args2);
    va_end(args2);

    printf("\n" YELLOW "Test %d: %s" RESET "\n", test_count, test_name);
    printf("Format: \"%s\"\n", format);
    printf("ft_printf retour: %d\n", ret1);
    printf("printf retour: %d\n", ret2);

    if (ret1 == ret2) {
        printf(GREEN "✓ PASS - Valeurs de retour identiques" RESET "\n");
        passed_tests++;
    } else {
        printf(RED "✗ FAIL - Valeurs de retour différentes" RESET "\n");
    }
}

void test_simple_conversions() {
    print_test_header("PARTIE OBLIGATOIRE - Conversions simples");

    // Test %c
    compare_outputs("Caractère simple", "%c", 'A');
    compare_outputs("Caractère null", "%c", '\0');

    // Test %s
    compare_outputs("String simple", "%s", "Hello World");
    compare_outputs("String vide", "%s", "");
    compare_outputs("String NULL", "%s", (char*)NULL);

    // Test %p
    int x = 42;
    compare_outputs("Pointeur", "%p", &x);
    compare_outputs("Pointeur NULL", "%p", NULL);

    // Test %d et %i
    compare_outputs("Entier positif", "%d", 42);
    compare_outputs("Entier négatif", "%d", -42);
    compare_outputs("Zéro", "%d", 0);
    compare_outputs("INT_MAX", "%d", INT_MAX);
    compare_outputs("INT_MIN", "%d", INT_MIN);
    compare_outputs("INT_MIN avec %i", "%i", INT_MIN);

    // Test %u
    compare_outputs("Unsigned simple", "%u", 42u);
    compare_outputs("Unsigned zero", "%u", 0u);
    compare_outputs("UINT_MAX", "%u", UINT_MAX);

    // Test %x et %X
    compare_outputs("Hex minuscule", "%x", 255);
    compare_outputs("Hex majuscule", "%X", 255);
    compare_outputs("Hex zero", "%x", 0);
    compare_outputs("Hex négatif", "%x", -1);

    // Test %%
    compare_outputs("Pourcentage", "%%");
    compare_outputs("Double pourcentage", "%%%%");
}

void test_multiple_args() {
    print_test_header("Arguments multiples et conversions mixtes");

    compare_outputs("Multiples args", "%d %s %c", 42, "test", 'X');
    compare_outputs("Conversions au milieu", "Début %d milieu %s fin", 123, "test");
    compare_outputs("Texte avant/après", "Valeur: %d (fini)", 42);
    compare_outputs("Complexe", "Int: %d, Hex: %x, String: %s, Char: %c", 42, 255, "hello", 'A');
}

void test_edge_cases() {
    print_test_header("Cas spéciaux et limites");

    // Test avec des valeurs limites
    compare_outputs("Très grand nombre", "%d", 2147483647);
    compare_outputs("Très petit nombre", "%d", -2147483648);

    // Test avec des strings spéciales
    compare_outputs("String très longue", "%s", "Cette string est très très très longue pour tester les limites");

    // Test avec des pointeurs
    char *ptr = "test";
    compare_outputs("Pointeur vers string", "%p", ptr);

    // Test avec des caractères spéciaux
    compare_outputs("Caractère spécial", "%c", '\n');
    compare_outputs("Caractère tab", "%c", '\t');
}

void test_get_crazy() {
    print_test_header("GET CRAZY - Combinaisons folles");

    // Test avec des flags dupliqués (si implémentés)
    compare_outputs("Flags dupliqués", "%----d", 42);
    compare_outputs("Zeros multiples", "%0000d", 42);

    // Test avec des formats bizarres
    compare_outputs("Format vide avec args", "", 42, "unused");
    compare_outputs("Beaucoup de %", "%d%%%d%%%d", 1, 2, 3);

    // Test de retour de valeur
    printf("\nTest spécial valeur de retour:\n");
    int ret1 = ft_printf("Test: %d %s", 42, "hello");
    printf("\nft_printf a retourné: %d\n", ret1);
    int ret2 = printf("Test: %d %s", 42, "hello");
    printf("\nprintf a retourné: %d\n", ret2);
}

void test_bonus_simple_flags() {
    print_test_header("BONUS - Flags simples (-, 0, .)");

    // Test flag -
    compare_outputs("Flag - avec %d", "%-5d", 42);
    compare_outputs("Flag - avec INT_MIN", "%-d", INT_MIN);
    compare_outputs("Flag - avec string", "%-10s", "test");

    // Test flag 0
    compare_outputs("Flag 0 simple", "%04d", 42);
    compare_outputs("Flag 0 avec négatif", "%04d", -42);
    compare_outputs("Flag 0 large", "%010d", 123);

    // Test flag . (précision)
    compare_outputs("Précision .5", "%.5d", 42);
    compare_outputs("Précision .0", "%.0d", 42);
    compare_outputs("Précision .10", "%.10d", 123);
    compare_outputs("Précision avec string", "%.5s", "Hello World");

    // Test combinaisons
    compare_outputs("- et largeur", "%-8d", 42);
    compare_outputs("0 et largeur", "%08d", 42);
    compare_outputs("Précision et largeur", "%8.5d", 42);
}

void test_bonus_advanced_flags() {
    print_test_header("BONUS - Flags avancés (#, +, space)");

    // Test flag +
    compare_outputs("Flag + positif", "%+d", 42);
    compare_outputs("Flag + négatif", "%+d", -42);
    compare_outputs("Flag + zero", "%+d", 0);

    // Test flag space
    compare_outputs("Flag space positif", "% d", 42);
    compare_outputs("Flag space négatif", "% d", -42);
    compare_outputs("Flag space zero", "% d", 0);

    // Test flag #
    compare_outputs("Flag # avec %x", "%#x", 42);
    compare_outputs("Flag # avec %X", "%#X", 42);
    compare_outputs("Flag # avec zero", "%#x", 0);

    // Test combinaisons complexes
    compare_outputs("Tous les flags", "%#+10.5d", 42);
    compare_outputs("Flags multiples", "%+- 10d", 42);
    compare_outputs("Flags avec hex", "%#-8x", 255);
}

void test_return_values() {
    print_test_header("Test des valeurs de retour");

    printf("Comparaison des valeurs de retour:\n");

    struct {
        const char *format;
        int arg1;
        const char *arg2;
    } tests[] = {
        {"", 0, NULL},
        {"Hello", 0, NULL},
        {"%d", 42, NULL},
        {"%d %s", 42, "test"},
        {"Long string with %d and %s", 123, "multiple args"},
        {NULL, 0, NULL} // Terminateur
    };

    for (int i = 0; tests[i].format != NULL; i++) {
        int ret_ft, ret_orig;

        if (tests[i].arg2) {
            ret_ft = ft_printf(tests[i].format, tests[i].arg1, tests[i].arg2);
            printf("\n");
            ret_orig = printf(tests[i].format, tests[i].arg1, tests[i].arg2);
        } else if (tests[i].arg1 != 0 || strcmp(tests[i].format, "") != 0) {
            ret_ft = ft_printf(tests[i].format, tests[i].arg1);
            printf("\n");
            ret_orig = printf(tests[i].format, tests[i].arg1);
        } else {
            ret_ft = ft_printf(tests[i].format);
            printf("\n");
            ret_orig = printf(tests[i].format);
        }

        printf("\nft_printf: %d, printf: %d ", ret_ft, ret_orig);
        if (ret_ft == ret_orig) {
            printf(GREEN "✓" RESET);
        } else {
            printf(RED "✗" RESET);
        }
        printf("\n");
    }
}

int main() {
    printf(BLUE "=== TESTS FT_PRINTF - ÉVALUATION COMPLÈTE ===" RESET "\n");
    printf("Basé sur la fiche d'évaluation officielle de 42\n");

    // Tests obligatoires
    test_simple_conversions();
    test_multiple_args();
    test_edge_cases();
    test_get_crazy();
    test_return_values();

    // Tests bonus
    test_bonus_simple_flags();
    test_bonus_advanced_flags();

    // Résumé
    printf("\n" BLUE "=== RÉSUMÉ ===" RESET "\n");
    printf("Tests passés: %d/%d\n", passed_tests, test_count);

    if (passed_tests == test_count) {
        printf(GREEN "🎉 Tous les tests sont passés!" RESET "\n");
    } else {
        printf(YELLOW "⚠️  Certains tests ont échoué." RESET "\n");
    }

    printf("\n" YELLOW "INSTRUCTIONS D'ÉVALUATION:" RESET "\n");
    printf("1. Vérifiez que ft_printf ne crash pas\n");
    printf("2. Vérifiez l'absence de fuites mémoire avec valgrind\n");
    printf("3. Vérifiez que les valeurs de retour correspondent à printf\n");
    printf("4. Testez les cas limites et les combinaisons de flags\n");
    printf("5. Les bonus ne comptent que si la partie obligatoire est parfaite\n");

    return 0;
}
