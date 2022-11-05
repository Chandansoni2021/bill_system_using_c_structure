#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

struct user{
        char mail[15];
        char pass[10];
        int id;
        int amount;
};
struct user coustomer[3];
int g_count=0;

void login(struct user coustomer[3],int g_count);
void new_user(struct user coustomer[3]);
void update(struct user coustomer[3],int g_count);
void display(struct user coustomer[3],int g_count);
void payment(struct user coustomer[3],int g_count);

int main(){
        int ch1;
        printf("\n\n======WELCOME TO ONLINE BILL PAYMENT SYSTEM=====\n");
        printf("1-NEW USER\n2-LOGIN\n3-Update the bill\n4-Display\n5-Payment\n");
        scanf("%d",&ch1);
        switch(ch1){
                case 1: new_user(coustomer);
                        main();
                        break;
                case 2: login(coustomer,g_count);
                        main();
                        break;
                case 3: update(coustomer,g_count);
                        main();
                        break;
                case 4: display(coustomer,g_count);
                        main();
                        break;
                case 5: payment(coustomer,g_count);
                        main();
                        break;
        }
        return 0;
}
void login(struct user coustomer[3],int g_count){
        char m[15],p[8];
        int i,flag=0;
        printf("== WELCOME TO LOGIN PAGE ==\n");
        printf("ENTER THE EMAIL-ID:");
        scanf("%s",m);
        printf("ENTER THE PASSWORD: ");
        scanf("%s",p);
        int ud=7893;
        for(i=0;i<=g_count;i++){
                if((strcmp(m,coustomer[i].mail)==0)&&(strcmp(p,coustomer[i].pass)==0)){
                    coustomer[i].id=ud;
                    printf("IT IS YOUR USER-ID\n :");
                    printf("USER ID - %d\n",coustomer[i].id);
                    flag=1;
                }
                ud++;
        }
        if(flag==1){
            printf("===LOGIN SUCCESSFULLY===\n");
        }else{
            // printf("NOT VALID\n");
            printf("PLEASE ENTER THE CORRECT EMAIL-ID OR PASSWORD\n");
        }
}

void new_user(struct user coustomer[3]){
    int p=0,l=0,u=0,d=0,s=0,flag=0,i;
    char pass_u[10];
    printf("ENTER THE MAIL-ID:");
    scanf("%s",coustomer[g_count].mail);
    printf("ENTER THE STRONG INCLUDE UPPER AND LOWER CASE AND @ ALSO PASSWORD:\n");
    scanf(" %s",pass_u);
    p=strlen(pass_u);
    for (i = 0; i < p; i++){
        if(pass_u[i] >= 'a' && pass_u[i] <= 'z') ++l;
        if(pass_u[i] >= 'A' && pass_u[i] <= 'Z') ++u;
        if(pass_u[i] >= '0' && pass_u[i] <= '9') ++d;
        if(pass_u[i] == '@' || pass_u[i] == '$') ++s;
    }    
    if(l > 0 && u > 0 && d > 0 && s > 0){
        flag=1;
    }
    if(flag==1){
        strcpy(coustomer[g_count].pass,pass_u);
        printf("==Details SAVE==\n");
        printf("please go to the LOGIN PAGE to find your USER ID  ");
    }else{
        printf("PLEASE ENTER VALID EMAIL-ID OR PASSWORD AND AGAIN SIGN-UP\n");
    }
    g_count++;
    // login(coustomer,g_count);
}

void update(struct user coustomer[3],int g_count){
    if(g_count>=0){
        int id,i,value,a,flag=0;
        char m[15],p[8];
        printf("Enter the admin Email:\n");
        scanf("%s",m);
        printf("Enter the admin password\n");
        scanf("%s",p);
        if(((strcmp(m,"admin"))==0)&&(strcmp(p,"Pass@22")==0)){
            printf("===================ADMIN EXCESS================\n");
            printf("Enter the user - ID :");
            scanf("%d",&id);
            if(id>0){
                for(i=0;i<=g_count;i++){
                    if(id==coustomer[i].id){
                        flag=1;
                        value = i;
                        break;
                    }
                }
            }
        }
        if(flag==1){
            printf("USER IS FOUND\n");
            printf("======   Update the bill value  ======\n");
            printf("Enter the pay amount :");
            scanf("%d",&a);
            coustomer[value].amount=a;
            printf("ADDED AMOUNT %d USER %d\n",id,coustomer[value].amount);
        }else{
            printf("NOT VALID User-Id\n");
        }
    }
}
void display(struct user coustomer[3],int g_count){
    int d,i,value,flag=0;
    printf("Enter the USER ID :\n");
    scanf("%d",&d);
    if(d>0){
        for(i=0;i<=g_count;i++){
            if(d==coustomer[i].id){
                value=i;
                flag=1;
                break;
            }
        }
    }
    if(flag=1){
        printf("Mail-%s\n",coustomer[value].mail);
        printf("Pass-%s\n",coustomer[value].pass);
        printf("ID-%d\n",coustomer[value].id);
        printf("Amount-%d\n",coustomer[value].amount);
    }else{
        printf("NOT VALID\n");
    }       
}

void payment(struct user coustomer[3],int g_count){
    char card[54];
    char cvv[3];
    char upi[10];
    int value=0,a,b,c=0,d,pay=0,ch2,i,f=0,flag=0,flag_1=0,flag_2=0;

    printf("Enter the USER ID :\n");
    scanf("%d",&d);
    if(d>0){
        for(i=0;i<=g_count;i++){
            if(d==coustomer[i].id){
                value=i;
                flag=1;
                break;
            }
        }
    }
    printf("YOUR BILL AMOUNT %d\n",coustomer[value].amount);
    printf("SELECT THE PAYMENT METHOD\n");
    printf("1.CREDIT CARD\n");
    printf("2.UPI ID\n");
    scanf("%d",&ch2);
    switch(ch2){
        case 1: 
        
        printf("ENTER THE CREDIT CARD OR DEBIT CARD No.:-\n");
                scanf("%s",card);
                a = strlen(card);
                printf("ENTER THE CVV NUM :-\n");
                scanf("%s",cvv);
                b = strlen(cvv);
                if(a==16 && b==3){
                    flag_1=1;
                if(flag_1==1){
                    printf("Enter the paying amount\n");
                    scanf("%d",&pay);
                    printf("===SUCCESSFUL PAYMENT===\n");
                    int rem = coustomer[value].amount-pay;
                    printf("REMIANING BALAENCE %d\n",rem);
                    coustomer[value].amount=rem;
                }
                break;
                }
            else{
                printf("give the correct information of card");

                }
       case 2: 
            printf("ENTER THE UPI ID: \n");
            scanf("%s",upi);
            c = strlen(upi);
            for(i=0;i<c;i++){
                if(upi[i]=='@') f=1;
            }
            if(f=1){
                printf("Valid UPI\n");
                sleep(2);
                flag_2=1;
            }
            if(flag_2==1){
                printf("Enter the paying amount\n");
                scanf("%d",&pay);
                printf("SUCCESSFUL PAYMENT\n");
                int rem = coustomer[value].amount-pay;
                printf("REMIANING BALAENCE: %d\n",rem);
                coustomer[value].amount=rem;
            }
            else
                printf("Not Valid\n");			
        default: printf("Choose Correct Option\n"); 
    }
}