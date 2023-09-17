#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  //use for delay(), getch() etc.
#include <windows.h> //use for gotoxy().
#include <ctype.h>  // use for toupper(), tolower() etc.
#include <string.h> //use for srtlen(), strcpy(), strcmp() etc.
#define size 100
int sell_amount[size];
int s=0;
struct node
{
    char name[30];
    int quantity;
    int price;
    int id;
    struct node *next;
}*head, *tail;

void lock()
{
    int pass=2283,user,e=0;
    do{
       printf("\n\n\t\t\t\t\t KEY = 2283 ");
       printf("\n\n\t\t\t\t\tEnter The KEY of your store: ");
       scanf("%d",&user);
       if(user==pass){
            printf("\n\n\t\t\t\t\tLock Opened\n\n\t\t\t\t\tPress any key to go go Main Menu: ");
            getch();
            menu();
            break;
       }
       else{
        printf("\n\t\t\t\t\tIncorrect key! Try again.");
        e++;
       }
    }while(e<=2);
    if(e>2){
        printf("\n\t\t\t\t\tYou crossed the limit!!");
        getch();
        exit(0);

    }
}

void createstore()
{
    int n;
    struct node *temp,*newnode;
    system("cls");
    title();
    printf("\n\n\t\t\t\t\tHow many item do you want to add in your store ");
    scanf("%d",&n);
    head = (struct node *)malloc(sizeof(struct node));
    if(head != NULL){
        printf("\n\t\t\t\t\tInput the name of item 1 ");
        scanf("%s", head->name);
        printf("\n\t\t\t\t\tEnter the product Code of item 1 ");
        scanf("%d",&head->id);
        printf("\n\t\t\t\t\tEnter the total quantity of product %d (total unit) ",1);
        scanf("%d",&head->quantity);
        printf("\n\t\t\t\t\tEnter your selling price per unit %d ",1);
        scanf("%d",&head->price);
        head->next = NULL;
        tail = head;
        system("cls");

        temp = head;
        if(n>1){
            for(int i=2; i<=n; i++){
                newnode = (struct node *)malloc(sizeof(struct node));
                title();
                if(newnode != NULL){
                    printf("\n\t\t\t\t\tInput the name of item %d ",i);
                    scanf("%s",newnode->name);
                    printf("\n\t\t\t\t\tEnter the product Code of item %d ",i);
                    scanf("%d",&newnode->id);
                    printf("\n\t\t\t\t\tEnter the total quantity of product %d (total unit) ",i);
                    scanf("%d",&newnode->quantity);
                    printf("\n\t\t\t\t\tEnter your selling price for product %d ",i);
                    scanf("%d",&newnode->price);
                    newnode->next = NULL;
                    temp->next = newnode;
                    temp = newnode;
                    tail = temp;
                    system("cls");
                }
                else{
                    printf("\n\t\t\t\t\tThere is no available space for your Store \n");
                }
            }
            title();
            printf("\n\n\t\t\t\t\t Successfully Created store!!\n\n\t\t\t\t\tPress any key to go to main menu: ");
            getch();
            menu();
        }
    }
    else{
        printf("\n\n\t\t\t\t\tThere is no available space for your Store \n");
    }

}

void additem()
{
    struct node *target, *newnode;
    char ad;
    system("cls");
    title();
    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode!=NULL){
        printf("\n\n\t\t\t\t\tInput the name of item ");
        scanf("%s",newnode->name);
        printf("\n\t\t\t\t\tEnter the product id of item ");
        scanf("%d",&newnode->id);
        printf("\n\t\t\t\t\tEnter the total quantity of product (total unit) ");
        scanf("%d",&newnode->quantity);
        printf("\n\t\t\t\t\tEnter your selling price for product ");
        scanf("%d",&newnode->price);
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
    else{
        printf("\n\t\t\t\t\tThere is no available space for your Store \n");
    }
    printf("\n\t\t\t\t\tIf you want to add more item please press (Y/N) Y= yes, N= no: ");
    scanf(" %c",&ad);
    if(toupper(ad) == 'Y'){
        additem();
    }
    else{
        menu();
    }

}

void display()
{
    struct node *temp;
    temp = head;
    system("cls");
    title();
    if(temp!=NULL){
        printf("\n\n\n\t\t\t\t\tName\t Code\t Quantity\t Rate \n\n");
        while(temp != NULL){
            printf("\t\t\t\t\t%s\t %d\t %d\t \t %d\n",temp->name, temp->id, temp->quantity, temp->price);
            temp = temp->next;
        }
        printf("\n\t\t\t\t\tPress any key to go to Main Menu: ");
        getch();
        menu();
    }
    else{
        printf("\n\t\t\t\t\tStore is Empty Press any key to go to main menu: ");
        getch();
        menu();
    }
}
void welcome()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t########################################");
    printf("\n\t\t\t\t#\t\tWELCOME TO\t\t#");
    printf("\n\t\t\t\t#\t\tTUSHAR's SHOP\t\t#");
    printf("\n\t\t\t\t########################################");
}
void title()
{
    printf("\n\n\t\t-----------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t  TUSHAR DREAM SHOP       ");
    printf("\n\t\t-----------------------------------------------------------------------------------------\n");
}

deleteitem()
{
    system("cls");
    struct node *target, *pretarget,*pretarget_2,*target_2;
    int src;
    char per;
    title();
    display2();
    printf("\n\n\t\t\t\t\tEnter the product id that you want to delete: ");
    scanf("%d",&src);
    target = head;
    target_2 = head;
    if(head->id == src){
        head = head->next;
        target->next = NULL;
        free(target);
        printf("\n\n\t\t\t\t\tSuccessfully removed\n");
    }
    else if(tail->id == src){
        while(target_2->next!=NULL){
            pretarget_2 = target_2;
            target_2 = target_2->next;
        }
            tail = pretarget_2;
            tail->next = NULL;
            free(target_2);
            printf("\n\n\t\t\t\t\tSuccessfully removed\n");

    }
    else{
        while(target->next!= NULL){

            if(target->id == src){
                pretarget->next = target->next;
                target->next = NULL;
                free(target);
                printf("\n\n\t\t\t\t\tSuccessfully removed\n");
                break;

            }
            pretarget = target;
            target = target->next;
        }
    }
    printf("\n\n\t\t\t\t\tDo you want to remove More..[Y/N]: ");
    scanf(" %c",&per);
    if(toupper(per) == 'Y'){
        deleteitem();
    }
    else{
        system("cls");
        title();
        printf("\n\n\n\t\t\t\t\tPress any key to go to main Menu: ");
        getch();
        menu();
    }

}
void sell()
{
    system("cls");
    struct node *temp;
    int code,unit,i,sum=0,count=0;
    char per;
    title();
    display2();
    printf("\n\t\t\t\t\tEnter the product Code that you are selling: ");
    scanf("%d",&code);
    printf("\t\t\t\t\tEnter how many unit you want to sell: ");
    scanf("%d",&unit);
    temp = head;
    while(temp != NULL){
        if(temp->id == code){
            if(temp->quantity == 0){
                printf("\n\t\t\t\t\tSorry! Out of stock.");
                break;
            }
            else if(temp->quantity<unit){
                printf("\n\t\t\t\t\tSorry! Product Shortage.");
                break;
            }
            else{
                temp->quantity = (temp->quantity - unit);
                sell_amount[s] = (temp->price*unit);
                count = count+(temp->price*unit);
                s++;
            }
            break;
        }
        temp = temp->next;
    }
    printf("\n\n\t\t\t\t\tDo you want to sell more [Y/N]: ");
    scanf(" %c",&per);
    if(toupper(per) == 'Y'){
        sell();
    }
    else{
        system("cls");
        title();
        for(i=0;i<s;i++){
            sum = sum+sell_amount[i];
        }
        printf("\n\n\n\t\t\tSelling complete. Your Bill is %d taka. Please pay the bill.\n\n\t\t\tPress any key to go to Main Menu: ",count);
        getch();
        menu();
    }
}

void menu()
{
    system("cls");
    int choice;
    title();
    printf("\n\n\n\n\t\t\t\t\tPRESS>> 1 for Create Store.\n");
    printf("\n\t\t\t\t\tPRESS>> 2 for Add New Item.\n");
    printf("\n\t\t\t\t\tPRESS>> 3 for Current Status.\n");
    printf("\n\t\t\t\t\tPRESS>> 4 for Sell Product.\n");
    printf("\n\t\t\t\t\tPRESS>> 5 for Remove Product\n");
    printf("\n\t\t\t\t\tPRESS>> 6 for Total Sell\n");
    printf("\n\t\t\t\t\tPRESS>> 7 for Refill Store\n");
    printf("\n\t\t\t\t\tPRESS>> 8 for Total Number of Item\n");
    printf("\n\t\t\t\t\tPRESS>> 9 for Exit\n");
    printf("\n\n\t\t\t\t\tPress from 1 to 9: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        createstore();
        break;
    case 2:
        additem();
        break;
    case 3:
        display();
        break;
    case 4:
        sell();
        break;
    case 5:
        deleteitem();
        break;
    case 6:
        totalsell();
        break;
    case 7:
        increase();
        break;
    case 8:
        count();
    case 9:
        exit(0);
    default:
        printf("\n\t\t\t\tInvalid Entry!! please Choose Right Option.... ");
        getch();
    }

}

void totalsell()
{
    system("cls");
    int i=0,val=0;
    title();
    while(sell_amount[i] != NULL){
        val = val+sell_amount[i];
        i++;
    }
    printf("\n\n\n\t\t\t\t\tTotal Sell is %d",val);
    printf("\n\t\t\t\t\tPress any key to go to Main Menu: ");
    getch();
    menu();

}

void display2()
{
    struct node *temp;
    temp = head;
    system("cls");
    title();
    if(temp!=NULL){
        printf("\n\n\n\t\t\t\t\tName\t Code\t Quantity\t Rate \n\n");
        while(temp != NULL){
            printf("\t\t\t\t\t%s\t %d\t %d\t \t %d\n",temp->name, temp->id, temp->quantity, temp->price);
            temp = temp->next;
        }
    }
    else{
        printf("\n\t\t\t\t\tStore is Empty\n");
    }
}

void increase()
{
    struct node *temp;
    int code,add;
    char per;
    system("cls");
    display2();
    printf("\n\n\t\t\t\tEnter Corresponding  product ID for your product that you want to increase: ");
    scanf("%d",&code);
    printf("\n\n\t\t\t\tEnter How many unit you want to add: ");
    scanf("%d",&add);
    temp = head;
    while(temp != NULL){
        if(temp->id == code){
            temp->quantity = temp->quantity + add;
            break;
        }
        temp = temp->next;
    }
    printf("\n\n\t\t\t\t\tDo you want to increase more [Y/N]: ");
    scanf(" %c",&per);
    if(toupper(per) == 'Y'){
        increase();
    }
    else{
        system("cls");
        title();
        printf("\n\n\n\t\t\t Quantity Increased successfully !! Press any key to go to Main Menu: ");
        getch();
        menu();
    }

}
void count()
{
    struct node *temp;
    int i=0,j=1;
    temp = head;
    system("cls");
    title();
    if(temp==NULL){
        printf("\n\n\t\t\t\t\tTotal Item In Your Store is 0.");
    }
    else{
        while(temp->next != NULL){
            j++;
            temp = temp->next;
        }
        printf("\n\n\t\t\t\t\tTotal Item In Your Store is %d.",j);
        printf("\n\n\t\t\t\t\tPress any key to go to Main Menu: ");
        getch();
        menu();
    }
}


void main()
{
    welcome();
    lock();

}
