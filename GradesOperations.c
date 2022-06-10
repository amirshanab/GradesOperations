//
// Created by Amir on 28/11/2021.
//
#include <stdio.h>
#include <malloc.h>
#include "GradesOperations.h"

StudentList* OperationsFunction1(){
    int idnum;
    int grade1num;
    int grade2num;
    FILE* fp;
    fp = fopen("/home/amir/Desktop/semester 1/ex3/StudentsGrades.txt", "r");
    if(fp == NULL) {
        return 0;
    }
    StudentList* Lis;
    Lis = createList();
    while(!feof(fp)){
        fscanf(fp, "%d%d%d",&idnum,&grade1num,&grade2num);
        Student *st;
        st = (Student*) malloc(sizeof(Student));
        st->id = idnum;
        st->grade1=grade1num;
        st->grade2 = grade2num;
        addToList(Lis,st);
    }
    printStudentList(Lis);
    return Lis;
}


double countExam1 (StudentList* Lis){
    if(Lis->head == NULL)
        return  0;
    StudentNode *temp = Lis->head;
    double count =0;
    while (temp!=NULL){
        if(temp->st->grade1 != -1)
            count++;
        temp = temp->next;
    }
    return count;

}
double countExam2 (StudentList* Lis){
    if(Lis->head == NULL)
        return  0;
    StudentNode *temp = Lis->head;
    double count =0;
    while (temp!=NULL){
        if(temp->st->grade2 != -1)
            count++;
        temp = temp->next;
    }
    return count;
}
int NumberOfStudents(StudentList* Lis){
    if(Lis->head == NULL) {
        return 0;
    }
    StudentNode *temp = Lis->head;
    int Count =0;
    while (temp!= NULL){
        Count++;
        temp =  temp->next;
    }

    return Count;
}
int NumberOfStudents1Ex(StudentList* Lis){
    if(Lis->head == NULL)
        return 0;

    StudentNode *temp = Lis->head;
    int count =0;
    while(temp!= NULL){
        if(temp->st->grade1 == -1 && temp->st->grade2!=-1 || temp->st->grade2 ==-1 && temp->st->grade1 !=-1)
            count++;

        temp = temp->next;
    }

    return count;
}

int NumberOfStudentsNoExam(StudentList* Lis){
    if(Lis->head == NULL)
        return 0;
    StudentNode *temp = Lis->head;
    int count =0;
    while (temp!= NULL){
        if(temp->st->grade1==-1 && temp->st->grade2==-1) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}
double NumberOfStudentsFail1(StudentList* Lis){
    if(Lis->head==NULL)
        return 0;
    double count =0;
    StudentNode *temp = Lis->head;
    while (temp!= NULL){
        if(temp->st->grade1<60 && temp->st->grade1!=-1) {
            count++;
        }
        temp = temp->next;
    }
    if(count == 0)
        return 0;
    double sumofS = countExam1(Lis);

    return (count/sumofS)*100;
}
double NumberOfStudentsFail2(StudentList* Lis) {
    if (Lis->head == NULL)
        return 0;
    double count = 0;

    StudentNode *temp = Lis->head;
    while (temp!= NULL) {
        if (temp->st->grade2 < 60 && temp->st->grade2!= -1) {
            count++;

        }
        temp = temp->next;
    }
    if(count == 0)
        return 0;

    double sumofS = countExam2(Lis);
    return (count/sumofS)*100;

}
double AvarageScore1(StudentList* Lis){
    if(Lis->head==NULL)
        return 0;
    double avarageScore=0;
    double count =0;
    double sum =0;
    StudentNode *temp = Lis->head;
    while (temp!= NULL){
        if(temp->st->grade1!=-1){
            sum+=temp->st->grade1;
            count++;
        }
        temp = temp->next;
    }
    avarageScore= (sum/count);

    return avarageScore;
}
double AvarageScore2(StudentList* Lis){
    if(Lis->head==NULL)
        return 0;
    StudentNode *temp = Lis->head;
    double sum =0;
    double count =0;
    double avarageScore =0;
    while (temp!= NULL){
        if(temp->st->grade2!=-1){
            sum+=temp->st->grade2;
            count++;
        }
        temp = temp->next;
    }
    avarageScore=sum/count;
    return avarageScore;
}
int IDNumberOfhigh(StudentList* Lis){
    if(Lis->head==NULL)
        return 0;
    if(NumberOfStudents(Lis) == NumberOfStudentsNoExam(Lis)){
        return 0;
    }
    StudentNode *temp = Lis->head;
    int max=temp->st->grade1;
    int id =temp->st->id;
    while (temp != NULL){
        if(temp->st->grade1 > max || temp->st->grade2>max) {
            if(temp->st->grade1 > temp->st->grade2){
                max = temp->st->grade1;} else max = temp->st->grade2;
            id = temp->st->id;
        }
        temp = temp->next;
    }
    return id;
}

int IDNumberOflow(StudentList* Lis){
    if(Lis->head ==NULL)
        return 0;

    if(NumberOfStudents(Lis) == NumberOfStudentsNoExam(Lis)){
        return 0;
    }

    StudentNode *temp = Lis->head;
    int Low = temp->st->grade1;
    int id = temp->st->id;
    while (temp!= NULL){
        if(temp->st->grade1 < Low  && temp->st->grade1!=-1 || temp->st->grade2 < Low && temp->st->grade2!=-1){
            if(temp->st->grade1<temp->st->grade2){
                Low = temp->st->grade1;
            } else Low = temp->st->grade2;
            id = temp->st->id;
        }
        temp = temp->next;
    }
    return id;
}
void OperationsFunction2(StudentList* Lis){
    FILE* fp2;
    fp2 =fopen("Report.txt", "w");
    fprintf(fp2,"The number of students that are in the file : %d\n" , NumberOfStudents(Lis));
    fprintf(fp2,"The number of students that only tested once : %d\n", NumberOfStudents1Ex(Lis));
    fprintf(fp2,"The Number of students that didn't come to any of the tests : %d\n", NumberOfStudentsNoExam(Lis));
    fprintf(fp2,"The percentage of students who failed the first test : %.2f%% \n", NumberOfStudentsFail1(Lis));
    fprintf(fp2,"The percentage of students who failed the second test : %.2f%% \n" , NumberOfStudentsFail2(Lis));
    fprintf(fp2,"The average Score of the first exam : %.2f\n", AvarageScore1(Lis));
    fprintf(fp2,"The average Score of the second exam : %.2f\n" , AvarageScore2(Lis));
    fprintf(fp2,"The ID number of the student with the highest mark : %d\n", IDNumberOfhigh(Lis));
    fprintf(fp2,"The ID number of the student with the lowest mark : %d\n", IDNumberOflow(Lis));
    fclose(fp2);
}