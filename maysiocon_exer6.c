#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct song_tag
{
    char title [20];
    char artist [20];
    char album [20];
    struct song_tag * nextSong ;
} song ;


typedef struct playlist_tag
{
    char name [50];
    int songCount;
    song * songHead;
    struct playlist_tag * next ;
} playlist ;


void seperator()
{
    printf("\n----------------------------\n\n");
}

//-----------------------------------

void addNew (playlist **head, int *i)
{
    char get, userInput[50], match=0;
    playlist *new = (playlist *)malloc(sizeof(playlist));
    new->next = NULL;

    printf("Enter new playlist name: ");
    scanf("%c", &get); //readline
    fgets(userInput, 50, stdin);
    memmove(&userInput[strlen(userInput)-1], &userInput[strlen(userInput)], 1); //remove \n at end of temp1

    if (*head!=NULL) //check if name already exists
    {
        playlist *temp=*head;
        while(temp!=NULL)
        {
            if (strcmp(userInput, temp->name)==0)
            {
                printf("\nSorry. The playlist name already exists.\n");
                match = 1; // match=True
                break;
            }
            temp = temp->next;
        }
    }


    //update in alphabetical order
    if (match==0)
    {
        strcpy(new->name, userInput);

        //insert at head
        if (*head==NULL || ((*head!=NULL) && (strcmp((*head)->name, new->name) > 0)) )
        {
            new->next = (*head);
            (*head)=new;
        }

        //insert mid or end
        else
        {
            playlist *temp = (*head);

            while(temp->next!=NULL && strcmp(temp->next->name, new->name) < 0 ) //string1 minus string2 is negative
            {
                temp=temp->next; //move to next node
            }
            //append
            new->next = temp->next;
            temp->next = new;
        }

    *i=*i+1; //update playlist count
    printf("\nSuccessfully updated the playlist.\n");

    }
    seperator();

}

//-----------------------------------

void printAvailable(playlist ***head)
{
    int i=1;
    printf("\nTHE AVAILABLE PLAYLIST ARE:\n");
    for(playlist *temp = **head; temp!=NULL;temp=temp->next)
        {
            printf("\t[%i] %s\n", i, temp->name);
            i++;
        }

}

//-----------------------------------

void addSong(playlist **head)
{
    char get, playlistName[50], userInput[20], change=0, match=0; //change=False

    if (*head==NULL)
    {
        printf("\nThere are still no playlist!\n");
    }

    else
    {
        song *newSong = (song*)malloc(sizeof(song));
        newSong->nextSong = NULL;

        printAvailable(&head);
        printf("\nEnter playlist name: ");
        scanf("%c", &get); //readline
        fgets(playlistName, 50, stdin);
        memmove(&playlistName[strlen(playlistName)-1], &playlistName[strlen(playlistName)], 1); //remove \n at end


        //if playlist exists
        for (playlist* temp = (*head); temp!=NULL;temp=temp->next)
        {
            if (strcmp(playlistName, temp->name)==0)
            {
                printf("Enter song title: ");
                scanf(" %[^\n]s",userInput);

                //check if already song exists (match=1)
                if(temp->songHead!=NULL)
                {
                    //traverse thru songlist
                    for (song *tempHold = (temp->songHead); tempHold!=NULL; tempHold=tempHold->nextSong)
                    {
                        if(strcmp(userInput, tempHold->title)==0)
                        {
                            printf("\nSorry. The song already exists in this playlist.\n");
                            match=1;
                            break;
                        }
                    }
                }

                if (match==0)
                {
                    temp->songCount= (temp->songCount)+1; //update songCount
                    strcpy(newSong->title, userInput);

                    //ask for artist
                    printf("Enter artist name: ");
                    scanf(" %[^\n]s",userInput);
                    strcpy(newSong->artist, userInput);

                    //ask for album
                    printf("Enter album name: ");
                    scanf(" %[^\n]s",userInput);
                    strcpy(newSong->album, userInput);


                    //update in alphabetical order
                    //insert at head
                    if (temp->songHead==NULL|| ((temp->songHead!=NULL) && (strcmp((temp)->songHead->title, newSong->title) > 0)) )
                    {
                        newSong->nextSong = temp->songHead;
                        temp->songHead=newSong;
                    }


                    //insert mid or end
                    else
                    {
                        song *tempHold = (temp->songHead);

                        while(tempHold->nextSong!=NULL && strcmp(tempHold->nextSong->title, newSong->title) < 0 ) //string1 minus string2 is negative
                        {
                            tempHold=tempHold->nextSong; //move to next node
                        }
                        //append
                        newSong->nextSong = tempHold->nextSong;
                        tempHold->nextSong = newSong;
                    }

                printf("\nSuccesfully updated the song list.\n");
                change=1; //change=True
                break; //stop traversing
                }
            }

        }

        if (change==0)
        {
            printf("\nSorry. The playlist does not exists in our records.\n");
        }


    seperator();
    }
}

//-----------------------------------

void listOfSongs(playlist **temp)
{
    int i=1;
    printf("PLAYLIST: %s\nSONGCOUNT: %i\n\n", (*temp)->name, (*temp)->songCount);
    for (song *tempHold = ((*temp)->songHead); tempHold!=NULL; tempHold=tempHold->nextSong)
    {
        printf("\t[%i] SONG TITLE: %s\n", i, tempHold->title);
        printf("\tARTIST: %s\n", tempHold->artist);
        printf("\tALBUM: %s\n\n", tempHold->album);
        i++;
    }
}

//-----------------------------------

void removeSong(playlist **head)
{
    if (*head==NULL)
    {
        printf("\nThere are still no playlist!\n");
    }

    else
    {
        char get, playlistName[50], userInput[20], artistName[20], change=0, match=0; //change=False

        printAvailable(&head);
        printf("\nEnter playlist name: ");
        scanf("%c", &get); //readline
        fgets(playlistName, 50, stdin);
        memmove(&playlistName[strlen(playlistName)-1], &playlistName[strlen(playlistName)], 1); //remove \n at end of temp1


        //if playlist exists
        for (playlist* temp = (*head); temp!=NULL;temp=temp->next)
        {
            if (strcmp(playlistName, temp->name)==0)
            {
                //check if there are songs
                if(temp->songHead!=NULL)
                {
                    listOfSongs(&temp); //print options

                    printf("Enter song title you wish to remove: ");
                    scanf(" %[^\n]s",userInput);

                    printf("Enter artist: ");
                    scanf(" %[^\n]s", artistName);

                    //traverse thru songlist
                    song *tempHold=(temp->songHead);
                    while(tempHold!=NULL)
                    {
                        if(strcmp(userInput, tempHold->title)==0)
                        {
                            //check if same artist
                            if (strcmp(artistName, tempHold->artist)==0)
                            {
                                match=1; //song exists in playlist
                                break;
                            }
                        }
                        tempHold = tempHold->nextSong;
                    }


                    if (match==0) //if song DNE
                    {
                        printf("\nSorry. The song does not exist in this playlist.\n");
                    }

                    else //proceed to delete
                    {
                        temp->songCount= (temp->songCount)-1; //update songCount
                        //delete at head
                        if (tempHold==temp->songHead)
                        {
                            temp->songHead=temp->songHead->nextSong;
                            free(tempHold);
                        }

                        //delete at mid or tail
                        else
                        {
                            song *tempFind = temp->songHead;
                            while(tempFind->nextSong != tempHold)
                            {
                                tempFind=tempFind->nextSong;
                            }

                            tempFind->nextSong = tempHold->nextSong;
                            free(tempHold);
                        }

                        printf("\nSuccessfully deleted the song.");
                    }

                }

                else
                {
                    printf("\nThere are no songs in this playlist yet!\n");
                }

                change=1; //change=True
                break; //stop traversing
                printf("\nSuccesfully removed the song.");
            }

        }

        if (change==0)
        {
            printf("\nSorry. The playlist does not exists in our records.\n");
        }
    }


    seperator();
}

//-----------------------------------

void viewPlaylist(playlist **head)
{
    if (*head==NULL)
    {
        printf("\nThere are still no playlist!\n");
    }

    else
    {
        char get, playlistName[50], userInput[50], change=0; //change=False

        printAvailable(&head);
        printf("\nEnter playlist name: ");
        scanf("%c", &get); //readline
        fgets(playlistName, 50, stdin);
        memmove(&playlistName[strlen(playlistName)-1], &playlistName[strlen(playlistName)], 1); //remove \n at end of temp1

        //if playlist exists
        for (playlist* temp = (*head); temp!=NULL;temp=temp->next)
        {
            if (strcmp(temp->name, playlistName)==0)
            {
                if (temp->songHead!=NULL)
                {

                    listOfSongs(&temp); //print options
                }
                else
                {
                    printf("\nThere are no songs in this playlist yet!\n");
                }

                change = 1;
                break; //end traverse
            }
        }

        if (change==0)
        {
            printf("\nSorry. The playlist does not exists in our records.\n");
        }
    }
    seperator();
}

//-----------------------------------

void printAll(playlist **head)
{
    if (*head==NULL)
    {
        printf("\nThere are still no playlist!\n");
    }

    else
    {
        printf("\nEVERY PLAYLIST AND SONG:\n\n");
        for(playlist *temp = *head; temp!=NULL; temp = temp->next)
        {
            printf("PLAYLIST: %s\nSONG COUNT: %i\n\n", temp->name, temp->songCount);
                for (song *tempHold = ((temp)->songHead); tempHold!=NULL; tempHold=tempHold->nextSong)
                {
                    printf("\tSONG TITLE: %s\n", tempHold->title);
                    printf("\tARTIST: %s\n", tempHold->artist);
                    printf("\tALBUM: %s\n\n", tempHold->album);
                }
        }
    }

    seperator();
}

//-----------------------------------

void savePlaylist(playlist **head, int i)
{
    playlist *temp = *head;

    FILE *openfile = fopen("exer6data.txt", "w");
    if( temp == NULL )
    {
        i=0;
        fprintf(openfile,"%d\n", i);
    }

    else
    {
        fprintf(openfile,"%d\n", i);

        for(temp=*head; temp!=NULL; temp = temp->next)
        {
            fprintf(openfile,"%s\n",temp->name); //write playlist data
            fprintf(openfile,"%d\n",temp->songCount);

            if (temp->songHead!=NULL)
            {
                for (song *tempHold = (temp->songHead); tempHold!=NULL; tempHold=tempHold->nextSong) //write song structure
                {
                    fprintf(openfile,"%s\n",tempHold->title);
                    fprintf(openfile,"%s\n",tempHold->artist);
                    fprintf(openfile,"%s\n",tempHold->album);
                }

            }
        }

    }

    seperator(); printf("     SAVED SUCCESSFULLY.\n"); seperator();
    fclose(openfile);
}

//-----------------------------------

void loadPlaylist(playlist **head, int *i)
{
    FILE *closefile = fopen("exer6data.txt","r");
    char get;
    if (closefile != NULL) //if not empty
    {
        fscanf(closefile,"%d\n", i);
        if(*(i)!=0)
        {
            for(int j=0; j<(*i); j++) //initialize Playlist
            {
                playlist *new = (playlist*)malloc(sizeof(playlist));
                new->next = NULL;

                fscanf(closefile, " %[^\n]s", new->name); //load playlist file
                fscanf(closefile,"%d", &(new->songCount));
                fscanf(closefile, "%c", &get); //extra


                //load Songs of "new" playlist
                for (int k=0; k < new->songCount; k++)
                {
                    song *newSong = (song*)malloc(sizeof(song));
                    newSong->nextSong = NULL;

                    fscanf(closefile, " %[^\n]", newSong->title);
                    fscanf(closefile, " %[^\n]", newSong->artist);
                    fscanf(closefile, " %[^\n]", newSong->album);

                    //alphabetical order the newSong vs songs existing

                    //insert in head
                    if (new->songHead==NULL || (new->songHead!=NULL)&&(strcmp(new->songHead->title, newSong->title) > 0))
                    {
                        newSong->nextSong = new->songHead;
                        new->songHead=newSong;
                    }

                    //insert in mid or end
                    else
                    {
                        song *tempHold = (new->songHead);

                        while(tempHold->nextSong!=NULL && strcmp(tempHold->nextSong->title, newSong->title)<0)
                        {
                            tempHold=tempHold->nextSong; //move to next node 
                        }
                        //append
                        newSong->nextSong = tempHold->nextSong;
                        tempHold->nextSong = newSong;
                    }

                    newSong=NULL; //reset


                }

                //sort "new" Playlist alphabetically
                //insert at head
                if (*head==NULL || ((*head!=NULL) && (strcmp((*head)->name, new->name) > 0)) )
                {
                    new->next = (*head);
                    *head = new;
                }

                //insert mid or end
                else
                {
                    playlist *temp = (*head); //initialize
                    while(temp->next!=NULL && strcmp(temp->next->name, new->name) < 0 ) //string1 minus string2 is negative
                    {
                        temp=temp->next; //move to next node
                    }
                    //append
                    new->next = temp->next;
                    temp->next = new;
                }
                
        }
        seperator(); printf("   LOADED SUCCESSFULLY.\n"); seperator();
        fclose(closefile);
    }


    }
}

//-----------------------------------

void freeAll(playlist **head)
{
    while (*head!=NULL)
    {
        playlist *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}



//-----------------------------------
int main()
{
    playlist *head = NULL;
    int choice, i=0; //i tracker ng ilang playlist nagawa
    loadPlaylist(&head, &i);


    while(1)
    {
        printf("========================\n\tWELCOME!\n========================\n");
        printf("[1] Add Playlist\n");
        printf("[2] Add Song to Playlist\n");
        printf("[3] Remove Song from the Playlist\n");
        printf("[4] View a Playlist\n");
        printf("[5] View all data\n");
        printf("[0] Exit\n\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice==1)
        {
            addNew(&head, &i);
        }

        else if (choice==2)
        {
            addSong(&head);
        }

        else if (choice==3)
        {
            removeSong(&head);
        }

        else if (choice==4)
        {
            viewPlaylist(&head);
        }

        else if (choice==5)
        {
            printAll(&head);
        }

        else if (choice==0)
        {
            savePlaylist(&head, i);
            freeAll(&head); //free mallocs
            printf("\nAll changes has been saved.\n");
            break; //exit
        }

        else
        {
            printf("Invalid. Input a new number.\n\n");
        }
    }
    return 0;

}
