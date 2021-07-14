#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
struct info
{
    char name[20];
    char address[25];
    long long int cont;
    int hourss;
    float bill;
    float advance;
    float remain;
    float hot_remain;
};
struct node
{
    int roomNo;
    struct info data;
    int occupy;
    struct node *next;
};
void displayEmptyRooms(struct node *head);
int displayList(struct node * head);
struct node * create(struct node * head,int n);
int searchRoom(struct node *,float);
int deallocate(struct node * head,int roomnumb);
int main()
{
    int ch,n,pos,x,u,v;
    int roomnumb;
    int mem,w,y,z;
    struct node * head1AC=NULL,*head1NAC=NULL,*head2AC=NULL,*head2NAC=NULL,*head4AC=NULL,*head4NAC=NULL;
    char str[25];
head1AC=create(head1AC,100);
head1NAC=create(head1NAC,200);
head2AC=create(head2AC,300);
head2NAC=create(head2NAC,400);
head4AC=create(head4AC,500);
head4NAC=create(head4NAC,600);
 printf("\n*** *** *** WELCOME TO A5'S HOTEL *** *** ***\n\n");
 time_t k;
 time(&k);
 printf("Today date and time is:%s",ctime(&k));
     while(1)
    {
    printf("\n*************Menu*****************\n");
    printf("1.AC room Booking                 \t2.Non AC room Booking\n3.display AC List                  \t4.display Non AC List\n5.Display empty AC room            \t6.Display non empty Non AC rooms\n7.Display price sheet for the rooms\t8.Billing and Deallocate\n9.Exit\n");
    printf("Enter choice:");
    scanf("%d",&ch);
      switch(ch)
      {
          case 1:
        printf("Enter member either 1,2 or 4:\n");
        scanf("%d",&mem);
            switch(mem)
            {
        case 1:x=searchRoom(head1AC,50);
                   if(x==0)
                    printf("SORRY ROOMS ARE NOT AVAILABLE\n");
                  else
                    printf("ROOM BOOKED\n");
                  break;
            case 2:x=searchRoom(head2AC,80);
                  if(x==0)
                    printf("SORRY ROOMS ARE NOT AVAILABLE\n");
                  else
                    printf("ROOM BOOKED\n");
                  break;
            case 4:x=searchRoom(head4AC,100);
                  if(x==0)
                    printf("SORRY ROOMS ARE NOT AVAILABLE\n");
                  else
                    printf("ROOM BOOKED\n");
                  break;
 default:printf("Please enter the above membered room type only\n");
break;
         }
         break;
          case 2:
        printf("Enter member either 1,2 or 4:\n");
        scanf("%d",&mem);
         switch(mem){
              case 1:x=searchRoom(head1NAC,40);
                  if(x==0)
                    printf("SORRY ROOMS ARE NOT AVAILABLE\n");
                  else
                    printf("ROOM BOOKED\n");
                  break;
                  case 2:x=searchRoom(head2NAC,60);
                  if(x==0)
                    printf("SORRY ROOMS ARE NOT AVAILABLE\n");
                  else
                    printf("ROOM BOOKED\n");
                  break;
         case 4:x=searchRoom(head4NAC,80);
                  if(x==0)
                    printf("SORRY ROOMS ARE NOT AVAILABLE\n");
                  else
                    printf("ROOM BOOKED\n");
                  break;
        default:printf("Please enter the above membered room type only\n");
break;
                  }
                  break;
        case 3:
             printf("Enter member either 1,2 or 4:\n");
        scanf("%d",&mem);
        switch(mem)
        {
            case 1:printf("AC 1 member list\n");
             v=displayList(head1AC);
              if(v==0)
              {
                  printf("No AC rooms booked for 1 member\n");
              }
             break;
    case 2:printf("AC 2 member list\n");
             v=displayList(head2AC);
              if(v==0)
              {
                  printf("No AC rooms booked for 2 members\n");
              }
             break;
    case 4:printf("AC 4 member list\n");
             v=displayList(head4AC);
              if(v==0)
              {
                  printf("No AC rooms booked for 4 members\n");
              }
             break;
              default:printf("Please enter the above membered room type only\n");
        }
           break;
    case 4:
                   printf("Enter member either 1,2 or 4:\n");
        scanf("%d",&mem);
        switch(mem)
        {
            case 1:printf("Non-AC 1 member list\n");
             v=displayList(head1NAC);
              if(v==0)
              {
                  printf("No Non-AC rooms booked for 1 member\n");
              }
             break;
    case 2:printf("Non-AC 2 member list\n");
             v=displayList(head2NAC);
              if(v==0)
              {
                  printf("No Non-AC rooms booked for 2 members\n");
              }
             break;
    case 4:printf("Non-AC 4 member list\n");
             v=displayList(head4NAC);
              if(v==0)
              {
                  printf("No Non-AC rooms booked for 4 members\n");
              }
             break;
   default:printf("Please enter the above membered room type only\n");
   break;      }
           break;
    case 5:
   printf("Enter member either 1,2 or 4:\n");
        scanf("%d",&mem);
            switch(mem)
            {
                case 1:printf("Empty AC rooms of 1 person are:\n");
             displayEmptyRooms(head1AC);
             break;
               case 2:printf("Empty AC rooms of 2 person are:\n");
             displayEmptyRooms(head2AC);
             break;
                case 4:printf("Empty AC rooms of 4 person are:\n");
             displayEmptyRooms(head4AC);
             break;
     default:printf("Please enter the above membered room type only\n");
     break;   }
break;
    case 6:
         printf("Enter member either 1,2 or 4:\n");
        scanf("%d",&mem);
        switch(mem){
            case 1: printf("Empty Non-AC rooms of 1 person are:\n");
             displayEmptyRooms(head1NAC);
             break;
    case 2:printf("Empty Non-AC rooms of 2 person are:\n");
             displayEmptyRooms(head2NAC);
             break;
    case 4:printf("Empty Non-AC rooms of 4 person are:\n");
             displayEmptyRooms(head4NAC);
             break;
        default:printf("Please enter the above membered room type only\n");
        break;
 }
        break;
    case 7:
        {
            printf("\n\n******Chargesheet of the rooms for 1 HOUR*******\n");
            printf("             AC     Non-AC\n");
            printf("1-Member   Rs.50    Rs.40 \n");
            printf("2-Member   Rs.80    Rs.60 \n");
            printf("4-Member   Rs.100   Rs.80 \n\n");
        }
        break;
    case 8:
        {
        printf("Enter the room Number\n");
        scanf("%d",&roomnumb);
        if((roomnumb<100)||(roomnumb>700))
           {
            printf("Invalid Room number in the Hotel\n");
       }
       else{ u= deallocate(head1AC,roomnumb);
        v=deallocate(head1NAC,roomnumb);
         w= deallocate(head2AC,roomnumb);
        x=deallocate(head2NAC,roomnumb);
        y= deallocate(head4AC,roomnumb);
        z=deallocate(head4NAC,roomnumb);
        if(v==1&&u==1&&w==1&&x==1&&y==1&&z==1)
        printf("No room occupied with the given room number in the Hotel\n");}
        }   break;
   case 9:
       printf("\n*** *** *** THANK YOU FOR VISITING *** *** ***\n");
       exit(0);
     }
    }
}
struct node * create(struct node *head,int n)
{
 int i;
 struct node *t,*p=head;
    for(i=1 ; i<11; i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
          t->occupy=0;
         if(t==NULL)
         {
             printf("Memory full\n");
             return NULL;
         }
         if(head==NULL)
           {
             head=t;
             p=head;
             t->roomNo=n+i;
           }
         else
         {
             p->next=t;
             p=p->next;
             t->roomNo=n+i;
         }
    }
    return head;
}
int searchRoom(struct node *head,float b)
{  int stay=0 ;time_t m;
time(&m);
int hours=0;
int days=0;
    struct node *p=head;
      while(p!=NULL)
      {
          if(p->occupy==0)
          {  printf("Room Alloted is %d\n",p->roomNo);
              printf("Enter name:");
              scanf("%s",p->data.name);
              printf("Enter contact:");
              scanf("%lld",&(p->data.cont));
              printf("Enter address:");
             scanf("%s",p->data.address);
             printf("Enter days and hours of stay:");
             scanf("%d%d",&days,&hours);
             stay=(days*24)+hours;
             p->data.hourss=stay;
             p->data.bill=stay*(float)b;
             printf("Total hour stay is :%d hours(Total hours=Days %d * 24 + Hours %d)\n",p->data.hourss,days,hours);
             printf("Total bill:Rs.%.2f\n",p->data.bill);
             printf("Enter the advance amount being paid:Rs.");
             scanf("%f",&(p->data.advance));
             p->data.remain=(p->data.bill)-(p->data.advance);
if((p->data.bill)>=(p->data.advance))
             printf("Remaining Amount:Rs.%.2f\n",p->data.remain);
if((p->data.bill)<(p->data.advance))
             printf("Extra Amount Paid to the hotel by customer:Rs.%.2f\n",p->data.remain);
             p->occupy=1;
            return 1;
          }
          p=p->next;
      }
      return 0;
}
int displayList(struct node *head)
{
    struct node *t=head;
    int flag=0;

      while(t!=NULL)
       {
       if(t->occupy!=0)
      {  flag=1;
       printf("\n\nRoom Number:%d\n",t->roomNo);
       printf("Name:%s\n",t->data.name);
       printf("Contact:%lld\n",t->data.cont);
       printf("Address:%s\n",(t->data.address));
       printf("Stay:%d hours\n",(t->data.hourss));
       printf("Bill=Rs.%.2f\n",(t->data.bill));
       printf("Advance paid:Rs.%.2f",(t->data.advance)) ;
             if((t->data.remain)>=0)
              printf("Remaining balance:Rs.%.2f",(t->data.remain));
              else if((t->data.remain)<0);
              printf("Extra Amount paid to the hotel:Rs.%.2f",(t->data.remain));
       printf("- - - - - - - - - - - - - - - - - - - \n");
        }t=t->next;
      }
      if(flag==0)
        return 0;
      else
      return 1;
}
int deallocate(struct node * head,int roomnumb)
{  float bal;
    struct node * p=head;
    int k=roomnumb;
      while(p!=NULL)
      {
          if((p->roomNo==k)&&(p->occupy==1))
            {

       while(p->data.remain>0)
      {
      printf("\nYou are kindly requested to pay Balance amount is=%.2f\n",p->data.remain);
      printf("Enter the remaining amount being paid:");
      scanf("%f",&bal);
      p->data.remain=(float)p->data.remain-(float)bal;
      }if (p->data.remain==0)
                {printf("The room Number %d is vacated\n",k);
           p->occupy=0;}
    if(p->data.remain<0)
        {printf("Extra amount paid by the customer is %.2f\n",p->data.remain);
        printf("The room Number %d is vacated\n",k);
           p->occupy=0;}
                   return 0;    }
       p=p->next;
           }
return 1;
      }
void displayEmptyRooms(struct node *head)
{
    struct node *p=head;
    while(p!=NULL)
    {
        if(p->occupy==0)
        {
            printf("ROOM NO. %d\n",p->roomNo);
        }
        p=p->next;
    }
}
