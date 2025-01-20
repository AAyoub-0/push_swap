/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 03:37:11 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/20 22:19:40 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
# include <time.h>

void generate_unique_numbers(int *array, int size, int min, int max) {
    if (max - min + 1 < size) {
        fprintf(stderr, "Erreur : plage trop petite pour générer des nombres uniques.\n");
        exit(EXIT_FAILURE);
    }

    // Remplir un tableau temporaire avec tous les nombres possibles
    int range = max - min + 1;
    int temp[range];
    for (int i = 0; i < range; i++) {
        temp[i] = min + i;
    }

    // Mélanger les nombres dans le tableau temporaire
    for (int i = range - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int swap = temp[i];
        temp[i] = temp[j];
        temp[j] = swap;
    }

    // Copier les premiers "size" éléments dans le tableau final
    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }
}

void filter_output(const char *output, int *num_i) {
    // Liste des mots à filtrer
    const char *keywords[] = {"ra", "rb", "rr", "sa", "sb", "pa", "pb", "rra", "rrb", "rrr"};
    size_t keywords_count = sizeof(keywords) / sizeof(keywords[0]);
    int print_line = 1;

    // Vérifie si une ligne contient un des mots-clés
    for (size_t i = 0; i < keywords_count; i++) {
        if (ft_strnstr(output, keywords[i], ft_strlen(keywords[i])) != NULL) {
            (*num_i)++;
            print_line = 0; // Ne pas afficher la ligne
            break;
        }
    }

    if (print_line) {
        printf("%s", output); // Affiche la ligne si elle ne contient pas de mots-clés
    }
}

void run_and_filter(t_bool (*test_function)(char *, int, int*), char *name, int size, int* array, int **i_num_total) {
    // Sauvegarde stdout
    int stdout_copy = dup(fileno(stdout));
    int num_i = 0;

    // Redirige stdout vers un fichier temporaire
    FILE *tmp = tmpfile();
    if (!tmp) {
        perror("tmpfile");
        return;
    }

    int tmp_fd = fileno(tmp);
    dup2(tmp_fd, fileno(stdout));

    // Exécute la fonction de test
    test_function(name, size, array);

    // Restaure stdout
    fflush(stdout);
    dup2(stdout_copy, fileno(stdout));
    close(stdout_copy);

    // Lit et filtre le contenu du fichier temporaire
    rewind(tmp);
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), tmp)) {
        filter_output(buffer, &num_i);
    }
    printf("\033[0;33mNumber of instructions: %d\033[0m\n", num_i);
    int test_num = ft_atoi(name + 5);
    (*i_num_total)[test_num - 1] = num_i;
    
    fclose(tmp);
}

t_bool    sort_test(char *test, int size, int *array)
{
    t_stack *stack_a = stack_create(size, 'a');
    t_stack *stack_b = stack_create(size, 'b');
    t_bool  success = true;
    stack_push_array(stack_a, array, size);

    stack_print(stack_a);
    if (size == 3)
        sort_three(stack_a);
    else if (size == 4)
        sort_four(stack_a, stack_b);
    else if (size == 5)
        sort_five(stack_a, stack_b);
    else
        sort_large(stack_a, stack_b);
    stack_print(stack_a);
    if  (is_sorted(stack_a) && stack_b->top == -1 && stack_a->top == size - 1) 
        printf("\033[0;32m%s OK\033[0m\n", test);
    else
    {
        success = false;
        printf("\033[0;31m%s KO\033[0m\n", test);
    }
    stack_destroy(stack_a);
    stack_destroy(stack_b);
    return (success);
}

void    size_3_test()
{
    printf("SIZE OF THREE\n");
    sort_test("TEST 1", 3, (int[]){1, 2, 3});
    sort_test("TEST 2", 3, (int[]){1, 3, 2});
    sort_test("TEST 3", 3, (int[]){2, 1, 3});
    sort_test("TEST 4", 3, (int[]){2, 3, 1});
    sort_test("TEST 5", 3, (int[]){3, 1, 2});
    sort_test("TEST 6", 3, (int[]){3, 2, 1});
    printf("\n");
}

void    size_4_test()
{
    printf("SIZE OF FOUR\n");
    sort_test("TEST 1", 4, (int[]){1, 2, 3, 4});
    sort_test("TEST 2", 4, (int[]){1, 2, 4, 3});
    sort_test("TEST 3", 4, (int[]){1, 3, 2, 4});
    sort_test("TEST 4", 4, (int[]){1, 3, 4, 2});
    sort_test("TEST 5", 4, (int[]){1, 4, 2, 3});
    sort_test("TEST 6", 4, (int[]){1, 4, 3, 2});
    sort_test("TEST 7", 4, (int[]){2, 1, 3, 4});
    sort_test("TEST 8", 4, (int[]){2, 1, 4, 3});
    sort_test("TEST 9", 4, (int[]){2, 3, 1, 4});
    sort_test("TEST 10", 4, (int[]){2, 3, 4, 1});
    sort_test("TEST 11", 4, (int[]){2, 4, 1, 3});
    sort_test("TEST 12", 4, (int[]){2, 4, 3, 1});
    sort_test("TEST 13", 4, (int[]){3, 1, 2, 4});
    sort_test("TEST 14", 4, (int[]){3, 1, 4, 2});
    sort_test("TEST 15", 4, (int[]){3, 2, 1, 4});
    sort_test("TEST 16", 4, (int[]){3, 2, 4, 1});
    sort_test("TEST 17", 4, (int[]){3, 4, 1, 2});
    sort_test("TEST 18", 4, (int[]){3, 4, 2, 1});
    sort_test("TEST 19", 4, (int[]){4, 1, 2, 3});
    sort_test("TEST 20", 4, (int[]){4, 1, 3, 2});
    sort_test("TEST 21", 4, (int[]){4, 2, 1, 3});
    sort_test("TEST 22", 4, (int[]){4, 2, 3, 1});
    sort_test("TEST 23", 4, (int[]){4, 3, 1, 2});
    sort_test("TEST 24", 4, (int[]){4, 3, 2, 1});
    printf("\n");
}

void    size_5_test()
{
    printf("SIZE OF FIVE\n");
    sort_test("TEST 1", 5, (int[]){1, 2, 3, 4, 5});
    sort_test("TEST 2", 5, (int[]){1, 2, 3, 5, 4});
    sort_test("TEST 3", 5, (int[]){1, 2, 4, 3, 5});
    sort_test("TEST 4", 5, (int[]){1, 2, 4, 5, 3});
    sort_test("TEST 5", 5, (int[]){1, 2, 5, 3, 4});
    sort_test("TEST 6", 5, (int[]){1, 2, 5, 4, 3});
    sort_test("TEST 7", 5, (int[]){1, 3, 2, 4, 5});
    sort_test("TEST 8", 5, (int[]){1, 3, 2, 5, 4});
    sort_test("TEST 9", 5, (int[]){1, 3, 4, 2, 5});
    sort_test("TEST 10", 5, (int[]){1, 3, 4, 5, 2});
    sort_test("TEST 11", 5, (int[]){1, 3, 5, 2, 4});
    sort_test("TEST 12", 5, (int[]){1, 3, 5, 4, 2});
    sort_test("TEST 13", 5, (int[]){1, 4, 2, 3, 5});
    sort_test("TEST 14", 5, (int[]){1, 4, 2, 5, 3});
    sort_test("TEST 15", 5, (int[]){1, 4, 3, 2, 5});
    sort_test("TEST 16", 5, (int[]){1, 4, 3, 5, 2});
    sort_test("TEST 17", 5, (int[]){1, 4, 5, 2, 3});
    sort_test("TEST 18", 5, (int[]){1, 4, 5, 3, 2});
    sort_test("TEST 19", 5, (int[]){1, 5, 2, 3, 4});
    sort_test("TEST 20", 5, (int[]){1, 5, 2, 4, 3});
    sort_test("TEST 21", 5, (int[]){1, 5, 3, 2, 4});
    sort_test("TEST 22", 5, (int[]){1, 5, 3, 4, 2});
    sort_test("TEST 23", 5, (int[]){1, 5, 4, 2, 3});
    sort_test("TEST 24", 5, (int[]){1, 5, 4, 3, 2});
    sort_test("TEST 25", 5, (int[]){2, 1, 3, 4, 5});
    sort_test("TEST 26", 5, (int[]){2, 1, 3, 5, 4});
    sort_test("TEST 27", 5, (int[]){2, 1, 4, 3, 5});
    sort_test("TEST 28", 5, (int[]){2, 1, 4, 5, 3});
    sort_test("TEST 29", 5, (int[]){2, 1, 5, 3, 4});
    sort_test("TEST 30", 5, (int[]){2, 1, 5, 4, 3});
    sort_test("TEST 31", 5, (int[]){2, 3, 1, 4, 5});
    sort_test("TEST 32", 5, (int[]){2, 3, 1, 5, 4});
    sort_test("TEST 33", 5, (int[]){2, 3, 4, 1, 5});
    sort_test("TEST 34", 5, (int[]){2, 3, 4, 5, 1});
    sort_test("TEST 35", 5, (int[]){2, 3, 5, 1, 4});
    sort_test("TEST 36", 5, (int[]){2, 3, 5, 4, 1});
    sort_test("TEST 37", 5, (int[]){2, 4, 1, 3, 5});
    sort_test("TEST 38", 5, (int[]){2, 4, 1, 5, 3});
    sort_test("TEST 39", 5, (int[]){2, 4, 3, 1, 5});
    sort_test("TEST 40", 5, (int[]){2, 4, 3, 5, 1});
    sort_test("TEST 41", 5, (int[]){2, 4, 5, 1, 3});
    sort_test("TEST 42", 5, (int[]){2, 4, 5, 3, 1});
    sort_test("TEST 43", 5, (int[]){2, 5, 1, 3, 4});
    sort_test("TEST 44", 5, (int[]){2, 5, 1, 4, 3});
    sort_test("TEST 45", 5, (int[]){2, 5, 3, 1, 4});
    sort_test("TEST 46", 5, (int[]){2, 5, 3, 4, 1});
    sort_test("TEST 47", 5, (int[]){2, 5, 4, 1, 3});
    sort_test("TEST 48", 5, (int[]){2, 5, 4, 3, 1});
    sort_test("TEST 49", 5, (int[]){3, 1, 2, 4, 5});
    sort_test("TEST 50", 5, (int[]){3, 1, 2, 5, 4});
    sort_test("TEST 51", 5, (int[]){3, 1, 4, 2, 5});
    sort_test("TEST 52", 5, (int[]){3, 1, 4, 5, 2});
    sort_test("TEST 53", 5, (int[]){3, 1, 5, 2, 4});
    sort_test("TEST 54", 5, (int[]){3, 1, 5, 4, 2});
    sort_test("TEST 55", 5, (int[]){3, 2, 1, 4, 5});
    sort_test("TEST 56", 5, (int[]){3, 2, 1, 5, 4});
    sort_test("TEST 57", 5, (int[]){3, 2, 4, 1, 5});
    sort_test("TEST 58", 5, (int[]){3, 2, 4, 5, 1});
    sort_test("TEST 59", 5, (int[]){3, 2, 5, 1, 4});
    sort_test("TEST 60", 5, (int[]){3, 2, 5, 4, 1});
    sort_test("TEST 61", 5, (int[]){3, 4, 1, 2, 5});
    sort_test("TEST 62", 5, (int[]){3, 4, 1, 5, 2});
    sort_test("TEST 63", 5, (int[]){3, 4, 2, 1, 5});
    sort_test("TEST 64", 5, (int[]){3, 4, 2, 5, 1});
    sort_test("TEST 65", 5, (int[]){3, 4, 5, 1, 2});
    sort_test("TEST 66", 5, (int[]){3, 4, 5, 2, 1});
    sort_test("TEST 67", 5, (int[]){3, 5, 1, 2, 4});
    sort_test("TEST 68", 5, (int[]){3, 5, 1, 4, 2});
    sort_test("TEST 69", 5, (int[]){3, 5, 2, 1, 4});
    sort_test("TEST 70", 5, (int[]){3, 5, 2, 4, 1});
    sort_test("TEST 71", 5, (int[]){3, 5, 4, 1, 2});
    sort_test("TEST 72", 5, (int[]){3, 5, 4, 2, 1});
    sort_test("TEST 73", 5, (int[]){4, 1, 2, 3, 5});
    sort_test("TEST 74", 5, (int[]){4, 1, 2, 5, 3});
    sort_test("TEST 75", 5, (int[]){4, 1, 3, 2, 5});
    sort_test("TEST 76", 5, (int[]){4, 1, 3, 5, 2});
    sort_test("TEST 77", 5, (int[]){4, 1, 5, 2, 3});
    sort_test("TEST 78", 5, (int[]){4, 1, 5, 3, 2});
    sort_test("TEST 79", 5, (int[]){4, 2, 1, 3, 5});
    sort_test("TEST 80", 5, (int[]){4, 2, 1, 5, 3});
    sort_test("TEST 81", 5, (int[]){4, 2, 3, 1, 5});
    sort_test("TEST 82", 5, (int[]){4, 2, 3, 5, 1});
    sort_test("TEST 83", 5, (int[]){4, 2, 5, 1, 3});
    sort_test("TEST 84", 5, (int[]){4, 2, 5, 3, 1});
    sort_test("TEST 85", 5, (int[]){4, 3, 1, 2, 5});
    sort_test("TEST 86", 5, (int[]){4, 3, 1, 5, 2});
    sort_test("TEST 87", 5, (int[]){4, 3, 2, 1, 5});
    sort_test("TEST 88", 5, (int[]){4, 3, 2, 5, 1});
    sort_test("TEST 89", 5, (int[]){4, 3, 5, 1, 2});
    sort_test("TEST 90", 5, (int[]){4, 3, 5, 2, 1});
    sort_test("TEST 91", 5, (int[]){4, 5, 1, 2, 3});
    sort_test("TEST 92", 5, (int[]){4, 5, 1, 3, 2});
    sort_test("TEST 93", 5, (int[]){4, 5, 2, 1, 3});
    sort_test("TEST 94", 5, (int[]){4, 5, 2, 3, 1});
    sort_test("TEST 95", 5, (int[]){4, 5, 3, 1, 2});
    sort_test("TEST 96", 5, (int[]){4, 5, 3, 2, 1});
    sort_test("TEST 97", 5, (int[]){5, 1, 2, 3, 4});
    sort_test("TEST 98", 5, (int[]){5, 1, 2, 4, 3});
    sort_test("TEST 99", 5, (int[]){5, 1, 3, 2, 4});
    sort_test("TEST 100", 5, (int[]){5, 1, 3, 4, 2});
    sort_test("TEST 101", 5, (int[]){5, 1, 4, 2, 3});
    sort_test("TEST 102", 5, (int[]){5, 1, 4, 3, 2});
    sort_test("TEST 103", 5, (int[]){5, 2, 1, 3, 4});
    sort_test("TEST 104", 5, (int[]){5, 2, 1, 4, 3});
    sort_test("TEST 105", 5, (int[]){5, 2, 3, 1, 4});
    sort_test("TEST 106", 5, (int[]){5, 2, 3, 4, 1});
    sort_test("TEST 107", 5, (int[]){5, 2, 4, 1, 3});
    sort_test("TEST 108", 5, (int[]){5, 2, 4, 3, 1});
    sort_test("TEST 109", 5, (int[]){5, 3, 1, 2, 4});
    sort_test("TEST 110", 5, (int[]){5, 3, 1, 4, 2});
    sort_test("TEST 111", 5, (int[]){5, 3, 2, 1, 4});
    sort_test("TEST 112", 5, (int[]){5, 3, 2, 4, 1});
    sort_test("TEST 113", 5, (int[]){5, 3, 4, 1, 2});
    sort_test("TEST 114", 5, (int[]){5, 3, 4, 2, 1});
    sort_test("TEST 115", 5, (int[]){5, 4, 1, 2, 3});
    sort_test("TEST 116", 5, (int[]){5, 4, 1, 3, 2});
    sort_test("TEST 117", 5, (int[]){5, 4, 2, 1, 3});
    sort_test("TEST 118", 5, (int[]){5, 4, 2, 3, 1});
    sort_test("TEST 119", 5, (int[]){5, 4, 3, 1, 2});
    sort_test("TEST 120", 5, (int[]){5, 4, 3, 2, 1});
    sort_test("TEST 120", 5, (int[]){100, 99, 98, 97, 96});
    printf("\n");
}

void    size_100_test()
{
    printf("SIZE OF 100\n");
    int array[100];
    generate_unique_numbers(array, 100, 1, 100);
    sort_test("TEST 1", 100, array);
    printf("\n");
}

void    size_500_test()
{
    printf("SIZE OF 500\n");
    int array[500];
    int test = 10;
    int *i_num_total = malloc(sizeof(int) * test);
    generate_unique_numbers(array, 500, 1, 500);
    run_and_filter(sort_test, "TEST 1", 500, array, &i_num_total);
    generate_unique_numbers(array, 500, -250, 250);
    run_and_filter(sort_test, "TEST 2", 500, array, &i_num_total);
    generate_unique_numbers(array, 500, -100, 500);
    run_and_filter(sort_test, "TEST 3", 500, array, &i_num_total);
    generate_unique_numbers(array, 500, -500, 500);
    run_and_filter(sort_test, "TEST 4", 500, array, &i_num_total);
    generate_unique_numbers(array, 500, -1000, 1000);
    run_and_filter(sort_test, "TEST 5", 500, array, &i_num_total);
    generate_unique_numbers(array, 500, -2500, 2500);
    run_and_filter(sort_test, "TEST 6", 500, array, &i_num_total);
    generate_unique_numbers(array, 500, -5000, 5000);
    run_and_filter(sort_test, "TEST 7", 500, array, &i_num_total);
    generate_unique_numbers(array, 500, -10000, 10000);
    run_and_filter(sort_test, "TEST 8", 500, array, &i_num_total);
    generate_unique_numbers(array, 500, -25000, 25000);
    run_and_filter(sort_test, "TEST 9", 500, array, &i_num_total);
    generate_unique_numbers(array, 500, -50000, 50000);
    run_and_filter(sort_test, "TEST 10", 500, array, &i_num_total);
    int avg = 0;
    ft_print_array_int(i_num_total, test);
    for (int i = 0; i < test; i++)
        avg += i_num_total[i];
    avg /= test;
    if (avg < 5500)
        printf("\033[0;32mAVERAGE NUMBER OF INSTRUCTIONS: %d\033[0m\n", avg);
    else
        printf("\033[0;31mAVERAGE NUMBER OF INSTRUCTIONS: %d\033[0m\n", avg);
    printf("\n");
}

void    test_targets()
{
    printf("\n");
    printf("Test of targets\n");
    int size = 500;
    t_stack *stack_a = stack_create(size, 'a');
    t_stack *stack_b = stack_create(size, 'b');
    int array[size];
    generate_unique_numbers(array, size, 1, size);
    stack_push_array(stack_a, array, size);
    
    stack_print(stack_a);
    stack_print(stack_b);
    sort_large(stack_a, stack_b);
    stack_print(stack_a);
    stack_print(stack_b);

    if (is_sorted(stack_a))
        printf("\033[0;32mTEST OK\033[0m\n");
    else
        printf("\033[0;31mTEST KO\033[0m\n");

    printf("\n");
}