#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BUFFER_STR 100
#define BUFFER_INT 20
#define NUM 10

typedef union Work
{
    char *work_address;
    struct
    {
        char *city;
        char *street;
        char *postOfficeCode;
    } WorkSeparated;
} Work;

typedef struct Data
{
    int day;
    int month;
    int year;
} Data;

typedef struct Citizens
{
    char *name;
    char *surname;
    Data date_birth;
    char gender;
    char *home_address;
    Work work_address;
} Citizens;

void printForm(Citizens *citizens, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Name: %s\n", citizens[i].name);
        printf("Surname: %s\n", citizens[i].surname);
        printf("Date of Birth: %d/%d/%d\n", citizens[i].date_birth.day, citizens[i].date_birth.month, citizens[i].date_birth.year);
        printf("Gender: %c\n", citizens[i].gender);
        printf("\tHome Address: %s\n", citizens[i].home_address);
        printf("Work Address:\n");
        printf("\t %s %s %s\n", citizens[i].work_address.WorkSeparated.city, citizens[i].work_address.WorkSeparated.street, citizens[i].work_address.WorkSeparated.postOfficeCode);
        printf("\n");
    }
}

void printMenu1()
{
    printf("+--------------------------------------+\n");
    printf("|               Menu                   |\n");
    printf("+--------------------------------------+\n");
    printf("| 0 - Exit                             |\n");
    printf("| 1 - Register Citizens form           |\n");
    printf("| 2 - Change register form             |\n");
    printf("| 3 - Bubble sort for surname          |\n");
    printf("| 4 - Quick sort for Work address      |\n");
    printf("+--------------------------------------+\n");
}

void printMenu2()
{
    printf("+--------------------------------------+\n");
    printf("|               Menu                   |\n");
    printf("+--------------------------------------+\n");
    printf("| 1 - Random content                   |\n");
    printf("| 2 - Input using keyboard             |\n");
    printf("+--------------------------------------+\n");
}

void printMenu3()
{
    printf("+--------------------------------------+\n");
    printf("|               Menu                   |\n");
    printf("+--------------------------------------+\n");
    printf("| 0 - Exit                             |\n");
    printf("| 1 - Name                             |\n");
    printf("| 2 - Surname                          |\n");
    printf("| 3 - Data of birthday                 |\n");
    printf("| 4 - Gender                           |\n");
    printf("| 5 - Home addres                      |\n");
    printf("| 6 - Work addres                      |\n");
    printf("+--------------------------------------+\n");
}

void registerFormKeyboard(Citizens *citizens, int n)
{
    char buffer[BUFFER_STR];

    for (int i = 0; i < n; i++)
    {
        printf("Input your name: ");
        scanf("%s", buffer);
        citizens[i].name = strdup(buffer);
        printf("\n");

        printf("Input your surname: ");
        scanf("%s", buffer);
        citizens[i].surname = strdup(buffer);
        printf("\n");

        printf("Input your data of birth: \n");
        printf("Day: ");
        scanf("%d", &citizens[i].date_birth.day);
        printf("\n");

        printf("Month: ");
        scanf("%d", &citizens[i].date_birth.month);
        printf("\n");

        printf("Year: ");
        scanf("%d", &citizens[i].date_birth.year);
        printf("\n");

        printf("Input your gender (m, f): ");
        scanf(" %c", &citizens[i].gender);
        printf("\n");

        printf("Input your home address: ");
        getchar();
        fgets(buffer, BUFFER_STR, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        citizens[i].home_address = strdup(buffer);
        printf("\n");

        printf("Input your Work address: \n");
        printf("City: ");
        scanf("%s", citizens[i].work_address.WorkSeparated.city);
        printf("\n");
        printf("Street: ");
        scanf("%s", citizens[i].work_address.WorkSeparated.street);
        printf("\n");
        printf("City: ");
        scanf("%s", citizens[i].work_address.WorkSeparated.postOfficeCode);
        printf("\n");
    }
}

void randomRegisterForm(Citizens *citizens, int n)
{
    char randomSurnames[NUM][BUFFER_STR] = {
        "Smith", "Johnson", "Williams", "Jones", "Brown",
        "Davis", "Miller", "Wilson", "Moore", "Taylor"};

    char randomNames[NUM][BUFFER_STR] = {
        "John", "Emma", "Michael", "Sophia", "William",
        "Olivia", "James", "Ava", "Alexander", "Mia"};

    char randomHomeAddresses[NUM][BUFFER_STR] = {
        "10 Main St", "20 Elm St", "30 Oak Ave", "40 Pine St", "50 Maple Ave",
        "60 Cedar St", "70 Birch Ave", "80 Walnut St", "90 Willow Ave", "100 Cherry St"};

    char randomWorkAddresses[NUM][BUFFER_STR] = {
        "10 Corporate Blvd", "20 Business Park", "30 Commerce St", "40 Industrial Ave", "50 Technology Dr",
        "60 Office Park", "70 Enterprise Rd", "80 Commercial Ave", "90 Professional Pkwy", "100 Innovation Blvd"};

    char Gender[2] = {'f', 'm'};

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        citizens[i].name = (char *)malloc(sizeof(char) * BUFFER_STR);
        citizens[i].surname = (char *)malloc(sizeof(char) * BUFFER_STR);

        strcpy(citizens[i].name, randomNames[rand() % NUM]);
        strcpy(citizens[i].surname, randomSurnames[rand() % NUM]);

        citizens[i].date_birth.day = rand() % 31 + 1;
        citizens[i].date_birth.month = rand() % 12 + 1;
        citizens[i].date_birth.year = rand() % 74 + 1950;

        citizens[i].gender = Gender[rand() % 2];

        citizens[i].home_address = (char *)malloc(sizeof(char) * BUFFER_STR);
        strcpy(citizens[i].home_address, randomHomeAddresses[rand() % NUM]);

        citizens[i].work_address.WorkSeparated.city = (char *)malloc(sizeof(char) * BUFFER_STR);
        citizens[i].work_address.WorkSeparated.street = (char *)malloc(sizeof(char) * BUFFER_STR);
        citizens[i].work_address.WorkSeparated.postOfficeCode = (char *)malloc(sizeof(char) * BUFFER_STR);

        strcpy(citizens[i].work_address.WorkSeparated.city, randomWorkAddresses[rand() % NUM]);
        strcpy(citizens[i].work_address.WorkSeparated.street, "");
        strcpy(citizens[i].work_address.WorkSeparated.postOfficeCode, "");
    }
}

void changeRegisterForm(Citizens *citizens, int n)
{
    int num;
    int sel = 1;
    char buffer[BUFFER_STR];

    printf("Input number of citizen: ");
    scanf("%d", &num);

    while (sel != 0)
    {
        printMenu3();
        printf("Select the field to change: ");
        scanf("%d", &sel);

        switch (sel)
        {
        case 0:
            return;
            break;
        case 1:
            printf("Name: ");
            free(citizens[num - 1].name);
            citizens[num - 1].name = (char *)malloc(sizeof(char) * BUFFER_STR);
            scanf("%s", citizens[num - 1].name);
            break;
        case 2:
            printf("Surname: ");
            free(citizens[num - 1].surname);
            citizens[num - 1].surname = (char *)malloc(sizeof(char) * BUFFER_STR);
            scanf("%s", citizens[num - 1].surname);
            break;
        case 3:
            printf("Day Month Year: ");
            scanf("%d %d %d", &citizens[num - 1].date_birth.day, &citizens[num - 1].date_birth.month, &citizens[num - 1].date_birth.year);
            break;
        case 4:
            printf("Gender: ");
            scanf(" %c", &citizens[num - 1].gender);
            break;
        case 5:
            printf("Home Address: ");
            getchar();
            fgets(buffer, BUFFER_STR, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            free(citizens[num - 1].home_address);
            citizens[num - 1].home_address = strdup(buffer);
            break;
        case 6:
            printf("Work Address (City Street PostCode): ");
            free(citizens[num - 1].work_address.WorkSeparated.city);
            free(citizens[num - 1].work_address.WorkSeparated.street);
            free(citizens[num - 1].work_address.WorkSeparated.postOfficeCode);
            citizens[num - 1].work_address.WorkSeparated.city = malloc(sizeof(char) * BUFFER_STR);
            citizens[num - 1].work_address.WorkSeparated.street = malloc(sizeof(char) * BUFFER_STR);
            citizens[num - 1].work_address.WorkSeparated.postOfficeCode = malloc(sizeof(char) * BUFFER_STR);
            scanf("%s %s %s", citizens[num - 1].work_address.WorkSeparated.city, citizens[num - 1].work_address.WorkSeparated.street, citizens[num - 1].work_address.WorkSeparated.postOfficeCode);
            break;
        default:
            printf("Invalid option\n");
        }
        printForm(citizens, n);
    }
}

void uppercase(char *str)
{
    while (*str)
    {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

int stringsCompare(const char *a, const char *b)
{
    char uppercaseA[BUFFER_STR];
    char uppercaseB[BUFFER_STR];

    strcpy(uppercaseA, a);
    strcpy(uppercaseB, b);

    uppercase(uppercaseA);
    uppercase(uppercaseB);

    return strcmp(uppercaseA, uppercaseB);
}

void swapStructures(Citizens *citizen1_ptr, Citizens *citizen2_ptr)
{
    Citizens temp;
    temp = *citizen1_ptr;
    *citizen1_ptr = *citizen2_ptr;
    *citizen2_ptr = temp;
}

void bubble_sort(Citizens *citizens, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (stringsCompare(citizens[j].surname, citizens[j + 1].surname) > 0)
            {
                swapStructures(&citizens[j], &citizens[j + 1]);
            }
        }
    }
}

int partition(Citizens *citizens, int low, int high)
{
    char pivot[BUFFER_STR];
    strcpy(pivot, citizens[high].work_address.WorkSeparated.city);
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (strcmp(citizens[j].work_address.WorkSeparated.city, pivot) >= 0)
        {
            i++;
            swapStructures(&citizens[i], &citizens[j]);
        }
    }
    swapStructures(&citizens[i + 1], &citizens[high]);
    return i + 1;
}

void quickSortDescending(Citizens *citizens, int low, int high)
{
    if (low < high)
    {
        int pi = partition(citizens, low, high);
        quickSortDescending(citizens, low, pi - 1);
        quickSortDescending(citizens, pi + 1, high);
    }
}

Citizens *memoryMalloc(Citizens *citizens, int n)
{
    citizens = (Citizens *)malloc(sizeof(Citizens) * n);
    for (int i = 0; i < n; i++)
    {
        citizens[i].name = NULL;
        citizens[i].surname = NULL;
        citizens[i].home_address = NULL;
        citizens[i].work_address.work_address = NULL;
        citizens[i].work_address.WorkSeparated.city = NULL;
        citizens[i].work_address.WorkSeparated.street = NULL;
        citizens[i].work_address.WorkSeparated.postOfficeCode = NULL;
    }
    return citizens;
}

void memoryFree(Citizens *citizens, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(citizens[i].name);
        free(citizens[i].surname);
        free(citizens[i].home_address);
        free(citizens[i].work_address.work_address);
        free(citizens[i].work_address.WorkSeparated.city);
        free(citizens[i].work_address.WorkSeparated.street);
        free(citizens[i].work_address.WorkSeparated.postOfficeCode);
    }
    free(citizens);
}

int main()
{
    int k;
    int t;
    int n;
    Citizens *citizens = NULL;
    printf("Input number of Citizens: ");
    scanf("%d", &n);
    citizens = memoryMalloc(citizens, n);

start:
    printMenu1();
    scanf("%d", &k);
    switch (k)
    {
    case 0:
        memoryFree(citizens, n);
        exit(1);
        break;
    case 1:
        printMenu2();
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            randomRegisterForm(citizens, n);
            break;
        case 2:
            registerFormKeyboard(citizens, n);
            break;
        }
        break;
    case 2:
        changeRegisterForm(citizens, n);
        break;
    case 3:
        bubble_sort(citizens, n);
        break;
    case 4:
        quickSortDescending(citizens, 0, n - 1);
        break;
    }

    printForm(citizens, n);

    goto start;
    return 0;
}
