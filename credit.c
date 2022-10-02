#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long credit;
    long long secondlast;
    //Prompt user for their credit card number
    do
    {
        credit = get_long("Number: ");
    }
    while (credit <= 0);
    //checksum every other number
    secondlast = credit / 10;
    int totalodd;
    while (secondlast > 0)
    {      
        int num = secondlast % 10;//to obtain second last digit
        int multiply = num * 2;//multiply every second last digit
        totalodd = totalodd + (multiply / 10) + (multiply % 10);//to make sure product of 2 digits are seperated and then added
        secondlast = secondlast / 100;
    } 
    long long crediteven = credit;
    int totaleven;
    //checksum  starting from last number
    while (crediteven > 0)
    {
        int numlast  = crediteven % 10;//ro obtain last digit
        totaleven = totaleven + numlast; //sum of numbers not multiplied by 2
        crediteven = crediteven / 100;
    }
    //checksome add and modulo operation
    long long finalcheck = credit;
    long long checkcheck = credit;
    int final = totaleven + totalodd; //sum of digits multiplied by 2 + sum of digits not multiply by 2
    int checkdigit = (final % 10); // to see if it is a valid card using checksum
    //to check the length of credit card number
    int counter = 0;
    while (checkcheck != 0)
    {
        checkcheck = checkcheck / 10;
        counter = counter + 1;
    }
    long long id;
    //to identify if the card is valid or invalid. If its valid it will check which card is it
    if (checkdigit == 0)
    {
        if (counter == 15)
        { 
            id = finalcheck / 10000000000000;
            //to check if it is an American express card
            if (id == 34 || id == 37)
            { 
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        } 
        else if (counter == 16)
        { 
            id = finalcheck / 100000000000000;
            //to check if it is a Mastercard
            if (id > 50 & id < 56)
            {
                printf("MASTERCARD\n");
            }
            else
            {  
                id = finalcheck / 1000000000000000;
                //to check if it is a Visa card
                if (id == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
         
        }
        else if (counter == 13)
        {
            id = finalcheck / 10000000000;
            //to check if it is a visa card
            if (id == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
