#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char players_path[] = "Resources/players.txt";
    char slots_path[] = "Resources/slots.txt";

    int playerCount = 0;
    int slotCount = 0;

    FILE *players; FILE *slots;
    players = fopen(players_path, "r");
    slots = fopen(slots_path, "r");
    if(players==NULL || slots==NULL){ return 1;}
    

    char temp[51];
    while((fgets(temp,50,players)) != NULL)
    {
        playerCount++;
    }
    while((fgets(temp,50,slots)) != NULL)
    {
        slotCount++;
    }
    printf("Counted %d players.\n", playerCount);
    printf("Counted %d slots.\n", slotCount);
    fclose(players); fclose(slots); // Close file pointers to allow them to be reset later
    
    // Allocate array memory for playerCount players.
    char **players_strings = (char **) malloc(playerCount * sizeof(char *));
    for (int i = 0; i < playerCount; i++) {
        players_strings[i] = (char *) malloc(50 * sizeof(char));
    }
    
    // Allocate array memory for slotCount slots.
    char **slots_strings = (char **) malloc(slotCount * sizeof(char *));
    for (int i = 0; i < slotCount; i++) {
        slots_strings[i] = (char *) malloc(50 * sizeof(char));
    }

    players = fopen(players_path, "r");
    slots = fopen(slots_path, "r");

    for(int i = 0; i < playerCount; i++)
    {
        if((fgets(temp,50,players)) != NULL)
        {
            strcpy(players_strings[i], temp);
        }
        
    }

    for(int i = 0; i < slotCount; i++)
    {
        if((fgets(temp,50,slots)) != NULL)
        {
            strcpy(slots_strings[i], temp);
        }
    }
    



    free(players_strings); free(slots_strings);
    fclose(players); fclose(slots);
    return 0;
}
