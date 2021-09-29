// problem statement:  Program to find the cheapest walnuts in Raghunath Bazaar of Jammu.//
#include <stdio.h>
#include <stdlib.h>
typedef struct data        // typedef enables us to use node by its name not by its type
{
    char shop[50];       // structre member which is a string and will hold the name of the shop
    int walnuts;        // integer type structure member which will store the price of walnut
    struct data *next; // this will hold the address of the next node
} node;
node *head = NULL;   // this varaible will hold the address of first node in the list , initially assigning null to it

void data() //function to store the data of shops and price of walnut
{
    node *ptr, *temp;                    //for nodes
    ptr = (node *)malloc(sizeof(node)); //allocation of node in the memory

    if (ptr == NULL) //if ptr returns null that means the memory is not available in the ram
    {
        printf("Memory not available\n");
    }
    else
    {
        printf("Enter the shop name\n");               //Asking the user to enter the shop name
        scanf("%*c%[^\n]", &ptr->shop);                //taking input from the user using scanf function
        printf("Enter the price of walnuts per kg\n"); //Asking the user to enter the price of the walnuts
        scanf("%d", &ptr->walnuts);                    //taking input from the user using scanf function
        ptr->next = NULL;

        if (head == NULL) //if the list is empty
        {
            head = ptr; //now both points towards first node
        }
        else //else we will enter the data at the end
        {
            temp = head;               //assigning the value of head to a temporary variable i.e. temp to save the adderss
            while (temp->next != NULL) //traversing the list to the last element of the list
            {
                temp = temp->next;
            }
            temp->next = ptr; //assigning the next of temp the address of ptr which is the new node
        }
    }
}

void min() //function to finding the minimum value of walnut
{
    int min;
    char *shopName;
    node *temp, *ptr; //temporary node declaration
    temp = head;      //assigning the value of head to a temporary variable i.e. temp

    if (head == NULL) //if the list is empty
    {
        printf("No data available\n");
    }
    else
    {
        shopName = temp->shop; // holds the name of the shop which is stored in shop member of the temp node
        min = temp->walnuts;   //initialising min with the price of walnut which is stored in the walnut member of temp node
        while (temp != NULL)   //traversing the list till the end
        {
            if (min > temp->walnuts) //if the price of min i.e. price of walnut is greater than the price of the walnut of next shop
            {
                shopName = temp->shop; // will move to the shop which has the price of walnut less than the previous shop
                min = temp->walnuts;
            }
            temp = temp->next;
        }
        printf("Shop name selling walnuts minimun :%s\n", shopName); //printing the name of the shop with the cheapest price of walnuts
        printf("Cheapest price of walnuts:%d/kg\n", min);            //printing the price of walnuts with the cheapest price
        printf("Press any key to continue");
    }
}

void view() //function to view all the data
{
    node *temp;
    if (head == NULL) //if the list is empty
    {
        printf("No data available\n");
    }
    else
    {
        temp = head;
        while (temp != NULL) //traversing the list
        {
            printf("Shop name:%s\n", temp->shop);              //printing the name of the shop
            printf("Price of walnuts:%d/kg\n", temp->walnuts); //printing the price of walnuts
            printf("\n");
            temp = temp->next;
        }
        printf("\nPress any key to continue");
    }
}
int main()
{
    int choice; //for holding the choice of the user
    do
    {
        printf("Press 1 to insert data\n");
        printf("Press 2 to find the minimum price of walnuts\n");
        printf("Press 3 to view all data\n");
        printf("Press 4 to exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            data();
            break;

        case 2:
            min();
            break;

        case 3:
            view();
            break;

        case 4:
            printf("Thanks visit again\n");
            break;

        default:
            printf("Wrong input entered\n");
        }
    } while (choice != 4);

    return 0;
}
