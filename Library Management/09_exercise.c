// Let us work on the menu of a library. Create a structure containing book information like accession number,
// name of author, book title and flag to know whether book is issued or not.
// Create a menu in which the following can be done.
// 1 - Display book information
// 2 - Add a new book
// 3 - Display all the books in the library of a particular author
// 4 - Display the number of books of a particular title
// 5 - Display the total number of books in the library
// 6 - Issue a book
// (If we issue a book, then its number gets decreased by 1 and if we add a book, its number gets increased by 1)

#include<stdio.h>
#include<string.h>
typedef struct library
{
  int acc_num;  // accession Number :-  It's a unique number given to each new item that is acquired by a library.
  char auth[20];  // Auther Name.
  char title[20]; // Book Title.
  int flag;  // Flag :- It is to know weather a Particular Book is issued or Not.
}lib;

int opt1(lib * book, int i, int num);
int opt2(lib book[], int n);
int opt3(lib book[], int n);
int opt4(lib * book, int n);
int opt5(lib * book, int n);
int main()
{
  /* Needed variables*/
  int opt, num=100, i, count=0;
  char auth_name='a', book_title='z';

  lib book[100];

  
  /* Adding acc. num and flag of 10 Book. Just as a example*/
  for(i=0; i<10; i++)
  {
      book[i].acc_num = num;
      book[i].flag = 1;
      num++;
  }

  /* Adding author and book name of 10 Books. Just as a example*/
  {
    strcpy(book[0].auth, "a");
    strcpy(book[1].auth, "b");
    strcpy(book[2].auth, "c");
    strcpy(book[3].auth, "d");
    strcpy(book[4].auth, "e");
    strcpy(book[5].auth, "f");
    strcpy(book[6].auth, "g");
    strcpy(book[7].auth, "h");
    strcpy(book[8].auth, "i");
    strcpy(book[9].auth, "j");

    strcpy(book[0].title, "z");
    strcpy(book[1].title, "y");
    strcpy(book[2].title, "x");
    strcpy(book[3].title, "w");
    strcpy(book[4].title, "u");
    strcpy(book[5].title, "t");
    strcpy(book[6].title, "s");
    strcpy(book[7].title, "r");
    strcpy(book[8].title, "q");
    strcpy(book[9].title, "p");

    count = 10;
}


  printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");

  printf("\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");


  /* Loop till user enter '0' means 'Exit'.*/
  while(opt != 0)
  {
    printf("                          --------------------------------------------------------\n");
    printf("                                                     MENU\n");
    printf("                          --------------------------------------------------------\n\n");

    printf("Choose an Option\n\n");

    printf("1. Add Book\n");
    printf("2. Display Book Information\n");    
    printf("3. Total No. of Books in Library.\n");
    printf("4. Issue a Book.\n");
    printf("5. Return a Book\n");
    printf("0. Exit System.\n\n");

    printf("Input => ");
    scanf("%d", &opt);
    printf("\n");

    switch (opt)
    {
      case(0):
      {
        printf("Good Bye Buddy!\n");
      }
      break;
      /* Case for Adding new Book*/
      case(1): 
      {  
        opt1(book, i, num);
        i++;
        num++;
        count++;

      }
      break;

      /* Case for Display Book Information Book*/
      case(2):
      {
          opt2(book, i);
      }
      break;

      /* Case for Total Number of Book in Library*/
      case(3): 
      {
        opt3(book, i);
      }
      break;

      case(4): 
      {
        opt4(book, i);
      }
      break;

      case(5):
      {
         opt5(book, i);
      }
      break;

      default:
      {
          printf("Enter Valid Option.");
      }
      break;

    }

  }

    
    return 0;
}

int opt1(lib * book, int i, int num)
{
    printf("Enter the Name of Book : ");
    scanf("%s", book[i].title);

    printf("Enter the Name of Auther : ");
    scanf("%s", book[i].auth);

    book[i].acc_num = num;

    book[i].flag = 1;

}

int opt2(lib book[], int n)
{
    int x;

    printf("Enter the Accession Number : ");
    scanf("%d", &x);

    for(int i=0; i<n; i++)
    {
       if(book[i].acc_num == x)
       {
         printf("Title : %s\n", book[i].title);
         printf("Auther Name : %s\n", book[i].auth);
         /* Condition for Book Issued or Not.*/
         if(book[i].flag == 0)
               printf("Issued Status : Issued (Not Available for Issue)\n");
         else
          printf("Issued Status : Not Issued (Available for Issue)\n");
       }
    }

}

int opt3(lib book[], int n)
{
  int available = 0, issued=0;

  for(int i=0; i<n; i++)
{
  if(book[i].flag == 1)
  {
    available++;
  }

  else
  {
    issued++;
  }
}

    printf("Number of Available Book in Library : %d\n", available);
    printf("Number of Issued Book : %d\n", issued);
}

int opt4(lib * book, int n)
{
    int acc_num;

    printf("Enter the Accession Number : ");
    scanf("%d", &acc_num);

    for(int i=0; i<n; i++)
    {
      if(book[i].acc_num == acc_num)
      {
        if(book[i].flag == 1) /* If Book not Issued*/
        {
        book[i].flag = 0;
        printf("Issued!\n");
        break;
        }
        else
        {
          printf("Already Issued!\n");
          break;
        }
      }
    }

}

int opt5(lib * book, int n)
{
  int acc_num;

  printf("Enter the accession Number of Book you want to return : ");
  scanf("%d", &acc_num);

  for(int i=0; i<n; i++)
  {
    if(book[i].acc_num == acc_num)
    {
        if(book[i].flag == 1)
        {
          printf("Can't Return! Because Already Available In Library.\n");
          break;
        }

        else
        {
          book[i].flag = 1;
          printf("Returned!\n");
          break;
        }
    }
  }
}