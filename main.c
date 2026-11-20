#include <stdio.h>

#define MAX_PARTICIPANT 500

struct Info{
    int id;
    char name[100];
    char email[100];
    char phone[15];
    char category[10]; // student/ teacher/ guest 
    int attendance; //Yes of no
    int meal;//same

};

struct Info infoLog[MAX_PARTICIPANT];
int infoIndex = 0;
struct Activity
{
    int activityId;
    char activityName[50];
};

struct ActivityReg
{
    int participantId;
    int activityId;
};

//Start Automatic ID 
int loadId(){
    int id;
    FILE* fptr;

    fptr = fopen("storeId.txt","r");

    if(fptr == NULL) return 1000;

    if (fscanf(fptr, "%d", &id) != 1) id = 1000;
    // else fscanf(fptr,"%d",&id);

    fclose(fptr);

    return id;
}

void saveId(int id){
    FILE* fptr = fopen("storeId.txt","w");

    if(fptr == NULL){
        printf("\nError saving ID");return;
    }
    else fprintf(fptr,"%d",id);

    fclose(fptr);
    
}

int assignID(){
    int id = loadId();
    id += 1;
    saveId(id);
    return id;

}
//End Automatic ID

//Registration part
void Registration(){
    infoLog[infoIndex].id = assignID();
    printf("\nEnter name: ");
    // scanf("%s",infoLog[infoIndex].name);
    scanf(" %99[^\n]", infoLog[infoIndex].name);
    printf("\nEnter Email: ");
    scanf("%99s",infoLog[infoIndex].email);
    printf("\nEnter Contact Number: ");
    scanf("%14s",infoLog[infoIndex].phone);
    printf("\nEnter Category (Student / Teacher / Guest): ");
    scanf("%s",infoLog[infoIndex].category);

    infoIndex++;
}

void menu(){
    printf("1. Register\n");
    printf("2. Search Participant\n");
    printf("3. Delete Participant\n");
    printf("4. Assign activity\n");
    printf("-1. Exit\n");
    printf("Select one of the option: ");
}

int main(){

    int select = 0;
    while (select != -1)
    {    
        menu();
        scanf("%d",&select);

        switch (select)
        {
            case -1:
                printf("Exiting...\n");
                break;    
            case 1:
                Registration();
                break;
            case 2:
                
                break;

            case 3:
            
            
                break;
            
            case 4:


                break;


            default:
                printf("INVALID CHOICE\n");
                break;
        }
    }
}