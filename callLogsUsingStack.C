#include <stdio.h>

#include <conio.h>

#include<string.h>

#include<stdlib.h>

void Display();

void Push();

void Delete(long int);

void Accept ();

void Save(long int);

#define size 1000

int top;

struct callog

{

    long int num;

    char name[20];

} c[size];

int main(int argc, char *argv[])

{

    top = -1;

    int ch,ch1;

    while(1)

    {

         clrscr();

         Display();

         printf("1.Make a Call\n2.options\n");

         printf("Enter Choice:");

         scanf("%d", &ch);

         if(ch == 1)

         {

             printf("Enter Mobile number :");

             Push();

         }

         if(ch==2)

         {    

             clrscr();

             printf ("1.Delete Number\n2.Save Number\n");

             printf("Enter Choice: ");

             scanf ("%d",&ch1);

             if(ch1==1)

             {

                 long int n;

                 printf ("Enter Number to Delete: ");

                 scanf ("%ld",&n);

                 Delete (n);

             }

             if(ch1==2)

             {

                 long int s;

                 printf("Enter Number to Save:");

                 scanf("%ld",&s);            

                 Save (s);

             }

        }

    }

}

void call()

{

    clrscr();

    printf("Calling to %ld ...\n", c[top].num);

    sleep(2);

    Accept();

}

void Accept()

{

    int l;

    for(l=top-1;l>=-1;l--)

    {

        if(c[top].num==c[l].num)

        {

            strcpy(c[top].name ,c[l].name);

            break;

        }

    }

    printf("Ringing...\n");

    sleep(5);

    printf("Hello!\n");

    sleep (2);

    printf("Hai\n");

    sleep (2);

    printf("bye\n");

    sleep (1);

    printf ("Call Ended\n");

    sleep(2);

}

void Push()

{

    top++;

    scanf("%ld", &c[top].num);

    call();

}

void Delete (long int d)

{

    int count=0;

    if(top==-1)

    {

        printf("Make Calls to Your Friends\n");

        sleep (3);

    }

    else if(d==c[top].num)

    {

        top--;

        count=1;

        printf ("Number Deleted\n");

        sleep(2);

    }

    else if(d!=c[top].num)

    {

        int k;

        for(k=top;k>=0;k--)

        {

            if(d==c[k].num)

            {

                count=1;

                c[k].num='*';

                printf ("Number Deleted\n");

                sleep(2);

                break;

            }

        }

    }

    if(count==0)

    {

        printf("Given number is not available! \n");

        sleep (3);

        }

}

void Save(long int se)

{

    int j,i,count=0;

    for(j=top;j>=0;j--)

    {

        if(se==c[j].num)

        {

            count=1;

            printf("Enter Name(max:20 Characters):");

            scanf("%s",c[j].name);            

             for(i=top;i>=0;i--)

             {

                 if(se==c[i].num)

                 {

                     strcpy(c[i].name,c[j].name);

                 }

             }

        }

        if(se==c[j].num)

        {

            break;

        }

    }

    if(count==0)

    {

           printf ("**New Contact**\n");

           top++;

           c[top].num=se;

           printf ("Enter Name(Max:20 Characters):");

           scanf("%s",c[top].name);

        } 

}        

void Display()

{

    int i;

    for (i = top; i >= 0; i--)

    {

        if(c[i].num!='*')

       {

        printf("%ld %s\n", c[i].num,c[i].name);

        }

    }

}
