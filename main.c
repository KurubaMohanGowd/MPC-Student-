#include<stdio.h>
#include<stdlib.h>

struct Student
{
    char name[50];
    int p;
    int c;
    int m;
};
void display(struct Student *s1,int students);
int main()
{
    printf("Enter the number of students : ");
    int students;
    scanf("%d",&students);
    int i;
    
    struct Student *s1=(struct Student *)malloc(students*sizeof(struct Student));
     
    for(i=0;i<students;i++)
    {
        printf("Enter the name of the student : ");
        __fpurge(stdin);
        scanf("%[^\n]",s1[i].name);
        printf("Enter P, C and M marks : ");
        scanf("%d %d %d", &s1[i].p,&s1[i].c,&s1[i].m);
    }
    display(s1,students);
    free(s1);
}
void display(struct Student *s,int n)
{
    int i;
    char line[50];
    int *avrg=malloc(n*sizeof(int));
    
    printf("-------------------------------------------------\n");
    
    printf("%-12s %-12s %-12s %-12s \n","Name","Maths","Physics","Chemistry");
     printf("-------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("%-12s %-12d %-12d %-12d ",s[i].name,s[i].m,s[i].p,s[i].c);
        avrg[0]+=s[i].m;
        avrg[1]+=s[i].p;
        avrg[2]+=s[i].c;
        printf("\n");
    }
    printf("-------------------------------------------------\n");
    printf("%-12s %-12.2f %-12.2f %-12.2f\n","Average",avrg[0]/(float)n,avrg[1]/(float)n,avrg[2]/(float)n);
    printf("-------------------------------------------------\n");
    free(avrg);
}
