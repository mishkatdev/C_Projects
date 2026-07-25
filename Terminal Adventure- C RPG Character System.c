#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


struct Character
{
    char name[30];
    int age;
    char class[20];

    int health;
    int attack;
    int level;
    int experience;
};


void createCharacter(struct Character *player)
{
    int choice;

    printf("\nEnter character name: ");
    scanf("%s", player->name);

    printf("Enter age: ");
    scanf("%d", &player->age);


    printf("\nChoose Class\n");
    printf("1. Warrior\n");
    printf("2. Mage\n");
    printf("3. Archer\n");

    printf("Choice: ");
    scanf("%d", &choice);


    switch(choice)
    {
        case 1:
            strcpy(player->class, "Warrior");
            player->health = 120;
            player->attack = 25;
            break;

        case 2:
            strcpy(player->class, "Mage");
            player->health = 90;
            player->attack = 35;
            break;

        case 3:
            strcpy(player->class, "Archer");
            player->health = 100;
            player->attack = 30;
            break;

        default:
            printf("Invalid choice! Default Warrior selected.\n");

            strcpy(player->class, "Warrior");
            player->health = 120;
            player->attack = 25;
    }


    player->level = 1;
    player->experience = 0;


    printf("\nCharacter Created Successfully!\n");
}



void displayCharacter(struct Character player)
{
    printf("\n========== CHARACTER PROFILE ==========\n");

    printf("Name       : %s\n", player.name);
    printf("Age        : %d\n", player.age);
    printf("Class      : %s\n", player.class);
    printf("Level      : %d\n", player.level);
    printf("Health     : %d\n", player.health);
    printf("Attack     : %d\n", player.attack);
    printf("Experience : %d\n", player.experience);

    printf("=======================================\n");
}



void train(struct Character *player)
{
    int choice;


    printf("\nTraining Ground\n");
    printf("1. Strength Training\n");
    printf("2. Speed Training\n");
    printf("3. Magic Training\n");

    printf("Choice: ");
    scanf("%d",&choice);


    switch(choice)
    {
        case 1:
            player->attack += 5;
            player->experience += 20;

            printf("\nAttack increased!\n");
            break;


        case 2:
            player->health += 10;
            player->experience += 20;

            printf("\nHealth increased!\n");
            break;


        case 3:
            player->attack += 8;
            player->experience += 25;

            printf("\nMagic power increased!\n");
            break;


        default:
            printf("\nInvalid training!\n");
    }


    if(player->experience >= 100)
    {
        player->level++;

        player->health += 20;
        player->attack += 10;

        player->experience = 0;


        printf("\n🎉 LEVEL UP!\n");
        printf("You reached Level %d\n", player->level);
    }
}



void battle(struct Character *player)
{
    int enemyHealth = 50;

    printf("\nA wild Goblin appeared!\n");


    while(enemyHealth > 0 && player->health > 0)
    {
        int choice;


        printf("\nYour HP: %d\n", player->health);
        printf("Enemy HP: %d\n", enemyHealth);


        printf("\n1. Attack\n");
        printf("2. Run\n");

        printf("Choice: ");
        scanf("%d",&choice);



        if(choice == 1)
        {
            enemyHealth -= player->attack;

            printf("\nYou attacked the Goblin!\n");


            if(enemyHealth > 0)
            {
                player->health -= 15;

                printf("Goblin attacked you!\n");
            }
        }


        else if(choice == 2)
        {
            printf("\nYou escaped!\n");
            return;
        }


        else
        {
            printf("Invalid choice!\n");
        }
    }



    if(player->health > 0)
    {
        printf("\n🏆 Enemy defeated!\n");


        player->experience += 50;


        printf("+50 Experience\n");


        if(player->experience >= 100)
        {
            player->level++;

            player->health += 20;
            player->attack += 10;

            player->experience = 0;


            printf("\nLEVEL UP!\n");
        }

    }

    else
    {
        printf("\n💀 You were defeated!\n");
    }
}




int main()
{
    struct Character player;

    int created = 0;
    int choice;


    srand(time(NULL));


    while(1)
    {

        printf("\n\n==============================\n");
        printf("   TERMINAL ADVENTURE RPG\n");
        printf("==============================\n");


        printf("1. Create Character\n");
        printf("2. View Profile\n");
        printf("3. Train\n");
        printf("4. Fight Enemy\n");
        printf("5. Exit\n");


        printf("\nChoose option: ");
        scanf("%d",&choice);



        switch(choice)
        {

            case 1:
                createCharacter(&player);
                created = 1;
                break;


            case 2:

                if(created)
                    displayCharacter(player);

                else
                    printf("Create a character first!\n");

                break;



            case 3:

                if(created)
                    train(&player);

                else
                    printf("Create a character first!\n");

                break;



            case 4:

                if(created)
                    battle(&player);

                else
                    printf("Create a character first!\n");

                break;



            case 5:

                printf("\nThanks for playing!\n");
                return 0;


            default:

                printf("Invalid option!\n");
        }

    }


    return 0;
}