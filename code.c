#include<stdio.h>
#include<time.h>
#include <string.h>
int isLeapYear(int year, int mon) 
{
    int flag = 0;
    if (year % 100 == 0) 
    {
            if (year % 400 == 0) 
            {
                    if (mon == 2) 
                    {
                            flag = 1;
                    }
            }
    } 
    else if (year % 4 == 0) 
    {
            if (mon == 2) 
            {
                    flag = 1;
            }
    }
    return (flag);
}
int len1(char name[])
{
    if((strlen(name)>=8)&&(strlen(name)<=16))
      {
          return 1;
      }
      else{
          printf("your username lenght must in between 8--16 \n");
         return 0;
      }
}
int isdig( char name[])
{
    int a=0;
    for(int i=0;i<strlen(name)-1;i++)
    {
          if(isdigit(name[i]))
          {
              a++;
           }
          else
          {
              a;
          }
    }
    if(a>0&&a<=7)
    {
        return 1;
    }
    else if(a>7){
        printf("your username contains more than 7 number \n");
        return 0;
    }
    else {
        printf("your username contains at least one number \n");
        return 0;
    }
}
int isalp( char name[])
{
    int a=0;
    for(int i=0;i<strlen(name)-1;i++)
    {
          if(isalpha(name[i]))
          {
              a++;
           }
          else
          {
              a;
          }
    }
    if(a!=0)
    {
        return 1;
    }
    else{
        printf("your username contains at least one letter \n");
        return 0;
    }
}

int isspec( char name[])
{
    int a=0;
    for(int i=0;i<strlen(name)-1;i++)
    {
          if(name[i]=='%'|| name[i]=='#'|| name[i]=='@'|| name[i]=='`'|| name[i]=='~'|| name[i]=='!'|| name[i]=='$'|| name[i]=='^'|| name[i]=='&'|| name[i]=='*'|| name[i]=='('|| name[i]==')'|| name[i]=='_'|| name[i]=='-'|| name[i]=='='|| name[i]=='+'|| name[i]=='{'|| name[i]=='}'|| name[i]=='['|| name[i]==']'|| name[i]==';'|| name[i]==':'|| name[i]=='"'|| name[i]=='<'|| name[i]==','|| name[i]=='>'|| name[i]=='>'|| name[i]=='/'|| name[i]=='?'|| name[i]==' '|| name[i]=='|')
          {
              a++;
           }
          else
          {
              a;
          }
    }
    if(a!=0)
    {
        printf("your username contains special charecters \n");
        return 0;
    }
    else{
        return 1;
    }
}
int len2(char name[])
{
    if((strlen(name)>=8)&&(strlen(name)<=16))
      {
          return 1;
      }
      else{
          printf("your password lenght not satisfice the condition \n");
         return 0;
      }
}
int isup( char name[])
{
    int a=0;
    for(int i=0;i<strlen(name)-1;i++)
    {
          if(name[i]>='A'&& name[i]<='Z')
          {
              a++;
           }
          else
          {
              a;
          }
    }
    if(a!=0)
    {
        return 1;
    }
    else{
        printf("your password contains at least one uppercase \n");
        return 0;
    }
}
int islow( char name[])
{
    int a=0;
    for(int i=0;i<strlen(name)-1;i++)
    {
          if(name[i]>='a'&& name[i]<='z')
          {
              a++;
           }
          else
          {
              a;
          }
    }
    if(a!=0)
    {
        return 1;
    }
    else{
        printf("your password contains at least one lowercase \n");
        return 0;
    }
}
int isconse(char name1[],char name2[])
{
    int a=0;
    for(int i=0;i<strlen(name1)-1;i++)
    {
        for(int j=0;j<strlen(name2)-1;j++)
        {
                if(name1[i]==name2[j])
                {
                              if(name1[i+1]==name2[j+1])
                              {
                                  if(name1[i+2]==name2[j+2])
                                  {
                                      a++;
                                  }
                              }
                }
        }
    }
    if(a!=0)
    {
        printf("your password contains 3 or more concecutive laters from your username \n");
        return 0;
    }
    else{
       
        return 1;
    }
}
int main()

{
    char name1[100];
    char name2[100];
    int DaysInMon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days, month, year;
    char dob[100];
    time_t ts;
    struct tm *ct;
 
  
    printf("Enter your date of birth (DD-MM-YYYY): ");
    scanf("%d-%d-%d",&days,&month, &year);
 
    
    ts = time(NULL);
    ct = localtime(&ts);
 
    printf("Current Date: %d/%d/%d\n",
            ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);
 
    days = DaysInMon[month - 1] - days + 1;
 
   
    if (isLeapYear(year, month)) 
    {
            days = days + 1;
    }
 
    days = days + ct->tm_mday;
    month = (12 - month) + (ct->tm_mon);
    year = (ct->tm_year + 1900) - year - 1;
 
   
    if (isLeapYear((ct->tm_year + 1900), (ct->tm_mon + 1))) 
    {
            if (days >= (DaysInMon[ct->tm_mon] + 1)) 
            {
                    days = days - (DaysInMon[ct->tm_mon] + 1);
                    month = month + 1;
            }
    } 
    else if (days >= DaysInMon[ct->tm_mon]) 
    {
            days = days - (DaysInMon[ct->tm_mon]);
            month = month + 1;
    }
 
    if (month >= 12) 
    {
            year = year + 1;
            month = month - 12;
    }
 
   
    printf("Hey you are  %d years %d months and %d days old. \n", year, month, days);
    printf("\n---------------------------------------------- \n");
    
     if(year<18)
   {
       printf("you are not 18 years or more \n");
       printf("you are not allowed to create the username and password \n");
      // printf("your password creation failed \n");
   }
   else
   {
       int c,d,f,e,x,y,z,g;
         printf("you are eligible for registration \n");
         printf("please enter your username : ");
         scanf("%s",&name1);
         printf("enter your password : ");
         scanf("%s",&name2);
         c=len1(name1);
         
         d=isdig(name1);
       
         f=isalp(name1);
         
         e=isspec(name1);
         
         x=len2(name2);
         
         y=isup(name2);
         
         z=islow(name2);

         g=isconse(name1, name2);        

         if(c==1&&d==1&&f==1&&e==1&&x==1&&y==1&&z==1&&g==1)
         {
             printf("\n---------registration  successfull--------");
         }
         else{
             printf("\n---registrtion failed becasuse of the above instractions are not followed--");
         }
      
}
 return 0;
}
