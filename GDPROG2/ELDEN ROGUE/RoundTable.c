

void runRoundTable(Player* player)
{
    char cInput;
    printf("\nWELCOME\n");
    displayRoundTable(player);
    scanf(" %c",&cInput);
    
    
}

void displayRoundTable(Player* player)
{
            printf("Name: %s\n", player->name);
            printf("Job Class: %s\n", player->jobName);
            printf("Level: %d\n", player->level);

    printf("Fast travel\n");
    printf("Level Up\n");
    printf("Inventory\n");
    printf("Shop\n");
    printf("Save\n");
    printf("Quit Game\n");

    printf("INPUT:");
   
}

