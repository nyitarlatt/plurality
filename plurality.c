#include <stdio.h>
#include <cs50.h>
#include <string.h>

//declare new datatype

typedef struct
{
    string name;
    int votes;
}
candidate;
candidate candidates[9];

//functions

int vote(string name, int n);
void print_winner(int argc);

// main#######

int main(int argc, string argv[])
{


    //valid arguments number

    if (argc < 2 || argc > 9)
    {
        return 1;
    }

    //assign candidates into new datatype

    for (int i = 0; i + 1 < argc; i++)
    {
        candidates[i].name = argv[i + 1];
    }

    //prompt number of votes

    int vn = get_int("Number of voters: ");
    string vot;

    //valid votes and assign result

    for (int i = 0; i < vn; i++)
    {
        vot = get_string("Vote: ");
        if(vote(vot, argc) == 0)
        {
            printf("Invalid vote.\n");
            i--;
        }
    }

    //print winner

    print_winner(argc);
}

//functions

//votes

int vote(string name, int n)
{
    for (int i = 0; i + 1 < n; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return 1;
        }
    }
    return 0;
}

//print_winner

void print_winner(int argc)
{
    for(int i = 0; i < argc - 1; i++)
    {
        int c = 0;
        for (int j = 0; j < argc; j++)
        {
            if(candidates[i].votes >= candidates[j].votes)
            {
                c++;
            }
            if (c > argc -1)
            {
                printf("%s\n", candidates[i].name);
            }
        }
    }
}

