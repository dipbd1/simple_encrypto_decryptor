/*This Code Has Been made by Some idiot noobs of Daffodil International University.
  So don't point out the mistakes, if you can then praise us with motivation.

  Code Completed at:                        17, 08, 2016
  Code Last Modified:                       18, 08, 2016
  Supported Operating System:               Windows
  OS Family:                                Windows NT
  Needed Compiler                           GNU GCC Compiler Set

  At Last, Don't try to alter any code, It might cause serious damage to your computer.

  */




#include<stdio.h>               //Needed Library or Header Files
#include<string.h>
#include<windows.h>

#define speed 10                //print_slow animation speed modifier or macro parameter

FILE *encrypt_p;                //File pointer to open txt file and close txt file.
FILE *decrypt_p;

int initiator =0;               //to cancel second time animation, i used it.
int encrypt_code, decrypt_code; // this variables work as encryption key code handler.
char xtra;                      // Press any key to continue receiver. It don't have actually any work.

char input_txt[10000];      //Some Global Variables. this two are used for output and input.
char output_txt[10000];

//**********************Declaring *********************

file_mode();
live_mode();
animation();
logo();
logo_static();

//********************Encryptor and Decryptor Function ********************

encrypt();                  //declaring some more function
decrypt();

//Here Starts Coding **************

main()
{
    //First Time Animation Handler****************
    if(initiator == 0)
    {
        animation();
        initiator++;
    }
    system("cls");
    char choice;

    //Logo Creating Functions *******************
    logo();
    logo_static();

    //printf("\t\tASCII Standard Encryptor and Decryptor\n\n\n");
    printf("1. File Mode\n");
    printf("2. Live Mode\n");
    printf("3. Exit\n");
    choice = getch();           //this variable take input and we compare it and then we got desired function.
    if(choice == '1')
    {
        file_mode();
    }
    else if(choice == '2')
    {
        live_mode();
    }
    else if (choice == '3')
    {
        return 0;
    }
    else//this can be called as exception handler for first menu.
    {
        system("cls");
        printf("Your Choice is wrong. Press any key to Restart.");
        xtra = getch();
        system("cls");
        return main();
    }
}

//live mode described bellow ****************

live_mode()
{
    system("cls");
    logo_static();
    printf("\n\t\t\t  ***Live Mode***\n\n\n");
    char choice;
    printf("1. Encrypt\n");
    printf("2. Decrypt.\n");
    choice = getch(choice);
    if(choice == '1')
    {

        system("cls");
        printf("Give a input(Input have to be single string): ");
        gets(input_txt);
        printf("\n\nNow enter the encryption key(key would be integer): ");
        scanf("%d", &encrypt_code);
        encrypt(input_txt);
        printf("\n\nEncrypted Text: %s", output_txt);
        printf("\n\n\nPress any Key to Continue...");
        xtra = getch();
        return main();
    }
    else if(choice == '2')
    {
        system("cls");
        printf("Give a input(Input have to be single string): ");
        gets(input_txt);
        printf("\n\nNow enter the encryption key(key would be integer): ");
        scanf("%d", &decrypt_code);
        decrypt(input_txt);
        printf("\n\nDecrypted Text: %s", output_txt);
        printf("\n\n\nPress any Key to Continue...");
        xtra = getch();
        return main();
    }
    else
    {
        printf("You Have given an Wrong Choice. Press any key to restart the program.");
        xtra = getch();
        system("cls");
        return main();
    }

}

//file mode described bellow ****************

file_mode()
{
    system("cls");
    logo_static();
    printf("\n\t\t\t  ***File Mode***\n\n\n");
    char choice, c;
    printf("1. Encrypt\n");
    printf("2. Decrypt.\n");
    choice = getch(choice);
    if(choice == '1')
    {
        decrypt_p = fopen ("input.txt", "r");
        encrypt_p = fopen ("output.txt", "w");

        system("cls");
        printf("Beside the code file, you will see a \nfile named input.txt and if not then \ncreate it and put your text what wanted to be encrypted.");
        printf("\n\nAnd if you have done, press any key.");
        xtra = getch();
        printf("\n\nNow enter the encryption key(key would be integer): ");
        scanf("%d", &encrypt_code);

        if (decrypt_p)
        {
            while ((c = getc(decrypt_p)) != EOF)
            {
                fputc(c+encrypt_code, encrypt_p);
            }
        }

        fclose(encrypt_p);
        fclose(decrypt_p);
        printf("ALL DONE!!!\nCheck Your File.\n");
        printf("\n\nPress any Key to Continue...\n");
        xtra = getch();
        return main();
    }
    else if(choice == '2')
    {

        encrypt_p = fopen ("input.txt", "r");
        decrypt_p = fopen ("output.txt", "w");

        system("cls");
        printf("Beside the code file, you will see a \nfile named input.txt and if not then \ncreate it and put your text what wanted to be decrypted.");
        printf("\n\nAnd if you have done, press any key.");
        xtra = getch();
        printf("\n\nNow enter the encryption key(key would be integer): ");
        scanf("%d", &decrypt_code);

        if (encrypt_p)
        {
            while ((c = getc(encrypt_p)) != EOF)
            {
                fputc(c-decrypt_code, decrypt_p);
            }
        }

        fclose(encrypt_p);
        fclose(decrypt_p);

        printf("ALL DONE!!!\nCheck Your File.\n");
        printf("\n\nPress any Key to Continue...\n");
        xtra = getch();
        return main();
    }
    else
    {
        printf("You Have given an Wrong Choice. Press any key to restart the program.");
        xtra = getch();
        return main();
    }

}

//the great encryptor function*******

encrypt(char input[10000])
{
    int i;
    for(i=0; i<10000; i++)
    {
        if(input[i]!= '\0')
        {
            output_txt[i] = input[i]+encrypt_code;
        }
        else
        {
            break;
        }
    }
}

//the great decryptor function **************

decrypt(char input[10000])
{
    int i;
    for(i=0; i<10000; i++)
    {
        if(input[i]!='\0')
        {
            output_txt[i] = input[i] - decrypt_code;
        }
        else
        {
            break;
        }
    }

}

//First time animation

animation()
{
    print_slow("######## ##    ##  ######  ########  ##    ## ########  ######## ####  #######  ##    ## \n");
    print_slow("##       ###   ## ##    ## ##     ##  ##  ##  ##     ##    ##     ##  ##     ## ###   ## \n");
    print_slow("##       ####  ## ##       ##     ##   ####   ##     ##    ##     ##  ##     ## ####  ## \n");
    print_slow("######   ## ## ## ##       ########     ##    ########     ##     ##  ##     ## ## ## ## \n");
    print_slow("##       ##  #### ##       ##   ##      ##    ##           ##     ##  ##     ## ##  #### \n");
    print_slow("##       ##   ### ##    ## ##    ##     ##    ##           ##     ##  ##     ## ##   ### \n");
    print_slow("######## ##    ##  ######  ##     ##    ##    ##           ##    ####  #######  ##    ## \n");

    Sleep(2000);
    print_slow("\n\n\t\t\t\tMODULE LOAD COMPLETE");
    Sleep(2000);
    system("cls");

    print_slow("########  ########  ######  ########  ##    ## ########  ######## ####  #######  ##    ## \n");
    print_slow("##     ## ##       ##    ## ##     ##  ##  ##  ##     ##    ##     ##  ##     ## ###   ## \n");
    print_slow("##     ## ##       ##       ##     ##   ####   ##     ##    ##     ##  ##     ## ####  ## \n");
    print_slow("##     ## ######   ##       ########     ##    ########     ##     ##  ##     ## ## ## ## \n");
    print_slow("##     ## ##       ##       ##   ##      ##    ##           ##     ##  ##     ## ##  #### \n");
    print_slow("##     ## ##       ##    ## ##    ##     ##    ##           ##     ##  ##     ## ##   ### \n");
    print_slow("########  ########  ######  ##     ##    ##    ##           ##    ####  #######  ##    ## \n");


    Sleep(2000);
    print_slow("\n\n\t\t\t\tMODULE LOAD COMPLETE");
    Sleep(2000);
    system("cls");
}


//the great print slow function **************

print_slow(char per[1000])
{
    int n, m;
    n=strlen(per);
    for(m=0; m<n; m++)
    {
        if(per[m]==' ')
        {
            printf("%c", per[m]);
            //continue;
        }
        else
        {
            Sleep(speed);
            printf("%c", per[m]);
        }
    }
}

//the animating logo **************

logo()
{
    int i, j;
    for(i=0; i<30; i++)
    {
        for(j=0; j<i+1; j++)
        {
            printf(" ");
        }
        printf("      /            /\n");
        for(j=0; j<i+1; j++)
        {
            printf(" ");
        }
        printf("     / ASCII      / \n");
        for(j=0; j<i+1; j++)
        {
            printf(" ");
        }
        printf("    / Standard   /  \n");
        for(j=0; j<i+1; j++)
        {
            printf(" ");
        }
        printf("   / Encryptor  /   \n");
        for(j=0; j<i+1; j++)
        {
            printf(" ");
        }
        printf("  /    and     /    \n");
        for(j=0; j<i+1; j++)
        {
            printf(" ");
        }
        printf(" /  Decryptor /     \n");
        for(j=0; j<i+1; j++)
        {
            printf(" ");
        }
        printf("/            /      \n");
        Sleep(10);
        system("cls");

    }
}

//and the static logo *****************

logo_static()
{

    print_slow("\t\t\t         /            /\n");
    print_slow("\t\t\t        / ASCII      / \n");
    print_slow("\t\t\t       / Standard   /  \n");
    print_slow("\t\t\t      / Encryptor  /   \n");
    print_slow("\t\t\t     /    and     /    \n");
    print_slow("\t\t\t    /  Decryptor /     \n");
    print_slow("\t\t\t   /            /      \n");
}
