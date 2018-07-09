#include <stdlib.h>
#include<stdio.h>

struct student
{
    
    int numbers;//学号
    char name[10];// 姓名
    char sex[10];//性别
    int dateofbirth;//出生日期
    char class1[15];//班级
    char phoneNumber[15];//电话号码
    int judge1;//5个评委
    int judge2;
    int judge3;
    int judge4;
    int judge5;
    int grade;//最终成绩
};
int main()
{
    struct student s[100];
    FILE *fp1,*fp2;
    int i=0,j;
    
    fp1 =fopen("/Users/20171105137/Desktop/student1.csv","r");// 只读，打开一个名为student.csv的文件
    if(fp1==NULL)
    {
        printf("The file is empty");
        exit(-1);//退出程序，终止进程
    }
    else
    {
        fscanf(fp1,"%*[^\n]%*c");//跳过第一行
        while(!feof(fp1))//当文件不是文件尾时，执行后续代码
        {
            fscanf(fp1,"%d,%[^,],%[^,],%d,%[^,],%[^,],%d,%d,%d,%d,%d",
                   &s[i].numbers,&s[i].name,&s[i].sex,&s[i].dateofbirth,&s[i].class1,
                   &s[i].phoneNumber,&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5);
            i++;
        }
        j=i;
        
        for(i=0;i<j;i++)
        {
            printf("%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d\n",s[i].numbers,
                   s[i].name,s[i].sex,s[i].dateofbirth,s[i].class1,s[i].phoneNumber,
                   s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);
        }
        
        fclose(fp1);
    }
    j=i;
    int max[100],min[100];
    
    for(i=0;i<j;i++)
    {
        max[i]=min[i]=s[i].judge1;
    }
    j=i;
    
    for(i=0;i<j;i++)
    {
        if(s[i].judge2>max[i])
            max[i]=s[i].judge2;
        if(s[i].judge3>max[i])
            max[i]=s[i].judge3;
        if(s[i].judge4>max[i])
            max[i]=s[i].judge4;
        if(s[i].judge5>max[i])
            max[i]=s[i].judge5;
    }
    j=i;
    
    for(i=0;i<j;i++)
    {
        if(s[i].judge2<min[i])
            min[i]=s[i].judge2;
        if(s[i].judge3<min[i])
            min[i]=s[i].judge3;
        if(s[i].judge4<min[i])
            min[i]=s[i].judge4;
        if(s[i].judge5<min[i])
            min[i]=s[i].judge5;
    }
    j=i;
    
    for(i=0;i<j;i++)
    {
        s[i].grade=(s[i].judge1+s[i].judge2+s[i].judge3+s[i].judge4+s[i].judge5-max[i]-min[i])/3;
    }
    j=i;
    i=0;
    
    fp2=fopen("student2.csv","w");//输出一个名为student2.CSV的文件
    fprintf(fp2,"numbers,name,sex,dateofbirth,class,phoneNumber,judge1,judge2,judge3,judge4,judge5,grade\n");
    
    while(i<j)
    {
        fprintf(fp2,"%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d,%d\n",
                s[i].numbers,s[i].name,s[i].sex,s[i].dateofbirth,s[i].class1,
                s[i].phoneNumber,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5,s[i].grade);
        i++;
    }
    fclose(fp2);
    
    return 0; 
}
